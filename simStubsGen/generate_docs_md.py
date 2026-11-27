import argparse
import re
from parse import parse, render_xml_ref

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


def _flag(obj, name):
    """Read a boolean documentation flag from a model object or an XML element."""
    for key in (name, name.replace('_', '-')):
        v = _attr(obj, key)
        if isinstance(v, bool):
            return v
        if isinstance(v, str):
            return v.strip().lower() in ('true', '1')
    return False


# ---------------------------------------------------------------------------
# Type names + synopsis rendering (mirrors renderLua*/renderPython*)
# ---------------------------------------------------------------------------

def lua_type(p):
    # mirrors renderLuaParamType: a table with an item-type renders as
    # 'item-type[size]' (even when the size is empty), otherwise as 'table'
    if p.dtype == 'table' and getattr(p, 'itype', None):
        it = p.itype
        if it == 'double':
            it = 'float'
        return f'{it}[{getattr(p, "size", "") or ""}]'
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


def _params(obj):
    """All declared params, as rendered by reference.xsl.

    The model also exposes 'write' params only (``obj.params``), which excludes
    values the C++ stubs do not convert (e.g. generic tables without item-type,
    or params marked with skip="true"); documentation shows every declared one.
    """
    return getattr(obj, 'all_params', None) or getattr(obj, 'params', None) or []


def _returns(obj):
    return getattr(obj, 'all_returns', None) or getattr(obj, 'returns', None) or []


def _synopsis(obj, type_fn, name):
    ret = ', '.join(f'{type_fn(p)} {p.name}' for p in _returns(obj))
    params = ', '.join(
        f'{type_fn(p)} {p.name}' + (f'={_attr(p, "default")}' if _attr(p, 'default') else '')
        for p in _params(obj)
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


def see_also_lines(obj, all_commands):
    links = []

    for sa in obj.see_also:
        if isinstance(sa, tuple):
            links.append(render_xml_ref(sa[0], sa[1], plugin.name))
        elif isinstance(sa, str):
            links.append(f'[{sa}](#{sa})')

    for cat in obj.categories:
        for other in all_commands:
            if other.name == obj.name:
                continue
            if set(other.categories) & set(obj.categories):
                links.append(render_xml_ref('command-ref', other.name, plugin.name))

    if links:
        return ['#### See also:', '', ', '.join(links), '']
    else:
        return []


# ---------------------------------------------------------------------------
# Filtering & ordering
# ---------------------------------------------------------------------------

def _visible(obj):
    # mirrors reference.xsl: not(@skip-documentation='true') and not(@deprecated='true')
    return not (_flag(obj, 'skip_documentation') or _flag(obj, 'deprecated'))


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

def anchor(aid):
    return f'<a name="{aid}" id="{aid}"></a>'


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
        out.append(f'### {anchor(n)} {plugin.name}.{n}')
        out.append('')

        d = c.description
        if d:
            out += [d, '']

        lua_only = _flag(c, 'lua_only')

        out += synopsis_lines(c, f'{plugin.name}.{n}', include_python=not lua_only)

        out += [
            '#### Parameters:', '',
            param_block(_params(c), True),
            '',
            '#### Return values:', '',
            param_block(_returns(c), False, 'No return values'),
            '',
        ]

        out += see_also_lines(c, commands)

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
        out.append(f'### {anchor(f"enum:{n}")} {plugin.name}.{n}')
        out.append('')
        items = getattr(e, 'items', None) or getattr(e, 'constants', None) or []
        if items:
            for item in items:
                iname = item.name
                idesc = (_attr(item, 'description') or '').strip()
                out.append(f'- **{iname}**' + (f': {idesc}' if idesc else ''))
        else:
            out.append('-')
        out.append('')

        out += see_also_lines(e, commands)

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
        out.append(f'### {anchor(f"struct:{n}")} {n}')
        out.append('')
        d = s.description
        if d:
            out += [d, '']
        fields = (getattr(s, 'params', None)
                  or getattr(s, 'fields', None)
                  or [])
        out += ['#### Fields:', '', param_block(fields, True, 'No fields'), '']
        out += see_also_lines(s, commands)

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
        out.append(f'### {anchor(f"scriptfun:{n}")} {n}')
        out.append('')

        d = f.description
        if d:
            out += [d, '']

        out += synopsis_lines(f, n, include_python=True)

        out += [
            '#### Parameters:', '',
            param_block(_params(f), True),
            '',
            '#### Return values:', '',
            param_block(_returns(f), False, 'No return values'),
            '',
        ]

        out += see_also_lines(f, commands)

markdown = '\n'.join(out).rstrip() + '\n'

if args.md_output_file:
    with open(args.md_output_file, 'w', encoding='utf-8') as fp:
        fp.write(markdown)
else:
    print(markdown)
