import sys
import re
from typing import Optional
import xml.etree.ElementTree as ET

if sys.version_info < (3, 7):
    sys.exit("Python 3.7 or higher is required.")


issues = {}


def report_issue(kind: str, obj: object, msg: str) -> None:
    context_str = str(obj)
    if context_str not in issues:
        issues[context_str] = []
    issues[context_str].append((kind, msg))


class PropertyFlags:
    def __init__(self, flags_node: Optional[ET.Element]) -> None:
        self.readable = False
        self.writable = False
        self.removable = False
        self.deprecated = False
        self.silent = False
        self.constant = False
        self.modelhashexclude = False
        if flags_node is not None:
            for k, v in flags_node.attrib.items():
                if hasattr(self, k):
                    setattr(self, k, {'true': True, 'false': False}[v])


class PropertyInfo:
    def __init__(self, cinfo: ClassInfo, prop_node: ET.Element) -> None:
        assert isinstance(cinfo, ClassInfo)

        self.class_info = cinfo
        self.name = prop_node.attrib['name']
        self.type = prop_node.attrib['type']
        self.flags = PropertyFlags(prop_node.find('flags'))
        self.label = ''
        self.description = ''
        self.replaced_by = None
        self.migrate_to = None
        self.supersedes = None
        self.enum = None

        if support_node := prop_node.find('support'):
            self.start_support = support_node.attrib['start']
            self.end_support = support_node.attrib['end']
            self.start_deprecated = support_node.attrib['start-deprecated']
            if replaced_by_node := support_node.find('replaced-by'):
                self.replaced_by = replaced_by_node.attrib.get('name')
            if migrate_to_node := support_node.find('migrate-to'):
                self.migrate_to = migrate_to_node.attrib.get('name')
            if supersedes_node := support_node.find('supersedes'):
                self.supersedes = supersedes_node.attrib.get('name')
        if label_node := prop_node.find('label'):
            self.label = label_node.text
        if description_node := prop_node.find('description'):
            self.description = description_node.text
        if handle_node := prop_node.find('handle'):
            self.handle_type = handle_node.attrib.get('type', 'object')
        if enum_node := prop_node.find('enum'):
            self.enum = enum_node.attrib.get('name')

    def __str__(self):
        return f'{self.class_info!s}, property {self.name}'



class NamespaceInfo:
    def __init__(self, cinfo: ClassInfo, ns_node: ET.Element) -> None:
        assert isinstance(cinfo, ClassInfo)
        self.class_info = cinfo
        self.name = ns_node.attrib['name']
        self.new_property_forced_type = ns_node.attrib.get('new-property-forced-type', '')
        self.deprecated = ns_node.attrib.get('deprecated', False)

    def __str__(self):
        return f'{self.class_info!s}, namespace {self.name}'


class ParamInfo:
    def __init__(self, minfo: MethodInfo, param_node: ET.Element, parent: Optional[ParamInfo] = None) -> None:
        assert isinstance(minfo, MethodInfo)
        self.method_info = minfo
        self.array, self.item_type, self.size = False, None, None
        if isinstance(param_node, str):
            self.name = parent.name
            self.type = param_node
            return
        self.name = param_node.attrib['name']
        self.type = param_node.attrib['type']
        if m := re.match(r'^(\w+)\[(\d*)\]$', self.type):
            self.array, self.item_type, self.size = True, ParamInfo(minfo, m.group(1), self), int(m.group(2)) if m.group(2) else None
            self.type = f'{self.item_type.type}array{self.size or ""}'
        self.ref = self.array or self.type in ('string', 'buffer', 'vector3', 'color', 'matrix')
        desc_node = param_node.find('description')
        self.description = desc_node.text if desc_node is not None else ''

    def __str__(self):
        return f'{self.method_info!s}, param {self.name}'


class MethodInfo:
    def __init__(self, cinfo: ClassInfo, method_node: ET.Element) -> None:
        assert isinstance(cinfo, ClassInfo)
        self.class_info = cinfo
        self.name = method_node.attrib['name']
        self.params = []
        self.returns = []
        self.has_errors = False
        if params_node := method_node.find('params'):
            for n in params_node.findall('param'):
                try:
                    self.params.append(ParamInfo(self, n))
                except Exception:
                    self.has_errors = True
        if returns_node := method_node.find('returns'):
            for n in returns_node.findall('param'):
                try:
                    self.returns.append(ParamInfo(self, n))
                except Exception:
                    self.has_errors = True
        desc_node = method_node.find('description')
        self.description = desc_node.text if desc_node is not None else ''

    def __str__(self):
        return f'{self.class_info!s}, method {self.name}'


class ClassInfo:
    def __init__(self, name: str, superclass: Optional[str] = None) -> None:
        self.name = name
        self.superclass = superclass
        self.properties = {}
        self.namespaces = {}
        self.methods = {}

    def __str__(self):
        return f'class {self.name}'

    def add_property(self, name: str, pinfo: PropertyInfo):
        assert name not in self.properties
        assert isinstance(pinfo, PropertyInfo)
        self.properties[name] = pinfo

    def add_namespace(self, name: str, nsinfo: NamespaceInfo):
        assert name not in self.namespaces
        assert isinstance(nsinfo, NamespaceInfo)
        self.namespaces[name] = nsinfo

    def add_method(self, name: str, minfo: MethodInfo):
        assert name not in self.methods
        assert isinstance(minfo, MethodInfo)
        self.methods[name] = minfo


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
        cinfo = ClassInfo(
            name = object_class_node.attrib['name'],
            superclass = object_class_node.attrib.get('superclass'),
        )
        for property_node in object_class_node:
            if property_node.tag != 'property': continue
            pinfo = PropertyInfo(cinfo, property_node)
            #if pinfo.deprecated: continue
            if pinfo.type == 'group': continue
            cinfo.add_property(property_node.attrib['name'], pinfo)
        for ns_node in object_class_node:
            if ns_node.tag != 'namespace': continue
            nsinfo = NamespaceInfo(cinfo, ns_node)
            if nsinfo.deprecated: continue
            cinfo.add_namespace(ns_node.attrib['name'], nsinfo)
        for method_node in object_class_node:
            if method_node.tag != 'method': continue
            minfo = MethodInfo(cinfo, method_node)
            if minfo.has_errors: continue
            cinfo.add_method(method_node.attrib['name'], minfo)
        classes[object_class_node.attrib['name']] = cinfo

    if 'custom' not in classes:
        classes['custom'] = ClassInfo(name = 'custom', superclass = 'object')
        report_issue('warning', classes['custom'], 'class "custom" missing from classes (adding empty class)')

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
