#ifdef SIM_LIB_PREFIX
    static int simGetMaterialId(const char* materialName) { return SIM_API_SYMBOL(simGetMaterialId)(materialName); }
    static int simGetShapeMaterial(int shapeHandle) { return SIM_API_SYMBOL(simGetShapeMaterial)(shapeHandle); }
    static int simHandleVarious() { return SIM_API_SYMBOL(simHandleVarious)(); }
    static int simSerialPortOpen(int portNumber,int baudRate,void* reserved1,void* reserved2) { return SIM_API_SYMBOL(simSerialPortOpen)(portNumber,baudRate,reserved1,reserved2); }
    static int simSerialPortClose(int portNumber) { return SIM_API_SYMBOL(simSerialPortClose)(portNumber); }
    static int simSerialPortSend(int portNumber,const char* data,int dataLength) { return SIM_API_SYMBOL(simSerialPortSend)(portNumber,data,dataLength); }
    static int simSerialPortRead(int portNumber,char* buffer,int dataLengthToRead) { return SIM_API_SYMBOL(simSerialPortRead)(portNumber,buffer,dataLengthToRead); }
    static int simGetPathPlanningHandle(const char* pathPlanningObjectName) { return SIM_API_SYMBOL(simGetPathPlanningHandle)(pathPlanningObjectName); }
    static int simGetMotionPlanningHandle(const char* motionPlanningObjectName) { return SIM_API_SYMBOL(simGetMotionPlanningHandle)(motionPlanningObjectName); }
    static int simRemoveMotionPlanning(int motionPlanningHandle) { return SIM_API_SYMBOL(simRemoveMotionPlanning)(motionPlanningHandle); }
    static int simPerformPathSearchStep(int temporaryPathSearchObject,bool abortSearch) { return SIM_API_SYMBOL(simPerformPathSearchStep)(temporaryPathSearchObject,abortSearch); }
    static int simLockInterface(bool locked) { return SIM_API_SYMBOL(simLockInterface)(locked); }
    static int simCopyPasteSelectedObjects() { return SIM_API_SYMBOL(simCopyPasteSelectedObjects)(); }
    static int simResetPath(int pathHandle) { return SIM_API_SYMBOL(simResetPath)(pathHandle); }
    static int simResetJoint(int jointHandle) { return SIM_API_SYMBOL(simResetJoint)(jointHandle); }
    static int simAppendScriptArrayEntry(const char* reservedSetToNull,int scriptHandleOrType,const char* arrayNameAtScriptName,const char* keyName,const char* data,const int* what) { return SIM_API_SYMBOL(simAppendScriptArrayEntry)(reservedSetToNull,scriptHandleOrType,arrayNameAtScriptName,keyName,data,what); }
    static int simClearScriptVariable(const char* reservedSetToNull,int scriptHandleOrType,const char* variableNameAtScriptName) { return SIM_API_SYMBOL(simClearScriptVariable)(reservedSetToNull,scriptHandleOrType,variableNameAtScriptName); }
    static int simAddSceneCustomData(int header,const char* data,int dataLength) { return SIM_API_SYMBOL(simAddSceneCustomData)(header,data,dataLength); }
    static int simGetSceneCustomDataLength(int header) { return SIM_API_SYMBOL(simGetSceneCustomDataLength)(header); }
    static int simGetSceneCustomData(int header,char* data) { return SIM_API_SYMBOL(simGetSceneCustomData)(header,data); }
    static int simAddObjectCustomData(int objectHandle,int header,const char* data,int dataLength) { return SIM_API_SYMBOL(simAddObjectCustomData)(objectHandle,header,data,dataLength); }
    static int simGetObjectCustomDataLength(int objectHandle,int header) { return SIM_API_SYMBOL(simGetObjectCustomDataLength)(objectHandle,header); }
    static int simGetObjectCustomData(int objectHandle,int header,char* data) { return SIM_API_SYMBOL(simGetObjectCustomData)(objectHandle,header,data); }
    static int simCreateUI(const char* uiName,int menuAttributes,const int* clientSize,const int* cellSize,int* buttonHandles) { return SIM_API_SYMBOL(simCreateUI)(uiName,menuAttributes,clientSize,cellSize,buttonHandles); }
    static int simCreateUIButton(int uiHandle,const int* position,const int* size,int buttonProperty) { return SIM_API_SYMBOL(simCreateUIButton)(uiHandle,position,size,buttonProperty); }
    static int simGetUIHandle(const char* uiName) { return SIM_API_SYMBOL(simGetUIHandle)(uiName); }
    static int simGetUIProperty(int uiHandle) { return SIM_API_SYMBOL(simGetUIProperty)(uiHandle); }
    static int simGetUIEventButton(int uiHandle,int* auxiliaryValues) { return SIM_API_SYMBOL(simGetUIEventButton)(uiHandle,auxiliaryValues); }
    static int simSetUIProperty(int uiHandle,int elementProperty) { return SIM_API_SYMBOL(simSetUIProperty)(uiHandle,elementProperty); }
    static int simGetUIButtonProperty(int uiHandle,int buttonHandle) { return SIM_API_SYMBOL(simGetUIButtonProperty)(uiHandle,buttonHandle); }
    static int simSetUIButtonProperty(int uiHandle,int buttonHandle,int buttonProperty) { return SIM_API_SYMBOL(simSetUIButtonProperty)(uiHandle,buttonHandle,buttonProperty); }
    static int simGetUIButtonSize(int uiHandle,int buttonHandle,int* size) { return SIM_API_SYMBOL(simGetUIButtonSize)(uiHandle,buttonHandle,size); }
    static int simSetUIButtonLabel(int uiHandle,int buttonHandle,const char* upStateLabel,const char* downStateLabel) { return SIM_API_SYMBOL(simSetUIButtonLabel)(uiHandle,buttonHandle,upStateLabel,downStateLabel); }
    static char* simGetUIButtonLabel(int uiHandle,int buttonHandle) { return SIM_API_SYMBOL(simGetUIButtonLabel)(uiHandle,buttonHandle); }
    static int simSetUISlider(int uiHandle,int buttonHandle,int position) { return SIM_API_SYMBOL(simSetUISlider)(uiHandle,buttonHandle,position); }
    static int simGetUISlider(int uiHandle,int buttonHandle) { return SIM_API_SYMBOL(simGetUISlider)(uiHandle,buttonHandle); }
    static int simSetUIButtonTexture(int uiHandle,int buttonHandle,const int* size,const char* textureData) { return SIM_API_SYMBOL(simSetUIButtonTexture)(uiHandle,buttonHandle,size,textureData); }
    static int simCreateUIButtonArray(int uiHandle,int buttonHandle) { return SIM_API_SYMBOL(simCreateUIButtonArray)(uiHandle,buttonHandle); }
    static int simDeleteUIButtonArray(int uiHandle,int buttonHandle) { return SIM_API_SYMBOL(simDeleteUIButtonArray)(uiHandle,buttonHandle); }
    static int simRemoveUI(int uiHandle) { return SIM_API_SYMBOL(simRemoveUI)(uiHandle); }
    static int simSetUIPosition(int uiHandle,const int* position) { return SIM_API_SYMBOL(simSetUIPosition)(uiHandle,position); }
    static int simGetUIPosition(int uiHandle,int* position) { return SIM_API_SYMBOL(simGetUIPosition)(uiHandle,position); }
    static int simLoadUI(const char* filename,int maxCount,int* uiHandles) { return SIM_API_SYMBOL(simLoadUI)(filename,maxCount,uiHandles); }
    static int simSaveUI(int count,const int* uiHandles,const char* filename) { return SIM_API_SYMBOL(simSaveUI)(count,uiHandles,filename); }
    static int simHandleGeneralCallbackScript(int callbackId,int callbackTag,void* additionalData) { return SIM_API_SYMBOL(simHandleGeneralCallbackScript)(callbackId,callbackTag,additionalData); }
    static int simRegisterCustomLuaFunction(const char* funcName,const char* callTips,const int* inputArgumentTypes,void(*callBack)(struct SLuaCallBack* p)) { return SIM_API_SYMBOL(simRegisterCustomLuaFunction)(funcName, callTips, inputArgumentTypes, callBack); }
    static int simRegisterCustomLuaVariable(const char* varName,const char* varValue) { return SIM_API_SYMBOL(simRegisterCustomLuaVariable)(varName,varValue); }
    static int simGetMechanismHandle(const char* mechanismName) { return SIM_API_SYMBOL(simGetMechanismHandle)(mechanismName); }
    static int simHandleMechanism(int mechanismHandle) { return SIM_API_SYMBOL(simHandleMechanism)(mechanismHandle); }
    static int simHandleCustomizationScripts(int callType) { return SIM_API_SYMBOL(simHandleCustomizationScripts)(callType); }
    static int simResetMilling(int objectHandle) { return SIM_API_SYMBOL(simResetMilling)(objectHandle); }
    static int simResetMill(int millHandle) { return SIM_API_SYMBOL(simResetMill)(millHandle); }
    static int simApplyMilling(int objectHandle) { return SIM_API_SYMBOL(simApplyMilling)(objectHandle); }
    static bool _simGetParentFollowsDynamic(const void* shape) { return SIM_API_SYMBOL(_simGetParentFollowsDynamic)(shape); }
    static int simGetNameSuffix(const char* name) { return SIM_API_SYMBOL(simGetNameSuffix)(name); }
    static int simSetNameSuffix(int nameSuffixNumber) { return SIM_API_SYMBOL(simSetNameSuffix)(nameSuffixNumber); }
    static int simAddStatusbarMessage(const char* message) { return SIM_API_SYMBOL(simAddStatusbarMessage)(message); }
    static char* simGetScriptSimulationParameter(int scriptHandle,const char* parameterName,int* parameterLength) { return SIM_API_SYMBOL(simGetScriptSimulationParameter)(scriptHandle,parameterName,parameterLength); }
    static int simSetScriptSimulationParameter(int scriptHandle,const char* parameterName,const char* parameterValue,int parameterLength) { return SIM_API_SYMBOL(simSetScriptSimulationParameter)(scriptHandle,parameterName,parameterValue,parameterLength); }
    static char* simGetScriptRawBuffer(int scriptHandle,int bufferHandle) { return SIM_API_SYMBOL(simGetScriptRawBuffer)(scriptHandle,bufferHandle); }
    static int simSetScriptRawBuffer(int scriptHandle,const char* buffer,int bufferSize) { return SIM_API_SYMBOL(simSetScriptRawBuffer)(scriptHandle,buffer,bufferSize); }
    static int simReleaseScriptRawBuffer(int scriptHandle,int bufferHandle) { return SIM_API_SYMBOL(simReleaseScriptRawBuffer)(scriptHandle,bufferHandle); }
    static int simRemoveIkGroup(int ikGroupHandle) { return SIM_API_SYMBOL(simRemoveIkGroup)(ikGroupHandle); }
    static int simExportIk(const char* pathAndFilename,int reserved1,void* reserved2) { return SIM_API_SYMBOL(simExportIk)(pathAndFilename,reserved1,reserved2); }
    static int simComputeJacobian(int ikGroupHandle,int options,void* reserved) { return SIM_API_SYMBOL(simComputeJacobian)(ikGroupHandle,options,reserved); }
    static int simGetIkGroupHandle(const char* ikGroupName) { return SIM_API_SYMBOL(simGetIkGroupHandle)(ikGroupName); }
    static int simHandleIkGroup(int ikGroupHandle) { return SIM_API_SYMBOL(simHandleIkGroup)(ikGroupHandle); }
    static int simSetThreadIsFree(bool freeMode) { return SIM_API_SYMBOL(simSetThreadIsFree)(freeMode); }
    static int simTubeOpen(int dataHeader,const char* dataName,int readBufferSize,bool notUsedButKeepFalse) { return SIM_API_SYMBOL(simTubeOpen)(dataHeader,dataName,readBufferSize,notUsedButKeepFalse); }
    static int simTubeClose(int tubeHandle) { return SIM_API_SYMBOL(simTubeClose)(tubeHandle); }
    static int simTubeWrite(int tubeHandle,const char* data,int dataLength) { return SIM_API_SYMBOL(simTubeWrite)(tubeHandle,data,dataLength); }
    static char* simTubeRead(int tubeHandle,int* dataLength) { return SIM_API_SYMBOL(simTubeRead)(tubeHandle,dataLength); }
    static int simTubeStatus(int tubeHandle,int* readPacketsCount,int* writePacketsCount) { return SIM_API_SYMBOL(simTubeStatus)(tubeHandle,readPacketsCount,writePacketsCount); }
    static char* simReceiveData(int dataHeader,const char* dataName,int antennaHandle,int index,int* dataLength,int* senderID,int* dataHeaderR,char** dataNameR) { return SIM_API_SYMBOL(simReceiveData)(dataHeader,dataName,antennaHandle,index,dataLength,senderID,dataHeaderR,dataNameR); }
    static int simInsertPathCtrlPoints(int pathHandle,int options,int startIndex,int ptCnt,const void* ptData) { return SIM_API_SYMBOL(simInsertPathCtrlPoints)(pathHandle,options,startIndex,ptCnt,ptData); }
    static int simCutPathCtrlPoints(int pathHandle,int startIndex,int ptCnt) { return SIM_API_SYMBOL(simCutPathCtrlPoints)(pathHandle,startIndex,ptCnt); }
    static int simGetThreadId() { return SIM_API_SYMBOL(simGetThreadId)(); }
    static int simSwitchThread() { return SIM_API_SYMBOL(simSwitchThread)(); }
    static int simLockResources(int lockType,int reserved) { return SIM_API_SYMBOL(simLockResources)(lockType,reserved); }
    static int simUnlockResources(int lockHandle) { return SIM_API_SYMBOL(simUnlockResources)(lockHandle); }
    static char* simGetUserParameter(int objectHandle,const char* parameterName,int* parameterLength) { return SIM_API_SYMBOL(simGetUserParameter)(objectHandle,parameterName,parameterLength); }
    static int simSetUserParameter(int objectHandle,const char* parameterName,const char* parameterValue,int parameterLength) { return SIM_API_SYMBOL(simSetUserParameter)(objectHandle,parameterName,parameterValue,parameterLength); }
    static int simCreateCollection(const char* collectionName,int options) { return SIM_API_SYMBOL(simCreateCollection)(collectionName,options); }
    static int simAddObjectToCollection(int collectionHandle,int objectHandle,int what,int options) { return SIM_API_SYMBOL(simAddObjectToCollection)(collectionHandle,objectHandle,what,options); }
    static int simGetCollectionHandle(const char* collectionName) { return SIM_API_SYMBOL(simGetCollectionHandle)(collectionName); }
    static int simRemoveCollection(int collectionHandle) { return SIM_API_SYMBOL(simRemoveCollection)(collectionHandle); }
    static int simEmptyCollection(int collectionHandle) { return SIM_API_SYMBOL(simEmptyCollection)(collectionHandle); }
    static char* simGetCollectionName(int collectionHandle) { return SIM_API_SYMBOL(simGetCollectionName)(collectionHandle); }
    static int simSetCollectionName(int collectionHandle,const char* collectionName) { return SIM_API_SYMBOL(simSetCollectionName)(collectionHandle,collectionName); }extern ptrSimGetMaterialId simGetMaterialId;
    static int simGetCollisionHandle(const char* collisionObjectName) { return SIM_API_SYMBOL(simGetCollisionHandle)(collisionObjectName); }
    static int simGetDistanceHandle(const char* distanceObjectName) { return SIM_API_SYMBOL(simGetDistanceHandle)(distanceObjectName); }
    static int simResetCollision(int collisionObjectHandle) { return SIM_API_SYMBOL(simResetCollision)(collisionObjectHandle); }
    static int simResetDistance(int distanceObjectHandle) { return SIM_API_SYMBOL(simResetDistance)(distanceObjectHandle); }
    static int simHandleCollision(int collisionObjectHandle) { return SIM_API_SYMBOL(simHandleCollision)(collisionObjectHandle); }
    static int simReadCollision(int collisionObjectHandle) { return SIM_API_SYMBOL(simReadCollision)(collisionObjectHandle); }
    static int simRemoveBanner(int bannerID) { return SIM_API_SYMBOL(simRemoveBanner)(bannerID); }
    static char* simGetObjectName(int objectHandle) { return SIM_API_SYMBOL(simGetObjectName)(objectHandle); }
    static int simSetObjectName(int objectHandle,const char* objectName) { return SIM_API_SYMBOL(simSetObjectName)(objectHandle,objectName); }
    static char* simGetScriptName(int scriptHandle) { return SIM_API_SYMBOL(simGetScriptName)(scriptHandle); }
    static int simGetScriptHandle(const char* scriptName) { return SIM_API_SYMBOL(simGetScriptHandle)(scriptName); }
    static int simSetScriptVariable(int scriptHandleOrType,const char* variableNameAtScriptName,int stackHandle) { return SIM_API_SYMBOL(simSetScriptVariable)(scriptHandleOrType,variableNameAtScriptName,stackHandle); }
    static int simGetObjectHandle(const char* objectAlias) { return SIM_API_SYMBOL(simGetObjectHandle)(objectAlias); }
    static int simGetObjectHandleEx(const char* objectAlias,int index,int proxy,int options) { return SIM_API_SYMBOL(simGetObjectHandleEx)(objectAlias,index,proxy,options); }
    static int simGetScript(int index) { return SIM_API_SYMBOL(simGetScript)(index); }
    static int simGetScriptAssociatedWithObject(int objectHandle) { return SIM_API_SYMBOL(simGetScriptAssociatedWithObject)(objectHandle); }
    static int simGetCustomizationScriptAssociatedWithObject(int objectHandle) { return SIM_API_SYMBOL(simGetCustomizationScriptAssociatedWithObject)(objectHandle); }
    static int simGetObjectAssociatedWithScript(int scriptHandle) { return SIM_API_SYMBOL(simGetObjectAssociatedWithScript)(scriptHandle); }
    static char* simGetObjectConfiguration(int objectHandle) { return SIM_API_SYMBOL(simGetObjectConfiguration)(objectHandle); }
    static int simSetObjectConfiguration(const char* data) { return SIM_API_SYMBOL(simSetObjectConfiguration)(data); }
    static char* simGetConfigurationTree(int objectHandle) { return SIM_API_SYMBOL(simGetConfigurationTree)(objectHandle); }
    static int simSetConfigurationTree(const char* data) { return SIM_API_SYMBOL(simSetConfigurationTree)(data); }
    static int simEnableEventCallback(int eventCallbackType,const char* plugin,int reserved) { return SIM_API_SYMBOL(simEnableEventCallback)(eventCallbackType,plugin,reserved); }
    static int simRMLPosition(int dofs,double timeStep,int flags,const double* currentPosVelAccel,const double* maxVelAccelJerk,const bool* selection,const double* targetPosVel,double* newPosVelAccel,void* auxData) { return SIM_API_SYMBOL(simRMLPosition)(dofs,timeStep,flags,currentPosVelAccel,maxVelAccelJerk,selection,targetPosVel,newPosVelAccel,auxData); }
    static int simRMLVelocity(int dofs,double timeStep,int flags,const double* currentPosVelAccel,const double* maxAccelJerk,const bool* selection,const double* targetVel,double* newPosVelAccel,void* auxData) { return SIM_API_SYMBOL(simRMLVelocity)(dofs,timeStep,flags,currentPosVelAccel,maxAccelJerk,selection,targetVel,newPosVelAccel,auxData); }
    static int simRMLPos(int dofs,double smallestTimeStep,int flags,const double* currentPosVelAccel,const double* maxVelAccelJerk,const bool* selection,const double* targetPosVel,void* auxData) { return SIM_API_SYMBOL(simRMLPos)(dofs,smallestTimeStep,flags,currentPosVelAccel,maxVelAccelJerk,selection,targetPosVel,auxData); }
    static int simRMLVel(int dofs,double smallestTimeStep,int flags,const double* currentPosVelAccel,const double* maxAccelJerk,const bool* selection,const double* targetVel,void* auxData) { return SIM_API_SYMBOL(simRMLVel)(dofs,smallestTimeStep,flags,currentPosVelAccel,maxAccelJerk,selection,targetVel,auxData); }
    static int simRMLStep(int handle,double timeStep,double* newPosVelAccel,void* auxData,void* reserved) { return SIM_API_SYMBOL(simRMLStep)(handle,timeStep,newPosVelAccel,auxData,reserved); }
    static int simRMLRemove(int handle) { return SIM_API_SYMBOL(simRMLRemove)(handle); }
    static int simGetSystemTimeInMilliseconds() { return SIM_API_SYMBOL(simGetSystemTimeInMilliseconds)(); }
    static unsigned int simGetSystemTimeInMs(int previousTime) { return SIM_API_SYMBOL(simGetSystemTimeInMs)(previousTime); }
    static char* simFileDialog(int mode,const char* title,const char* startPath,const char* initName,const char* extName,const char* ext) { return SIM_API_SYMBOL(simFileDialog)(mode,title,startPath,initName,extName,ext); }
    static int simMsgBox(int dlgType,int buttons,const char* title,const char* message) { return SIM_API_SYMBOL(simMsgBox)(dlgType,buttons,title,message); }
    static int simGetDialogResult(int genericDialogHandle) { return SIM_API_SYMBOL(simGetDialogResult)(genericDialogHandle); }
    static char* simGetDialogInput(int genericDialogHandle) { return SIM_API_SYMBOL(simGetDialogInput)(genericDialogHandle); }
    static int simEndDialog(int genericDialogHandle) { return SIM_API_SYMBOL(simEndDialog)(genericDialogHandle); }
    static int simIsObjectInSelection(int objectHandle) { return SIM_API_SYMBOL(simIsObjectInSelection)(objectHandle); }
    static int simAddObjectToSelection(int what,int objectHandle) { return SIM_API_SYMBOL(simAddObjectToSelection)(what,objectHandle); }
    static int simRemoveObjectFromSelection(int what,int objectHandle) { return SIM_API_SYMBOL(simRemoveObjectFromSelection)(what,objectHandle); }
    static int simGetObjectSelectionSize() { return SIM_API_SYMBOL(simGetObjectSelectionSize)(); }
    static int simGetObjectLastSelection() { return SIM_API_SYMBOL(simGetObjectLastSelection)(); }
    static int simGetObjectSelection(int* objectHandles) { return SIM_API_SYMBOL(simGetObjectSelection)(objectHandles); }
    static int simDeleteSelectedObjects() { return SIM_API_SYMBOL(simDeleteSelectedObjects)(); }
    static int simGetObjectUniqueIdentifier(int objectHandle,int* uniqueIdentifier) { return SIM_API_SYMBOL(simGetObjectUniqueIdentifier)(objectHandle,uniqueIdentifier); }
    static void _simSetDynamicJointLocalTransformationPart2IsValid(void* joint,bool valid) { return SIM_API_SYMBOL(_simSetDynamicJointLocalTransformationPart2IsValid)(joint,valid); }
    static void _simSetDynamicForceSensorLocalTransformationPart2IsValid(void* forceSensor,bool valid) { return SIM_API_SYMBOL(_simSetDynamicForceSensorLocalTransformationPart2IsValid)(forceSensor,valid); }
    static bool _simIsForceSensorBroken(const void* forceSensor) { return SIM_API_SYMBOL(_simIsForceSensorBroken)(forceSensor); }
    static int simBreakForceSensor(int objectHandle) { return SIM_API_SYMBOL(simBreakForceSensor)(objectHandle); }
    static int simSetScriptText(int scriptHandle,const char* scriptText) { return SIM_API_SYMBOL(simSetScriptText)(scriptHandle,scriptText); }
    static const char* simGetScriptText(int scriptHandle) { return SIM_API_SYMBOL(simGetScriptText)(scriptHandle); }
    static int simGetScriptProperty(int scriptHandle,int* scriptProperty,int* associatedObjectHandle) { return SIM_API_SYMBOL(simGetScriptProperty)(scriptHandle,scriptProperty,associatedObjectHandle); }
    static void _simSetGeomProxyDynamicsFullRefreshFlag(void* geomData,bool flag) { return SIM_API_SYMBOL(_simSetGeomProxyDynamicsFullRefreshFlag)(geomData,flag); }
    static bool _simGetGeomProxyDynamicsFullRefreshFlag(const void* geomData) { return SIM_API_SYMBOL(_simGetGeomProxyDynamicsFullRefreshFlag)(geomData); }
    static int simRemoveObject(int objectHandle) { return SIM_API_SYMBOL(simRemoveObject)(objectHandle); }
    static void _simSetShapeIsStaticAndNotRespondableButDynamicTag(const void* shape,bool tag) { return SIM_API_SYMBOL(_simSetShapeIsStaticAndNotRespondableButDynamicTag)(shape,tag); }
    static bool _simGetShapeIsStaticAndNotRespondableButDynamicTag(const void* shape) { return SIM_API_SYMBOL(_simGetShapeIsStaticAndNotRespondableButDynamicTag)(shape); }
    static int simGetVisionSensorResolution(int visionSensorHandle,int* resolution) { return SIM_API_SYMBOL(simGetVisionSensorResolution)(visionSensorHandle,resolution); }
    static unsigned char* simGetVisionSensorCharImage(int visionSensorHandle,int* resolutionX,int* resolutionY) { return SIM_API_SYMBOL(simGetVisionSensorCharImage)(visionSensorHandle,resolutionX,resolutionY); }
    static int simSetVisionSensorCharImage(int visionSensorHandle,const unsigned char* image) { return SIM_API_SYMBOL(simSetVisionSensorCharImage)(visionSensorHandle,image); }
    static void* simBroadcastMessage(int* auxiliaryData,void* customData,int* replyData) { return SIM_API_SYMBOL(simBroadcastMessage)(auxiliaryData,customData,replyData); }
    static void* simSendModuleMessage(int message,int* auxiliaryData,void* customData,int* replyData) { return SIM_API_SYMBOL(simSendModuleMessage)(message,auxiliaryData,customData,replyData); }
    static bool _simIsDynamicMotorEnabled(const void* joint) { return SIM_API_SYMBOL(_simIsDynamicMotorEnabled)(joint); }
    static bool _simIsDynamicMotorPositionCtrlEnabled(const void* joint) { return SIM_API_SYMBOL(_simIsDynamicMotorPositionCtrlEnabled)(joint); }
    static bool _simIsDynamicMotorTorqueModulationEnabled(const void* joint) { return SIM_API_SYMBOL(_simIsDynamicMotorTorqueModulationEnabled)(joint); }
    static int _simGetContactCallbackCount() { return SIM_API_SYMBOL(_simGetContactCallbackCount)(); }
    static const void* _simGetContactCallback(int index) { return SIM_API_SYMBOL(_simGetContactCallback)(index); }
    static int _simGetJointCallbackCallOrder(const void* joint) { return SIM_API_SYMBOL(_simGetJointCallbackCallOrder)(joint); }
    static int simSetDoubleSignal(const char* signalName,double signalValue) { return SIM_API_SYMBOL(simSetDoubleSignal)(signalName,signalValue); }
    static int simGetDoubleSignal(const char* signalName,double* signalValue) { return SIM_API_SYMBOL(simGetDoubleSignal)(signalName,signalValue); }
    static int simClearDoubleSignal(const char* signalName) { return SIM_API_SYMBOL(simClearDoubleSignal)(signalName); }
    static int simRemoveParticleObject(int objectHandle) { return SIM_API_SYMBOL(simRemoveParticleObject)(objectHandle); }
    static int simAddParticleObject(int objectType,SIMDOUBLE size,SIMDOUBLE density,const void* params,SIMDOUBLE lifeTime,int maxItemCount,const float* color,const float* setToNULL,const float* setToNULL2,const float* setToNULL3) { return SIM_API_SYMBOL(simAddParticleObject)(objectType,size,density,params,lifeTime,maxItemCount,color,setToNULL,setToNULL2,setToNULL3); }
    static int simAddParticleObjectItem(int objectHandle,const SIMDOUBLE* itemData) { return SIM_API_SYMBOL(simAddParticleObjectItem)(objectHandle,itemData); }
    static int simJointGetForce(int jointHandle,SIMDOUBLE* forceOrTorque) { return SIM_API_SYMBOL(simJointGetForce)(jointHandle,forceOrTorque); }
    static int simGetMpConfigForTipPose(int motionPlanningObjectHandle,int options,SIMDOUBLE closeNodesDistance,int trialCount,const SIMDOUBLE* tipPose,int maxTimeInMs,SIMDOUBLE* outputJointPositions,const SIMDOUBLE* referenceConfigs,int referenceConfigCount,const SIMDOUBLE* jointWeights,const int* jointBehaviour,int correctionPasses) { return SIM_API_SYMBOL(simGetMpConfigForTipPose)(motionPlanningObjectHandle,options,closeNodesDistance,trialCount,tipPose,maxTimeInMs,outputJointPositions,referenceConfigs,referenceConfigCount,jointWeights,jointBehaviour,correctionPasses); }
    static SIMDOUBLE* simFindMpPath(int motionPlanningObjectHandle,const SIMDOUBLE* startConfig,const SIMDOUBLE* goalConfig,int options,SIMDOUBLE stepSize,int* outputConfigsCnt,int maxTimeInMs,SIMDOUBLE* reserved,const int* auxIntParams,const SIMDOUBLE* auxFloatParams) { return SIM_API_SYMBOL(simFindMpPath)(motionPlanningObjectHandle,startConfig,goalConfig,options,stepSize,outputConfigsCnt,maxTimeInMs,reserved,auxIntParams,auxFloatParams); }
    static SIMDOUBLE* simSimplifyMpPath(int motionPlanningObjectHandle,const SIMDOUBLE* pathBuffer,int configCnt,int options,SIMDOUBLE stepSize,int increment,int* outputConfigsCnt,int maxTimeInMs,SIMDOUBLE* reserved,const int* auxIntParams,const SIMDOUBLE* auxFloatParams) { return SIM_API_SYMBOL(simSimplifyMpPath)(motionPlanningObjectHandle,pathBuffer,configCnt,options,stepSize,increment,outputConfigsCnt,maxTimeInMs,reserved,auxIntParams,auxFloatParams); }
    static SIMDOUBLE* simFindIkPath(int motionPlanningObjectHandle,const SIMDOUBLE* startConfig,const SIMDOUBLE* goalPose,int options,SIMDOUBLE stepSize,int* outputConfigsCnt,SIMDOUBLE* reserved,const int* auxIntParams,const SIMDOUBLE* auxFloatParams) { return SIM_API_SYMBOL(simFindIkPath)(motionPlanningObjectHandle,startConfig,goalPose,options,stepSize,outputConfigsCnt,reserved,auxIntParams,auxFloatParams); }
    static SIMDOUBLE* simGetMpConfigTransition(int motionPlanningObjectHandle,const SIMDOUBLE* startConfig,const SIMDOUBLE* goalConfig,int options,const int* select,SIMDOUBLE calcStepSize,SIMDOUBLE maxOutStepSize,int wayPointCnt,const SIMDOUBLE* wayPoints,int* outputConfigsCnt,const int* auxIntParams,const SIMDOUBLE* auxFloatParams) { return SIM_API_SYMBOL(simGetMpConfigTransition)(motionPlanningObjectHandle,startConfig,goalConfig,options,select,calcStepSize,maxOutStepSize,wayPointCnt,wayPoints,outputConfigsCnt,auxIntParams,auxFloatParams); }
    static int simCreateMotionPlanning(int jointCnt,const int* jointHandles,const int* jointRangeSubdivisions,const SIMDOUBLE* jointMetricWeights,int options,const int* intParams,const SIMDOUBLE* floatParams,const void* reserved) { return SIM_API_SYMBOL(simCreateMotionPlanning)(jointCnt,jointHandles,jointRangeSubdivisions,jointMetricWeights,options,intParams,floatParams,reserved); }
    static int simSearchPath(int pathPlanningObjectHandle,SIMDOUBLE maximumSearchTime) { return SIM_API_SYMBOL(simSearchPath)(pathPlanningObjectHandle,maximumSearchTime); }
    static int simInitializePathSearch(int pathPlanningObjectHandle,SIMDOUBLE maximumSearchTime,SIMDOUBLE searchTimeStep) { return SIM_API_SYMBOL(simInitializePathSearch)(pathPlanningObjectHandle,maximumSearchTime,searchTimeStep); }
    static int simHandlePath(int pathHandle,SIMDOUBLE deltaTime) { return SIM_API_SYMBOL(simHandlePath)(pathHandle,deltaTime); }
    static int simHandleJoint(int jointHandle,SIMDOUBLE deltaTime) { return SIM_API_SYMBOL(simHandleJoint)(jointHandle,deltaTime); }
    static int simSetUIButtonColor(int uiHandle,int buttonHandle,const float* upStateColor,const float* downStateColor,const float* labelColor) { return SIM_API_SYMBOL(simSetUIButtonColor)(uiHandle,buttonHandle,upStateColor,downStateColor,labelColor); }
    static int simSetUIButtonArrayColor(int uiHandle,int buttonHandle,const int* position,const float* color) { return SIM_API_SYMBOL(simSetUIButtonArrayColor)(uiHandle,buttonHandle,position,color); }
    static int simRegisterContactCallback(int(*callBack)(int,int,int,int*,SIMDOUBLE*)) { return SIM_API_SYMBOL(simRegisterContactCallback)(callBack); }
    static int simSetJointForce(int objectHandle,SIMDOUBLE forceOrTorque) { return SIM_API_SYMBOL(simSetJointForce)(objectHandle,forceOrTorque); }
    static int simHandleMill(int millHandle,SIMDOUBLE* removedSurfaceAndVolume) { return SIM_API_SYMBOL(simHandleMill)(millHandle,removedSurfaceAndVolume); }
    static int simSetShapeMassAndInertia(int shapeHandle,SIMDOUBLE mass,const SIMDOUBLE* inertiaMatrix,const SIMDOUBLE* centerOfMass,const SIMDOUBLE* transformation) { return SIM_API_SYMBOL(simSetShapeMassAndInertia)(shapeHandle,mass,inertiaMatrix,centerOfMass,transformation); }
    static int simGetShapeMassAndInertia(int shapeHandle,SIMDOUBLE* mass,SIMDOUBLE* inertiaMatrix,SIMDOUBLE* centerOfMass,const SIMDOUBLE* transformation) { return SIM_API_SYMBOL(simGetShapeMassAndInertia)(shapeHandle,mass,inertiaMatrix,centerOfMass,transformation); }
    static int simCheckIkGroup(int ikGroupHandle,int jointCnt,const int* jointHandles,SIMDOUBLE* jointValues,const int* jointOptions) { return SIM_API_SYMBOL(simCheckIkGroup)(ikGroupHandle,jointCnt,jointHandles,jointValues,jointOptions); }
    static int simCreateIkGroup(int options,const int* intParams,const SIMDOUBLE* floatParams,const void* reserved) { return SIM_API_SYMBOL(simCreateIkGroup)(options,intParams,floatParams,reserved); }
    static int simCreateIkElement(int ikGroupHandle,int options,const int* intParams,const SIMDOUBLE* floatParams,const void* reserved) { return SIM_API_SYMBOL(simCreateIkElement)(ikGroupHandle,options,intParams,floatParams,reserved); }
    static int simGetConfigForTipPose(int ikGroupHandle,int jointCnt,const int* jointHandles,SIMDOUBLE thresholdDist,int maxTimeInMs,SIMDOUBLE* retConfig,const SIMDOUBLE* metric,int collisionPairCnt,const int* collisionPairs,const int* jointOptions,const SIMDOUBLE* lowLimits,const SIMDOUBLE* ranges,void* reserved) { return SIM_API_SYMBOL(simGetConfigForTipPose)(ikGroupHandle,jointCnt,jointHandles,thresholdDist,maxTimeInMs,retConfig,metric,collisionPairCnt,collisionPairs,jointOptions,lowLimits,ranges,reserved); }
    static SIMDOUBLE* simGenerateIkPath(int ikGroupHandle,int jointCnt,const int* jointHandles,int ptCnt,int collisionPairCnt,const int* collisionPairs,const int* jointOptions,void* reserved) { return SIM_API_SYMBOL(simGenerateIkPath)(ikGroupHandle,jointCnt,jointHandles,ptCnt,collisionPairCnt,collisionPairs,jointOptions,reserved); }
    static SIMDOUBLE* simGetIkGroupMatrix(int ikGroupHandle,int options,int* matrixSize) { return SIM_API_SYMBOL(simGetIkGroupMatrix)(ikGroupHandle,options,matrixSize); }
    static int simSetIkGroupProperties(int ikGroupHandle,int resolutionMethod,int maxIterations,SIMDOUBLE damping,void* reserved) { return SIM_API_SYMBOL(simSetIkGroupProperties)(ikGroupHandle,resolutionMethod,maxIterations,damping,reserved); }
    static int simGetPositionOnPath(int pathHandle,SIMDOUBLE relativeDistance,SIMDOUBLE* position) { return SIM_API_SYMBOL(simGetPositionOnPath)(pathHandle,relativeDistance,position); }
    static int simGetOrientationOnPath(int pathHandle,SIMDOUBLE relativeDistance,SIMDOUBLE* eulerAngles) { return SIM_API_SYMBOL(simGetOrientationOnPath)(pathHandle,relativeDistance,eulerAngles); }
    static int simGetDataOnPath(int pathHandle,SIMDOUBLE relativeDistance,int dataType,int* intData,SIMDOUBLE* floatData) { return SIM_API_SYMBOL(simGetDataOnPath)(pathHandle,relativeDistance,dataType,intData,floatData); }
    static int simGetClosestPositionOnPath(int pathHandle,SIMDOUBLE* absolutePosition,SIMDOUBLE* pathPosition) { return SIM_API_SYMBOL(simGetClosestPositionOnPath)(pathHandle,absolutePosition,pathPosition); }
    static int simGetPathPosition(int objectHandle,SIMDOUBLE* position) { return SIM_API_SYMBOL(simGetPathPosition)(objectHandle,position); }
    static int simSetPathPosition(int objectHandle,SIMDOUBLE position) { return SIM_API_SYMBOL(simSetPathPosition)(objectHandle,position); }
    static int simGetPathLength(int objectHandle,SIMDOUBLE* length) { return SIM_API_SYMBOL(simGetPathLength)(objectHandle,length); }
    static int simCreatePath(int attributes,const int* intParams,const SIMDOUBLE* floatParams,const float* color) { return SIM_API_SYMBOL(simCreatePath)(attributes,intParams,floatParams,color); }
    static int simSetPathTargetNominalVelocity(int objectHandle,SIMDOUBLE targetNominalVelocity) { return SIM_API_SYMBOL(simSetPathTargetNominalVelocity)(objectHandle,targetNominalVelocity); }
    static int simHandleDistance(int distanceObjectHandle,SIMDOUBLE* smallestDistance) { return SIM_API_SYMBOL(simHandleDistance)(distanceObjectHandle,smallestDistance); }
    static int simReadDistance(int distanceObjectHandle,SIMDOUBLE* smallestDistance) { return SIM_API_SYMBOL(simReadDistance)(distanceObjectHandle,smallestDistance); }
    static int simAddBanner(const char* label,SIMDOUBLE size,int options,const SIMDOUBLE* positionAndEulerAngles,int parentObjectHandle,const float* labelColors,const float* backgroundColors) { return SIM_API_SYMBOL(simAddBanner)(label,size,options,positionAndEulerAngles,parentObjectHandle,labelColors,backgroundColors); }
    static int simAddGhost(int ghostGroup,int objectHandle,int options,SIMDOUBLE startTime,SIMDOUBLE endTime,const float* color) { return SIM_API_SYMBOL(simAddGhost)(ghostGroup,objectHandle,options,startTime,endTime,color); }
    static int simModifyGhost(int ghostGroup,int ghostId,int operation,SIMDOUBLE floatValue,int options,int optionsMask,const SIMDOUBLE* colorOrTransformation) { return SIM_API_SYMBOL(simModifyGhost)(ghostGroup,ghostId,operation,floatValue,options,optionsMask,colorOrTransformation); }
    static int simSetGraphUserData(int graphHandle,const char* streamName,SIMDOUBLE data) { return SIM_API_SYMBOL(simSetGraphUserData)(graphHandle,streamName,data); }
    static int simCopyMatrix(const SIMDOUBLE* matrixIn,SIMDOUBLE* matrixOut) { return SIM_API_SYMBOL(simCopyMatrix)(matrixIn,matrixOut); }
    static int simSetVisionSensorFilter(int visionSensorHandle,int filterIndex,int options,const int* pSizes,const unsigned char* bytes,const int* ints,const SIMDOUBLE* floats,const unsigned char* custom) { return SIM_API_SYMBOL(simSetVisionSensorFilter)(visionSensorHandle,filterIndex,options,pSizes,bytes,ints,floats,custom); }
    static int simGetVisionSensorFilter(int visionSensorHandle,int filterIndex,int* options,int* pSizes,unsigned char** bytes,int** ints,SIMDOUBLE** floats,unsigned char** custom) { return SIM_API_SYMBOL(simGetVisionSensorFilter)(visionSensorHandle,filterIndex,options,pSizes,bytes,ints,floats,custom); }
    static int simSetIkElementProperties(int ikGroupHandle,int tipDummyHandle,int constraints,const SIMDOUBLE* precision,const SIMDOUBLE* weight,void* reserved) { return SIM_API_SYMBOL(simSetIkElementProperties)(ikGroupHandle,tipDummyHandle,constraints,precision,weight,reserved); }
    static int simSendData(int targetID,int dataHeader,const char* dataName,const char* data,int dataLength,int antennaHandle,SIMDOUBLE actionRadius,SIMDOUBLE emissionAngle1,SIMDOUBLE emissionAngle2,SIMDOUBLE persistence) { return SIM_API_SYMBOL(simSendData)(targetID,dataHeader,dataName,data,dataLength,antennaHandle,actionRadius,emissionAngle1,emissionAngle2,persistence); }
    static int simSetObjectSizeValues(int objectHandle,const SIMDOUBLE* sizeValues) { return SIM_API_SYMBOL(simSetObjectSizeValues)(objectHandle,sizeValues); }
    static int simGetObjectSizeValues(int objectHandle,SIMDOUBLE* sizeValues) { return SIM_API_SYMBOL(simGetObjectSizeValues)(objectHandle,sizeValues); }
    static int simDisplayDialog(const char* titleText,const char* mainText,int dialogType,const char* initialText,const float* titleColors,const float* dialogColors,int* elementHandle) { return SIM_API_SYMBOL(simDisplayDialog)(titleText,mainText,dialogType,initialText,titleColors,dialogColors,elementHandle); }
    static int simScaleSelectedObjects(SIMDOUBLE scalingFactor,bool scalePositionsToo) { return SIM_API_SYMBOL(simScaleSelectedObjects)(scalingFactor,scalePositionsToo); }
    static void _simSetDynamicJointLocalTransformationPart2(void* joint,const SIMDOUBLE* pos,const SIMDOUBLE* quat) { return SIM_API_SYMBOL(_simSetDynamicJointLocalTransformationPart2)(joint,pos,quat); }
    static void _simSetDynamicForceSensorLocalTransformationPart2(void* forceSensor,const SIMDOUBLE* pos,const SIMDOUBLE* quat) { return SIM_API_SYMBOL(_simSetDynamicForceSensorLocalTransformationPart2)(forceSensor,pos,quat); }
    static void _simGetDynamicForceSensorLocalTransformationPart2(const void* forceSensor,SIMDOUBLE* pos,SIMDOUBLE* quat) { return SIM_API_SYMBOL(_simGetDynamicForceSensorLocalTransformationPart2)(forceSensor,pos,quat); }
    static int simSetScriptAttribute(int scriptHandle,int attributeID,SIMDOUBLE floatVal,int intOrBoolVal) { return SIM_API_SYMBOL(simSetScriptAttribute)(scriptHandle,attributeID,floatVal,intOrBoolVal); }
    static int simGetScriptAttribute(int scriptHandle,int attributeID,SIMDOUBLE* floatVal,int* intOrBoolVal) { return SIM_API_SYMBOL(simGetScriptAttribute)(scriptHandle,attributeID,floatVal,intOrBoolVal); }
    static int simGetJointMaxForce(int jointHandle,SIMDOUBLE* forceOrTorque) { return SIM_API_SYMBOL(simGetJointMaxForce)(jointHandle,forceOrTorque); }
    static int simSetJointMaxForce(int objectHandle,SIMDOUBLE forceOrTorque) { return SIM_API_SYMBOL(simSetJointMaxForce)(objectHandle,forceOrTorque); }
    static float* simGetVisionSensorImage(int visionSensorHandle) { return SIM_API_SYMBOL(simGetVisionSensorImage)(visionSensorHandle); }
    static int simSetVisionSensorImage(int visionSensorHandle,const float* image) { return SIM_API_SYMBOL(simSetVisionSensorImage)(visionSensorHandle,image); }
    static float* simGetVisionSensorDepthBuffer(int visionSensorHandle) { return SIM_API_SYMBOL(simGetVisionSensorDepthBuffer)(visionSensorHandle); }
    static int simCreatePureShape(int primitiveType,int options,const SIMDOUBLE* sizes,SIMDOUBLE mass,const int* precision) { return SIM_API_SYMBOL(simCreatePureShape)(primitiveType,options,sizes,mass,precision); }
    static void _simGetMotorPid(const void* joint,SIMDOUBLE* pParam,SIMDOUBLE* iParam,SIMDOUBLE* dParam) { return SIM_API_SYMBOL(_simGetMotorPid)(joint,pParam,iParam,dParam); }
    static int simBuildMatrixQ(const SIMDOUBLE* position,const SIMDOUBLE* quaternion,SIMDOUBLE* matrix) { return SIM_API_SYMBOL(simBuildMatrixQ)(position,quaternion,matrix); }
    static int simGetQuaternionFromMatrix(const SIMDOUBLE* matrix,SIMDOUBLE* quaternion) { return SIM_API_SYMBOL(simGetQuaternionFromMatrix)(matrix,quaternion); }
    static void _simGetPrincipalMomentOfInertia(const void* geomInfo,SIMDOUBLE* inertia) { return SIM_API_SYMBOL(_simGetPrincipalMomentOfInertia)(geomInfo,inertia); }
    static void _simGetLocalInertiaFrame(const void* geomInfo,SIMDOUBLE* pos,SIMDOUBLE* quat) { return SIM_API_SYMBOL(_simGetLocalInertiaFrame)(geomInfo,pos,quat); }
    static int simGetShapeVertex(int shapeHandle,int groupElementIndex,int vertexIndex,SIMDOUBLE* relativePosition) { return SIM_API_SYMBOL(simGetShapeVertex)(shapeHandle,groupElementIndex,vertexIndex,relativePosition); }
    static int simGetShapeTriangle(int shapeHandle,int groupElementIndex,int triangleIndex,int* vertexIndices,SIMDOUBLE* triangleNormals) { return SIM_API_SYMBOL(simGetShapeTriangle)(shapeHandle,groupElementIndex,triangleIndex,vertexIndices,triangleNormals); }
#endif

typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetMaterialId))(const char* materialName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetShapeMaterial))(int shapeHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleVarious))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSerialPortOpen))(int portNumber,int baudRate,void* reserved1,void* reserved2);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSerialPortClose))(int portNumber);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSerialPortSend))(int portNumber,const char* data,int dataLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSerialPortRead))(int portNumber,char* buffer,int dataLengthToRead);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetPathPlanningHandle))(const char* pathPlanningObjectName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetMotionPlanningHandle))(const char* motionPlanningObjectName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveMotionPlanning))(int motionPlanningHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimPerformPathSearchStep))(int temporaryPathSearchObject,bool abortSearch);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimLockInterface))(bool locked);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCopyPasteSelectedObjects))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimResetPath))(int pathHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimResetJoint))(int jointHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAppendScriptArrayEntry))(const char* reservedSetToNull,int scriptHandleOrType,const char* arrayNameAtScriptName,const char* keyName,const char* data,const int* what);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimClearScriptVariable))(const char* reservedSetToNull,int scriptHandleOrType,const char* variableNameAtScriptName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddSceneCustomData))(int header,const char* data,int dataLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetSceneCustomDataLength))(int header);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetSceneCustomData))(int header,char* data);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddObjectCustomData))(int objectHandle,int header,const char* data,int dataLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectCustomDataLength))(int objectHandle,int header);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectCustomData))(int objectHandle,int header,char* data);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCreateUI))(const char* uiName,int menuAttributes,const int* clientSize,const int* cellSize,int* buttonHandles);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCreateUIButton))(int uiHandle,const int* position,const int* size,int buttonProperty);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetUIHandle))(const char* uiName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetUIProperty))(int uiHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetUIEventButton))(int uiHandle,int* auxiliaryValues);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetUIProperty))(int uiHandle,int elementProperty);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetUIButtonProperty))(int uiHandle,int buttonHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetUIButtonProperty))(int uiHandle,int buttonHandle,int buttonProperty);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetUIButtonSize))(int uiHandle,int buttonHandle,int* size);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetUIButtonLabel))(int uiHandle,int buttonHandle,const char* upStateLabel,const char* downStateLabel);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetUIButtonLabel))(int uiHandle,int buttonHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetUISlider))(int uiHandle,int buttonHandle,int position);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetUISlider))(int uiHandle,int buttonHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetUIButtonTexture))(int uiHandle,int buttonHandle,const int* size,const char* textureData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCreateUIButtonArray))(int uiHandle,int buttonHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimDeleteUIButtonArray))(int uiHandle,int buttonHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveUI))(int uiHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetUIPosition))(int uiHandle,const int* position);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetUIPosition))(int uiHandle,int* position);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimLoadUI))(const char* filename,int maxCount,int* uiHandles);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSaveUI))(int count,const int* uiHandles,const char* filename);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleGeneralCallbackScript))(int callbackId,int callbackTag,void* additionalData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRegisterCustomLuaFunction))(const char* funcName,const char* callTips,const int* inputArgumentTypes,void(*callBack)(struct SLuaCallBack* p));
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRegisterCustomLuaVariable))(const char* varName,const char* varValue);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetMechanismHandle))(const char* mechanismName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleMechanism))(int mechanismHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleCustomizationScripts))(int callType);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimResetMilling))(int objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimResetMill))(int millHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimApplyMilling))(int objectHandle);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simGetParentFollowsDynamic))(const void* shape);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetNameSuffix))(const char* name);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetNameSuffix))(int nameSuffixNumber);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddStatusbarMessage))(const char* message);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetScriptSimulationParameter))(int scriptHandle,const char* parameterName,int* parameterLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetScriptSimulationParameter))(int scriptHandle,const char* parameterName,const char* parameterValue,int parameterLength);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetScriptRawBuffer))(int scriptHandle,int bufferHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetScriptRawBuffer))(int scriptHandle,const char* buffer,int bufferSize);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimReleaseScriptRawBuffer))(int scriptHandle,int bufferHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveIkGroup))(int ikGroupHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimExportIk))(const char* pathAndFilename,int reserved1,void* reserved2);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimComputeJacobian))(int ikGroupHandle,int options,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetIkGroupHandle))(const char* ikGroupName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleIkGroup))(int ikGroupHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetThreadIsFree))(bool freeMode);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimTubeOpen))(int dataHeader,const char* dataName,int readBufferSize,bool notUsedButKeepFalse);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimTubeClose))(int tubeHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimTubeWrite))(int tubeHandle,const char* data,int dataLength);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimTubeRead))(int tubeHandle,int* dataLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimTubeStatus))(int tubeHandle,int* readPacketsCount,int* writePacketsCount);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimReceiveData))(int dataHeader,const char* dataName,int antennaHandle,int index,int* dataLength,int* senderID,int* dataHeaderR,char** dataNameR);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimInsertPathCtrlPoints))(int pathHandle,int options,int startIndex,int ptCnt,const void* ptData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCutPathCtrlPoints))(int pathHandle,int startIndex,int ptCnt);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetThreadId))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSwitchThread))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimLockResources))(int lockType,int reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimUnlockResources))(int lockHandle);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetUserParameter))(int objectHandle,const char* parameterName,int* parameterLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetUserParameter))(int objectHandle,const char* parameterName,const char* parameterValue,int parameterLength);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCreateCollection))(const char* collectionName,int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddObjectToCollection))(int collectionHandle,int objectHandle,int what,int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetCollectionHandle))(const char* collectionName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveCollection))(int collectionHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimEmptyCollection))(int collectionHandle);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetCollectionName))(int collectionHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetCollectionName))(int collectionHandle,const char* collectionName);extern ptrSimGetMaterialId simGetMaterialId;
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetCollisionHandle))(const char* collisionObjectName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetDistanceHandle))(const char* distanceObjectName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimResetCollision))(int collisionObjectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimResetDistance))(int distanceObjectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleCollision))(int collisionObjectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimReadCollision))(int collisionObjectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveBanner))(int bannerID);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectName))(int objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectName))(int objectHandle,const char* objectName);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetScriptName))(int scriptHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetScriptHandle))(const char* scriptName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetScriptVariable))(int scriptHandleOrType,const char* variableNameAtScriptName,int stackHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectHandle))(const char* objectAlias);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectHandleEx))(const char* objectAlias,int index,int proxy,int options);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetScript))(int index);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetScriptAssociatedWithObject))(int objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetCustomizationScriptAssociatedWithObject))(int objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectAssociatedWithScript))(int scriptHandle);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectConfiguration))(int objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectConfiguration))(const char* data);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetConfigurationTree))(int objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetConfigurationTree))(const char* data);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimEnableEventCallback))(int eventCallbackType,const char* plugin,int reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRMLPosition))(int dofs,double timeStep,int flags,const double* currentPosVelAccel,const double* maxVelAccelJerk,const bool* selection,const double* targetPosVel,double* newPosVelAccel,void* auxData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRMLVelocity))(int dofs,double timeStep,int flags,const double* currentPosVelAccel,const double* maxAccelJerk,const bool* selection,const double* targetVel,double* newPosVelAccel,void* auxData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRMLPos))(int dofs,double smallestTimeStep,int flags,const double* currentPosVelAccel,const double* maxVelAccelJerk,const bool* selection,const double* targetPosVel,void* auxData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRMLVel))(int dofs,double smallestTimeStep,int flags,const double* currentPosVelAccel,const double* maxAccelJerk,const bool* selection,const double* targetVel,void* auxData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRMLStep))(int handle,double timeStep,double* newPosVelAccel,void* auxData,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRMLRemove))(int handle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetSystemTimeInMilliseconds))();
typedef unsigned int (__cdecl *SIM_API_SYMBOL(ptrSimGetSystemTimeInMs))(int previousTime);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimFileDialog))(int mode,const char* title,const char* startPath,const char* initName,const char* extName,const char* ext);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimMsgBox))(int dlgType,int buttons,const char* title,const char* message);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetDialogResult))(int genericDialogHandle);
typedef char* (__cdecl *SIM_API_SYMBOL(ptrSimGetDialogInput))(int genericDialogHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimEndDialog))(int genericDialogHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimIsObjectInSelection))(int objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddObjectToSelection))(int what,int objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveObjectFromSelection))(int what,int objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectSelectionSize))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectLastSelection))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectSelection))(int* objectHandles);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimDeleteSelectedObjects))();
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectUniqueIdentifier))(int objectHandle,int* uniqueIdentifier);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetDynamicJointLocalTransformationPart2IsValid))(void* joint,bool valid);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetDynamicForceSensorLocalTransformationPart2IsValid))(void* forceSensor,bool valid);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simIsForceSensorBroken))(const void* forceSensor);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimBreakForceSensor))(int objectHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetScriptText))(int scriptHandle,const char* scriptText);
typedef const char* (__cdecl *SIM_API_SYMBOL(ptrSimGetScriptText))(int scriptHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetScriptProperty))(int scriptHandle,int* scriptProperty,int* associatedObjectHandle);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetGeomProxyDynamicsFullRefreshFlag))(void* geomData,bool flag);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simGetGeomProxyDynamicsFullRefreshFlag))(const void* geomData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveObject))(int objectHandle);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetShapeIsStaticAndNotRespondableButDynamicTag))(const void* shape,bool tag);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simGetShapeIsStaticAndNotRespondableButDynamicTag))(const void* shape);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetVisionSensorResolution))(int visionSensorHandle,int* resolution);
typedef unsigned char* (__cdecl *SIM_API_SYMBOL(ptrSimGetVisionSensorCharImage))(int visionSensorHandle,int* resolutionX,int* resolutionY);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetVisionSensorCharImage))(int visionSensorHandle,const unsigned char* image);
typedef void* (__cdecl *SIM_API_SYMBOL(ptrSimBroadcastMessage))(int* auxiliaryData,void* customData,int* replyData);
typedef void* (__cdecl *SIM_API_SYMBOL(ptrSimSendModuleMessage))(int message,int* auxiliaryData,void* customData,int* replyData);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simIsDynamicMotorEnabled))(const void* joint);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simIsDynamicMotorPositionCtrlEnabled))(const void* joint);
typedef bool (__cdecl *SIM_API_SYMBOL(ptr_simIsDynamicMotorTorqueModulationEnabled))(const void* joint);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simGetContactCallbackCount))();
typedef const void* (__cdecl *SIM_API_SYMBOL(ptr_simGetContactCallback))(int index);
typedef int (__cdecl *SIM_API_SYMBOL(ptr_simGetJointCallbackCallOrder))(const void* joint);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetDoubleSignal))(const char* signalName,double signalValue);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetDoubleSignal))(const char* signalName,double* signalValue);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimClearDoubleSignal))(const char* signalName);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRemoveParticleObject))(int objectHandle);
/* deprecated, and previously single precision functions: */
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddParticleObject))(int objectType,SIMDOUBLE size,SIMDOUBLE density,const void* params,SIMDOUBLE lifeTime,int maxItemCount,const float* color,const float* setToNULL,const float* setToNULL2,const float* setToNULL3);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddParticleObjectItem))(int objectHandle,const SIMDOUBLE* itemData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimJointGetForce))(int jointHandle,SIMDOUBLE* forceOrTorque);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetMpConfigForTipPose))(int motionPlanningObjectHandle,int options,SIMDOUBLE closeNodesDistance,int trialCount,const SIMDOUBLE* tipPose,int maxTimeInMs,SIMDOUBLE* outputJointPositions,const SIMDOUBLE* referenceConfigs,int referenceConfigCount,const SIMDOUBLE* jointWeights,const int* jointBehaviour,int correctionPasses);
typedef SIMDOUBLE* (__cdecl *SIM_API_SYMBOL(ptrSimFindMpPath))(int motionPlanningObjectHandle,const SIMDOUBLE* startConfig,const SIMDOUBLE* goalConfig,int options,SIMDOUBLE stepSize,int* outputConfigsCnt,int maxTimeInMs,SIMDOUBLE* reserved,const int* auxIntParams,const SIMDOUBLE* auxFloatParams);
typedef SIMDOUBLE* (__cdecl *SIM_API_SYMBOL(ptrSimSimplifyMpPath))(int motionPlanningObjectHandle,const SIMDOUBLE* pathBuffer,int configCnt,int options,SIMDOUBLE stepSize,int increment,int* outputConfigsCnt,int maxTimeInMs,SIMDOUBLE* reserved,const int* auxIntParams,const SIMDOUBLE* auxFloatParams);
typedef SIMDOUBLE* (__cdecl *SIM_API_SYMBOL(ptrSimFindIkPath))(int motionPlanningObjectHandle,const SIMDOUBLE* startConfig,const SIMDOUBLE* goalPose,int options,SIMDOUBLE stepSize,int* outputConfigsCnt,SIMDOUBLE* reserved,const int* auxIntParams,const SIMDOUBLE* auxFloatParams);
typedef SIMDOUBLE* (__cdecl *SIM_API_SYMBOL(ptrSimGetMpConfigTransition))(int motionPlanningObjectHandle,const SIMDOUBLE* startConfig,const SIMDOUBLE* goalConfig,int options,const int* select,SIMDOUBLE calcStepSize,SIMDOUBLE maxOutStepSize,int wayPointCnt,const SIMDOUBLE* wayPoints,int* outputConfigsCnt,const int* auxIntParams,const SIMDOUBLE* auxFloatParams);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCreateMotionPlanning))(int jointCnt,const int* jointHandles,const int* jointRangeSubdivisions,const SIMDOUBLE* jointMetricWeights,int options,const int* intParams,const SIMDOUBLE* floatParams,const void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSearchPath))(int pathPlanningObjectHandle,SIMDOUBLE maximumSearchTime);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimInitializePathSearch))(int pathPlanningObjectHandle,SIMDOUBLE maximumSearchTime,SIMDOUBLE searchTimeStep);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandlePath))(int pathHandle,SIMDOUBLE deltaTime);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleJoint))(int jointHandle,SIMDOUBLE deltaTime);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetUIButtonColor))(int uiHandle,int buttonHandle,const float* upStateColor,const float* downStateColor,const float* labelColor);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetUIButtonArrayColor))(int uiHandle,int buttonHandle,const int* position,const float* color);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimRegisterContactCallback))(int(*callBack)(int,int,int,int*,SIMDOUBLE*));
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetJointForce))(int objectHandle,SIMDOUBLE forceOrTorque);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleMill))(int millHandle,SIMDOUBLE* removedSurfaceAndVolume);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetShapeMassAndInertia))(int shapeHandle,SIMDOUBLE mass,const SIMDOUBLE* inertiaMatrix,const SIMDOUBLE* centerOfMass,const SIMDOUBLE* transformation);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetShapeMassAndInertia))(int shapeHandle,SIMDOUBLE* mass,SIMDOUBLE* inertiaMatrix,SIMDOUBLE* centerOfMass,const SIMDOUBLE* transformation);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCheckIkGroup))(int ikGroupHandle,int jointCnt,const int* jointHandles,SIMDOUBLE* jointValues,const int* jointOptions);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCreateIkGroup))(int options,const int* intParams,const SIMDOUBLE* floatParams,const void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCreateIkElement))(int ikGroupHandle,int options,const int* intParams,const SIMDOUBLE* floatParams,const void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetConfigForTipPose))(int ikGroupHandle,int jointCnt,const int* jointHandles,SIMDOUBLE thresholdDist,int maxTimeInMs,SIMDOUBLE* retConfig,const SIMDOUBLE* metric,int collisionPairCnt,const int* collisionPairs,const int* jointOptions,const SIMDOUBLE* lowLimits,const SIMDOUBLE* ranges,void* reserved);
typedef SIMDOUBLE* (__cdecl *SIM_API_SYMBOL(ptrSimGenerateIkPath))(int ikGroupHandle,int jointCnt,const int* jointHandles,int ptCnt,int collisionPairCnt,const int* collisionPairs,const int* jointOptions,void* reserved);
typedef SIMDOUBLE* (__cdecl *SIM_API_SYMBOL(ptrSimGetIkGroupMatrix))(int ikGroupHandle,int options,int* matrixSize);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetIkGroupProperties))(int ikGroupHandle,int resolutionMethod,int maxIterations,SIMDOUBLE damping,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetPositionOnPath))(int pathHandle,SIMDOUBLE relativeDistance,SIMDOUBLE* position);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetOrientationOnPath))(int pathHandle,SIMDOUBLE relativeDistance,SIMDOUBLE* eulerAngles);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetDataOnPath))(int pathHandle,SIMDOUBLE relativeDistance,int dataType,int* intData,SIMDOUBLE* floatData);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetClosestPositionOnPath))(int pathHandle,SIMDOUBLE* absolutePosition,SIMDOUBLE* pathPosition);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetPathPosition))(int objectHandle,SIMDOUBLE* position);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetPathPosition))(int objectHandle,SIMDOUBLE position);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetPathLength))(int objectHandle,SIMDOUBLE* length);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCreatePath))(int attributes,const int* intParams,const SIMDOUBLE* floatParams,const float* color);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetPathTargetNominalVelocity))(int objectHandle,SIMDOUBLE targetNominalVelocity);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimHandleDistance))(int distanceObjectHandle,SIMDOUBLE* smallestDistance);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimReadDistance))(int distanceObjectHandle,SIMDOUBLE* smallestDistance);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddBanner))(const char* label,SIMDOUBLE size,int options,const SIMDOUBLE* positionAndEulerAngles,int parentObjectHandle,const float* labelColors,const float* backgroundColors);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimAddGhost))(int ghostGroup,int objectHandle,int options,SIMDOUBLE startTime,SIMDOUBLE endTime,const float* color);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimModifyGhost))(int ghostGroup,int ghostId,int operation,SIMDOUBLE floatValue,int options,int optionsMask,const SIMDOUBLE* colorOrTransformation);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetGraphUserData))(int graphHandle,const char* streamName,SIMDOUBLE data);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCopyMatrix))(const SIMDOUBLE* matrixIn,SIMDOUBLE* matrixOut);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetVisionSensorFilter))(int visionSensorHandle,int filterIndex,int options,const int* pSizes,const unsigned char* bytes,const int* ints,const SIMDOUBLE* floats,const unsigned char* custom);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetVisionSensorFilter))(int visionSensorHandle,int filterIndex,int* options,int* pSizes,unsigned char** bytes,int** ints,SIMDOUBLE** floats,unsigned char** custom);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetIkElementProperties))(int ikGroupHandle,int tipDummyHandle,int constraints,const SIMDOUBLE* precision,const SIMDOUBLE* weight,void* reserved);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSendData))(int targetID,int dataHeader,const char* dataName,const char* data,int dataLength,int antennaHandle,SIMDOUBLE actionRadius,SIMDOUBLE emissionAngle1,SIMDOUBLE emissionAngle2,SIMDOUBLE persistence);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetObjectSizeValues))(int objectHandle,const SIMDOUBLE* sizeValues);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetObjectSizeValues))(int objectHandle,SIMDOUBLE* sizeValues);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimDisplayDialog))(const char* titleText,const char* mainText,int dialogType,const char* initialText,const float* titleColors,const float* dialogColors,int* elementHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimScaleSelectedObjects))(SIMDOUBLE scalingFactor,bool scalePositionsToo);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetDynamicJointLocalTransformationPart2))(void* joint,const SIMDOUBLE* pos,const SIMDOUBLE* quat);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simSetDynamicForceSensorLocalTransformationPart2))(void* forceSensor,const SIMDOUBLE* pos,const SIMDOUBLE* quat);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetDynamicForceSensorLocalTransformationPart2))(const void* forceSensor,SIMDOUBLE* pos,SIMDOUBLE* quat);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetScriptAttribute))(int scriptHandle,int attributeID,SIMDOUBLE floatVal,int intOrBoolVal);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetScriptAttribute))(int scriptHandle,int attributeID,SIMDOUBLE* floatVal,int* intOrBoolVal);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetJointMaxForce))(int jointHandle,SIMDOUBLE* forceOrTorque);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetJointMaxForce))(int objectHandle,SIMDOUBLE forceOrTorque);
typedef float* (__cdecl *SIM_API_SYMBOL(ptrSimGetVisionSensorImage))(int visionSensorHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimSetVisionSensorImage))(int visionSensorHandle,const float* image);
typedef float* (__cdecl *SIM_API_SYMBOL(ptrSimGetVisionSensorDepthBuffer))(int visionSensorHandle);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimCreatePureShape))(int primitiveType,int options,const SIMDOUBLE* sizes,SIMDOUBLE mass,const int* precision);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetMotorPid))(const void* joint,SIMDOUBLE* pParam,SIMDOUBLE* iParam,SIMDOUBLE* dParam);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimBuildMatrixQ))(const SIMDOUBLE* position,const SIMDOUBLE* quaternion,SIMDOUBLE* matrix);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetQuaternionFromMatrix))(const SIMDOUBLE* matrix,SIMDOUBLE* quaternion);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetPrincipalMomentOfInertia))(const void* geomInfo,SIMDOUBLE* inertia);
typedef void (__cdecl *SIM_API_SYMBOL(ptr_simGetLocalInertiaFrame))(const void* geomInfo,SIMDOUBLE* pos,SIMDOUBLE* quat);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetShapeVertex))(int shapeHandle,int groupElementIndex,int vertexIndex,SIMDOUBLE* relativePosition);
typedef int (__cdecl *SIM_API_SYMBOL(ptrSimGetShapeTriangle))(int shapeHandle,int groupElementIndex,int triangleIndex,int* vertexIndices,SIMDOUBLE* triangleNormals);

extern SIM_API_SYMBOL(ptrSimGetShapeMaterial) SIM_API_SYMBOL(simGetShapeMaterial);
extern SIM_API_SYMBOL(ptrSimHandleVarious) SIM_API_SYMBOL(simHandleVarious);
extern SIM_API_SYMBOL(ptrSimSerialPortOpen) SIM_API_SYMBOL(simSerialPortOpen);
extern SIM_API_SYMBOL(ptrSimSerialPortClose) SIM_API_SYMBOL(simSerialPortClose);
extern SIM_API_SYMBOL(ptrSimSerialPortSend) SIM_API_SYMBOL(simSerialPortSend);
extern SIM_API_SYMBOL(ptrSimSerialPortRead) SIM_API_SYMBOL(simSerialPortRead);
extern SIM_API_SYMBOL(ptrSimJointGetForce) SIM_API_SYMBOL(simJointGetForce);
extern SIM_API_SYMBOL(ptrSimGetPathPlanningHandle) SIM_API_SYMBOL(simGetPathPlanningHandle);
extern SIM_API_SYMBOL(ptrSimGetMotionPlanningHandle) SIM_API_SYMBOL(simGetMotionPlanningHandle);
extern SIM_API_SYMBOL(ptrSimGetMpConfigForTipPose) SIM_API_SYMBOL(simGetMpConfigForTipPose);
extern SIM_API_SYMBOL(ptrSimFindMpPath) SIM_API_SYMBOL(simFindMpPath);
extern SIM_API_SYMBOL(ptrSimSimplifyMpPath) SIM_API_SYMBOL(simSimplifyMpPath);
extern SIM_API_SYMBOL(ptrSimFindIkPath) SIM_API_SYMBOL(simFindIkPath);
extern SIM_API_SYMBOL(ptrSimGetMpConfigTransition) SIM_API_SYMBOL(simGetMpConfigTransition);
extern SIM_API_SYMBOL(ptrSimCreateMotionPlanning) SIM_API_SYMBOL(simCreateMotionPlanning);
extern SIM_API_SYMBOL(ptrSimRemoveMotionPlanning) SIM_API_SYMBOL(simRemoveMotionPlanning);
extern SIM_API_SYMBOL(ptrSimSearchPath) SIM_API_SYMBOL(simSearchPath);
extern SIM_API_SYMBOL(ptrSimInitializePathSearch) SIM_API_SYMBOL(simInitializePathSearch);
extern SIM_API_SYMBOL(ptrSimPerformPathSearchStep) SIM_API_SYMBOL(simPerformPathSearchStep);
extern SIM_API_SYMBOL(ptrSimLockInterface) SIM_API_SYMBOL(simLockInterface);
extern SIM_API_SYMBOL(ptrSimCopyPasteSelectedObjects) SIM_API_SYMBOL(simCopyPasteSelectedObjects);
extern SIM_API_SYMBOL(ptrSimResetPath) SIM_API_SYMBOL(simResetPath);
extern SIM_API_SYMBOL(ptrSimHandlePath) SIM_API_SYMBOL(simHandlePath);
extern SIM_API_SYMBOL(ptrSimResetJoint) SIM_API_SYMBOL(simResetJoint);
extern SIM_API_SYMBOL(ptrSimHandleJoint) SIM_API_SYMBOL(simHandleJoint);
extern SIM_API_SYMBOL(ptrSimAppendScriptArrayEntry) SIM_API_SYMBOL(simAppendScriptArrayEntry);
extern SIM_API_SYMBOL(ptrSimClearScriptVariable) SIM_API_SYMBOL(simClearScriptVariable);
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
extern SIM_API_SYMBOL(ptrSimAddSceneCustomData) SIM_API_SYMBOL(simAddSceneCustomData);
extern SIM_API_SYMBOL(ptrSimGetSceneCustomDataLength) SIM_API_SYMBOL(simGetSceneCustomDataLength);
extern SIM_API_SYMBOL(ptrSimGetSceneCustomData) SIM_API_SYMBOL(simGetSceneCustomData);
extern SIM_API_SYMBOL(ptrSimAddObjectCustomData) SIM_API_SYMBOL(simAddObjectCustomData);
extern SIM_API_SYMBOL(ptrSimGetObjectCustomDataLength) SIM_API_SYMBOL(simGetObjectCustomDataLength);
extern SIM_API_SYMBOL(ptrSimGetObjectCustomData) SIM_API_SYMBOL(simGetObjectCustomData);
extern SIM_API_SYMBOL(ptrSimCreateUI) SIM_API_SYMBOL(simCreateUI);
extern SIM_API_SYMBOL(ptrSimCreateUIButton) SIM_API_SYMBOL(simCreateUIButton);
extern SIM_API_SYMBOL(ptrSimGetUIHandle) SIM_API_SYMBOL(simGetUIHandle);
extern SIM_API_SYMBOL(ptrSimGetUIProperty) SIM_API_SYMBOL(simGetUIProperty);
extern SIM_API_SYMBOL(ptrSimGetUIEventButton) SIM_API_SYMBOL(simGetUIEventButton);
extern SIM_API_SYMBOL(ptrSimSetUIProperty) SIM_API_SYMBOL(simSetUIProperty);
extern SIM_API_SYMBOL(ptrSimGetUIButtonProperty) SIM_API_SYMBOL(simGetUIButtonProperty);
extern SIM_API_SYMBOL(ptrSimSetUIButtonProperty) SIM_API_SYMBOL(simSetUIButtonProperty);
extern SIM_API_SYMBOL(ptrSimGetUIButtonSize) SIM_API_SYMBOL(simGetUIButtonSize);
extern SIM_API_SYMBOL(ptrSimSetUIButtonLabel) SIM_API_SYMBOL(simSetUIButtonLabel);
extern SIM_API_SYMBOL(ptrSimGetUIButtonLabel) SIM_API_SYMBOL(simGetUIButtonLabel);
extern SIM_API_SYMBOL(ptrSimSetUISlider) SIM_API_SYMBOL(simSetUISlider);
extern SIM_API_SYMBOL(ptrSimGetUISlider) SIM_API_SYMBOL(simGetUISlider);
extern SIM_API_SYMBOL(ptrSimSetUIButtonColor) SIM_API_SYMBOL(simSetUIButtonColor);
extern SIM_API_SYMBOL(ptrSimSetUIButtonTexture) SIM_API_SYMBOL(simSetUIButtonTexture);
extern SIM_API_SYMBOL(ptrSimCreateUIButtonArray) SIM_API_SYMBOL(simCreateUIButtonArray);
extern SIM_API_SYMBOL(ptrSimSetUIButtonArrayColor) SIM_API_SYMBOL(simSetUIButtonArrayColor);
extern SIM_API_SYMBOL(ptrSimDeleteUIButtonArray) SIM_API_SYMBOL(simDeleteUIButtonArray);
extern SIM_API_SYMBOL(ptrSimRemoveUI) SIM_API_SYMBOL(simRemoveUI);
extern SIM_API_SYMBOL(ptrSimSetUIPosition) SIM_API_SYMBOL(simSetUIPosition);
extern SIM_API_SYMBOL(ptrSimGetUIPosition) SIM_API_SYMBOL(simGetUIPosition);
extern SIM_API_SYMBOL(ptrSimLoadUI) SIM_API_SYMBOL(simLoadUI);
extern SIM_API_SYMBOL(ptrSimSaveUI) SIM_API_SYMBOL(simSaveUI);
extern SIM_API_SYMBOL(ptrSimHandleGeneralCallbackScript) SIM_API_SYMBOL(simHandleGeneralCallbackScript);
extern SIM_API_SYMBOL(ptrSimRegisterCustomLuaFunction) SIM_API_SYMBOL(simRegisterCustomLuaFunction);
extern SIM_API_SYMBOL(ptrSimRegisterCustomLuaVariable) SIM_API_SYMBOL(simRegisterCustomLuaVariable);
extern SIM_API_SYMBOL(ptrSimRegisterContactCallback) SIM_API_SYMBOL(simRegisterContactCallback);
extern SIM_API_SYMBOL(ptrSimGetMechanismHandle) SIM_API_SYMBOL(simGetMechanismHandle);
extern SIM_API_SYMBOL(ptrSimHandleMechanism) SIM_API_SYMBOL(simHandleMechanism);
extern SIM_API_SYMBOL(ptrSimHandleCustomizationScripts) SIM_API_SYMBOL(simHandleCustomizationScripts);
extern SIM_API_SYMBOL(ptrSimCallScriptFunction) SIM_API_SYMBOL(simCallScriptFunction);
extern SIM_API_SYMBOL(ptrSimSetVisionSensorFilter) SIM_API_SYMBOL(simSetVisionSensorFilter);
extern SIM_API_SYMBOL(ptrSimGetVisionSensorFilter) SIM_API_SYMBOL(simGetVisionSensorFilter);
extern SIM_API_SYMBOL(ptrSimGetScriptSimulationParameter) SIM_API_SYMBOL(simGetScriptSimulationParameter);
extern SIM_API_SYMBOL(ptrSimSetScriptSimulationParameter) SIM_API_SYMBOL(simSetScriptSimulationParameter);
extern SIM_API_SYMBOL(ptrSimSetJointForce) SIM_API_SYMBOL(simSetJointForce);
extern SIM_API_SYMBOL(ptrSimHandleMill) SIM_API_SYMBOL(simHandleMill);
extern SIM_API_SYMBOL(ptrSimResetMill) SIM_API_SYMBOL(simResetMill);
extern SIM_API_SYMBOL(ptrSimResetMilling) SIM_API_SYMBOL(simResetMilling);
extern SIM_API_SYMBOL(ptrSimApplyMilling) SIM_API_SYMBOL(simApplyMilling);
extern SIM_API_SYMBOL(ptr_simGetParentFollowsDynamic) SIM_API_SYMBOL(_simGetParentFollowsDynamic);
extern SIM_API_SYMBOL(ptrSimGetNameSuffix) SIM_API_SYMBOL(simGetNameSuffix);
extern SIM_API_SYMBOL(ptrSimSetNameSuffix) SIM_API_SYMBOL(simSetNameSuffix);
extern SIM_API_SYMBOL(ptrSimAddStatusbarMessage) SIM_API_SYMBOL(simAddStatusbarMessage);
extern SIM_API_SYMBOL(ptrSimGetScriptRawBuffer) SIM_API_SYMBOL(simGetScriptRawBuffer);
extern SIM_API_SYMBOL(ptrSimSetScriptRawBuffer) SIM_API_SYMBOL(simSetScriptRawBuffer);
extern SIM_API_SYMBOL(ptrSimReleaseScriptRawBuffer) SIM_API_SYMBOL(simReleaseScriptRawBuffer);
extern SIM_API_SYMBOL(ptrSimSetShapeMassAndInertia) SIM_API_SYMBOL(simSetShapeMassAndInertia);
extern SIM_API_SYMBOL(ptrSimGetShapeMassAndInertia) SIM_API_SYMBOL(simGetShapeMassAndInertia);
extern SIM_API_SYMBOL(ptrSimCheckIkGroup) SIM_API_SYMBOL(simCheckIkGroup);
extern SIM_API_SYMBOL(ptrSimCreateIkGroup) SIM_API_SYMBOL(simCreateIkGroup);
extern SIM_API_SYMBOL(ptrSimRemoveIkGroup) SIM_API_SYMBOL(simRemoveIkGroup);
extern SIM_API_SYMBOL(ptrSimCreateIkElement) SIM_API_SYMBOL(simCreateIkElement);
extern SIM_API_SYMBOL(ptrSimExportIk) SIM_API_SYMBOL(simExportIk);
extern SIM_API_SYMBOL(ptrSimComputeJacobian) SIM_API_SYMBOL(simComputeJacobian);
extern SIM_API_SYMBOL(ptrSimGetConfigForTipPose) SIM_API_SYMBOL(simGetConfigForTipPose);
extern SIM_API_SYMBOL(ptrSimGenerateIkPath) SIM_API_SYMBOL(simGenerateIkPath);
extern SIM_API_SYMBOL(ptrSimGetIkGroupHandle) SIM_API_SYMBOL(simGetIkGroupHandle);
extern SIM_API_SYMBOL(ptrSimGetIkGroupMatrix) SIM_API_SYMBOL(simGetIkGroupMatrix);
extern SIM_API_SYMBOL(ptrSimHandleIkGroup) SIM_API_SYMBOL(simHandleIkGroup);
extern SIM_API_SYMBOL(ptrSimSetIkGroupProperties) SIM_API_SYMBOL(simSetIkGroupProperties);
extern SIM_API_SYMBOL(ptrSimSetIkElementProperties) SIM_API_SYMBOL(simSetIkElementProperties);
extern SIM_API_SYMBOL(ptrSimSetThreadIsFree) SIM_API_SYMBOL(simSetThreadIsFree);
extern SIM_API_SYMBOL(ptrSimTubeOpen) SIM_API_SYMBOL(simTubeOpen);
extern SIM_API_SYMBOL(ptrSimTubeClose) SIM_API_SYMBOL(simTubeClose);
extern SIM_API_SYMBOL(ptrSimTubeWrite) SIM_API_SYMBOL(simTubeWrite);
extern SIM_API_SYMBOL(ptrSimTubeRead) SIM_API_SYMBOL(simTubeRead);
extern SIM_API_SYMBOL(ptrSimTubeStatus) SIM_API_SYMBOL(simTubeStatus);
extern SIM_API_SYMBOL(ptrSimSendData) SIM_API_SYMBOL(simSendData);
extern SIM_API_SYMBOL(ptrSimReceiveData) SIM_API_SYMBOL(simReceiveData);
extern SIM_API_SYMBOL(ptrSimGetPositionOnPath) SIM_API_SYMBOL(simGetPositionOnPath);
extern SIM_API_SYMBOL(ptrSimGetDataOnPath) SIM_API_SYMBOL(simGetDataOnPath);
extern SIM_API_SYMBOL(ptrSimGetOrientationOnPath) SIM_API_SYMBOL(simGetOrientationOnPath);
extern SIM_API_SYMBOL(ptrSimGetClosestPositionOnPath) SIM_API_SYMBOL(simGetClosestPositionOnPath);
extern SIM_API_SYMBOL(ptrSimGetPathPosition) SIM_API_SYMBOL(simGetPathPosition);
extern SIM_API_SYMBOL(ptrSimSetPathPosition) SIM_API_SYMBOL(simSetPathPosition);
extern SIM_API_SYMBOL(ptrSimGetPathLength) SIM_API_SYMBOL(simGetPathLength);
extern SIM_API_SYMBOL(ptrSimCreatePath) SIM_API_SYMBOL(simCreatePath);
extern SIM_API_SYMBOL(ptrSimInsertPathCtrlPoints) SIM_API_SYMBOL(simInsertPathCtrlPoints);
extern SIM_API_SYMBOL(ptrSimCutPathCtrlPoints) SIM_API_SYMBOL(simCutPathCtrlPoints);
extern SIM_API_SYMBOL(ptrSimGetThreadId) SIM_API_SYMBOL(simGetThreadId);
extern SIM_API_SYMBOL(ptrSimSwitchThread) SIM_API_SYMBOL(simSwitchThread);
extern SIM_API_SYMBOL(ptrSimLockResources) SIM_API_SYMBOL(simLockResources);
extern SIM_API_SYMBOL(ptrSimUnlockResources) SIM_API_SYMBOL(simUnlockResources);
extern SIM_API_SYMBOL(ptrSimGetUserParameter) SIM_API_SYMBOL(simGetUserParameter);
extern SIM_API_SYMBOL(ptrSimSetUserParameter) SIM_API_SYMBOL(simSetUserParameter);
extern SIM_API_SYMBOL(ptrSimSetPathTargetNominalVelocity) SIM_API_SYMBOL(simSetPathTargetNominalVelocity);
extern SIM_API_SYMBOL(ptrSimGetCollectionHandle) SIM_API_SYMBOL(simGetCollectionHandle);
extern SIM_API_SYMBOL(ptrSimRemoveCollection) SIM_API_SYMBOL(simRemoveCollection);
extern SIM_API_SYMBOL(ptrSimEmptyCollection) SIM_API_SYMBOL(simEmptyCollection);
extern SIM_API_SYMBOL(ptrSimGetCollectionName) SIM_API_SYMBOL(simGetCollectionName);
extern SIM_API_SYMBOL(ptrSimSetCollectionName) SIM_API_SYMBOL(simSetCollectionName);
extern SIM_API_SYMBOL(ptrSimCreateCollection) SIM_API_SYMBOL(simCreateCollection);
extern SIM_API_SYMBOL(ptrSimAddObjectToCollection) SIM_API_SYMBOL(simAddObjectToCollection);
extern SIM_API_SYMBOL(ptrSimGetCollisionHandle) SIM_API_SYMBOL(simGetCollisionHandle);
extern SIM_API_SYMBOL(ptrSimGetDistanceHandle) SIM_API_SYMBOL(simGetDistanceHandle);
extern SIM_API_SYMBOL(ptrSimResetCollision) SIM_API_SYMBOL(simResetCollision);
extern SIM_API_SYMBOL(ptrSimResetDistance) SIM_API_SYMBOL(simResetDistance);
extern SIM_API_SYMBOL(ptrSimHandleCollision) SIM_API_SYMBOL(simHandleCollision);
extern SIM_API_SYMBOL(ptrSimReadCollision) SIM_API_SYMBOL(simReadCollision);
extern SIM_API_SYMBOL(ptrSimHandleDistance) SIM_API_SYMBOL(simHandleDistance);
extern SIM_API_SYMBOL(ptrSimReadDistance) SIM_API_SYMBOL(simReadDistance);
extern SIM_API_SYMBOL(ptrSimAddBanner) SIM_API_SYMBOL(simAddBanner);
extern SIM_API_SYMBOL(ptrSimRemoveBanner) SIM_API_SYMBOL(simRemoveBanner);
extern SIM_API_SYMBOL(ptrSimAddGhost) SIM_API_SYMBOL(simAddGhost);
extern SIM_API_SYMBOL(ptrSimModifyGhost) SIM_API_SYMBOL(simModifyGhost);
extern SIM_API_SYMBOL(ptrSimSetGraphUserData) SIM_API_SYMBOL(simSetGraphUserData);
extern SIM_API_SYMBOL(ptrSimAddPointCloud) SIM_API_SYMBOL(simAddPointCloud);
extern SIM_API_SYMBOL(ptrSimModifyPointCloud) SIM_API_SYMBOL(simModifyPointCloud);
extern SIM_API_SYMBOL(ptrSimCopyMatrix) SIM_API_SYMBOL(simCopyMatrix);
extern SIM_API_SYMBOL(ptrSimGetObjectInt32Param) SIM_API_SYMBOL(simGetObjectIntParameter);
extern SIM_API_SYMBOL(ptrSimSetObjectInt32Param) SIM_API_SYMBOL(simSetObjectIntParameter);
extern SIM_API_SYMBOL(ptrSimGetObjectInt32Param) SIM_API_SYMBOL(simGetObjectInt32Parameter);
extern SIM_API_SYMBOL(ptrSimSetObjectInt32Param) SIM_API_SYMBOL(simSetObjectInt32Parameter);
extern SIM_API_SYMBOL(ptrSimGetObjectFloatParam) SIM_API_SYMBOL(simGetObjectFloatParameter);
extern SIM_API_SYMBOL(ptrSimSetObjectFloatParam) SIM_API_SYMBOL(simSetObjectFloatParameter);
extern SIM_API_SYMBOL(ptrSimGetObjectStringParam) SIM_API_SYMBOL(simGetObjectStringParameter);
extern SIM_API_SYMBOL(ptrSimSetObjectStringParam) SIM_API_SYMBOL(simSetObjectStringParameter);
extern SIM_API_SYMBOL(ptrSimSetBoolParam) SIM_API_SYMBOL(simSetBooleanParameter);
extern SIM_API_SYMBOL(ptrSimGetBoolParam) SIM_API_SYMBOL(simGetBooleanParameter);
extern SIM_API_SYMBOL(ptrSimSetBoolParam) SIM_API_SYMBOL(simSetBoolParameter);
extern SIM_API_SYMBOL(ptrSimGetBoolParam) SIM_API_SYMBOL(simGetBoolParameter);
extern SIM_API_SYMBOL(ptrSimSetInt32Param) SIM_API_SYMBOL(simSetIntegerParameter);
extern SIM_API_SYMBOL(ptrSimGetInt32Param) SIM_API_SYMBOL(simGetIntegerParameter);
extern SIM_API_SYMBOL(ptrSimSetInt32Param) SIM_API_SYMBOL(simSetInt32Parameter);
extern SIM_API_SYMBOL(ptrSimGetInt32Param) SIM_API_SYMBOL(simGetInt32Parameter);
extern SIM_API_SYMBOL(ptrSimGetUInt64Param) SIM_API_SYMBOL(simGetUInt64Parameter);
extern SIM_API_SYMBOL(ptrSimSetFloatParam) SIM_API_SYMBOL(simSetFloatingParameter);
extern SIM_API_SYMBOL(ptrSimGetFloatParam) SIM_API_SYMBOL(simGetFloatingParameter);
extern SIM_API_SYMBOL(ptrSimSetFloatParam) SIM_API_SYMBOL(simSetFloatParameter);
extern SIM_API_SYMBOL(ptrSimGetFloatParam) SIM_API_SYMBOL(simGetFloatParameter);
extern SIM_API_SYMBOL(ptrSimSetStringParam) SIM_API_SYMBOL(simSetStringParameter);
extern SIM_API_SYMBOL(ptrSimGetStringParam) SIM_API_SYMBOL(simGetStringParameter);
extern SIM_API_SYMBOL(ptrSimSetArrayParam) SIM_API_SYMBOL(simSetArrayParameter);
extern SIM_API_SYMBOL(ptrSimGetArrayParam) SIM_API_SYMBOL(simGetArrayParameter);
extern SIM_API_SYMBOL(ptrSimGetEngineFloatParam) SIM_API_SYMBOL(simGetEngineFloatParameter);
extern SIM_API_SYMBOL(ptrSimGetEngineInt32Param) SIM_API_SYMBOL(simGetEngineInt32Parameter);
extern SIM_API_SYMBOL(ptrSimGetEngineBoolParam) SIM_API_SYMBOL(simGetEngineBoolParameter);
extern SIM_API_SYMBOL(ptrSimSetEngineFloatParam) SIM_API_SYMBOL(simSetEngineFloatParameter);
extern SIM_API_SYMBOL(ptrSimSetEngineInt32Param) SIM_API_SYMBOL(simSetEngineInt32Parameter);
extern SIM_API_SYMBOL(ptrSimSetEngineBoolParam) SIM_API_SYMBOL(simSetEngineBoolParameter);
extern SIM_API_SYMBOL(ptrSimIsHandle) SIM_API_SYMBOL(simIsHandleValid);
extern SIM_API_SYMBOL(ptrSimAddModuleMenuEntry) SIM_API_SYMBOL(simAddModuleMenuEntry);
extern SIM_API_SYMBOL(ptrSimSetModuleMenuItemState) SIM_API_SYMBOL(simSetModuleMenuItemState);
extern SIM_API_SYMBOL(ptrSimSetInt32Signal) SIM_API_SYMBOL(simSetIntegerSignal);
extern SIM_API_SYMBOL(ptrSimGetInt32Signal) SIM_API_SYMBOL(simGetIntegerSignal);
extern SIM_API_SYMBOL(ptrSimClearInt32Signal) SIM_API_SYMBOL(simClearIntegerSignal);
extern SIM_API_SYMBOL(ptrSimGetObjectName) SIM_API_SYMBOL(simGetObjectName);
extern SIM_API_SYMBOL(ptrSimSetObjectName) SIM_API_SYMBOL(simSetObjectName);
extern SIM_API_SYMBOL(ptrSimGetScriptName) SIM_API_SYMBOL(simGetScriptName);
extern SIM_API_SYMBOL(ptrSimGetScriptHandle) SIM_API_SYMBOL(simGetScriptHandle);
extern SIM_API_SYMBOL(ptrSimSetScriptVariable) SIM_API_SYMBOL(simSetScriptVariable);
extern SIM_API_SYMBOL(ptrSimGetObjectHandle) SIM_API_SYMBOL(simGetObjectHandle);
extern SIM_API_SYMBOL(ptrSimGetScript) SIM_API_SYMBOL(simGetScript);
extern SIM_API_SYMBOL(ptrSimGetScriptAssociatedWithObject) SIM_API_SYMBOL(simGetScriptAssociatedWithObject);
extern SIM_API_SYMBOL(ptrSimGetCustomizationScriptAssociatedWithObject) SIM_API_SYMBOL(simGetCustomizationScriptAssociatedWithObject);
extern SIM_API_SYMBOL(ptrSimGetObjectAssociatedWithScript) SIM_API_SYMBOL(simGetObjectAssociatedWithScript);
extern SIM_API_SYMBOL(ptrSimGetObjectConfiguration) SIM_API_SYMBOL(simGetObjectConfiguration);
extern SIM_API_SYMBOL(ptrSimSetObjectConfiguration) SIM_API_SYMBOL(simSetObjectConfiguration);
extern SIM_API_SYMBOL(ptrSimGetConfigurationTree) SIM_API_SYMBOL(simGetConfigurationTree);
extern SIM_API_SYMBOL(ptrSimSetConfigurationTree) SIM_API_SYMBOL(simSetConfigurationTree);
extern SIM_API_SYMBOL(ptrSimEnableEventCallback) SIM_API_SYMBOL(simEnableEventCallback);
extern SIM_API_SYMBOL(ptrSimSetObjectSizeValues) SIM_API_SYMBOL(simSetObjectSizeValues);
extern SIM_API_SYMBOL(ptrSimGetObjectSizeValues) SIM_API_SYMBOL(simGetObjectSizeValues);
extern SIM_API_SYMBOL(ptrSimGetSystemTimeInMilliseconds) SIM_API_SYMBOL(simGetSystemTimeInMilliseconds);
extern SIM_API_SYMBOL(ptrSimGetSystemTimeInMs) SIM_API_SYMBOL(simGetSystemTimeInMs);
extern SIM_API_SYMBOL(ptrSimFileDialog) SIM_API_SYMBOL(simFileDialog);
extern SIM_API_SYMBOL(ptrSimMsgBox) SIM_API_SYMBOL(simMsgBox);
extern SIM_API_SYMBOL(ptrSimDisplayDialog) SIM_API_SYMBOL(simDisplayDialog);
extern SIM_API_SYMBOL(ptrSimGetDialogResult) SIM_API_SYMBOL(simGetDialogResult);
extern SIM_API_SYMBOL(ptrSimGetDialogInput) SIM_API_SYMBOL(simGetDialogInput);
extern SIM_API_SYMBOL(ptrSimEndDialog) SIM_API_SYMBOL(simEndDialog);
extern SIM_API_SYMBOL(ptrSimIsObjectInSelection) SIM_API_SYMBOL(simIsObjectInSelection);
extern SIM_API_SYMBOL(ptrSimAddObjectToSelection) SIM_API_SYMBOL(simAddObjectToSelection);
extern SIM_API_SYMBOL(ptrSimRemoveObjectFromSelection) SIM_API_SYMBOL(simRemoveObjectFromSelection);
extern SIM_API_SYMBOL(ptrSimGetObjectSelectionSize) SIM_API_SYMBOL(simGetObjectSelectionSize);
extern SIM_API_SYMBOL(ptrSimGetObjectLastSelection) SIM_API_SYMBOL(simGetObjectLastSelection);
extern SIM_API_SYMBOL(ptrSimGetObjectSelection) SIM_API_SYMBOL(simGetObjectSelection);
extern SIM_API_SYMBOL(ptrSimScaleSelectedObjects) SIM_API_SYMBOL(simScaleSelectedObjects);
extern SIM_API_SYMBOL(ptrSimDeleteSelectedObjects) SIM_API_SYMBOL(simDeleteSelectedObjects);
extern SIM_API_SYMBOL(ptrSimSetNamedStringParam) SIM_API_SYMBOL(simSetStringNamedParam);
extern SIM_API_SYMBOL(ptrSimGetNamedStringParam) SIM_API_SYMBOL(simGetStringNamedParam);
extern SIM_API_SYMBOL(ptrSimGetObjectUniqueIdentifier) SIM_API_SYMBOL(simGetObjectUniqueIdentifier);
extern SIM_API_SYMBOL(ptr_simSetDynamicJointLocalTransformationPart2) SIM_API_SYMBOL(_simSetDynamicJointLocalTransformationPart2);
extern SIM_API_SYMBOL(ptr_simSetDynamicForceSensorLocalTransformationPart2) SIM_API_SYMBOL(_simSetDynamicForceSensorLocalTransformationPart2);
extern SIM_API_SYMBOL(ptr_simSetDynamicJointLocalTransformationPart2IsValid) SIM_API_SYMBOL(_simSetDynamicJointLocalTransformationPart2IsValid);
extern SIM_API_SYMBOL(ptr_simSetDynamicForceSensorLocalTransformationPart2IsValid) SIM_API_SYMBOL(_simSetDynamicForceSensorLocalTransformationPart2IsValid);
extern SIM_API_SYMBOL(ptr_simIsForceSensorBroken) SIM_API_SYMBOL(_simIsForceSensorBroken);
extern SIM_API_SYMBOL(ptrSimBreakForceSensor) SIM_API_SYMBOL(simBreakForceSensor);
extern SIM_API_SYMBOL(ptr_simGetDynamicForceSensorLocalTransformationPart2) SIM_API_SYMBOL(_simGetDynamicForceSensorLocalTransformationPart2);
extern SIM_API_SYMBOL(ptrSimGetJointMatrix) SIM_API_SYMBOL(simGetJointMatrix);
extern SIM_API_SYMBOL(ptrSimSetSphericalJointMatrix) SIM_API_SYMBOL(simSetSphericalJointMatrix);
extern SIM_API_SYMBOL(ptrSimGetObjectHandleEx) SIM_API_SYMBOL(simGetObjectHandleEx);
extern SIM_API_SYMBOL(ptrSimSetScriptAttribute) SIM_API_SYMBOL(simSetScriptAttribute);
extern SIM_API_SYMBOL(ptrSimGetScriptAttribute) SIM_API_SYMBOL(simGetScriptAttribute);
extern SIM_API_SYMBOL(ptrSimSetScriptText) SIM_API_SYMBOL(simSetScriptText);
extern SIM_API_SYMBOL(ptrSimGetScriptText) SIM_API_SYMBOL(simGetScriptText);
extern SIM_API_SYMBOL(ptrSimGetScriptProperty) SIM_API_SYMBOL(simGetScriptProperty);
extern SIM_API_SYMBOL(ptrSimGetJointMaxForce) SIM_API_SYMBOL(simGetJointMaxForce);
extern SIM_API_SYMBOL(ptrSimSetJointMaxForce) SIM_API_SYMBOL(simSetJointMaxForce);
extern SIM_API_SYMBOL(ptr_simSetGeomProxyDynamicsFullRefreshFlag) SIM_API_SYMBOL(_simSetGeomProxyDynamicsFullRefreshFlag);
extern SIM_API_SYMBOL(ptr_simGetGeomProxyDynamicsFullRefreshFlag) SIM_API_SYMBOL(_simGetGeomProxyDynamicsFullRefreshFlag);
extern SIM_API_SYMBOL(ptrSimRemoveObject) SIM_API_SYMBOL(simRemoveObject);
extern SIM_API_SYMBOL(ptr_simSetShapeIsStaticAndNotRespondableButDynamicTag) SIM_API_SYMBOL(_simSetShapeIsStaticAndNotRespondableButDynamicTag);
extern SIM_API_SYMBOL(ptr_simGetShapeIsStaticAndNotRespondableButDynamicTag) SIM_API_SYMBOL(_simGetShapeIsStaticAndNotRespondableButDynamicTag);
extern SIM_API_SYMBOL(ptrSimGetVisionSensorResolution) SIM_API_SYMBOL(simGetVisionSensorResolution);
extern SIM_API_SYMBOL(ptrSimGetVisionSensorImage) SIM_API_SYMBOL(simGetVisionSensorImage);
extern SIM_API_SYMBOL(ptrSimGetVisionSensorCharImage) SIM_API_SYMBOL(simGetVisionSensorCharImage);
extern SIM_API_SYMBOL(ptrSimSetVisionSensorImage) SIM_API_SYMBOL(simSetVisionSensorImage);
extern SIM_API_SYMBOL(ptrSimSetVisionSensorCharImage) SIM_API_SYMBOL(simSetVisionSensorCharImage);
extern SIM_API_SYMBOL(ptrSimGetVisionSensorDepthBuffer) SIM_API_SYMBOL(simGetVisionSensorDepthBuffer);
extern SIM_API_SYMBOL(ptrSimCreatePureShape) SIM_API_SYMBOL(simCreatePureShape);
extern SIM_API_SYMBOL(ptrSimBroadcastMessage) SIM_API_SYMBOL(simBroadcastMessage);
extern SIM_API_SYMBOL(ptrSimSendModuleMessage) SIM_API_SYMBOL(simSendModuleMessage);
extern SIM_API_SYMBOL(ptr_simIsDynamicMotorEnabled) SIM_API_SYMBOL(_simIsDynamicMotorEnabled);
extern SIM_API_SYMBOL(ptr_simIsDynamicMotorPositionCtrlEnabled) SIM_API_SYMBOL(_simIsDynamicMotorPositionCtrlEnabled);
extern SIM_API_SYMBOL(ptr_simIsDynamicMotorTorqueModulationEnabled) SIM_API_SYMBOL(_simIsDynamicMotorTorqueModulationEnabled);
extern SIM_API_SYMBOL(ptr_simGetMotorPid) SIM_API_SYMBOL(_simGetMotorPid);
extern SIM_API_SYMBOL(ptr_simGetContactCallbackCount) SIM_API_SYMBOL(_simGetContactCallbackCount);
extern SIM_API_SYMBOL(ptr_simGetContactCallback) SIM_API_SYMBOL(_simGetContactCallback);
extern SIM_API_SYMBOL(ptrSimBuildMatrixQ) SIM_API_SYMBOL(simBuildMatrixQ);
extern SIM_API_SYMBOL(ptrSimGetQuaternionFromMatrix) SIM_API_SYMBOL(simGetQuaternionFromMatrix);
extern SIM_API_SYMBOL(ptr_simGetLocalInertiaFrame) SIM_API_SYMBOL(_simGetLocalInertiaFrame);
extern SIM_API_SYMBOL(ptr_simGetPrincipalMomentOfInertia) SIM_API_SYMBOL(_simGetPrincipalMomentOfInertia);
extern SIM_API_SYMBOL(ptr_simGetJointCallbackCallOrder) SIM_API_SYMBOL(_simGetJointCallbackCallOrder);
extern SIM_API_SYMBOL(ptrSimSetDoubleSignal) SIM_API_SYMBOL(simSetDoubleSignal);
extern SIM_API_SYMBOL(ptrSimGetDoubleSignal) SIM_API_SYMBOL(simGetDoubleSignal);
extern SIM_API_SYMBOL(ptrSimClearDoubleSignal) SIM_API_SYMBOL(simClearDoubleSignal);
extern SIM_API_SYMBOL(ptrSimAddParticleObject) SIM_API_SYMBOL(simAddParticleObject);
extern SIM_API_SYMBOL(ptrSimRemoveParticleObject) SIM_API_SYMBOL(simRemoveParticleObject);
extern SIM_API_SYMBOL(ptrSimAddParticleObjectItem) SIM_API_SYMBOL(simAddParticleObjectItem);
extern SIM_API_SYMBOL(ptrSimGetShapeVertex) SIM_API_SYMBOL(simGetShapeVertex);
extern SIM_API_SYMBOL(ptrSimGetShapeTriangle) SIM_API_SYMBOL(simGetShapeTriangle);
