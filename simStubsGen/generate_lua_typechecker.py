import argparse
import os
import sys
from parse import parse
from model import ParamTable

parser = argparse.ArgumentParser(description='Generate Lua typechecker.')
parser.add_argument('lua_file', type=str, default=None, help='the input lua file')
parser.add_argument('xml_file', type=str, default=None, help='the (lua) XML file')
parser.add_argument('out_file', type=str, default=None, help='the output lua file')
parser.add_argument("--old-style", help='old style (for plugins with simStart/simEnd entrypoints)', action='store_true')
args = parser.parse_args()

if args is False:
    SystemExit

plugin = parse(args.xml_file)

with open(args.out_file, 'wt') as f:
    f.write(f"""-- {plugin.name} lua type-checking wrapper
-- (this file is automatically generated: do not edit)
require 'checkargs'

""")
    if args.old_style:
        f.write(f"""local {plugin.name}=require('{os.path.splitext(os.path.basename(args.lua_file))[0]}')

function {plugin.name}.__addTypeCheck()
    local function wrapFunc(funcName,wrapperGenerator)
        _G['{plugin.name}'][funcName]=wrapperGenerator(_G['{plugin.name}'][funcName])
    end
""")
    else:
        f.write(f"""return function(obj)
    local function wrapFunc(funcName,wrapperGenerator)
        obj[funcName]=wrapperGenerator(obj[funcName])
    end
""")

    for cmd in plugin.commands:
        paramList = ','.join(p.name for p in cmd.all_params)
        f.write(f"""
    wrapFunc('{cmd.name}',function(origFunc)
        return function(...)
            {paramList and 'local ' or ''}{paramList}{paramList and '=' or ''}checkargsEx(
                {{level=1}},
                {{
""")
        for p in cmd.all_params:
            f.write(f"""                    {{type='{p.dtype}'""")
            if isinstance(p,ParamTable):
                if p.itype:
                    f.write(f""",item_type='{p.itype}'""")
                if p.size:
                    f.write(f""",size='{p.size}'""")
            if p.nullable:
                f.write(f""",nullable=true""")
            if p.default:
                f.write(f""",default={p.default}""")
            f.write(f"""}},
""")
        f.write(f"""                }},
                ...
            )
            local _rets={{origFunc({paramList})}}
            return table.unpack(_rets)
        end
    end)
""")

    if args.old_style:
        f.write(f"""
    {plugin.name}.__addTypeCheck=nil
""")

    f.write(f"""end
""")

    if args.old_style:
        f.write(f"""
sim.registerScriptFuncHook('sysCall_init','{plugin.name}.__addTypeCheck',true)

return {plugin.name}
""")
