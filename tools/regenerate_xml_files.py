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

            for ns in props_cls.findall("namespace"):
                methods_cls.append(deepcopy(ns))

        else:
            # Create new object-class with properties.xml attributes
            new_cls = ET.Element("object-class", dict(props_cls.attrib))

            for prop in props_cls.findall("property"):
                new_cls.append(deepcopy(prop))

            for ns in props_cls.findall("namespace"):
                new_cls.append(deepcopy(ns))

            methods_root.append(new_cls)

    methods_tree.write(output_file, encoding="utf-8", xml_declaration=True)


def extract_objects_properties(script_dir: Path, coppeliasim_executable: str):
    import subprocess

    sim_xml_dir = script_dir.parent / 'sim'
    objects_properties_xml = sim_xml_dir / 'objects-properties.xml'
    objects_xml = sim_xml_dir / 'objects.xml'
    objects_methods_xml = sim_xml_dir / 'objects-methods.xml'
    enums_xml = sim_xml_dir / 'enums.xml'

    cmd = [
        coppeliasim_executable,
        '--headless',
        '--param', 'addOns.autoLoad=false',
        '--addon', script_dir / 'extract_objects_properties.lua',
        '--param', f'objects_properties_xml={objects_properties_xml}',
        '--param', f'enums_xml={enums_xml}',
    ]
    print('Running:', ' '.join(map(str, cmd)))
    subprocess.run(cmd, check=True)
    print(f'Wrote {enums_xml}')
    print(f'Wrote {objects_properties_xml}')

    merge_objects_xml(
        objects_properties_xml,
        objects_methods_xml,
        objects_xml,
    )
    print(f'Wrote {objects_xml}')


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
