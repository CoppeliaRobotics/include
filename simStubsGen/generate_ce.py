import argparse
import json
import sys
from parse import parse

parser = argparse.ArgumentParser(description='Generate Code-Editor Lua file.')
parser.add_argument('xml_file', type=str, default=None, help='the (merged) XML file')
parser.add_argument('out_file', type=str, default=None, help='the output Lua file')
args = parser.parse_args()

if args is False:
    SystemExit

plugin = parse(args.xml_file)

mapping = {}

pluginKey = f'{plugin.name}'
if plugin.version > 1:
    pluginKey += f'-{plugin.version}'

with open(args.out_file, 'wt') as f:
    f.write(f"""local codeEditorInfos=[[
""")
    for cmd in plugin.commands:
        f.write(f'{cmd.calltip}\n')
    for enum in plugin.enums:
        for item in enum.items:
            f.write(f'{plugin.name}.{enum.name}.{item.name}\n')
    f.write(f"""]]

registerCodeEditorInfos("{pluginKey}",codeEditorInfos)
""")
