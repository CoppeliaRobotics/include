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

PLUGIN = plugin.name

# ---------------------------------------------------------------------------
# Generic helpers (works on lxml elements AND model objects AND raw strings)
# ---------------------------------------------------------------------------

def _is_element(v):
    return v is not None and hasattr(v, 'tag') and hasattr(v, 'iter')


def _attr(obj, name, default=None):
    if obj is None:
        return default
    if _is_element(obj):
        return obj.get(name, default)
    return getattr(obj, name, default)


def _name(obj):
    if obj is None:
        return None
    if isinstance(obj, str):
        return obj
    return _attr(obj, 'name')


# ---------------------------------------------------------------------------
# Description rendering: XML-in -> markdown (mirrors the XSLT templates)
# ---------------------------------------------------------------------------

def _xml_to_md(node):
    parts = []
    if node.text:
        parts.append(node.text)
    for child in node:
        tag = child.tag if isinstance(child.tag, str) else ''
        inner = _xml_to_md(child)
        if tag == 'command-ref':
            n = child.get('name', '')
            parts.append(f'[{PLUGIN}.{n}](#{n})')
        elif tag == 'enum-ref':
            n = child.get('name', '')
            parts.append(f'[{PLUGIN}.{n}](#enum:{n})')
        elif tag == 'struct-ref':
            n = child.get('name', '')
            parts.append(f'[{n}](#struct:{n})')
        elif tag == 'script-function-ref':
            n = child.get('name', '')
            parts.append(f'[{n}](#scriptfun:{n})')
        elif tag == 'sub':
            parts.append(f'~{inner}~')
        elif tag == 'sup':
            parts.append(f'^{inner}^')
        elif tag == 'em':
            parts.append(f'*{inner}*')
        elif tag == 'strong':
            parts.append(f'**{inner}**')
        elif tag == 'br':
            parts.append('  \n')
        elif tag == 'a':
            parts.append(f'[{inner}]({child.get("href", "")})')
        elif tag == 'code':
            lang = child.get('language') or 'lua'
            if child.get('display', '') == 'inline':
                parts.append(f'`{inner}`')
            else:
                parts.append(f'\n```{lang}\n{inner}\n```\n')
        elif tag == 'ul':
            parts.append('\n')
            for li in child.findall('li'):
                parts.append(f'- {_xml_to_md(li).strip()}\n')
            parts.append('\n')
        elif tag == 'ol':
            parts.append('\n')
            for i, li in enumerate(child.findall('li'), 1):
                parts.append(f'{i}. {_xml_to_md(li).strip()}\n')
            parts.append('\n')
        elif tag == 'li':
            parts.append(inner)
        else:
            parts.append(inner)
        if child.tail:
            parts.append(child.tail)
    return ''.join(parts)


def _html_to_md(text):
    text = re.sub(r'<sub>(.*?)</sub>', r'~\1~', text)
    text = re.sub(r'<sup>(.*?)</sup>', r'^\1^', text)
    text = re.sub(r'<em>(.*?)</em>', r'*\1*', text)
    text = re.sub(r'<strong>(.*?)</strong>', r'**\1**', text)
    text = re.sub(r'<br\s*/?>', '  \n', text)
    text = re.sub(r'<a\s+href="([^"]*)"[^>]*>(.*?)</a>', r'[\2](\1)', text)
    text = re.sub(r'<code[^>]*>(.*?)</code>', r'`\1`', text)
    text = re.sub(r'<li>(.*?)</li>', r'- \1', text)
    text = re.sub(r'</?(?:ul|ol)>', '\n', text)
    text = re.sub(r'<[^>]+>', '', text)
    return text


def to_md(value):
    if value is None:
        return ''
    if _is_element(value):
        return _xml_to_md(value).strip()
    return _html_to_md(str(value)).strip()


# ---------------------------------------------------------------------------
# Type names + synopsis rendering (mirrors renderLua*/renderPython*)
# ---------------------------------------------------------------------------

def lua_type(p):
    t = _attr(p, 'type') or ''
    item = _attr(p, 'item_type')
    if t == 'table' and item:
        it = 'float' if item == 'double' else item
        return f'{it}[{_attr(p, "size", "") or ""}]'
    if t == 'double':
        return 'float'
    return t


def py_type(p):
    t = _attr(p, 'type') or ''
    if t == 'table':
        return 'list'
    if t == 'double':
        return 'float'
    return t


def _params_of(obj):
    return getattr(obj, 'params', None) or []


def _returns_of(obj):
    return (getattr(obj, 'return_values', None)
            or getattr(obj, 'returns', None)
            or [])


def synopsis_lines(obj, name, include_python=True):
    """Return markdown lines for the combined Lua/Python synopsis section."""
    lines = ['**Synopsis**:', '', '```lua',
             _synopsis(obj, lua_type, name), '```', '']
    if include_python:
        lines += ['```python',
                  _synopsis(obj, py_type, name), '```', '']
    return lines


def _synopsis(obj, type_fn, name):
    ret = ', '.join(f'{type_fn(p)} {_name(p)}' for p in _returns_of(obj))
    params = ', '.join(
        f'{type_fn(p)} {_name(p)}' + (f'={_attr(p, "default")}' if _attr(p, 'default') else '')
        for p in _params_of(obj)
    )
    s = f'{name}({params})'
    return f'{ret} = {s}' if ret else s


def param_block(params, show_default, empty_msg='No params'):
    if not params:
        return empty_msg
    lines = []
    for p in params:
        t = _attr(p, 'type') or ''
        display = 'float' if t == 'double' else t
        if t == 'table':
            item = _attr(p, 'item_type')
            if item:
                display += f' of {"float" if item == "double" else item}'
            size = _attr(p, 'size')
            if size and size not in ('', '*'):
                display += f', size {size}'
        if show_default and _attr(p, 'default'):
            display += f', default: {_attr(p, "default")}'
        line = f'- **{_name(p)}** ({display})'
        d = to_md(getattr(p, 'description', None))
        if d:
            line += f': {d}'
        lines.append(line)
    return '\n'.join(lines)


# ---------------------------------------------------------------------------
# See also (manual + category-based auto refs)
# ---------------------------------------------------------------------------

def _categories(cmd):
    cats = getattr(cmd, 'categories', None)
    if not cats:
        return set()
    if isinstance(cats, str):
        return {cats}
    out = set()
    for c in cats:
        if isinstance(c, str):
            out.add(c)
            continue
        n = _attr(c, 'name')
        indirect = _attr(c, 'indirect')
        if n and not (indirect is True or indirect == 'true'):
            out.add(n)
    return out


def _ref_link(tag, name):
    if tag == 'command-ref':
        return f'[{PLUGIN}.{name}](#{name})'
    if tag == 'enum-ref':
        return f'[{PLUGIN}.{name}](#enum:{name})'
    if tag == 'struct-ref':
        return f'[{name}](#struct:{name})'
    if tag == 'script-function-ref':
        return f'[{name}](#scriptfun:{name})'
    return name


def render_see_also(obj, all_commands):
    links = []
    sa = getattr(obj, 'see_also', None)
    if sa is not None:
        if _is_element(sa):
            for child in sa:
                tag = child.tag if isinstance(child.tag, str) else ''
                if tag in ('command-ref', 'enum-ref', 'struct-ref', 'script-function-ref'):
                    links.append(_ref_link(tag, child.get('name', '')))
        elif isinstance(sa, str):
            for m in re.finditer(r'<a\s+href="([^"]*)"[^>]*>(.*?)</a>', sa):
                links.append(f'[{m.group(2)}]({m.group(1)})')

    cats = _categories(obj)
    if cats:
        for other in all_commands:
            if _name(other) == _name(obj):
                continue
            if _categories(other) & cats:
                n = _name(other)
                links.append(f'[{PLUGIN}.{n}](#{n})')

    return ', '.join(links) if links else '-'


# ---------------------------------------------------------------------------
# Filtering & ordering
# ---------------------------------------------------------------------------

def _visible(obj):
    skip = _attr(obj, 'skip_documentation')
    dep = _attr(obj, 'deprecated')
    return not (skip is True or skip == 'true' or dep is True or dep == 'true')


def _sorted(lst):
    return sorted(lst, key=lambda o: (_name(o) or ''))


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


out = [f'# {PLUGIN} Plugin API reference', '']

desc = to_md(getattr(plugin, 'description', None))
if desc:
    out += [desc, '']

# Alphabetical list
if commands:
    out.append('## Alphabetical list')
    out.append('')
    for c in commands:
        n = _name(c)
        out.append(f'- [{PLUGIN}.{n}](#{n})')
    out.append('')

# Commands
if commands:
    out.append('## Commands')
    out.append('')
    for c in commands:
        n = _name(c)
        out.append(_anchor(n, f'{PLUGIN}.{n}'))
        out.append('')

        d = to_md(getattr(c, 'description', None))
        if d:
            out += [f'**Description**: {d}', '']

        lua_only = _attr(c, 'lua_only')
        is_lua_only = lua_only is True or lua_only == 'true'

        out += synopsis_lines(c, f'{PLUGIN}.{n}', include_python=not is_lua_only)

        out += [
            '**Lua parameters**:', '',
            param_block(_params_of(c), True),
            '',
            '**Lua return values**:', '',
            param_block(_returns_of(c), False, 'No return values'),
            '',
        ]

        sa = render_see_also(c, commands)
        if sa != '-':
            out += [f'**See also**: {sa}', '']

# Enums / constants
if enums:
    out += [
        '## Constants',
        '',
        f'Constants used in the various functions. Refer to each constant using '
        f'*enumName.constantName*, i.e. **{PLUGIN}.curve_type.xy** for **xy** '
        f'constant in **{PLUGIN}.curve_type** enum.',
        '',
    ]
    for e in enums:
        n = _name(e)
        out.append(_anchor(f'enum:{n}', f'{PLUGIN}.{n}'))
        out.append('')
        items = getattr(e, 'items', None) or getattr(e, 'constants', None) or []
        if items:
            for item in items:
                iname = _name(item)
                idesc = to_md(getattr(item, 'description', None))
                out.append(f'- **{iname}**' + (f': {idesc}' if idesc else ''))
        else:
            out.append('-')
        out.append('')

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
        n = _name(s)
        out.append(_anchor(f'struct:{n}', n))
        out.append('')
        d = to_md(getattr(s, 'description', None))
        if d:
            out += [f'**Description**: {d}', '']
        fields = (getattr(s, 'params', None)
                  or getattr(s, 'fields', None)
                  or [])
        out += ['**Fields**:', '', param_block(fields, True, 'No fields'), '']
        sa = render_see_also(s, commands)
        if sa != '-':
            out += [f'**See also**: {sa}', '']

# Script functions
if script_functions:
    out += [
        '## Script functions',
        '',
        'Script functions are used to call some lua code from the plugin side '
        '(typically used for event handlers).',
        '',
    ]
    for f in script_functions:
        n = _name(f)
        out.append(_anchor(f'scriptfun:{n}', n))
        out.append('')

        d = to_md(getattr(f, 'description', None))
        if d:
            out += [f'**Description**: {d}', '']

        out += synopsis_lines(f, n, include_python=True)

        out += [
            '**Lua parameters**:', '',
            param_block(_params_of(f), True),
            '',
            '**Lua return values**:', '',
            param_block(_returns_of(f), False, 'No return values'),
            '',
        ]

        sa = render_see_also(f, commands)
        if sa != '-':
            out += [f'**See also**: {sa}', '']

markdown = '\n'.join(out).rstrip() + '\n'

if args.md_output_file:
    with open(args.md_output_file, 'w', encoding='utf-8') as fp:
        fp.write(markdown)
else:
    print(markdown)
