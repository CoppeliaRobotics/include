#ifdef SIM_LIB_PREFIX
    static int simRunSimulator(const char* applicationName,int options,void(*setToNull1)(),void(*setToNull2)(),void(*setToNull3)()) { return SIM_API_SYMBOL(simRunSimulator)(applicationName,options,nullptr, nullptr, nullptr); }
    static int simRunSimulatorEx(const char* applicationName,int options,void(*setToNull1)(),void(*setToNull2)(),void(*setToNull3)(),int stopDelay,const char* sceneOrModelToLoad) { return SIM_API_SYMBOL(simRunSimulatorEx)(applicationName,options,nullptr ,nullptr , nullptr, int stopDelay,const char* sceneOrModelToLoad); }
    static int simExtLaunchUIThread(const char* applicationName,int options,const char* sceneOrModelOrUiToLoad,const char* applicationDir_) { return SIM_API_SYMBOL(simExtLaunchUIThread)(applicationName,options,sceneOrModelOrUiToLoad,applicationDir_); }
    static int simExtCanInitSimThread() { return SIM_API_SYMBOL(simExtCanInitSimThread)(); }
    static int simExtSimThreadInit() { return SIM_API_SYMBOL(simExtSimThreadInit)(); }
    static int simExtSimThreadDestroy() { return SIM_API_SYMBOL(simExtSimThreadDestroy)(); }
    static int simExtPostExitRequest() { return SIM_API_SYMBOL(simExtPostExitRequest)(); }
    static int simExtGetExitRequest() { return SIM_API_SYMBOL(simExtGetExitRequest)(); }
    static int simExtStep(bool stepIfRunning) { return SIM_API_SYMBOL(simExtStep)(stepIfRunning); }
    static int simExtCallScriptFunction(int scriptHandleOrType, const char* functionNameAtScriptName,const int* inIntData, int inIntCnt,const SIMDOUBLE* inFloatData, int inFloatCnt,const char** inStringData, int inStringCnt,const char* inBufferData, int inBufferCnt,int** outIntData, int* outIntCnt,SIMDOUBLE** outFloatData, int* outFloatCnt,char*** outStringData, int* outStringCnt,char** outBufferData, int* outBufferSize) { return SIM_API_SYMBOL(simExtCallScriptFunction)(scriptHandleOrType, const char* functionNameAtScriptName,const int* inIntData, int inIntCnt,const SIMDOUBLE* inFloatData, int inFloatCnt,const char** inStringData,inStringCnt,inBufferData,inBufferCnt,outIntData,outIntCnt,outFloatData,outFloatCnt,outStringData,outStringCnt,outBufferData,outBufferSize); }
    static int simAddModuleMenuEntry(const char* entryLabel,int itemCount,int* itemHandles) { return SIM_API_SYMBOL(simAddModuleMenuEntry)(entryLabel,itemCount,itemHandles); }
    static int simSetModuleMenuItemState(int itemHandle,int state,const char* label) { return SIM_API_SYMBOL(simSetModuleMenuItemState)(itemHandle,state,label); }
    static int simAddPointCloud(int pageMask,int layerMask,int objectHandle,int options,SIMDOUBLE pointSize,int ptCnt,const SIMDOUBLE* pointCoordinates,const char* defaultColors,const char* pointColors,const SIMDOUBLE* pointNormals) { return SIM_API_SYMBOL(simAddPointCloud)(pageMask,layerMask,objectHandle,options,pointSize,ptCnt,pointCoordinates,defaultColors,pointColors,pointNormals); }
    static int simModifyPointCloud(int pointCloudHandle,int operation,const int* intParam,const SIMDOUBLE* floatParam) { return SIM_API_SYMBOL(simModifyPointCloud)(pointCloudHandle,operation,intParam,floatParam); }
    static void _simGetJointOdeParameters(const void* joint,SIMDOUBLE* stopERP,SIMDOUBLE* stopCFM,SIMDOUBLE* bounce,SIMDOUBLE* fudge,SIMDOUBLE* normalCFM) { return SIM_API_SYMBOL(_simGetJointOdeParameters)(joint,stopERP,stopCFM,bounce,fudge,normalCFM); }
    static void _simGetJointBulletParameters(const void* joint,SIMDOUBLE* stopERP,SIMDOUBLE* stopCFM,SIMDOUBLE* normalCFM) { return SIM_API_SYMBOL(_simGetJointBulletParameters)(joint,stopERP,stopCFM,normalCFM); }
    static void _simGetOdeMaxContactFrictionCFMandERP(const void* geomInfo,int* maxContacts,SIMDOUBLE* friction,SIMDOUBLE* cfm,SIMDOUBLE* erp) { return SIM_API_SYMBOL(_simGetOdeMaxContactFrictionCFMandERP)(geomInfo,maxContacts,friction,cfm,erp); }
    static bool _simGetBulletCollisionMargin(const void* geomInfo,SIMDOUBLE* margin,int* otherProp) { return SIM_API_SYMBOL(_simGetBulletCollisionMargin)(geomInfo,margin,otherProp); }
    static SIMDOUBLE _simGetBulletRestitution(const void* geomInfo) { return SIM_API_SYMBOL(_simGetBulletRestitution)(geomInfo); }
    static void _simGetVortexParameters(const void* object,int version,SIMDOUBLE* floatParams,int* intParams) { return SIM_API_SYMBOL(_simGetVortexParameters)(object,version,floatParams,intParams); }
    static void _simGetNewtonParameters(const void* object,int* version,SIMDOUBLE* floatParams,int* intParams) { return SIM_API_SYMBOL(_simGetNewtonParameters)(object,version,floatParams,intParams); }
    static void _simGetDamping(const void* geomInfo,SIMDOUBLE* linDamping,SIMDOUBLE* angDamping) { return SIM_API_SYMBOL(_simGetDamping)(geomInfo,linDamping,angDamping); }
    static SIMDOUBLE _simGetFriction(const void* geomInfo) { return SIM_API_SYMBOL(_simGetFriction)(geomInfo); }
    static bool _simGetBulletStickyContact(const void* geomInfo) { return SIM_API_SYMBOL(_simGetBulletStickyContact)(geomInfo); }
    static int simCallScriptFunction(int scriptHandleOrType,const char* functionNameAtScriptName,SLuaCallBack* data,const char* reservedSetToNull) { return SIM_API_SYMBOL(simCallScriptFunction)(scriptHandleOrType,functionNameAtScriptName,data,reservedSetToNull); }
    static int simGetJointMatrix(int objectHandle,SIMDOUBLE* matrix) { return SIM_API_SYMBOL(simGetJointMatrix)(objectHandle,matrix); }
    static int simSetSphericalJointMatrix(int objectHandle,const SIMDOUBLE* matrix) { return SIM_API_SYMBOL(simSetSphericalJointMatrix)(objectHandle,matrix); }
    static const void* _simGetGeomProxyFromShape(const void* shape) { return SIM_API_SYMBOL(_simGetGeomProxyFromShape)(shape); }
    static int simReorientShapeBoundingBox(int shapeHandle,int relativeToHandle,int reservedSetToZero) { return SIM_API_SYMBOL(simReorientShapeBoundingBox)(shapeHandle,relativeToHandle,reservedSetToZero); }
    static int simIsDeprecated(const char* funcOrConst) { return SIM_API_SYMBOL(simIsDeprecated)(funcOrConst); }
    static int simLoadModule(const char* filenameAndPath,const char* pluginName) { return SIM_API_SYMBOL(simLoadModule)(filenameAndPath,pluginName); }
    static int simUnloadModule(int pluginhandle) { return SIM_API_SYMBOL(simUnloadModule)(pluginhandle); }
    static int simSetModuleInfo(const char* moduleName,int infoType,const char* stringInfo,int intInfo) { return SIM_API_SYMBOL(simSetModuleInfo)(moduleName,infoType,stringInfo,intInfo); }
    static int simGetModuleInfo(const char* moduleName,int infoType,char** stringInfo,int* intInfo) { return SIM_API_SYMBOL(simGetModuleInfo)(moduleName,infoType,stringInfo,intInfo); }
    static char* simGetModuleName(int index,unsigned char* moduleVersion) { return SIM_API_SYMBOL(simGetModuleName)(index,moduleVersion); }
    static int simIsStackValueNull(int stackHandle) { return SIM_API_SYMBOL(simIsStackValueNull)(stackHandle); }
    static int simIsRealTimeSimulationStepNeeded() { return SIM_API_SYMBOL(simIsRealTimeSimulationStepNeeded)(); }
    static int simAdjustRealTimeTimer(int instanceIndex,SIMDOUBLE deltaTime) { return SIM_API_SYMBOL(simAdjustRealTimeTimer)(instanceIndex,deltaTime); }
    static int simSetSimulationPassesPerRenderingPass(int p) { return SIM_API_SYMBOL(simSetSimulationPassesPerRenderingPass)(p); }
    static int simGetSimulationPassesPerRenderingPass() { return SIM_API_SYMBOL(simGetSimulationPassesPerRenderingPass)(); }
    static int simAdvanceSimulationByOneStep() { return SIM_API_SYMBOL(simAdvanceSimulationByOneStep)(); }
    static int simHandleMainScript() { return SIM_API_SYMBOL(simHandleMainScript)(); }
    static int simGetScriptInt32Param(int scriptHandle,int parameterID,int* parameter) { return SIM_API_SYMBOL(simGetScriptInt32Param)(scriptHandle,parameterID,parameter); }
    static int simSetScriptInt32Param(int scriptHandle,int parameterID,int parameter) { return SIM_API_SYMBOL(simSetScriptInt32Param)(scriptHandle,parameterID,parameter); }
    static char* simGetScriptStringParam(int scriptHandle,int parameterID,int* parameterLength) { return SIM_API_SYMBOL(simGetScriptStringParam)(scriptHandle,parameterID,parameterLength); }
    static int simSetScriptStringParam(int scriptHandle,int parameterID,const char* parameter,int parameterLength) { return SIM_API_SYMBOL(simSetScriptStringParam)(scriptHandle,parameterID,parameter,parameterLength); }
    static int simAddScript(int scriptProperty) { return SIM_API_SYMBOL(simAddScript)(scriptProperty); }
    static int simRemoveScript(int scriptHandle) { return SIM_API_SYMBOL(simRemoveScript)(scriptHandle); }
    static int simAssociateScriptWithObject(int scriptHandle,int associatedObjectHandle) { return SIM_API_SYMBOL(simAssociateScriptWithObject)(scriptHandle,associatedObjectHandle); }
    static int simPersistentDataWrite(const char* dataName,const char* dataValue,int dataLength,int options) { return SIM_API_SYMBOL(simPersistentDataWrite)(dataName,dataValue,dataLength,options); }
    static char* simPersistentDataRead(const char* dataName,int* dataLength) { return SIM_API_SYMBOL(simPersistentDataRead)(dataName,dataLength); }
    static char* simGetPersistentDataTags(int* tagCount) { return SIM_API_SYMBOL(simGetPersistentDataTags)(tagCount); }
    static int simSetBoolParam(int Param,bool boolState) { return SIM_API_SYMBOL(simSetBoolParam)(Param,boolState); }
    static int simGetBoolParam(int Param) { return SIM_API_SYMBOL(simGetBoolParam)(Param); }
    static int simSetInt32Param(int Param,int intState) { return SIM_API_SYMBOL(simSetInt32Param)(Param,intState); }
    static int simGetInt32Param(int Param,int* intState) { return SIM_API_SYMBOL(simGetInt32Param)(Param,intState); }
    static int simGetUInt64Param(int Param,unsigned long long int* intState) { return SIM_API_SYMBOL(simGetUInt64Param)(Param,intState); }
    static int simSetStringParam(int Param,const char* stringState) { return SIM_API_SYMBOL(simSetStringParam)(Param,stringState); }
    static char* simGetStringParam(int Param) { return SIM_API_SYMBOL(simGetStringParam)(Param); }
    static int simSetNamedStringParam(const char* paramName,const char* stringParam,int paramLength) { return SIM_API_SYMBOL(simSetNamedStringParam)(paramName,stringParam,paramLength); }
    static char* simGetNamedStringParam(const char* paramName,int* paramLength) { return SIM_API_SYMBOL(simGetNamedStringParam)(paramName,paramLength); }
    static int simSetInt32Signal(const char* signalName,int signalValue) { return SIM_API_SYMBOL(simSetInt32Signal)(signalName,signalValue); }
    static int simGetInt32Signal(const char* signalName,int* signalValue) { return SIM_API_SYMBOL(simGetInt32Signal)(signalName,signalValue); }
    static int simClearInt32Signal(const char* signalName) { return SIM_API_SYMBOL(simClearInt32Signal)(signalName); }
    static int simClearFloatSignal(const char* signalName) { return SIM_API_SYMBOL(simClearFloatSignal)(signalName); }
    static int simSetStringSignal(const char* signalName,const char* signalValue,int stringLength) { return SIM_API_SYMBOL(simSetStringSignal)(signalName,signalValue,stringLength); }
    static char* simGetStringSignal(const char* signalName,int* stringLength) { return SIM_API_SYMBOL(simGetStringSignal)(signalName,stringLength); }
    static int simClearStringSignal(const char* signalName) { return SIM_API_SYMBOL(simClearStringSignal)(signalName); }
    static char* simGetSignalName(int signalIndex,int signalType) { return SIM_API_SYMBOL(simGetSignalName)(signalIndex,signalType); }
    static int simGetObjectInt32Param(int objectHandle,int parameterID,int* parameter) { return SIM_API_SYMBOL(simGetObjectInt32Param)(objectHandle,parameterID,parameter); }
    static int simSetObjectInt32Param(int objectHandle,int parameterID,int parameter) { return SIM_API_SYMBOL(simSetObjectInt32Param)(objectHandle,parameterID,parameter); }
    static char* simGetObjectStringParam(int objectHandle,int parameterID,int* parameterLength) { return SIM_API_SYMBOL(simGetObjectStringParam)(objectHandle,parameterID,parameterLength); }
    static int simSetObjectStringParam(int objectHandle,int parameterID,const char* parameter,int parameterLength) { return SIM_API_SYMBOL(simSetObjectStringParam)(objectHandle,parameterID,parameter,parameterLength); }
    static int simWriteCustomDataBlock(int objectHandle,const char* tagName,const char* data,int dataSize) { return SIM_API_SYMBOL(simWriteCustomDataBlock)(objectHandle,tagName,data,dataSize); }
    static char* simReadCustomDataBlock(int objectHandle,const char* tagName,int* dataSize) { return SIM_API_SYMBOL(simReadCustomDataBlock)(objectHandle,tagName,dataSize); }
    static char* simReadCustomDataBlockTags(int objectHandle,int* tagCount) { return SIM_API_SYMBOL(simReadCustomDataBlockTags)(objectHandle,tagCount); }
    static int simGetEngineInt32Param(int paramId,int objectHandle,const void* object,bool* ok) { return SIM_API_SYMBOL(simGetEngineInt32Param)(paramId,objectHandle,object,ok); }
    static bool simGetEngineBoolParam(int paramId,int objectHandle,const void* object,bool* ok) { return SIM_API_SYMBOL(simGetEngineBoolParam)(paramId,objectHandle,object,ok); }
    static int simSetEngineInt32Param(int paramId,int objectHandle,const void* object,int val) { return SIM_API_SYMBOL(simSetEngineInt32Param)(paramId,objectHandle,object,val); }
    static int simSetEngineBoolParam(int paramId,int objectHandle,const void* object,bool val) { return SIM_API_SYMBOL(simSetEngineBoolParam)(paramId,objectHandle,object,val); }
    static int simSetArrayParam(int Param,const SIMDOUBLE* arrayOfValues) { return SIM_API_SYMBOL(simSetArrayParam)(Param,arrayOfValues); }
    static int simGetArrayParam(int Param,SIMDOUBLE* arrayOfValues) { return SIM_API_SYMBOL(simGetArrayParam)(Param,arrayOfValues); }
    static int simSetFloatSignal(const char* signalName,SIMDOUBLE signalValue) { return SIM_API_SYMBOL(simSetFloatSignal)(signalName,signalValue); }
    static int simGetFloatSignal(const char* signalName,SIMDOUBLE* signalValue) { return SIM_API_SYMBOL(simGetFloatSignal)(signalName,signalValue); }
    static int simSetFloatParam(int Param,SIMDOUBLE floatState) { return SIM_API_SYMBOL(simSetFloatParam)(Param,floatState); }
    static int simGetFloatParam(int Param,SIMDOUBLE* floatState) { return SIM_API_SYMBOL(simGetFloatParam)(Param,floatState); }
    static int simGetObjectFloatParam(int objectHandle,int parameterID,SIMDOUBLE* parameter) { return SIM_API_SYMBOL(simGetObjectFloatParam)(objectHandle,parameterID,parameter); }
    static int simSetObjectFloatParam(int objectHandle,int parameterID,SIMDOUBLE parameter) { return SIM_API_SYMBOL(simSetObjectFloatParam)(objectHandle,parameterID,parameter); }
    static SIMDOUBLE* simGetObjectFloatArrayParam(int objectHandle,int parameterID,int* size) { return SIM_API_SYMBOL(simGetObjectFloatArrayParam)(objectHandle,parameterID,size); }
    static int simSetObjectFloatArrayParam(int objectHandle,int parameterID,const SIMDOUBLE* params,int size) { return SIM_API_SYMBOL(simSetObjectFloatArrayParam)(objectHandle,parameterID,params,size); }
    static SIMDOUBLE simGetEngineFloatParam(int paramId,int objectHandle,const void* object,bool* ok) { return SIM_API_SYMBOL(simGetEngineFloatParam)(paramId,objectHandle,object,ok); }
    static int simSetEngineFloatParam(int paramId,int objectHandle,const void* object,SIMDOUBLE val) { return SIM_API_SYMBOL(simSetEngineFloatParam)(paramId,objectHandle,object,val); }
    static int simSetLightParameters(int objectHandle,int state,const float* setToNULL,const float* diffusePart,const float* specularPart) { return SIM_API_SYMBOL(simSetLightParameters)(objectHandle,state,setToNULL,diffusePart,specularPart); }
    static int simGetLightParameters(int objectHandle,SIMDOUBLE* setToNULL,SIMDOUBLE* diffusePart,SIMDOUBLE* specularPart) { return SIM_API_SYMBOL(simGetLightParameters)(objectHandle,setToNULL,diffusePart,specularPart); }
    static int simSetModelProperty(int objectHandle,int modelProperty) { return SIM_API_SYMBOL(simSetModelProperty)(objectHandle,modelProperty); }
    static int simGetModelProperty(int objectHandle) { return SIM_API_SYMBOL(simGetModelProperty)(objectHandle); }
    static int simSetObjectProperty(int objectHandle,int prop) { return SIM_API_SYMBOL(simSetObjectProperty)(objectHandle,prop); }
    static int simGetObjectProperty(int objectHandle) { return SIM_API_SYMBOL(simGetObjectProperty)(objectHandle); }
    static int simSetObjectSpecialProperty(int objectHandle,int prop) { return SIM_API_SYMBOL(simSetObjectSpecialProperty)(objectHandle,prop); }
    static int simGetObjectSpecialProperty(int objectHandle) { return SIM_API_SYMBOL(simGetObjectSpecialProperty)(objectHandle); }
#endif

typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRunSimulator))(const char* applicationName,int options,void(*setToNull1)(),void(*setToNull2)(),void(*setToNull3)());
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRunSimulatorEx))(const char* applicationName,int options,void(*setToNull1)(),void(*setToNull2)(),void(*setToNull3)(),int stopDelay,const char* sceneOrModelToLoad);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimExtLaunchUIThread))(const char* applicationName,int options,const char* sceneOrModelOrUiToLoad,const char* applicationDir_);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimExtCanInitSimThread))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimExtSimThreadInit))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimExtSimThreadDestroy))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimExtPostExitRequest))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimExtGetExitRequest))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimExtStep))(bool stepIfRunning);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimExtCallScriptFunction))(int scriptHandleOrType, const char* functionNameAtScriptName,const int* inIntData, int inIntCnt,const SIMDOUBLE* inFloatData, int inFloatCnt,const char** inStringData, int inStringCnt,const char* inBufferData, int inBufferCnt,int** outIntData, int* outIntCnt,SIMDOUBLE** outFloatData, int* outFloatCnt,char*** outStringData, int* outStringCnt,char** outBufferData, int* outBufferSize);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddModuleMenuEntry))(const char* entryLabel,int itemCount,int* itemHandles);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetModuleMenuItemState))(int itemHandle,int state,const char* label);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddPointCloud))(int pageMask,int layerMask,int objectHandle,int options,SIMDOUBLE pointSize,int ptCnt,const SIMDOUBLE* pointCoordinates,const char* defaultColors,const char* pointColors,const SIMDOUBLE* pointNormals);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimModifyPointCloud))(int pointCloudHandle,int operation,const int* intParam,const SIMDOUBLE* floatParam);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetJointOdeParameters))(const void* joint,SIMDOUBLE* stopERP,SIMDOUBLE* stopCFM,SIMDOUBLE* bounce,SIMDOUBLE* fudge,SIMDOUBLE* normalCFM);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetJointBulletParameters))(const void* joint,SIMDOUBLE* stopERP,SIMDOUBLE* stopCFM,SIMDOUBLE* normalCFM);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetOdeMaxContactFrictionCFMandERP))(const void* geomInfo,int* maxContacts,SIMDOUBLE* friction,SIMDOUBLE* cfm,SIMDOUBLE* erp);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simGetBulletCollisionMargin))(const void* geomInfo,SIMDOUBLE* margin,int* otherProp);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptr_simGetBulletRestitution))(const void* geomInfo);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetVortexParameters))(const void* object,int version,SIMDOUBLE* floatParams,int* intParams);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetNewtonParameters))(const void* object,int* version,SIMDOUBLE* floatParams,int* intParams);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetDamping))(const void* geomInfo,SIMDOUBLE* linDamping,SIMDOUBLE* angDamping);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptr_simGetFriction))(const void* geomInfo);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simGetBulletStickyContact))(const void* geomInfo);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCallScriptFunction))(int scriptHandleOrType,const char* functionNameAtScriptName,SLuaCallBack* data,const char* reservedSetToNull);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetJointMatrix))(int objectHandle,SIMDOUBLE* matrix);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetSphericalJointMatrix))(int objectHandle,const SIMDOUBLE* matrix);
typedef const void* (__cdecl *SIM_API_SYMBOL(ptr_simGetGeomProxyFromShape))(const void* shape);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimReorientShapeBoundingBox))(int shapeHandle,int relativeToHandle,int reservedSetToZero);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimIsDeprecated))(const char* funcOrConst);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimLoadModule))(const char* filenameAndPath,const char* pluginName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimUnloadModule))(int pluginhandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetModuleInfo))(const char* moduleName,int infoType,const char* stringInfo,int intInfo);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetModuleInfo))(const char* moduleName,int infoType,char** stringInfo,int* intInfo);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetModuleName))(int index,unsigned char* moduleVersion);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimIsStackValueNull))(int stackHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimIsRealTimeSimulationStepNeeded))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAdjustRealTimeTimer))(int instanceIndex,SIMDOUBLE deltaTime);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetSimulationPassesPerRenderingPass))(int p);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetSimulationPassesPerRenderingPass))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAdvanceSimulationByOneStep))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleMainScript))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetScriptInt32Param))(int scriptHandle,int parameterID,int* parameter);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetScriptInt32Param))(int scriptHandle,int parameterID,int parameter);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetScriptStringParam))(int scriptHandle,int parameterID,int* parameterLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetScriptStringParam))(int scriptHandle,int parameterID,const char* parameter,int parameterLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddScript))(int scriptProperty);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveScript))(int scriptHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAssociateScriptWithObject))(int scriptHandle,int associatedObjectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPersistentDataWrite))(const char* dataName,const char* dataValue,int dataLength,int options);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimPersistentDataRead))(const char* dataName,int* dataLength);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetPersistentDataTags))(int* tagCount);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetBoolParam))(int Param,bool boolState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetBoolParam))(int Param);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetInt32Param))(int Param,int intState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetInt32Param))(int Param,int* intState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetUInt64Param))(int Param,unsigned long long int* intState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetStringParam))(int Param,const char* stringState);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetStringParam))(int Param);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetNamedStringParam))(const char* paramName,const char* stringParam,int paramLength);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetNamedStringParam))(const char* paramName,int* paramLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetInt32Signal))(const char* signalName,int signalValue);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetInt32Signal))(const char* signalName,int* signalValue);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimClearInt32Signal))(const char* signalName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimClearFloatSignal))(const char* signalName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetStringSignal))(const char* signalName,const char* signalValue,int stringLength);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetStringSignal))(const char* signalName,int* stringLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimClearStringSignal))(const char* signalName);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetSignalName))(int signalIndex,int signalType);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectInt32Param))(int objectHandle,int parameterID,int* parameter);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectInt32Param))(int objectHandle,int parameterID,int parameter);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectStringParam))(int objectHandle,int parameterID,int* parameterLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectStringParam))(int objectHandle,int parameterID,const char* parameter,int parameterLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimWriteCustomDataBlock))(int objectHandle,const char* tagName,const char* data,int dataSize);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimReadCustomDataBlock))(int objectHandle,const char* tagName,int* dataSize);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimReadCustomDataBlockTags))(int objectHandle,int* tagCount);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetEngineInt32Param))(int paramId,int objectHandle,const void* object,bool* ok);
typedef bool (__cdecl *SIM_API_SYMBOL(ptrSimGetEngineBoolParam))(int paramId,int objectHandle,const void* object,bool* ok);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetEngineInt32Param))(int paramId,int objectHandle,const void* object,int val);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetEngineBoolParam))(int paramId,int objectHandle,const void* object,bool val);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetArrayParam))(int Param,const SIMDOUBLE* arrayOfValues);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetArrayParam))(int Param,SIMDOUBLE* arrayOfValues);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetFloatSignal))(const char* signalName,SIMDOUBLE signalValue);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetFloatSignal))(const char* signalName,SIMDOUBLE* signalValue);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetFloatParam))(int Param,SIMDOUBLE floatState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetFloatParam))(int Param,SIMDOUBLE* floatState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectFloatParam))(int objectHandle,int parameterID,SIMDOUBLE* parameter);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectFloatParam))(int objectHandle,int parameterID,SIMDOUBLE parameter);
typedef SIMDOUBLE* (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectFloatArrayParam))(int objectHandle,int parameterID,int* size);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectFloatArrayParam))(int objectHandle,int parameterID,const SIMDOUBLE* params,int size);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptrSimGetEngineFloatParam))(int paramId,int objectHandle,const void* object,bool* ok);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetEngineFloatParam))(int paramId,int objectHandle,const void* object,SIMDOUBLE val);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetLightParameters))(int objectHandle,int state,const float* setToNULL,const float* diffusePart,const float* specularPart);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetLightParameters))(int objectHandle,SIMDOUBLE* setToNULL,SIMDOUBLE* diffusePart,SIMDOUBLE* specularPart);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetModelProperty))(int objectHandle,int modelProperty);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetModelProperty))(int objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectProperty))(int objectHandle,int prop);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectProperty))(int objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectSpecialProperty))(int objectHandle,int prop);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectSpecialProperty))(int objectHandle);

extern SIM_API_SYMBOL(ptrSimRunSimulator) SIM_API_SYMBOL(simRunSimulator);
extern SIM_API_SYMBOL(ptrSimRunSimulatorEx) SIM_API_SYMBOL(simRunSimulatorEx);
extern SIM_API_SYMBOL(ptrSimExtLaunchUIThread) SIM_API_SYMBOL(simExtLaunchUIThread);
extern SIM_API_SYMBOL(ptrSimExtCanInitSimThread) SIM_API_SYMBOL(simExtCanInitSimThread);
extern SIM_API_SYMBOL(ptrSimExtSimThreadInit) SIM_API_SYMBOL(simExtSimThreadInit);
extern SIM_API_SYMBOL(ptrSimExtSimThreadDestroy) SIM_API_SYMBOL(simExtSimThreadDestroy);
extern SIM_API_SYMBOL(ptrSimExtPostExitRequest) SIM_API_SYMBOL(simExtPostExitRequest);
extern SIM_API_SYMBOL(ptrSimExtGetExitRequest) SIM_API_SYMBOL(simExtGetExitRequest);
extern SIM_API_SYMBOL(ptrSimExtStep) SIM_API_SYMBOL(simExtStep);
extern SIM_API_SYMBOL(ptrSimExtCallScriptFunction) SIM_API_SYMBOL(simExtCallScriptFunction);
extern SIM_API_SYMBOL(ptrSimAddModuleMenuEntry) SIM_API_SYMBOL(simAddModuleMenuEntry);
extern SIM_API_SYMBOL(ptrSimSetModuleMenuItemState) SIM_API_SYMBOL(simSetModuleMenuItemState);
extern SIM_API_SYMBOL(ptrSimAddPointCloud) SIM_API_SYMBOL(simAddPointCloud);
extern SIM_API_SYMBOL(ptrSimModifyPointCloud) SIM_API_SYMBOL(simModifyPointCloud);
extern SIM_API_SYMBOL(ptr_simGetJointOdeParameters) SIM_API_SYMBOL(_simGetJointOdeParameters);
extern SIM_API_SYMBOL(ptr_simGetJointBulletParameters) SIM_API_SYMBOL(_simGetJointBulletParameters);
extern SIM_API_SYMBOL(ptr_simGetOdeMaxContactFrictionCFMandERP) SIM_API_SYMBOL(_simGetOdeMaxContactFrictionCFMandERP);
extern SIM_API_SYMBOL(ptr_simGetBulletCollisionMargin) SIM_API_SYMBOL(_simGetBulletCollisionMargin);
extern SIM_API_SYMBOL(ptr_simGetBulletStickyContact) SIM_API_SYMBOL(_simGetBulletStickyContact);
extern SIM_API_SYMBOL(ptr_simGetBulletRestitution) SIM_API_SYMBOL(_simGetBulletRestitution);
extern SIM_API_SYMBOL(ptr_simGetVortexParameters) SIM_API_SYMBOL(_simGetVortexParameters);
extern SIM_API_SYMBOL(ptr_simGetNewtonParameters) SIM_API_SYMBOL(_simGetNewtonParameters);
extern SIM_API_SYMBOL(ptr_simGetDamping) SIM_API_SYMBOL(_simGetDamping);
extern SIM_API_SYMBOL(ptr_simGetFriction) SIM_API_SYMBOL(_simGetFriction);
extern SIM_API_SYMBOL(ptrSimCallScriptFunction) SIM_API_SYMBOL(simCallScriptFunction);
extern SIM_API_SYMBOL(ptrSimGetJointMatrix) SIM_API_SYMBOL(simGetJointMatrix);
extern SIM_API_SYMBOL(ptrSimSetSphericalJointMatrix) SIM_API_SYMBOL(simSetSphericalJointMatrix);
extern SIM_API_SYMBOL(ptr_simGetGeomProxyFromShape) SIM_API_SYMBOL(_simGetGeomProxyFromShape);
extern SIM_API_SYMBOL(ptrSimReorientShapeBoundingBox) SIM_API_SYMBOL(simReorientShapeBoundingBox);
extern SIM_API_SYMBOL(ptrSimIsDeprecated) SIM_API_SYMBOL(simIsDeprecated);
extern SIM_API_SYMBOL(ptrSimLoadModule) SIM_API_SYMBOL(simLoadModule);
extern SIM_API_SYMBOL(ptrSimUnloadModule) SIM_API_SYMBOL(simUnloadModule);
extern SIM_API_SYMBOL(ptrSimGetModuleName) SIM_API_SYMBOL(simGetModuleName);
extern SIM_API_SYMBOL(ptrSimSetModuleInfo) SIM_API_SYMBOL(simSetModuleInfo);
extern SIM_API_SYMBOL(ptrSimGetModuleInfo) SIM_API_SYMBOL(simGetModuleInfo);
extern SIM_API_SYMBOL(ptrSimIsStackValueNull) SIM_API_SYMBOL(simIsStackValueNull);
extern SIM_API_SYMBOL(ptrSimIsRealTimeSimulationStepNeeded) SIM_API_SYMBOL(simIsRealTimeSimulationStepNeeded);
extern SIM_API_SYMBOL(ptrSimAdjustRealTimeTimer) SIM_API_SYMBOL(simAdjustRealTimeTimer);
extern SIM_API_SYMBOL(ptrSimSetSimulationPassesPerRenderingPass) SIM_API_SYMBOL(simSetSimulationPassesPerRenderingPass);
extern SIM_API_SYMBOL(ptrSimGetSimulationPassesPerRenderingPass) SIM_API_SYMBOL(simGetSimulationPassesPerRenderingPass);
extern SIM_API_SYMBOL(ptrSimAdvanceSimulationByOneStep) SIM_API_SYMBOL(simAdvanceSimulationByOneStep);
extern SIM_API_SYMBOL(ptrSimHandleMainScript) SIM_API_SYMBOL(simHandleMainScript);
extern SIM_API_SYMBOL(ptrSimGetScriptInt32Param) SIM_API_SYMBOL(simGetScriptInt32Param);
extern SIM_API_SYMBOL(ptrSimSetScriptInt32Param) SIM_API_SYMBOL(simSetScriptInt32Param);
extern SIM_API_SYMBOL(ptrSimGetScriptStringParam) SIM_API_SYMBOL(simGetScriptStringParam);
extern SIM_API_SYMBOL(ptrSimSetScriptStringParam) SIM_API_SYMBOL(simSetScriptStringParam);
extern SIM_API_SYMBOL(ptrSimAddScript) SIM_API_SYMBOL(simAddScript);
extern SIM_API_SYMBOL(ptrSimRemoveScript) SIM_API_SYMBOL(simRemoveScript);
extern SIM_API_SYMBOL(ptrSimAssociateScriptWithObject) SIM_API_SYMBOL(simAssociateScriptWithObject);
extern SIM_API_SYMBOL(ptrSimPersistentDataWrite) SIM_API_SYMBOL(simPersistentDataWrite);
extern SIM_API_SYMBOL(ptrSimPersistentDataRead) SIM_API_SYMBOL(simPersistentDataRead);
extern SIM_API_SYMBOL(ptrSimGetPersistentDataTags) SIM_API_SYMBOL(simGetPersistentDataTags);
extern SIM_API_SYMBOL(ptrSimSetBoolParam) SIM_API_SYMBOL(simSetBoolParam);
extern SIM_API_SYMBOL(ptrSimGetBoolParam) SIM_API_SYMBOL(simGetBoolParam);
extern SIM_API_SYMBOL(ptrSimSetInt32Param) SIM_API_SYMBOL(simSetInt32Param);
extern SIM_API_SYMBOL(ptrSimGetInt32Param) SIM_API_SYMBOL(simGetInt32Param);
extern SIM_API_SYMBOL(ptrSimGetUInt64Param) SIM_API_SYMBOL(simGetUInt64Param);
extern SIM_API_SYMBOL(ptrSimSetFloatParam) SIM_API_SYMBOL(simSetFloatParam);
extern SIM_API_SYMBOL(ptrSimGetFloatParam) SIM_API_SYMBOL(simGetFloatParam);
extern SIM_API_SYMBOL(ptrSimSetStringParam) SIM_API_SYMBOL(simSetStringParam);
extern SIM_API_SYMBOL(ptrSimGetStringParam) SIM_API_SYMBOL(simGetStringParam);
extern SIM_API_SYMBOL(ptrSimSetArrayParam) SIM_API_SYMBOL(simSetArrayParam);
extern SIM_API_SYMBOL(ptrSimGetArrayParam) SIM_API_SYMBOL(simGetArrayParam);
extern SIM_API_SYMBOL(ptrSimSetNamedStringParam) SIM_API_SYMBOL(simSetNamedStringParam);
extern SIM_API_SYMBOL(ptrSimGetNamedStringParam) SIM_API_SYMBOL(simGetNamedStringParam);
extern SIM_API_SYMBOL(ptrSimSetInt32Signal) SIM_API_SYMBOL(simSetInt32Signal);
extern SIM_API_SYMBOL(ptrSimGetInt32Signal) SIM_API_SYMBOL(simGetInt32Signal);
extern SIM_API_SYMBOL(ptrSimClearInt32Signal) SIM_API_SYMBOL(simClearInt32Signal);
extern SIM_API_SYMBOL(ptrSimSetFloatSignal) SIM_API_SYMBOL(simSetFloatSignal);
extern SIM_API_SYMBOL(ptrSimGetFloatSignal) SIM_API_SYMBOL(simGetFloatSignal);
extern SIM_API_SYMBOL(ptrSimClearFloatSignal) SIM_API_SYMBOL(simClearFloatSignal);
extern SIM_API_SYMBOL(ptrSimSetStringSignal) SIM_API_SYMBOL(simSetStringSignal);
extern SIM_API_SYMBOL(ptrSimGetStringSignal) SIM_API_SYMBOL(simGetStringSignal);
extern SIM_API_SYMBOL(ptrSimClearStringSignal) SIM_API_SYMBOL(simClearStringSignal);
extern SIM_API_SYMBOL(ptrSimGetSignalName) SIM_API_SYMBOL(simGetSignalName);
extern SIM_API_SYMBOL(ptrSimSetLightParameters) SIM_API_SYMBOL(simSetLightParameters);
extern SIM_API_SYMBOL(ptrSimGetLightParameters) SIM_API_SYMBOL(simGetLightParameters);
extern SIM_API_SYMBOL(ptrSimGetObjectInt32Param) SIM_API_SYMBOL(simGetObjectInt32Param);
extern SIM_API_SYMBOL(ptrSimSetObjectInt32Param) SIM_API_SYMBOL(simSetObjectInt32Param);
extern SIM_API_SYMBOL(ptrSimGetObjectFloatParam) SIM_API_SYMBOL(simGetObjectFloatParam);
extern SIM_API_SYMBOL(ptrSimSetObjectFloatParam) SIM_API_SYMBOL(simSetObjectFloatParam);
extern SIM_API_SYMBOL(ptrSimGetObjectFloatArrayParam) SIM_API_SYMBOL(simGetObjectFloatArrayParam);
extern SIM_API_SYMBOL(ptrSimSetObjectFloatArrayParam) SIM_API_SYMBOL(simSetObjectFloatArrayParam);
extern SIM_API_SYMBOL(ptrSimGetObjectStringParam) SIM_API_SYMBOL(simGetObjectStringParam);
extern SIM_API_SYMBOL(ptrSimSetObjectStringParam) SIM_API_SYMBOL(simSetObjectStringParam);
extern SIM_API_SYMBOL(ptrSimWriteCustomDataBlock) SIM_API_SYMBOL(simWriteCustomDataBlock);
extern SIM_API_SYMBOL(ptrSimReadCustomDataBlock) SIM_API_SYMBOL(simReadCustomDataBlock);
extern SIM_API_SYMBOL(ptrSimReadCustomDataBlockTags) SIM_API_SYMBOL(simReadCustomDataBlockTags);
extern SIM_API_SYMBOL(ptrSimGetEngineFloatParam) SIM_API_SYMBOL(simGetEngineFloatParam);
extern SIM_API_SYMBOL(ptrSimGetEngineInt32Param) SIM_API_SYMBOL(simGetEngineInt32Param);
extern SIM_API_SYMBOL(ptrSimGetEngineBoolParam) SIM_API_SYMBOL(simGetEngineBoolParam);
extern SIM_API_SYMBOL(ptrSimSetEngineFloatParam) SIM_API_SYMBOL(simSetEngineFloatParam);
extern SIM_API_SYMBOL(ptrSimSetEngineInt32Param) SIM_API_SYMBOL(simSetEngineInt32Param);
extern SIM_API_SYMBOL(ptrSimSetEngineBoolParam) SIM_API_SYMBOL(simSetEngineBoolParam);
extern SIM_API_SYMBOL(ptrSimSetObjectProperty) SIM_API_SYMBOL(simSetObjectProperty);
extern SIM_API_SYMBOL(ptrSimGetObjectProperty) SIM_API_SYMBOL(simGetObjectProperty);
extern SIM_API_SYMBOL(ptrSimSetObjectSpecialProperty) SIM_API_SYMBOL(simSetObjectSpecialProperty);
extern SIM_API_SYMBOL(ptrSimGetObjectSpecialProperty) SIM_API_SYMBOL(simGetObjectSpecialProperty);
extern SIM_API_SYMBOL(ptrSimSetModelProperty) SIM_API_SYMBOL(simSetModelProperty);
extern SIM_API_SYMBOL(ptrSimGetModelProperty) SIM_API_SYMBOL(simGetModelProperty);

#ifdef SIM_INTERFACE_OLD
#include "simLib-old2.h"
#endif
