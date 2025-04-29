#include <simPlusPlus/Lib.h>
#include <simPlusPlus/Plugin.h>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

namespace sim
{

static bool debugStackEnabled = false;

api_error::api_error(const std::string &func_)
    : api_error(func_, "")
{
}

static std::string getLastError_noexcept()
{
    char *ret = simGetLastError();
    if(!ret) return "unknown error";
    std::string s(ret);
    releaseBuffer(ret);
    return s;
}

api_error::api_error(const std::string &func_, const std::string &error_)
    : func(func_),
      error((error_.empty() ? "" : (error_ + std::string(": "))) + getLastError_noexcept()),
      exception("%s: %s", func_, error_)
{
}

void enableStackDebug()
{
    debugStackEnabled = true;
}

void disableStackDebug()
{
    debugStackEnabled = false;
}

bool isStackDebugEnabled()
{
    return debugStackEnabled;
}

#ifndef NDEBUG

template<typename... Arguments>
void addStackDebugLog(const std::string &fmt, Arguments&&... args)
{
    if(debugStackEnabled)
    {
        auto msg = util::sprintf(fmt, std::forward<Arguments>(args)...);
        addLog(sim_verbosity_debug, "STACK DEBUG: %s", msg);
    }
}

static void addStackDebugDump(handle_t stackHandle)
{
    if(debugStackEnabled)
        debugStack(stackHandle);
}

#else // RELEASE
#define addStackDebugLog(...)
#define addStackDebugDump(x)
#endif

int programVersion()
{
    int simVer = sim::getInt32Param(sim_intparam_program_version);
    int simRev = sim::getInt32Param(sim_intparam_program_revision);
    simVer = simVer * 100 + simRev;
    return simVer;
}

std::string versionString(int v)
{
    int revision = v % 100;
    v /= 100;
    int patch = v % 100;
    v /= 100;
    int minor = v % 100;
    v /= 100;
    int major = v % 100;
    return util::sprintf("%d.%d.%drev%d", major, minor, patch, revision);
}

// int simRunSimulator(const char *applicationName, int options, void(*initCallBack)(), void(*loopCallBack)(), void(*deinitCallBack)());

// int simRunSimulatorEx(const char *applicationName, int options, void(*initCallBack)(), void(*loopCallBack)(), void(*deinitCallBack)(), int stopDelay, const char *sceneOrModelToLoad);

// char *simGetSimulatorMessage(int *messageID, int *auxiliaryData, int *returnedDataSize);

void * getMainWindow(int type)
{
    return simGetMainWindow(type);
}

std::string getLastError()
{
    char *ret = simGetLastError();
    if(ret == NULL)
        throw api_error("simGetLastError");
    std::string s(ret);
    releaseBuffer(ret);
    return s;
}

void setBoolParam(int parameter, bool value)
{
    if(simSetBoolParam(parameter, value) == -1)
        throw api_error("simSetBoolParameter");
}

bool getBoolParam(int parameter)
{
    int ret;
    if((ret = simGetBoolParam(parameter)) == -1)
        throw api_error("simGetBoolParam");
    return ret > 0;
}

void setInt32Param(int parameter, int value)
{
    if(simSetInt32Param(parameter, value) == -1)
        throw api_error("simSetInt32Param");
}

int getInt32Param(int parameter)
{
    int ret;
    if(simGetInt32Param(parameter, &ret) == -1)
        throw api_error("simGetInt32Param");
    return ret;
}

unsigned long long int getUInt64Param(int parameter)
{
    unsigned long long int ret;
    if(simGetUInt64Param(parameter, &ret) == -1)
        throw api_error("simGetUInt64Param");
    return ret;
}

void setStringParam(int parameter, char *value)
{
    if(simSetStringParam(parameter, value) == -1)
        throw api_error("simSetStringParam");
}

void setStringParam(int parameter, const std::string &value)
{
    if(simSetStringParam(parameter, value.c_str()) == -1)
        throw api_error("simSetStringParam");
}

std::string getStringParam(int parameter)
{
    char *ret;
    if((ret = simGetStringParam(parameter)) == nullptr)
        throw api_error("simGetStringParam");
    std::string s(ret);
    releaseBuffer(ret);
    return s;
}

void setNamedStringParam(const std::string &parameter, const std::string &value)
{
    if(simSetNamedStringParam(parameter.c_str(), value.c_str(), value.size()) == -1)
        throw api_error("simSetNamedStringParam");
}

void setNamedBoolParam(const std::string &parameter, bool value)
{
    setNamedStringParam(parameter, value ? "true" : "false");
}

void setNamedFloatParam(const std::string &parameter, double value)
{
    setNamedStringParam(parameter, std::to_string(value));
}

void setNamedInt32Param(const std::string &parameter, int value)
{
    setNamedStringParam(parameter, std::to_string(value));
}

std::optional<std::string> getNamedStringParam(const std::string &parameter)
{
    char *ret;
    int len;
    if((ret = simGetNamedStringParam(parameter.c_str(), &len)) == NULL)
        return {};
    std::string s(ret, len);
    releaseBuffer(ret);
    return s;
}

std::optional<bool> getNamedBoolParam(const std::string &parameter)
{
    auto v = getNamedStringParam(parameter);
    if(!v) return {};
    auto s = *v;
    if(s == "true") return true;
    if(s == "false") return false;
    if(s == "on") return true;
    if(s == "off") return false;
    if(s == "1") return true;
    if(s == "0") return false;
    throw api_error("simGetNamedBoolParam");
}

std::optional<double> getNamedFloatParam(const std::string &parameter)
{
    auto v = getNamedStringParam(parameter);
    if(!v) return {};
    return std::stod(*v);
}

std::optional<int> getNamedInt32Param(const std::string &parameter)
{
    auto v = getNamedStringParam(parameter);
    if(!v) return {};
    return std::stoi(*v);
}

handle_t getObject(const char *objectPath, int index, handle_t proxy, int options)
{
    handle_t handle = simGetObject(objectPath, index, proxy, options);
    if(handle == -1)
        throw api_error("simGetObject");
    return handle;
}

handle_t getObject(const std::string &objectPath, int index, handle_t proxy, int options)
{
    return getObject(objectPath.c_str(), index, proxy, options);
}

handle_t getObject(const std::string &objectPath, int index, handle_t proxy, bool noError)
{
    int options = 0;
    if(noError) options |= 1;
    return getObject(objectPath, index, proxy, options);
}

handle_t getObject(const std::string &objectPath, int index, handle_t proxy)
{
    return getObject(objectPath, index, proxy, 0);
}

long long int getObjectUid(handle_t objectHandle)
{
    long long int ret = simGetObjectUid(objectHandle);
    if(ret == -1)
        throw api_error("simGetObjectUid");
    return ret;
}

handle_t getObjectFromUid(long long int uid, int options)
{
    handle_t handle = simGetObjectFromUid(uid, options);
    if(handle == -1)
        throw api_error("simGetObjectFromUid");
    return handle;
}

handle_t getObjectFromUid(long long int uid, bool noError)
{
    int options = 0;
    if(noError) options |= 1;
    return getObjectFromUid(uid, options);
}

handle_t getScriptHandleEx(int scriptType, handle_t objHandle, std::optional<std::string> scriptName)
{
    return simGetScriptHandleEx(scriptType, objHandle, scriptName ? scriptName->c_str() : nullptr);
}

void removeObjects(const std::vector<handle_t> &objectHandles)
{
    if(simRemoveObjects(objectHandles.data(), objectHandles.size()) == -1)
        throw api_error("simRemoveObjects");
}

int removeModel(handle_t objectHandle)
{
    int n = simRemoveModel(objectHandle);
    if(n == -1)
        throw api_error("simRemoveModel");
    return n;
}

std::string getObjectAlias(handle_t objectHandle, int options)
{
    char *ret;
    if((ret = simGetObjectAlias(objectHandle, options)) == NULL)
        throw api_error("simGetObjectAlias");
    std::string s(ret);
    releaseBuffer(ret);
    return s;
}

void setObjectAlias(handle_t objectHandle, const std::string &alias, int options)
{
    if(simSetObjectAlias(objectHandle, alias.c_str(), options) == -1)
        throw api_error("simSetObjectAlias");
}

handle_t getObjectParent(handle_t objectHandle)
{
    return simGetObjectParent(objectHandle);
}

handle_t getObjectChild(handle_t objectHandle, int index)
{
    return simGetObjectChild(objectHandle, index);
}

std::vector<handle_t> getObjectChildren(handle_t objectHandle)
{
    std::vector<handle_t> ret;
    handle_t childHandle;
    for(int index = 0; ; index++)
    {
        if((childHandle = simGetObjectChild(objectHandle, index)) == -1) break;
        ret.push_back(childHandle);
    }
    return ret;
}

void setObjectParent(handle_t objectHandle, handle_t parentObjectHandle, bool keepInPlace)
{
    if(simSetObjectParent(objectHandle, parentObjectHandle, keepInPlace) == -1)
        throw api_error("simSetObjectParent");
}

int getObjectType(handle_t objectHandle)
{
    int ret;
    if((ret = simGetObjectType(objectHandle)) == -1)
        throw api_error("simGetObjectType");
    return ret;
}

int getJointType(handle_t objectHandle)
{
    int type = simGetJointType(objectHandle);
    if(type == -1)
        throw api_error("simGetJointType");
    return type;
}

// int simReservedCommand(int v, int w);

int getSimulationState()
{
    int ret = simGetSimulationState();
    if(ret == -1)
        throw api_error("simGetSimulationState");
    return ret;
}

void loadScene(const char *filename)
{
    if(simLoadScene(filename) == -1)
        throw api_error("simLoadScene");
}

void loadScene(const std::string &filename)
{
    return loadScene(filename.c_str());
}

void closeScene()
{
    if(simCloseScene() == -1)
        throw api_error("simCloseScene");
}

void saveScene(const char *filename)
{
    if(simSaveScene(filename) == -1)
        throw api_error("simSaveScene");
}

void saveScene(const std::string &filename)
{
    return saveScene(filename.c_str());
}

handle_t loadModel(const char *filename)
{
    handle_t ret = simLoadModel(filename);
    if(ret == -1)
        throw api_error("simLoadModel");
    return ret;
}

handle_t loadModel(const std::string &filename)
{
    return loadModel(filename.c_str());
}

void saveModel(handle_t baseOfModelHandle, const char *filename)
{
    if(simSaveModel(baseOfModelHandle, filename) == -1)
        throw api_error("simSaveModel");
}

void saveModel(handle_t baseOfModelHandle, const std::string &filename)
{
    return saveModel(baseOfModelHandle, filename.c_str());
}

bool doesFileExist(const char *filename)
{
    int ret = simDoesFileExist(filename);
    if(ret == -1)
        throw api_error("simDoesFileExist");
    return ret > 0;
}

bool doesFileExist(const std::string &filename)
{
    return doesFileExist(filename.c_str());
}

std::vector<handle_t> getObjectSel()
{
    handle_t *buf;
    int count;
    if((buf = simGetObjectSel(&count)) == NULL)
        throw api_error("simGetObjectSel");
    std::vector<handle_t> handles;
    handles.resize(count);
    for(size_t i = 0; i < count; i++)
        handles[i] = buf[i];
    releaseBuffer(buf);
    return handles;
}

int setObjectSel(const handle_t *handles, int cnt)
{
    int ret = simSetObjectSel(handles, cnt);
    if(ret == -1)
        throw api_error("simSetObjectSel");
    return ret;
}

int setObjectSel(const std::vector<handle_t> &handles)
{
    return setObjectSel(handles.data(), handles.size());
}

// int simAssociateScriptWithObject(handle_t scriptHandle, handle_t associatedObjectHandle);

// int simHandleMainScript();

// int simResetScript(handle_t scriptHandle);

// int simAddScript(int scriptProperty);

// int simRemoveScript(handle_t scriptHandle);

// int simRefreshDialogs(int refreshDegree);

// int simResetProximitySensor(handle_t sensorHandle);

void * createBuffer(int size)
{
    void *ret = simCreateBuffer(size);
    if(ret == NULL)
        throw api_error("simCreateBuffer");
    return ret;
}

void releaseBuffer(const void *buffer)
{
    if(simReleaseBuffer(buffer) == -1)
        throw api_error("simReleaseBuffer");
}

bool checkCollision(handle_t entity1Handle, handle_t entity2Handle)
{
    int ret = simCheckCollision(entity1Handle, entity2Handle);
    if(ret == -1)
        throw api_error("simCheckCollision");
    return ret > 0;
}

// int simGetRealTimeSimulation();

// int simIsRealTimeSimulationStepNeeded();

// int simGetSimulationPassesPerRenderingPass();

// int simAdvanceSimulationByOneStep();

// int simStartSimulation();

// int simStopSimulation();

// int simPauseSimulation();

// char *simGetModuleName(int index, unsigned char *moduleVersion);

// int simAdjustView(int viewHandleOrIndex, handle_t associatedViewableObjectHandle, int options, const char *viewLabel);

void setLastError(const std::string &msg)
{
    if(simSetLastError(nullptr, msg.c_str()) == -1)
        throw api_error("simSetLastError");
}

// int simResetGraph(handle_t graphHandle);

// int simDestroyGraphCurve(handle_t graphHandle, int curveId);

// int simDuplicateGraphCurveToStatic(handle_t graphHandle, int curveId, const char *curveName);

// int simSetNavigationMode(int navigationMode);

// int simGetNavigationMode();

// int simSetPage(int index);

// int simGetPage();

int registerScriptCallbackFunction(const std::string &funcNameAtPluginName, const std::string &callTips, void (*callBack)(struct SScriptCallBack *cb))
{
    int ret = simRegisterScriptCallbackFunction(funcNameAtPluginName.c_str(), callTips.c_str(), callBack);
    if(ret == 0)
    {
        addLog(sim_verbosity_warnings, "replaced function '%s'", funcNameAtPluginName);
    }
    if(ret == -1)
        throw api_error("simRegisterScriptCallbackFunction");
    return ret;
}

int registerScriptCallbackFunction(const std::string &funcNameAtPluginName, void (*callBack)(struct SScriptCallBack *cb))
{
    int ret = simRegisterScriptCallbackFunction(funcNameAtPluginName.c_str(), nullptr, callBack);
    if(ret == 0)
    {
        addLog(sim_verbosity_warnings, "replaced function '%s'", funcNameAtPluginName);
    }
    if(ret == -1)
        throw api_error("simRegisterScriptCallbackFunction");
    return ret;
}

int registerScriptVariableRaw(const std::string &varName, const char *varValue, int stackID)
{
    int ret = simRegisterScriptVariable(varName.c_str(), varValue, stackID);
    if(ret == 0)
    {
        addLog(sim_verbosity_warnings, "replaced variable '%s'", varName);
    }
    if(ret == -1)
        throw api_error("simRegisterScriptVariable");
    return ret;
}

int registerScriptVariableRaw(const std::string &varName, const std::string &varValue, int stackID)
{
    return registerScriptVariableRaw(varName, varValue.c_str(), stackID);
}

int registerScriptVariable(const std::string &varName, const char *varValue, int stackID)
{
    return registerScriptVariable(varName, std::string(varValue), stackID);
}

int registerScriptVariable(const std::string &varName, const std::string &varValue, int stackID)
{
    std::string s = varValue;
    std::string::size_type pos = 0;
    while((pos = s.find('\"', pos)) != std::string::npos)
    {
        s.replace(pos, 1, "\\\"");
        pos += 2;
    }
    s = "\"" + s + "\"";
    return registerScriptVariableRaw(varName, s, stackID);
}

// int simRegisterScriptFuncHook(handle_t scriptHandle, const char *funcToHook, const char *userFunction, bool executeBefore, int options);

void copyPasteObjects(std::vector<handle_t> &shapeHandles, int options)
{
    if(simCopyPasteObjects(shapeHandles.data(), shapeHandles.size(), options) == -1)
        throw api_error("simCopyPasteObjects");
}

std::vector<handle_t> copyPasteObjects(const std::vector<handle_t> &shapeHandles, int options)
{
    std::vector<handle_t> ret(shapeHandles);
    copyPasteObjects(ret, options);
    return ret;
}

// int simRemoveDrawingObject(handle_t objectHandle);

int announceSceneContentChange()
{
    int ret = simAnnounceSceneContentChange();
    if(ret == -1)
        throw api_error("simAnnounceSceneContentChange");
    return ret;
}

// int simSetInt32Signal(const char *signalName, int signalValue);

// int simGetInt32Signal(const char *signalName, int *signalValue);

// int simClearInt32Signal(const char *signalName);

// int simClearFloatSignal(const char *signalName);

// int simSetStringSignal(const char *signalName, const char *signalValue, int stringLength);

// char *simGetStringSignal(const char *signalName, int *stringLength);

// int simClearStringSignal(const char *signalName);

// char *simGetSignalName(int signalIndex, int signalType);

void setObjectProperty(handle_t objectHandle, int prop)
{
    if(simSetObjectProperty(objectHandle, prop) == -1)
        throw api_error("simSetObjectProperty");
}

int getObjectProperty(handle_t objectHandle)
{
    int ret = simGetObjectProperty(objectHandle);
    if(ret == -1)
        throw api_error("simGetObjectProperty");
    return ret;
}

// int simSetObjectSpecialProperty(handle_t objectHandle, int prop);

// int simGetObjectSpecialProperty(handle_t objectHandle);

// int simSetExplicitHandling(handle_t objectHandle, int explicitFlags);

// int simGetExplicitHandling(handle_t objectHandle);

handle_t getLinkDummy(handle_t dummyHandle)
{
    return simGetLinkDummy(dummyHandle);
}

void setLinkDummy(handle_t dummyHandle, handle_t linkedDummyHandle)
{
    if(simSetLinkDummy(dummyHandle, linkedDummyHandle) == -1)
        throw api_error("simSetLinkDummy");
}

void setModelProperty(handle_t objectHandle, int modelProperty)
{
    if(simSetModelProperty(objectHandle, modelProperty) == -1)
        throw api_error("simSetModelProperty");
}

int getModelProperty(handle_t objectHandle)
{
    int ret = simGetModelProperty(objectHandle);
    if(ret == -1)
        throw api_error("simGetModelProperty");
    return ret;
}

void resetDynamicObject(handle_t objectHandle)
{
    if(simResetDynamicObject(objectHandle) == -1)
        throw api_error("simResetDynamicObject");
}

void setJointMode(handle_t jointHandle, int jointMode)
{
    if(simSetJointMode(jointHandle, jointMode, 0) == -1)
        throw api_error("simSetJointMode");
}

int getJointMode(handle_t jointHandle)
{
    int ret = simGetJointMode(jointHandle, nullptr);
    if(ret == -1)
        throw api_error("simGetJointMode");
    return ret;
}

// int simSerialOpen(const char *portString, int baudRate, void *reserved1, void *reserved2);

// int simSerialClose(handle_t portHandle);

// int simSerialSend(handle_t portHandle, const char *data, int dataLength);

// int simSerialRead(handle_t portHandle, char *buffer, int dataLengthToRead);

// int simSerialCheck(handle_t portHandle);

// int simAuxiliaryConsoleClose(handle_t consoleHandle);

// int simAuxiliaryConsoleShow(handle_t consoleHandle, bool showState);

// int simAuxiliaryConsolePrint(handle_t consoleHandle, const char *text);

int getObjectInt32Param(handle_t objectHandle, int parameterID)
{
    int ret;
    if(simGetObjectInt32Param(objectHandle, parameterID, &ret) == -1)
        throw api_error("simGetObjectInt32Param");
    return ret;
}

void setObjectInt32Param(handle_t objectHandle, int parameterID, int parameter)
{
    if(simSetObjectInt32Param(objectHandle, parameterID, parameter) == -1)
        throw api_error("simSetObjectInt32Param");
}

std::string getObjectStringParam(handle_t objectHandle, int parameterID)
{
    char *ret;
    int len;
    if((ret = simGetObjectStringParam(objectHandle, parameterID, &len)) == NULL)
        throw api_error("simGetObjectStringParam");
    std::string s(ret, len);
    releaseBuffer(ret);
    return s;
}

void setObjectStringParam(handle_t objectHandle, int parameterID, const std::string &parameter)
{
    // XXX: fix const ptrs in the regular API
    if(simSetObjectStringParam(objectHandle, parameterID, const_cast<char*>(parameter.data()), parameter.size()) == -1)
        throw api_error("simSetObjectStringParam");
}

// int simSetSimulationPassesPerRenderingPass(int p);

void persistentDataWrite(const std::string &dataName, const std::string &dataValue, int options)
{
    if(simPersistentDataWrite(dataName.c_str(), dataValue.c_str(), dataValue.length(), options) == -1)
        throw api_error("simPersistentDataWrite");
}

std::string persistentDataRead(const std::string &dataName)
{
    int length = 0;
    char *buf = simPersistentDataRead(dataName.c_str(), &length);
    if(!buf)
        throw api_error("simPersistentDataRead");
    std::string ret(buf, length);
    releaseBuffer(buf);
    return ret;
}

bool isHandle(handle_t generalObjectHandle, int generalObjectType)
{
    int ret = simIsHandle(generalObjectHandle, generalObjectType);
    if(ret == -1)
        throw api_error("simIsHandle");
    return ret > 0;
}

// int simResetVisionSensor(handle_t visionSensorHandle);

void setVisionSensorImg(handle_t sensorHandle, const unsigned char *img, int options, std::array<int, 2> pos, std::array<int, 2> size)
{
    if(simSetVisionSensorImg(sensorHandle, img, options, pos.data(), size.data()) == -1)
        throw api_error("simSetVisionSensorImg");
}

// int simRuckigRemove(handle_t objHandle);

handle_t groupShapes(const std::vector<handle_t> &shapeHandles, bool merge)
{
    handle_t groupedHandle = simGroupShapes(shapeHandles.data(), shapeHandles.size() * (merge ? -1 : 1));
    if(groupedHandle == -1)
        throw api_error("simGroupShapes");
    return groupedHandle;
}

std::vector<handle_t> ungroupShape(handle_t shapeHandle)
{
    int shapeCount = 0;
    handle_t *shapeHandles = simUngroupShape(shapeHandle, &shapeCount);
    if(shapeHandles == nullptr)
        throw api_error("simUngroupShape");
    std::vector<handle_t> ret(shapeCount, -1);
    for(size_t i = 0; i < shapeCount; i++)
        ret[i] = shapeHandles[i];
    releaseBuffer(shapeHandles);
    return ret;
}

void quitSimulator()
{
    simQuitSimulator(true);
}

void setShapeMaterial(handle_t shapeHandle, handle_t materialIdOrShapeHandle)
{
    if(simSetShapeMaterial(shapeHandle, materialIdOrShapeHandle) == -1)
        throw api_error("simSetShapeMaterial");
}

// int simGetTextureId(const char *textureName, int *resolution);

// unsigned char *simReadTexture(int textureId, int options, int posX, int posY, int sizeX, int sizeY);

void writeCustomDataBlock(handle_t objectHandle, const char *tagName, const char *data, int dataSize)
{
    if(simWriteCustomDataBlock(objectHandle, tagName, data, dataSize) == -1)
        throw api_error("simWriteCustomDataBlock");
}

void writeCustomDataBlock(handle_t objectHandle, const std::string &tagName, const std::string &data)
{
    return writeCustomDataBlock(objectHandle, tagName.c_str(), data.c_str(), data.length());
}

char * readCustomDataBlock(handle_t objectHandle, const char *tagName, int *dataSize)
{
    return simReadCustomDataBlock(objectHandle, tagName, dataSize);
}

std::optional<std::string> readCustomDataBlock(handle_t objectHandle, const std::string &tagName)
{
    int size = 0;
    char *buf = readCustomDataBlock(objectHandle, tagName.c_str(), &size);
    if(!buf) return {};
    std::string s(buf, size);
    releaseBuffer(buf);
    return s;
}

char * readCustomDataBlockTags(handle_t objectHandle, int *tagCount)
{
    return simReadCustomDataBlockTags(objectHandle, tagCount);
}

std::vector<std::string> readCustomDataBlockTags(handle_t objectHandle)
{
    std::vector<std::string> ret;
    int count = 0;
    char *buf = readCustomDataBlockTags(objectHandle, &count);
    if(buf)
    {
        int len = 0;
        char *tmp = buf;
        for(int i = 0; i < count; i++)
        {
            while(*tmp) {tmp++; len++;}
        }
        std::string s(buf, len);
        boost::split(ret, s, boost::is_any_of("\0"));
        releaseBuffer(buf);
    }
    return ret;
}

handle_t getObjects(int index, int objectType)
{
    int ret;
    if((ret = simGetObjects(index, objectType)) == -1)
        throw api_error("simGetObjects");
    return ret;
}

std::vector<handle_t> getObjects(int objectType)
{
    std::vector<handle_t> ret;
    int i = 0;
    handle_t handle = -1;
    while(1)
    {
        handle = simGetObjects(i++, objectType);
        if(handle == -1) break;
        ret.push_back(handle);
    }
    return ret;
}

std::vector<handle_t> getObjectsInTree(handle_t treeBaseHandle, int objectType, int options)
{
    handle_t *ret;
    int count;
    if((ret = simGetObjectsInTree(treeBaseHandle, objectType, options, &count)) == NULL)
        throw api_error("simGetObjectsInTree");
    std::vector<handle_t> v;
    for(size_t i = 0; i < count; i++) v.push_back(ret[i]);
    return v;
}

// int simGetShapeTextureId(handle_t shapeHandle);

// int simCreateCollectionEx(int options);

// int simAddItemToCollection(handle_t collectionHandle, int what, handle_t objectHandle, int options);

// int simDestroyCollection(handle_t collectionHandle);

// int *simGetCollectionObjects(handle_t collectionHandle, int *objectCount);

int getScriptInt32Param(handle_t scriptHandle, int parameterID)
{
    int param;
    if(simGetScriptInt32Param(scriptHandle, parameterID, &param) == -1)
        throw api_error("simGetScriptInt32Param");
    return param;
}

int setScriptInt32Param(handle_t scriptHandle, int parameterID, int parameter)
{
    int ret = simSetScriptInt32Param(scriptHandle, parameterID, parameter);
    if(ret == -1)
        throw api_error("simSetScriptInt32Param");
    return ret;
}

std::string getScriptStringParam(handle_t scriptHandle, int parameterID)
{
    int parameterLength = 0;
    char *buf = simGetScriptStringParam(scriptHandle, parameterID, &parameterLength);
    if(!buf)
        throw api_error("simGetScriptStringParam");
    std::string s(buf, parameterLength);
    releaseBuffer(buf);
    return s;
}

std::optional<std::string> getScriptStringParamOpt(handle_t scriptHandle, int parameterID)
{
    int parameterLength = 0;
    char *buf = simGetScriptStringParam(scriptHandle, parameterID, &parameterLength);
    if(!buf) return {};
    std::string s(buf, parameterLength);
    releaseBuffer(buf);
    return s;
}

int setScriptStringParam(handle_t scriptHandle, int parameterID, const std::string &parameter)
{
    int ret = simSetScriptStringParam(scriptHandle, parameterID, parameter.c_str(), parameter.length());
    if(ret == -1)
        throw api_error("simSetScriptStringParam");
    return ret;
}

// int simReorientShapeBoundingBox(handle_t shapeHandle, handle_t relativeToHandle, int reservedSetToZero);

// int simSaveImage(const unsigned char *image, const int *resolution, int options, const char *filename, int quality, void *reserved);

unsigned char * loadImage(int *resolution, int options, const char *filename, void *reserved)
{
    unsigned char *buf = simLoadImage(resolution, options, filename, reserved);
    if(!buf)
        throw api_error("simLoadImage");
    return buf;
}

unsigned char * loadImage(int *resolution, int options, const std::string &filename, void *reserved)
{
    return loadImage(resolution, options, filename.c_str(), reserved);
}

unsigned char * getScaledImage(const unsigned char *imageIn, const int *resolutionIn, int *resolutionOut, int options)
{
    unsigned char *buf = simGetScaledImage(imageIn, resolutionIn, resolutionOut, options, nullptr);
    if(!buf)
        throw api_error("simGetScaledImage");
    return buf;
}

unsigned char * getScaledImage(const unsigned char *imageIn, std::array<int, 2> resolutionIn, int *resolutionOut, int options)
{
    return getScaledImage(imageIn, resolutionIn.data(), resolutionOut, options);
}

void callScriptFunctionEx(handle_t scriptHandle, const std::string &functionName, int stackId)
{
    if(simCallScriptFunctionEx(scriptHandle, functionName.c_str(), stackId) == -1)
        throw api_error("simCallScriptFunctionEx");
}

// char *simGetExtensionString(handle_t objectHandle, int index, const char *key);

handle_t createStack()
{
    addStackDebugLog("simCreateStack");

    handle_t ret = simCreateStack();
    if(ret == -1)
        throw api_error("simCreateStack");

    addStackDebugDump(ret);

    return ret;
}

void releaseStack(handle_t stackHandle)
{
    addStackDebugLog("simReleaseStack");

    if(simReleaseStack(stackHandle) != 1)
        throw api_error("simReleaseStack");
}

handle_t copyStack(handle_t stackHandle)
{
    addStackDebugLog("simCopyStack");

    handle_t ret = simCopyStack(stackHandle);
    if(ret == -1)
        throw api_error("simCopyStack");
    return ret;
}

void pushNullOntoStack(handle_t stackHandle)
{
    addStackDebugLog("simPushNullOntoStack");

    if(simPushNullOntoStack(stackHandle) == -1)
        throw api_error("simPushNullOntoStack");

    addStackDebugDump(stackHandle);
}

void pushBoolOntoStack(handle_t stackHandle, bool value)
{
    addStackDebugLog("simPushBoolOntoStack %d", value);

    if(simPushBoolOntoStack(stackHandle, value) == -1)
        throw api_error("simPushBoolOntoStack");

    addStackDebugDump(stackHandle);
}

void pushInt32OntoStack(handle_t stackHandle, int value)
{
    addStackDebugLog("simPushInt32OntoStack %d", value);

    if(simPushInt32OntoStack(stackHandle, value) == -1)
        throw api_error("simPushInt32OntoStack");

    addStackDebugDump(stackHandle);
}

void pushInt64OntoStack(handle_t stackHandle, long long int value)
{
    addStackDebugLog("simPushInt64OntoStack %ld", value);

    if(simPushInt64OntoStack(stackHandle, value) == -1)
        throw api_error("simPushInt64OntoStack");

    addStackDebugDump(stackHandle);
}

void pushStringOntoStack(handle_t stackHandle, const char *value, int stringSize)
{
    addStackDebugLog("simPushStringOntoStack \"%s\" [%d]", value, stringSize);

    if(simPushStringOntoStack(stackHandle, value, stringSize) == -1)
        throw api_error("simPushStringOntoStack");

    addStackDebugDump(stackHandle);
}

void pushStringOntoStack(handle_t stackHandle, const std::string &value)
{
    addStackDebugLog("simPushStringOntoStack \"%s\" [%d]", value.c_str(), value.size());

    if(simPushStringOntoStack(stackHandle, value.c_str(), value.size()) == -1)
        throw api_error("simPushStringOntoStack");

    addStackDebugDump(stackHandle);
}

void pushTextOntoStack(handle_t stackHandle, const char *value)
{
    addStackDebugLog("simPushTextOntoStack \"%s\"", value);

    if(simPushTextOntoStack(stackHandle, value) == -1)
        throw api_error("simPushTextOntoStack");

    addStackDebugDump(stackHandle);
}

void pushTextOntoStack(handle_t stackHandle, const std::string &value)
{
    pushTextOntoStack(stackHandle, value.c_str());
}

void pushBufferOntoStack(handle_t stackHandle, const char *value, int bufferSize)
{
    addStackDebugLog("simPushBufferOntoStack [%d bytes]", bufferSize);

    if(simPushBufferOntoStack(stackHandle, value, bufferSize) == -1)
        throw api_error("simPushBufferOntoStack");

    addStackDebugDump(stackHandle);
}

void pushBufferOntoStack(handle_t stackHandle, const uint8_t *value, int bufferSize)
{
    pushBufferOntoStack(stackHandle, reinterpret_cast<const char*>(value), bufferSize);
}

void pushBufferOntoStack(handle_t stackHandle, const std::string &value)
{
    pushBufferOntoStack(stackHandle, value.data(), value.size());
}

void pushBufferOntoStack(handle_t stackHandle, const std::vector<uint8_t> &value)
{
    pushBufferOntoStack(stackHandle, value.data(), value.size());
}

void pushUInt8TableOntoStack(handle_t stackHandle, const unsigned char *values, int valueCnt)
{
    addStackDebugLog("simPushUInt8TableOntoStack <%d values>", valueCnt);

    if(simPushUInt8TableOntoStack(stackHandle, values, valueCnt) == -1)
        throw api_error("simPushUInt8TableOntoStack");

    addStackDebugDump(stackHandle);
}

void pushUInt8TableOntoStack(handle_t stackHandle, const std::vector<unsigned char> &values)
{
    pushUInt8TableOntoStack(stackHandle, values.data(), values.size());
}

void pushInt32TableOntoStack(handle_t stackHandle, const int *values, int valueCnt)
{
    addStackDebugLog("simPushInt32TableOntoStack <%d values>", valueCnt);

    if(simPushInt32TableOntoStack(stackHandle, values, valueCnt) == -1)
        throw api_error("simPushInt32TableOntoStack");

    addStackDebugDump(stackHandle);
}

void pushInt32TableOntoStack(handle_t stackHandle, const std::vector<int> &values)
{
    pushInt32TableOntoStack(stackHandle, values.data(), values.size());
}

void pushInt64TableOntoStack(handle_t stackHandle, const long long int *values, int valueCnt)
{
    addStackDebugLog("simPushInt64TableOntoStack <%d values>", valueCnt);

    if(simPushInt64TableOntoStack(stackHandle, values, valueCnt) == -1)
        throw api_error("simPushInt64TableOntoStack");

    addStackDebugDump(stackHandle);
}

void pushInt64TableOntoStack(handle_t stackHandle, const std::vector<long long int> &values)
{
    pushInt64TableOntoStack(stackHandle, values.data(), values.size());
}

void pushTableOntoStack(handle_t stackHandle)
{
    addStackDebugLog("simPushTableOntoStack");

    if(simPushTableOntoStack(stackHandle) == -1)
        throw api_error("simPushTableOntoStack");

    addStackDebugDump(stackHandle);
}

void insertDataIntoStackTable(handle_t stackHandle)
{
    addStackDebugLog("simInsertDataIntoStackTable");

    if(simInsertDataIntoStackTable(stackHandle) == -1)
        throw api_error("simInsertDataIntoStackTable");

    addStackDebugDump(stackHandle);
}

int getStackSize(handle_t stackHandle)
{
    int ret = simGetStackSize(stackHandle);

    addStackDebugLog("simGetStackSize -> %d", ret);

    if(ret == -1)
        throw api_error("simGetStackSize");
    return ret;
}

int popStackItem(handle_t stackHandle, int count)
{
    int ret = simPopStackItem(stackHandle, count);

    addStackDebugLog("simPopStackItem %d -> %d", count, ret);

    if(ret == -1)
        throw api_error("simPopStackItem");

    addStackDebugDump(stackHandle);

    return ret;
}

void moveStackItemToTop(handle_t stackHandle, int cIndex)
{
    addStackDebugLog("simMoveStackItemToTop %d", cIndex);

    if(simMoveStackItemToTop(stackHandle, cIndex) == -1)
        throw api_error("simMoveStackItemToTop");

    addStackDebugDump(stackHandle);
}

int getStackItemType(handle_t stackHandle, int cIndex)
{
    int ret = simGetStackItemType(stackHandle, cIndex);
    if(ret == -1)
        throw api_error("simGetStackItemType");

    addStackDebugLog("simGetStackItemType -> %d", ret);

    return ret;}

int getStackBoolValue(handle_t stackHandle, bool *boolValue)
{
    int ret = simGetStackBoolValue(stackHandle, boolValue);
    if(ret == -1)
        throw api_error("simGetStackBoolValue");

#ifndef NDEBUG
    if(debugStackEnabled)
    {
        if(ret)
            addStackDebugLog("simGetStackBoolValue -> %s", *boolValue ? "true" : "false");
        else
            addStackDebugLog("simGetStackBoolValue -> not a bool");
    }
#endif

    return ret;
}

int getStackInt32Value(handle_t stackHandle, int *numberValue)
{
    int ret = simGetStackInt32Value(stackHandle, numberValue);
    if(ret == -1)
        throw api_error("simGetStackInt32Value");

#ifndef NDEBUG
    if(debugStackEnabled)
    {
        if(ret)
            addStackDebugLog("simGetStackInt32Value -> %d", *numberValue);
        else
            addStackDebugLog("simGetStackInt32Value -> not an int");
    }
#endif

    return ret;
}

int getStackInt64Value(handle_t stackHandle, long long int *numberValue)
{
    int ret = simGetStackInt64Value(stackHandle, numberValue);
    if(ret == -1)
        throw api_error("simGetStackInt64Value");

#ifndef NDEBUG
    if(debugStackEnabled)
    {
        if(ret)
            addStackDebugLog("simGetStackInt64Value -> %d", *numberValue);
        else
            addStackDebugLog("simGetStackInt64Value -> not an int");
    }
#endif

    return ret;
}

char * getStackStringValue(handle_t stackHandle, int *stringSize)
{
    char *ret = simGetStackStringValue(stackHandle, stringSize);

#ifndef NDEBUG
    if(debugStackEnabled)
    {
        if(ret)
            addStackDebugLog("simGetStackStringValue -> \"%s\"", ret);
        else
            addStackDebugLog("simGetStackStringValue -> not a string");
    }
#endif

    // if stringSize is NULL, we cannot distinguish error (-1) from type error (0)
    if(ret == NULL && stringSize && *stringSize == -1)
        throw api_error("simGetStackStringValue");

    // ret might be NULL, indicating type error:
    return ret;
}

int getStackStringValue(handle_t stackHandle, std::string *stringValue)
{
    int stringSize = -1;
    char *ret = getStackStringValue(stackHandle, &stringSize);
    if(ret)
    {
        *stringValue = std::string(ret, stringSize);
        releaseBuffer(ret);
        return 1;
    }
    else
    {
        return 0;
    }
}

int getStackStringType(handle_t stackHandle, int cIndex)
{
    int ret = simGetStackStringType(stackHandle, cIndex);

    if(ret == -1)
        throw api_error("simGetStackStringType");

    return ret;
}

int getStackTableInfo(handle_t stackHandle, int infoType)
{
    int ret = simGetStackTableInfo(stackHandle, infoType);

#ifndef NDEBUG
    if(debugStackEnabled)
    {
        std::string infoTypeStr = "???", retStr = "???";
        switch(infoType)
        {
        case 0: infoTypeStr = "check table type"; break;
        case 1: infoTypeStr = "check array of nil"; break;
        case 2: infoTypeStr = "check array of number"; break;
        case 3: infoTypeStr = "check array of boolean"; break;
        case 4: infoTypeStr = "check array of string"; break;
        case 5: infoTypeStr = "check array of table"; break;
        }
        if(infoType == 0)
        {
            switch(ret)
            {
            case -4: retStr = "sim_stack_table_circular_ref"; break;
            case -3: retStr = "sim_stack_table_not_table"; break;
            case -2: retStr = "sim_stack_table_map"; break;
            case  0: retStr = "sim_stack_table_empty"; break;
            default:
                if(ret > 0)
                    retStr = util::sprintf("array of %d elements", ret);
                break;
            }
        }
        else retStr = ret ? "yes" : "no";
        addStackDebugLog("simGetStackTableInfo %d (%s) -> %d (%s)", infoType, infoTypeStr, ret, retStr);
    }
#endif // NDEBUG

    if(ret == -1)
        throw api_error("simGetStackTableInfo");
    return ret;
}

int getStackUInt8Table(handle_t stackHandle, unsigned char *array, int count)
{
    int ret = simGetStackUInt8Table(stackHandle, array, count);

    addStackDebugLog("simGetStackUInt8Table count = %d -> %d", count, ret);

    if(ret == -1)
        throw api_error("simGetStackUInt8Table");
    return ret;
}

int getStackUInt8Table(handle_t stackHandle, std::vector<unsigned char> *v)
{
    int count = getStackTableInfo(stackHandle, 0);
    v->resize(count);
    return getStackUInt8Table(stackHandle, v->data(), count);
}


int getStackInt32Table(handle_t stackHandle, int *array, int count)
{
    int ret = simGetStackInt32Table(stackHandle, array, count);

    addStackDebugLog("simGetStackInt32Table count = %d -> %d", count, ret);

    if(ret == -1)
        throw api_error("simGetStackInt32Table");
    return ret;
}

int getStackInt32Table(handle_t stackHandle, std::vector<int> *v)
{
    int count = getStackTableInfo(stackHandle, 0);
    v->resize(count);
    return getStackInt32Table(stackHandle, v->data(), count);
}

int getStackInt64Table(handle_t stackHandle, long long int *array, int count)
{
    int ret = simGetStackInt64Table(stackHandle, array, count);

    addStackDebugLog("simGetStackInt64Table count = %d -> %d", count, ret);

    if(ret == -1)
        throw api_error("simGetStackInt64Table");
    return ret;
}

int getStackInt64Table(handle_t stackHandle, std::vector<long long int> *v)
{
    int count = getStackTableInfo(stackHandle, 0);
    v->resize(count);
    return getStackInt64Table(stackHandle, v->data(), count);
}

void unfoldStackTable(handle_t stackHandle)
{
    addStackDebugLog("simUnfoldStackTable");

    if(simUnfoldStackTable(stackHandle) == -1)
        throw api_error("simUnfoldStackTable");

#ifndef NDEBUG
    if(debugStackEnabled)
    {
        simDebugStack(stackHandle, -1);
    }
#endif // NDEBUG
}

void debugStack(handle_t stackHandle, int index)
{
    if(simDebugStack(stackHandle, index) == -1)
        throw api_error("simDebugStack");
}

int getEngineInt32Param(int paramId, handle_t objectHandle, const void *object)
{
    bool ok = false;
    int ret = simGetEngineInt32Param(paramId, objectHandle, object, &ok);
    if(!ok)
        throw api_error("simGetEngineInt32Param");
    return ret;
}

bool getEngineBoolParam(int paramId, handle_t objectHandle, const void *object)
{
    bool ok = false;
    bool ret = simGetEngineBoolParam(paramId, objectHandle, object, &ok);
    if(!ok)
        throw api_error("simGetEngineBoolParam");
    return ret;
}

void setEngineInt32Param(int paramId, handle_t objectHandle, const void *object, int val)
{
    if(simSetEngineInt32Param(paramId, objectHandle, object, val) != 1)
        throw api_error("simSetEngineInt32Param");
}

void setEngineBoolParam(int paramId, handle_t objectHandle, const void *object, bool val)
{
    if(simSetEngineBoolParam(paramId, objectHandle, object, val) != 1)
        throw api_error("simSetEngineBoolParam");
}

// int simInsertObjectIntoOctree(handle_t octreeHandle, handle_t objectHandle, int options, const unsigned char *color, unsigned int tag, void *reserved);

// int simSubtractObjectFromOctree(handle_t octreeHandle, handle_t objectHandle, int options, void *reserved);

// char *simOpenTextEditor(const char *initText, const char *xml, int *various);

// char *simPackTable(handle_t stackHandle, int *bufferSize);

// int simUnpackTable(handle_t stackHandle, const char *buffer, int bufferSize);

// int simSetReferencedHandles(handle_t objectHandle, int count, const int *referencedHandles, const int *reserved1, const int *reserved2);

// int simGetReferencedHandles(handle_t objectHandle, int **referencedHandles, int **reserved1, int **reserved2);

void executeScriptString(handle_t scriptHandle, const std::string &code, int stackID)
{
    if(simExecuteScriptString(scriptHandle, code.c_str(), stackID) == -1)
        throw api_error("simExecuteScriptString");
}

std::vector<std::string> getApiFunc(handle_t scriptHandle, const std::string &apiWord)
{
    std::vector<std::string> ret;
    char *buf = simGetApiFunc(scriptHandle, apiWord.c_str());
    if(buf)
    {
        boost::split(ret, buf, boost::is_any_of(" "));
        releaseBuffer(buf);
    }
    return ret;
}

std::string getApiInfo(handle_t scriptHandle, const std::string &apiWord)
{
    char *buf = simGetApiInfo(scriptHandle, apiWord.c_str());
    if(buf)
    {
        std::string s(buf);
        releaseBuffer(buf);
        return s;
    }
    return "";
}

void setPluginInfo(const std::string &moduleName, int infoType, const std::string &stringInfo)
{
    if(simSetPluginInfo(moduleName.c_str(), infoType, stringInfo.c_str(), 0) == -1)
        throw api_error("simSetPluginInfo");
}

void setPluginInfo(const std::string &moduleName, int infoType, int intInfo)
{
    if(simSetPluginInfo(moduleName.c_str(), infoType, nullptr, intInfo) == -1)
        throw api_error("simSetPluginInfo");
}

void setPluginInfo(int infoType, const std::string &stringInfo)
{
    setPluginInfo(pluginInfo->name, infoType, stringInfo);
}

void setPluginInfo(int infoType, int intInfo)
{
    setPluginInfo(pluginInfo->name, infoType, intInfo);
}

void getPluginInfo(const std::string &moduleName, int infoType, std::string &stringInfo)
{
    int intInfo = 0;
    char *s = nullptr;
    if(simGetPluginInfo(moduleName.c_str(), infoType, &s, &intInfo) == -1)
        throw api_error("simGetPluginInfo");
    if(s)
    {
        stringInfo = std::string(s);
        releaseBuffer(s);
    }
}

void getPluginInfo(const std::string &moduleName, int infoType, int &intInfo)
{
    char *s = nullptr;
    if(simGetPluginInfo(moduleName.c_str(), infoType, &s, &intInfo) == -1)
        throw api_error("simGetPluginInfo");
    if(s)
        releaseBuffer(s);
}

std::string getPluginInfoStr(const std::string &moduleName, int infoType)
{
    std::string s;
    getPluginInfo(moduleName, infoType, s);
    return s;
}

int getPluginInfoInt(const std::string &moduleName, int infoType)
{
    int i;
    getPluginInfo(moduleName, infoType, i);
    return i;
}

void getPluginInfo(int infoType, std::string &stringInfo)
{
    getPluginInfo(pluginInfo->name, infoType, stringInfo);
}

void getPluginInfo(int infoType, int &intInfo)
{
    getPluginInfo(pluginInfo->name, infoType, intInfo);
}

std::string getPluginInfoStr(int infoType)
{
    std::string s;
    getPluginInfo(infoType, s);
    return s;
}

int getPluginInfoInt(int infoType)
{
    int i;
    getPluginInfo(infoType, i);
    return i;
}

std::vector<std::string> getPersistentDataTags()
{
    std::vector<std::string> ret;
    int count = 0;
    char *buf = simGetPersistentDataTags(&count);
    if(buf)
    {
        boost::split(ret, buf, boost::is_any_of("\0"));
        releaseBuffer(buf);
    }
    return ret;
}

int eventNotification(const std::string &event)
{
    return simEventNotification(event.c_str());
}

void addLog(std::optional<std::string> pluginName, int verbosityLevel, std::optional<std::string> logMsg)
{
    if(simAddLog(pluginName ? pluginName->c_str() : nullptr, verbosityLevel, logMsg ? logMsg->c_str() : nullptr) == -1)
        throw api_error("simAddLog");
}

bool isDynamicallyEnabled(handle_t objectHandle)
{
    int ret = simIsDynamicallyEnabled(objectHandle);
    if(ret == -1)
        throw api_error("simIsDynamicallyEnabled");
    return ret > 0;
}

bool initScript(handle_t scriptHandle)
{
    int ret = simInitScript(scriptHandle);
    if(ret == -1)
        throw api_error("simInitScript");
    return ret > 0;
}

int moduleEntry(handle_t handle, const char *label, int state)
{
    handle_t retHandle = simModuleEntry(handle, label, state);
    if(retHandle == -1)
        throw api_error("simModuleEntry");
    return retHandle;
}

int moduleEntry(handle_t handle, const std::string &label, int state)
{
    return moduleEntry(handle, label.c_str(), state);
}

int moduleEntry(const std::string &label, int state)
{
    return moduleEntry(-1, label, state);
}

int moduleEntry(handle_t handle, int state)
{
    handle_t retHandle = simModuleEntry(handle, nullptr, state);
    if(retHandle == -1)
        throw api_error("simModuleEntry");
    return retHandle;
}

bool checkExecAuthorization(const char *what, const char *args)
{
    int ret = simCheckExecAuthorization(what, args);
    if(ret == -1)
        throw api_error("simCheckExecAuthorization");
    return ret > 0;
}

bool checkExecAuthorization(const std::string &what, const std::string &args)
{
    return checkExecAuthorization(what.c_str(), args.c_str());
}

void pushFloatOntoStack(handle_t stackHandle, float value)
{
    addStackDebugLog("simPushFloatOntoStack %f", value);

    if(simPushFloatOntoStack(stackHandle, value) == -1)
        throw api_error("simPushFloatOntoStack");

    addStackDebugDump(stackHandle);
}

void pushFloatTableOntoStack(handle_t stackHandle, const float *values, int valueCnt)
{
    addStackDebugLog("simPushFloatTableOntoStack <%d values>", valueCnt);

    if(simPushFloatTableOntoStack(stackHandle, values, valueCnt) == -1)
        throw api_error("simPushFloatTableOntoStack");

    addStackDebugDump(stackHandle);
}

void pushFloatTableOntoStack(handle_t stackHandle, const std::vector<float> &values)
{
    pushFloatTableOntoStack(stackHandle, values.data(), values.size());
}

int getStackFloatValue(handle_t stackHandle, float *numberValue)
{
    int ret = simGetStackFloatValue(stackHandle, numberValue);
    if(ret == -1)
        throw api_error("simGetStackFloatValue");

#ifndef NDEBUG
    if(debugStackEnabled)
    {
        if(ret)
            addStackDebugLog("simGetStackFloatValue -> %f", *numberValue);
        else
            addStackDebugLog("simGetStackFloatValue -> not a float");
    }
#endif

    return ret;
}

int getStackFloatTable(handle_t stackHandle, float *array, int count)
{
    int ret = simGetStackFloatTable(stackHandle, array, count);

    addStackDebugLog("simGetStackFloatTable count = %d -> %d", count, ret);

    if(ret == -1)
        throw api_error("simGetStackFloatTable");
    return ret;
}

int getStackFloatTable(handle_t stackHandle, std::vector<float> *v)
{
    int count = getStackTableInfo(stackHandle, 0);
    v->resize(count);
    return getStackFloatTable(stackHandle, v->data(), count);
}

// float *simGetVisionSensorDepth(handle_t sensorHandle, int options, const int *pos, const int *size, int *resolution);

// int simSetVisionSensorDepth(handle_t sensorHandle, int options, const float *depth);

// float *simCheckVisionSensorEx(handle_t visionSensorHandle, handle_t entityHandle, bool returnImage);

// int simRuckigPos(int dofs, double baseCycleTime, int flags, const double *currentPos, const double *currentVel, const double *currentAccel, const double *maxVel, const double *maxAccel, const double *maxJerk, const bool *selection, const double *targetPos, const double *targetVel, double *reserved1, int *reserved2);

// int simRuckigVel(int dofs, double baseCycleTime, int flags, const double *currentPos, const double *currentVel, const double *currentAccel, const double *maxAccel, const double *maxJerk, const bool *selection, const double *targetVel, double *reserved1, int *reserved2);

// int simRuckigStep(handle_t objHandle, double cycleTime, double *newPos, double *newVel, double *newAccel, double *syncTime, double *reserved1, int *reserved2);

void pushDoubleOntoStack(handle_t stackHandle, double value)
{
    addStackDebugLog("simPushDoubleOntoStack %g", value);

    if(simPushDoubleOntoStack(stackHandle, value) == -1)
        throw api_error("simPushDoubleOntoStack");

    addStackDebugDump(stackHandle);
}

void pushDoubleTableOntoStack(handle_t stackHandle, const double *values, int valueCnt)
{
    addStackDebugLog("simPushDoubleTableOntoStack <%d values>", valueCnt);

    if(simPushDoubleTableOntoStack(stackHandle, values, valueCnt) == -1)
        throw api_error("simPushDoubleTableOntoStack");

    addStackDebugDump(stackHandle);
}

void pushDoubleTableOntoStack(handle_t stackHandle, const std::vector<double> &values)
{
    pushDoubleTableOntoStack(stackHandle, values.data(), values.size());
}

int getStackDoubleValue(handle_t stackHandle, double *numberValue)
{
    int ret = simGetStackDoubleValue(stackHandle, numberValue);
    if(ret == -1)
        throw api_error("simGetStackDoubleValue");

#ifndef NDEBUG
    if(debugStackEnabled)
    {
        if(ret)
            addStackDebugLog("simGetStackDoubleValue -> %g", *numberValue);
        else
            addStackDebugLog("simGetStackDoubleValue -> not a double");
    }
#endif

    return ret;
}

int getStackDoubleTable(handle_t stackHandle, double *array, int count)
{
    int ret = simGetStackDoubleTable(stackHandle, array, count);

    addStackDebugLog("simGetStackDoubleTable, count = %d -> %d", count, ret);

    if(ret == -1)
        throw api_error("simGetStackDoubleTable");
    return ret;
}

int getStackDoubleTable(handle_t stackHandle, std::vector<double> *v)
{
    int count = getStackTableInfo(stackHandle, 0);
    v->resize(count);
    return getStackDoubleTable(stackHandle, v->data(), count);
}

// int simExtLaunchUIThread(const char *applicationName, int options, const char *sceneOrModelOrUiToLoad, const char *applicationDir_);

// int simExtCanInitSimThread();

// int simExtSimThreadInit();

// int simExtSimThreadDestroy();

// int simExtPostExitRequest();

// int simExtGetExitRequest();

// int simExtStep(bool stepIfRunning);

// void _simSetDynamicSimulationIconCode(void *object, int code);

// void _simSetDynamicObjectFlagForVisualization(void *object, int flag);

// int _simGetObjectListSize(int objType);

// const void * _simGetObjectFromIndex(int objType, int index);

// int _simGetObjectID(const void *object);

// int _simGetObjectType(const void *object);

// const void ** _simGetObjectChildren(const void *object, int *count);

// const void * _simGetGeomProxyFromShape(const void *shape);

// const void * _simGetParentObject(const void *object);

// const void * _simGetObject(int objID);

// const void * _simGetIkGroupObject(int ikGroupID);

// int _simMpHandleIkGroupObject(const void *ikGroup);

// bool _simIsShapeDynamicallyStatic(const void *shape);

// int _simGetTreeDynamicProperty(const void *object);

// int _simGetDummyLinkType(const void *dummy, int *linkedDummyID);

// int _simGetJointMode(const void *joint);

// bool _simIsJointInHybridOperation(const void *joint);

// void _simDisableDynamicTreeForManipulation(const void *object, bool disableFlag);

// bool _simIsShapeDynamicallyRespondable(const void *shape);

// int _simGetDynamicCollisionMask(const void *shape);

// const void * _simGetLastParentForLocalGlobalCollidable(const void *shape);

// bool _simGetStartSleeping(const void *shape);

// bool _simGetWasPutToSleepOnce(const void *shape);

// bool _simGetDynamicsFullRefreshFlag(const void *object);

// void _simSetDynamicsFullRefreshFlag(const void *object, bool flag);

// void _simClearAdditionalForceAndTorque(const void *shape);

// int _simGetJointType(const void *joint);

// const void * _simGetGeomWrapFromGeomProxy(const void *geomData);

// int _simGetPurePrimitiveType(const void *geomInfo);

// bool _simIsGeomWrapGeometric(const void *geomInfo);

// bool _simIsGeomWrapConvex(const void *geomInfo);

// int _simGetGeometricCount(const void *geomInfo);

// void _simGetAllGeometrics(const void *geomInfo, void **allGeometrics);

// void _simMakeDynamicAnnouncement(int announceType);

// int _simGetTimeDiffInMs(int previousTime);

// bool _simDoEntitiesCollide(int entity1ID, int entity2ID, int *cacheBuffer, bool overrideCollidableFlagIfShape1, bool overrideCollidableFlagIfShape2, bool pathPlanningRoutineCalling);

// int _simGetJointDynCtrlMode(const void *joint);

// int simFloatingViewRemove(handle_t floatingViewHandle);

int getShapeViz(handle_t shapeHandle, int index, struct SShapeVizInfo *info)
{
    int ret = simGetShapeViz(shapeHandle, index, info);
    if(ret == -1)
        throw api_error("simGetShapeViz");
    return ret;
}

void setArrayParam(int parameter, std::array<double, 3> value)
{
    if(simSetArrayParam(parameter, value.data()) == -1)
        throw api_error("simSetArrayParam");
}

std::array<double, 3> getArrayParam(int parameter)
{
    std::array<double, 3> ret;
    if(simGetArrayParam(parameter, ret.data()) == -1)
        throw api_error("simGetArrayParam");
    return ret;
}

// int simSetFloatSignal(const char *signalName, double signalValue);

// int simGetFloatSignal(const char *signalName, double *signalValue);

void setFloatParam(int parameter, double value)
{
    if(simSetFloatParam(parameter, value) == -1)
        throw api_error("simSetFloatParam");
}

double getFloatParam(int parameter)
{
    double ret;
    if(simGetFloatParam(parameter, &ret) == -1)
        throw api_error("simGetFloatParam");
    return ret;
}

double getObjectFloatParam(handle_t objectHandle, int parameterID)
{
    double ret;
    if(simGetObjectFloatParam(objectHandle, parameterID, &ret) == -1)
        throw api_error("simGetObjectFloatParam");
    return ret;
}

void setObjectFloatParam(handle_t objectHandle, int parameterID, double parameter)
{
    if(simSetObjectFloatParam(objectHandle, parameterID, parameter) == -1)
        throw api_error("simSetObjectFloatParam");
}

// double *simGetObjectFloatArrayParam(handle_t objectHandle, int parameterID, int *size);

// int simSetObjectFloatArrayParam(handle_t objectHandle, int parameterID, const double *params, int size);

double getEngineFloatParam(int paramId, handle_t objectHandle, const void *object)
{
    bool ok = false;
    double ret = simGetEngineFloatParam(paramId, objectHandle, object, &ok);
    if(!ok)
        throw api_error("simGetEngineFloatParam");
    return ret;
}

void setEngineFloatParam(int paramId, handle_t objectHandle, const void *object, double val)
{
    if(simSetEngineFloatParam(paramId, objectHandle, object, val) != 1)
        throw api_error("simSetEngineFloatParam");
}

void transformImage(unsigned char *image, const int *resolution, int options)
{
    if(simTransformImage(image, resolution, options, nullptr, nullptr, nullptr) == -1)
        throw api_error("simTransformImage");
}

void transformImage(unsigned char *image, std::array<int, 2> resolution, int options)
{
    transformImage(image, resolution.data(), options);
}

// const double *simGetOctreeVoxels(handle_t octreeHandle, int *ptCnt, void *reserved);

std::vector<double> getPointCloudPoints(handle_t pointCloudHandle)
{
    int count = 0;
    const double *buf = simGetPointCloudPoints(pointCloudHandle, &count, 0);
    std::vector<double> ret;
    if(buf)
    {
        ret.resize(count * 3);
        for(size_t i = 0; i < count * 3; i++)
            ret[i] = buf[i];
    }
    return ret;
}

void getObjectMatrix(handle_t objectHandle, handle_t relativeToObjectHandle, double *matrix)
{
    if(simGetObjectMatrix(objectHandle, relativeToObjectHandle, matrix) == -1)
        throw api_error("simGetObjectMatrix");
}

std::array<double, 12> getObjectMatrix(handle_t objectHandle, handle_t relativeToObjectHandle)
{
    std::array<double, 12> ret;
    getObjectMatrix(objectHandle, relativeToObjectHandle, ret.data());
    return ret;
}

void setObjectMatrix(handle_t objectHandle, handle_t relativeToObjectHandle, const double *matrix)
{
    if(simSetObjectMatrix(objectHandle, relativeToObjectHandle, matrix) == -1)
        throw api_error("simSetObjectMatrix");
}

void setObjectMatrix(handle_t objectHandle, handle_t relativeToObjectHandle, const std::array<double, 12> &matrix)
{
    setObjectMatrix(objectHandle, relativeToObjectHandle, matrix.data());
}

void getObjectPose(handle_t objectHandle, handle_t relativeToObjectHandle, double *pose)
{
    if(simGetObjectPose(objectHandle, relativeToObjectHandle, pose) == -1)
        throw api_error("simGetObjectPose");
}

std::array<double, 7> getObjectPose(handle_t objectHandle, handle_t relativeToObjectHandle)
{
    std::array<double, 7> ret;
    getObjectPose(objectHandle, relativeToObjectHandle, ret.data());
    return ret;
}

void setObjectPose(handle_t objectHandle, handle_t relativeToObjectHandle, const double *pose)
{
    if(simSetObjectPose(objectHandle, relativeToObjectHandle, pose) == -1)
        throw api_error("simSetObjectPose");
}

void setObjectPose(handle_t objectHandle, handle_t relativeToObjectHandle, std::array<double, 7> pose)
{
    setObjectPose(objectHandle, relativeToObjectHandle, pose.data());
}

void getObjectPosition(handle_t objectHandle, handle_t relativeToObjectHandle, double *position)
{
    if(simGetObjectPosition(objectHandle, relativeToObjectHandle, position) == -1)
        throw api_error("simGetObjectPosition");
}

std::array<double, 3> getObjectPosition(handle_t objectHandle, handle_t relativeToObjectHandle)
{
    std::array<double, 3> ret;
    getObjectPosition(objectHandle, relativeToObjectHandle, ret.data());
    return ret;
}

void setObjectPosition(handle_t objectHandle, handle_t relativeToObjectHandle, const double *position)
{
    if(simSetObjectPosition(objectHandle, relativeToObjectHandle, position) == -1)
        throw api_error("simSetObjectPosition");
}

void setObjectPosition(handle_t objectHandle, handle_t relativeToObjectHandle, const std::array<double, 3> &position)
{
    setObjectPosition(objectHandle, relativeToObjectHandle, position.data());
}

void getObjectOrientation(handle_t objectHandle, handle_t relativeToObjectHandle, double *eulerAngles)
{
    if(simGetObjectOrientation(objectHandle, relativeToObjectHandle, eulerAngles) == -1)
        throw api_error("simGetObjectOrientation");
}

std::array<double, 3> getObjectOrientation(handle_t objectHandle, handle_t relativeToObjectHandle)
{
    std::array<double, 3> ret;
    getObjectOrientation(objectHandle, relativeToObjectHandle, ret.data());
    return ret;
}

void setObjectOrientation(handle_t objectHandle, handle_t relativeToObjectHandle, const double *eulerAngles)
{
    if(simSetObjectOrientation(objectHandle, relativeToObjectHandle, eulerAngles) == -1)
        throw api_error("simSetObjectOrientation");
}

void setObjectOrientation(handle_t objectHandle, handle_t relativeToObjectHandle, const std::array<double, 3> &eulerAngles)
{
    setObjectOrientation(objectHandle, relativeToObjectHandle, eulerAngles.data());
}

double getJointPosition(handle_t objectHandle)
{
    double position;
    if(simGetJointPosition(objectHandle, &position) == -1)
        throw api_error("simGetJointPosition");
    return position;
}

void setJointPosition(handle_t objectHandle, double position)
{
    if(simSetJointPosition(objectHandle, position) == -1)
        throw api_error("simGetJointPosition");
}

void setJointTargetPosition(handle_t objectHandle, double targetPosition)
{
    if(simSetJointTargetPosition(objectHandle, targetPosition) == -1)
        throw api_error("simSetJointTargetPosition");
}

double getJointTargetPosition(handle_t objectHandle)
{
    double targetPosition;
    if(simGetJointTargetPosition(objectHandle, &targetPosition) == -1)
        throw api_error("simGetJointTargetPosition");
    return targetPosition;
}

double getJointTargetForce(handle_t jointHandle)
{
    double forceOrTorque;
    if(simGetJointTargetForce(jointHandle, &forceOrTorque) == -1)
        throw api_error("simGetJointTargetForce");
    return forceOrTorque;
}

void setJointTargetForce(handle_t objectHandle, double forceOrTorque, bool signedValue)
{
    if(simSetJointTargetForce(objectHandle, forceOrTorque, signedValue) == -1)
        throw api_error("simSetJointTargetForce");
}

void getObjectChildPose(handle_t objectHandle, double *pose)
{
    if(simGetObjectChildPose(objectHandle, pose) == -1)
        throw api_error("simGetObjectChildPose");
}

std::array<double, 7> getObjectChildPose(handle_t objectHandle)
{
    std::array<double, 7> pose;
    getObjectChildPose(objectHandle, pose.data());
    return pose;
}

void setObjectChildPose(handle_t objectHandle, const double *pose)
{
    if(simSetObjectChildPose(objectHandle, pose) == -1)
        throw api_error("simSetObjectChildPose");
}

void setObjectChildPose(handle_t objectHandle, std::array<double, 7> pose)
{
    setObjectChildPose(objectHandle, pose.data());
}

void getJointInterval(handle_t objectHandle, bool *cyclic, double *interval)
{
    if(simGetJointInterval(objectHandle, cyclic, interval) == -1)
        throw api_error("simGetJointInterval");
}

std::array<double, 2> getJointInterval(handle_t objectHandle, bool *cyclic)
{
    std::array<double, 2> interval;
    getJointInterval(objectHandle, cyclic, interval.data());
    return interval;
}

void setJointInterval(handle_t objectHandle, bool cyclic, const double *interval)
{
    if(simSetJointInterval(objectHandle, cyclic, interval) == -1)
        throw api_error("simSetJointInterval");
}

void setJointInterval(handle_t objectHandle, bool cyclic, std::array<double, 2> interval)
{
    setJointInterval(objectHandle, cyclic, interval.data());
}

// int simBuildIdentityMatrix(double *matrix);

// int simBuildMatrix(const double *position, const double *eulerAngles, double *matrix);

// int simBuildPose(const double *position, const double *eulerAngles, double *pose);

// int simGetEulerAnglesFromMatrix(const double *matrix, double *eulerAngles);

// int simInvertMatrix(double *matrix);

std::array<double, 12> multiplyMatrices(std::array<double, 12> matrixIn1, std::array<double, 12> matrixIn2)
{
    std::array<double, 12> ret;
    if(simMultiplyMatrices(matrixIn1.data(), matrixIn2.data(), ret.data()) == -1)
        throw api_error("simMultiplyMatrices");
    return ret;
}

std::array<double, 7> multiplyPoses(std::array<double, 7> poseIn1, std::array<double, 7> poseIn2)
{
    std::array<double, 7> ret;
    if(simMultiplyPoses(poseIn1.data(), poseIn2.data(), ret.data()) == -1)
        throw api_error("simMultiplyPoses");
    return ret;
}

std::array<double, 7> invertPose(std::array<double, 7> pose)
{
    std::array<double, 7> ret(pose);
    if(simInvertPose(ret.data()) == -1)
        throw api_error("simInvertPose");
    return ret;
}

std::array<double, 7> interpolatePoses(std::array<double, 7> poseIn1, std::array<double, 7> poseIn2, double interpolFactor)
{
    std::array<double, 7> ret;
    if(simInterpolatePoses(poseIn1.data(), poseIn2.data(), interpolFactor, ret.data()) == -1)
        throw api_error("simInterpolatePoses");
    return ret;
}

std::array<double, 12> poseToMatrix(std::array<double, 7> poseIn)
{
    std::array<double, 12> ret;
    if(simPoseToMatrix(poseIn.data(), ret.data()) == -1)
        throw api_error("simPoseToMatrix");
    return ret;
}

std::array<double, 7> matrixToPose(std::array<double, 12> matrixIn)
{
    std::array<double, 7> ret;
    if(simMatrixToPose(matrixIn.data(), ret.data()) == -1)
        throw api_error("simMatrixToPose");
    return ret;
}

std::array<double, 12> interpolateMatrices(std::array<double, 12> matrixIn1, std::array<double, 12> matrixIn2, double interpolFactor)
{
    std::array<double, 12> ret;
    if(simInterpolateMatrices(matrixIn1.data(), matrixIn2.data(), interpolFactor, ret.data()) == -1)
        throw api_error("simInterpolateMatrices");
    return ret;
}

void transformVector(const double *matrix, double *vect)
{
    if(simTransformVector(matrix, vect) == -1)
        throw api_error("simTransformVector");
}

std::array<double, 3> transformVector(std::array<double, 12> matrix, std::array<double, 3> vect)
{
    std::array<double, 3> ret(vect);
    transformVector(matrix.data(), ret.data());
    return ret;
}

double getSimulationTime()
{
    double ret = simGetSimulationTime();
    if(ret < 0)
        throw api_error("simGetSimulationTime");
    return ret;
}

double getSystemTime()
{
    return simGetSystemTime();
}

// int simHandleProximitySensor(handle_t sensorHandle, double *detectedPoint, int *detectedObjectHandle, double *normalVector);

// int simReadProximitySensor(handle_t sensorHandle, double *detectedPoint, int *detectedObjectHandle, double *normalVector);

// int simHandleDynamics(double deltaTime);

// int simCheckProximitySensor(handle_t sensorHandle, handle_t entityHandle, double *detectedPoint);

// int simCheckProximitySensorEx(handle_t sensorHandle, handle_t entityHandle, int detectionMode, double detectionThreshold, double maxAngle, double *detectedPoint, int *detectedObjectHandle, double *normalVector);

// int simCheckProximitySensorEx2(handle_t sensorHandle, double *vertexPointer, int itemType, int itemCount, int detectionMode, double detectionThreshold, double maxAngle, double *detectedPoint, double *normalVector);

// int simCheckCollisionEx(handle_t entity1Handle, handle_t entity2Handle, double **intersectionSegments);

// int simCheckDistance(handle_t entity1Handle, handle_t entity2Handle, double threshold, double *distanceData);

// int simSetSimulationTimeStep(double timeStep);

double getSimulationTimeStep()
{
    double ret = simGetSimulationTimeStep();
    if(ret < 0)
        throw api_error("simGetSimulationTimeStep");
    return ret;
}

// int simAdjustRealTimeTimer(int instanceIndex, double deltaTime);

// int simFloatingViewAdd(double posX, double posY, double sizeX, double sizeY, int options);

// int simHandleGraph(handle_t graphHandle, double simulationTime);

// int simSetGraphStreamTransformation(handle_t graphHandle, int streamId, int trType, double mult, double off, int movingAvgPeriod);

// int simAddGraphCurve(handle_t graphHandle, const char *curveName, int dim, const int *streamIds, const double *defaultValues, const char *unitStr, int options, const float *color, int curveWidth);

// int simSetGraphStreamValue(handle_t graphHandle, int streamId, double value);

// int simSetJointTargetVelocity(handle_t objectHandle, double targetVelocity);

// int simGetJointTargetVelocity(handle_t objectHandle, double *targetVelocity);

// int simScaleObjects(const int *objectHandles, int objectCount, double scalingFactor, bool scalePositionsToo);

// int simAddDrawingObject(int objectType, double size, double duplicateTolerance, handle_t parentObjectHandle, int maxItemCount, const float *color, const float *setToNULL, const float *setToNULL2, const float *setToNULL3);

// int simAddGraphStream(handle_t graphHandle, const char *streamName, const char *unitStr, int options, const float *color, double cyclicRange);

// int simAddDrawingObjectItem(handle_t objectHandle, const double *itemData);

// double simGetObjectSizeFactor(handle_t objectHandle);

// int simReadForceSensor(handle_t objectHandle, double *forceVector, double *torqueVector);

// int simSetLightParameters(handle_t objectHandle, int state, const float *setToNULL, const float *diffusePart, const float *specularPart);

int getLightParameters(handle_t objectHandle)
{
    int ret = simGetLightParameters(objectHandle, nullptr, nullptr, nullptr);
    if(ret == -1)
        throw api_error("simGetLightParameters");
    return ret;
}

int getLightParameters(handle_t objectHandle, std::array<double, 3> &diffuse)
{
    int ret = simGetLightParameters(objectHandle, nullptr, diffuse.data(), nullptr);
    if(ret == -1)
        throw api_error("simGetLightParameters");
    return ret;
}

int getLightParameters(handle_t objectHandle, std::array<double, 3> &diffuse, std::array<double, 3> &specular)
{
    int ret = simGetLightParameters(objectHandle, nullptr, diffuse.data(), specular.data());
    if(ret == -1)
        throw api_error("simGetLightParameters");
    return ret;
}

// int simGetVelocity(handle_t shapeHandle, double *linearVelocity, double *angularVelocity);

std::pair<std::array<double, 3>, std::array<double, 3>> getObjectVelocity(handle_t objectHandle)
{
    std::array<double, 3> lin, ang;
    if(simGetObjectVelocity(objectHandle, lin.data(), ang.data()) == -1)
        throw api_error("simGetObjectVelocity");
    return std::make_pair(lin, ang);
}

// int simGetJointVelocity(handle_t jointHandle, double *velocity);

// int simAddForceAndTorque(handle_t shapeHandle, const double *force, const double *torque);

// int simAddForce(handle_t shapeHandle, const double *position, const double *force);

void setObjectColor(handle_t objectHandle, int index, int colorComponent, const float *rgbData)
{
    int ret = simSetObjectColor(objectHandle, index, colorComponent, rgbData);
    if(ret == -1)
        throw api_error("simSetObjectColor");
}

void setObjectColor(handle_t objectHandle, int index, int colorComponent, const std::array<float, 3> &rgbData)
{
    setObjectColor(objectHandle, index, colorComponent, rgbData.data());
}

std::optional<std::array<float, 3>> getObjectColor(handle_t objectHandle, int index, int colorComponent)
{
    std::array<float, 3> rgbData;
    int ret = simGetObjectColor(objectHandle, index, colorComponent, rgbData.data());
    if(ret == -1)
        throw api_error("simGetObjectColor");
    if(ret == 0)
        return {};
    return rgbData;
}

void setShapeColor(handle_t shapeHandle, const char *colorName, int colorComponent, const float *rgbData)
{
    int ret = simSetShapeColor(shapeHandle, colorName, colorComponent, rgbData);
    if(ret == -1)
        throw api_error("simSetShapeColor");
}

void setShapeColor(handle_t shapeHandle, std::optional<std::string> colorName, int colorComponent, const std::array<float, 3> &rgbData)
{
    setShapeColor(shapeHandle, colorName ? colorName->c_str() : nullptr, colorComponent, rgbData.data());
}

std::optional<std::array<float, 3>> getShapeColor(handle_t shapeHandle, std::optional<std::string> colorName, int colorComponent)
{
    std::array<float, 3> rgbData;
    int ret = simGetShapeColor(shapeHandle, colorName ? colorName->c_str() : 0, colorComponent, rgbData.data());
    if(ret == -1)
        throw api_error("simGetShapeColor");
    if(ret == 0)
        return {};
    return rgbData;
}

std::optional<std::array<float, 3>> getShapeColor(handle_t shapeHandle, int colorComponent)
{
    return getShapeColor(shapeHandle, {}, colorComponent);
}

// int simGetContactInfo(int dynamicPass, handle_t objectHandle, int index, int *objectHandles, double *contactInfo);

// int simAuxiliaryConsoleOpen(const char *title, int maxLines, int mode, const int *position, const int *size, const float *textColor, const float *backgroundColor);

handle_t importShape(const char *pathAndFilename, int options, double scalingFactor)
{
    handle_t handle = simImportShape(0, pathAndFilename, options, 0, scalingFactor);
    if(handle == -1)
        throw api_error("simImportShape");
    return handle;
}

handle_t importShape(const std::string &pathAndFilename, int options, double scalingFactor)
{
    return importShape(pathAndFilename.c_str(), options, scalingFactor);
}

// int simImportMesh(int fileformat, const char *pathAndFilename, int options, double identicalVerticeTolerance, double scalingFactor, double ***vertices, int **verticesSizes, int ***indices, int **indicesSizes, double ***reserved, char ***names);

// int simExportMesh(int fileformat, const char *pathAndFilename, int options, double scalingFactor, int elementCount, const double **vertices, const int *verticesSizes, const int **indices, const int *indicesSizes, double **reserved, const char **names);

handle_t createMeshShape(int options, double shadingAngle, const double *vertices, int verticesSize, const int *indices, int indicesSize)
{
    handle_t handle = simCreateMeshShape(options, shadingAngle, vertices, verticesSize, indices, indicesSize, nullptr);
    if(handle == -1)
        throw api_error("simCreateMeshShape");
    return handle;
}

handle_t createMeshShape(int options, double shadingAngle, const std::vector<double> &vertices, const std::vector<int> &indices)
{
    return createMeshShape(options, shadingAngle, vertices.data(), vertices.size(), indices.data(), indices.size());
}

handle_t createPrimitiveShape(int primitiveType, const double *sizes, int options)
{
    handle_t handle = simCreatePrimitiveShape(primitiveType, sizes, options);
    if(handle == -1)
        throw api_error("simCreatePrimitiveShape");
    return handle;
}

handle_t createPrimitiveShape(int primitiveType, std::array<double, 3> sizes, int options)
{
    return createPrimitiveShape(primitiveType, sizes.data(), options);
}

handle_t createHeightfieldShape(int options, double shadingAngle, int xPointCount, int yPointCount, double xSize, const double *heights)
{
    handle_t handle = simCreateHeightfieldShape(options, shadingAngle, xPointCount, yPointCount, xSize, heights);
    if(handle == -1)
        throw api_error("simCreateHeightfieldShape");
    return handle;
}

handle_t createHeightfieldShape(int options, double shadingAngle, int xPointCount, int yPointCount, double xSize, const std::vector<double> &heights)
{
    return createHeightfieldShape(options, shadingAngle, xPointCount, yPointCount, xSize, heights.data());
}

void getShapeMesh(handle_t shapeHandle, double **vertices, int *verticesSize, int **indices, int *indicesSize, double **normals)
{
    if(simGetShapeMesh(shapeHandle, vertices, verticesSize, indices, indicesSize, normals) == -1)
        throw api_error("simGetShapeMesh");
}

void getShapeMesh(handle_t shapeHandle, std::vector<double> vertices, std::vector<int> indices, std::optional<std::vector<double>> normals)
{
    double *verticesBuf;
    int verticesSize = 0;
    int *indicesBuf;
    int indicesSize = 0;
    double *normalsBuf;
    getShapeMesh(shapeHandle, &verticesBuf, &verticesSize, &indicesBuf, &indicesSize, normals ? &normalsBuf : nullptr);
    vertices.assign(verticesBuf, verticesBuf + verticesSize);
    indices.assign(indicesBuf, indicesBuf + indicesSize);
    if(normals)
        normals->assign(normalsBuf, normalsBuf + indicesSize * 3);
    releaseBuffer(verticesBuf);
    releaseBuffer(indicesBuf);
    releaseBuffer(normalsBuf);
}

handle_t createJoint(int jointType, int jointMode, int options, const double *sizes)
{
    handle_t handle = simCreateJoint(jointType, jointMode, options, sizes, nullptr, nullptr);
    if(handle == -1)
        throw api_error("simCreateJoint");
    return handle;
}

handle_t createJoint(int jointType, int jointMode, int options, std::optional<std::array<double, 2>> sizes)
{
    return createJoint(jointType, jointMode, options, sizes ? sizes->data() : nullptr);
}

handle_t createDummy(double size)
{
    handle_t handle = simCreateDummy(size, nullptr);
    if(handle == -1)
        throw api_error("simCreateDummy");
    return handle;
}

handle_t createForceSensor(int options, const int *intParams, const double *floatParams)
{
    handle_t handle = simCreateForceSensor(options, intParams, floatParams, nullptr);
    if(handle == -1)
        throw api_error("simCreateForceSensor");
    return handle;
}

handle_t createForceSensor(int options, int type, int valueCount, int thresholdCount, double size, double forceThreshold, double torqueThreshold)
{
    int intParams[] = {
        type,
        valueCount,
        thresholdCount,
        0,
        0
    };
    double floatParams[] = {
        size,
        forceThreshold,
        torqueThreshold,
        0.0,
        0.0
    };
    return createForceSensor(options, &intParams[0], &floatParams[0]);
}

handle_t createVisionSensor(int options, const int *intParams, const double *floatParams)
{
    handle_t handle = simCreateVisionSensor(options, intParams, floatParams, nullptr);
    if(handle == -1)
        throw api_error("simCreateVisionSensor");
    return handle;
}

handle_t createVisionSensor(int options, std::array<int, 2> resolution, double clipNear, double clipFar, double viewAngleOrOrthoSize, double xSize, std::array<float, 3> nullPixelColor)
{
    int intParams[] = {
        resolution[0],
        resolution[1],
        0,
        0
    };
    double floatParams[] = {
        clipNear,
        clipFar,
        viewAngleOrOrthoSize,
        xSize,
        0.0,
        0.0,
        nullPixelColor[0],
        nullPixelColor[1],
        nullPixelColor[2],
        0.0,
        0.0
    };
    return createVisionSensor(options, &intParams[0], &floatParams[0]);
}

handle_t createProximitySensor(int sensorType, int options, const int *intParams, const double *floatParams)
{
    handle_t handle = simCreateProximitySensor(sensorType, 16, options, intParams, floatParams, nullptr);
    if(handle == -1)
        throw api_error("simCreateProximitySensor");
    return handle;
}

handle_t createProximitySensor(int sensorType, int options, int faceCount, int faceCountFar, int subdivisions, int subdivisionsFar, int randDetSampleCountPerReading, int randDetIndividualRayDetCntForTrig, double offset, double range, std::array<double, 2> size, std::array<double, 2> sizeFar, double insideGap, double radius, double radiusFar, double angle, double thresholdAngle, double smallestDetDist, double sensPointSize)
{
    int intParams[] = {
        faceCount,
        faceCountFar,
        subdivisions,
        subdivisionsFar,
        randDetSampleCountPerReading,
        randDetIndividualRayDetCntForTrig,
        0,
        0
    };
    double floatParams[] = {
        offset,
        range,
        size[0],
        size[1],
        sizeFar[0],
        sizeFar[1],
        insideGap,
        radius,
        radiusFar,
        angle,
        thresholdAngle,
        smallestDetDist,
        sensPointSize,
        0.0,
        0.0
    };
    return createProximitySensor(sensorType, options, &intParams[0], &floatParams[0]);
}

std::pair<std::array<double, 3>, double> getRotationAxis(std::array<double, 12> matrixStart, std::array<double, 12> matrixGoal)
{
    std::array<double, 3> axis;
    double angle;
    if(simGetRotationAxis(matrixStart.data(), matrixGoal.data(), axis.data(), &angle) == -1)
        throw api_error("simGetRotationAxis");
    return std::make_pair(axis, angle);
}

std::pair<std::array<double, 3>, double> getRotationAxis(std::array<double, 7> matrixStart, std::array<double, 7> matrixGoal)
{
    std::array<double, 3> axis;
    double angle;
    if(simGetRotationAxis(matrixStart.data(), matrixGoal.data(), axis.data(), &angle) == -1)
        throw api_error("simGetRotationAxis");
    return std::make_pair(axis, angle);
}

// int simRotateAroundAxis(const double *matrixIn, const double *axis, const double *axisPos, double angle, double *matrixOut);

// int simGetJointForce(handle_t jointHandle, double *forceOrTorque);

// int simCameraFitToView(int viewHandleOrIndex, int objectCount, const int *objectHandles, int options, double scaling);

// int simHandleVisionSensor(handle_t visionSensorHandle, double **auxValues, int **auxValuesCount);

// int simReadVisionSensor(handle_t visionSensorHandle, double **auxValues, int **auxValuesCount);

// int simCheckVisionSensor(handle_t visionSensorHandle, handle_t entityHandle, double **auxValues, int **auxValuesCount);

unsigned char * getVisionSensorImg(handle_t sensorHandle, int options, double rgbaCutOff, std::array<int, 2> pos, std::array<int, 2> size, std::array<int, 2> *resolution)
{
    unsigned char *buf = simGetVisionSensorImg(sensorHandle, options, rgbaCutOff, pos.data(), size.data(), resolution ? resolution->data() : nullptr);
    if(!buf)
        throw api_error("simGetVisionSensorImg");
    return buf;
}

std::array<int, 2> getVisionSensorRes(handle_t visionSensorHandle)
{
    std::array<int, 2> ret;
    if(simGetVisionSensorRes(visionSensorHandle, ret.data()) == -1)
        throw api_error("simGetVisionSensorRes");
    return ret;
}

std::array<double, 4> getObjectQuaternion(handle_t objectHandle, handle_t relativeToObjectHandle)
{
    std::array<double, 4> ret;
    if(simGetObjectQuaternion(objectHandle, relativeToObjectHandle, ret.data()) == -1)
        throw api_error("simGetObjectQuaternion");
    return ret;
}

void setObjectQuaternion(handle_t objectHandle, handle_t relativeToObjectHandle, const std::array<double, 4> &quaternion)
{
    if(simSetObjectQuaternion(objectHandle, relativeToObjectHandle, quaternion.data()) == -1)
        throw api_error("simSetObjectQuaternion");
}

// int simConvexDecompose(handle_t shapeHandle, int options, const int *intParams, const double *floatParams);

void writeTexture(int textureId, int options, const char *data, int posX, int posY, int sizeX, int sizeY, double interpol)
{
    if(simWriteTexture(textureId, options, data, posX, posY, sizeX, sizeY, interpol) == -1)
        throw api_error("simWriteTexture");
}

// int simCreateTexture(const char *fileName, int options, const double *planeSizes, const double *scalingUV, const double *xy_g, int fixedResolution, int *textureId, int *resolution, const void *reserved);

// int simGetShapeGeomInfo(handle_t shapeHandle, int *intData, double *floatData, void *reserved);

// int simScaleObject(handle_t objectHandle, double xScale, double yScale, double zScale, int options);

// int simSetShapeTexture(handle_t shapeHandle, int textureId, int mappingMode, int options, const double *uvScaling, const double *position, const double *orientation);

// int simGetQHull(const double *inVertices, int inVerticesL, double **verticesOut, int *verticesOutL, int **indicesOut, int *indicesOutL, int reserved1, const double *reserved2);

// int simGetDecimatedMesh(const double *inVertices, int inVerticesL, const int *inIndices, int inIndicesL, double **verticesOut, int *verticesOutL, int **indicesOut, int *indicesOutL, double decimationPercent, int reserved1, const double *reserved2);

// int simComputeMassAndInertia(handle_t shapeHandle, double density);

// int simCreateOctree(double voxelSize, int options, double pointSize, void *reserved);

handle_t createPointCloud(double maxVoxelSize, int maxPtCntPerVoxel, int options, double pointSize)
{
    handle_t ret = simCreatePointCloud(maxVoxelSize, maxPtCntPerVoxel, options, pointSize, nullptr);
    if(ret == -1)
        throw api_error("simCreatePointCloud");
    return ret;
}

// int simSetPointCloudOptions(handle_t pointCloudHandle, double maxVoxelSize, int maxPtCntPerVoxel, int options, double pointSize, void *reserved);

// int simGetPointCloudOptions(handle_t pointCloudHandle, double *maxVoxelSize, int *maxPtCntPerVoxel, int *options, double *pointSize, void *reserved);

// int simInsertVoxelsIntoOctree(handle_t octreeHandle, int options, const double *pts, int ptCnt, const unsigned char *color, const unsigned int *tag, void *reserved);

// int simRemoveVoxelsFromOctree(handle_t octreeHandle, int options, const double *pts, int ptCnt, void *reserved);

// int simInsertPointsIntoPointCloud(handle_t pointCloudHandle, int options, const double *pts, int ptCnt, const unsigned char *color, void *optionalValues);

// int simRemovePointsFromPointCloud(handle_t pointCloudHandle, int options, const double *pts, int ptCnt, double tolerance, void *reserved);

// int simIntersectPointsWithPointCloud(handle_t pointCloudHandle, int options, const double *pts, int ptCnt, double tolerance, void *reserved);

int insertObjectIntoPointCloud(handle_t pointCloudHandle, handle_t objectHandle, int options, double gridSize, std::optional<std::array<unsigned char, 3>> color, std::optional<float> duplicateTolerance)
{
    std::array<unsigned char, 3> color_;
    unsigned char *colorPtr = nullptr;
    if(color)
    {
        color_ = *color;
        colorPtr = color_.data();
    }

    int optionalValues[2];
    void *optionalValuesPtr = nullptr;
    if(duplicateTolerance)
    {
        optionalValuesPtr = &optionalValues[0];
        ((int *)optionalValuesPtr)[0] = 1;
        ((float *)optionalValuesPtr)[1] = *duplicateTolerance;
    }

    int ret = simInsertObjectIntoPointCloud(pointCloudHandle, objectHandle, options, gridSize, colorPtr, optionalValuesPtr);
    if(ret == -1)
        throw api_error("simInsertObjectIntoPointCloud");
    return ret;
}

// int simSubtractObjectFromPointCloud(handle_t pointCloudHandle, handle_t objectHandle, int options, double tolerance, void *reserved);

bool checkOctreePointOccupancy(handle_t octreeHandle, int options, const double *points, int ptCnt, unsigned int *tag, unsigned long long int *location)
{
    int ret = simCheckOctreePointOccupancy(octreeHandle, options, points, ptCnt, tag, location, nullptr);
    if(ret == -1)
        throw api_error("simCheckOctreePointOccupancy");
    return ret > 0;
}

bool checkOctreePointOccupancy(handle_t octreeHandle, int options, const std::vector<double> &pts, unsigned int *tag, unsigned long long int *location)
{
    return checkOctreePointOccupancy(octreeHandle, options, pts.data(), pts.size(), tag, location);
}

// int simApplyTexture(handle_t shapeHandle, const double *textureCoordinates, int textCoordSize, const unsigned char *texture, const int *textureResolution, int options);

// int simSetJointDependency(handle_t jointHandle, handle_t masterJointHandle, double offset, double multCoeff);

// int simGetJointDependency(handle_t jointHandle, int *masterJointHandle, double *offset, double *multCoeff);

double getShapeMass(handle_t shapeHandle)
{
    double mass = 0.0;
    if(simGetShapeMass(shapeHandle, &mass) == -1)
        throw api_error("simGetShapeMass");
    return mass;
}

void setShapeMass(handle_t shapeHandle, double mass)
{
    if(simSetShapeMass(shapeHandle, mass) == -1)
        throw api_error("simSetShapeMass");
}

void getShapeInertia(handle_t shapeHandle, double *inertiaMatrix, double *transformationMatrix)
{
    if(simGetShapeInertia(shapeHandle, inertiaMatrix, transformationMatrix) == -1)
        throw api_error("simGetShapeInertia");
}

std::pair<std::array<double, 9>, std::array<double, 12>> getShapeInertia(handle_t shapeHandle)
{
    std::array<double, 9> inertiaMatrix;
    std::array<double, 12> transformationMatrix;
    getShapeInertia(shapeHandle, inertiaMatrix.data(), transformationMatrix.data());
    return std::make_pair(inertiaMatrix, transformationMatrix);
}

void setShapeInertia(handle_t shapeHandle, const double *inertiaMatrix, const double *transformationMatrix)
{
    if(simSetShapeInertia(shapeHandle, inertiaMatrix, transformationMatrix) == -1)
        throw api_error("simSetShapeInertia");
}

void setShapeInertia(handle_t shapeHandle, std::array<double, 9> inertiaMatrix, std::array<double, 12> transformationMatrix)
{
    return setShapeInertia(shapeHandle, inertiaMatrix.data(), transformationMatrix.data());
}

// int simGenerateShapeFromPath(const double *path, int pathSize, const double *section, int sectionSize, int options, const double *upVector, double reserved);

// double simGetClosestPosOnPath(const double *path, int pathSize, const double *pathLengths, const double *absPt);

// int simExtCallScriptFunction(int scriptHandleOrType, const char *functionNameAtScriptName, const int *inIntData, int inIntCnt, const double *inFloatData, int inFloatCnt, const char **inStringData, int inStringCnt, const char *inBufferData, int inBufferCnt, int **outIntData, int *outIntCnt, double **outFloatData, int *outFloatCnt, char ***outStringData, int *outStringCnt, char **outBufferData, int *outBufferSize);

// void simGetObjectLocalTransformation(const void *object, double *pos, double *quat, bool excludeFirstJointTransformation);

// void simSetObjectLocalTransformation(void *object, const double *pos, const double *quat, double simTime);

// void simDynReportObjectCumulativeTransformation(void *object, const double *pos, const double *quat, double simTime);

// void simSetObjectCumulativeTransformation(void *object, const double *pos, const double *quat, bool keepChildrenInPlace);

// void simGetObjectCumulativeTransformation(const void *object, double *pos, double *quat, bool excludeFirstJointTransformation);

// void simSetJointVelocity(const void *joint, double vel);

// void simSetJointPosition(const void *joint, double pos);

// double simGetJointPosition(const void *joint);

// void simSetDynamicMotorPositionControlTargetPosition(const void *joint, double pos);

// void simGetInitialDynamicVelocity(const void *shape, double *vel);

// void simSetInitialDynamicVelocity(void *shape, const double *vel);

// void simGetInitialDynamicAngVelocity(const void *shape, double *angularVel);

// void simSetInitialDynamicAngVelocity(void *shape, const double *angularVel);

// void simSetShapeDynamicVelocity(void *shape, const double *linear, const double *angular, double simTime);

// void simGetAdditionalForceAndTorque(const void *shape, double *force, double *torque);

// bool simGetJointPositionInterval(const void *joint, double *minValue, double *rangeValue);

// double simGetDynamicMotorTargetPosition(const void *joint);

// double simGetDynamicMotorTargetVelocity(const void *joint);

// double simGetDynamicMotorMaxForce(const void *joint);

// double simGetDynamicMotorUpperLimitVelocity(const void *joint);

// void simSetDynamicMotorReflectedPositionFromDynamicEngine(void *joint, double pos, double simTime);

// void simSetJointSphericalTransformation(void *joint, const double *quat, double simTime);

// void simAddForceSensorCumulativeForcesAndTorques(void *forceSensor, const double *force, const double *torque, int totalPassesCount, double simTime);

// void simAddJointCumulativeForcesOrTorques(void *joint, double forceOrTorque, int totalPassesCount, double simTime);

// double simGetMass(const void *geomInfo);

// double simGetLocalInertiaInfo(const void *object, double *pos, double *quat, double *diagI);

// void simGetPurePrimitiveSizes(const void *geometric, double *sizes);

// void simGetVerticesLocalFrame(const void *geometric, double *pos, double *quat);

// const double *simGetHeightfieldData(const void *geometric, int *xCount, int *yCount, double *minHeight, double *maxHeight);

// void simGetCumulativeMeshes(const void *geomInfo, double **vertices, int *verticesSize, int **indices, int *indicesSize);

// void simGetGravity(double *gravity);

// bool simGetDistanceBetweenEntitiesIfSmaller(int entity1ID, int entity2ID, double *distance, double *ray, int *cacheBuffer, bool overrideMeasurableFlagIfNonCollection1, bool overrideMeasurableFlagIfNonCollection2, bool pathPlanningRoutineCalling);

// int simHandleJointControl(const void *joint, int auxV, const int *inputValuesInt, const double *inputValuesFloat, double *outputValues);

// int simHandleCustomContact(int objHandle1, int objHandle2, int engine, int *dataInt, double *dataFloat);

// double simGetPureHollowScaling(const void *geometric);

// void simDynCallback(const int *intData, const double *floatData);

void setBoolProperty(handle_t target, const std::string &pname, bool value)
{
    int ret = simSetBoolProperty(target, pname.c_str(), value);
    if(ret == -1)
        throw api_error("simSetBoolProperty");
}

bool getBoolProperty(handle_t target, const std::string &pname)
{
    int value = 0;
    int ret = simGetBoolProperty(target, pname.c_str(), &value);
    if(ret == -1)
        throw api_error("simGetBoolProperty");
    return value > 0;
}

void setIntProperty(handle_t target, const std::string &pname, int value)
{
    int ret = simSetIntProperty(target, pname.c_str(), value);
    if(ret == -1)
        throw api_error("simSetIntProperty");
}

int getIntProperty(handle_t target, const std::string &pname)
{
    int value = 0;
    int ret = simGetIntProperty(target, pname.c_str(), &value);
    if(ret == -1)
        throw api_error("simGetIntProperty");
    return value;
}

void setFloatProperty(handle_t target, const std::string &pname, double value)
{
    int ret = simSetFloatProperty(target, pname.c_str(), value);
    if(ret == -1)
        throw api_error("simSetFloatProperty");
}

double getFloatProperty(handle_t target, const std::string &pname)
{
    double value = 0;
    int ret = simGetFloatProperty(target, pname.c_str(), &value);
    if(ret == -1)
        throw api_error("simGetFloatProperty");
    return value;
}

void setStringProperty(handle_t target, const std::string &pname, const std::string &value)
{
    int ret = simSetStringProperty(target, pname.c_str(), value.c_str());
    if(ret == -1)
        throw api_error("simSetStringProperty");
}

std::string getStringProperty(handle_t target, const std::string &pname)
{
    char *value = simGetStringProperty(target, pname.c_str());
    if(!value)
        throw api_error("simGetStringProperty");
    std::string s(value);
    sim::releaseBuffer(value);
    return s;
}

void setBufferProperty(handle_t target, const std::string &pname, const std::string &value)
{
    int ret = simSetBufferProperty(target, pname.c_str(), value.c_str(), value.size());
    if(ret == -1)
        throw api_error("simSetBufferProperty");
}

std::string getBufferProperty(handle_t target, const std::string &pname)
{
    int len = 0;
    char *value = simGetBufferProperty(target, pname.c_str(), &len);
    if(!value)
        throw api_error("simGetBufferProperty");
    std::string s(value, len);
    sim::releaseBuffer(value);
    return s;
}

void setVector3Property(handle_t target, const std::string &pname, std::array<double, 3> value)
{
    int ret = simSetVector3Property(target, pname.c_str(), value.data());
    if(ret == -1)
        throw api_error("simSetVector3Property");
}

std::array<double, 3> getVector3Property(handle_t target, const std::string &pname)
{
    std::array<double, 3> value;
    int ret = simGetVector3Property(target, pname.c_str(), value.data());
    if(ret == -1)
        throw api_error("simGetVector3Property");
    return value;
}

void setQuaternionProperty(handle_t target, const std::string &pname, std::array<double, 4> value)
{
    int ret = simSetQuaternionProperty(target, pname.c_str(), value.data());
    if(ret == -1)
        throw api_error("simSetQuaternionProperty");
}

std::array<double, 4> getQuaternionProperty(handle_t target, const std::string &pname)
{
    std::array<double, 4> value;
    int ret = simGetQuaternionProperty(target, pname.c_str(), value.data());
    if(ret == -1)
        throw api_error("simGetQuaternionProperty");
    return value;
}

void setPoseProperty(handle_t target, const std::string &pname, std::array<double, 7> value)
{
    int ret = simSetPoseProperty(target, pname.c_str(), value.data());
    if(ret == -1)
        throw api_error("simSetPoseProperty");
}

std::array<double, 7> getPoseProperty(handle_t target, const std::string &pname)
{
    std::array<double, 7> value;
    int ret = simGetPoseProperty(target, pname.c_str(), value.data());
    if(ret == -1)
        throw api_error("simGetPoseProperty");
    return value;
}

void setColorProperty(handle_t target, const std::string &pname, std::array<float, 3> value)
{
    int ret = simSetColorProperty(target, pname.c_str(), value.data());
    if(ret == -1)
        throw api_error("simSetColorProperty");
}

std::array<float, 3> getColorProperty(handle_t target, const std::string &pname)
{
    std::array<float, 3> value;
    int ret = simGetColorProperty(target, pname.c_str(), value.data());
    if(ret == -1)
        throw api_error("simGetColorProperty");
    return value;
}

void setFloatArrayProperty(handle_t target, const std::string &pname, const std::vector<double> &value)
{
    int ret = simSetFloatArrayProperty(target, pname.c_str(), value.data(), value.size());
    if(ret == -1)
        throw api_error("simSetFloatArrayProperty");
}

std::vector<double> getFloatArrayProperty(handle_t target, const std::string &pname)
{
    int len = 0;
    double *value = simGetFloatArrayProperty(target, pname.c_str(), &len);
    if(!value)
        throw api_error("simGetFloatArrayProperty");
    std::vector<double> v(value, value + len);
    sim::releaseBuffer(value);
    return v;
}

void setIntArrayProperty(handle_t target, const std::string &pname, const std::vector<int> &value)
{
    int ret = simSetIntArrayProperty(target, pname.c_str(), value.data(), value.size());
    if(ret == -1)
        throw api_error("simSetIntArrayProperty");
}

std::vector<int> getIntArrayProperty(handle_t target, const std::string &pname)
{
    int len = 0;
    int *value = simGetIntArrayProperty(target, pname.c_str(), &len);
    if(!value)
        throw api_error("simGetIntArrayProperty");
    std::vector<int> v(value, value + len);
    sim::releaseBuffer(value);
    return v;
}

#if 0
void setFloatArray2Property(handle_t target, const std::string &pname, const std::array<double, 2> &value)
{
    int ret = simSetFloatArray2Property(target, pname.c_str(), value.data());
    if(ret == -1)
        throw api_error("simSetFloatArray2Property");
}

std::array<double, 2> getFloatArray2Property(handle_t target, const std::string &pname)
{
    std::array<double, 2> v;
    int ret = simGetFloatArray2Property(target, pname.c_str(), v.data());
    if(ret == -1)
        throw api_error("simGetFloatArray2Property");
    return v;
}

void setFloatArray3Property(handle_t target, const std::string &pname, const std::array<double, 3> &value)
{
    int ret = simSetFloatArray3Property(target, pname.c_str(), value.data());
    if(ret == -1)
        throw api_error("simSetFloatArray3Property");
}

std::array<double, 3> getFloatArray3Property(handle_t target, const std::string &pname)
{
    std::array<double, 3> v;
    int ret = simGetFloatArray3Property(target, pname.c_str(), v.data());
    if(ret == -1)
        throw api_error("simGetFloatArray3Property");
    return v;
}
#endif

void setIntArray2Property(handle_t target, const std::string &pname, const std::array<int, 2> &value)
{
    int ret = simSetIntArray2Property(target, pname.c_str(), value.data());
    if(ret == -1)
        throw api_error("simSetIntArray2Property");
}

std::array<int, 2> getIntArray2Property(handle_t target, const std::string &pname)
{
    std::array<int, 2> v;
    int ret = simGetIntArray2Property(target, pname.c_str(), v.data());
    if(ret == -1)
        throw api_error("simGetIntArray2Property");
    return v;
}

void removeProperty(handle_t target, const std::string &pname)
{
    int ret = simRemoveProperty(target, pname.c_str());
    if(ret == -1)
        throw api_error("simRemoveProperty");
}

bool getPropertyName(handle_t target, int index, std::string &pname)
{
    return getPropertyName(target, index, pname, pname);
}

bool getPropertyName(handle_t target, int index, std::string &pname, SPropertyOptions &opts)
{
    return getPropertyName(target, index, pname, pname, opts);
}

bool getPropertyName(handle_t target, int index, std::string &pname, std::string &pclass)
{
    SPropertyOptions opts;
    return getPropertyName(target, index, pname, pclass, opts);
}

bool getPropertyName(handle_t target, int index, std::string &pname, std::string &pclass, SPropertyOptions &opts)
{
    char* ret = simGetPropertyName(target, index, &opts);
    if(!ret) return false;
    std::string nameAndClass = std::string(ret);
    sim::releaseBuffer(ret);

    size_t pos = nameAndClass.find(',');
    if(pos != std::string::npos)
    {
        pname = nameAndClass.substr(0, pos);
        if(&pname != &pclass)
            pclass = nameAndClass.substr(pos + 1);
    }
    else
    {
        pname = nameAndClass;
        if(&pname != &pclass)
            pclass = "";
    }

    return true;
}

bool getPropertyInfo(handle_t target, const std::string &pname, SPropertyInfo &info)
{
    SPropertyOptions opts;
    return getPropertyInfo(target, pname, info, opts);
}

bool getPropertyInfo(handle_t target, const std::string &pname, SPropertyInfo &info, SPropertyOptions &opts)
{
    int ret = simGetPropertyInfo(target, pname.c_str(), &info, &opts);
    if(ret == -1)
        throw api_error("simGetPropertyInfo");
    return ret > 0;
}

#ifdef HAVE_JSONCONS
void pushObjectOntoStack(handle_t stackHandle, const jsoncons::json &obj)
{
    sim::pushTableOntoStack(stackHandle);

    for(const auto& kv : obj.object_range())
    {
        const std::string& key = kv.key();
        const auto& val = kv.value();

        sim::pushStringOntoStack(stackHandle, key);
        sim::pushValueOntoStack(stackHandle, val);
        sim::insertDataIntoStackTable(stackHandle);
    }
}

void pushArrayOntoStack(handle_t stackHandle, const jsoncons::json& arr)
{
    sim::pushTableOntoStack(stackHandle);

    size_t index = 1;
    for(const auto& item : arr.array_range())
    {
        sim::pushInt32OntoStack(stackHandle, index++);
        sim::pushValueOntoStack(stackHandle, item);
        sim::insertDataIntoStackTable(stackHandle);
    }
}

void pushValueOntoStack(handle_t stackHandle, const jsoncons::json& value)
{
    if(value.is_object())
        sim::pushObjectOntoStack(stackHandle, value);
    else if(value.is_array())
        sim::pushArrayOntoStack(stackHandle, value);
    else if(value.is_string())
        sim::pushTextOntoStack(stackHandle, value.as<std::string>());
    else if(value.is_byte_string())
        sim::pushBufferOntoStack(stackHandle, value.as<std::vector<uint8_t>>());
    else if(value.is_bool())
        sim::pushBoolOntoStack(stackHandle, value.as<bool>());
    else if(value.is_int64())
        sim::pushInt64OntoStack(stackHandle, value.as<int64_t>());
    else if(value.is_uint64())
        sim::pushInt64OntoStack(stackHandle, static_cast<int64_t>(value.as<uint64_t>()));
    else if(value.is_double())
        sim::pushDoubleOntoStack(stackHandle, value.as<double>());
    else if(value.is_null())
        sim::pushNullOntoStack(stackHandle);
    else
        throw std::runtime_error("sim::pushValueOntoStack: unexpected value type: " + std::to_string(static_cast<uint8_t>(value.type())));
}

int getStackValue(handle_t stackHandle, jsoncons::json *value)
{
    int ret = -1;
    int t = sim::getStackItemType(stackHandle, -1);
    double doubleValue;
    bool boolValue;
    std::string stringValue;
    long long intValue;
    int info, oldSize, size, i, n;
    oldSize = sim::getStackSize(stackHandle);
    switch(t)
    {
    case sim_stackitem_null:
        *value = jsoncons::json::null();
        sim::popStackItem(stackHandle, 1);
        break;
    case sim_stackitem_double:
        ret = sim::getStackDoubleValue(stackHandle, &doubleValue);
        *value = jsoncons::json(doubleValue);
        sim::popStackItem(stackHandle, 1);
        break;
    case sim_stackitem_bool:
        ret = sim::getStackBoolValue(stackHandle, &boolValue);
        *value = jsoncons::json(boolValue);
        sim::popStackItem(stackHandle, 1);
        break;
    case sim_stackitem_string:
        ret = sim::getStackStringValue(stackHandle, &stringValue);
        *value = jsoncons::json(stringValue);
        sim::popStackItem(stackHandle, 1);
        break;
    case sim_stackitem_integer:
        ret = sim::getStackInt64Value(stackHandle, &intValue);
        *value = jsoncons::json(intValue);
        sim::popStackItem(stackHandle, 1);
        break;
    case sim_stackitem_table:
        info = sim::getStackTableInfo(stackHandle, 0);
        if(info == sim_stack_table_empty)
        {
            *value = jsoncons::json::array();
            sim::popStackItem(stackHandle, 1);
            break;
        }
        sim::unfoldStackTable(stackHandle);
        size = sim::getStackSize(stackHandle);
        n = (size - oldSize + 1) / 2;
        if(info == sim_stack_table_map)
        {
            *value = jsoncons::json::object();
            for(i = 0; i < n; i++)
            {
                sim::moveStackItemToTop(stackHandle, oldSize - 1);
                jsoncons::json key;
                sim::getStackValue(stackHandle, &key);
                if(!key.is_string())
                    throw std::runtime_error("sim::getStackValue: invalid table key type: " + std::to_string(static_cast<uint8_t>(key.type())));
                sim::moveStackItemToTop(stackHandle, oldSize - 1);
                jsoncons::json value_i;
                sim::getStackValue(stackHandle, &value_i);
                (*value)[key.as<std::string>()] = value_i;
            }
            ret = 1;
        }
        else if(info > 0)
        {
            *value = jsoncons::json::array();
            for(i = 0; i < n; i++)
            {
                sim::moveStackItemToTop(stackHandle, oldSize - 1);
                jsoncons::json key;
                sim::getStackValue(stackHandle, &key);
                sim::moveStackItemToTop(stackHandle, oldSize - 1);
                jsoncons::json value_i;
                sim::getStackValue(stackHandle, &value_i);
                value->push_back(value_i);
            }
            ret = 1;
        }
        else throw std::runtime_error("sim::getStackValue: unexpected table type: " + std::to_string(info));
        break;
    }
    return ret;
}
#endif

} // namespace sim
