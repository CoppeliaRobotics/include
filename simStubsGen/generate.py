import argparse
import os
import os.path
import errno
import re
import sys
import subprocess

from parse import parse
import model

parser = argparse.ArgumentParser(description='Generate various things for CoppeliaSim plugin.')
parser.add_argument('output_dir', type=str, default=None, help='the output directory')
parser.add_argument('--xml-file', type=str, default='callbacks.xml', help='the XML file with the callback definitions')
parser.add_argument('--lua-file', action='append', type=str, default=None, help='an optional LUA file containing docstrings (can appear multiple times)')
parser.add_argument("--gen-stubs", help='generate C++ stubs', action='store_true')
parser.add_argument("--gen-lua-xml", help='generate XML translation of Lua docstrings', action='store_true')
parser.add_argument("--gen-reference-xml", help='generate merged XML (from callbacks.xml and lua.xml)', action='store_true')
parser.add_argument("--gen-reference-html", help='generate HTML documentation (from reference.xml or callbacks.xml)', action='store_true')
parser.add_argument("--gen-lua-typechecker", help='generate Lua code for type-checking', action='store_true')
parser.add_argument("--gen-api-index", help='generate api index mapping for CodeEditor plugin', action='store_true')
parser.add_argument("--gen-ce", help='generate code-editor files', action='store_true')
parser.add_argument("--gen-cmake-meta", help='generate cmake metadata', action='store_true')
parser.add_argument("--gen-all", help='generate everything', action='store_true')
parser.add_argument("--verbose", help='print commands being executed', action='store_true')
args = parser.parse_args()

if args is False:
    SystemExit

self_dir = os.path.dirname(os.path.realpath(__file__))

def output(filename):
    return os.path.join(args.output_dir, filename)

def rel(filename):
    return os.path.join(self_dir, filename)

def runsubprocess(what, cmdargs):
    if args.verbose:
        print(' '.join(['"%s"' % arg if ' ' in arg else arg for arg in cmdargs]))
    try:
        child = subprocess.Popen(cmdargs)
        child.communicate()
    except OSError as e:
        print('error: program "{0}" is missing (hint: try "sudo apt install {0}")'.format(what), file=sys.stderr)
        sys.exit(1)
    if child.returncode != 0:
        print('failed to run %s' % what)
        sys.exit(1)

def runtool(what, *cmdargs):
    runsubprocess(what, [sys.executable, rel(what + '.py')] + list(cmdargs))

def runprogram(what, *cmdargs):
    runsubprocess(what, [what] + list(cmdargs))

# check dependencies & inputs:
input_xml = args.xml_file
if args.gen_all:
    args.gen_stubs = True
    args.gen_lua_xml = True
    args.gen_reference_xml = True
    args.gen_reference_html = True
    args.gen_lua_typechecker = True
    args.gen_api_index = True
    args.gen_ce = True
if args.gen_api_index:
    args.gen_reference_xml = True
if args.gen_reference_xml:
    input_xml = output('reference.xml')
    args.gen_lua_xml = True
if args.gen_lua_typechecker:
    args.gen_lua_xml = True
if args.gen_ce:
    args.gen_lua_xml = True

if args.verbose:
    print(' '.join(['"%s"' % arg if ' ' in arg else arg for arg in sys.argv]))

# create output dir if needed:
try:
    os.makedirs(args.output_dir)
except OSError as exc:
    if exc.errno == errno.EEXIST and os.path.isdir(args.output_dir):
        pass

plugin_doc = ''
for rel_path in ('../README.md', './README.md'):
    if os.path.isfile(p := os.path.join(os.path.dirname(args.xml_file), rel_path)):
        def find_doc_block(lines):
            inside = False
            collected = []
            for line in lines:
                if '[//]: # (plugin_doc_begin)' in line:
                    inside = True
                    continue
                if '[//]: # (plugin_doc_end)' in line:
                    break
                if inside:
                    collected.append(line.rstrip())
            return collected
        with open(p, "r", encoding="utf-8") as f:
            lines = f.readlines()
        doc_lines = find_doc_block(lines)
        if doc_lines:
            print(f'found plugin_doc block in {p}')
            import markdown
            plugin_doc = markdown.markdown(
                '\n'.join(doc_lines),
                extensions=['fenced_code', 'tables', 'nl2br'],
                output_format='html5',
            )

plugin = parse(args.xml_file)

lua_files = args.lua_file or []

if args.gen_cmake_meta:
    runtool('generate_cmake_metadata', args.xml_file, output('meta.cmake'))
    sys.exit(0)

if args.gen_lua_xml:
    if not lua_files:
        print('no lua file defined. skipping generate_lua_xml')
        args.gen_lua_xml = False
    else:
        cmdargs = ['generate_lua_xml']
        cmdargs.extend(['--xml-file', args.xml_file])
        for lua_file in lua_files:
            cmdargs.extend(['--lua-file', lua_file])
        cmdargs.extend(['--xml-output-file', output('lua.xml')])
        runtool(*cmdargs)

if args.gen_reference_xml:
    if not lua_files:
        input_xml = args.xml_file
        print('no lua file defined. skipping gen_reference_xml')
    else:
        runtool('merge_xml', args.xml_file, output('lua.xml'), output('reference.xml'))

if args.gen_reference_html:
    xsltproc_in = input_xml
    xsltproc_out = output('reference.html')
    xsltproc_xsl = rel('xsl/reference.xsl')
    if os.name == 'nt':
        # on windows xsltproc will raise a I/O error if path contains backslashes
        xsltproc_in = xsltproc_in.replace('\\', '/')
        xsltproc_out = xsltproc_out.replace('\\', '/')
        xsltproc_xsl = xsltproc_xsl.replace('\\', '/')
    runprogram('xsltproc', '-o', xsltproc_out, xsltproc_xsl, xsltproc_in)
    if plugin_doc:
        with open(xsltproc_out, "r", encoding="utf-8") as f:
            content = f.read()
        marker = '<!--###PLUGIN_DOC###-->'
        if marker in content:
            print(f"adding plugin_doc block to {output('reference.html')}...")
            content = content.replace(marker, plugin_doc)
            with open(xsltproc_out, "w", encoding="utf-8") as f:
                f.write(content)
        else:
            print(f"warning: no {marker} marker in {output('reference.html')}")

if args.gen_lua_typechecker:
    if not lua_files:
        print('no lua file defined. skipping gen_lua_typechecker')
        args.gen_lua_typechecker = False
    else:
        runtool('generate_lua_typechecker', args.xml_file, output('lua.xml'), output(f'typecheck.lua'))

if args.gen_api_index:
    runtool('generate_api_index', input_xml, output('index.json'))

if args.gen_ce:
    runtool('generate_ce', input_xml, output('ce.lua'))

if args.gen_stubs:
    tool = [
        'external/pycpp/pycpp',
        '-p', 'xml_file=' + args.xml_file,
        '-P', self_dir
    ]
    for fn in ('stubs.cpp', 'stubs.h', 'plugin.h', 'stubsPlusPlus.cpp'):
        runtool(*tool, '-i', rel('cpp/' + fn), '-o', output(fn))

