#!/usr/bin/env python3

import re
import sys

re_define = re.compile(r'^#define\s+([A-Z0-9_]+)_PROPERTIES\s*\\')
re_func = re.compile(r'^\s*FUNCX\(([^,]+),\s*"([^"]+)"')
re_strippfx = re.compile(r'^(DEPRECATED|GROUP|METHOD)_')

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
        if m := re_define.match(line):
            k = m.group(1).lower()
            cur = out[k] = {}
        elif m := re_func.match(line):
            group = m.group(1)
            prop = m.group(2)
            group = re.sub(re_strippfx, '', group)
            if prop != group:
                cur[prop] = group

for k, d in out.items():
    k = [h for h in classes if h.lower() == k][0]
    print(f'    \'{k}\': {{')
    for p, v in d.items():
        print(f'        \'{p}\': \'{v}\',')
    print(f'    }},')
