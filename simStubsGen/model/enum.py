from .parse import *

class Enum(object):
    def __init__(self, plugin, node):
        if node.tag != 'enum':
            raise ValueError('expected <enum>, got <%s>' % node.tag)
        self.plugin = plugin
        self.name = node.attrib['name']
        self.item_prefix = node.attrib.get('item-prefix', '')
        self.base = int(node.attrib.get('base', 0))
        self.items = [type('', (), {
                'name': n.attrib['name'],
                'value': n.attrib.get('value', self.base + i),
                'description': read_description(n),
            }) for i, n in enumerate(node.findall('item'))]
        self.description = read_description(node)
        self.see_also = read_see_also(node)
        self.categories = read_categories(node)
