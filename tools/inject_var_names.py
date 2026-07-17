#!/usr/bin/env python3
import sys
import csv
import xml.etree.ElementTree as ET

if len(sys.argv) != 4:
    print(f'usage: {sys.argv[0]} <input-xml> <var-names-csv> <output-xml>')
    sys.exit(1)

xml_input, csv_input, xml_output = sys.argv[1:]

tree = ET.parse(xml_input)
root = tree.getroot()

# Index properties by (object-class name, property name)
properties = {}
methods = {}
for obj_class in root.findall("object-class"):
    class_name = obj_class.get("name")
    for prop in obj_class.findall("property"):
        properties[(class_name, prop.get("name"))] = prop
    for met in obj_class.findall("method"):
        methods[(class_name, met.get("name"))] = met

missing = []

if csv_input == "-":
    csv_file = sys.stdin
else:
    csv_file = open(csv_input, newline="", encoding="utf-8")

with csv_file as f:
    for row in csv.DictReader(f):
        key = (row["object_class"], row["property"])
        if (prop := properties.get(key)) is not None:
            prop.set("var", row["var"])
            prop.set("aux", ','.join([row["i1"], row["i2"], row["i3"], row["i4"], row["i5"]]))
        elif (met := methods.get(key)) is not None:
            met.set("var", row["var"])
        else:
            missing.append(key)
            continue

ET.indent(tree, space=(' ' * 4))
tree.write(xml_output, encoding="utf-8", xml_declaration=True)

if missing:
    print("No matching property found for:")
    for class_name, prop_name in missing:
        print(f"  object-class={class_name!r}, property={prop_name!r}")
else:
    print("All edits applied.")
