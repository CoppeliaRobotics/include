import sys
import fnmatch
import re
import cplusplus
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


def parse_bool(attr_value: str, default: bool = False) -> bool:
    if attr_value is None:
        return default
    return attr_value.lower() in ('true', '1', 'yes')


def cppBool(b: bool) -> str:
    return 'true' if b else 'false'


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
                    setattr(self, k, parse_bool(v))


class PropertyInfo:
    ignored_properties = {
        'pointCloud': {
            'points',
            'colors',
        },
        'ocTree': {
            'voxels',
            'colors',
        },
    }

    renamed_properties = {
        'sceneObject': {
            'parent': 'parent_',  # used by QObject
            'children': 'children_',  # used by QObject
        },
        'drawingObject': {
            'parent': 'parent_',  # used by QObject
        },
    }

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

        self.ignored = any(fnmatch.fnmatchcase(self.name, ipn) for ipn in PropertyInfo.ignored_properties.get(cinfo.name, set()))
        if self.type == 'method': self.ignored = True # temp workaround

        if support_node := prop_node.find('support'):
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

    @property
    def normalizedName(self):
        return self.name.replace('.', '_')

    @property
    def cppMemberName(self):
        return f'{self.qpropertyName}_'

    @property
    def cppType(self):
        handleType = getattr(self, 'handle-type', 'object')
        handleClass = 'sim::' + handleType[0].upper() + handleType[1:]
        match self.type:
            case 'bool':
                return 'bool'
            case 'color':
                return 'QColor'
            case 'buffer':
                return 'QByteArray'
            case 'long':
                return 'int64_t'
            case 'float':
                return 'double'
            case 'floatarray':
                return 'QList<double>'
            case 'floatarray2':
                return 'QList<double>'
            case 'pose':
                return 'Pose'
            case 'int':
                return 'int32_t'
            case 'intarray':
                return 'QList<int32_t>'
            case 'intarray2':
                return 'QList<int32_t>'
            case 'handle':
                return f'{handleClass} *'
            case 'handlearray':
                return f'QList<{handleClass} *>'
            case 'string':
                return 'QString'
            case 'stringarray':
                return 'QList<QString>'
            case 'vector3':
                return 'QVector3D'
            case 'quaternion':
                return 'QQuaternion'
            case 'matrix':
                return 'Matrix'
            case 'enum':
                return 'int'
            case _:
                raise TypeError(f'unhandled type: {self.type}')

    @property
    def cppPropertySetter(self):
        match self.type:
            case 'bool':
                return 'setBoolProperty'
            case 'color':
                return 'setColorProperty'
            case 'buffer':
                return 'setBufferProperty'
            case 'long':
                return 'setLongProperty'
            case 'float':
                return 'setFloatProperty'
            case 'floatarray':
                return 'setFloatArrayProperty'
            case 'floatarray2':
                return 'setFloatArray2Property'
            case 'pose':
                return 'setPoseProperty'
            case 'int':
                return 'setIntProperty'
            case 'intarray':
                return 'setIntArrayProperty'
            case 'intarray2':
                return 'setIntArray2Property'
            case 'handle':
                return 'setHandleProperty'
            case 'handlearray':
                return 'setHandleArrayProperty'
            case 'string':
                return 'setStringProperty'
            case 'stringarray':
                return 'setStringArrayProperty'
            case 'vector3':
                return 'setVector3Property'
            case 'quaternion':
                return 'setQuaternionProperty'
            case 'matrix':
                return 'setMatrixProperty'
            case 'enum':
                return 'setIntProperty'
            case _:
                raise TypeError(f'unhandled type: {self.type}')

    @property
    def cppHandleType(self):
        handleType = getattr(self, 'handle_type', 'object')
        handleClass = 'sim::' + handleType[0].upper() + handleType[1:]
        match self.type:
            case 'handle' | 'handlearray':
                return handleClass

    @property
    def cppTypeFuncArg(self):
        match self.type:
            case 'buffer' | 'floatarray' | 'intarray' | 'handlearray' | 'string' | 'stringarray':
                return f'const {self.cppType} &'
            case _:
                return self.cppType

    @property
    def qpropertyName(self):
        return PropertyInfo.renamed_properties.get(self.class_info.name, {}).get(self.normalizedName, self.normalizedName)

    @property
    def qpropertyGetter(self):
        return self.qpropertyName

    @property
    def qpropertySetter(self):
        pname = self.qpropertyName
        return f'set{pname[0].upper()}{pname[1:]}'

    @property
    def qpropertyNotify(self):
        pname = self.qpropertyName
        return f'{pname}Changed'


class NamespaceInfo:
    def __init__(self, cinfo: ClassInfo, ns_node: ET.Element) -> None:
        assert isinstance(cinfo, ClassInfo)
        self.class_info = cinfo
        self.name = ns_node.attrib['name']
        self.new_property_forced_type = ns_node.attrib.get('new-property-forced-type', '')
        self.ignored = False
        self.deprecated = ns_node.attrib.get('deprecated', False)

    def __str__(self):
        return f'{self.class_info!s}, namespace {self.name}'


class ParamInfo:
    valid_types = {
        'bool', 'int', 'long', 'float', 'string', 'buffer',
        'vector3', 'quaternion', 'pose', 'matrix',
        'color', 'handle', 'handlearray',
        'intarray', 'floatarray', 'stringarray', 'colorarray', 'quaternionarray',
        'intarray2', 'floatarray2', 'floatarray3',
        'map',
    }

    fallback_types = {
        'handlearray2': 'handlearray',
    }

    def __init__(self, minfo: MethodInfo, param_node: ET.Element) -> None:
        assert isinstance(minfo, MethodInfo)
        self.method_info = minfo
        self.array, self.item_type, self.size = False, None, None
        if isinstance(param_node, str):
            self.type = param_node
            return
        self.name = param_node.attrib['name']
        self.type = param_node.attrib['type']
        if m := re.match(r'^(\w+)\[(\d*)\]$', self.type):
            self.array, self.item_type, self.size = True, ParamInfo(minfo, m.group(1)), int(m.group(2)) if m.group(2) else None
            self.type = f'{self.item_type.type}array{self.size or ""}'
        if self.type in ParamInfo.fallback_types:
            report_issue('warning', self, f'type {self.type} is not a valid type, using {ParamInfo.fallback_types[self.type]}')
            self.type = ParamInfo.fallback_types[self.type]
        self.ref = self.array or self.type in ('string', 'buffer', 'vector3', 'color', 'matrix')
        desc_node = param_node.find('description')
        self.description = desc_node.text if desc_node is not None else ''
        if self.type not in ParamInfo.valid_types:
            report_issue('error', self, f'type {self.type} is not a valid type')
            raise ValueError('bad type: ' + self.type)

    def __str__(self):
        return f'{self.method_info!s}, param {self.name}'

    @property
    def cppName(self):
        return cplusplus.fix_reserved_name(self.name, suffix='_')

    @property
    def cppType(self):
        if self.type == 'float':
            return 'double'
        if self.type == 'string':
            return 'QString'
        if self.type == 'buffer':
            return 'QByteArray'
        if self.type == 'handle':
            return 'handle_t'
        if self.type == 'vector3':
            return 'QVector3D'
        if self.type == 'quaternion':
            return 'QQuaternion'
        if self.type == 'pose':
            return 'Pose'
        if self.type == 'matrix':
            return 'Matrix'
        if self.type == 'color':
            return 'QColor'
        if self.type == 'map':
            return 'QVariantMap'
        if self.type == 'any':
            return 'QVariant'
        if self.array:
            return f'QList<{self.item_type.cppType}>' + (f' /* [{self.size}] */' if self.size else '')
        return self.type

    @property
    def cppDecl(self):
        return f'{self.cppType} {self.cppName}'

    @property
    def cppDeclRef(self):
        if self.ref:
            return f'const {self.cppType} &{self.cppName}'
        else:
            return self.cppDecl


class MethodInfo:
    ignored_methods = {
        'object': {
            'getProperty',
            'setProperty',
            'getProperties',
            'setProperties',
            'getPropertiesInfos',
        },
        'detachedScript': {
            'callFunction',
            'getFunctions',
            'executeString',
        },
    }

    renamed_methods = {
        'sceneObject': {
            'setAlias': 'setAliasEx',  # clash with 'alias' property setter
        },
    }

    def __init__(self, cinfo: ClassInfo, method_node: ET.Element) -> None:
        assert isinstance(cinfo, ClassInfo)
        self.class_info = cinfo
        self.name = method_node.attrib['name']
        self.ignored = any(fnmatch.fnmatchcase(self.name, imn) for imn in MethodInfo.ignored_methods.get(cinfo.name, set()))
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

    @property
    def normalizedName(self):
        return self.name.replace('.', '_')

    @property
    def cppName(self):
        return MethodInfo.renamed_methods.get(self.class_info.name, {}).get(self.normalizedName, self.normalizedName)

    @property
    def cppArgs(self):
        return ', '.join(p.cppDeclRef for p in self.params)

    @property
    def cppRets(self):
        if len(self.returns) == 0: return 'void'
        if len(self.returns) == 1: return self.returns[0].cppType
        return 'QVariantList'


class ClassInfo:
    renamed_classes = {
        'drawingObject': 'DrawingObjectBase',
        'marker': 'MarkerBase',
        'ocTree': 'OcTreeBase',
        'pointCloud': 'PointCloudBase',
    }

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

    @property
    def cppClassName(self):
        n = self.name[0].upper() + self.name[1:]
        return ClassInfo.renamed_classes.get(self.name, n)


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
            if pinfo.ignored: continue
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
            if minfo.ignored or minfo.has_errors: continue
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
