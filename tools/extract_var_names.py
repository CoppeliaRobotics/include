#!/usr/bin/env python3

import re
import sys

re_define = re.compile(r'^#define\s+([A-Z0-9_]+)_PROPERTIES\s*\\')
re_func = re.compile(r'^\s*FUNCX\((.*)\)')
re_strippinfo = re.compile(r'PropertyInfo\(\{.*\}\)')

out = {}
cur = {}

classes = ['object', 'app', 'detachedScript', 'mesh', 'collection',
    'scene', 'customObject', 'sceneObject', 'marker', 'shape',
    'proximitySensor', 'visionSensor', 'camera', 'graph', 'ocTree',
    'pointCloud', 'joint', 'drawingObject', 'dummy', 'forceSensor',
    'light', 'script', 'customObjectClass', 'customSceneObjectClass',
    'customSceneObject', 'stack', 'color']

with open(sys.argv[1], encoding="utf-8") as f:
    for line in f:
        line = re.sub(re_strippinfo, '0', line)
        if m := re_define.match(line):
            k = m.group(1).lower()
            cur = out[k] = {}
        elif m := re_func.match(line):
            fields = [x.strip() for x in m.group(1).split(',')]
            var, pname, ptype, pflags, pinfo, i1, i2, i3, i4, i5 = fields
            if pname[0] == '"' and pname[-1] == '"':
                pname = pname[1:-1]
            cur[pname] = (var, i1, i2, i3, i4, i5)

print('object_class,property,var,i1,i2,i3,i4,i5')
for k, d in out.items():
    k = [h for h in classes if h.lower() == k][0]
    for p, vs in d.items():
        print(k, p, *vs, sep=',')
