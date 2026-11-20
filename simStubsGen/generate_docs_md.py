import argparse
import re
from parse import parse

parser = argparse.ArgumentParser(description='Generate markdown API reference from XML.')
parser.add_argument('--xml-file', type=str, default=None, help='the callbacks.xml file')
parser.add_argument('--md-output-file', type=str, default=None, help='the output markdown file')
args = parser.parse_args()

if args is False:
    SystemExit

plugin = parse(args.xml_file)

def _is_element(v):
    return v is not None and hasattr(v, 'tag') and hasattr(v, 'iter')


def _attr(obj, name, default=None):
    if obj is None:
        return default
    if _is_element(obj):
        return obj.get(name, default)
    return getattr(obj, name, default)


# ---------------------------------------------------------------------------
# Type names + synopsis rendering (mirrors renderLua*/renderPython*)
# ---------------------------------------------------------------------------

def lua_type(p):
    if p.dtype == 'table':
        it = p.itype
        if it == 'double': it = 'float'
        if p.size:
            it += f'[{p.size}]'
        return it
    if p.dtype == 'double':
        return 'float'
    return p.dtype


def py_type(p):
    if p.dtype == 'table':
        return 'list'
    if p.dtype == 'double':
        return 'float'
    return p.dtype


def synopsis_lines(obj, name, include_python=True):
    """Return markdown lines for the combined Lua/Python synopsis section."""
    lines = ['#### Synopsis:', '', '```lua',
             _synopsis(obj, lua_type, name), '```', '']
    if include_python:
        lines += ['```python',
                  _synopsis(obj, py_type, name), '```', '']
    return lines


def _synopsis(obj, type_fn, name):
    ret = ', '.join(f'{type_fn(p)} {p.name}' for p in obj.returns)
    params = ', '.join(
        f'{type_fn(p)} {p.name}' + (f'={_attr(p, "default")}' if _attr(p, 'default') else '')
        for p in obj.params
    )
    s = f'{name}({params})'
    return f'{ret} = {s}' if ret else s


def param_block(params, show_default, empty_msg='No params'):
    if not params:
        return empty_msg
    lines = []
    for p in params:
        t = p.dtype
        display = 'float' if t == 'double' else t
        if t == 'table':
            item = p.itype
            if item:
                display += f' of {"float" if item == "double" else item}'
            size = p.size
            if size and size not in ('', '*'):
                display += f', size {size}'
        if show_default and p.default:
            display += f', default: {p.default}'
        line = f'- **{p.name}** ({display})'
        d = p.description
        if d:
            line += f': {d}'
        lines.append(line)
    return '\n'.join(lines)


def render_see_also(obj, all_commands):
    links = []
    for sa in obj.see_also:
        if isinstance(sa, tuple):
            links.append('-'.join(sa))
        elif isinstance(sa, str):
            links.append(sa)

    for cat in obj.categories:
        for other in all_commands:
            if other.name == obj.name:
                continue
            if set(other.categories) & set(obj.categories):
                links.append(other.name)

    return ', '.join(links) if links else '-'


# ---------------------------------------------------------------------------
# Filtering & ordering
# ---------------------------------------------------------------------------

def _visible(obj):
    skip = _attr(obj, 'skip_documentation')
    dep = _attr(obj, 'deprecated')
    return not (skip is True or skip == 'true' or dep is True or dep == 'true')


def _sorted(lst):
    return sorted(lst, key=lambda o: (o.name or ''))


commands = _sorted([c for c in (getattr(plugin, 'commands', None) or []) if _visible(c)])
enums = _sorted([e for e in (getattr(plugin, 'enums', None) or []) if _visible(e)])
structs = _sorted([s for s in (getattr(plugin, 'structs', None) or []) if _visible(s)])
script_functions = _sorted([
    f for f in (getattr(plugin, 'script_functions', None)
                or getattr(plugin, 'scriptfunctions', None) or [])
    if _visible(f)
])


# ---------------------------------------------------------------------------
# Build markdown
# ---------------------------------------------------------------------------

def _anchor(aid, label):
    return f'### <a name="{aid}" id="{aid}"></a>{label}'


out = [f'# {plugin.name} Plugin API reference', '']

if plugin.info:
    out += [plugin.info, '']

# Alphabetical list
if commands:
    out.append('## Alphabetical list')
    out.append('')
    for c in commands:
        n = c.name
        out.append(f'- [{plugin.name}.{n}](#{n})')
    out.append('')

# Commands
if commands:
    out.append('## Commands')
    out.append('')
    for c in commands:
        n = c.name
        out.append(f'### {plugin.name}.{n}')
        out.append('')

        d = c.description
        if d:
            out += [d, '']

        lua_only = _attr(c, 'lua_only')
        is_lua_only = lua_only is True or lua_only == 'true'

        out += synopsis_lines(c, f'{plugin.name}.{n}', include_python=not is_lua_only)

        out += [
            '#### Parameters:', '',
            param_block(c.params, True),
            '',
            '#### Return values:', '',
            param_block(c.returns, False, 'No return values'),
            '',
        ]

        sa = render_see_also(c, commands)
        if sa != '-':
            out += [f'#### See also:', sa, '']

# Enums / constants
if enums:
    out += [
        '## Constants',
        '',
        f'Constants used in the various functions. Refer to each constant using '
        f'*enumName.constantName*, i.e. **{plugin.name}.curve_type.xy** for **xy** '
        f'constant in **{plugin.name}.curve_type** enum.',
        '',
    ]
    for e in enums:
        n = e.name
        out.append(f'### {plugin.name}.{n}')
        out.append('')
        items = getattr(e, 'items', None) or getattr(e, 'constants', None) or []
        if items:
            for item in items:
                iname = item.name
                idesc = None # missing in simStubsGen/model/enum.py
                out.append(f'- **{iname}**' + (f': {idesc}' if idesc else ''))
        else:
            out.append('-')
        out.append('')

        sa = render_see_also(e, commands)
        if sa != '-':
            out += [f'#### See also:', sa, '']

# Structs
if structs:
    out += [
        '## Data structures',
        '',
        'Data structures are used to pass complex data around. Create data '
        'structures in Lua in the form of a map, e.g.: '
        '`{line_size=3, add_to_legend=false, selectable=true}`',
        '',
    ]
    for s in structs:
        n = s.name
        out.append(f'### {plugin.name}.{n}')
        out.append('')
        d = s.description
        if d:
            out += [d, '']
        fields = (getattr(s, 'params', None)
                  or getattr(s, 'fields', None)
                  or [])
        out += ['#### Fields:', '', param_block(fields, True, 'No fields'), '']
        sa = render_see_also(s, commands)
        if sa != '-':
            out += [f'#### See also:', sa, '']

# Script functions
if script_functions:
    out += [
        '## Script functions',
        '',
        'Script functions define the signature of lua functions called by plugins '
        '(typically used for event handlers).',
        '',
    ]
    for f in script_functions:
        n = f.name
        out.append(f'### {plugin.name}.{n}')
        out.append('')

        d = f.description
        if d:
            out += [d, '']

        out += synopsis_lines(f, n, include_python=True)

        out += [
            '#### Parameters:', '',
            param_block(f.params, True),
            '',
            '#### Return values:', '',
            param_block(f.returns, False, 'No return values'),
            '',
        ]

        sa = render_see_also(f, commands)
        if sa != '-':
            out += [f'#### See also:', sa, '']

markdown = '\n'.join(out).rstrip() + '\n'

if args.md_output_file:
    with open(args.md_output_file, 'w', encoding='utf-8') as fp:
        fp.write(markdown)
else:
    print(markdown)
