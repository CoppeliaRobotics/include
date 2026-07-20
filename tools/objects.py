from __future__ import annotations
import sys
import re
from typing import Optional, Any
import xml.etree.ElementTree as ET

if sys.version_info < (3, 7):
    sys.exit("Python 3.7 or higher is required.")


classes = {}
functions = {}
enums = {}

issues = {}


def report_issue(kind: str, obj: object, msg: str) -> None:
    context_str = str(obj)
    if context_str not in issues:
        issues[context_str] = []
    issues[context_str].append((kind, msg))


def bool_from_str(s: Optional[str], default: Optional[bool] = None) -> bool:
    if s is None and default is not None: return default
    if s == 'true': return True
    if s == 'false': return False
    raise Exception(f'invalid value for bool: {s!s}')


class PropertyFlags:
    def __init__(self, info: PropertyInfo | MethodInfo, flags_node: Optional[ET.Element] = None) -> None:
        if isinstance(info, PropertyInfo):
            self.property_info = info
        elif isinstance(info, MethodInfo):
            self.method_info = info

        self.readable = False
        self.writable = False
        self.removable = False
        self.deprecated = False
        self.silent = False
        self.constant = False
        self.modelhashexclude = False

        if flags_node is not None:
            assert flags_node.tag == 'flags'
            for k, v in flags_node.attrib.items():
                if hasattr(self, k):
                    setattr(self, k, bool_from_str(v))


class PropertyInfo:
    def __init__(self, cinfo: ClassInfo, prop_node: ET.Element) -> None:
        assert isinstance(cinfo, ClassInfo)
        assert prop_node.tag == 'property', 'invalid node tag'
        assert 'name' in prop_node.attrib, 'missing "name" attribute'
        assert 'type' in prop_node.attrib, 'missing "type" attribute'

        self.class_info = cinfo
        self.name = prop_node.attrib['name']
        self.type = prop_node.attrib['type']
        self.flags = PropertyFlags(self, prop_node.find('flags'))
        self.label = ''
        self.description = ''
        self.replaced_by = None
        self.migrate_to = None
        self.supersedes = None
        self.enum = None
        self.var = prop_node.attrib.get('var')
        self.aux = []
        if auxStr := prop_node.attrib.get('aux'):
            self.aux = auxStr.split(',')

        if (support_node := prop_node.find('support')) is not None:
            self.start_support = support_node.attrib['start']
            self.end_support = support_node.attrib['end']
            self.start_deprecated = support_node.attrib['start-deprecated']

        if (replaced_by_node := prop_node.find('replaced-by')) is not None:
            assert 'name' in replaced_by_node.attrib, 'missing "name" attribute in <replaced-by>'
            self.replaced_by = replaced_by_node.attrib.get('name')

        if (migrate_to_node := prop_node.find('migrate-to')) is not None:
            assert 'name' in migrate_to_node.attrib, 'missing "name" attribute in <migrate-to>'
            self.migrate_to = migrate_to_node.attrib.get('name')

        if (supersedes_node := prop_node.find('supersedes')) is not None:
            self.supersedes = []
            for node in supersedes_node.findall('item'):
                assert 'name' in node.attrib, 'missing "name" attribute in <supersedes>/<item>'
                self.supersedes.append(node.attrib.get('name'))

        if (label_node := prop_node.find('label')) is not None:
            self.label = label_node.text

        if (description_node := prop_node.find('description')) is not None:
            self.description = description_node.text

        if (handle_node := prop_node.find('handle')) is not None:
            self.handle_type = handle_node.attrib.get('type', 'object')

        if (enum_node := prop_node.find('enum')) is not None:
            self.enum = enum_node.attrib.get('name')

    def __str__(self):
        return f'{self.class_info!s}, property {self.name}'



class NamespaceInfo:
    def __init__(self, cinfo: ClassInfo, ns_node: ET.Element) -> None:
        assert isinstance(cinfo, ClassInfo)
        assert ns_node.tag == 'namespace', 'invalid node tag'
        assert 'name' in ns_node.attrib, 'missing "name" attribute'

        self.class_info = cinfo
        self.name = ns_node.attrib['name']
        self.new_property_forced_type = ns_node.attrib.get('new-property-forced-type', '')
        self.deprecated = ns_node.attrib.get('deprecated', False)

    def __str__(self):
        return f'{self.class_info!s}, namespace {self.name}'


class ParamInfo:
    def __init__(self, minfo: MethodInfo, param_node: ET.Element, accepts_defaults: bool, parent: Optional[ParamInfo] = None, type: Optional[str] = None) -> None:
        assert isinstance(minfo, MethodInfo)
        assert param_node.tag == 'param', 'invalid node tag'
        assert 'name' in param_node.attrib, 'missing "name" attribute'
        assert 'type' in param_node.attrib, 'missing "type" attribute'

        self.method_info = minfo
        self.array, self.item_type, self.size = False, None, None
        if parent:
            self.name = parent.name
            self.type = type
            return
        self.name = param_node.attrib['name']
        self.type = param_node.attrib['type']
        if m := re.match(r'^(\w+)\[(\d*)\]$', self.type):
            self.array, self.item_type, self.size = True, ParamInfo(minfo, param_node, accepts_defaults, self, m.group(1)), int(m.group(2)) if m.group(2) else None
            self.type = f'{self.item_type.type}array{self.size or ""}'
        self.ref = self.array or self.type in ('string', 'buffer', 'vector3', 'color', 'matrix')
        self.description = ''

        if accepts_defaults:
            self.default = param_node.attrib.get('default')
        elif 'default' in param_node.attrib:
            raise Exception('attribute "default" not allowed here')

        if (description_node := param_node.find('description')) is not None:
            self.description = description_node.text

    def __str__(self):
        return f'{self.method_info!s}, param {self.name}'


class MethodInfo:
    def __init__(self, cinfo: ClassInfo, method_node: ET.Element, tag: str) -> None:
        assert isinstance(cinfo, ClassInfo)
        assert method_node.tag == tag, 'invalid node tag'
        assert 'name' in method_node.attrib, 'missing "name" attribute'

        self.class_info = cinfo
        self.name = method_node.attrib['name']
        self.type = 'method'
        self.lang = method_node.attrib['lang']
        self.flags = PropertyFlags(self)
        self.flags.silent = True
        self.flags.constant = True
        self.flags.modelhashexclude = True
        self.var = method_node.attrib.get('var')
        self.aux = []
        self.params = []
        self.returns = []
        self.has_errors = False
        self.description = ''

        if (params_node := method_node.find('params')) is not None:
            for n in params_node.findall('param'):
                try:
                    self.params.append(ParamInfo(self, n, True))
                except Exception:
                    self.has_errors = True

        if (returns_node := method_node.find('returns')) is not None:
            for n in returns_node.findall('param'):
                try:
                    self.returns.append(ParamInfo(self, n, False))
                except Exception:
                    self.has_errors = True

        if (description_node := method_node.find('description')) is not None:
            self.description = description_node.text

    def __str__(self):
        return f'{self.class_info!s}, method {self.name}'


class ClassInfo:
    def __init__(self, object_class_node: ET.Element) -> None:
        assert object_class_node.tag == 'object-class', 'invalid node tag'
        assert 'name' in object_class_node.attrib, 'missing "name" attribute'

        self.name = object_class_node.attrib['name']
        self.superclass = object_class_node.attrib.get('superclass')
        self.properties = {}
        self.methods = {}
        self.namespaces = {}

        for property_node in object_class_node.findall('property'):
            pinfo = PropertyInfo(self, property_node)
            self.properties[pinfo.name] = pinfo

        for method_node in object_class_node.findall('method'):
            minfo = MethodInfo(self, method_node, 'method')
            if minfo.has_errors: continue
            self.methods[minfo.name] = minfo

        for ns_node in object_class_node.findall('namespace'):
            nsinfo = NamespaceInfo(self, ns_node)
            self.namespaces[nsinfo.name] = nsinfo

    def __str__(self):
        return f'class {self.name}'

    def get_superclass(self):
        return classes.get(self.superclass)

    def get_method(self, method_name: str, *, search_superclasses: bool = True):
        c = self
        while c:
            if c.methods[method_name]:
                return c.methods[method_name]
            if not search_superclasses:
                return
            c = c.get_superclass()


class EnumInfo:
    def __init__(self, enum_node: ET.Element) -> None:
        assert enum_node.tag == 'enum', 'invalid node tag'
        assert 'name' in enum_node.attrib, 'missing "name" attribute'

        self.name = enum_node.attrib['name']
        self.label = enum_node.attrib.get('label', '')
        self.items = {}
        v = 0
        for item_node in enum_node.findall('item'):
            assert 'name' in item_node.attrib, 'missing "name" attribute'
            name = item_node.attrib['name']
            value = int(item_node.attrib.get('value', v))
            v += 1
            self.items[name] = value


def sorted_classes(mapping):
    """
    mapping: dict[class -> superclass or None]
    Returns classes sorted so that superclasses appear before subclasses.
    """
    # Build adjacency: superclass -> [subclasses]
    children = {}
    indegree = {}  # number of superclasses each class depends on (0 = root)

    # Initialize
    for cls, sup in mapping.items():
        indegree.setdefault(cls, 0)
        if sup is not None:
            indegree.setdefault(sup, 0)
            # cls depends on sup
            indegree[cls] += 1
            children.setdefault(sup, []).append(cls)
        else:
            children.setdefault(cls, [])

    # Kahn's algorithm: BFS topological sort
    queue = [cls for cls, deg in indegree.items() if deg == 0]
    order = []

    while queue:
        cls = queue.pop(0)
        order.append(cls)
        for child in children.get(cls, []):
            indegree[child] -= 1
            if indegree[child] == 0:
                queue.append(child)

    return order

def get_classes(object_classes_xml):
    tree = ET.parse(object_classes_xml)
    object_classes_root = tree.getroot()
    assert object_classes_root.tag == 'object-classes'
    classes = {}
    for object_class_node in object_classes_root:
        if object_class_node.tag != 'object-class': continue
        try:
            cinfo = ClassInfo(object_class_node)
            classes[cinfo.name] = cinfo
        except Exception as e:
            raise Exception(f'error in class "{object_class_node.attrib["name"]}"')

    # resolve superclass:
    for c in classes.values():
        if isinstance(c.superclass, str):
            c.superclass = classes.get(c.superclass)

    # remove classes without a superclass:
    for className in [n for n, c in classes.items() if c.superclass is None]:
        if className == 'object': continue
        report_issue('error', classes[className], "ignored because it doesn't have a superclass")
        del classes[className]

    # sort classes in topological order:
    topo_order = sorted_classes({k: v.superclass.name if v.superclass else None for k, v in classes.items()})
    classes = {k: classes[k] for k in topo_order}
    # sort properties in alphabetical order:
    for c in classes.values():
        c.properties = {pn: c.properties[pn] for pn in sorted(c.properties.keys())}

    for context_str in sorted(issues.keys()):
        for kind, msg in sorted(issues[context_str]):
            print(f'{context_str}: {kind}: {msg}')

    return classes
