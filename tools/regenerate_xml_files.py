import sys
from pathlib import Path


def merge_objects_xml(properties_file, methods_file, output_file):
    import xml.etree.ElementTree as ET
    from copy import deepcopy

    props_tree = ET.parse(properties_file)
    methods_tree = ET.parse(methods_file)

    props_root = props_tree.getroot()
    methods_root = methods_tree.getroot()

    if props_root.tag != "object-classes" or methods_root.tag != "object-classes":
        raise ValueError("Both XML files must have <object-classes> as root")

    # Build lookup for methods.xml object-classes
    methods_classes = {}
    for cls in methods_root.findall("object-class"):
        name = cls.get("name")
        if name:
            methods_classes[name] = cls

    # Process all classes from properties.xml
    for props_cls in props_root.findall("object-class"):
        name = props_cls.get("name")
        if not name:
            continue

        if name in methods_classes:
            methods_cls = methods_classes[name]

            # ---- Merge attributes (properties.xml has priority) ----
            merged_attrib = dict(methods_cls.attrib)  # start from methods.xml
            merged_attrib.update(props_cls.attrib)    # overwrite with properties.xml
            methods_cls.attrib.clear()
            methods_cls.attrib.update(merged_attrib)

            # ---- Replace property nodes ----
            for prop in methods_cls.findall("property"):
                methods_cls.remove(prop)

            for prop in props_cls.findall("property"):
                methods_cls.append(deepcopy(prop))

        else:
            # Create new object-class with properties.xml attributes
            new_cls = ET.Element("object-class", dict(props_cls.attrib))

            for prop in props_cls.findall("property"):
                new_cls.append(deepcopy(prop))

            methods_root.append(new_cls)

    methods_tree.write(output_file, encoding="utf-8", xml_declaration=True)


def extract_objects_properties(script_dir: Path, coppeliasim_executable: str):
    import subprocess

    sim_xml_dir = script_dir.parent / 'sim'
    objects_properties_xml = sim_xml_dir / 'objects-properties.xml'
    objects_xml = sim_xml_dir / 'objects.xml'
    objects_methods_xml = sim_xml_dir / 'objects-methods.xml'

    cmd = [
        coppeliasim_executable,
        '--headless',
        '--param', 'addOns.autoLoad=false',
        '--addon', script_dir / 'extract_objects_properties.lua',
        '--param', f'output_xml={objects_properties_xml}',
    ]
    print('Running:', ' '.join(map(str, cmd)))
    subprocess.run(cmd, check=True)
    print(f'Wrote {objects_properties_xml}')

    merge_objects_xml(
        objects_properties_xml,
        objects_methods_xml,
        objects_xml,
    )
    print(f'Wrote {objects_xml}')


def extract_enums(script_dir: Path):
    import re
    import sys
    from typing import Dict, List, Optional, Tuple
    import xml.etree.ElementTree as ET
    from xml.dom import minidom
    from pathlib import Path

    '''
    python script to parse enums in a C header file annotated with special comments:

    // @enum name="sceneObjectType" label="scene object types" type="int" prefix="sim_sceneobject_" description=""
    enum { // values are serialized
            sim_sceneobject_shape =0,
            sim_sceneobject_joint,
            sim_sceneobject_forcesensor = 12, // @item label="force sensor"
    };

    and write the XML:

    <enum name="sceneObjectType" label="scene object types" type="int" prefix="sim_sceneobject_" description="">
        <item name="shape" value="0" />
        <item name="joint" value="1" />
        <item name="forcesensor" value="12" label="force sensor" />
    </enum>

    enum special comment starts with @enum, contains variables: name, label, type, prefix, description

    prefix is used to strip the prefix from C enum items

    item special comment starts with @item, but you should collect also enum items without this special comment

    to determine the value of the enum, use normal C/C++ rules, e.g. first item has default value 0, and any other item has default value of previous item + 1, but of course value can be overridden by assigning it explicitly, as per C/C++ standard.
    '''

    class EnumItem:
        def __init__(self, name: str, value: Optional[int] = None, label: str = ""):
            self.name = name
            self.value = value
            self.label = label

    class EnumDefinition:
        def __init__(self, name: str, label: str, type_: str, prefix: str, description: str):
            self.name = name
            self.label = label
            self.type = type_
            self.prefix = prefix
            self.description = description
            self.items: List[EnumItem] = []

    def parse_enum_comment(line: str) -> Optional[Dict[str, str]]:
        """Parse @enum comment and extract parameters."""
        match = re.search(r'@enum\s+(.*?)(?:\*/|$)', line)
        if not match:
            return None

        params_str = match.group(1)
        params = {}

        # Parse name="value" pairs
        pattern = r'(\w+)="([^"]*)"'
        for key, value in re.findall(pattern, params_str):
            params[key] = value

        return params

    def parse_item_comment(line: str) -> Optional[Dict[str, str]]:
        """Parse @item comment and extract parameters."""
        match = re.search(r'@item\s+(.*?)(?:\*/|$)', line)
        if not match:
            return None

        params_str = match.group(1)
        params = {}

        # Parse name="value" pairs
        pattern = r'(\w+)="([^"]*)"'
        for key, value in re.findall(pattern, params_str):
            params[key] = value

        return params

    def parse_c_value(value_str: str) -> int:
        """Parse a C integer constant (handles decimal and hex)."""
        value_str = value_str.strip()
        if value_str.startswith('0x') or value_str.startswith('0X'):
            return int(value_str, 16)
        return int(value_str)

    def strip_prefix(name: str, prefix: str) -> str:
        """Strip the prefix from an enum item name."""
        if prefix and name.startswith(prefix):
            return name[len(prefix):]
        return name

    def parse_enum_block(lines: List[str], start_idx: int) -> Tuple[Optional[EnumDefinition], int]:
        """Parse an enum block starting at start_idx."""

        # Look for @enum comment before the enum keyword
        enum_params = None
        for i in range(start_idx, max(-1, start_idx - 5), -1):
            if i >= 0 and '//' in lines[i]:
                enum_params = parse_enum_comment(lines[i])
                if enum_params:
                    break

        if not enum_params:
            # Check if @enum is on the same line as enum
            current_line = lines[start_idx]
            if '//' in current_line:
                parts = current_line.split('//')
                if len(parts) > 1:
                    enum_params = parse_enum_comment('//' + parts[1])

        if not enum_params:
            return None, start_idx

        # Find the start of enum block
        line_idx = start_idx
        while line_idx < len(lines) and '{' not in lines[line_idx]:
            line_idx += 1

        if line_idx >= len(lines):
            return None, start_idx

        # Create enum definition
        enum_def = EnumDefinition(
            name=enum_params.get('name', ''),
            label=enum_params.get('label', ''),
            type_=enum_params.get('type', 'int'),
            prefix=enum_params.get('prefix', ''),
            description=enum_params.get('description', '')
        )

        # Parse enum items
        line_idx += 1  # Skip past '{'
        current_value = 0
        items = []

        while line_idx < len(lines):
            line = lines[line_idx].strip()

            # Check for end of enum
            if line.startswith('}'):
                line_idx += 1
                break

            # Skip empty lines and comments (except @item comments)
            if not line or (line.startswith('//') and '@item' not in line):
                line_idx += 1
                continue

            # Check for item comment
            item_params = None
            if '//' in line:
                parts = line.split('//')
                if len(parts) > 1:
                    item_params = parse_item_comment('//' + parts[1])

            # Parse enum item
            if line.endswith(','):
                line = line[:-1]

            # Handle assignment
            if '=' in line:
                parts = line.split('=', 1)
                name = parts[0].strip()
                value_expr = parts[1].split(',')[0].strip()  # In case there's a comment after value
                # Remove any trailing comment from value expression
                if '//' in value_expr:
                    value_expr = value_expr.split('//')[0].strip()
                try:
                    current_value = parse_c_value(value_expr)
                except ValueError:
                    # If we can't parse the value, use the default
                    pass
            else:
                # No assignment, use default value
                name = line.split(',')[0].strip()

            # Clean up name (remove any trailing comma or comment)
            name = name.split(',')[0].strip()

            if name:  # Only add if we have a name
                item_label = item_params.get('label', '') if item_params else ''
                items.append(EnumItem(name, current_value, item_label))

            current_value += 1
            line_idx += 1

        # Process items: strip prefix and assign to enum definition
        for item in items:
            stripped_name = strip_prefix(item.name, enum_def.prefix)
            enum_def.items.append(EnumItem(stripped_name, item.value, item.label))

        return enum_def, line_idx

    def parse_c_header(filename: str) -> List[EnumDefinition]:
        """Parse a C header file and extract all annotated enums."""
        with open(filename, 'r') as f:
            content = f.read()

        # Split into lines and clean up
        lines = [line.rstrip() for line in content.split('\n')]

        enums = []
        i = 0

        while i < len(lines):
            line = lines[i]

            # Look for enum keyword
            if 'enum' in line:
                enum_def, new_idx = parse_enum_block(lines, i)
                if enum_def:
                    enums.append(enum_def)
                    i = new_idx
                    continue

            i += 1

        return enums

    def enum_to_xml(enum_def: EnumDefinition) -> ET.Element:
        """Convert an EnumDefinition to XML element."""
        enum_elem = ET.Element('enum', {
            'name': enum_def.name,
            'label': enum_def.label,
            'type': enum_def.type,
            'prefix': enum_def.prefix,
            'description': enum_def.description
        })

        for item in enum_def.items:
            attrs = {'name': item.name, 'value': str(item.value)}
            if item.label:
                attrs['label'] = item.label
            ET.SubElement(enum_elem, 'item', attrs)

        return enum_elem

    def prettify_xml(elem: ET.Element) -> str:
        """Return a pretty-printed XML string for the Element."""
        rough_string = ET.tostring(elem, 'utf-8')
        reparsed = minidom.parseString(rough_string)
        return reparsed.toprettyxml(indent="    ")

    input_file = script_dir.parent / 'simLib' / 'simConst.h'
    output_file = script_dir.parent / 'sim' / 'enums.xml'

    try:
        enums = parse_c_header(str(input_file))

        # Create root element
        root = ET.Element('enums')

        # Add all enums
        for enum_def in enums:
            root.append(enum_to_xml(enum_def))

        # Output XML
        xml_str = prettify_xml(root)

        # Remove XML declaration if you want just the enums
        lines = xml_str.split('\n')
        if lines[0].startswith('<?xml'):
            lines = lines[1:]

        # Output result
        with open(output_file, 'wt') as f:
            f.write('\n'.join(lines).strip())
        print(f"Wrote '{output_file}'")

    except FileNotFoundError:
        print(f"Error: File '{input_file}' not found.")
        sys.exit(1)
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)


if __name__ == '__main__':
    script_dir = Path(__file__).resolve().parent
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument(
        '--coppeliaSim-bin',
        required=True,
        help='Path to CoppeliaSim executable'
    )
    args = parser.parse_args()
    extract_objects_properties(script_dir, args.coppeliaSim_bin)
    extract_enums(script_dir)
