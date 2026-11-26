import os
import sys
import xml.etree.ElementTree as ET
import re
from pathlib import Path

import model

def parse(xml_file):
    try:
        import xmlschema
        schema = xmlschema.XMLSchema11(Path(__file__).resolve().parent.parent / "xsd" / "callbacks.xsd")
        schema.validate(xml_file)
    except ModuleNotFoundError:
        print(f'warning: missing python package "xmlschema"; input file {os.path.basename(xml_file)} will not be validated.', file=sys.stderr)
    tree = ET.parse(xml_file)
    root = tree.getroot()
    return model.Plugin(root, xml_file)

def escape(s, method='C'):
    if isinstance(s, str) and method == 'C':
        return s.replace('\\', '\\\\').replace('"', '\\"').replace('\n', '\\n').replace('\r', '')
    else:
        return s

def read_description(node):
    if not isinstance(node, ET.Element): return ''
    desc_node = node.find('description')
    if desc_node is None: return ''
    parts = [desc_node.text or '']
    for child in desc_node:
        parts.append(ET.tostring(child, encoding='unicode'))
    description = ''.join(parts)
    #description = description.split('\n')[0]
    description = re.sub(' +', ' ', description)
    description = re.sub(r'<sub>(.*?)</sub>', r'~\1~', description)
    description = re.sub(r'<sup>(.*?)</sup>', r'^\1^', description)
    description = re.sub(r'<em>(.*?)</em>', r'*\1*', description)
    description = re.sub(r'<strong>(.*?)</strong>', r'**\1**', description)
    description = re.sub(r'<br\s*/?>', '  \n', description)
    description = re.sub(r'<a\s+href="([^"]*)"[^>]*>(.*?)</a>', r'[\2](\1)', description)
    description = re.sub(r'<code[^>]*>(.*?)</code>', r'`\1`', description)
    description = re.sub(r'<li>(.*?)</li>', r'- \1', description)
    description = re.sub(r'</?(?:ul|ol)>', '\n', description)
    description = re.sub(r'<[^>]+>', '', description)
    return description

def read_see_also(node):
    see_also = []
    see_also_node = node.find('see-also')
    if see_also_node is not None:
        for child in see_also_node:
            if child.tag in ('command-ref', 'enum-ref', 'struct-ref', 'script-function-ref'):
                see_also.append((child.tag, child.attrib.get('name', '')))
            else:
                see_also.append(ET.tostring(child))
    return see_also

def read_categories(node):
    categories = []
    for catnode in node.findall('categories/category'):
        categories.append(catnode.attrib['name'])
    return categories

def read_flag(node, name):
    if not isinstance(node, ET.Element):
        return False
    return node.attrib.get(name, '').strip().lower() in ('true', '1')
