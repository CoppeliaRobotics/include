import argparse
import re
import sys
import xml.etree.ElementTree as ET
from parse import parse

parser = argparse.ArgumentParser(description='Generate xml from lua functions annotated with doc-strings.')
parser.add_argument('xml_file', type=str, default=None, help='the callbacks.xml file')
parser.add_argument('lua_file', type=str, default=None, help='the input lua file')
parser.add_argument('out_xml', type=str, default=None, help='the output lua.xml file')
parser.add_argument("--verbose", help='print verbose messages', action='store_true')
parser.add_argument("--dry-run", help='don\'t write any output file', action='store_true')
args = parser.parse_args()

if args is False:
    SystemExit

plugin = parse(args.xml_file)

fun = None
ins, outs = [], []
cats = []

def output():
    if fun:
        if args.verbose:
            print('.')
        f, tagopts, fdesc = fun
        cmd = ET.SubElement(root, 'command')
        cmd.attrib['name'] = f
        for k, v in tagopts.items():
            cmd.attrib[k.replace('_', '-')] = str(v).lower() if isinstance(v, bool) else str(v)
        if fdesc:
            d = ET.SubElement(cmd, 'description')
            d.text = fdesc
        if cats:
            cs = ET.SubElement(cmd, 'categories')
            for cat in cats:
                c = ET.SubElement(cs, 'category', name=cat)
        pars = ET.SubElement(cmd, 'params')
        rets = ET.SubElement(cmd, 'return')
        for (src, parent) in ((ins, pars), (outs, rets)):
            for (typeSpec, name, description) in src:
                p = ET.SubElement(parent, 'param')
                p.attrib['name'] = str(name)
                p.attrib['type'] = str(typeSpec['type'])
                if 'item_type' in typeSpec:
                    p.attrib['item-type'] = str(typeSpec['item_type'])
                if 'size' in typeSpec:
                    p.attrib['size'] = str(typeSpec["size"])
                if 'nullable' in typeSpec:
                    p.attrib['nullable'] = str(typeSpec["nullable"]).lower()
                if 'default' in typeSpec:
                    v = typeSpec["default"]
                    p.attrib['default'] = str(v).lower() if isinstance(v, bool) else str(v)
                if description:
                    d = ET.SubElement(p, 'description')
                    d.text = description

def error(msg):
    global args, lineno
    print(f'{args.lua_file}:{lineno}: {msg}')
    sys.exit(2)


def parse_lua_table(lua_str):
    """Parses a subset of Lua table literals into Python dictionaries."""

    lua_str = lua_str.strip()

    if not lua_str.startswith("{") or not lua_str.endswith("}"):
        raise ValueError("Invalid Lua table format: " + lua_str)

    def parse_table(s, index=0):
        """Recursive function to parse Lua tables."""
        result = {}
        key = None
        value = None
        i = index + 1  # Skip the opening '{'

        while i < len(s):
            char = s[i]

            if char in " \t\r\n":
                i += 1  # Skip whitespace
                continue

            if char == "}":
                if key is not None and value is not None:
                    result[key] = value  # Store last key-value pair
                return result, i + 1  # Skip closing '}'

            if char == "{":
                value, i = parse_table(s, i)
                if key is not None:
                    result[key] = value
                    key, value = None, None
                continue

            match = re.match(r"([a-zA-Z_]\w*)\s*=", s[i:])
            if match:  # Found a key
                key = match.group(1)
                i += match.end()
                continue

            match = re.match(r"-?\d+(\.\d+)?", s[i:])
            if match:  # Found a number
                value = float(match.group()) if "." in match.group() else int(match.group())
                i += match.end()
                if key is not None:
                    result[key] = value
                    key, value = None, None
                continue

            if s.startswith("true", i):
                value = True
                i += 4
                if key is not None:
                    result[key] = value
                    key, value = None, None
                continue

            if s.startswith("false", i):
                value = False
                i += 5
                if key is not None:
                    result[key] = value
                    key, value = None, None
                continue

            if s.startswith('"', i):
                i2 = s.index('"', i + 1)  # Fix index
                value = s[i + 1:i2]
                i = i2 + 1
                if key is not None:
                    result[key] = value
                    key, value = None, None
                continue

            if s.startswith("'", i):
                i2 = s.index("'", i + 1)  # Fix index
                value = s[i + 1:i2]
                i = i2 + 1
                if key is not None:
                    result[key] = value
                    key, value = None, None
                continue

            if char == ",":
                i += 1  # Skip comma
                continue

            raise ValueError(f"Unexpected character at index {i}: '{char}'")

        raise ValueError("Unexpected end of input")

    parsed_table, _ = parse_table(lua_str)
    return parsed_table


root = ET.Element('plugin')
root.attrib['name'] = plugin.name
if plugin.version:
    root.attrib['version'] = str(plugin.version)


with open(args.lua_file, 'r') as f:
    for lineno, line in enumerate(f):
        lineno += 1
        try:
            if m := re.match(r'\s*--\s*@((\w+)\b\s*(\{[^\s]*\})?)\s*(.*?)\s*$', line):
                _, tag, tagopts, line = m.groups()
                tagopts = parse_lua_table(tagopts) if tagopts else {}

                if tag in ('func', 'fun'):
                    if m := re.match(r'(\S+)\s*(.*?)\s*$', line):
                        name, description = m.groups()
                        fun = (name, tagopts, description)
                        if args.verbose:
                            print(f'fun={name}{tagopts}, {description}')
                    else:
                        error('bad arguments: must be: @func <funcName> [description]')
                elif tag in ('arg', 'ret'):
                    if tagopts:
                        # was in the form @arg {typespec...} name [descr]
                        if m := re.match(r'(\w+)\s*(.*?)$', line):
                            name, description = m.groups()
                            typeSpec = tagopts
                        else:
                            error(f'bad arguments: must be: @{tag} <typeSpec> <name> [description]')
                    else:
                        # was in the form @arg simpletype name [descr]
                        if m := re.match(r'(\w+)\s+(\w+)\s*(.*?)$', line):
                            dtype, name, description = m.groups()
                            typeSpec = {'type': dtype}
                        elif m := re.match(r'table\.(\w+)\s+(\w+)\s*(.*?)$', line):
                            itype, name, description = m.groups()
                            typeSpec = {'type': 'table', 'item_type': itype}
                        else:
                            error(f'bad arguments: must be: @{tag} <typeSpec> <name> [description]')
                    if not all(k in ('type', 'item_type', 'default', 'size', 'nullable') for k in typeSpec):
                        error(f'bad key in typeSpec: {", ".join(typeSpec.keys())}')
                    if tag == 'arg':
                        ins.append((typeSpec, name, description))
                        if args.verbose:
                            print(f'arg={typeSpec}, {name}, {description}')
                    elif tag == 'ret':
                        outs.append((typeSpec, name, description))
                        if args.verbose:
                            print(f'ret={typeSpec}, {name}, {description}')
                elif tag == 'cats':
                    cats = [x.strip() for x in line.split(',')]
                    if args.verbose:
                        print(f'cats={cats}')
                else:
                    error(f'unknown tag: @{tag}')
            else:
                output()
                fun = None
                ins, outs = [], []
                cats = []
        except Exception as e:
            raise Exception(f'error at {args.lua_file}:{lineno}: {e!s}')
    output()

tree = ET.ElementTree(root)
if not args.dry_run:
    tree.write(args.out_xml, encoding='utf-8', xml_declaration=True)
if args.dry_run:
    from xml.dom.minidom import parseString
    print(parseString(ET.tostring(root,'utf-8')).toprettyxml(indent="  "))
