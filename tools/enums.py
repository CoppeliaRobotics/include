import sys
import re
from cplusplus import *

if sys.version_info < (3, 7):
    sys.exit("Python 3.7 or higher is required.")

def get_enums(enums_xml):
    import xml.etree.ElementTree as ET
    tree = ET.parse(enums_xml)
    enums_root = tree.getroot()
    assert enums_root.tag == 'enums'
    return {
        enum.attrib['name']: {
            item.attrib['name']: item.attrib['value']
            for item in enum
            if item.tag == 'item'
        }
        for enum in enums_root
        if enum.tag == 'enum'
    }
