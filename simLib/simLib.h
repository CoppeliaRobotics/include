// Use this header to dynamically load and bind coppeliaSim.dll and its functions (call loadSimLibrary and unloadSimLibrary)

#if !defined(SIMLIB_INCLUDED_)
#define SIMLIB_INCLUDED_

#include "simConst.h"
#include "simTypes.h"
#ifdef SIM_INTERFACE_SINGLE
#define SIMDOUBLE float
#else
#define SIMDOUBLE double
#endif

#ifdef SIM_UNIFIED_HANDLES
#define SIMHANDLE long long int
#define LH true
#else
#define SIMHANDLE int
#define LH false
#endif

#ifdef QT_FRAMEWORK
    #include <QLibrary>
    #include <QDebug>
    #define LIBRARY QLibrary*
    #define __cdecl
    #define FARPROC void*
#else
    #ifdef _WIN32
        #include <Windows.h>
        #define LIBRARY HINSTANCE
    #elif defined (__linux) || defined (__APPLE__)
        #define __cdecl
        #define FARPROC void*
        #define LIBRARY void*
    #endif
    #include <stdio.h>
#endif // QT_FRAMEWORK

#ifdef SIM_LIB_PREFIX
    #define SIM_API_SYMBOL_CONCAT2(a, b) a ## b
    #define SIM_API_SYMBOL_CONCAT(a, b) SIM_API_SYMBOL_CONCAT2(a, b)
    #define SIM_API_SYMBOL(x) SIM_API_SYMBOL_CONCAT(SIM_LIB_PREFIX, x)

    static int simSetBoolProperty(long long int target, const char* pName, int pState) { return SIM_API_SYMBOL(simSetBoolProperty)(target,pName,pState); }
    static int simGetBoolProperty(long long int target, const char* pName, int* pState) { return SIM_API_SYMBOL(simGetBoolProperty)(target,pName,pState); }
    static int simSetIntProperty(long long int target, const char* pName, int pState) { return SIM_API_SYMBOL(simSetIntProperty)(target,pName,pState); }
    static int simGetIntProperty(long long int target, const char* pName, int* pState) { return SIM_API_SYMBOL(simGetIntProperty)(target,pName,pState); }
    static int simSetLongProperty(long long int target, const char* pName, long long int pState) { return SIM_API_SYMBOL(simSetLongProperty)(target,pName,pState); }
    static int simGetLongProperty(long long int target, const char* pName, long long int* pState) { return SIM_API_SYMBOL(simGetLongProperty)(target,pName,pState); }
    static int simSetFloatProperty(long long int target, const char* pName, double pState) { return SIM_API_SYMBOL(simSetFloatProperty)(target,pName,pState); }
    static int simGetFloatProperty(long long int target, const char* pName, double* pState) { return SIM_API_SYMBOL(simGetFloatProperty)(target,pName,pState); }
    static int simSetStringProperty(long long int target, const char* pName, const char* pState) { return SIM_API_SYMBOL(simSetStringProperty)(target,pName,pState); }
    static char* simGetStringProperty(long long int target, const char* pName) { return SIM_API_SYMBOL(simGetStringProperty)(target,pName); }
    static int simSetTableProperty(long long int target, const char* pName, const char* buffer, int bufferL) { return SIM_API_SYMBOL(simSetTableProperty)(target,pName,buffer,bufferL); }
    static char* simGetTableProperty(long long int target, const char* pName, int* bufferL) { return SIM_API_SYMBOL(simGetTableProperty)(target,pName,bufferL); }
    static int simSetBufferProperty(long long int target, const char* pName, const char* buffer, int bufferL) { return SIM_API_SYMBOL(simSetBufferProperty)(target,pName,buffer,bufferL); }
    static char* simGetBufferProperty(long long int target, const char* pName, int* bufferL) { return SIM_API_SYMBOL(simGetBufferProperty)(target,pName,bufferL); }
    static int simSetIntArray2Property(long long int target, const char* pName, const int* pState) { return SIM_API_SYMBOL(simSetIntArray2Property)(target,pName,pState); }
    static int simGetIntArray2Property(long long int target, const char* pName, int* pState) { return SIM_API_SYMBOL(simGetIntArray2Property)(target,pName,pState); }
    static int simSetVector2Property(long long int target, const char* pName, const double* pState) { return SIM_API_SYMBOL(simSetVector2Property)(target,pName,pState); }
    static int simGetVector2Property(long long int target, const char* pName, double* pState) { return SIM_API_SYMBOL(simGetVector2Property)(target,pName,pState); }
    static int simSetVector3Property(long long int target, const char* pName, const double* pState) { return SIM_API_SYMBOL(simSetVector3Property)(target,pName,pState); }
    static int simGetVector3Property(long long int target, const char* pName, double* pState) { return SIM_API_SYMBOL(simGetVector3Property)(target,pName,pState); }
    static int simSetQuaternionProperty(long long int target, const char* pName, const double* pState) { return SIM_API_SYMBOL(simSetQuaternionProperty)(target,pName,pState); }
    static int simGetQuaternionProperty(long long int target, const char* pName, double* pState) { return SIM_API_SYMBOL(simGetQuaternionProperty)(target,pName,pState); }
    static int simSetPoseProperty(long long int target, const char* pName, const double* pState) { return SIM_API_SYMBOL(simSetPoseProperty)(target,pName,pState); }
    static int simGetPoseProperty(long long int target, const char* pName, double* pState) { return SIM_API_SYMBOL(simGetPoseProperty)(target,pName,pState); }
    static int simSetColorProperty(long long int target, const char* pName, const float* pState) { return SIM_API_SYMBOL(simSetColorProperty)(target,pName,pState); }
    static int simGetColorProperty(long long int target, const char* pName, float* pState) { return SIM_API_SYMBOL(simGetColorProperty)(target,pName,pState); }
    static int simSetFloatArrayProperty(long long int target, const char* pName, const double* v, int vL) { return SIM_API_SYMBOL(simSetFloatArrayProperty)(target,pName,v,vL); }
    static double* simGetFloatArrayProperty(long long int target, const char* pName, int* vL) { return SIM_API_SYMBOL(simGetFloatArrayProperty)(target,pName,vL); }
    static int simSetIntArrayProperty(long long int target, const char* pName, const int* v, int vL) { return SIM_API_SYMBOL(simSetIntArrayProperty)(target,pName,v,vL); }
    static int* simGetIntArrayProperty(long long int target, const char* pName, int* vL) { return SIM_API_SYMBOL(simGetIntArrayProperty)(target,pName,vL); }
    static int simRemoveProperty(long long int target, const char* pName) { return SIM_API_SYMBOL(simRemoveProperty)(target,pName); }
    static char* simGetPropertyName(long long int target, int index, SPropertyOptions* options) { return SIM_API_SYMBOL(simGetPropertyName)(target,index,options); }
    static int simGetPropertyInfo(long long int target, const char* pName, SPropertyInfo* infos, SPropertyOptions* options) { return SIM_API_SYMBOL(simGetPropertyInfo)(target,pName,infos,options); }
    static void simRegCallback(int index, void* cb) { return SIM_API_SYMBOL(simRegCallback)(index,cb); }
    static void simRunGui(int options) { return SIM_API_SYMBOL(simRunGui)(options); }
    static int simInitialize(const char* appDir,int options) { return SIM_API_SYMBOL(simInitialize)(appDir,options); }
    static int simDeinitialize() { return SIM_API_SYMBOL(simDeinitialize)(); }
    static int simPostExitRequest() { return SIM_API_SYMBOL(simPostExitRequest)(); }
    static int simGetExitRequest() { return SIM_API_SYMBOL(simGetExitRequest)(); }
    static int simLoop(void(*callback)(),int options) { return SIM_API_SYMBOL(simLoop)(callback,options); }
    static int simTest(int mode,void* ptr1,void* ptr2,void* ptr3) { return SIM_API_SYMBOL(simTest)(mode,ptr1,ptr2,ptr3); }
    static int simAddLog(const char* pluginName,int verbosityLevel,const char* logMsg) { return SIM_API_SYMBOL(simAddLog)(pluginName,verbosityLevel,logMsg); }
    static char* simGetSimulatorMessage(int* messageID,int* auxiliaryData,int* returnedDataSize) { return SIM_API_SYMBOL(simGetSimulatorMessage)(messageID,auxiliaryData,returnedDataSize); }
    static void* simGetMainWindow(int type) { return SIM_API_SYMBOL(simGetMainWindow)(type); }
    static char* simGetLastError() { return SIM_API_SYMBOL(simGetLastError)(); }
    static char* simGetLastInfo() { return SIM_API_SYMBOL(simGetLastInfo)(); }
    static SIMHANDLE simGetObject(const char* objectPath,int index,SIMHANDLE proxy,int options) { return SIM_API_SYMBOL(simGetObject)(objectPath,index,proxy,options); }
    static long long int simGetObjectUid(SIMHANDLE objectHandle) { return SIM_API_SYMBOL(simGetObjectUid)(objectHandle); }
    static SIMHANDLE simGetObjectFromUid(long long int uid,int options) { return SIM_API_SYMBOL(simGetObjectFromUid)(uid,options); }
    static SIMHANDLE simGetScriptHandleEx(int scriptType,SIMHANDLE objHandle,const char* scriptName) { return SIM_API_SYMBOL(simGetScriptHandleEx)(scriptType,objHandle,scriptName); }
    static int simRemoveObjects(const SIMHANDLE* objectHandles,int count) { return SIM_API_SYMBOL(simRemoveObjects)(objectHandles,count); }
    static int simRemoveModel(SIMHANDLE objectHandle) { return SIM_API_SYMBOL(simRemoveModel)(objectHandle); }
    static char* simGetObjectAlias(SIMHANDLE objectHandle,int options) { return SIM_API_SYMBOL(simGetObjectAlias)(objectHandle,options); }
    static int simSetObjectAlias(SIMHANDLE objectHandle,const char* objectAlias,int options) { return SIM_API_SYMBOL(simSetObjectAlias)(objectHandle,objectAlias,options); }
    static SIMHANDLE simGetObjectParent(SIMHANDLE objectHandle) { return SIM_API_SYMBOL(simGetObjectParent)(objectHandle); }
    static SIMHANDLE simGetObjectChild(SIMHANDLE objectHandle,int index) { return SIM_API_SYMBOL(simGetObjectChild)(objectHandle,index); }
    static int simSetObjectParent(SIMHANDLE objectHandle,SIMHANDLE parentObjectHandle,bool keepInPlace) { return SIM_API_SYMBOL(simSetObjectParent)(objectHandle,parentObjectHandle,keepInPlace); }
    static int simGetObjectType(SIMHANDLE objectHandle) { return SIM_API_SYMBOL(simGetObjectType)(objectHandle); }
    static int simGetJointType(SIMHANDLE objectHandle) { return SIM_API_SYMBOL(simGetJointType)(objectHandle); }
    static int simReservedCommand(int v,int w) { return SIM_API_SYMBOL(simReservedCommand)(v,w); }
    static int simGetSimulationState() { return SIM_API_SYMBOL(simGetSimulationState)(); }
    static int simLoadScene(const char* filename) { return SIM_API_SYMBOL(simLoadScene)(filename); }
    static int simCloseScene() { return SIM_API_SYMBOL(simCloseScene)(); }
    static int simSaveScene(const char* filename) { return SIM_API_SYMBOL(simSaveScene)(filename); }
    static SIMHANDLE simLoadModel(const char* filename) { return SIM_API_SYMBOL(simLoadModel)(filename); }
    static int simSaveModel(SIMHANDLE baseOfModelHandle,const char* filename) { return SIM_API_SYMBOL(simSaveModel)(baseOfModelHandle,filename); }
    static int simDoesFileExist(const char* filename) { return SIM_API_SYMBOL(simDoesFileExist)(filename); }
    static SIMHANDLE* simGetObjectSel(int* cnt) { return SIM_API_SYMBOL(simGetObjectSel)(cnt); }
    static int simSetObjectSel(const SIMHANDLE* handles,int cnt) { return SIM_API_SYMBOL(simSetObjectSel)(handles,cnt); }
    static int simResetScript(SIMHANDLE scriptHandle) { return SIM_API_SYMBOL(simResetScript)(scriptHandle); }
    static int simRefreshDialogs(int refreshDegree) { return SIM_API_SYMBOL(simRefreshDialogs)(refreshDegree); }
    static int simResetProximitySensor(SIMHANDLE sensorHandle) { return SIM_API_SYMBOL(simResetProximitySensor)(sensorHandle); }
    static void* simCreateBuffer(int size) { return SIM_API_SYMBOL(simCreateBuffer)(size); }
    static int simReleaseBuffer(const void* buffer) { return SIM_API_SYMBOL(simReleaseBuffer)(buffer); }
    static int simCheckCollision(SIMHANDLE entity1Handle,SIMHANDLE entity2Handle) { return SIM_API_SYMBOL(simCheckCollision)(entity1Handle,entity2Handle); }
    static int simGetRealTimeSimulation() { return SIM_API_SYMBOL(simGetRealTimeSimulation)(); }
    static int simStartSimulation() { return SIM_API_SYMBOL(simStartSimulation)(); }
    static int simStopSimulation() { return SIM_API_SYMBOL(simStopSimulation)(); }
    static int simPauseSimulation() { return SIM_API_SYMBOL(simPauseSimulation)(); }
    static int simAdjustView(int viewHandleOrIndex,SIMHANDLE associatedViewableObjectHandle,int options,const char* viewLabel) { return SIM_API_SYMBOL(simAdjustView)(viewHandleOrIndex,associatedViewableObjectHandle,options,viewLabel); }
    static int simSetLastError(const char* setToNullptr,const char* errorMessage) { return SIM_API_SYMBOL(simSetLastError)(setToNullptr,errorMessage); }
    static int simResetGraph(SIMHANDLE graphHandle) { return SIM_API_SYMBOL(simResetGraph)(graphHandle); }
    static int simDestroyGraphCurve(SIMHANDLE graphHandle,SIMHANDLE curveId) { return SIM_API_SYMBOL(simDestroyGraphCurve)(graphHandle,curveId); }
    static int simDuplicateGraphCurveToStatic(SIMHANDLE graphHandle,SIMHANDLE curveId,const char* curveName) { return SIM_API_SYMBOL(simDuplicateGraphCurveToStatic)(graphHandle,curveId,curveName); }
    static int simSetNavigationMode(int navigationMode) { return SIM_API_SYMBOL(simSetNavigationMode)(navigationMode); }
    static int simGetNavigationMode() { return SIM_API_SYMBOL(simGetNavigationMode)(); }
    static int simSetPage(int index) { return SIM_API_SYMBOL(simSetPage)(index); }
    static int simGetPage() { return SIM_API_SYMBOL(simGetPage)(); }
    static int simRegisterScriptCallbackFunction(const char* func,const char* reserved_setToNull,void(*callBack)(struct SScriptCallBack* cb)) { return SIM_API_SYMBOL(simRegisterScriptCallbackFunction)(func,reserved_setToNull,callBack); }
    static int simRegisterScriptVariable(const char* var,const char* value,SIMHANDLE stackHandle) { return SIM_API_SYMBOL(simRegisterScriptVariable)(var,value,stackHandle); }
    static int simRegisterScriptFuncHook(SIMHANDLE scriptHandle,const char* funcToHook,const char* userFunction,bool executeBefore,int options) { return SIM_API_SYMBOL(simRegisterScriptFuncHook)(scriptHandle,funcToHook,userFunction,executeBefore,options); }
    static int simCopyPasteObjects(SIMHANDLE* objectHandles,int objectCount,int options) { return SIM_API_SYMBOL(simCopyPasteObjects)(objectHandles,objectCount,options); }
    static int simRemoveDrawingObject(SIMHANDLE objectHandle) { return SIM_API_SYMBOL(simRemoveDrawingObject)(objectHandle); }
    static int simAnnounceSceneContentChange() { return SIM_API_SYMBOL(simAnnounceSceneContentChange)(); }
    static int simSetExplicitHandling(SIMHANDLE objectHandle,int explicitFlags) { return SIM_API_SYMBOL(simSetExplicitHandling)(objectHandle,explicitFlags); }
    static int simGetExplicitHandling(SIMHANDLE objectHandle) { return SIM_API_SYMBOL(simGetExplicitHandling)(objectHandle); }
    static SIMHANDLE simGetLinkDummy(SIMHANDLE dummyHandle) { return SIM_API_SYMBOL(simGetLinkDummy)(dummyHandle); }
    static int simSetLinkDummy(SIMHANDLE dummyHandle,SIMHANDLE linkedDummyHandle) { return SIM_API_SYMBOL(simSetLinkDummy)(dummyHandle,linkedDummyHandle); }
    static int simResetDynamicObject(SIMHANDLE objectHandle) { return SIM_API_SYMBOL(simResetDynamicObject)(objectHandle); }
    static int simSetJointMode(SIMHANDLE jointHandle,int jointMode,int options) { return SIM_API_SYMBOL(simSetJointMode)(jointHandle,jointMode,options); }
    static int simGetJointMode(SIMHANDLE jointHandle,int* options) { return SIM_API_SYMBOL(simGetJointMode)(jointHandle,options); }
    static int simSerialOpen(const char* portString,int baudRate,void* reserved1,void* reserved2) { return SIM_API_SYMBOL(simSerialOpen)(portString,baudRate,reserved1,reserved2); }
    static int simSerialClose(int portHandle) { return SIM_API_SYMBOL(simSerialClose)(portHandle); }
    static int simSerialSend(int portHandle,const char* data,int dataLength) { return SIM_API_SYMBOL(simSerialSend)(portHandle,data,dataLength); }
    static int simSerialRead(int portHandle,char* buffer,int dataLengthToRead) { return SIM_API_SYMBOL(simSerialRead)(portHandle,buffer,dataLengthToRead); }
    static int simSerialCheck(int portHandle) { return SIM_API_SYMBOL(simSerialCheck)(portHandle); }
    static int simAuxiliaryConsoleClose(int consoleHandle) { return SIM_API_SYMBOL(simAuxiliaryConsoleClose)(consoleHandle); }
    static int simAuxiliaryConsoleShow(int consoleHandle,bool showState) { return SIM_API_SYMBOL(simAuxiliaryConsoleShow)(consoleHandle,showState); }
    static int simAuxiliaryConsolePrint(int consoleHandle,const char* text) { return SIM_API_SYMBOL(simAuxiliaryConsolePrint)(consoleHandle,text); }
    static int simIsHandle(SIMHANDLE generalObjectHandle,int generalObjectType) { return SIM_API_SYMBOL(simIsHandle)(generalObjectHandle,generalObjectType); }
    static int simResetVisionSensor(SIMHANDLE visionSensorHandle) { return SIM_API_SYMBOL(simResetVisionSensor)(visionSensorHandle); }
    static int simSetVisionSensorImg(SIMHANDLE sensorHandle,const unsigned char* img,int options,const int* pos,const int* size) { return SIM_API_SYMBOL(simSetVisionSensorImg)(sensorHandle,img,options,pos,size); }
    static int simRuckigRemove(int objHandle) { return SIM_API_SYMBOL(simRuckigRemove)(objHandle); }
    static SIMHANDLE simGroupShapes(const SIMHANDLE* shapeHandles,int shapeCount) { return SIM_API_SYMBOL(simGroupShapes)(shapeHandles,shapeCount); }
    static SIMHANDLE* simUngroupShape(SIMHANDLE shapeHandle,int* shapeCount) { return SIM_API_SYMBOL(simUngroupShape)(shapeHandle,shapeCount); }
    static void simQuitSimulator(bool ignoredArgument) { return SIM_API_SYMBOL(simQuitSimulator)(ignoredArgument); }
    static int simSetShapeMaterial(SIMHANDLE shapeHandle,SIMHANDLE materialIdOrShapeHandle) { return SIM_API_SYMBOL(simSetShapeMaterial)(shapeHandle,materialIdOrShapeHandle); }
    static SIMHANDLE simGetTextureId(const char* textureName,int* resolution) { return SIM_API_SYMBOL(simGetTextureId)(textureName,resolution); }
    static unsigned char* simReadTexture(SIMHANDLE textureId,int options,int posX,int posY,int sizeX,int sizeY) { return SIM_API_SYMBOL(simReadTexture)(textureId,options,posX,posY,sizeX,sizeY); }
    static SIMHANDLE simGetObjects(int index,int objectType) { return SIM_API_SYMBOL(simGetObjects)(index,objectType); }
    static SIMHANDLE* simGetObjectsInTree(SIMHANDLE treeBaseHandle,int objectType,int options,int* objectCount) { return SIM_API_SYMBOL(simGetObjectsInTree)(treeBaseHandle,objectType,options,objectCount); }
    static SIMHANDLE simGetShapeTextureId(SIMHANDLE shapeHandle) { return SIM_API_SYMBOL(simGetShapeTextureId)(shapeHandle); }
    static SIMHANDLE simCreateCollectionEx(int options) { return SIM_API_SYMBOL(simCreateCollectionEx)(options); }
    static int simAddItemToCollection(SIMHANDLE collectionHandle,int what,SIMHANDLE objectHandle,int options) { return SIM_API_SYMBOL(simAddItemToCollection)(collectionHandle,what,objectHandle,options); }
    static int simDestroyCollection(SIMHANDLE collectionHandle) { return SIM_API_SYMBOL(simDestroyCollection)(collectionHandle); }
    static SIMHANDLE* simGetCollectionObjects(SIMHANDLE collectionHandle,int* objectCount) { return SIM_API_SYMBOL(simGetCollectionObjects)(collectionHandle,objectCount); }
    static int simAlignShapeBB(SIMHANDLE shapeHandle,const double* pose) { return SIM_API_SYMBOL(simAlignShapeBB)(shapeHandle,pose); }
    static int simRelocateShapeFrame(SIMHANDLE shapeHandle,const double* pose) { return SIM_API_SYMBOL(simRelocateShapeFrame)(shapeHandle,pose); }
    static int simSaveImage(const unsigned char* image,const int* resolution,int options,const char* filename,int quality,void* reserved) { return SIM_API_SYMBOL(simSaveImage)(image,resolution,options,filename,quality,reserved); }
    static unsigned char* simLoadImage(int* resolution,int options,const char* filename,void* reserved) { return SIM_API_SYMBOL(simLoadImage)(resolution,options,filename,reserved); }
    static unsigned char* simGetScaledImage(const unsigned char* imageIn,const int* resolutionIn,int* resolutionOut,int options,void* reserved) { return SIM_API_SYMBOL(simGetScaledImage)(imageIn,resolutionIn,resolutionOut,options,reserved); }
    static int simCallScriptFunctionEx(SIMHANDLE scriptHandleOrType,const char* functionNameAtScriptName,SIMHANDLE stackId) { return SIM_API_SYMBOL(simCallScriptFunctionEx)(scriptHandleOrType,functionNameAtScriptName,stackId); }
    static char* simGetExtensionString(SIMHANDLE objectHandle,int index,const char* key) { return SIM_API_SYMBOL(simGetExtensionString)(objectHandle,index,key); }
    static SIMHANDLE simCreateStack() { return SIM_API_SYMBOL(simCreateStack)(); }
    static int simReleaseStack(SIMHANDLE stackHandle) { return SIM_API_SYMBOL(simReleaseStack)(stackHandle); }
    static SIMHANDLE simCopyStack(SIMHANDLE stackHandle) { return SIM_API_SYMBOL(simCopyStack)(stackHandle); }
    static int simPushNullOntoStack(SIMHANDLE stackHandle) { return SIM_API_SYMBOL(simPushNullOntoStack)(stackHandle); }
    static int simPushBoolOntoStack(SIMHANDLE stackHandle,bool value) { return SIM_API_SYMBOL(simPushBoolOntoStack)(stackHandle,value); }
    static int simPushInt32OntoStack(SIMHANDLE stackHandle,int value) { return SIM_API_SYMBOL(simPushInt32OntoStack)(stackHandle,value); }
    static int simPushInt64OntoStack(SIMHANDLE stackHandle,long long int value) { return SIM_API_SYMBOL(simPushInt64OntoStack)(stackHandle,value); }
    static int simPushTextOntoStack(SIMHANDLE stackHandle,const char* value) { return SIM_API_SYMBOL(simPushTextOntoStack)(stackHandle,value); }
    static int simPushStringOntoStack(SIMHANDLE stackHandle,const char* value,int stringSize) { return SIM_API_SYMBOL(simPushStringOntoStack)(stackHandle,value,stringSize); }
    static int simPushBufferOntoStack(SIMHANDLE stackHandle,const char* value,int stringSize) { return SIM_API_SYMBOL(simPushBufferOntoStack)(stackHandle,value,stringSize); }
    static int simPushUInt8TableOntoStack(SIMHANDLE stackHandle,const unsigned char* values,int valueCnt) { return SIM_API_SYMBOL(simPushUInt8TableOntoStack)(stackHandle,values,valueCnt); }
    static int simPushInt32TableOntoStack(SIMHANDLE stackHandle,const int* values,int valueCnt) { return SIM_API_SYMBOL(simPushInt32TableOntoStack)(stackHandle,values,valueCnt); }
    static int simPushInt64TableOntoStack(SIMHANDLE stackHandle,const long long int* values,int valueCnt) { return SIM_API_SYMBOL(simPushInt64TableOntoStack)(stackHandle,values,valueCnt); }
    static int simPushTableOntoStack(SIMHANDLE stackHandle) { return SIM_API_SYMBOL(simPushTableOntoStack)(stackHandle); }
    static int simInsertDataIntoStackTable(SIMHANDLE stackHandle) { return SIM_API_SYMBOL(simInsertDataIntoStackTable)(stackHandle); }
    static int simGetStackSize(SIMHANDLE stackHandle) { return SIM_API_SYMBOL(simGetStackSize)(stackHandle); }
    static int simPopStackItem(SIMHANDLE stackHandle,int count) { return SIM_API_SYMBOL(simPopStackItem)(stackHandle,count); }
    static int simMoveStackItemToTop(SIMHANDLE stackHandle,int cIndex) { return SIM_API_SYMBOL(simMoveStackItemToTop)(stackHandle,cIndex); }
    static int simGetStackItemType(SIMHANDLE stackHandle,int cIndex) { return SIM_API_SYMBOL(simGetStackItemType)(stackHandle,cIndex); }
    static int simGetStackStringType(SIMHANDLE stackHandle,int cIndex) { return SIM_API_SYMBOL(simGetStackStringType)(stackHandle,cIndex); }
    static int simGetStackBoolValue(SIMHANDLE stackHandle,bool* boolValue) { return SIM_API_SYMBOL(simGetStackBoolValue)(stackHandle,boolValue); }
    static int simGetStackInt32Value(SIMHANDLE stackHandle,int* numberValue) { return SIM_API_SYMBOL(simGetStackInt32Value)(stackHandle,numberValue); }
    static int simGetStackInt64Value(SIMHANDLE stackHandle,long long int* numberValue) { return SIM_API_SYMBOL(simGetStackInt64Value)(stackHandle,numberValue); }
    static char* simGetStackStringValue(SIMHANDLE stackHandle,int* stringSize) { return SIM_API_SYMBOL(simGetStackStringValue)(stackHandle,stringSize); }
    static int simGetStackTableInfo(SIMHANDLE stackHandle,int infoType) { return SIM_API_SYMBOL(simGetStackTableInfo)(stackHandle,infoType); }
    static int simGetStackUInt8Table(SIMHANDLE stackHandle,unsigned char* array,int count) { return SIM_API_SYMBOL(simGetStackUInt8Table)(stackHandle,array,count); }
    static int simGetStackInt32Table(SIMHANDLE stackHandle,int* array,int count) { return SIM_API_SYMBOL(simGetStackInt32Table)(stackHandle,array,count); }
    static int simGetStackInt64Table(SIMHANDLE stackHandle,long long int* array,int count) { return SIM_API_SYMBOL(simGetStackInt64Table)(stackHandle,array,count); }
    static int simUnfoldStackTable(SIMHANDLE stackHandle) { return SIM_API_SYMBOL(simUnfoldStackTable)(stackHandle); }
    static int simDebugStack(SIMHANDLE stackHandle,int cIndex) { return SIM_API_SYMBOL(simDebugStack)(stackHandle,cIndex); }
    static int simInsertObjectIntoOctree(SIMHANDLE octreeHandle,SIMHANDLE objectHandle,int options,const unsigned char* color,unsigned int tag,void* reserved) { return SIM_API_SYMBOL(simInsertObjectIntoOctree)(octreeHandle,objectHandle,options,color,tag,reserved); }
    static int simSubtractObjectFromOctree(SIMHANDLE octreeHandle,SIMHANDLE objectHandle,int options,void* reserved) { return SIM_API_SYMBOL(simSubtractObjectFromOctree)(octreeHandle,objectHandle,options,reserved); }
    static char* simOpenTextEditor(const char* initText,const char* xml,int* various) { return SIM_API_SYMBOL(simOpenTextEditor)(initText,xml,various); }
    static char* simPackTable(SIMHANDLE stackHandle,int* bufferSize) { return SIM_API_SYMBOL(simPackTable)(stackHandle,bufferSize); }
    static int simUnpackTable(SIMHANDLE stackHandle,const char* buffer,int bufferSize) { return SIM_API_SYMBOL(simUnpackTable)(stackHandle,buffer,bufferSize); }
    static int simSetReferencedHandles(SIMHANDLE objectHandle,int count,const SIMHANDLE* referencedHandles,const char* tag,const int* reserved2) { return SIM_API_SYMBOL(simSetReferencedHandles)(objectHandle,count,referencedHandles,tag,reserved2); }
    static int simGetReferencedHandles(SIMHANDLE objectHandle,SIMHANDLE** referencedHandles,const char* tag,SIMHANDLE** reserved2) { return SIM_API_SYMBOL(simGetReferencedHandles)(objectHandle,referencedHandles,tag,reserved2); }
    static int simExecuteScriptString(SIMHANDLE scriptHandle,const char* stringToExecute,SIMHANDLE stackHandle) { return SIM_API_SYMBOL(simExecuteScriptString)(scriptHandle,stringToExecute,stackHandle); }
    static char* simGetApiFunc(SIMHANDLE scriptHandle,const char* apiWord) { return SIM_API_SYMBOL(simGetApiFunc)(scriptHandle,apiWord); }
    static char* simGetApiInfo(SIMHANDLE scriptHandle,const char* apiWord) { return SIM_API_SYMBOL(simGetApiInfo)(scriptHandle,apiWord); }
    static int simSetPluginInfo(const char* pluginName,int infoType,const char* stringInfo,int intInfo) { return SIM_API_SYMBOL(simSetPluginInfo)(pluginName,infoType,stringInfo,intInfo); }
    static int simGetPluginInfo(const char* pluginName,int infoType,char** stringInfo,int* intInfo) { return SIM_API_SYMBOL(simGetPluginInfo)(pluginName,infoType,stringInfo,intInfo); }
    static char* simGetPluginName(int index) { return SIM_API_SYMBOL(simGetPluginName)(index); }
    static int simEventNotification(const char* event) { return SIM_API_SYMBOL(simEventNotification)(event); }
    static int simIsDynamicallyEnabled(SIMHANDLE objectHandle) { return SIM_API_SYMBOL(simIsDynamicallyEnabled)(objectHandle); }
    static int simInitScript(SIMHANDLE scriptHandle) { return SIM_API_SYMBOL(simInitScript)(scriptHandle); }
    static int simModuleEntry(int handle,const char* label,int state) { return SIM_API_SYMBOL(simModuleEntry)(handle,label,state); }
    static int simCheckExecAuthorization(const char* what,const char* args) { return SIM_API_SYMBOL(simCheckExecAuthorization)(what,args); }
    static int simPushFloatOntoStack(SIMHANDLE stackHandle,float value) { return SIM_API_SYMBOL(simPushFloatOntoStack)(stackHandle,value); }
    static int simPushFloatTableOntoStack(SIMHANDLE stackHandle,const float* values,int valueCnt) { return SIM_API_SYMBOL(simPushFloatTableOntoStack)(stackHandle,values,valueCnt); }
    static int simGetStackFloatValue(SIMHANDLE stackHandle,float* numberValue) { return SIM_API_SYMBOL(simGetStackFloatValue)(stackHandle,numberValue); }
    static int simGetStackFloatTable(SIMHANDLE stackHandle,float* array,int count) { return SIM_API_SYMBOL(simGetStackFloatTable)(stackHandle,array,count); }
    static float* simGetVisionSensorDepth(SIMHANDLE sensorHandle,int options,const int* pos,const int* size,int* resolution) { return SIM_API_SYMBOL(simGetVisionSensorDepth)(sensorHandle,options,pos,size,resolution); }
    static int _simSetVisionSensorDepth(SIMHANDLE sensorHandle,int options,const float* depth) { return SIM_API_SYMBOL(_simSetVisionSensorDepth)(sensorHandle,options,depth); }
    static float* simCheckVisionSensorEx(SIMHANDLE visionSensorHandle,SIMHANDLE entityHandle,bool returnImage) { return SIM_API_SYMBOL(simCheckVisionSensorEx)(visionSensorHandle,entityHandle,returnImage); }
    static int simRuckigPos(int dofs,double baseCycleTime,int flags,const double* currentPos,const double* currentVel,const double* currentAccel,const double* maxVel,const double* maxAccel,const double* maxJerk,const bool* selection,const double* targetPos,const double* targetVel,double* reserved1,int* reserved2) { return SIM_API_SYMBOL(simRuckigPos)(dofs,baseCycleTime,flags,currentPos,currentVel,currentAccel,maxVel,maxAccel,maxJerk,selection,targetPos,targetVel,reserved1,reserved2); }
    static int simRuckigVel(int dofs,double baseCycleTime,int flags,const double* currentPos,const double* currentVel,const double* currentAccel,const double* maxAccel,const double* maxJerk,const bool* selection,const double* targetVel,double* reserved1,int* reserved2) { return SIM_API_SYMBOL(simRuckigVel)(dofs,baseCycleTime,flags,currentPos,currentVel,currentAccel,maxAccel,maxJerk,selection,targetVel,reserved1,reserved2); }
    static int simRuckigStep(int objHandle,double cycleTime,double* newPos,double* newVel,double* newAccel,double* syncTime,double* reserved1,int* reserved2) { return SIM_API_SYMBOL(simRuckigStep)(objHandle,cycleTime,newPos,newVel,newAccel,syncTime,reserved1,reserved2); }
    static int simPushDoubleOntoStack(SIMHANDLE stackHandle,double value) { return SIM_API_SYMBOL(simPushDoubleOntoStack)(stackHandle,value); }
    static int simPushDoubleTableOntoStack(SIMHANDLE stackHandle,const double* values,int valueCnt) { return SIM_API_SYMBOL(simPushDoubleTableOntoStack)(stackHandle,values,valueCnt); }
    static int simGetStackDoubleValue(SIMHANDLE stackHandle,double* numberValue) { return SIM_API_SYMBOL(simGetStackDoubleValue)(stackHandle,numberValue); }
    static int simGetStackDoubleTable(SIMHANDLE stackHandle,double* array,int count) { return SIM_API_SYMBOL(simGetStackDoubleTable)(stackHandle,array,count); }
    static void _simSetDynamicSimulationIconCode(void* object,int code) { return SIM_API_SYMBOL(_simSetDynamicSimulationIconCode)(object,code); }
    static void _simSetDynamicObjectFlagForVisualization(void* object,int flag) { return SIM_API_SYMBOL(_simSetDynamicObjectFlagForVisualization)(object,flag); }
    static int _simGetObjectListSize(int objType) { return SIM_API_SYMBOL(_simGetObjectListSize)(objType); }
    static const void* _simGetObjectFromIndex(int objType,int index) { return SIM_API_SYMBOL(_simGetObjectFromIndex)(objType,index); }
    static SIMHANDLE _simGetObjectID(const void* object) { return SIM_API_SYMBOL(_simGetObjectID)(object); }
    static int _simGetObjectType(const void* object) { return SIM_API_SYMBOL(_simGetObjectType)(object); }
    static const void** _simGetObjectChildren(const void* object,int* count) { return SIM_API_SYMBOL(_simGetObjectChildren)(object,count); }
    static const void* _simGetParentObject(const void* object) { return SIM_API_SYMBOL(_simGetParentObject)(object); }
    static const void* _simGetObject(SIMHANDLE objID) { return SIM_API_SYMBOL(_simGetObject)(objID); }
    static const void* _simGetIkGroupObject(int ikGroupID) { return SIM_API_SYMBOL(_simGetIkGroupObject)(ikGroupID); }
    static int _simMpHandleIkGroupObject(const void* ikGroup) { return SIM_API_SYMBOL(_simMpHandleIkGroupObject)(ikGroup); }
    static bool _simIsShapeDynamicallyStatic(const void* shape) { return SIM_API_SYMBOL(_simIsShapeDynamicallyStatic)(shape); }
    static int _simGetTreeDynamicProperty(const void* object) { return SIM_API_SYMBOL(_simGetTreeDynamicProperty)(object); }
    static int _simGetDummyLinkType(const void* dummy,SIMHANDLE* linkedDummyID) { return SIM_API_SYMBOL(_simGetDummyLinkType)(dummy,linkedDummyID); }
    static int _simGetJointMode(const void* joint) { return SIM_API_SYMBOL(_simGetJointMode)(joint); }
    static bool _simIsJointInHybridOperation(const void* joint) { return SIM_API_SYMBOL(_simIsJointInHybridOperation)(joint); }
    static void _simDisableDynamicTreeForManipulation(const void* object,bool disableFlag) { return SIM_API_SYMBOL(_simDisableDynamicTreeForManipulation)(object,disableFlag); }
    static bool _simIsShapeDynamicallyRespondable(const void* shape) { return SIM_API_SYMBOL(_simIsShapeDynamicallyRespondable)(shape); }
    static int _simGetDynamicCollisionMask(const void* shape) { return SIM_API_SYMBOL(_simGetDynamicCollisionMask)(shape); }
    static const void* _simGetLastParentForLocalGlobalCollidable(const void* shape) { return SIM_API_SYMBOL(_simGetLastParentForLocalGlobalCollidable)(shape); }
    static bool _simGetStartSleeping(const void* shape) { return SIM_API_SYMBOL(_simGetStartSleeping)(shape); }
    static bool _simGetWasPutToSleepOnce(const void* shape) { return SIM_API_SYMBOL(_simGetWasPutToSleepOnce)(shape); }
    static bool _simGetDynamicsFullRefreshFlag(const void* object) { return SIM_API_SYMBOL(_simGetDynamicsFullRefreshFlag)(object); }
    static void _simSetDynamicsFullRefreshFlag(const void* object,bool flag) { return SIM_API_SYMBOL(_simSetDynamicsFullRefreshFlag)(object,flag); }
    static void _simClearAdditionalForceAndTorque(const void* shape) { return SIM_API_SYMBOL(_simClearAdditionalForceAndTorque)(shape); }
    static int _simGetJointType(const void* joint) { return SIM_API_SYMBOL(_simGetJointType)(joint); }
    static const void* _simGetGeomWrapFromGeomProxy(const void* geomData) { return SIM_API_SYMBOL(_simGetGeomWrapFromGeomProxy)(geomData); }
    static int _simGetPurePrimitiveType(const void* geomInfo) { return SIM_API_SYMBOL(_simGetPurePrimitiveType)(geomInfo); }
    static bool _simIsGeomWrapGeometric(const void* geomInfo) { return SIM_API_SYMBOL(_simIsGeomWrapGeometric)(geomInfo); }
    static bool _simIsGeomWrapConvex(const void* geomInfo) { return SIM_API_SYMBOL(_simIsGeomWrapConvex)(geomInfo); }
    static int _simGetGeometricCount(const void* geomInfo) { return SIM_API_SYMBOL(_simGetGeometricCount)(geomInfo); }
    static void _simGetAllGeometrics(const void* geomInfo,void** allGeometrics) { return SIM_API_SYMBOL(_simGetAllGeometrics)(geomInfo,allGeometrics); }
    static void _simMakeDynamicAnnouncement(int announceType) { return SIM_API_SYMBOL(_simMakeDynamicAnnouncement)(announceType); }
    static int _simGetTimeDiffInMs(int previousTime) { return SIM_API_SYMBOL(_simGetTimeDiffInMs)(previousTime); }
    static bool _simDoEntitiesCollide(SIMHANDLE entity1ID,SIMHANDLE entity2ID,SIMHANDLE* cacheBuffer,bool overrideCollidableFlagIfShape1,bool overrideCollidableFlagIfShape2,bool pathPlanningRoutineCalling) { return SIM_API_SYMBOL(_simDoEntitiesCollide)(entity1ID,entity2ID,cacheBuffer,overrideCollidableFlagIfShape1,overrideCollidableFlagIfShape2,pathPlanningRoutineCalling); }
    static int _simGetJointDynCtrlMode(const void* joint) { return SIM_API_SYMBOL(_simGetJointDynCtrlMode)(joint); }
    static int simFloatingViewRemove(int floatingViewHandle) { return SIM_API_SYMBOL(simFloatingViewRemove)(floatingViewHandle); }
    #ifdef interfaceIsSinglePrecision
        static int simGetShapeViz(SIMHANDLE shapeHandle,int index,struct SShapeVizInfof* info) { return SIM_API_SYMBOL(simGetShapeViz)(shapeHandle,index,info); }
    #else
        static int simGetShapeViz(SIMHANDLE shapeHandle,int index,struct SShapeVizInfo* info) { return SIM_API_SYMBOL(simGetShapeViz)(shapeHandle,index,info); }
    #endif
    static int simTransformImage(unsigned char* image,const int* resolution,int options,const SIMDOUBLE* floatParams,const int* intParams,void* reserved) { return SIM_API_SYMBOL(simTransformImage)(image,resolution,options,floatParams,intParams,reserved); }
    static const SIMDOUBLE* simGetOctreeVoxels(SIMHANDLE octreeHandle,int* ptCnt,void* reserved) { return SIM_API_SYMBOL(simGetOctreeVoxels)(octreeHandle,ptCnt,reserved); }
    static const SIMDOUBLE* simGetPointCloudPoints(SIMHANDLE pointCloudHandle,int* ptCnt,void* reserved) { return SIM_API_SYMBOL(simGetPointCloudPoints)(pointCloudHandle,ptCnt,reserved); }
    static int simGetObjectMatrix(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,SIMDOUBLE* matrix) { return SIM_API_SYMBOL(simGetObjectMatrix)(objectHandle,relativeToObjectHandle,matrix); }
    static int simSetObjectMatrix(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,const SIMDOUBLE* matrix) { return SIM_API_SYMBOL(simSetObjectMatrix)(objectHandle,relativeToObjectHandle,matrix); }
    static int simGetObjectPose(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,SIMDOUBLE* pose) { return SIM_API_SYMBOL(simGetObjectPose)(objectHandle,relativeToObjectHandle,pose); }
    static int simSetObjectPose(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,const SIMDOUBLE* pose) { return SIM_API_SYMBOL(simSetObjectPose)(objectHandle,relativeToObjectHandle,pose); }
    static int simGetObjectPosition(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,SIMDOUBLE* position) { return SIM_API_SYMBOL(simGetObjectPosition)(objectHandle,relativeToObjectHandle,position); }
    static int simSetObjectPosition(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,const SIMDOUBLE* position) { return SIM_API_SYMBOL(simSetObjectPosition)(objectHandle,relativeToObjectHandle,position); }
    static int simGetObjectOrientation(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,SIMDOUBLE* eulerAngles) { return SIM_API_SYMBOL(simGetObjectOrientation)(objectHandle,relativeToObjectHandle,eulerAngles); }
    static int simSetObjectOrientation(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,const SIMDOUBLE* eulerAngles) { return SIM_API_SYMBOL(simSetObjectOrientation)(objectHandle,relativeToObjectHandle,eulerAngles); }
    static int simGetJointPosition(SIMHANDLE objectHandle,SIMDOUBLE* position) { return SIM_API_SYMBOL(simGetJointPosition)(objectHandle,position); }
    static int simSetJointPosition(SIMHANDLE objectHandle,SIMDOUBLE position) { return SIM_API_SYMBOL(simSetJointPosition)(objectHandle,position); }
    static int simSetJointTargetPosition(SIMHANDLE objectHandle,SIMDOUBLE targetPosition) { return SIM_API_SYMBOL(simSetJointTargetPosition)(objectHandle,targetPosition); }
    static int simGetJointTargetPosition(SIMHANDLE objectHandle,SIMDOUBLE* targetPosition) { return SIM_API_SYMBOL(simGetJointTargetPosition)(objectHandle,targetPosition); }
    static int simGetJointTargetForce(SIMHANDLE jointHandle,SIMDOUBLE* forceOrTorque) { return SIM_API_SYMBOL(simGetJointTargetForce)(jointHandle,forceOrTorque); }
    static int simSetJointTargetForce(SIMHANDLE objectHandle,SIMDOUBLE forceOrTorque,bool signedValue) { return SIM_API_SYMBOL(simSetJointTargetForce)(objectHandle,forceOrTorque,signedValue); }
    static int simGetObjectChildPose(SIMHANDLE objectHandle,SIMDOUBLE* pose) { return SIM_API_SYMBOL(simGetObjectChildPose)(objectHandle,pose); }
    static int simSetObjectChildPose(SIMHANDLE objectHandle,const SIMDOUBLE* pose) { return SIM_API_SYMBOL(simSetObjectChildPose)(objectHandle,pose); }
    static int simGetJointInterval(SIMHANDLE objectHandle,bool* cyclic,SIMDOUBLE* interval) { return SIM_API_SYMBOL(simGetJointInterval)(objectHandle,cyclic,interval); }
    static int simSetJointInterval(SIMHANDLE objectHandle,bool cyclic,const SIMDOUBLE* interval) { return SIM_API_SYMBOL(simSetJointInterval)(objectHandle,cyclic,interval); }
    static int simBuildIdentityMatrix(SIMDOUBLE* matrix) { return SIM_API_SYMBOL(simBuildIdentityMatrix)(matrix); }
    static int simBuildMatrix(const SIMDOUBLE* position,const SIMDOUBLE* eulerAngles,SIMDOUBLE* matrix) { return SIM_API_SYMBOL(simBuildMatrix)(position,eulerAngles,matrix); }
    static int simBuildPose(const SIMDOUBLE* position,const SIMDOUBLE* eulerAngles,SIMDOUBLE* pose) { return SIM_API_SYMBOL(simBuildPose)(position,eulerAngles,pose); }
    static int simGetEulerAnglesFromMatrix(const SIMDOUBLE* matrix,SIMDOUBLE* eulerAngles) { return SIM_API_SYMBOL(simGetEulerAnglesFromMatrix)(matrix,eulerAngles); }
    static int simInvertMatrix(SIMDOUBLE* matrix) { return SIM_API_SYMBOL(simInvertMatrix)(matrix); }
    static int simMultiplyMatrices(const SIMDOUBLE* matrixIn1,const SIMDOUBLE* matrixIn2,SIMDOUBLE* matrixOut) { return SIM_API_SYMBOL(simMultiplyMatrices)(matrixIn1,matrixIn2,matrixOut); }
    static int simMultiplyPoses(const SIMDOUBLE* poseIn1,const SIMDOUBLE* poseIn2,SIMDOUBLE* poseOut) { return SIM_API_SYMBOL(simMultiplyPoses)(poseIn1,poseIn2,poseOut); }
    static int simInvertPose(SIMDOUBLE* pose) { return SIM_API_SYMBOL(simInvertPose)(pose); }
    static int simInterpolatePoses(const SIMDOUBLE* poseIn1,const SIMDOUBLE* poseIn2,SIMDOUBLE interpolFactor,SIMDOUBLE* poseOut) { return SIM_API_SYMBOL(simInterpolatePoses)(poseIn1,poseIn2,interpolFactor,poseOut); }
    static int simPoseToMatrix(const SIMDOUBLE* poseIn,SIMDOUBLE* matrixOut) { return SIM_API_SYMBOL(simPoseToMatrix)(poseIn,matrixOut); }
    static int simMatrixToPose(const SIMDOUBLE* matrixIn,SIMDOUBLE* poseOut) { return SIM_API_SYMBOL(simMatrixToPose)(matrixIn,poseOut); }
    static int simInterpolateMatrices(const SIMDOUBLE* matrixIn1,const SIMDOUBLE* matrixIn2,SIMDOUBLE interpolFactor,SIMDOUBLE* matrixOut) { return SIM_API_SYMBOL(simInterpolateMatrices)(matrixIn1,matrixIn2,interpolFactor,matrixOut); }
    static int simTransformVector(const SIMDOUBLE* matrix,SIMDOUBLE* vect) { return SIM_API_SYMBOL(simTransformVector)(matrix,vect); }
    static SIMDOUBLE simGetSimulationTime() { return SIM_API_SYMBOL(simGetSimulationTime)(); }
    static SIMDOUBLE simGetSystemTime() { return SIM_API_SYMBOL(simGetSystemTime)(); }
    static int simHandleProximitySensor(SIMHANDLE sensorHandle,SIMDOUBLE* detectedPoint,SIMHANDLE* detectedObjectHandle,SIMDOUBLE* normalVector) { return SIM_API_SYMBOL(simHandleProximitySensor)(sensorHandle,detectedPoint,detectedObjectHandle,normalVector); }
    static int simReadProximitySensor(SIMHANDLE sensorHandle,SIMDOUBLE* detectedPoint,SIMHANDLE* detectedObjectHandle,SIMDOUBLE* normalVector) { return SIM_API_SYMBOL(simReadProximitySensor)(sensorHandle,detectedPoint,detectedObjectHandle,normalVector); }
    static int simHandleDynamics(SIMDOUBLE deltaTime) { return SIM_API_SYMBOL(simHandleDynamics)(deltaTime); }
    static int simCheckProximitySensor(SIMHANDLE sensorHandle,SIMHANDLE entityHandle,SIMDOUBLE* detectedPoint) { return SIM_API_SYMBOL(simCheckProximitySensor)(sensorHandle,entityHandle,detectedPoint); }
    static int simCheckProximitySensorEx(SIMHANDLE sensorHandle,SIMHANDLE entityHandle,int detectionMode,SIMDOUBLE detectionThreshold,SIMDOUBLE maxAngle,SIMDOUBLE* detectedPoint,SIMHANDLE* detectedObjectHandle,SIMDOUBLE* normalVector) { return SIM_API_SYMBOL(simCheckProximitySensorEx)(sensorHandle,entityHandle,detectionMode,detectionThreshold,maxAngle,detectedPoint,detectedObjectHandle,normalVector); }
    static int simCheckProximitySensorEx2(SIMHANDLE sensorHandle,SIMDOUBLE* vertexPointer,int itemType,int itemCount,int detectionMode,SIMDOUBLE detectionThreshold,SIMDOUBLE maxAngle,SIMDOUBLE* detectedPoint,SIMDOUBLE* normalVector) { return SIM_API_SYMBOL(simCheckProximitySensorEx2)(sensorHandle,vertexPointer,itemType,itemCount,detectionMode,detectionThreshold,maxAngle,detectedPoint,normalVector); }
    static int simCheckCollisionEx(SIMHANDLE entity1Handle,SIMHANDLE entity2Handle,SIMDOUBLE** intersectionSegments) { return SIM_API_SYMBOL(simCheckCollisionEx)(entity1Handle,entity2Handle,intersectionSegments); }
    static int simCheckDistance(SIMHANDLE entity1Handle,SIMHANDLE entity2Handle,SIMDOUBLE threshold,SIMDOUBLE* distanceData) { return SIM_API_SYMBOL(simCheckDistance)(entity1Handle,entity2Handle,threshold,distanceData); }
    static int simSetSimulationTimeStep(SIMDOUBLE timeStep) { return SIM_API_SYMBOL(simSetSimulationTimeStep)(timeStep); }
    static SIMDOUBLE simGetSimulationTimeStep() { return SIM_API_SYMBOL(simGetSimulationTimeStep)(); }
    static int simFloatingViewAdd(SIMDOUBLE posX,SIMDOUBLE posY,SIMDOUBLE sizeX,SIMDOUBLE sizeY,int options) { return SIM_API_SYMBOL(simFloatingViewAdd)(posX,posY,sizeX,sizeY,options); }
    static int simHandleGraph(SIMHANDLE graphHandle,SIMDOUBLE simulationTime) { return SIM_API_SYMBOL(simHandleGraph)(graphHandle,simulationTime); }
    static int simSetGraphStreamTransformation(SIMHANDLE graphHandle,int streamId,int trType,SIMDOUBLE mult,SIMDOUBLE off,int movingAvgPeriod) { return SIM_API_SYMBOL(simSetGraphStreamTransformation)(graphHandle,streamId,trType,mult,off,movingAvgPeriod); }
    static int simAddGraphCurve(SIMHANDLE graphHandle,const char* curveName,int dim,const int* streamIds,const SIMDOUBLE* defaultValues,const char* unitStr,int options,const float* color,int curveWidth) { return SIM_API_SYMBOL(simAddGraphCurve)(graphHandle,curveName,dim,streamIds,defaultValues,unitStr,options,color,curveWidth); }
    static int simSetGraphStreamValue(SIMHANDLE graphHandle,int streamId,SIMDOUBLE value) { return SIM_API_SYMBOL(simSetGraphStreamValue)(graphHandle,streamId,value); }
    static int simSetJointTargetVelocity(SIMHANDLE objectHandle,SIMDOUBLE targetVelocity) { return SIM_API_SYMBOL(simSetJointTargetVelocity)(objectHandle,targetVelocity); }
    static int simGetJointTargetVelocity(SIMHANDLE objectHandle,SIMDOUBLE* targetVelocity) { return SIM_API_SYMBOL(simGetJointTargetVelocity)(objectHandle,targetVelocity); }
    static int simScaleObjects(const SIMHANDLE* objectHandles,int objectCount,SIMDOUBLE scalingFactor,bool scalePositionsToo) { return SIM_API_SYMBOL(simScaleObjects)(objectHandles,objectCount,scalingFactor,scalePositionsToo); }
    static SIMHANDLE simAddDrawingObject(int objectType,SIMDOUBLE size,SIMDOUBLE duplicateTolerance,SIMHANDLE parentObjectHandle,int maxItemCount,const float* color,const float* setToNULL,const float* setToNULL2,const float* setToNULL3) { return SIM_API_SYMBOL(simAddDrawingObject)(objectType,size,duplicateTolerance,parentObjectHandle,maxItemCount,color,setToNULL,setToNULL2,setToNULL3); }
    static int simAddGraphStream(SIMHANDLE graphHandle,const char* streamName,const char* unitStr,int options,const float* color,SIMDOUBLE cyclicRange) { return SIM_API_SYMBOL(simAddGraphStream)(graphHandle,streamName,unitStr,options,color,cyclicRange); }
    static int simAddDrawingObjectItem(SIMHANDLE objectHandle,const SIMDOUBLE* itemData) { return SIM_API_SYMBOL(simAddDrawingObjectItem)(objectHandle,itemData); }
    static SIMDOUBLE simGetObjectSizeFactor(SIMHANDLE objectHandle) { return SIM_API_SYMBOL(simGetObjectSizeFactor)(objectHandle); }
    static int simReadForceSensor(SIMHANDLE objectHandle,SIMDOUBLE* forceVector,SIMDOUBLE* torqueVector) { return SIM_API_SYMBOL(simReadForceSensor)(objectHandle,forceVector,torqueVector); }
    static int simGetVelocity(SIMHANDLE shapeHandle,SIMDOUBLE* linearVelocity,SIMDOUBLE* angularVelocity) { return SIM_API_SYMBOL(simGetVelocity)(shapeHandle,linearVelocity,angularVelocity); }
    static int simGetObjectVelocity(SIMHANDLE objectHandle,SIMDOUBLE* linearVelocity,SIMDOUBLE* angularVelocity) { return SIM_API_SYMBOL(simGetObjectVelocity)(objectHandle,linearVelocity,angularVelocity); }
    static int simGetJointVelocity(SIMHANDLE jointHandle,SIMDOUBLE* velocity) { return SIM_API_SYMBOL(simGetJointVelocity)(jointHandle,velocity); }
    static int simAddForceAndTorque(SIMHANDLE shapeHandle,const SIMDOUBLE* force,const SIMDOUBLE* torque) { return SIM_API_SYMBOL(simAddForceAndTorque)(shapeHandle,force,torque); }
    static int simAddForce(SIMHANDLE shapeHandle,const SIMDOUBLE* position,const SIMDOUBLE* force) { return SIM_API_SYMBOL(simAddForce)(shapeHandle,position,force); }
    static int simSetObjectColor(SIMHANDLE objectHandle,int index,int colorComponent,const float* rgbData) { return SIM_API_SYMBOL(simSetObjectColor)(objectHandle,index,colorComponent,rgbData); }
    static int simGetObjectColor(SIMHANDLE objectHandle,int index,int colorComponent,float* rgbData) { return SIM_API_SYMBOL(simGetObjectColor)(objectHandle,index,colorComponent,rgbData); }
    static int simSetShapeColor(SIMHANDLE shapeHandle,const char* colorName,int colorComponent,const float* rgbData) { return SIM_API_SYMBOL(simSetShapeColor)(shapeHandle,colorName,colorComponent,rgbData); }
    static int simGetShapeColor(SIMHANDLE shapeHandle,const char* colorName,int colorComponent,float* rgbData) { return SIM_API_SYMBOL(simGetShapeColor)(shapeHandle,colorName,colorComponent,rgbData); }
    static int simGetContactInfo(int dynamicPass,SIMHANDLE objectHandle,int index,SIMHANDLE* objectHandles,SIMDOUBLE* contactInfo) { return SIM_API_SYMBOL(simGetContactInfo)(dynamicPass,objectHandle,index,objectHandles,contactInfo); }
    static int simAuxiliaryConsoleOpen(const char* title,int maxLines,int mode,const int* position,const int* size,const float* textColor,const float* backgroundColor) { return SIM_API_SYMBOL(simAuxiliaryConsoleOpen)(title,maxLines,mode,position,size,textColor,backgroundColor); }
    static SIMHANDLE simImportShape(int fileformat,const char* pathAndFilename,int options,SIMDOUBLE identicalVerticeTolerance,SIMDOUBLE scalingFactor) { return SIM_API_SYMBOL(simImportShape)(fileformat,pathAndFilename,options,identicalVerticeTolerance,scalingFactor); }
    static int simImportMesh(int fileformat,const char* pathAndFilename,int options,SIMDOUBLE identicalVerticeTolerance,SIMDOUBLE scalingFactor,SIMDOUBLE*** vertices,int** verticesSizes,int*** indices,int** indicesSizes,SIMDOUBLE*** reserved,char*** names) { return SIM_API_SYMBOL(simImportMesh)(fileformat,pathAndFilename,options,identicalVerticeTolerance,scalingFactor,vertices,verticesSizes,indices,indicesSizes,reserved,names); }
    static int simExportMesh(int fileformat,const char* pathAndFilename,int options,SIMDOUBLE scalingFactor,int elementCount,const SIMDOUBLE** vertices,const int* verticesSizes,const int** indices,const int* indicesSizes,SIMDOUBLE** reserved,const char** names) { return SIM_API_SYMBOL(simExportMesh)(fileformat,pathAndFilename,options,scalingFactor,elementCount,vertices,verticesSizes,indices,indicesSizes,reserved,names); }
    static SIMHANDLE simCreateShape(int options,double shadingAngle,const double* vertices,int verticesSize,const int* indices,int indicesSize,const double* normals,const float* textCoords,const unsigned char* texture,const int* textureResolution) { return SIM_API_SYMBOL(simCreateShape)(options,shadingAngle,vertices,verticesSize,indices,indicesSize,normals,textCoords,texture,textureResolution); }
    static SIMHANDLE simCreateMeshShape(int options,SIMDOUBLE shadingAngle,const SIMDOUBLE* vertices,int verticesSize,const int* indices,int indicesSize,SIMDOUBLE* reserved) { return SIM_API_SYMBOL(simCreateMeshShape)(options,shadingAngle,vertices,verticesSize,indices,indicesSize,reserved); }
    static SIMHANDLE simCreatePrimitiveShape(int primitiveType,const SIMDOUBLE* sizes,int options) { return SIM_API_SYMBOL(simCreatePrimitiveShape)(primitiveType,sizes,options); }
    static SIMHANDLE simCreateHeightfieldShape(int options,SIMDOUBLE shadingAngle,int xPointCount,int yPointCount,SIMDOUBLE xSize,const SIMDOUBLE* heights) { return SIM_API_SYMBOL(simCreateHeightfieldShape)(options,shadingAngle,xPointCount,yPointCount,xSize,heights); }
    static int simGetShapeMesh(SIMHANDLE shapeHandle,SIMDOUBLE** vertices,int* verticesSize,int** indices,int* indicesSize,SIMDOUBLE** normals) { return SIM_API_SYMBOL(simGetShapeMesh)(shapeHandle,vertices,verticesSize,indices,indicesSize,normals); }
    static SIMHANDLE simCreateJoint(int jointType,int jointMode,int options,const SIMDOUBLE* sizes,const SIMDOUBLE* reservedA,const SIMDOUBLE* reservedB) { return SIM_API_SYMBOL(simCreateJoint)(jointType,jointMode,options,sizes,reservedA,reservedB); }
    static SIMHANDLE simCreateDummy(SIMDOUBLE size,const float* reserved) { return SIM_API_SYMBOL(simCreateDummy)(size,reserved); }
    static SIMHANDLE simCreateScript(int scriptType,const char* scriptText, int options, const char* lang) { return SIM_API_SYMBOL(simCreateScript)(scriptType,scriptText,options,lang); }
    static int simGetObjectHierarchyOrder(SIMHANDLE objectHandle, int* totalSiblings) { return SIM_API_SYMBOL(simGetObjectHierarchyOrder)(objectHandle,totalSiblings); }
    static int simSetObjectHierarchyOrder(SIMHANDLE objectHandle, int order) { return SIM_API_SYMBOL(simSetObjectHierarchyOrder)(objectHandle,order); }
    static SIMHANDLE simCreateForceSensor(int options,const int* intParams,const SIMDOUBLE* floatParams,const SIMDOUBLE* reserved) { return SIM_API_SYMBOL(simCreateForceSensor)(options,intParams,floatParams,reserved); }
    static SIMHANDLE simCreateVisionSensor(int options,const int* intParams,const SIMDOUBLE* floatParams,const SIMDOUBLE* reserved) { return SIM_API_SYMBOL(simCreateVisionSensor)(options,intParams,floatParams,reserved); }
    static SIMHANDLE simCreateProximitySensor(int sensorType,int subType,int options,const int* intParams,const SIMDOUBLE* floatParams,const SIMDOUBLE* reserved) { return SIM_API_SYMBOL(simCreateProximitySensor)(sensorType,subType,options,intParams,floatParams,reserved); }
    static int simGetRotationAxis(const SIMDOUBLE* matrixStart,const SIMDOUBLE* matrixGoal,SIMDOUBLE* axis,SIMDOUBLE* angle) { return SIM_API_SYMBOL(simGetRotationAxis)(matrixStart,matrixGoal,axis,angle); }
    static int simRotateAroundAxis(const SIMDOUBLE* matrixIn,const SIMDOUBLE* axis,const SIMDOUBLE* axisPos,SIMDOUBLE angle,SIMDOUBLE* matrixOut) { return SIM_API_SYMBOL(simRotateAroundAxis)(matrixIn,axis,axisPos,angle,matrixOut); }
    static int simGetJointForce(SIMHANDLE jointHandle,SIMDOUBLE* forceOrTorque) { return SIM_API_SYMBOL(simGetJointForce)(jointHandle,forceOrTorque); }
    static int simCameraFitToView(SIMHANDLE viewHandleOrIndex,int objectCount,const SIMHANDLE* objectHandles,int options,SIMDOUBLE scaling) { return SIM_API_SYMBOL(simCameraFitToView)(viewHandleOrIndex,objectCount,objectHandles,options,scaling); }
    static int simHandleVisionSensor(SIMHANDLE visionSensorHandle,SIMDOUBLE** auxValues,int** auxValuesCount) { return SIM_API_SYMBOL(simHandleVisionSensor)(visionSensorHandle,auxValues,auxValuesCount); }
    static int simReadVisionSensor(SIMHANDLE visionSensorHandle,SIMDOUBLE** auxValues,int** auxValuesCount) { return SIM_API_SYMBOL(simReadVisionSensor)(visionSensorHandle,auxValues,auxValuesCount); }
    static int simCheckVisionSensor(SIMHANDLE visionSensorHandle,SIMHANDLE entityHandle,SIMDOUBLE** auxValues,int** auxValuesCount) { return SIM_API_SYMBOL(simCheckVisionSensor)(visionSensorHandle,entityHandle,auxValues,auxValuesCount); }
    static unsigned char* simGetVisionSensorImg(SIMHANDLE sensorHandle,int options,SIMDOUBLE rgbaCutOff,const int* pos,const int* size,int* resolution) { return SIM_API_SYMBOL(simGetVisionSensorImg)(sensorHandle,options,rgbaCutOff,pos,size,resolution); }
    static int simGetVisionSensorRes(SIMHANDLE visionSensorHandle,int* resolution) { return SIM_API_SYMBOL(simGetVisionSensorRes)(visionSensorHandle,resolution); }
    static int simGetObjectQuaternion(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,SIMDOUBLE* quaternion) { return SIM_API_SYMBOL(simGetObjectQuaternion)(objectHandle,relativeToObjectHandle,quaternion); }
    static int simSetObjectQuaternion(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,const SIMDOUBLE* quaternion) { return SIM_API_SYMBOL(simSetObjectQuaternion)(objectHandle,relativeToObjectHandle,quaternion); }
    static SIMHANDLE simConvexDecompose(SIMHANDLE shapeHandle,int options,const int* intParams,const SIMDOUBLE* floatParams) { return SIM_API_SYMBOL(simConvexDecompose)(shapeHandle,options,intParams,floatParams); }
    static int simWriteTexture(SIMHANDLE textureId,int options,const char* data,int posX,int posY,int sizeX,int sizeY,SIMDOUBLE interpol) { return SIM_API_SYMBOL(simWriteTexture)(textureId,options,data,posX,posY,sizeX,sizeY,interpol); }
    static SIMHANDLE simCreateTexture(const char* fileName,int options,const SIMDOUBLE* planeSizes,const SIMDOUBLE* scalingUV,const SIMDOUBLE* xy_g,int fixedResolution,int* textureId,int* resolution,const void* reserved) { return SIM_API_SYMBOL(simCreateTexture)(fileName,options,planeSizes,scalingUV,xy_g,fixedResolution,textureId,resolution,reserved); }
    static int simGetShapeGeomInfo(SIMHANDLE shapeHandle,int* intData,SIMDOUBLE* floatData,void* reserved) { return SIM_API_SYMBOL(simGetShapeGeomInfo)(shapeHandle,intData,floatData,reserved); }
    static int simScaleObject(SIMHANDLE objectHandle,SIMDOUBLE xScale,SIMDOUBLE yScale,SIMDOUBLE zScale,int options) { return SIM_API_SYMBOL(simScaleObject)(objectHandle,xScale,yScale,zScale,options); }
    static int simSetShapeTexture(SIMHANDLE shapeHandle,SIMHANDLE textureId,int mappingMode,int options,const SIMDOUBLE* uvScaling,const SIMDOUBLE* position,const SIMDOUBLE* orientation) { return SIM_API_SYMBOL(simSetShapeTexture)(shapeHandle,textureId,mappingMode,options,uvScaling,position,orientation); }
    static int simGetQHull(const SIMDOUBLE* inVertices,int inVerticesL,SIMDOUBLE** verticesOut,int* verticesOutL,int** indicesOut,int* indicesOutL,int reserved1,const SIMDOUBLE* reserved2) { return SIM_API_SYMBOL(simGetQHull)(inVertices,inVerticesL,verticesOut,verticesOutL,indicesOut,indicesOutL,reserved1,reserved2); }
    static int simGetDecimatedMesh(const SIMDOUBLE* inVertices,int inVerticesL,const int* inIndices,int inIndicesL,SIMDOUBLE** verticesOut,int* verticesOutL,int** indicesOut,int* indicesOutL,SIMDOUBLE decimationPercent,int reserved1,const SIMDOUBLE* reserved2) { return SIM_API_SYMBOL(simGetDecimatedMesh)(inVertices,inVerticesL,inIndices,inIndicesL,verticesOut,verticesOutL,indicesOut,indicesOutL,decimationPercent,reserved1,reserved2); }
    static int simComputeMassAndInertia(SIMHANDLE shapeHandle,SIMDOUBLE density) { return SIM_API_SYMBOL(simComputeMassAndInertia)(shapeHandle,density); }
    static SIMHANDLE simCreateOctree(SIMDOUBLE voxelSize,int options,SIMDOUBLE pointSize,void* reserved) { return SIM_API_SYMBOL(simCreateOctree)(voxelSize,options,pointSize,reserved); }
    static SIMHANDLE simCreatePointCloud(SIMDOUBLE maxVoxelSize,int maxPtCntPerVoxel,int options,SIMDOUBLE pointSize,void* reserved) { return SIM_API_SYMBOL(simCreatePointCloud)(maxVoxelSize,maxPtCntPerVoxel,options,pointSize,reserved); }
    static int simSetPointCloudOptions(SIMHANDLE pointCloudHandle,SIMDOUBLE maxVoxelSize,int maxPtCntPerVoxel,int options,SIMDOUBLE pointSize,void* reserved) { return SIM_API_SYMBOL(simSetPointCloudOptions)(pointCloudHandle,maxVoxelSize,maxPtCntPerVoxel,options,pointSize,reserved); }
    static int simGetPointCloudOptions(SIMHANDLE pointCloudHandle,SIMDOUBLE* maxVoxelSize,int* maxPtCntPerVoxel,int* options,SIMDOUBLE* pointSize,void* reserved) { return SIM_API_SYMBOL(simGetPointCloudOptions)(pointCloudHandle,maxVoxelSize,maxPtCntPerVoxel,options,pointSize,reserved); }
    static int simInsertVoxelsIntoOctree(SIMHANDLE octreeHandle,int options,const SIMDOUBLE* pts,int ptCnt,const unsigned char* color,const unsigned int* tag,void* reserved) { return SIM_API_SYMBOL(simInsertVoxelsIntoOctree)(octreeHandle,options,pts,ptCnt,color,tag,reserved); }
    static int simRemoveVoxelsFromOctree(SIMHANDLE octreeHandle,int options,const SIMDOUBLE* pts,int ptCnt,void* reserved) { return SIM_API_SYMBOL(simRemoveVoxelsFromOctree)(octreeHandle,options,pts,ptCnt,reserved); }
    static int simInsertPointsIntoPointCloud(SIMHANDLE pointCloudHandle,int options,const SIMDOUBLE* pts,int ptCnt,const unsigned char* color,void* optionalValues) { return SIM_API_SYMBOL(simInsertPointsIntoPointCloud)(pointCloudHandle,options,pts,ptCnt,color,optionalValues); }
    static int simRemovePointsFromPointCloud(SIMHANDLE pointCloudHandle,int options,const SIMDOUBLE* pts,int ptCnt,SIMDOUBLE tolerance,void* reserved) { return SIM_API_SYMBOL(simRemovePointsFromPointCloud)(pointCloudHandle,options,pts,ptCnt,tolerance,reserved); }
    static int simIntersectPointsWithPointCloud(SIMHANDLE pointCloudHandle,int options,const SIMDOUBLE* pts,int ptCnt,SIMDOUBLE tolerance,void* reserved) { return SIM_API_SYMBOL(simIntersectPointsWithPointCloud)(pointCloudHandle,options,pts,ptCnt,tolerance,reserved); }
    static int simInsertObjectIntoPointCloud(SIMHANDLE pointCloudHandle,SIMHANDLE objectHandle,int options,SIMDOUBLE gridSize,const unsigned char* color,void* optionalValues) { return SIM_API_SYMBOL(simInsertObjectIntoPointCloud)(pointCloudHandle,objectHandle,options,gridSize,color,optionalValues); }
    static int simSubtractObjectFromPointCloud(SIMHANDLE pointCloudHandle,SIMHANDLE objectHandle,int options,SIMDOUBLE tolerance,void* reserved) { return SIM_API_SYMBOL(simSubtractObjectFromPointCloud)(pointCloudHandle,objectHandle,options,tolerance,reserved); }
    static int simCheckOctreePointOccupancy(SIMHANDLE octreeHandle,int options,const SIMDOUBLE* points,int ptCnt,unsigned int* tag,unsigned long long int* location,void* reserved) { return SIM_API_SYMBOL(simCheckOctreePointOccupancy)(octreeHandle,options,points,ptCnt,tag,location,reserved); }
    static int simApplyTexture(SIMHANDLE shapeHandle,const SIMDOUBLE* textureCoordinates,int textCoordSize,const unsigned char* texture,const int* textureResolution,int options) { return SIM_API_SYMBOL(simApplyTexture)(shapeHandle,textureCoordinates,textCoordSize,texture,textureResolution,options); }
    static int simSetJointDependency(SIMHANDLE jointHandle,SIMHANDLE masterJointHandle,SIMDOUBLE offset,SIMDOUBLE multCoeff) { return SIM_API_SYMBOL(simSetJointDependency)(jointHandle,masterJointHandle,offset,multCoeff); }
    static int simGetJointDependency(SIMHANDLE jointHandle,SIMHANDLE* masterJointHandle,SIMDOUBLE* offset,SIMDOUBLE* multCoeff) { return SIM_API_SYMBOL(simGetJointDependency)(jointHandle,masterJointHandle,offset,multCoeff); }
    static int simGetShapeMass(SIMHANDLE shapeHandle,SIMDOUBLE* mass) { return SIM_API_SYMBOL(simGetShapeMass)(shapeHandle,mass); }
    static int simSetShapeMass(SIMHANDLE shapeHandle,SIMDOUBLE mass) { return SIM_API_SYMBOL(simSetShapeMass)(shapeHandle,mass); }
    static int simGetShapeInertia(SIMHANDLE shapeHandle,SIMDOUBLE* inertiaMatrix,SIMDOUBLE* transformationMatrix) { return SIM_API_SYMBOL(simGetShapeInertia)(shapeHandle,inertiaMatrix,transformationMatrix); }
    static int simSetShapeInertia(SIMHANDLE shapeHandle,const SIMDOUBLE* inertiaMatrix,const SIMDOUBLE* transformationMatrix) { return SIM_API_SYMBOL(simSetShapeInertia)(shapeHandle,inertiaMatrix,transformationMatrix); }
    static SIMHANDLE simGenerateShapeFromPath(const SIMDOUBLE* path,int pathSize,const SIMDOUBLE* section,int sectionSize,int options,const SIMDOUBLE* upVector,SIMDOUBLE reserved) { return SIM_API_SYMBOL(simGenerateShapeFromPath)(path,pathSize,section,sectionSize,options,upVector,reserved); }
    static SIMDOUBLE simGetClosestPosOnPath(const SIMDOUBLE* path,int pathSize,const SIMDOUBLE* pathLengths,const SIMDOUBLE* absPt) { return SIM_API_SYMBOL(simGetClosestPosOnPath)(path,pathSize,pathLengths,absPt); }
    static void _simGetObjectLocalTransformation(const void* object,SIMDOUBLE* pos,SIMDOUBLE* quat,bool excludeFirstJointTransformation) { return SIM_API_SYMBOL(_simGetObjectLocalTransformation)(object,pos,quat,excludeFirstJointTransformation); }
    static void _simSetObjectLocalTransformation(void* object,const SIMDOUBLE* pos,const SIMDOUBLE* quat,SIMDOUBLE simTime) { return SIM_API_SYMBOL(_simSetObjectLocalTransformation)(object,pos,quat,simTime); }
    static void _simDynReportObjectCumulativeTransformation(void* object,const SIMDOUBLE* pos,const SIMDOUBLE* quat,SIMDOUBLE simTime) { return SIM_API_SYMBOL(_simDynReportObjectCumulativeTransformation)(object,pos,quat,simTime); }
    static void _simSetObjectCumulativeTransformation(void* object,const SIMDOUBLE* pos,const SIMDOUBLE* quat,bool keepChildrenInPlace) { return SIM_API_SYMBOL(_simSetObjectCumulativeTransformation)(object,pos,quat,keepChildrenInPlace); }
    static void _simGetObjectCumulativeTransformation(const void* object,SIMDOUBLE* pos,SIMDOUBLE* quat,bool excludeFirstJointTransformation) { return SIM_API_SYMBOL(_simGetObjectCumulativeTransformation)(object,pos,quat,excludeFirstJointTransformation); }
    static void _simSetJointVelocity(const void* joint,SIMDOUBLE vel) { return SIM_API_SYMBOL(_simSetJointVelocity)(joint,vel); }
    static void _simSetJointPosition(const void* joint,SIMDOUBLE pos) { return SIM_API_SYMBOL(_simSetJointPosition)(joint,pos); }
    static SIMDOUBLE _simGetJointPosition(const void* joint) { return SIM_API_SYMBOL(_simGetJointPosition)(joint); }
    static void _simSetDynamicMotorPositionControlTargetPosition(const void* joint,SIMDOUBLE pos) { return SIM_API_SYMBOL(_simSetDynamicMotorPositionControlTargetPosition)(joint,pos); }
    static void _simGetInitialDynamicVelocity(const void* shape,SIMDOUBLE* vel) { return SIM_API_SYMBOL(_simGetInitialDynamicVelocity)(shape,vel); }
    static void _simSetInitialDynamicVelocity(void* shape,const SIMDOUBLE* vel) { return SIM_API_SYMBOL(_simSetInitialDynamicVelocity)(shape,vel); }
    static void _simGetInitialDynamicAngVelocity(const void* shape,SIMDOUBLE* angularVel) { return SIM_API_SYMBOL(_simGetInitialDynamicAngVelocity)(shape,angularVel); }
    static void _simSetInitialDynamicAngVelocity(void* shape,const SIMDOUBLE* angularVel) { return SIM_API_SYMBOL(_simSetInitialDynamicAngVelocity)(shape,angularVel); }
    static void _simSetShapeDynamicVelocity(void* shape,const SIMDOUBLE* linear,const SIMDOUBLE* angular,SIMDOUBLE simTime) { return SIM_API_SYMBOL(_simSetShapeDynamicVelocity)(shape,linear,angular,simTime); }
    static void _simGetAdditionalForceAndTorque(const void* shape,SIMDOUBLE* force,SIMDOUBLE* torque) { return SIM_API_SYMBOL(_simGetAdditionalForceAndTorque)(shape,force,torque); }
    static bool _simGetJointPositionInterval(const void* joint,SIMDOUBLE* minValue,SIMDOUBLE* rangeValue) { return SIM_API_SYMBOL(_simGetJointPositionInterval)(joint,minValue,rangeValue); }
    static SIMDOUBLE _simGetDynamicMotorTargetPosition(const void* joint) { return SIM_API_SYMBOL(_simGetDynamicMotorTargetPosition)(joint); }
    static SIMDOUBLE _simGetDynamicMotorTargetVelocity(const void* joint) { return SIM_API_SYMBOL(_simGetDynamicMotorTargetVelocity)(joint); }
    static SIMDOUBLE _simGetDynamicMotorMaxForce(const void* joint) { return SIM_API_SYMBOL(_simGetDynamicMotorMaxForce)(joint); }
    static SIMDOUBLE _simGetDynamicMotorUpperLimitVelocity(const void* joint) { return SIM_API_SYMBOL(_simGetDynamicMotorUpperLimitVelocity)(joint); }
    static void _simSetDynamicMotorReflectedPositionFromDynamicEngine(void* joint,SIMDOUBLE pos,SIMDOUBLE simTime) { return SIM_API_SYMBOL(_simSetDynamicMotorReflectedPositionFromDynamicEngine)(joint,pos,simTime); }
    static void _simSetJointSphericalTransformation(void* joint,const SIMDOUBLE* quat,SIMDOUBLE simTime) { return SIM_API_SYMBOL(_simSetJointSphericalTransformation)(joint,quat,simTime); }
    static void _simAddForceSensorCumulativeForcesAndTorques(void* forceSensor,const SIMDOUBLE* force,const SIMDOUBLE* torque,int totalPassesCount,SIMDOUBLE simTime) { return SIM_API_SYMBOL(_simAddForceSensorCumulativeForcesAndTorques)(forceSensor,force,torque,totalPassesCount,simTime); }
    static void _simAddJointCumulativeForcesOrTorques(void* joint,SIMDOUBLE forceOrTorque,int totalPassesCount,SIMDOUBLE simTime) { return SIM_API_SYMBOL(_simAddJointCumulativeForcesOrTorques)(joint,forceOrTorque,totalPassesCount,simTime); }
    static SIMDOUBLE _simGetMass(const void* geomInfo) { return SIM_API_SYMBOL(_simGetMass)(geomInfo); }
    static SIMDOUBLE _simGetLocalInertiaInfo(const void* object,SIMDOUBLE* pos,SIMDOUBLE* quat,SIMDOUBLE* diagI) { return SIM_API_SYMBOL(_simGetLocalInertiaInfo)(object,pos,quat,diagI); }
    static void _simGetPurePrimitiveSizes(const void* geometric,SIMDOUBLE* sizes) { return SIM_API_SYMBOL(_simGetPurePrimitiveSizes)(geometric,sizes); }
    static void _simGetVerticesLocalFrame(const void* shape,const void* geometric,SIMDOUBLE* pos,SIMDOUBLE* quat) { return SIM_API_SYMBOL(_simGetVerticesLocalFrame)(shape,geometric,pos,quat); }
    static const SIMDOUBLE* _simGetHeightfieldData(const void* geometric,int* xCount,int* yCount,SIMDOUBLE* minHeight,SIMDOUBLE* maxHeight) { return SIM_API_SYMBOL(_simGetHeightfieldData)(geometric,xCount,yCount,minHeight,maxHeight); }
    static void _simGetCumulativeMeshes(const void* shape,const void* geomInfo,SIMDOUBLE** vertices,int* verticesSize,int** indices,int* indicesSize) { return SIM_API_SYMBOL(_simGetCumulativeMeshes)(shape,geomInfo,vertices,verticesSize,indices,indicesSize); }
    static void _simGetGravity(SIMDOUBLE* gravity) { return SIM_API_SYMBOL(_simGetGravity)(gravity); }
    static bool _simGetDistanceBetweenEntitiesIfSmaller(SIMHANDLE entity1ID,SIMHANDLE entity2ID,SIMDOUBLE* distance,SIMDOUBLE* ray,int* cacheBuffer,bool overrideMeasurableFlagIfNonCollection1,bool overrideMeasurableFlagIfNonCollection2,bool pathPlanningRoutineCalling) { return SIM_API_SYMBOL(_simGetDistanceBetweenEntitiesIfSmaller)(entity1ID,entity2ID,distance,ray,cacheBuffer,overrideMeasurableFlagIfNonCollection1,overrideMeasurableFlagIfNonCollection2,pathPlanningRoutineCalling); }
    static int _simHandleJointControl(const void* joint,int auxV,const int* inputValuesInt,const SIMDOUBLE* inputValuesFloat,SIMDOUBLE* outputValues) { return SIM_API_SYMBOL(_simHandleJointControl)(joint,auxV,inputValuesInt,inputValuesFloat,outputValues); }
    static int _simHandleCustomContact(SIMHANDLE objHandle1,SIMHANDLE objHandle2,int engine,int* dataInt,SIMDOUBLE* dataFloat) { return SIM_API_SYMBOL(_simHandleCustomContact)(objHandle1,objHandle2,engine,dataInt,dataFloat); }
    static SIMDOUBLE _simGetPureHollowScaling(const void* geometric) { return SIM_API_SYMBOL(_simGetPureHollowScaling)(geometric); }
    static void _simDynCallback(const int* intData,const SIMDOUBLE* floatData) { return SIM_API_SYMBOL(_simDynCallback)(intData,floatData); }
#else
    #define SIM_API_SYMBOL(x) x
#endif // SIM_API_SYMBOL

int getSimProcAddresses(LIBRARY lib);
LIBRARY loadSimLibrary(const char* pathAndFilename);
void unloadSimLibrary(LIBRARY lib);
FARPROC _getProcAddress(LIBRARY lib,const char* funcName);
int simAddLog(const char* pluginName,int verbosityLevel,const char* logMsg);

typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetBoolProperty))(long long int target, const char* pName, int pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetBoolProperty))(long long int target, const char* pName, int* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetIntProperty))(long long int target, const char* pName, int pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetIntProperty))(long long int target, const char* pName, int* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetLongProperty))(long long int target, const char* pName, long long int pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetLongProperty))(long long int target, const char* pName, long long int* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetFloatProperty))(long long int target, const char* pName, double pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetFloatProperty))(long long int target, const char* pName, double* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetStringProperty))(long long int target, const char* pName, const char* pState);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetStringProperty))(long long int target, const char* pName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetTableProperty))(long long int target, const char* pName, const char* buffer, int bufferL);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetTableProperty))(long long int target, const char* pName, int* bufferL);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetBufferProperty))(long long int target, const char* pName, const char* buffer, int bufferL);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetBufferProperty))(long long int target, const char* pName, int* bufferL);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetIntArray2Property))(long long int target, const char* pName, const int* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetIntArray2Property))(long long int target, const char* pName, int* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetVector2Property))(long long int target, const char* pName, const double* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetVector2Property))(long long int target, const char* pName, double* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetVector3Property))(long long int target, const char* pName, const double* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetVector3Property))(long long int target, const char* pName, double* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetQuaternionProperty))(long long int target, const char* pName, const double* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetQuaternionProperty))(long long int target, const char* pName, double* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetPoseProperty))(long long int target, const char* pName, const double* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetPoseProperty))(long long int target, const char* pName, double* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetColorProperty))(long long int target, const char* pName, const float* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetColorProperty))(long long int target, const char* pName, float* pState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetFloatArrayProperty))(long long int target, const char* pName, const double* v, int vL);
typedef double* (__cdecl *SIM_API_SYMBOL(ptrSimGetFloatArrayProperty))(long long int target, const char* pName, int* vL);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetIntArrayProperty))(long long int target, const char* pName, const int* v, int vL);
typedef int* (__cdecl *SIM_API_SYMBOL(ptrSimGetIntArrayProperty))(long long int target, const char* pName, int* vL);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveProperty))(long long int target, const char* pName);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetPropertyName))(long long int target, int index, SPropertyOptions* options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetPropertyInfo))(long long int target, const char* pName, SPropertyInfo* infos, SPropertyOptions* options);

typedef void (__cdecl *SIM_API_SYMBOL(ptrSimRegCallback))(int index, void* cb);
typedef void (__cdecl *SIM_API_SYMBOL(ptrSimRunGui))(int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimInitialize))(const char* appDir,int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimDeinitialize))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPostExitRequest))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetExitRequest))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimLoop))(void(*callback)(),int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimTest))(int mode,void* ptr1,void* ptr2,void* ptr3);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddLog))(const char* pluginName,int verbosityLevel,const char* logMsg);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetSimulatorMessage))(int* messageID,int* auxiliaryData,int* returnedDataSize);
typedef void* (__cdecl *SIM_API_SYMBOL(ptrSimGetMainWindow))(int type);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetLastError))();
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetLastInfo))();
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimGetObject))(const char* objectPath,int index,SIMHANDLE proxy,int options);
typedef long long int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectUid))(SIMHANDLE objectHandle);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectFromUid))(long long int uid,int options);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimGetScriptHandleEx))(int scriptType,SIMHANDLE objHandle,const char* scriptName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveObjects))(const SIMHANDLE* objectHandles,int count);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveModel))(SIMHANDLE objectHandle);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectAlias))(SIMHANDLE objectHandle,int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectAlias))(SIMHANDLE objectHandle,const char* objectAlias,int options);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectParent))(SIMHANDLE objectHandle);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectChild))(SIMHANDLE objectHandle,int index);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectParent))(SIMHANDLE objectHandle,SIMHANDLE parentObjectHandle,bool keepInPlace);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectType))(SIMHANDLE objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetJointType))(SIMHANDLE objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimReservedCommand))(int v,int w);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetSimulationState))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimLoadScene))(const char* filename);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCloseScene))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSaveScene))(const char* filename);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimLoadModel))(const char* filename);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSaveModel))(SIMHANDLE baseOfModelHandle,const char* filename);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimDoesFileExist))(const char* filename);
typedef SIMHANDLE* (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectSel))(int* cnt);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectSel))(const SIMHANDLE* handles,int cnt);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimResetScript))(SIMHANDLE scriptHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRefreshDialogs))(int refreshDegree);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimResetProximitySensor))(SIMHANDLE sensorHandle);
typedef void* (__cdecl *SIM_API_SYMBOL(ptrSimCreateBuffer))(int size);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimReleaseBuffer))(const void* buffer);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCheckCollision))(SIMHANDLE entity1Handle,SIMHANDLE entity2Handle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetRealTimeSimulation))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimStartSimulation))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimStopSimulation))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPauseSimulation))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAdjustView))(int viewHandleOrIndex,SIMHANDLE associatedViewableObjectHandle,int options,const char* viewLabel);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetLastError))(const char* setToNullptr,const char* errorMessage);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimResetGraph))(SIMHANDLE graphHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimDestroyGraphCurve))(SIMHANDLE graphHandle,SIMHANDLE curveId);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimDuplicateGraphCurveToStatic))(SIMHANDLE graphHandle,SIMHANDLE curveId,const char* curveName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetNavigationMode))(int navigationMode);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetNavigationMode))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetPage))(int index);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetPage))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRegisterScriptCallbackFunction))(const char* func,const char* reserved_setToNull,void(*callBack)(struct SScriptCallBack* cb));
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRegisterScriptVariable))(const char* var,const char* value,SIMHANDLE stackHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRegisterScriptFuncHook))(SIMHANDLE scriptHandle,const char* funcToHook,const char* userFunction,bool executeBefore,int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCopyPasteObjects))(SIMHANDLE* objectHandles,int objectCount,int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveDrawingObject))(SIMHANDLE objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAnnounceSceneContentChange))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetExplicitHandling))(SIMHANDLE objectHandle,int explicitFlags);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetExplicitHandling))(SIMHANDLE objectHandle);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimGetLinkDummy))(SIMHANDLE dummyHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetLinkDummy))(SIMHANDLE dummyHandle,SIMHANDLE linkedDummyHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimResetDynamicObject))(SIMHANDLE objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetJointMode))(SIMHANDLE jointHandle,int jointMode,int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetJointMode))(SIMHANDLE jointHandle,int* options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSerialOpen))(const char* portString,int baudRate,void* reserved1,void* reserved2);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSerialClose))(int portHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSerialSend))(int portHandle,const char* data,int dataLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSerialRead))(int portHandle,char* buffer,int dataLengthToRead);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSerialCheck))(int portHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAuxiliaryConsoleClose))(int consoleHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAuxiliaryConsoleShow))(int consoleHandle,bool showState);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAuxiliaryConsolePrint))(int consoleHandle,const char* text);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimIsHandle))(SIMHANDLE generalObjectHandle,int generalObjectType);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimResetVisionSensor))(SIMHANDLE visionSensorHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetVisionSensorImg))(SIMHANDLE sensorHandle,const unsigned char* img,int options,const int* pos,const int* size);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRuckigRemove))(int objHandle);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimGroupShapes))(const SIMHANDLE* shapeHandles,int shapeCount);
typedef SIMHANDLE* (__cdecl *SIM_API_SYMBOL(ptrSimUngroupShape))(SIMHANDLE shapeHandle,int* shapeCount);
typedef void (__cdecl *SIM_API_SYMBOL(ptrSimQuitSimulator))(bool ignoredArgument);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetShapeMaterial))(SIMHANDLE shapeHandle,SIMHANDLE materialIdOrShapeHandle);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimGetTextureId))(const char* textureName,int* resolution);
typedef unsigned char* (__cdecl *SIM_API_SYMBOL(ptrSimReadTexture))(SIMHANDLE textureId,int options,int posX,int posY,int sizeX,int sizeY);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimGetObjects))(int index,int objectType);
typedef SIMHANDLE* (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectsInTree))(SIMHANDLE treeBaseHandle,int objectType,int options,int* objectCount);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimGetShapeTextureId))(SIMHANDLE shapeHandle);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreateCollectionEx))(int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddItemToCollection))(SIMHANDLE collectionHandle,int what,SIMHANDLE objectHandle,int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimDestroyCollection))(SIMHANDLE collectionHandle);
typedef SIMHANDLE* (__cdecl *SIM_API_SYMBOL(ptrSimGetCollectionObjects))(SIMHANDLE collectionHandle,int* objectCount);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAlignShapeBB))(SIMHANDLE shapeHandle,const double* pose);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRelocateShapeFrame))(SIMHANDLE shapeHandle,const double* pose);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSaveImage))(const unsigned char* image,const int* resolution,int options,const char* filename,int quality,void* reserved);
typedef unsigned char* (__cdecl *SIM_API_SYMBOL(ptrSimLoadImage))(int* resolution,int options,const char* filename,void* reserved);
typedef unsigned char* (__cdecl *SIM_API_SYMBOL(ptrSimGetScaledImage))(const unsigned char* imageIn,const int* resolutionIn,int* resolutionOut,int options,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCallScriptFunctionEx))(SIMHANDLE scriptHandleOrType,const char* functionNameAtScriptName,SIMHANDLE stackId);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetExtensionString))(SIMHANDLE objectHandle,int index,const char* key);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreateStack))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimReleaseStack))(SIMHANDLE stackHandle);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCopyStack))(SIMHANDLE stackHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushNullOntoStack))(SIMHANDLE stackHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushBoolOntoStack))(SIMHANDLE stackHandle,bool value);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushInt32OntoStack))(SIMHANDLE stackHandle,int value);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushInt64OntoStack))(SIMHANDLE stackHandle,long long int value);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushTextOntoStack))(SIMHANDLE stackHandle,const char* value);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushStringOntoStack))(SIMHANDLE stackHandle,const char* value,int stringSize);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushBufferOntoStack))(SIMHANDLE stackHandle,const char* value,int stringSize);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushUInt8TableOntoStack))(SIMHANDLE stackHandle,const unsigned char* values,int valueCnt);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushInt32TableOntoStack))(SIMHANDLE stackHandle,const int* values,int valueCnt);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushInt64TableOntoStack))(SIMHANDLE stackHandle,const long long int* values,int valueCnt);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushTableOntoStack))(SIMHANDLE stackHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimInsertDataIntoStackTable))(SIMHANDLE stackHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackSize))(SIMHANDLE stackHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPopStackItem))(SIMHANDLE stackHandle,int count);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimMoveStackItemToTop))(SIMHANDLE stackHandle,int cIndex);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackItemType))(SIMHANDLE stackHandle,int cIndex);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackStringType))(SIMHANDLE stackHandle,int cIndex);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackBoolValue))(SIMHANDLE stackHandle,bool* boolValue);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackInt32Value))(SIMHANDLE stackHandle,int* numberValue);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackInt64Value))(SIMHANDLE stackHandle,long long int* numberValue);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetStackStringValue))(SIMHANDLE stackHandle,int* stringSize);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackTableInfo))(SIMHANDLE stackHandle,int infoType);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackUInt8Table))(SIMHANDLE stackHandle,unsigned char* array,int count);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackInt32Table))(SIMHANDLE stackHandle,int* array,int count);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackInt64Table))(SIMHANDLE stackHandle,long long int* array,int count);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimUnfoldStackTable))(SIMHANDLE stackHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimDebugStack))(SIMHANDLE stackHandle,int cIndex);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimInsertObjectIntoOctree))(SIMHANDLE octreeHandle,SIMHANDLE objectHandle,int options,const unsigned char* color,unsigned int tag,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSubtractObjectFromOctree))(SIMHANDLE octreeHandle,SIMHANDLE objectHandle,int options,void* reserved);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimOpenTextEditor))(const char* initText,const char* xml,int* various);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimPackTable))(SIMHANDLE stackHandle,int* bufferSize);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimUnpackTable))(SIMHANDLE stackHandle,const char* buffer,int bufferSize);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetReferencedHandles))(SIMHANDLE objectHandle,int count,const SIMHANDLE* referencedHandles,const char* tag,const int* reserved2);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetReferencedHandles))(SIMHANDLE objectHandle,SIMHANDLE** referencedHandles,const char* tag,SIMHANDLE** reserved2);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimExecuteScriptString))(SIMHANDLE scriptHandle,const char* stringToExecute,SIMHANDLE stackHandle);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetApiFunc))(SIMHANDLE scriptHandle,const char* apiWord);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetApiInfo))(SIMHANDLE scriptHandle,const char* apiWord);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetPluginInfo))(const char* pluginName,int infoType,const char* stringInfo,int intInfo);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetPluginInfo))(const char* pluginName,int infoType,char** stringInfo,int* intInfo);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetPluginName))(int index);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimEventNotification))(const char* event);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimIsDynamicallyEnabled))(SIMHANDLE objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimInitScript))(SIMHANDLE scriptHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimModuleEntry))(int handle,const char* label,int state);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCheckExecAuthorization))(const char* what,const char* args);
/* ------------------------------------------------------- */
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushFloatOntoStack))(SIMHANDLE stackHandle,float value);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushFloatTableOntoStack))(SIMHANDLE stackHandle,const float* values,int valueCnt);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackFloatValue))(SIMHANDLE stackHandle,float* numberValue);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackFloatTable))(SIMHANDLE stackHandle,float* array,int count);
typedef float* (__cdecl *SIM_API_SYMBOL(ptrSimGetVisionSensorDepth))(SIMHANDLE sensorHandle,int options,const int* pos,const int* size,int* resolution);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simSetVisionSensorDepth))(SIMHANDLE sensorHandle,int options,const float* depth);
typedef float* (__cdecl *SIM_API_SYMBOL(ptrSimCheckVisionSensorEx))(SIMHANDLE visionSensorHandle,SIMHANDLE entityHandle,bool returnImage);
/* ------------------------------------------------------- */
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRuckigPos))(int dofs,double baseCycleTime,int flags,const double* currentPos,const double* currentVel,const double* currentAccel,const double* maxVel,const double* maxAccel,const double* maxJerk,const bool* selection,const double* targetPos,const double* targetVel,double* reserved1,int* reserved2);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRuckigVel))(int dofs,double baseCycleTime,int flags,const double* currentPos,const double* currentVel,const double* currentAccel,const double* maxAccel,const double* maxJerk,const bool* selection,const double* targetVel,double* reserved1,int* reserved2);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRuckigStep))(int objHandle,double cycleTime,double* newPos,double* newVel,double* newAccel,double* syncTime,double* reserved1,int* reserved2);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushDoubleOntoStack))(SIMHANDLE stackHandle,double value);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPushDoubleTableOntoStack))(SIMHANDLE stackHandle,const double* values,int valueCnt);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackDoubleValue))(SIMHANDLE stackHandle,double* numberValue);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetStackDoubleTable))(SIMHANDLE stackHandle,double* array,int count);
/* non-documented functions, mainly for the dynamics plugins: */
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetDynamicSimulationIconCode))(void* object,int code);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetDynamicObjectFlagForVisualization))(void* object,int flag);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simGetObjectListSize))(int objType);
typedef const void* (__cdecl *SIM_API_SYMBOL(ptr_simGetObjectFromIndex))(int objType,int index);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptr_simGetObjectID))(const void* object);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simGetObjectType))(const void* object);
typedef const void** (__cdecl *SIM_API_SYMBOL(ptr_simGetObjectChildren))(const void* object,int* count);
typedef const void* (__cdecl *SIM_API_SYMBOL(ptr_simGetParentObject))(const void* object);
typedef const void* (__cdecl *SIM_API_SYMBOL(ptr_simGetObject))(SIMHANDLE objID);

typedef const void* (__cdecl *SIM_API_SYMBOL(ptr_simGetIkGroupObject))(int ikGroupID);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simMpHandleIkGroupObject))(const void* ikGroup);

typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simIsShapeDynamicallyStatic))(const void* shape);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simGetTreeDynamicProperty))(const void* object);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simGetDummyLinkType))(const void* dummy,SIMHANDLE* linkedDummyID);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simGetJointMode))(const void* joint);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simIsJointInHybridOperation))(const void* joint);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simDisableDynamicTreeForManipulation))(const void* object,bool disableFlag);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simIsShapeDynamicallyRespondable))(const void* shape);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simGetDynamicCollisionMask))(const void* shape);
typedef const void* (__cdecl *SIM_API_SYMBOL(ptr_simGetLastParentForLocalGlobalCollidable))(const void* shape);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simGetStartSleeping))(const void* shape);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simGetWasPutToSleepOnce))(const void* shape);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simGetDynamicsFullRefreshFlag))(const void* object);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetDynamicsFullRefreshFlag))(const void* object,bool flag);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simClearAdditionalForceAndTorque))(const void* shape);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simGetJointType))(const void* joint);
typedef const void* (__cdecl *SIM_API_SYMBOL(ptr_simGetGeomWrapFromGeomProxy))(const void* geomData);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simGetPurePrimitiveType))(const void* geomInfo);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simIsGeomWrapGeometric))(const void* geomInfo);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simIsGeomWrapConvex))(const void* geomInfo);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simGetGeometricCount))(const void* geomInfo);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetAllGeometrics))(const void* geomInfo,void** allGeometrics);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simMakeDynamicAnnouncement))(int announceType);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simGetTimeDiffInMs))(int previousTime);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simDoEntitiesCollide))(SIMHANDLE entity1ID,SIMHANDLE entity2ID,SIMHANDLE* cacheBuffer,bool overrideCollidableFlagIfShape1,bool overrideCollidableFlagIfShape2,bool pathPlanningRoutineCalling);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simGetJointDynCtrlMode))(const void* joint);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimFloatingViewRemove))(int floatingViewHandle);
#ifdef interfaceIsSinglePrecision
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetShapeViz))(SIMHANDLE shapeHandle,int index,struct SShapeVizInfof* info);
#else
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetShapeViz))(SIMHANDLE shapeHandle,int index,struct SShapeVizInfo* info);
#endif

typedef int (__cdecl *SIM_API_SYMBOL(ptrSimTransformImage))(unsigned char* image,const int* resolution,int options,const SIMDOUBLE* floatParams,const int* intParams,void* reserved);
typedef const SIMDOUBLE* (__cdecl *SIM_API_SYMBOL(ptrSimGetOctreeVoxels))(SIMHANDLE octreeHandle,int* ptCnt,void* reserved);
typedef const SIMDOUBLE* (__cdecl *SIM_API_SYMBOL(ptrSimGetPointCloudPoints))(SIMHANDLE pointCloudHandle,int* ptCnt,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectMatrix))(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,SIMDOUBLE* matrix);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectMatrix))(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,const SIMDOUBLE* matrix);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectPose))(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,SIMDOUBLE* pose);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectPose))(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,const SIMDOUBLE* pose);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectPosition))(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,SIMDOUBLE* position);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectPosition))(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,const SIMDOUBLE* position);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectOrientation))(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,SIMDOUBLE* eulerAngles);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectOrientation))(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,const SIMDOUBLE* eulerAngles);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetJointPosition))(SIMHANDLE objectHandle,SIMDOUBLE* position);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetJointPosition))(SIMHANDLE objectHandle,SIMDOUBLE position);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetJointTargetPosition))(SIMHANDLE objectHandle,SIMDOUBLE targetPosition);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetJointTargetPosition))(SIMHANDLE objectHandle,SIMDOUBLE* targetPosition);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetJointTargetForce))(SIMHANDLE jointHandle,SIMDOUBLE* forceOrTorque);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetJointTargetForce))(SIMHANDLE objectHandle,SIMDOUBLE forceOrTorque,bool signedValue);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectChildPose))(SIMHANDLE objectHandle,SIMDOUBLE* pose);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectChildPose))(SIMHANDLE objectHandle,const SIMDOUBLE* pose);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetJointInterval))(SIMHANDLE objectHandle,bool* cyclic,SIMDOUBLE* interval);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetJointInterval))(SIMHANDLE objectHandle,bool cyclic,const SIMDOUBLE* interval);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimBuildIdentityMatrix))(SIMDOUBLE* matrix);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimBuildMatrix))(const SIMDOUBLE* position,const SIMDOUBLE* eulerAngles,SIMDOUBLE* matrix);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimBuildPose))(const SIMDOUBLE* position,const SIMDOUBLE* eulerAngles,SIMDOUBLE* pose);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetEulerAnglesFromMatrix))(const SIMDOUBLE* matrix,SIMDOUBLE* eulerAngles);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimInvertMatrix))(SIMDOUBLE* matrix);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimMultiplyMatrices))(const SIMDOUBLE* matrixIn1,const SIMDOUBLE* matrixIn2,SIMDOUBLE* matrixOut);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimMultiplyPoses))(const SIMDOUBLE* poseIn1,const SIMDOUBLE* poseIn2,SIMDOUBLE* poseOut);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimInvertPose))(SIMDOUBLE* pose);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimInterpolatePoses))(const SIMDOUBLE* poseIn1,const SIMDOUBLE* poseIn2,SIMDOUBLE interpolFactor,SIMDOUBLE* poseOut);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPoseToMatrix))(const SIMDOUBLE* poseIn,SIMDOUBLE* matrixOut);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimMatrixToPose))(const SIMDOUBLE* matrixIn,SIMDOUBLE* poseOut);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimInterpolateMatrices))(const SIMDOUBLE* matrixIn1,const SIMDOUBLE* matrixIn2,SIMDOUBLE interpolFactor,SIMDOUBLE* matrixOut);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimTransformVector))(const SIMDOUBLE* matrix,SIMDOUBLE* vect);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptrSimGetSimulationTime))();
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptrSimGetSystemTime))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleProximitySensor))(SIMHANDLE sensorHandle,SIMDOUBLE* detectedPoint,SIMHANDLE* detectedObjectHandle,SIMDOUBLE* normalVector);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimReadProximitySensor))(SIMHANDLE sensorHandle,SIMDOUBLE* detectedPoint,SIMHANDLE* detectedObjectHandle,SIMDOUBLE* normalVector);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleDynamics))(SIMDOUBLE deltaTime);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCheckProximitySensor))(SIMHANDLE sensorHandle,SIMHANDLE entityHandle,SIMDOUBLE* detectedPoint);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCheckProximitySensorEx))(SIMHANDLE sensorHandle,SIMHANDLE entityHandle,int detectionMode,SIMDOUBLE detectionThreshold,SIMDOUBLE maxAngle,SIMDOUBLE* detectedPoint,SIMHANDLE* detectedObjectHandle,SIMDOUBLE* normalVector);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCheckProximitySensorEx2))(SIMHANDLE sensorHandle,SIMDOUBLE* vertexPointer,int itemType,int itemCount,int detectionMode,SIMDOUBLE detectionThreshold,SIMDOUBLE maxAngle,SIMDOUBLE* detectedPoint,SIMDOUBLE* normalVector);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCheckCollisionEx))(SIMHANDLE entity1Handle,SIMHANDLE entity2Handle,SIMDOUBLE** intersectionSegments);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCheckDistance))(SIMHANDLE entity1Handle,SIMHANDLE entity2Handle,SIMDOUBLE threshold,SIMDOUBLE* distanceData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetSimulationTimeStep))(SIMDOUBLE timeStep);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptrSimGetSimulationTimeStep))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimFloatingViewAdd))(SIMDOUBLE posX,SIMDOUBLE posY,SIMDOUBLE sizeX,SIMDOUBLE sizeY,int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleGraph))(SIMHANDLE graphHandle,SIMDOUBLE simulationTime);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetGraphStreamTransformation))(SIMHANDLE graphHandle,int streamId,int trType,SIMDOUBLE mult,SIMDOUBLE off,int movingAvgPeriod);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddGraphCurve))(SIMHANDLE graphHandle,const char* curveName,int dim,const int* streamIds,const SIMDOUBLE* defaultValues,const char* unitStr,int options,const float* color,int curveWidth);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetGraphStreamValue))(SIMHANDLE graphHandle,int streamId,SIMDOUBLE value);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetJointTargetVelocity))(SIMHANDLE objectHandle,SIMDOUBLE targetVelocity);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetJointTargetVelocity))(SIMHANDLE objectHandle,SIMDOUBLE* targetVelocity);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimScaleObjects))(const SIMHANDLE* objectHandles,int objectCount,SIMDOUBLE scalingFactor,bool scalePositionsToo);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimAddDrawingObject))(int objectType,SIMDOUBLE size,SIMDOUBLE duplicateTolerance,SIMHANDLE parentObjectHandle,int maxItemCount,const float* color,const float* setToNULL,const float* setToNULL2,const float* setToNULL3);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddGraphStream))(SIMHANDLE graphHandle,const char* streamName,const char* unitStr,int options,const float* color,SIMDOUBLE cyclicRange);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddDrawingObjectItem))(SIMHANDLE objectHandle,const SIMDOUBLE* itemData);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectSizeFactor))(SIMHANDLE objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimReadForceSensor))(SIMHANDLE objectHandle,SIMDOUBLE* forceVector,SIMDOUBLE* torqueVector);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetVelocity))(SIMHANDLE shapeHandle,SIMDOUBLE* linearVelocity,SIMDOUBLE* angularVelocity);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectVelocity))(SIMHANDLE objectHandle,SIMDOUBLE* linearVelocity,SIMDOUBLE* angularVelocity);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetJointVelocity))(SIMHANDLE jointHandle,SIMDOUBLE* velocity);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddForceAndTorque))(SIMHANDLE shapeHandle,const SIMDOUBLE* force,const SIMDOUBLE* torque);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddForce))(SIMHANDLE shapeHandle,const SIMDOUBLE* position,const SIMDOUBLE* force);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectColor))(SIMHANDLE objectHandle,int index,int colorComponent,const float* rgbData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectColor))(SIMHANDLE objectHandle,int index,int colorComponent,float* rgbData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetShapeColor))(SIMHANDLE shapeHandle,const char* colorName,int colorComponent,const float* rgbData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetShapeColor))(SIMHANDLE shapeHandle,const char* colorName,int colorComponent,float* rgbData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetContactInfo))(int dynamicPass,SIMHANDLE objectHandle,int index,SIMHANDLE* objectHandles,SIMDOUBLE* contactInfo);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAuxiliaryConsoleOpen))(const char* title,int maxLines,int mode,const int* position,const int* size,const float* textColor,const float* backgroundColor);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimImportShape))(int fileformat,const char* pathAndFilename,int options,SIMDOUBLE identicalVerticeTolerance,SIMDOUBLE scalingFactor);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimImportMesh))(int fileformat,const char* pathAndFilename,int options,SIMDOUBLE identicalVerticeTolerance,SIMDOUBLE scalingFactor,SIMDOUBLE*** vertices,int** verticesSizes,int*** indices,int** indicesSizes,SIMDOUBLE*** reserved,char*** names);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimExportMesh))(int fileformat,const char* pathAndFilename,int options,SIMDOUBLE scalingFactor,int elementCount,const SIMDOUBLE** vertices,const int* verticesSizes,const int** indices,const int* indicesSizes,SIMDOUBLE** reserved,const char** names);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreateShape))(int options,double shadingAngle,const double* vertices,int verticesSize,const int* indices,int indicesSize,const double* normals,const float* textCoords,const unsigned char* texture,const int* textureResolution);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreateMeshShape))(int options,SIMDOUBLE shadingAngle,const SIMDOUBLE* vertices,int verticesSize,const int* indices,int indicesSize,SIMDOUBLE* reserved);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreatePrimitiveShape))(int primitiveType,const SIMDOUBLE* sizes,int options);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreateHeightfieldShape))(int options,SIMDOUBLE shadingAngle,int xPointCount,int yPointCount,SIMDOUBLE xSize,const SIMDOUBLE* heights);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetShapeMesh))(SIMHANDLE shapeHandle,SIMDOUBLE** vertices,int* verticesSize,int** indices,int* indicesSize,SIMDOUBLE** normals);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreateJoint))(int jointType,int jointMode,int options,const SIMDOUBLE* sizes,const SIMDOUBLE* reservedA,const SIMDOUBLE* reservedB);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreateDummy))(SIMDOUBLE size,const float* reserved);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreateScript))(int scriptType,const char* scriptText, int options, const char* lang);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectHierarchyOrder))(SIMHANDLE objectHandle, int* totalSiblings);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectHierarchyOrder))(SIMHANDLE objectHandle, int order);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreateForceSensor))(int options,const int* intParams,const SIMDOUBLE* floatParams,const SIMDOUBLE* reserved);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreateVisionSensor))(int options,const int* intParams,const SIMDOUBLE* floatParams,const SIMDOUBLE* reserved);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreateProximitySensor))(int sensorType,int subType,int options,const int* intParams,const SIMDOUBLE* floatParams,const SIMDOUBLE* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetRotationAxis))(const SIMDOUBLE* matrixStart,const SIMDOUBLE* matrixGoal,SIMDOUBLE* axis,SIMDOUBLE* angle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRotateAroundAxis))(const SIMDOUBLE* matrixIn,const SIMDOUBLE* axis,const SIMDOUBLE* axisPos,SIMDOUBLE angle,SIMDOUBLE* matrixOut);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetJointForce))(SIMHANDLE jointHandle,SIMDOUBLE* forceOrTorque);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCameraFitToView))(SIMHANDLE viewHandleOrIndex,int objectCount,const SIMHANDLE* objectHandles,int options,SIMDOUBLE scaling);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleVisionSensor))(SIMHANDLE visionSensorHandle,SIMDOUBLE** auxValues,int** auxValuesCount);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimReadVisionSensor))(SIMHANDLE visionSensorHandle,SIMDOUBLE** auxValues,int** auxValuesCount);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCheckVisionSensor))(SIMHANDLE visionSensorHandle,SIMHANDLE entityHandle,SIMDOUBLE** auxValues,int** auxValuesCount);
typedef unsigned char* (__cdecl *SIM_API_SYMBOL(ptrSimGetVisionSensorImg))(SIMHANDLE sensorHandle,int options,SIMDOUBLE rgbaCutOff,const int* pos,const int* size,int* resolution);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetVisionSensorRes))(SIMHANDLE visionSensorHandle,int* resolution);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectQuaternion))(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,SIMDOUBLE* quaternion);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectQuaternion))(SIMHANDLE objectHandle,SIMHANDLE relativeToObjectHandle,const SIMDOUBLE* quaternion);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimConvexDecompose))(SIMHANDLE shapeHandle,int options,const int* intParams,const SIMDOUBLE* floatParams);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimWriteTexture))(SIMHANDLE textureId,int options,const char* data,int posX,int posY,int sizeX,int sizeY,SIMDOUBLE interpol);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreateTexture))(const char* fileName,int options,const SIMDOUBLE* planeSizes,const SIMDOUBLE* scalingUV,const SIMDOUBLE* xy_g,int fixedResolution,int* textureId,int* resolution,const void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetShapeGeomInfo))(SIMHANDLE shapeHandle,int* intData,SIMDOUBLE* floatData,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimScaleObject))(SIMHANDLE objectHandle,SIMDOUBLE xScale,SIMDOUBLE yScale,SIMDOUBLE zScale,int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetShapeTexture))(SIMHANDLE shapeHandle,SIMHANDLE textureId,int mappingMode,int options,const SIMDOUBLE* uvScaling,const SIMDOUBLE* position,const SIMDOUBLE* orientation);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetQHull))(const SIMDOUBLE* inVertices,int inVerticesL,SIMDOUBLE** verticesOut,int* verticesOutL,int** indicesOut,int* indicesOutL,int reserved1,const SIMDOUBLE* reserved2);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetDecimatedMesh))(const SIMDOUBLE* inVertices,int inVerticesL,const int* inIndices,int inIndicesL,SIMDOUBLE** verticesOut,int* verticesOutL,int** indicesOut,int* indicesOutL,SIMDOUBLE decimationPercent,int reserved1,const SIMDOUBLE* reserved2);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimComputeMassAndInertia))(SIMHANDLE shapeHandle,SIMDOUBLE density);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreateOctree))(SIMDOUBLE voxelSize,int options,SIMDOUBLE pointSize,void* reserved);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimCreatePointCloud))(SIMDOUBLE maxVoxelSize,int maxPtCntPerVoxel,int options,SIMDOUBLE pointSize,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetPointCloudOptions))(SIMHANDLE pointCloudHandle,SIMDOUBLE maxVoxelSize,int maxPtCntPerVoxel,int options,SIMDOUBLE pointSize,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetPointCloudOptions))(SIMHANDLE pointCloudHandle,SIMDOUBLE* maxVoxelSize,int* maxPtCntPerVoxel,int* options,SIMDOUBLE* pointSize,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimInsertVoxelsIntoOctree))(SIMHANDLE octreeHandle,int options,const SIMDOUBLE* pts,int ptCnt,const unsigned char* color,const unsigned int* tag,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveVoxelsFromOctree))(SIMHANDLE octreeHandle,int options,const SIMDOUBLE* pts,int ptCnt,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimInsertPointsIntoPointCloud))(SIMHANDLE pointCloudHandle,int options,const SIMDOUBLE* pts,int ptCnt,const unsigned char* color,void* optionalValues);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemovePointsFromPointCloud))(SIMHANDLE pointCloudHandle,int options,const SIMDOUBLE* pts,int ptCnt,SIMDOUBLE tolerance,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimIntersectPointsWithPointCloud))(SIMHANDLE pointCloudHandle,int options,const SIMDOUBLE* pts,int ptCnt,SIMDOUBLE tolerance,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimInsertObjectIntoPointCloud))(SIMHANDLE pointCloudHandle,SIMHANDLE objectHandle,int options,SIMDOUBLE gridSize,const unsigned char* color,void* optionalValues);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSubtractObjectFromPointCloud))(SIMHANDLE pointCloudHandle,SIMHANDLE objectHandle,int options,SIMDOUBLE tolerance,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCheckOctreePointOccupancy))(SIMHANDLE octreeHandle,int options,const SIMDOUBLE* points,int ptCnt,unsigned int* tag,unsigned long long int* location,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimApplyTexture))(SIMHANDLE shapeHandle,const SIMDOUBLE* textureCoordinates,int textCoordSize,const unsigned char* texture,const int* textureResolution,int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetJointDependency))(SIMHANDLE jointHandle,SIMHANDLE masterJointHandle,SIMDOUBLE offset,SIMDOUBLE multCoeff);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetJointDependency))(SIMHANDLE jointHandle,SIMHANDLE* masterJointHandle,SIMDOUBLE* offset,SIMDOUBLE* multCoeff);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetShapeMass))(SIMHANDLE shapeHandle,SIMDOUBLE* mass);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetShapeMass))(SIMHANDLE shapeHandle,SIMDOUBLE mass);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetShapeInertia))(SIMHANDLE shapeHandle,SIMDOUBLE* inertiaMatrix,SIMDOUBLE* transformationMatrix);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetShapeInertia))(SIMHANDLE shapeHandle,const SIMDOUBLE* inertiaMatrix,const SIMDOUBLE* transformationMatrix);
typedef SIMHANDLE (__cdecl *SIM_API_SYMBOL(ptrSimGenerateShapeFromPath))(const SIMDOUBLE* path,int pathSize,const SIMDOUBLE* section,int sectionSize,int options,const SIMDOUBLE* upVector,SIMDOUBLE reserved);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptrSimGetClosestPosOnPath))(const SIMDOUBLE* path,int pathSize,const SIMDOUBLE* pathLengths,const SIMDOUBLE* absPt);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetObjectLocalTransformation))(const void* object,SIMDOUBLE* pos,SIMDOUBLE* quat,bool excludeFirstJointTransformation);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetObjectLocalTransformation))(void* object,const SIMDOUBLE* pos,const SIMDOUBLE* quat,SIMDOUBLE simTime);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simDynReportObjectCumulativeTransformation))(void* object,const SIMDOUBLE* pos,const SIMDOUBLE* quat,SIMDOUBLE simTime);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetObjectCumulativeTransformation))(void* object,const SIMDOUBLE* pos,const SIMDOUBLE* quat,bool keepChildrenInPlace);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetObjectCumulativeTransformation))(const void* object,SIMDOUBLE* pos,SIMDOUBLE* quat,bool excludeFirstJointTransformation);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetJointVelocity))(const void* joint,SIMDOUBLE vel);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetJointPosition))(const void* joint,SIMDOUBLE pos);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptr_simGetJointPosition))(const void* joint);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetDynamicMotorPositionControlTargetPosition))(const void* joint,SIMDOUBLE pos);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetInitialDynamicVelocity))(const void* shape,SIMDOUBLE* vel);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetInitialDynamicVelocity))(void* shape,const SIMDOUBLE* vel);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetInitialDynamicAngVelocity))(const void* shape,SIMDOUBLE* angularVel);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetInitialDynamicAngVelocity))(void* shape,const SIMDOUBLE* angularVel);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetShapeDynamicVelocity))(void* shape,const SIMDOUBLE* linear,const SIMDOUBLE* angular,SIMDOUBLE simTime);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetAdditionalForceAndTorque))(const void* shape,SIMDOUBLE* force,SIMDOUBLE* torque);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simGetJointPositionInterval))(const void* joint,SIMDOUBLE* minValue,SIMDOUBLE* rangeValue);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptr_simGetDynamicMotorTargetPosition))(const void* joint);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptr_simGetDynamicMotorTargetVelocity))(const void* joint);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptr_simGetDynamicMotorMaxForce))(const void* joint);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptr_simGetDynamicMotorUpperLimitVelocity))(const void* joint);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetDynamicMotorReflectedPositionFromDynamicEngine))(void* joint,SIMDOUBLE pos,SIMDOUBLE simTime);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetJointSphericalTransformation))(void* joint,const SIMDOUBLE* quat,SIMDOUBLE simTime);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simAddForceSensorCumulativeForcesAndTorques))(void* forceSensor,const SIMDOUBLE* force,const SIMDOUBLE* torque,int totalPassesCount,SIMDOUBLE simTime);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simAddJointCumulativeForcesOrTorques))(void* joint,SIMDOUBLE forceOrTorque,int totalPassesCount,SIMDOUBLE simTime);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptr_simGetMass))(const void* geomInfo);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptr_simGetLocalInertiaInfo))(const void* object,SIMDOUBLE* pos,SIMDOUBLE* quat,SIMDOUBLE* diagI);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetPurePrimitiveSizes))(const void* geometric,SIMDOUBLE* sizes);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetVerticesLocalFrame))(const void* shape,const void* geometric,SIMDOUBLE* pos,SIMDOUBLE* quat);
typedef const SIMDOUBLE* (__cdecl *SIM_API_SYMBOL(ptr_simGetHeightfieldData))(const void* geometric,int* xCount,int* yCount,SIMDOUBLE* minHeight,SIMDOUBLE* maxHeight);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetCumulativeMeshes))(const void* shape,const void* geomInfo,SIMDOUBLE** vertices,int* verticesSize,int** indices,int* indicesSize);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetGravity))(SIMDOUBLE* gravity);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simGetDistanceBetweenEntitiesIfSmaller))(SIMHANDLE entity1ID,SIMHANDLE entity2ID,SIMDOUBLE* distance,SIMDOUBLE* ray,int* cacheBuffer,bool overrideMeasurableFlagIfNonCollection1,bool overrideMeasurableFlagIfNonCollection2,bool pathPlanningRoutineCalling);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simHandleJointControl))(const void* joint,int auxV,const int* inputValuesInt,const SIMDOUBLE* inputValuesFloat,SIMDOUBLE* outputValues);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simHandleCustomContact))(SIMHANDLE objHandle1,SIMHANDLE objHandle2,int engine,int* dataInt,SIMDOUBLE* dataFloat);
typedef SIMDOUBLE (__cdecl *SIM_API_SYMBOL(ptr_simGetPureHollowScaling))(const void* geometric);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simDynCallback))(const int* intData,const SIMDOUBLE* floatData);

extern SIM_API_SYMBOL(ptrSimSetBoolProperty) SIM_API_SYMBOL(simSetBoolProperty);
extern SIM_API_SYMBOL(ptrSimGetBoolProperty) SIM_API_SYMBOL(simGetBoolProperty);
extern SIM_API_SYMBOL(ptrSimSetIntProperty) SIM_API_SYMBOL(simSetIntProperty);
extern SIM_API_SYMBOL(ptrSimGetIntProperty) SIM_API_SYMBOL(simGetIntProperty);
extern SIM_API_SYMBOL(ptrSimSetLongProperty) SIM_API_SYMBOL(simSetLongProperty);
extern SIM_API_SYMBOL(ptrSimGetLongProperty) SIM_API_SYMBOL(simGetLongProperty);
extern SIM_API_SYMBOL(ptrSimSetFloatProperty) SIM_API_SYMBOL(simSetFloatProperty);
extern SIM_API_SYMBOL(ptrSimGetFloatProperty) SIM_API_SYMBOL(simGetFloatProperty);
extern SIM_API_SYMBOL(ptrSimSetStringProperty) SIM_API_SYMBOL(simSetStringProperty);
extern SIM_API_SYMBOL(ptrSimGetStringProperty) SIM_API_SYMBOL(simGetStringProperty);
extern SIM_API_SYMBOL(ptrSimSetTableProperty) SIM_API_SYMBOL(simSetTableProperty);
extern SIM_API_SYMBOL(ptrSimGetTableProperty) SIM_API_SYMBOL(simGetTableProperty);
extern SIM_API_SYMBOL(ptrSimSetBufferProperty) SIM_API_SYMBOL(simSetBufferProperty);
extern SIM_API_SYMBOL(ptrSimGetBufferProperty) SIM_API_SYMBOL(simGetBufferProperty);
extern SIM_API_SYMBOL(ptrSimSetIntArray2Property) SIM_API_SYMBOL(simSetIntArray2Property);
extern SIM_API_SYMBOL(ptrSimGetIntArray2Property) SIM_API_SYMBOL(simGetIntArray2Property);
extern SIM_API_SYMBOL(ptrSimSetVector2Property) SIM_API_SYMBOL(simSetVector2Property);
extern SIM_API_SYMBOL(ptrSimGetVector2Property) SIM_API_SYMBOL(simGetVector2Property);
extern SIM_API_SYMBOL(ptrSimSetVector3Property) SIM_API_SYMBOL(simSetVector3Property);
extern SIM_API_SYMBOL(ptrSimGetVector3Property) SIM_API_SYMBOL(simGetVector3Property);
extern SIM_API_SYMBOL(ptrSimSetQuaternionProperty) SIM_API_SYMBOL(simSetQuaternionProperty);
extern SIM_API_SYMBOL(ptrSimGetQuaternionProperty) SIM_API_SYMBOL(simGetQuaternionProperty);
extern SIM_API_SYMBOL(ptrSimSetPoseProperty) SIM_API_SYMBOL(simSetPoseProperty);
extern SIM_API_SYMBOL(ptrSimGetPoseProperty) SIM_API_SYMBOL(simGetPoseProperty);
extern SIM_API_SYMBOL(ptrSimSetColorProperty) SIM_API_SYMBOL(simSetColorProperty);
extern SIM_API_SYMBOL(ptrSimGetColorProperty) SIM_API_SYMBOL(simGetColorProperty);
extern SIM_API_SYMBOL(ptrSimSetFloatArrayProperty) SIM_API_SYMBOL(simSetFloatArrayProperty);
extern SIM_API_SYMBOL(ptrSimGetFloatArrayProperty) SIM_API_SYMBOL(simGetFloatArrayProperty);
extern SIM_API_SYMBOL(ptrSimSetIntArrayProperty) SIM_API_SYMBOL(simSetIntArrayProperty);
extern SIM_API_SYMBOL(ptrSimGetIntArrayProperty) SIM_API_SYMBOL(simGetIntArrayProperty);
extern SIM_API_SYMBOL(ptrSimRemoveProperty) SIM_API_SYMBOL(simRemoveProperty);
extern SIM_API_SYMBOL(ptrSimGetPropertyName) SIM_API_SYMBOL(simGetPropertyName);
extern SIM_API_SYMBOL(ptrSimGetPropertyInfo) SIM_API_SYMBOL(simGetPropertyInfo);

extern SIM_API_SYMBOL(ptrSimRegCallback) SIM_API_SYMBOL(simRegCallback);
extern SIM_API_SYMBOL(ptrSimRunGui) SIM_API_SYMBOL(simRunGui);
extern SIM_API_SYMBOL(ptrSimInitialize) SIM_API_SYMBOL(simInitialize);
extern SIM_API_SYMBOL(ptrSimDeinitialize) SIM_API_SYMBOL(simDeinitialize);
extern SIM_API_SYMBOL(ptrSimPostExitRequest) SIM_API_SYMBOL(simPostExitRequest);
extern SIM_API_SYMBOL(ptrSimGetExitRequest) SIM_API_SYMBOL(simGetExitRequest);
extern SIM_API_SYMBOL(ptrSimLoop) SIM_API_SYMBOL(simLoop);
extern SIM_API_SYMBOL(ptrSimTest) SIM_API_SYMBOL(simTest);
extern SIM_API_SYMBOL(ptrSimGetSimulatorMessage) SIM_API_SYMBOL(simGetSimulatorMessage);
extern SIM_API_SYMBOL(ptrSimGetMainWindow) SIM_API_SYMBOL(simGetMainWindow);
extern SIM_API_SYMBOL(ptrSimGetLastError) SIM_API_SYMBOL(simGetLastError);
extern SIM_API_SYMBOL(ptrSimGetLastInfo) SIM_API_SYMBOL(simGetLastInfo);
extern SIM_API_SYMBOL(ptrSimGetObject) SIM_API_SYMBOL(simGetObject);
extern SIM_API_SYMBOL(ptrSimGetObjectUid) SIM_API_SYMBOL(simGetObjectUid);
extern SIM_API_SYMBOL(ptrSimGetObjectFromUid) SIM_API_SYMBOL(simGetObjectFromUid);
extern SIM_API_SYMBOL(ptrSimGetScriptHandleEx) SIM_API_SYMBOL(simGetScriptHandleEx);
extern SIM_API_SYMBOL(ptrSimRemoveObjects) SIM_API_SYMBOL(simRemoveObjects);
extern SIM_API_SYMBOL(ptrSimRemoveModel) SIM_API_SYMBOL(simRemoveModel);
extern SIM_API_SYMBOL(ptrSimGetObjectAlias) SIM_API_SYMBOL(simGetObjectAlias);
extern SIM_API_SYMBOL(ptrSimSetObjectAlias) SIM_API_SYMBOL(simSetObjectAlias);
extern SIM_API_SYMBOL(ptrSimGetObjectMatrix) SIM_API_SYMBOL(simGetObjectMatrix);
extern SIM_API_SYMBOL(ptrSimSetObjectMatrix) SIM_API_SYMBOL(simSetObjectMatrix);
extern SIM_API_SYMBOL(ptrSimGetObjectPose) SIM_API_SYMBOL(simGetObjectPose);
extern SIM_API_SYMBOL(ptrSimSetObjectPose) SIM_API_SYMBOL(simSetObjectPose);
extern SIM_API_SYMBOL(ptrSimGetObjectPosition) SIM_API_SYMBOL(simGetObjectPosition);
extern SIM_API_SYMBOL(ptrSimSetObjectPosition) SIM_API_SYMBOL(simSetObjectPosition);
extern SIM_API_SYMBOL(ptrSimGetObjectOrientation) SIM_API_SYMBOL(simGetObjectOrientation);
extern SIM_API_SYMBOL(ptrSimSetObjectOrientation) SIM_API_SYMBOL(simSetObjectOrientation);
extern SIM_API_SYMBOL(ptrSimGetJointPosition) SIM_API_SYMBOL(simGetJointPosition);
extern SIM_API_SYMBOL(ptrSimSetJointPosition) SIM_API_SYMBOL(simSetJointPosition);
extern SIM_API_SYMBOL(ptrSimSetJointTargetPosition) SIM_API_SYMBOL(simSetJointTargetPosition);
extern SIM_API_SYMBOL(ptrSimGetJointTargetPosition) SIM_API_SYMBOL(simGetJointTargetPosition);
extern SIM_API_SYMBOL(ptrSimGetObjectChildPose) SIM_API_SYMBOL(simGetObjectChildPose);
extern SIM_API_SYMBOL(ptrSimSetObjectChildPose) SIM_API_SYMBOL(simSetObjectChildPose);
extern SIM_API_SYMBOL(ptrSimGetJointInterval) SIM_API_SYMBOL(simGetJointInterval);
extern SIM_API_SYMBOL(ptrSimSetJointInterval) SIM_API_SYMBOL(simSetJointInterval);
extern SIM_API_SYMBOL(ptrSimGetObjectParent) SIM_API_SYMBOL(simGetObjectParent);
extern SIM_API_SYMBOL(ptrSimGetObjectChild) SIM_API_SYMBOL(simGetObjectChild);
extern SIM_API_SYMBOL(ptrSimSetObjectParent) SIM_API_SYMBOL(simSetObjectParent);
extern SIM_API_SYMBOL(ptrSimGetObjectType) SIM_API_SYMBOL(simGetObjectType);
extern SIM_API_SYMBOL(ptrSimGetJointType) SIM_API_SYMBOL(simGetJointType);
extern SIM_API_SYMBOL(ptrSimBuildIdentityMatrix) SIM_API_SYMBOL(simBuildIdentityMatrix);
extern SIM_API_SYMBOL(ptrSimBuildMatrix) SIM_API_SYMBOL(simBuildMatrix);
extern SIM_API_SYMBOL(ptrSimBuildPose) SIM_API_SYMBOL(simBuildPose);
extern SIM_API_SYMBOL(ptrSimGetEulerAnglesFromMatrix) SIM_API_SYMBOL(simGetEulerAnglesFromMatrix);
extern SIM_API_SYMBOL(ptrSimInvertMatrix) SIM_API_SYMBOL(simInvertMatrix);
extern SIM_API_SYMBOL(ptrSimMultiplyMatrices) SIM_API_SYMBOL(simMultiplyMatrices);
extern SIM_API_SYMBOL(ptrSimMultiplyPoses) SIM_API_SYMBOL(simMultiplyPoses);
extern SIM_API_SYMBOL(ptrSimInvertPose) SIM_API_SYMBOL(simInvertPose);
extern SIM_API_SYMBOL(ptrSimInterpolatePoses) SIM_API_SYMBOL(simInterpolatePoses);
extern SIM_API_SYMBOL(ptrSimPoseToMatrix) SIM_API_SYMBOL(simPoseToMatrix);
extern SIM_API_SYMBOL(ptrSimMatrixToPose) SIM_API_SYMBOL(simMatrixToPose);
extern SIM_API_SYMBOL(ptrSimInterpolateMatrices) SIM_API_SYMBOL(simInterpolateMatrices);
extern SIM_API_SYMBOL(ptrSimTransformVector) SIM_API_SYMBOL(simTransformVector);
extern SIM_API_SYMBOL(ptrSimReservedCommand) SIM_API_SYMBOL(simReservedCommand);
extern SIM_API_SYMBOL(ptrSimGetSimulationTime) SIM_API_SYMBOL(simGetSimulationTime);
extern SIM_API_SYMBOL(ptrSimGetSimulationState) SIM_API_SYMBOL(simGetSimulationState);
extern SIM_API_SYMBOL(ptrSimGetSystemTime) SIM_API_SYMBOL(simGetSystemTime);
extern SIM_API_SYMBOL(ptrSimLoadScene) SIM_API_SYMBOL(simLoadScene);
extern SIM_API_SYMBOL(ptrSimCloseScene) SIM_API_SYMBOL(simCloseScene);
extern SIM_API_SYMBOL(ptrSimSaveScene) SIM_API_SYMBOL(simSaveScene);
extern SIM_API_SYMBOL(ptrSimLoadModel) SIM_API_SYMBOL(simLoadModel);
extern SIM_API_SYMBOL(ptrSimSaveModel) SIM_API_SYMBOL(simSaveModel);
extern SIM_API_SYMBOL(ptrSimDoesFileExist) SIM_API_SYMBOL(simDoesFileExist);
extern SIM_API_SYMBOL(ptrSimGetObjectSel) SIM_API_SYMBOL(simGetObjectSel);
extern SIM_API_SYMBOL(ptrSimSetObjectSel) SIM_API_SYMBOL(simSetObjectSel);
extern SIM_API_SYMBOL(ptrSimHandleProximitySensor) SIM_API_SYMBOL(simHandleProximitySensor);
extern SIM_API_SYMBOL(ptrSimReadProximitySensor) SIM_API_SYMBOL(simReadProximitySensor);
extern SIM_API_SYMBOL(ptrSimHandleDynamics) SIM_API_SYMBOL(simHandleDynamics);
extern SIM_API_SYMBOL(ptrSimResetScript) SIM_API_SYMBOL(simResetScript);
extern SIM_API_SYMBOL(ptrSimRefreshDialogs) SIM_API_SYMBOL(simRefreshDialogs);
extern SIM_API_SYMBOL(ptrSimResetProximitySensor) SIM_API_SYMBOL(simResetProximitySensor);
extern SIM_API_SYMBOL(ptrSimCheckProximitySensor) SIM_API_SYMBOL(simCheckProximitySensor);
extern SIM_API_SYMBOL(ptrSimCheckProximitySensorEx) SIM_API_SYMBOL(simCheckProximitySensorEx);
extern SIM_API_SYMBOL(ptrSimCheckProximitySensorEx2) SIM_API_SYMBOL(simCheckProximitySensorEx2);
extern SIM_API_SYMBOL(ptrSimCreateBuffer) SIM_API_SYMBOL(simCreateBuffer);
extern SIM_API_SYMBOL(ptrSimReleaseBuffer) SIM_API_SYMBOL(simReleaseBuffer);
extern SIM_API_SYMBOL(ptrSimCheckCollision) SIM_API_SYMBOL(simCheckCollision);
extern SIM_API_SYMBOL(ptrSimCheckCollisionEx) SIM_API_SYMBOL(simCheckCollisionEx);
extern SIM_API_SYMBOL(ptrSimCheckDistance) SIM_API_SYMBOL(simCheckDistance);
extern SIM_API_SYMBOL(ptrSimSetSimulationTimeStep) SIM_API_SYMBOL(simSetSimulationTimeStep);
extern SIM_API_SYMBOL(ptrSimGetSimulationTimeStep) SIM_API_SYMBOL(simGetSimulationTimeStep);
extern SIM_API_SYMBOL(ptrSimGetRealTimeSimulation) SIM_API_SYMBOL(simGetRealTimeSimulation);
extern SIM_API_SYMBOL(ptrSimStartSimulation) SIM_API_SYMBOL(simStartSimulation);
extern SIM_API_SYMBOL(ptrSimStopSimulation) SIM_API_SYMBOL(simStopSimulation);
extern SIM_API_SYMBOL(ptrSimPauseSimulation) SIM_API_SYMBOL(simPauseSimulation);
extern SIM_API_SYMBOL(ptrSimFloatingViewAdd) SIM_API_SYMBOL(simFloatingViewAdd);
extern SIM_API_SYMBOL(ptrSimFloatingViewRemove) SIM_API_SYMBOL(simFloatingViewRemove);
extern SIM_API_SYMBOL(ptrSimAdjustView) SIM_API_SYMBOL(simAdjustView);
extern SIM_API_SYMBOL(ptrSimSetLastError) SIM_API_SYMBOL(simSetLastError);
extern SIM_API_SYMBOL(ptrSimHandleGraph) SIM_API_SYMBOL(simHandleGraph);
extern SIM_API_SYMBOL(ptrSimResetGraph) SIM_API_SYMBOL(simResetGraph);
extern SIM_API_SYMBOL(ptrSimAddGraphStream) SIM_API_SYMBOL(simAddGraphStream);
extern SIM_API_SYMBOL(ptrSimDestroyGraphCurve) SIM_API_SYMBOL(simDestroyGraphCurve);
extern SIM_API_SYMBOL(ptrSimSetGraphStreamTransformation) SIM_API_SYMBOL(simSetGraphStreamTransformation);
extern SIM_API_SYMBOL(ptrSimDuplicateGraphCurveToStatic) SIM_API_SYMBOL(simDuplicateGraphCurveToStatic);
extern SIM_API_SYMBOL(ptrSimAddGraphCurve) SIM_API_SYMBOL(simAddGraphCurve);
extern SIM_API_SYMBOL(ptrSimSetGraphStreamValue) SIM_API_SYMBOL(simSetGraphStreamValue);
extern SIM_API_SYMBOL(ptrSimSetNavigationMode) SIM_API_SYMBOL(simSetNavigationMode);
extern SIM_API_SYMBOL(ptrSimGetNavigationMode) SIM_API_SYMBOL(simGetNavigationMode);
extern SIM_API_SYMBOL(ptrSimSetPage) SIM_API_SYMBOL(simSetPage);
extern SIM_API_SYMBOL(ptrSimGetPage) SIM_API_SYMBOL(simGetPage);
extern SIM_API_SYMBOL(ptrSimRegisterScriptCallbackFunction) SIM_API_SYMBOL(simRegisterScriptCallbackFunction);
extern SIM_API_SYMBOL(ptrSimRegisterScriptVariable) SIM_API_SYMBOL(simRegisterScriptVariable);
extern SIM_API_SYMBOL(ptrSimRegisterScriptFuncHook) SIM_API_SYMBOL(simRegisterScriptFuncHook);
extern SIM_API_SYMBOL(ptrSimSetJointTargetVelocity) SIM_API_SYMBOL(simSetJointTargetVelocity);
extern SIM_API_SYMBOL(ptrSimGetJointTargetVelocity) SIM_API_SYMBOL(simGetJointTargetVelocity);
extern SIM_API_SYMBOL(ptrSimCopyPasteObjects) SIM_API_SYMBOL(simCopyPasteObjects);
extern SIM_API_SYMBOL(ptrSimScaleObjects) SIM_API_SYMBOL(simScaleObjects);
extern SIM_API_SYMBOL(ptrSimAddDrawingObject) SIM_API_SYMBOL(simAddDrawingObject);
extern SIM_API_SYMBOL(ptrSimRemoveDrawingObject) SIM_API_SYMBOL(simRemoveDrawingObject);
extern SIM_API_SYMBOL(ptrSimAddDrawingObjectItem) SIM_API_SYMBOL(simAddDrawingObjectItem);
extern SIM_API_SYMBOL(ptrSimGetObjectSizeFactor) SIM_API_SYMBOL(simGetObjectSizeFactor);
extern SIM_API_SYMBOL(ptrSimAnnounceSceneContentChange) SIM_API_SYMBOL(simAnnounceSceneContentChange);
extern SIM_API_SYMBOL(ptrSimReadForceSensor) SIM_API_SYMBOL(simReadForceSensor);
extern SIM_API_SYMBOL(ptrSimGetVelocity) SIM_API_SYMBOL(simGetVelocity);
extern SIM_API_SYMBOL(ptrSimGetObjectVelocity) SIM_API_SYMBOL(simGetObjectVelocity);
extern SIM_API_SYMBOL(ptrSimGetJointVelocity) SIM_API_SYMBOL(simGetJointVelocity);
extern SIM_API_SYMBOL(ptrSimAddForceAndTorque) SIM_API_SYMBOL(simAddForceAndTorque);
extern SIM_API_SYMBOL(ptrSimAddForce) SIM_API_SYMBOL(simAddForce);
extern SIM_API_SYMBOL(ptrSimSetExplicitHandling) SIM_API_SYMBOL(simSetExplicitHandling);
extern SIM_API_SYMBOL(ptrSimGetExplicitHandling) SIM_API_SYMBOL(simGetExplicitHandling);
extern SIM_API_SYMBOL(ptrSimGetLinkDummy) SIM_API_SYMBOL(simGetLinkDummy);
extern SIM_API_SYMBOL(ptrSimSetLinkDummy) SIM_API_SYMBOL(simSetLinkDummy);
extern SIM_API_SYMBOL(ptrSimSetObjectColor) SIM_API_SYMBOL(simSetObjectColor);
extern SIM_API_SYMBOL(ptrSimGetObjectColor) SIM_API_SYMBOL(simGetObjectColor);
extern SIM_API_SYMBOL(ptrSimSetShapeColor) SIM_API_SYMBOL(simSetShapeColor);
extern SIM_API_SYMBOL(ptrSimGetShapeColor) SIM_API_SYMBOL(simGetShapeColor);
extern SIM_API_SYMBOL(ptrSimResetDynamicObject) SIM_API_SYMBOL(simResetDynamicObject);
extern SIM_API_SYMBOL(ptrSimSetJointMode) SIM_API_SYMBOL(simSetJointMode);
extern SIM_API_SYMBOL(ptrSimGetJointMode) SIM_API_SYMBOL(simGetJointMode);
extern SIM_API_SYMBOL(ptrSimSerialOpen) SIM_API_SYMBOL(simSerialOpen);
extern SIM_API_SYMBOL(ptrSimSerialClose) SIM_API_SYMBOL(simSerialClose);
extern SIM_API_SYMBOL(ptrSimSerialSend) SIM_API_SYMBOL(simSerialSend);
extern SIM_API_SYMBOL(ptrSimSerialRead) SIM_API_SYMBOL(simSerialRead);
extern SIM_API_SYMBOL(ptrSimSerialCheck) SIM_API_SYMBOL(simSerialCheck);
extern SIM_API_SYMBOL(ptrSimGetContactInfo) SIM_API_SYMBOL(simGetContactInfo);
extern SIM_API_SYMBOL(ptrSimAuxiliaryConsoleOpen) SIM_API_SYMBOL(simAuxiliaryConsoleOpen);
extern SIM_API_SYMBOL(ptrSimAuxiliaryConsoleClose) SIM_API_SYMBOL(simAuxiliaryConsoleClose);
extern SIM_API_SYMBOL(ptrSimAuxiliaryConsoleShow) SIM_API_SYMBOL(simAuxiliaryConsoleShow);
extern SIM_API_SYMBOL(ptrSimAuxiliaryConsolePrint) SIM_API_SYMBOL(simAuxiliaryConsolePrint);
extern SIM_API_SYMBOL(ptrSimImportShape) SIM_API_SYMBOL(simImportShape);
extern SIM_API_SYMBOL(ptrSimImportMesh) SIM_API_SYMBOL(simImportMesh);
extern SIM_API_SYMBOL(ptrSimExportMesh) SIM_API_SYMBOL(simExportMesh);
extern SIM_API_SYMBOL(ptrSimCreateShape) SIM_API_SYMBOL(simCreateShape);
extern SIM_API_SYMBOL(ptrSimCreateMeshShape) SIM_API_SYMBOL(simCreateMeshShape);
extern SIM_API_SYMBOL(ptrSimCreatePrimitiveShape) SIM_API_SYMBOL(simCreatePrimitiveShape);
extern SIM_API_SYMBOL(ptrSimCreateHeightfieldShape) SIM_API_SYMBOL(simCreateHeightfieldShape);
extern SIM_API_SYMBOL(ptrSimGetShapeMesh) SIM_API_SYMBOL(simGetShapeMesh);
extern SIM_API_SYMBOL(ptrSimCreateJoint) SIM_API_SYMBOL(simCreateJoint);
extern SIM_API_SYMBOL(ptrSimCreateDummy) SIM_API_SYMBOL(simCreateDummy);
extern SIM_API_SYMBOL(ptrSimCreateScript) SIM_API_SYMBOL(simCreateScript);
extern SIM_API_SYMBOL(ptrSimGetObjectHierarchyOrder) SIM_API_SYMBOL(simGetObjectHierarchyOrder);
extern SIM_API_SYMBOL(ptrSimSetObjectHierarchyOrder) SIM_API_SYMBOL(simSetObjectHierarchyOrder);
extern SIM_API_SYMBOL(ptrSimCreateForceSensor) SIM_API_SYMBOL(simCreateForceSensor);
extern SIM_API_SYMBOL(ptrSimCreateVisionSensor) SIM_API_SYMBOL(simCreateVisionSensor);
extern SIM_API_SYMBOL(ptrSimCreateProximitySensor) SIM_API_SYMBOL(simCreateProximitySensor);
extern SIM_API_SYMBOL(ptrSimGetRotationAxis) SIM_API_SYMBOL(simGetRotationAxis);
extern SIM_API_SYMBOL(ptrSimRotateAroundAxis) SIM_API_SYMBOL(simRotateAroundAxis);
extern SIM_API_SYMBOL(ptrSimGetJointForce) SIM_API_SYMBOL(simGetJointForce);
extern SIM_API_SYMBOL(ptrSimGetJointTargetForce) SIM_API_SYMBOL(simGetJointTargetForce);
extern SIM_API_SYMBOL(ptrSimSetJointTargetForce) SIM_API_SYMBOL(simSetJointTargetForce);
extern SIM_API_SYMBOL(ptrSimCameraFitToView) SIM_API_SYMBOL(simCameraFitToView);
extern SIM_API_SYMBOL(ptrSimIsHandle) SIM_API_SYMBOL(simIsHandle);
extern SIM_API_SYMBOL(ptrSimHandleVisionSensor) SIM_API_SYMBOL(simHandleVisionSensor);
extern SIM_API_SYMBOL(ptrSimReadVisionSensor) SIM_API_SYMBOL(simReadVisionSensor);
extern SIM_API_SYMBOL(ptrSimResetVisionSensor) SIM_API_SYMBOL(simResetVisionSensor);
extern SIM_API_SYMBOL(ptrSimCheckVisionSensor) SIM_API_SYMBOL(simCheckVisionSensor);
extern SIM_API_SYMBOL(ptrSimCheckVisionSensorEx) SIM_API_SYMBOL(simCheckVisionSensorEx);
extern SIM_API_SYMBOL(ptrSimGetVisionSensorImg) SIM_API_SYMBOL(simGetVisionSensorImg);
extern SIM_API_SYMBOL(ptrSimSetVisionSensorImg) SIM_API_SYMBOL(simSetVisionSensorImg);
extern SIM_API_SYMBOL(ptrSimGetVisionSensorRes) SIM_API_SYMBOL(simGetVisionSensorRes);
extern SIM_API_SYMBOL(ptrSimGetVisionSensorDepth) SIM_API_SYMBOL(simGetVisionSensorDepth);
extern SIM_API_SYMBOL(ptr_simSetVisionSensorDepth) SIM_API_SYMBOL(_simSetVisionSensorDepth);
extern SIM_API_SYMBOL(ptrSimGetObjectQuaternion) SIM_API_SYMBOL(simGetObjectQuaternion);
extern SIM_API_SYMBOL(ptrSimSetObjectQuaternion) SIM_API_SYMBOL(simSetObjectQuaternion);
extern SIM_API_SYMBOL(ptrSimRuckigPos) SIM_API_SYMBOL(simRuckigPos);
extern SIM_API_SYMBOL(ptrSimRuckigVel) SIM_API_SYMBOL(simRuckigVel);
extern SIM_API_SYMBOL(ptrSimRuckigStep) SIM_API_SYMBOL(simRuckigStep);
extern SIM_API_SYMBOL(ptrSimRuckigRemove) SIM_API_SYMBOL(simRuckigRemove);
extern SIM_API_SYMBOL(ptrSimGroupShapes) SIM_API_SYMBOL(simGroupShapes);
extern SIM_API_SYMBOL(ptrSimUngroupShape) SIM_API_SYMBOL(simUngroupShape);
extern SIM_API_SYMBOL(ptrSimConvexDecompose) SIM_API_SYMBOL(simConvexDecompose);
extern SIM_API_SYMBOL(ptrSimQuitSimulator) SIM_API_SYMBOL(simQuitSimulator);
extern SIM_API_SYMBOL(ptrSimSetShapeMaterial) SIM_API_SYMBOL(simSetShapeMaterial);
extern SIM_API_SYMBOL(ptrSimGetTextureId) SIM_API_SYMBOL(simGetTextureId);
extern SIM_API_SYMBOL(ptrSimReadTexture) SIM_API_SYMBOL(simReadTexture);
extern SIM_API_SYMBOL(ptrSimWriteTexture) SIM_API_SYMBOL(simWriteTexture);
extern SIM_API_SYMBOL(ptrSimCreateTexture) SIM_API_SYMBOL(simCreateTexture);
extern SIM_API_SYMBOL(ptrSimGetShapeGeomInfo) SIM_API_SYMBOL(simGetShapeGeomInfo);
extern SIM_API_SYMBOL(ptrSimGetObjects) SIM_API_SYMBOL(simGetObjects);
extern SIM_API_SYMBOL(ptrSimGetObjectsInTree) SIM_API_SYMBOL(simGetObjectsInTree);
extern SIM_API_SYMBOL(ptrSimScaleObject) SIM_API_SYMBOL(simScaleObject);
extern SIM_API_SYMBOL(ptrSimSetShapeTexture) SIM_API_SYMBOL(simSetShapeTexture);
extern SIM_API_SYMBOL(ptrSimGetShapeTextureId) SIM_API_SYMBOL(simGetShapeTextureId);
extern SIM_API_SYMBOL(ptrSimCreateCollectionEx) SIM_API_SYMBOL(simCreateCollectionEx);
extern SIM_API_SYMBOL(ptrSimAddItemToCollection) SIM_API_SYMBOL(simAddItemToCollection);
extern SIM_API_SYMBOL(ptrSimDestroyCollection) SIM_API_SYMBOL(simDestroyCollection);
extern SIM_API_SYMBOL(ptrSimGetCollectionObjects) SIM_API_SYMBOL(simGetCollectionObjects);
extern SIM_API_SYMBOL(ptrSimAlignShapeBB) SIM_API_SYMBOL(simAlignShapeBB);
extern SIM_API_SYMBOL(ptrSimRelocateShapeFrame) SIM_API_SYMBOL(simRelocateShapeFrame);
extern SIM_API_SYMBOL(ptrSimSaveImage) SIM_API_SYMBOL(simSaveImage);
extern SIM_API_SYMBOL(ptrSimLoadImage) SIM_API_SYMBOL(simLoadImage);
extern SIM_API_SYMBOL(ptrSimGetScaledImage) SIM_API_SYMBOL(simGetScaledImage);
extern SIM_API_SYMBOL(ptrSimTransformImage) SIM_API_SYMBOL(simTransformImage);
extern SIM_API_SYMBOL(ptrSimGetQHull) SIM_API_SYMBOL(simGetQHull);
extern SIM_API_SYMBOL(ptrSimGetDecimatedMesh) SIM_API_SYMBOL(simGetDecimatedMesh);
extern SIM_API_SYMBOL(ptrSimCallScriptFunctionEx) SIM_API_SYMBOL(simCallScriptFunctionEx);
extern SIM_API_SYMBOL(ptrSimGetExtensionString) SIM_API_SYMBOL(simGetExtensionString);
extern SIM_API_SYMBOL(ptrSimComputeMassAndInertia) SIM_API_SYMBOL(simComputeMassAndInertia);
extern SIM_API_SYMBOL(ptrSimCreateStack) SIM_API_SYMBOL(simCreateStack);
extern SIM_API_SYMBOL(ptrSimReleaseStack) SIM_API_SYMBOL(simReleaseStack);
extern SIM_API_SYMBOL(ptrSimCopyStack) SIM_API_SYMBOL(simCopyStack);
extern SIM_API_SYMBOL(ptrSimPushNullOntoStack) SIM_API_SYMBOL(simPushNullOntoStack);
extern SIM_API_SYMBOL(ptrSimPushBoolOntoStack) SIM_API_SYMBOL(simPushBoolOntoStack);
extern SIM_API_SYMBOL(ptrSimPushInt32OntoStack) SIM_API_SYMBOL(simPushInt32OntoStack);
extern SIM_API_SYMBOL(ptrSimPushInt64OntoStack) SIM_API_SYMBOL(simPushInt64OntoStack);
extern SIM_API_SYMBOL(ptrSimPushFloatOntoStack) SIM_API_SYMBOL(simPushFloatOntoStack);
extern SIM_API_SYMBOL(ptrSimPushDoubleOntoStack) SIM_API_SYMBOL(simPushDoubleOntoStack);
extern SIM_API_SYMBOL(ptrSimPushTextOntoStack) SIM_API_SYMBOL(simPushTextOntoStack);
extern SIM_API_SYMBOL(ptrSimPushStringOntoStack) SIM_API_SYMBOL(simPushStringOntoStack);
extern SIM_API_SYMBOL(ptrSimPushBufferOntoStack) SIM_API_SYMBOL(simPushBufferOntoStack);
extern SIM_API_SYMBOL(ptrSimPushUInt8TableOntoStack) SIM_API_SYMBOL(simPushUInt8TableOntoStack);
extern SIM_API_SYMBOL(ptrSimPushInt32TableOntoStack) SIM_API_SYMBOL(simPushInt32TableOntoStack);
extern SIM_API_SYMBOL(ptrSimPushInt64TableOntoStack) SIM_API_SYMBOL(simPushInt64TableOntoStack);
extern SIM_API_SYMBOL(ptrSimPushFloatTableOntoStack) SIM_API_SYMBOL(simPushFloatTableOntoStack);
extern SIM_API_SYMBOL(ptrSimPushDoubleTableOntoStack) SIM_API_SYMBOL(simPushDoubleTableOntoStack);
extern SIM_API_SYMBOL(ptrSimPushTableOntoStack) SIM_API_SYMBOL(simPushTableOntoStack);
extern SIM_API_SYMBOL(ptrSimInsertDataIntoStackTable) SIM_API_SYMBOL(simInsertDataIntoStackTable);
extern SIM_API_SYMBOL(ptrSimGetStackSize) SIM_API_SYMBOL(simGetStackSize);
extern SIM_API_SYMBOL(ptrSimPopStackItem) SIM_API_SYMBOL(simPopStackItem);
extern SIM_API_SYMBOL(ptrSimMoveStackItemToTop) SIM_API_SYMBOL(simMoveStackItemToTop);
extern SIM_API_SYMBOL(ptrSimGetStackItemType) SIM_API_SYMBOL(simGetStackItemType);
extern SIM_API_SYMBOL(ptrSimGetStackStringType) SIM_API_SYMBOL(simGetStackStringType);
extern SIM_API_SYMBOL(ptrSimGetStackBoolValue) SIM_API_SYMBOL(simGetStackBoolValue);
extern SIM_API_SYMBOL(ptrSimGetStackInt32Value) SIM_API_SYMBOL(simGetStackInt32Value);
extern SIM_API_SYMBOL(ptrSimGetStackInt64Value) SIM_API_SYMBOL(simGetStackInt64Value);
extern SIM_API_SYMBOL(ptrSimGetStackFloatValue) SIM_API_SYMBOL(simGetStackFloatValue);
extern SIM_API_SYMBOL(ptrSimGetStackDoubleValue) SIM_API_SYMBOL(simGetStackDoubleValue);
extern SIM_API_SYMBOL(ptrSimGetStackStringValue) SIM_API_SYMBOL(simGetStackStringValue);
extern SIM_API_SYMBOL(ptrSimGetStackTableInfo) SIM_API_SYMBOL(simGetStackTableInfo);
extern SIM_API_SYMBOL(ptrSimGetStackUInt8Table) SIM_API_SYMBOL(simGetStackUInt8Table);
extern SIM_API_SYMBOL(ptrSimGetStackInt32Table) SIM_API_SYMBOL(simGetStackInt32Table);
extern SIM_API_SYMBOL(ptrSimGetStackInt64Table) SIM_API_SYMBOL(simGetStackInt64Table);
extern SIM_API_SYMBOL(ptrSimGetStackFloatTable) SIM_API_SYMBOL(simGetStackFloatTable);
extern SIM_API_SYMBOL(ptrSimGetStackDoubleTable) SIM_API_SYMBOL(simGetStackDoubleTable);
extern SIM_API_SYMBOL(ptrSimUnfoldStackTable) SIM_API_SYMBOL(simUnfoldStackTable);
extern SIM_API_SYMBOL(ptrSimDebugStack) SIM_API_SYMBOL(simDebugStack);
extern SIM_API_SYMBOL(ptrSimCreateOctree) SIM_API_SYMBOL(simCreateOctree);
extern SIM_API_SYMBOL(ptrSimCreatePointCloud) SIM_API_SYMBOL(simCreatePointCloud);
extern SIM_API_SYMBOL(ptrSimSetPointCloudOptions) SIM_API_SYMBOL(simSetPointCloudOptions);
extern SIM_API_SYMBOL(ptrSimGetPointCloudOptions) SIM_API_SYMBOL(simGetPointCloudOptions);
extern SIM_API_SYMBOL(ptrSimInsertVoxelsIntoOctree) SIM_API_SYMBOL(simInsertVoxelsIntoOctree);
extern SIM_API_SYMBOL(ptrSimRemoveVoxelsFromOctree) SIM_API_SYMBOL(simRemoveVoxelsFromOctree);
extern SIM_API_SYMBOL(ptrSimInsertPointsIntoPointCloud) SIM_API_SYMBOL(simInsertPointsIntoPointCloud);
extern SIM_API_SYMBOL(ptrSimRemovePointsFromPointCloud) SIM_API_SYMBOL(simRemovePointsFromPointCloud);
extern SIM_API_SYMBOL(ptrSimIntersectPointsWithPointCloud) SIM_API_SYMBOL(simIntersectPointsWithPointCloud);
extern SIM_API_SYMBOL(ptrSimGetOctreeVoxels) SIM_API_SYMBOL(simGetOctreeVoxels);
extern SIM_API_SYMBOL(ptrSimGetPointCloudPoints) SIM_API_SYMBOL(simGetPointCloudPoints);
extern SIM_API_SYMBOL(ptrSimInsertObjectIntoOctree) SIM_API_SYMBOL(simInsertObjectIntoOctree);
extern SIM_API_SYMBOL(ptrSimSubtractObjectFromOctree) SIM_API_SYMBOL(simSubtractObjectFromOctree);
extern SIM_API_SYMBOL(ptrSimInsertObjectIntoPointCloud) SIM_API_SYMBOL(simInsertObjectIntoPointCloud);
extern SIM_API_SYMBOL(ptrSimSubtractObjectFromPointCloud) SIM_API_SYMBOL(simSubtractObjectFromPointCloud);
extern SIM_API_SYMBOL(ptrSimCheckOctreePointOccupancy) SIM_API_SYMBOL(simCheckOctreePointOccupancy);
extern SIM_API_SYMBOL(ptrSimOpenTextEditor) SIM_API_SYMBOL(simOpenTextEditor);
extern SIM_API_SYMBOL(ptrSimPackTable) SIM_API_SYMBOL(simPackTable);
extern SIM_API_SYMBOL(ptrSimUnpackTable) SIM_API_SYMBOL(simUnpackTable);
extern SIM_API_SYMBOL(ptrSimSetReferencedHandles) SIM_API_SYMBOL(simSetReferencedHandles);
extern SIM_API_SYMBOL(ptrSimGetReferencedHandles) SIM_API_SYMBOL(simGetReferencedHandles);
extern SIM_API_SYMBOL(ptrSimGetShapeViz) SIM_API_SYMBOL(simGetShapeViz);
extern SIM_API_SYMBOL(ptrSimExecuteScriptString) SIM_API_SYMBOL(simExecuteScriptString);
extern SIM_API_SYMBOL(ptrSimGetApiFunc) SIM_API_SYMBOL(simGetApiFunc);
extern SIM_API_SYMBOL(ptrSimGetApiInfo) SIM_API_SYMBOL(simGetApiInfo);
extern SIM_API_SYMBOL(ptrSimGetPluginName) SIM_API_SYMBOL(simGetPluginName);
extern SIM_API_SYMBOL(ptrSimSetPluginInfo) SIM_API_SYMBOL(simSetPluginInfo);
extern SIM_API_SYMBOL(ptrSimGetPluginInfo) SIM_API_SYMBOL(simGetPluginInfo);
extern SIM_API_SYMBOL(ptrSimEventNotification) SIM_API_SYMBOL(simEventNotification);
extern SIM_API_SYMBOL(ptrSimApplyTexture) SIM_API_SYMBOL(simApplyTexture);
extern SIM_API_SYMBOL(ptrSimSetJointDependency) SIM_API_SYMBOL(simSetJointDependency);
extern SIM_API_SYMBOL(ptrSimGetJointDependency) SIM_API_SYMBOL(simGetJointDependency);
extern SIM_API_SYMBOL(ptrSimGetShapeMass) SIM_API_SYMBOL(simGetShapeMass);
extern SIM_API_SYMBOL(ptrSimSetShapeMass) SIM_API_SYMBOL(simSetShapeMass);
extern SIM_API_SYMBOL(ptrSimGetShapeInertia) SIM_API_SYMBOL(simGetShapeInertia);
extern SIM_API_SYMBOL(ptrSimSetShapeInertia) SIM_API_SYMBOL(simSetShapeInertia);
extern SIM_API_SYMBOL(ptrSimIsDynamicallyEnabled) SIM_API_SYMBOL(simIsDynamicallyEnabled);
extern SIM_API_SYMBOL(ptrSimGenerateShapeFromPath) SIM_API_SYMBOL(simGenerateShapeFromPath);
extern SIM_API_SYMBOL(ptrSimGetClosestPosOnPath) SIM_API_SYMBOL(simGetClosestPosOnPath);
extern SIM_API_SYMBOL(ptrSimInitScript) SIM_API_SYMBOL(simInitScript);
extern SIM_API_SYMBOL(ptrSimModuleEntry) SIM_API_SYMBOL(simModuleEntry);
extern SIM_API_SYMBOL(ptrSimCheckExecAuthorization) SIM_API_SYMBOL(simCheckExecAuthorization);
extern SIM_API_SYMBOL(ptr_simSetDynamicSimulationIconCode) SIM_API_SYMBOL(_simSetDynamicSimulationIconCode);
extern SIM_API_SYMBOL(ptr_simSetDynamicObjectFlagForVisualization) SIM_API_SYMBOL(_simSetDynamicObjectFlagForVisualization);
extern SIM_API_SYMBOL(ptr_simGetObjectListSize) SIM_API_SYMBOL(_simGetObjectListSize);
extern SIM_API_SYMBOL(ptr_simGetObjectFromIndex) SIM_API_SYMBOL(_simGetObjectFromIndex);
extern SIM_API_SYMBOL(ptr_simGetObjectID) SIM_API_SYMBOL(_simGetObjectID);
extern SIM_API_SYMBOL(ptr_simGetObjectType) SIM_API_SYMBOL(_simGetObjectType);
extern SIM_API_SYMBOL(ptr_simGetObjectChildren) SIM_API_SYMBOL(_simGetObjectChildren);
extern SIM_API_SYMBOL(ptr_simGetParentObject) SIM_API_SYMBOL(_simGetParentObject);
extern SIM_API_SYMBOL(ptr_simGetObject) SIM_API_SYMBOL(_simGetObject);
extern SIM_API_SYMBOL(ptr_simGetIkGroupObject) SIM_API_SYMBOL(_simGetIkGroupObject);
extern SIM_API_SYMBOL(ptr_simMpHandleIkGroupObject) SIM_API_SYMBOL(_simMpHandleIkGroupObject);
extern SIM_API_SYMBOL(ptr_simGetObjectLocalTransformation) SIM_API_SYMBOL(_simGetObjectLocalTransformation);
extern SIM_API_SYMBOL(ptr_simSetObjectLocalTransformation) SIM_API_SYMBOL(_simSetObjectLocalTransformation);
extern SIM_API_SYMBOL(ptr_simDynReportObjectCumulativeTransformation) SIM_API_SYMBOL(_simDynReportObjectCumulativeTransformation);
extern SIM_API_SYMBOL(ptr_simSetObjectCumulativeTransformation) SIM_API_SYMBOL(_simSetObjectCumulativeTransformation);
extern SIM_API_SYMBOL(ptr_simGetObjectCumulativeTransformation) SIM_API_SYMBOL(_simGetObjectCumulativeTransformation);
extern SIM_API_SYMBOL(ptr_simIsShapeDynamicallyStatic) SIM_API_SYMBOL(_simIsShapeDynamicallyStatic);
extern SIM_API_SYMBOL(ptr_simGetTreeDynamicProperty) SIM_API_SYMBOL(_simGetTreeDynamicProperty);
extern SIM_API_SYMBOL(ptr_simGetDummyLinkType) SIM_API_SYMBOL(_simGetDummyLinkType);
extern SIM_API_SYMBOL(ptr_simGetJointMode) SIM_API_SYMBOL(_simGetJointMode);
extern SIM_API_SYMBOL(ptr_simIsJointInHybridOperation) SIM_API_SYMBOL(_simIsJointInHybridOperation);
extern SIM_API_SYMBOL(ptr_simDisableDynamicTreeForManipulation) SIM_API_SYMBOL(_simDisableDynamicTreeForManipulation);
extern SIM_API_SYMBOL(ptr_simIsShapeDynamicallyRespondable) SIM_API_SYMBOL(_simIsShapeDynamicallyRespondable);
extern SIM_API_SYMBOL(ptr_simGetDynamicCollisionMask) SIM_API_SYMBOL(_simGetDynamicCollisionMask);
extern SIM_API_SYMBOL(ptr_simGetLastParentForLocalGlobalCollidable) SIM_API_SYMBOL(_simGetLastParentForLocalGlobalCollidable);
extern SIM_API_SYMBOL(ptr_simSetJointVelocity) SIM_API_SYMBOL(_simSetJointVelocity);
extern SIM_API_SYMBOL(ptr_simSetJointPosition) SIM_API_SYMBOL(_simSetJointPosition);
extern SIM_API_SYMBOL(ptr_simGetJointPosition) SIM_API_SYMBOL(_simGetJointPosition);
extern SIM_API_SYMBOL(ptr_simSetDynamicMotorPositionControlTargetPosition) SIM_API_SYMBOL(_simSetDynamicMotorPositionControlTargetPosition);
extern SIM_API_SYMBOL(ptr_simGetInitialDynamicVelocity) SIM_API_SYMBOL(_simGetInitialDynamicVelocity);
extern SIM_API_SYMBOL(ptr_simSetInitialDynamicVelocity) SIM_API_SYMBOL(_simSetInitialDynamicVelocity);
extern SIM_API_SYMBOL(ptr_simGetInitialDynamicAngVelocity) SIM_API_SYMBOL(_simGetInitialDynamicAngVelocity);
extern SIM_API_SYMBOL(ptr_simSetInitialDynamicAngVelocity) SIM_API_SYMBOL(_simSetInitialDynamicAngVelocity);
extern SIM_API_SYMBOL(ptr_simGetStartSleeping) SIM_API_SYMBOL(_simGetStartSleeping);
extern SIM_API_SYMBOL(ptr_simGetWasPutToSleepOnce) SIM_API_SYMBOL(_simGetWasPutToSleepOnce);
extern SIM_API_SYMBOL(ptr_simGetDynamicsFullRefreshFlag) SIM_API_SYMBOL(_simGetDynamicsFullRefreshFlag);
extern SIM_API_SYMBOL(ptr_simSetDynamicsFullRefreshFlag) SIM_API_SYMBOL(_simSetDynamicsFullRefreshFlag);
extern SIM_API_SYMBOL(ptr_simSetShapeDynamicVelocity) SIM_API_SYMBOL(_simSetShapeDynamicVelocity);
extern SIM_API_SYMBOL(ptr_simGetAdditionalForceAndTorque) SIM_API_SYMBOL(_simGetAdditionalForceAndTorque);
extern SIM_API_SYMBOL(ptr_simClearAdditionalForceAndTorque) SIM_API_SYMBOL(_simClearAdditionalForceAndTorque);
extern SIM_API_SYMBOL(ptr_simGetJointPositionInterval) SIM_API_SYMBOL(_simGetJointPositionInterval);
extern SIM_API_SYMBOL(ptr_simGetJointType) SIM_API_SYMBOL(_simGetJointType);
extern SIM_API_SYMBOL(ptr_simGetDynamicMotorTargetPosition) SIM_API_SYMBOL(_simGetDynamicMotorTargetPosition);
extern SIM_API_SYMBOL(ptr_simGetDynamicMotorTargetVelocity) SIM_API_SYMBOL(_simGetDynamicMotorTargetVelocity);
extern SIM_API_SYMBOL(ptr_simGetDynamicMotorMaxForce) SIM_API_SYMBOL(_simGetDynamicMotorMaxForce);
extern SIM_API_SYMBOL(ptr_simGetDynamicMotorUpperLimitVelocity) SIM_API_SYMBOL(_simGetDynamicMotorUpperLimitVelocity);
extern SIM_API_SYMBOL(ptr_simSetDynamicMotorReflectedPositionFromDynamicEngine) SIM_API_SYMBOL(_simSetDynamicMotorReflectedPositionFromDynamicEngine);
extern SIM_API_SYMBOL(ptr_simSetJointSphericalTransformation) SIM_API_SYMBOL(_simSetJointSphericalTransformation);
extern SIM_API_SYMBOL(ptr_simAddForceSensorCumulativeForcesAndTorques) SIM_API_SYMBOL(_simAddForceSensorCumulativeForcesAndTorques);
extern SIM_API_SYMBOL(ptr_simAddJointCumulativeForcesOrTorques) SIM_API_SYMBOL(_simAddJointCumulativeForcesOrTorques);
extern SIM_API_SYMBOL(ptr_simGetGeomWrapFromGeomProxy) SIM_API_SYMBOL(_simGetGeomWrapFromGeomProxy);
extern SIM_API_SYMBOL(ptr_simGetPurePrimitiveType) SIM_API_SYMBOL(_simGetPurePrimitiveType);
extern SIM_API_SYMBOL(ptr_simIsGeomWrapGeometric) SIM_API_SYMBOL(_simIsGeomWrapGeometric);
extern SIM_API_SYMBOL(ptr_simIsGeomWrapConvex) SIM_API_SYMBOL(_simIsGeomWrapConvex);
extern SIM_API_SYMBOL(ptr_simGetGeometricCount) SIM_API_SYMBOL(_simGetGeometricCount);
extern SIM_API_SYMBOL(ptr_simGetAllGeometrics) SIM_API_SYMBOL(_simGetAllGeometrics);
extern SIM_API_SYMBOL(ptr_simGetPurePrimitiveSizes) SIM_API_SYMBOL(_simGetPurePrimitiveSizes);
extern SIM_API_SYMBOL(ptr_simMakeDynamicAnnouncement) SIM_API_SYMBOL(_simMakeDynamicAnnouncement);
extern SIM_API_SYMBOL(ptr_simGetVerticesLocalFrame) SIM_API_SYMBOL(_simGetVerticesLocalFrame);
extern SIM_API_SYMBOL(ptr_simGetHeightfieldData) SIM_API_SYMBOL(_simGetHeightfieldData);
extern SIM_API_SYMBOL(ptr_simGetCumulativeMeshes) SIM_API_SYMBOL(_simGetCumulativeMeshes);
extern SIM_API_SYMBOL(ptr_simGetMass) SIM_API_SYMBOL(_simGetMass);
extern SIM_API_SYMBOL(ptr_simGetLocalInertiaInfo) SIM_API_SYMBOL(_simGetLocalInertiaInfo);
extern SIM_API_SYMBOL(ptr_simGetGravity) SIM_API_SYMBOL(_simGetGravity);
extern SIM_API_SYMBOL(ptr_simGetTimeDiffInMs) SIM_API_SYMBOL(_simGetTimeDiffInMs);
extern SIM_API_SYMBOL(ptr_simDoEntitiesCollide) SIM_API_SYMBOL(_simDoEntitiesCollide);
extern SIM_API_SYMBOL(ptr_simGetDistanceBetweenEntitiesIfSmaller) SIM_API_SYMBOL(_simGetDistanceBetweenEntitiesIfSmaller);
extern SIM_API_SYMBOL(ptr_simHandleJointControl) SIM_API_SYMBOL(_simHandleJointControl);
extern SIM_API_SYMBOL(ptr_simHandleCustomContact) SIM_API_SYMBOL(_simHandleCustomContact);
extern SIM_API_SYMBOL(ptr_simGetPureHollowScaling) SIM_API_SYMBOL(_simGetPureHollowScaling);
extern SIM_API_SYMBOL(ptr_simGetJointDynCtrlMode) SIM_API_SYMBOL(_simGetJointDynCtrlMode);
extern SIM_API_SYMBOL(ptr_simDynCallback) SIM_API_SYMBOL(_simDynCallback);

#include "simLib-old.h"
#endif
