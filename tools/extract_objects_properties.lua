local function log(...)
    local lfsx = require 'lfsx'
    print('[' .. lfsx.basename(sim.self.addOnPath) .. '] ' .. string.format(...))
end

function sysCall_init()
    sim = require 'sim-2'
    json = require 'dkjson'
    cbor = require 'simCBOR'
    lfsx = require 'lfsx'

    classInfo = {}
    superclass = {}
    flags = {'readable', 'writable', 'removable', 'silent', 'deprecated', 'constant'}
    typemap = table.invert(table.filter(sim, {matchKeyPrefix = 'propertytype_', stripKeyPrefix = true}))

    addOnDir = lfsx.dirname(sim.self.addOnPath)
    log('addOnDir = %s', addOnDir)

    local shapePath = lfsx.pathjoin(addOnDir, 'shape.simmodel.xml')
    log('shapePath = %s', shapePath)
    local shape = sim.scene:loadModel(shapePath)
    log('shape = %s', shape)
    log('shape.meshes = %s', shape.meshes)

    allHandles = {
        sim.app,
        sim.scene,
        sim.app:createObject{type = 'collection'},
        sim.scene.mainScript,
        sim.scene:createObject{type = 'drawingObject'},
        sim.scene:createObject{type = 'dummy'},
        sim.scene:createObject{type = 'joint'},
        sim.scene:createObject{type = 'camera'},
        sim.scene:createObject{type = 'marker'},
        sim.scene:createObject{type = 'shape', mesh = {}},
        sim.scene:createObject{type = 'script'},
        sim.scene:createObject{type = 'forceSensor'},
        sim.scene:loadModel(lfsx.pathjoin(addOnDir, 'graph.simmodel.xml')), --sim.scene:createObject{type = 'graph'},
        sim.scene:createObject{type = 'light'},
        sim.scene:createObject{type = 'ocTree'},
        sim.scene:createObject{type = 'pointCloud'},
        sim.scene:createObject{type = 'proximitySensor'},
        sim.scene:createObject{type = 'visionSensor'},
        sim.scene:loadModel(lfsx.pathjoin(addOnDir, 'shape.simmodel.xml')).meshes[1], --sim.scene:createObject{type = 'shape', mesh = {texture = {resolution = {2, 2}, image = string.rep('\x00', 3 * 4), rgba = false}}}.meshes[1],
    }

    local function setSuperClass(t, superClass)
        if superclass[t] == nil then
            log('superclass(%s) -> %s', t, superClass)
            superclass[t] = superClass
        end
    end

    local foundInconsistentFlags = false
    for _, h in ipairs(allHandles) do
        log('object %s:%d superClass=%s', h.type, h.handle, json.encode(h.metaInfo.superClass))
        local classHierarchy = table.add({h.type}, h.metaInfo.superClass)
        for i = 2, #classHierarchy do
            setSuperClass(classHierarchy[i-1], classHierarchy[i])
        end
        local info
        local ok, err = pcall(function()
            info = sim.getPropertiesInfos(h, {excludeFlags = 0})
        end)
        if not ok then
            error(string.format('target %d: %s', h.handle, err))
        end
        classInfo[h.type] = classInfo[h.type] or {properties = {}}
        --FIXME: namespace info is not reported in the correct class (typically: sceneObject) but in its subclasses
        --classInfo[h.type].namespaces = h.metaInfo.namespaces
        for pname, pinfo in pairs(info) do
            local pclass = pinfo.class or h.type
            local fullk = pclass .. '.' .. pname
            pinfo.type = typemap[pinfo.type]
            pinfo.flags.large = nil
            pinfo.flags.value = nil
            if pinfo.type == 'method' then goto continue end
            if pclass == 'app' and string.startswith(pname, 'namedParam.') then goto continue end
            if string.startswith(pname, 'customData.') then goto continue end
            if string.startswith(pname, 'signal.') then goto continue end
            if string.startswith(pname, 'refs.') then goto continue end
            if string.startswith(pname, 'origRefs.') then goto continue end
            classInfo[pclass] = classInfo[pclass] or {properties = {}}
            if classInfo[pclass].properties[pname] then
                if not table.eq(pinfo, classInfo[pclass].properties[pname]) then
                    printf('inconsistent property info for %s.%s', pclass, pname)
                    print(classInfo[pclass].properties[pname])
                    print(pinfo)
                    foundInconsistentFlags = true
                end
            else
                classInfo[pclass].properties[pname] = pinfo
            end
            ::continue::
        end
    end
    assert(not foundInconsistentFlags, 'found inconsistent flags')

    --FIXME: namespace info is not reported in the correct class (typically: sceneObject) but in its subclasses
    --       namespaces defined manually here:
    classInfo.app.namespaces = {
        customData = {},
        signal = {},
        namedParam = {},
    }
    classInfo.scene.namespaces = {
        customData = {},
        signal = {},
    }
    classInfo.sceneObject.namespaces = {
        customData = {},
        signal = {},
        refs = {newPropertyForcedType = 'handlearray'},
        origRefs = {newPropertyForcedType = 'handlearray'},
    }

    -- XXX: drawing objects currently do not have any exposed property
    classInfo.drawingObject.properties.cyclic = {type = 'bool'}
    classInfo.drawingObject.properties.maxCnt = {type = 'int'}
    classInfo.drawingObject.properties.overlay = {type = 'bool'}
    classInfo.drawingObject.properties.parentUid = {type = 'long'}
    classInfo.drawingObject.properties.size = {type = 'float'}
    classInfo.drawingObject.properties.itemType = {type = 'string'}
    classInfo.drawingObject.properties.points = {type = 'floatarray'}
    classInfo.drawingObject.properties.quaternions = {type = 'floatarray'}
    classInfo.drawingObject.properties.colors = {type = 'floatarray'}
    classInfo.drawingObject.properties.appendPoints = {type = 'floatarray'}
    classInfo.drawingObject.properties.appendQuaternions = {type = 'floatarray'}
    classInfo.drawingObject.properties.appendColors = {type = 'floatarray'}

    -- XXX: temporary
    classInfo.joint.properties.dynCtrlMode.enum = 'jointDynCtrlMode'
    classInfo.scene.properties.simulationState.enum = 'simulationState'

    objectsPropertiesXML = sim.app.namedParam.objects_properties_xml

    classesNode = {
        tag = 'object-classes',
        attrs = {},
        children = {},
    }

    classNames = table.keys(classInfo)
    table.sort(classNames)

    for _, className in ipairs(classNames) do
        local classNode = {
            tag = 'object-class',
            attrs = {
                name = className,
                superclass = superclass[className],
            },
            children = {},
        }
        table.insert(classesNode.children, classNode)
        local propertiesNames = table.keys(classInfo[className].properties)
        table.sort(propertiesNames)
        for _, propertyName in ipairs(propertiesNames) do
            local pinfo = classInfo[className].properties[propertyName]
            local propertyNode = {
                tag = 'property',
                attrs = {
                    name = propertyName,
                    type = pinfo.type,
                },
                children = {},
            }
            flgs = {}
            local flgs_def = {
                readable = true,
                writable = true,
                removable = false,
                deprecated = false,
                silent = false,
                constant = false,
            }
            for flg, v in pairs(pinfo.flags or {}) do
                if v ~= flgs_def[flg] then
                    table.insert(flgs, '"' .. flg .. '": ' .. (v and 'true' or 'false'))
                    propertyNode.attrs[flg] = (v and 'true' or 'false')
                end
            end
            if (classInfo[className].properties[propertyName].handleType or '') ~= '' then
                propertyNode.attrs['handle-type'] = classInfo[className].properties[propertyName].handleType
            end
            if (classInfo[className].properties[propertyName].label or '') ~= '' then
                propertyNode.attrs.label = classInfo[className].properties[propertyName].label
            end
            for _, attrName in ipairs{'enum', 'start-support', 'start-deprecated', 'end-support'} do
                local infoName = attrName:gsub('%-(.)', string.upper)
                propertyNode.attrs[attrName] = classInfo[className].properties[propertyName][infoName]
            end
            if (classInfo[className].properties[propertyName].description or '') ~= '' then
                local descrNode = {
                    tag = 'description',
                    attrs = {},
                    children = {classInfo[className].properties[propertyName].description},
                }
                table.insert(propertyNode.children, descrNode)
            end
            table.insert(classNode.children, propertyNode)
        end

        local namespacesNames = table.keys(classInfo[className].namespaces or {})
        table.sort(namespacesNames)
        for _, namespaceName in ipairs(namespacesNames) do
            local nsinfo = classInfo[className].namespaces[namespaceName]
            local namespaceNode = {
                tag = 'namespace',
                attrs = {
                    name = namespaceName,
                    ['new-property-forced-type'] = nsinfo.newPropertyForcedType,
                },
                children = {},
            }
            table.insert(classNode.children, namespaceNode)
        end
    end
    local attrOrder = {
        'name',
        'type',
        'handle-type',
        'deprecated',
        'readable',
        'writable',
        'removable',
        'silent',
        'constant',
        'enum',
        'label',
        'start-support',
        'start-deprecated',
        'end-support',
    }
    local file = io.open(objectsPropertiesXML, 'w')
    if file then
        file:write(string.renderxml(classesNode, attrOrder))
        file:close()
    else
        print('Error: Could not open output file ' .. objectsPropertiesXML)
    end

    enumsXML = sim.app.namedParam.enums_xml
    enumsNode = {
        tag = 'enums',
        attrs = {},
        children = {},
    }
    for _, enumName in ipairs(sim.app.enumTypes) do
        log('enum: %s', enumName)
        local enumNode = {
            tag = 'enum',
            attrs = {name = enumName},
            children = {},
        }
        local info = sim.app:getEnumInfo(enumName)
        -- sort entries by value:
        local entries = {}
        for k, v in pairs(info) do
            table.insert(entries, {k, v})
        end
        table.sort(entries, function(a, b) return a[2] < b[2] end)
        for _, entry in ipairs(entries) do
            local k, v = table.unpack(entry)
            table.insert(enumNode.children, {
                tag = 'item',
                attrs = {name = k, value = v},
                children = {},
            })
        end
        table.insert(enumsNode.children, enumNode)
    end
    local file = io.open(enumsXML, 'w')
    if file then
        file:write(string.renderxml(enumsNode, attrOrder))
        file:close()
    else
        print('Error: Could not open output file ' .. enumsXML)
    end

    sim.app:quit()
end
