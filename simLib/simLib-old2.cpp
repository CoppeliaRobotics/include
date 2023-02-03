ptrSimGetMaterialId simGetMaterialId=nullptr;
ptrSimGetShapeMaterial simGetShapeMaterial=nullptr;
ptrSimHandleVarious simHandleVarious=nullptr;
ptrSimSerialPortOpen simSerialPortOpen=nullptr;
ptrSimSerialPortClose simSerialPortClose=nullptr;
ptrSimSerialPortSend simSerialPortSend=nullptr;
ptrSimSerialPortRead simSerialPortRead=nullptr;
ptrSimJointGetForce simJointGetForce=nullptr;
ptrSimGetPathPlanningHandle simGetPathPlanningHandle=nullptr;
ptrSimGetMotionPlanningHandle simGetMotionPlanningHandle=nullptr;
ptrSimGetMpConfigForTipPose simGetMpConfigForTipPose=nullptr;
ptrSimFindMpPath simFindMpPath=nullptr;
ptrSimSimplifyMpPath simSimplifyMpPath=nullptr;
ptrSimGetMpConfigTransition simGetMpConfigTransition=nullptr;
ptrSimFindIkPath simFindIkPath=nullptr;
ptrSimCreateMotionPlanning simCreateMotionPlanning=nullptr;
ptrSimRemoveMotionPlanning simRemoveMotionPlanning=nullptr;
ptrSimSearchPath simSearchPath=nullptr;
ptrSimInitializePathSearch simInitializePathSearch=nullptr;
ptrSimPerformPathSearchStep simPerformPathSearchStep=nullptr;
ptrSimLockInterface simLockInterface=nullptr;
ptrSimCopyPasteSelectedObjects simCopyPasteSelectedObjects=nullptr;
ptrSimResetPath simResetPath=nullptr;
ptrSimHandlePath simHandlePath=nullptr;
ptrSimResetJoint simResetJoint=nullptr;
ptrSimHandleJoint simHandleJoint=nullptr;
ptrSimAppendScriptArrayEntry simAppendScriptArrayEntry=nullptr;
ptrSimClearScriptVariable simClearScriptVariable=nullptr;
ptrSimAddSceneCustomData simAddSceneCustomData=nullptr;
ptrSimGetSceneCustomDataLength simGetSceneCustomDataLength=nullptr;
ptrSimGetSceneCustomData simGetSceneCustomData=nullptr;
ptrSimAddObjectCustomData simAddObjectCustomData=nullptr;
ptrSimGetObjectCustomDataLength simGetObjectCustomDataLength=nullptr;
ptrSimGetObjectCustomData simGetObjectCustomData=nullptr;
ptrSimCreateUI simCreateUI=nullptr;
ptrSimCreateUIButton simCreateUIButton=nullptr;
ptrSimGetUIHandle simGetUIHandle=nullptr;
ptrSimGetUIProperty simGetUIProperty=nullptr;
ptrSimGetUIEventButton simGetUIEventButton=nullptr;
ptrSimSetUIProperty simSetUIProperty=nullptr;
ptrSimGetUIButtonProperty simGetUIButtonProperty=nullptr;
ptrSimSetUIButtonProperty simSetUIButtonProperty=nullptr;
ptrSimGetUIButtonSize simGetUIButtonSize=nullptr;
ptrSimSetUIButtonLabel simSetUIButtonLabel=nullptr;
ptrSimGetUIButtonLabel simGetUIButtonLabel=nullptr;
ptrSimSetUISlider simSetUISlider=nullptr;
ptrSimGetUISlider simGetUISlider=nullptr;
ptrSimSetUIButtonColor simSetUIButtonColor=nullptr;
ptrSimSetUIButtonTexture simSetUIButtonTexture=nullptr;
ptrSimCreateUIButtonArray simCreateUIButtonArray=nullptr;
ptrSimSetUIButtonArrayColor simSetUIButtonArrayColor=nullptr;
ptrSimDeleteUIButtonArray simDeleteUIButtonArray=nullptr;
ptrSimRemoveUI simRemoveUI=nullptr;
ptrSimSetUIPosition simSetUIPosition=nullptr;
ptrSimGetUIPosition simGetUIPosition=nullptr;
ptrSimLoadUI simLoadUI=nullptr;
ptrSimSaveUI simSaveUI=nullptr;
ptrSimHandleGeneralCallbackScript simHandleGeneralCallbackScript=nullptr;
ptrSimRegisterCustomLuaFunction simRegisterCustomLuaFunction=nullptr;
ptrSimRegisterCustomLuaVariable simRegisterCustomLuaVariable=nullptr;
ptrSimRegisterContactCallback simRegisterContactCallback=nullptr;
ptrSimGetMechanismHandle simGetMechanismHandle=nullptr;
ptrSimHandleMechanism simHandleMechanism=nullptr;
ptrSimHandleCustomizationScripts simHandleCustomizationScripts=nullptr;
ptrSimSetVisionSensorFilter simSetVisionSensorFilter=nullptr;
ptrSimGetVisionSensorFilter simGetVisionSensorFilter=nullptr;
ptrSimGetScriptSimulationParameter simGetScriptSimulationParameter=nullptr;
ptrSimSetScriptSimulationParameter simSetScriptSimulationParameter=nullptr;
ptrSimSetJointForce simSetJointForce=nullptr;
ptrSimHandleMill simHandleMill=nullptr;
ptrSimResetMill simResetMill=nullptr;
ptrSimResetMilling simResetMilling=nullptr;
ptrSimApplyMilling simApplyMilling=nullptr;
ptr_simGetParentFollowsDynamic _simGetParentFollowsDynamic=nullptr;
ptrSimGetNameSuffix simGetNameSuffix=nullptr;
ptrSimSetNameSuffix simSetNameSuffix=nullptr;
ptrSimAddStatusbarMessage simAddStatusbarMessage=nullptr;
ptrSimGetScriptRawBuffer simGetScriptRawBuffer=nullptr;
ptrSimSetScriptRawBuffer simSetScriptRawBuffer=nullptr;
ptrSimReleaseScriptRawBuffer simReleaseScriptRawBuffer=nullptr;
ptrSimSetShapeMassAndInertia simSetShapeMassAndInertia=nullptr;
ptrSimGetShapeMassAndInertia simGetShapeMassAndInertia=nullptr;
ptrSimCheckIkGroup simCheckIkGroup=nullptr;
ptrSimCreateIkGroup simCreateIkGroup=nullptr;
ptrSimRemoveIkGroup simRemoveIkGroup=nullptr;
ptrSimCreateIkElement simCreateIkElement=nullptr;
ptrSimExportIk simExportIk=nullptr;
ptrSimComputeJacobian simComputeJacobian=nullptr;
ptrSimGetConfigForTipPose simGetConfigForTipPose=nullptr;
ptrSimGenerateIkPath simGenerateIkPath=nullptr;
ptrSimGetIkGroupHandle simGetIkGroupHandle=nullptr;
ptrSimGetIkGroupMatrix simGetIkGroupMatrix=nullptr;
ptrSimHandleIkGroup simHandleIkGroup=nullptr;
ptrSimSetIkGroupProperties simSetIkGroupProperties=nullptr;
ptrSimSetIkElementProperties simSetIkElementProperties=nullptr;
ptrSimSetThreadIsFree simSetThreadIsFree=nullptr;
ptrSimTubeOpen simTubeOpen=nullptr;
ptrSimTubeClose simTubeClose=nullptr;
ptrSimTubeWrite simTubeWrite=nullptr;
ptrSimTubeRead simTubeRead=nullptr;
ptrSimTubeStatus simTubeStatus=nullptr;
ptrSimSendData simSendData=nullptr;
ptrSimReceiveData simReceiveData=nullptr;
ptrSimGetPositionOnPath simGetPositionOnPath=nullptr;
ptrSimGetDataOnPath simGetDataOnPath=nullptr;
ptrSimGetOrientationOnPath simGetOrientationOnPath=nullptr;
ptrSimGetClosestPositionOnPath simGetClosestPositionOnPath=nullptr;
ptrSimGetPathPosition simGetPathPosition=nullptr;
ptrSimSetPathPosition simSetPathPosition=nullptr;
ptrSimGetPathLength simGetPathLength=nullptr;
ptrSimCreatePath simCreatePath=nullptr;
ptrSimInsertPathCtrlPoints simInsertPathCtrlPoints=nullptr;
ptrSimCutPathCtrlPoints simCutPathCtrlPoints=nullptr;
ptrSimGetThreadId simGetThreadId=nullptr;
ptrSimSwitchThread simSwitchThread=nullptr;
ptrSimLockResources simLockResources=nullptr;
ptrSimUnlockResources simUnlockResources=nullptr;
ptrSimGetUserParameter simGetUserParameter=nullptr;
ptrSimSetUserParameter simSetUserParameter=nullptr;
ptrSimSetPathTargetNominalVelocity simSetPathTargetNominalVelocity=nullptr;
ptrSimGetCollectionHandle simGetCollectionHandle=nullptr;
ptrSimRemoveCollection simRemoveCollection=nullptr;
ptrSimEmptyCollection simEmptyCollection=nullptr;
ptrSimGetCollectionName simGetCollectionName=nullptr;
ptrSimSetCollectionName simSetCollectionName=nullptr;
ptrSimCreateCollection simCreateCollection=nullptr;
ptrSimAddObjectToCollection simAddObjectToCollection=nullptr;
ptrSimGetCollisionHandle simGetCollisionHandle=nullptr;
ptrSimGetDistanceHandle simGetDistanceHandle=nullptr;
ptrSimResetCollision simResetCollision=nullptr;
ptrSimResetDistance simResetDistance=nullptr;
ptrSimHandleCollision simHandleCollision=nullptr;
ptrSimReadCollision simReadCollision=nullptr;
ptrSimHandleDistance simHandleDistance=nullptr;
ptrSimReadDistance simReadDistance=nullptr;
ptrSimAddBanner simAddBanner=nullptr;
ptrSimRemoveBanner simRemoveBanner=nullptr;
ptrSimAddGhost simAddGhost=nullptr;
ptrSimModifyGhost simModifyGhost=nullptr;
ptrSimSetGraphUserData simSetGraphUserData=nullptr;
ptrSimCopyMatrix simCopyMatrix=nullptr;
ptrSimGetObjectName simGetObjectName=nullptr;
ptrSimSetObjectName simSetObjectName=nullptr;
ptrSimGetScriptName simGetScriptName=nullptr;
ptrSimGetScriptHandle simGetScriptHandle=nullptr;
ptrSimSetScriptVariable simSetScriptVariable=nullptr;
ptrSimGetObjectHandle simGetObjectHandle=nullptr;
ptrSimGetObjectHandleEx simGetObjectHandleEx=nullptr;
ptrSimGetScript simGetScript=nullptr;
ptrSimGetScriptAssociatedWithObject simGetScriptAssociatedWithObject=nullptr;
ptrSimGetCustomizationScriptAssociatedWithObject simGetCustomizationScriptAssociatedWithObject=nullptr;
ptrSimGetObjectAssociatedWithScript simGetObjectAssociatedWithScript=nullptr;
ptrSimGetObjectConfiguration simGetObjectConfiguration=nullptr;
ptrSimSetObjectConfiguration simSetObjectConfiguration=nullptr;
ptrSimGetConfigurationTree simGetConfigurationTree=nullptr;
ptrSimSetConfigurationTree simSetConfigurationTree=nullptr;
ptrSimEnableEventCallback simEnableEventCallback=nullptr;
ptrSimSetObjectSizeValues simSetObjectSizeValues=nullptr;
ptrSimGetObjectSizeValues simGetObjectSizeValues=nullptr;
ptrSimRMLPosition simRMLPosition=nullptr;
ptrSimRMLVelocity simRMLVelocity=nullptr;
ptrSimRMLPos simRMLPos=nullptr;
ptrSimRMLVel simRMLVel=nullptr;
ptrSimRMLStep simRMLStep=nullptr;
ptrSimRMLRemove simRMLRemove=nullptr;
ptrSimGetSystemTimeInMs simGetSystemTimeInMs=nullptr;
ptrSimGetSystemTimeInMilliseconds simGetSystemTimeInMilliseconds=nullptr;
ptrSimFileDialog simFileDialog=nullptr;
ptrSimMsgBox simMsgBox=nullptr;
ptrSimDisplayDialog simDisplayDialog=nullptr;
ptrSimGetDialogResult simGetDialogResult=nullptr;
ptrSimGetDialogInput simGetDialogInput=nullptr;
ptrSimEndDialog simEndDialog=nullptr;
ptrSimIsObjectInSelection simIsObjectInSelection=nullptr;
ptrSimAddObjectToSelection simAddObjectToSelection=nullptr;
ptrSimRemoveObjectFromSelection simRemoveObjectFromSelection=nullptr;
ptrSimGetObjectSelectionSize simGetObjectSelectionSize=nullptr;
ptrSimGetObjectLastSelection simGetObjectLastSelection=nullptr;
ptrSimGetObjectSelection simGetObjectSelection=nullptr;
ptrSimScaleSelectedObjects simScaleSelectedObjects=nullptr;
ptrSimDeleteSelectedObjects simDeleteSelectedObjects=nullptr;
ptrSimGetObjectUniqueIdentifier simGetObjectUniqueIdentifier=nullptr;
ptr_simSetDynamicJointLocalTransformationPart2 _simSetDynamicJointLocalTransformationPart2=nullptr;
ptr_simSetDynamicForceSensorLocalTransformationPart2 _simSetDynamicForceSensorLocalTransformationPart2=nullptr;
ptr_simSetDynamicJointLocalTransformationPart2IsValid _simSetDynamicJointLocalTransformationPart2IsValid=nullptr;
ptr_simSetDynamicForceSensorLocalTransformationPart2IsValid _simSetDynamicForceSensorLocalTransformationPart2IsValid=nullptr;
ptr_simGetDynamicForceSensorLocalTransformationPart2 _simGetDynamicForceSensorLocalTransformationPart2=nullptr;
ptr_simIsForceSensorBroken _simIsForceSensorBroken=nullptr;
ptrSimBreakForceSensor simBreakForceSensor=nullptr;
ptrSimSetScriptAttribute simSetScriptAttribute=nullptr;
ptrSimGetScriptAttribute simGetScriptAttribute=nullptr;
ptrSimSetScriptText simSetScriptText=nullptr;
ptrSimGetScriptText simGetScriptText=nullptr;
ptrSimGetScriptProperty simGetScriptProperty=nullptr;
ptrSimGetJointMaxForce simGetJointMaxForce=nullptr;
ptrSimSetJointMaxForce simSetJointMaxForce=nullptr;
ptr_simSetGeomProxyDynamicsFullRefreshFlag _simSetGeomProxyDynamicsFullRefreshFlag=nullptr;
ptr_simGetGeomProxyDynamicsFullRefreshFlag _simGetGeomProxyDynamicsFullRefreshFlag=nullptr;
ptrSimRemoveObject simRemoveObject=nullptr;
ptr_simSetShapeIsStaticAndNotRespondableButDynamicTag _simSetShapeIsStaticAndNotRespondableButDynamicTag=nullptr;
ptr_simGetShapeIsStaticAndNotRespondableButDynamicTag _simGetShapeIsStaticAndNotRespondableButDynamicTag=nullptr;
ptrSimGetVisionSensorResolution simGetVisionSensorResolution=nullptr;
ptrSimGetVisionSensorImage simGetVisionSensorImage=nullptr;
ptrSimGetVisionSensorCharImage simGetVisionSensorCharImage=nullptr;
ptrSimSetVisionSensorImage simSetVisionSensorImage=nullptr;
ptrSimSetVisionSensorCharImage simSetVisionSensorCharImage=nullptr;
ptrSimGetVisionSensorDepthBuffer simGetVisionSensorDepthBuffer=nullptr;
ptrSimCreatePureShape simCreatePureShape=nullptr;
ptrSimBroadcastMessage simBroadcastMessage=nullptr;
ptrSimSendModuleMessage simSendModuleMessage=nullptr;
ptr_simIsDynamicMotorEnabled _simIsDynamicMotorEnabled=nullptr;
ptr_simIsDynamicMotorPositionCtrlEnabled _simIsDynamicMotorPositionCtrlEnabled=nullptr;
ptr_simIsDynamicMotorTorqueModulationEnabled _simIsDynamicMotorTorqueModulationEnabled=nullptr;
ptr_simGetMotorPid _simGetMotorPid=nullptr;
ptr_simGetContactCallbackCount _simGetContactCallbackCount=nullptr;
ptr_simGetContactCallback _simGetContactCallback=nullptr;
ptrSimBuildMatrixQ simBuildMatrixQ=nullptr;
ptrSimGetQuaternionFromMatrix simGetQuaternionFromMatrix=nullptr;
ptr_simGetPrincipalMomentOfInertia _simGetPrincipalMomentOfInertia=nullptr;
ptr_simGetLocalInertiaFrame _simGetLocalInertiaFrame=nullptr;
ptr_simGetJointCallbackCallOrder _simGetJointCallbackCallOrder=nullptr;
ptrSimSetDoubleSignal simSetDoubleSignal=nullptr;
ptrSimGetDoubleSignal simGetDoubleSignal=nullptr;
ptrSimClearDoubleSignal simClearDoubleSignal=nullptr;
ptrSimAddParticleObject simAddParticleObject=nullptr;
ptrSimRemoveParticleObject simRemoveParticleObject=nullptr;
ptrSimAddParticleObjectItem simAddParticleObjectItem=nullptr;
ptrSimGetShapeVertex simGetShapeVertex=nullptr;
ptrSimGetShapeTriangle simGetShapeTriangle=nullptr;
ptrSimGetObjectInt32Param simGetObjectIntParameter=nullptr;
ptrSimSetObjectInt32Param simSetObjectIntParameter=nullptr;
ptrSimGetObjectInt32Param simGetObjectInt32Parameter=nullptr;
ptrSimSetObjectInt32Param simSetObjectInt32Parameter=nullptr;
ptrSimGetObjectFloatParam simGetObjectFloatParameter=nullptr;
ptrSimSetObjectFloatParam simSetObjectFloatParameter=nullptr;
ptrSimGetObjectStringParam simGetObjectStringParameter=nullptr;
ptrSimSetObjectStringParam simSetObjectStringParameter=nullptr;
ptrSimSetBoolParam simSetBooleanParameter=nullptr;
ptrSimGetBoolParam simGetBooleanParameter=nullptr;
ptrSimSetBoolParam simSetBoolParameter=nullptr;
ptrSimGetBoolParam simGetBoolParameter=nullptr;
ptrSimSetInt32Param simSetIntegerParameter=nullptr;
ptrSimGetInt32Param simGetIntegerParameter=nullptr;
ptrSimSetInt32Param simSetInt32Parameter=nullptr;
ptrSimGetInt32Param simGetInt32Parameter=nullptr;
ptrSimGetUInt64Param simGetUInt64Parameter=nullptr;
ptrSimSetFloatParam simSetFloatingParameter=nullptr;
ptrSimGetFloatParam simGetFloatingParameter=nullptr;
ptrSimSetFloatParam simSetFloatParameter=nullptr;
ptrSimGetFloatParam simGetFloatParameter=nullptr;
ptrSimSetStringParam simSetStringParameter=nullptr;
ptrSimGetStringParam simGetStringParameter=nullptr;
ptrSimSetArrayParam simSetArrayParameter=nullptr;
ptrSimGetArrayParam simGetArrayParameter=nullptr;
ptrSimGetEngineFloatParam simGetEngineFloatParameter=nullptr;
ptrSimGetEngineInt32Param simGetEngineInt32Parameter=nullptr;
ptrSimGetEngineBoolParam simGetEngineBoolParameter=nullptr;
ptrSimSetEngineFloatParam simSetEngineFloatParameter=nullptr;
ptrSimSetEngineInt32Param simSetEngineInt32Parameter=nullptr;
ptrSimSetEngineBoolParam simSetEngineBoolParameter=nullptr;
ptrSimIsHandle simIsHandleValid=nullptr;
ptrSimSetInt32Signal simSetIntegerSignal=nullptr;
ptrSimGetInt32Signal simGetIntegerSignal=nullptr;
ptrSimClearInt32Signal simClearIntegerSignal=nullptr;
ptrSimSetNamedStringParam simSetStringNamedParam=nullptr;
ptrSimGetNamedStringParam simGetStringNamedParam=nullptr;


int getSimProcAddressesOld2(LIBRARY lib)
{
    simGetMaterialId=(ptrSimGetMaterialId)(_getProcAddress(lib,"simGetMaterialId",false));
    simGetShapeMaterial=(ptrSimGetShapeMaterial)(_getProcAddress(lib,"simGetShapeMaterial",false));
    simHandleVarious=(ptrSimHandleVarious)(_getProcAddress(lib,"simHandleVarious",false));
    simSerialPortOpen=(ptrSimSerialPortOpen)(_getProcAddress(lib,"simSerialPortOpen",false));
    simSerialPortClose=(ptrSimSerialPortClose)(_getProcAddress(lib,"simSerialPortClose",false));
    simSerialPortSend=(ptrSimSerialPortSend)(_getProcAddress(lib,"simSerialPortSend",false));
    simSerialPortRead=(ptrSimSerialPortRead)(_getProcAddress(lib,"simSerialPortRead",false));
    simGetPathPlanningHandle=(ptrSimGetPathPlanningHandle)(_getProcAddress(lib,"simGetPathPlanningHandle",false));
    simGetMotionPlanningHandle=(ptrSimGetMotionPlanningHandle)(_getProcAddress(lib,"simGetMotionPlanningHandle",false));
    simRemoveMotionPlanning=(ptrSimRemoveMotionPlanning)(_getProcAddress(lib,"simRemoveMotionPlanning",false));
    simPerformPathSearchStep=(ptrSimPerformPathSearchStep)(_getProcAddress(lib,"simPerformPathSearchStep",false));
    simLockInterface=(ptrSimLockInterface)(_getProcAddress(lib,"simLockInterface",false));
    simCopyPasteSelectedObjects=(ptrSimCopyPasteSelectedObjects)(_getProcAddress(lib,"simCopyPasteSelectedObjects",false));
    simResetPath=(ptrSimResetPath)(_getProcAddress(lib,"simResetPath",false));
    simResetJoint=(ptrSimResetJoint)(_getProcAddress(lib,"simResetJoint",false));
    simAppendScriptArrayEntry=(ptrSimAppendScriptArrayEntry)(_getProcAddress(lib,"simAppendScriptArrayEntry",false));
    simClearScriptVariable=(ptrSimClearScriptVariable)(_getProcAddress(lib,"simClearScriptVariable",false));
    simAddSceneCustomData=(ptrSimAddSceneCustomData)(_getProcAddress(lib,"simAddSceneCustomData",false));
    simGetSceneCustomDataLength=(ptrSimGetSceneCustomDataLength)(_getProcAddress(lib,"simGetSceneCustomDataLength",false));
    simGetSceneCustomData=(ptrSimGetSceneCustomData)(_getProcAddress(lib,"simGetSceneCustomData",false));
    simAddObjectCustomData=(ptrSimAddObjectCustomData)(_getProcAddress(lib,"simAddObjectCustomData",false));
    simGetObjectCustomDataLength=(ptrSimGetObjectCustomDataLength)(_getProcAddress(lib,"simGetObjectCustomDataLength",false));
    simGetObjectCustomData=(ptrSimGetObjectCustomData)(_getProcAddress(lib,"simGetObjectCustomData",false));
    simCreateUI=(ptrSimCreateUI)(_getProcAddress(lib,"simCreateUI",false));
    simCreateUIButton=(ptrSimCreateUIButton)(_getProcAddress(lib,"simCreateUIButton",false));
    simGetUIHandle=(ptrSimGetUIHandle)(_getProcAddress(lib,"simGetUIHandle",false));
    simGetUIProperty=(ptrSimGetUIProperty)(_getProcAddress(lib,"simGetUIProperty",false));
    simGetUIEventButton=(ptrSimGetUIEventButton)(_getProcAddress(lib,"simGetUIEventButton",false));
    simSetUIProperty=(ptrSimSetUIProperty)(_getProcAddress(lib,"simSetUIProperty",false));
    simGetUIButtonProperty=(ptrSimGetUIButtonProperty)(_getProcAddress(lib,"simGetUIButtonProperty",false));
    simSetUIButtonProperty=(ptrSimSetUIButtonProperty)(_getProcAddress(lib,"simSetUIButtonProperty",false));
    simGetUIButtonSize=(ptrSimGetUIButtonSize)(_getProcAddress(lib,"simGetUIButtonSize",false));
    simSetUIButtonLabel=(ptrSimSetUIButtonLabel)(_getProcAddress(lib,"simSetUIButtonLabel",false));
    simGetUIButtonLabel=(ptrSimGetUIButtonLabel)(_getProcAddress(lib,"simGetUIButtonLabel",false));
    simSetUISlider=(ptrSimSetUISlider)(_getProcAddress(lib,"simSetUISlider",false));
    simGetUISlider=(ptrSimGetUISlider)(_getProcAddress(lib,"simGetUISlider",false));
    simSetUIButtonTexture=(ptrSimSetUIButtonTexture)(_getProcAddress(lib,"simSetUIButtonTexture",false));
    simCreateUIButtonArray=(ptrSimCreateUIButtonArray)(_getProcAddress(lib,"simCreateUIButtonArray",false));
    simDeleteUIButtonArray=(ptrSimDeleteUIButtonArray)(_getProcAddress(lib,"simDeleteUIButtonArray",false));
    simRemoveUI=(ptrSimRemoveUI)(_getProcAddress(lib,"simRemoveUI",false));
    simSetUIPosition=(ptrSimSetUIPosition)(_getProcAddress(lib,"simSetUIPosition",false));
    simGetUIPosition=(ptrSimGetUIPosition)(_getProcAddress(lib,"simGetUIPosition",false));
    simLoadUI=(ptrSimLoadUI)(_getProcAddress(lib,"simLoadUI",false));
    simSaveUI=(ptrSimSaveUI)(_getProcAddress(lib,"simSaveUI",false));
    simHandleGeneralCallbackScript=(ptrSimHandleGeneralCallbackScript)(_getProcAddress(lib,"simHandleGeneralCallbackScript",false));
    simRegisterCustomLuaFunction=(ptrSimRegisterCustomLuaFunction)(_getProcAddress(lib,"simRegisterCustomLuaFunction",false));
    simRegisterCustomLuaVariable=(ptrSimRegisterCustomLuaVariable)(_getProcAddress(lib,"simRegisterCustomLuaVariable",false));
    simGetMechanismHandle=(ptrSimGetMechanismHandle)(_getProcAddress(lib,"simGetMechanismHandle",false));
    simHandleMechanism=(ptrSimHandleMechanism)(_getProcAddress(lib,"simHandleMechanism",false));
    simHandleCustomizationScripts=(ptrSimHandleCustomizationScripts)(_getProcAddress(lib,"simHandleCustomizationScripts",false));
    simGetScriptSimulationParameter=(ptrSimGetScriptSimulationParameter)(_getProcAddress(lib,"simGetScriptSimulationParameter",false));
    simSetScriptSimulationParameter=(ptrSimSetScriptSimulationParameter)(_getProcAddress(lib,"simSetScriptSimulationParameter",false));
    simResetMill=(ptrSimResetMill)(_getProcAddress(lib,"simResetMill",false));
    simResetMilling=(ptrSimResetMilling)(_getProcAddress(lib,"simResetMilling",false));
    simApplyMilling=(ptrSimApplyMilling)(_getProcAddress(lib,"simApplyMilling",false));
    _simGetParentFollowsDynamic=(ptr_simGetParentFollowsDynamic)(_getProcAddress(lib,"_simGetParentFollowsDynamic",false));
    simGetNameSuffix=(ptrSimGetNameSuffix)(_getProcAddress(lib,"simGetNameSuffix",false));
    simSetNameSuffix=(ptrSimSetNameSuffix)(_getProcAddress(lib,"simSetNameSuffix",false));
    simAddStatusbarMessage=(ptrSimAddStatusbarMessage)(_getProcAddress(lib,"simAddStatusbarMessage",false));
    simGetScriptRawBuffer=(ptrSimGetScriptRawBuffer)(_getProcAddress(lib,"simGetScriptRawBuffer",false));
    simSetScriptRawBuffer=(ptrSimSetScriptRawBuffer)(_getProcAddress(lib,"simSetScriptRawBuffer",false));
    simReleaseScriptRawBuffer=(ptrSimReleaseScriptRawBuffer)(_getProcAddress(lib,"simReleaseScriptRawBuffer",false));
    simRemoveIkGroup=(ptrSimRemoveIkGroup)(_getProcAddress(lib,"simRemoveIkGroup",false));
    simExportIk=(ptrSimExportIk)(_getProcAddress(lib,"simExportIk",false));
    simComputeJacobian=(ptrSimComputeJacobian)(_getProcAddress(lib,"simComputeJacobian",false));
    simGetIkGroupHandle=(ptrSimGetIkGroupHandle)(_getProcAddress(lib,"simGetIkGroupHandle",false));
    simHandleIkGroup=(ptrSimHandleIkGroup)(_getProcAddress(lib,"simHandleIkGroup",false));
    simSetThreadIsFree=(ptrSimSetThreadIsFree)(_getProcAddress(lib,"simSetThreadIsFree",false));
    simTubeOpen=(ptrSimTubeOpen)(_getProcAddress(lib,"simTubeOpen",false));
    simTubeClose=(ptrSimTubeClose)(_getProcAddress(lib,"simTubeClose",false));
    simTubeWrite=(ptrSimTubeWrite)(_getProcAddress(lib,"simTubeWrite",false));
    simTubeRead=(ptrSimTubeRead)(_getProcAddress(lib,"simTubeRead",false));
    simTubeStatus=(ptrSimTubeStatus)(_getProcAddress(lib,"simTubeStatus",false));
    simReceiveData=(ptrSimReceiveData)(_getProcAddress(lib,"simReceiveData",false));
    simInsertPathCtrlPoints=(ptrSimInsertPathCtrlPoints)(_getProcAddress(lib,"simInsertPathCtrlPoints",false));
    simCutPathCtrlPoints=(ptrSimCutPathCtrlPoints)(_getProcAddress(lib,"simCutPathCtrlPoints",false));
    simGetThreadId=(ptrSimGetThreadId)(_getProcAddress(lib,"simGetThreadId",false));
    simSwitchThread=(ptrSimSwitchThread)(_getProcAddress(lib,"simSwitchThread",false));
    simGetObjectName=(ptrSimGetObjectName)(_getProcAddress(lib,"simGetObjectName",false));
    simSetObjectName=(ptrSimSetObjectName)(_getProcAddress(lib,"simSetObjectName",false));
    simGetScriptName=(ptrSimGetScriptName)(_getProcAddress(lib,"simGetScriptName",false));
    simGetScriptHandle=(ptrSimGetScriptHandle)(_getProcAddress(lib,"simGetScriptHandle",false));
    simSetScriptVariable=(ptrSimSetScriptVariable)(_getProcAddress(lib,"simSetScriptVariable",false));
    simGetObjectHandle=(ptrSimGetObjectHandle)(_getProcAddress(lib,"simGetObjectHandle",false));
    simGetObjectHandleEx=(ptrSimGetObjectHandleEx)(_getProcAddress(lib,"simGetObjectHandleEx",false));
    simGetScript=(ptrSimGetScript)(_getProcAddress(lib,"simGetScript",false));
    simGetScriptAssociatedWithObject=(ptrSimGetScriptAssociatedWithObject)(_getProcAddress(lib,"simGetScriptAssociatedWithObject",false));
    simGetCustomizationScriptAssociatedWithObject=(ptrSimGetCustomizationScriptAssociatedWithObject)(_getProcAddress(lib,"simGetCustomizationScriptAssociatedWithObject",false));
    simGetObjectAssociatedWithScript=(ptrSimGetObjectAssociatedWithScript)(_getProcAddress(lib,"simGetObjectAssociatedWithScript",false));
    simGetObjectConfiguration=(ptrSimGetObjectConfiguration)(_getProcAddress(lib,"simGetObjectConfiguration",false));
    simSetObjectConfiguration=(ptrSimSetObjectConfiguration)(_getProcAddress(lib,"simSetObjectConfiguration",false));
    simGetConfigurationTree=(ptrSimGetConfigurationTree)(_getProcAddress(lib,"simGetConfigurationTree",false));
    simSetConfigurationTree=(ptrSimSetConfigurationTree)(_getProcAddress(lib,"simSetConfigurationTree",false));
    simEnableEventCallback=(ptrSimEnableEventCallback)(_getProcAddress(lib,"simEnableEventCallback",false));
    simRMLPosition=(ptrSimRMLPosition)(_getProcAddress(lib,"simRMLPosition",false));
    simRMLVelocity=(ptrSimRMLVelocity)(_getProcAddress(lib,"simRMLVelocity",false));
    simRMLPos=(ptrSimRMLPos)(_getProcAddress(lib,"simRMLPos",false));
    simRMLVel=(ptrSimRMLVel)(_getProcAddress(lib,"simRMLVel",false));
    simRMLStep=(ptrSimRMLStep)(_getProcAddress(lib,"simRMLStep",false));
    simRMLRemove=(ptrSimRMLRemove)(_getProcAddress(lib,"simRMLRemove",false));
    simGetSystemTimeInMilliseconds=(ptrSimGetSystemTimeInMilliseconds)(_getProcAddress(lib,"simGetSystemTimeInMilliseconds",false));
    simGetSystemTimeInMs=(ptrSimGetSystemTimeInMs)(_getProcAddress(lib,"simGetSystemTimeInMs",false));
    simFileDialog=(ptrSimFileDialog)(_getProcAddress(lib,"simFileDialog",false));
    simMsgBox=(ptrSimMsgBox)(_getProcAddress(lib,"simMsgBox",false));
    simGetDialogResult=(ptrSimGetDialogResult)(_getProcAddress(lib,"simGetDialogResult",false));
    simGetDialogInput=(ptrSimGetDialogInput)(_getProcAddress(lib,"simGetDialogInput",false));
    simEndDialog=(ptrSimEndDialog)(_getProcAddress(lib,"simEndDialog",false));
    simIsObjectInSelection=(ptrSimIsObjectInSelection)(_getProcAddress(lib,"simIsObjectInSelection",false));
    simAddObjectToSelection=(ptrSimAddObjectToSelection)(_getProcAddress(lib,"simAddObjectToSelection",false));
    simRemoveObjectFromSelection=(ptrSimRemoveObjectFromSelection)(_getProcAddress(lib,"simRemoveObjectFromSelection",false));
    simGetObjectSelectionSize=(ptrSimGetObjectSelectionSize)(_getProcAddress(lib,"simGetObjectSelectionSize",false));
    simLockResources=(ptrSimLockResources)(_getProcAddress(lib,"simLockResources",false));
    simUnlockResources=(ptrSimUnlockResources)(_getProcAddress(lib,"simUnlockResources",false));
    simGetUserParameter=(ptrSimGetUserParameter)(_getProcAddress(lib,"simGetUserParameter",false));
    simSetUserParameter=(ptrSimSetUserParameter)(_getProcAddress(lib,"simSetUserParameter",false));
    simGetCollectionHandle=(ptrSimGetCollectionHandle)(_getProcAddress(lib,"simGetCollectionHandle",false));
    simRemoveCollection=(ptrSimRemoveCollection)(_getProcAddress(lib,"simRemoveCollection",false));
    simEmptyCollection=(ptrSimEmptyCollection)(_getProcAddress(lib,"simEmptyCollection",false));
    simGetCollectionName=(ptrSimGetCollectionName)(_getProcAddress(lib,"simGetCollectionName",false));
    simSetCollectionName=(ptrSimSetCollectionName)(_getProcAddress(lib,"simSetCollectionName",false));
    simCreateCollection=(ptrSimCreateCollection)(_getProcAddress(lib,"simCreateCollection",false));
    simAddObjectToCollection=(ptrSimAddObjectToCollection)(_getProcAddress(lib,"simAddObjectToCollection",false));
    simGetCollisionHandle=(ptrSimGetCollisionHandle)(_getProcAddress(lib,"simGetCollisionHandle",false));
    simGetDistanceHandle=(ptrSimGetDistanceHandle)(_getProcAddress(lib,"simGetDistanceHandle",false));
    simResetCollision=(ptrSimResetCollision)(_getProcAddress(lib,"simResetCollision",false));
    simResetDistance=(ptrSimResetDistance)(_getProcAddress(lib,"simResetDistance",false));
    simHandleCollision=(ptrSimHandleCollision)(_getProcAddress(lib,"simHandleCollision",false));
    simReadCollision=(ptrSimReadCollision)(_getProcAddress(lib,"simReadCollision",false));
    simRemoveBanner=(ptrSimRemoveBanner)(_getProcAddress(lib,"simRemoveBanner",false));
    simGetObjectLastSelection=(ptrSimGetObjectLastSelection)(_getProcAddress(lib,"simGetObjectLastSelection",false));
    simGetObjectSelection=(ptrSimGetObjectSelection)(_getProcAddress(lib,"simGetObjectSelection",false));
    simDeleteSelectedObjects=(ptrSimDeleteSelectedObjects)(_getProcAddress(lib,"simDeleteSelectedObjects",false));
    simGetObjectUniqueIdentifier=(ptrSimGetObjectUniqueIdentifier)(_getProcAddress(lib,"simGetObjectUniqueIdentifier",false));
    _simSetDynamicJointLocalTransformationPart2IsValid=(ptr_simSetDynamicJointLocalTransformationPart2IsValid)(_getProcAddress(lib,"_simSetDynamicJointLocalTransformationPart2IsValid",false));
    _simSetDynamicForceSensorLocalTransformationPart2IsValid=(ptr_simSetDynamicForceSensorLocalTransformationPart2IsValid)(_getProcAddress(lib,"_simSetDynamicForceSensorLocalTransformationPart2IsValid",false));
    _simIsForceSensorBroken=(ptr_simIsForceSensorBroken)(_getProcAddress(lib,"_simIsForceSensorBroken",false));
    simBreakForceSensor=(ptrSimBreakForceSensor)(_getProcAddress(lib,"simBreakForceSensor",false));
    simSetScriptText=(ptrSimSetScriptText)(_getProcAddress(lib,"simSetScriptText",false));
    simGetScriptText=(ptrSimGetScriptText)(_getProcAddress(lib,"simGetScriptText",false));
    simGetScriptProperty=(ptrSimGetScriptProperty)(_getProcAddress(lib,"simGetScriptProperty",false));
    _simSetGeomProxyDynamicsFullRefreshFlag=(ptr_simSetGeomProxyDynamicsFullRefreshFlag)(_getProcAddress(lib,"_simSetGeomProxyDynamicsFullRefreshFlag",false));
    _simGetGeomProxyDynamicsFullRefreshFlag=(ptr_simGetGeomProxyDynamicsFullRefreshFlag)(_getProcAddress(lib,"_simGetGeomProxyDynamicsFullRefreshFlag",false));
    simRemoveObject=(ptrSimRemoveObject)(_getProcAddress(lib,"simRemoveObject",false));
    _simSetShapeIsStaticAndNotRespondableButDynamicTag=(ptr_simSetShapeIsStaticAndNotRespondableButDynamicTag)(_getProcAddress(lib,"_simSetShapeIsStaticAndNotRespondableButDynamicTag",false));
    _simGetShapeIsStaticAndNotRespondableButDynamicTag=(ptr_simGetShapeIsStaticAndNotRespondableButDynamicTag)(_getProcAddress(lib,"_simGetShapeIsStaticAndNotRespondableButDynamicTag",false));
    simGetVisionSensorResolution=(ptrSimGetVisionSensorResolution)(_getProcAddress(lib,"simGetVisionSensorResolution",false));
    simGetVisionSensorCharImage=(ptrSimGetVisionSensorCharImage)(_getProcAddress(lib,"simGetVisionSensorCharImage",false));
    simSetVisionSensorCharImage=(ptrSimSetVisionSensorCharImage)(_getProcAddress(lib,"simSetVisionSensorCharImage",false));
    simBroadcastMessage=(ptrSimBroadcastMessage)(_getProcAddress(lib,"simBroadcastMessage",false));
    simSendModuleMessage=(ptrSimSendModuleMessage)(_getProcAddress(lib,"simSendModuleMessage",false));
    _simIsDynamicMotorEnabled=(ptr_simIsDynamicMotorEnabled)(_getProcAddress(lib,"_simIsDynamicMotorEnabled",false));
    _simIsDynamicMotorPositionCtrlEnabled=(ptr_simIsDynamicMotorPositionCtrlEnabled)(_getProcAddress(lib,"_simIsDynamicMotorPositionCtrlEnabled",false));
    _simIsDynamicMotorTorqueModulationEnabled=(ptr_simIsDynamicMotorTorqueModulationEnabled)(_getProcAddress(lib,"_simIsDynamicMotorTorqueModulationEnabled",false));
    _simGetContactCallbackCount=(ptr_simGetContactCallbackCount)(_getProcAddress(lib,"_simGetContactCallbackCount",false));
    _simGetContactCallback=(ptr_simGetContactCallback)(_getProcAddress(lib,"_simGetContactCallback",false));
    _simGetJointCallbackCallOrder=(ptr_simGetJointCallbackCallOrder)(_getProcAddress(lib,"_simGetJointCallbackCallOrder",false));
    simSetDoubleSignal=(ptrSimSetDoubleSignal)(_getProcAddress(lib,"simSetDoubleSignal",false));
    simGetDoubleSignal=(ptrSimGetDoubleSignal)(_getProcAddress(lib,"simGetDoubleSignal",false));
    simClearDoubleSignal=(ptrSimClearDoubleSignal)(_getProcAddress(lib,"simClearDoubleSignal",false));
    simRemoveParticleObject=(ptrSimRemoveParticleObject)(_getProcAddress(lib,"simRemoveParticleObject",false));
    simAddParticleObject=(ptrSimAddParticleObject)(_getProcAddress(lib,"simAddParticleObject",false));
    simAddParticleObjectItem=(ptrSimAddParticleObjectItem)(_getProcAddress(lib,"simAddParticleObjectItem",false));
    simGetVisionSensorImage=(ptrSimGetVisionSensorImage)(_getProcAddress(lib,"simGetVisionSensorImage",false));
    simSetVisionSensorImage=(ptrSimSetVisionSensorImage)(_getProcAddress(lib,"simSetVisionSensorImage",false));
    simGetVisionSensorDepthBuffer=(ptrSimGetVisionSensorDepthBuffer)(_getProcAddress(lib,"simGetVisionSensorDepthBuffer",false));
    simJointGetForce=(ptrSimJointGetForce)(_getProcAddress(lib,"simJointGetForce",true));
    simGetMpConfigForTipPose=(ptrSimGetMpConfigForTipPose)(_getProcAddress(lib,"simGetMpConfigForTipPose",true));
    simFindMpPath=(ptrSimFindMpPath)(_getProcAddress(lib,"simFindMpPath",true));
    simSimplifyMpPath=(ptrSimSimplifyMpPath)(_getProcAddress(lib,"simSimplifyMpPath",true));
    simFindIkPath=(ptrSimFindIkPath)(_getProcAddress(lib,"simFindIkPath",true));
    simGetMpConfigTransition=(ptrSimGetMpConfigTransition)(_getProcAddress(lib,"simGetMpConfigTransition",true));
    simCreateMotionPlanning=(ptrSimCreateMotionPlanning)(_getProcAddress(lib,"simCreateMotionPlanning",true));
    simSearchPath=(ptrSimSearchPath)(_getProcAddress(lib,"simSearchPath",true));
    simInitializePathSearch=(ptrSimInitializePathSearch)(_getProcAddress(lib,"simInitializePathSearch",true));
    simHandlePath=(ptrSimHandlePath)(_getProcAddress(lib,"simHandlePath",true));
    simHandleJoint=(ptrSimHandleJoint)(_getProcAddress(lib,"simHandleJoint",true));
    simSetUIButtonColor=(ptrSimSetUIButtonColor)(_getProcAddress(lib,"simSetUIButtonColor",false));
    simSetUIButtonArrayColor=(ptrSimSetUIButtonArrayColor)(_getProcAddress(lib,"simSetUIButtonArrayColor",false));
    simRegisterContactCallback=(ptrSimRegisterContactCallback)(_getProcAddress(lib,"simRegisterContactCallback",true));
    simSetJointForce=(ptrSimSetJointForce)(_getProcAddress(lib,"simSetJointForce",true));
    simHandleMill=(ptrSimHandleMill)(_getProcAddress(lib,"simHandleMill",true));
    simSetShapeMassAndInertia=(ptrSimSetShapeMassAndInertia)(_getProcAddress(lib,"simSetShapeMassAndInertia",true));
    simGetShapeMassAndInertia=(ptrSimGetShapeMassAndInertia)(_getProcAddress(lib,"simGetShapeMassAndInertia",true));
    simCheckIkGroup=(ptrSimCheckIkGroup)(_getProcAddress(lib,"simCheckIkGroup",true));
    simCreateIkGroup=(ptrSimCreateIkGroup)(_getProcAddress(lib,"simCreateIkGroup",true));
    simCreateIkElement=(ptrSimCreateIkElement)(_getProcAddress(lib,"simCreateIkElement",true));
    simGetConfigForTipPose=(ptrSimGetConfigForTipPose)(_getProcAddress(lib,"simGetConfigForTipPose",true));
    simGenerateIkPath=(ptrSimGenerateIkPath)(_getProcAddress(lib,"simGenerateIkPath",true));
    simGetIkGroupMatrix=(ptrSimGetIkGroupMatrix)(_getProcAddress(lib,"simGetIkGroupMatrix",true));
    simSetIkGroupProperties=(ptrSimSetIkGroupProperties)(_getProcAddress(lib,"simSetIkGroupProperties",true));
    simGetPositionOnPath=(ptrSimGetPositionOnPath)(_getProcAddress(lib,"simGetPositionOnPath",true));
    simGetDataOnPath=(ptrSimGetDataOnPath)(_getProcAddress(lib,"simGetDataOnPath",true));
    simGetOrientationOnPath=(ptrSimGetOrientationOnPath)(_getProcAddress(lib,"simGetOrientationOnPath",true));
    simGetClosestPositionOnPath=(ptrSimGetClosestPositionOnPath)(_getProcAddress(lib,"simGetClosestPositionOnPath",true));
    simGetPathPosition=(ptrSimGetPathPosition)(_getProcAddress(lib,"simGetPathPosition",true));
    simSetPathPosition=(ptrSimSetPathPosition)(_getProcAddress(lib,"simSetPathPosition",true));
    simGetPathLength=(ptrSimGetPathLength)(_getProcAddress(lib,"simGetPathLength",true));
    simCreatePath=(ptrSimCreatePath)(_getProcAddress(lib,"simCreatePath",true));
    simSetPathTargetNominalVelocity=(ptrSimSetPathTargetNominalVelocity)(_getProcAddress(lib,"simSetPathTargetNominalVelocity",true));
    simHandleDistance=(ptrSimHandleDistance)(_getProcAddress(lib,"simHandleDistance",true));
    simReadDistance=(ptrSimReadDistance)(_getProcAddress(lib,"simReadDistance",true));
    simAddBanner=(ptrSimAddBanner)(_getProcAddress(lib,"simAddBanner",true));
    simAddGhost=(ptrSimAddGhost)(_getProcAddress(lib,"simAddGhost",true));
    simModifyGhost=(ptrSimModifyGhost)(_getProcAddress(lib,"simModifyGhost",true));
    simSetGraphUserData=(ptrSimSetGraphUserData)(_getProcAddress(lib,"simSetGraphUserData",true));
    simCopyMatrix=(ptrSimCopyMatrix)(_getProcAddress(lib,"simCopyMatrix",true));
    simSetVisionSensorFilter=(ptrSimSetVisionSensorFilter)(_getProcAddress(lib,"simSetVisionSensorFilter",true));
    simGetVisionSensorFilter=(ptrSimGetVisionSensorFilter)(_getProcAddress(lib,"simGetVisionSensorFilter",true));
    simSetIkElementProperties=(ptrSimSetIkElementProperties)(_getProcAddress(lib,"simSetIkElementProperties",true));
    simSendData=(ptrSimSendData)(_getProcAddress(lib,"simSendData",true));
    simSetObjectSizeValues=(ptrSimSetObjectSizeValues)(_getProcAddress(lib,"simSetObjectSizeValues",true));
    simGetObjectSizeValues=(ptrSimGetObjectSizeValues)(_getProcAddress(lib,"simGetObjectSizeValues",true));
    simDisplayDialog=(ptrSimDisplayDialog)(_getProcAddress(lib,"simDisplayDialog",false));
    simScaleSelectedObjects=(ptrSimScaleSelectedObjects)(_getProcAddress(lib,"simScaleSelectedObjects",true));
    _simGetDynamicForceSensorLocalTransformationPart2=(ptr_simGetDynamicForceSensorLocalTransformationPart2)(_getProcAddress(lib,"_simGetDynamicForceSensorLocalTransformationPart2",true));
    _simSetDynamicJointLocalTransformationPart2=(ptr_simSetDynamicJointLocalTransformationPart2)(_getProcAddress(lib,"_simSetDynamicJointLocalTransformationPart2",true));
    _simSetDynamicForceSensorLocalTransformationPart2=(ptr_simSetDynamicForceSensorLocalTransformationPart2)(_getProcAddress(lib,"_simSetDynamicForceSensorLocalTransformationPart2",true));
    simSetScriptAttribute=(ptrSimSetScriptAttribute)(_getProcAddress(lib,"simSetScriptAttribute",true));
    simGetScriptAttribute=(ptrSimGetScriptAttribute)(_getProcAddress(lib,"simGetScriptAttribute",true));
    simGetJointMaxForce=(ptrSimGetJointMaxForce)(_getProcAddress(lib,"simGetJointMaxForce",true));
    simSetJointMaxForce=(ptrSimSetJointMaxForce)(_getProcAddress(lib,"simSetJointMaxForce",true));
    simCreatePureShape=(ptrSimCreatePureShape)(_getProcAddress(lib,"simCreatePureShape",true));
    _simGetMotorPid=(ptr_simGetMotorPid)(_getProcAddress(lib,"_simGetMotorPid",true));
    simBuildMatrixQ=(ptrSimBuildMatrixQ)(_getProcAddress(lib,"simBuildMatrixQ",true));
    _simGetLocalInertiaFrame=(ptr_simGetLocalInertiaFrame)(_getProcAddress(lib,"_simGetLocalInertiaFrame",true));
    _simGetPrincipalMomentOfInertia=(ptr_simGetPrincipalMomentOfInertia)(_getProcAddress(lib,"_simGetPrincipalMomentOfInertia",true));
    simGetQuaternionFromMatrix=(ptrSimGetQuaternionFromMatrix)(_getProcAddress(lib,"simGetQuaternionFromMatrix",true));
    simGetShapeVertex=(ptrSimGetShapeVertex)(_getProcAddress(lib,"simGetShapeVertex",true));
    simGetShapeTriangle=(ptrSimGetShapeTriangle)(_getProcAddress(lib,"simGetShapeTriangle",true));
    simGetObjectIntParameter=(ptrSimGetObjectInt32Param)(_getProcAddress(lib,"simGetObjectInt32Param",false));
    simSetObjectIntParameter=(ptrSimSetObjectInt32Param)(_getProcAddress(lib,"simSetObjectInt32Param",false));
    simGetObjectInt32Parameter=(ptrSimGetObjectInt32Param)(_getProcAddress(lib,"simGetObjectInt32Param",false));
    simSetObjectInt32Parameter=(ptrSimSetObjectInt32Param)(_getProcAddress(lib,"simSetObjectInt32Param",false));
    simGetObjectFloatParameter=(ptrSimGetObjectFloatParam)(_getProcAddress(lib,"simGetObjectFloatParam",true));
    simSetObjectFloatParameter=(ptrSimSetObjectFloatParam)(_getProcAddress(lib,"simSetObjectFloatParam",true));
    simGetObjectStringParameter=(ptrSimGetObjectStringParam)(_getProcAddress(lib,"simGetObjectStringParam",false));
    simSetObjectStringParameter=(ptrSimSetObjectStringParam)(_getProcAddress(lib,"simSetObjectStringParam",false));
    simSetBooleanParameter=(ptrSimSetBoolParam)(_getProcAddress(lib,"simSetBoolParam",false));
    simGetBooleanParameter=(ptrSimGetBoolParam)(_getProcAddress(lib,"simGetBoolParam",false));
    simSetBoolParameter=(ptrSimSetBoolParam)(_getProcAddress(lib,"simSetBoolParam",false));
    simGetBoolParameter=(ptrSimGetBoolParam)(_getProcAddress(lib,"simGetBoolParam",false));
    simSetIntegerParameter=(ptrSimSetInt32Param)(_getProcAddress(lib,"simSetInt32Param",false));
    simGetIntegerParameter=(ptrSimGetInt32Param)(_getProcAddress(lib,"simGetInt32Param",false));
    simSetInt32Parameter=(ptrSimSetInt32Param)(_getProcAddress(lib,"simSetInt32Param",false));
    simGetInt32Parameter=(ptrSimGetInt32Param)(_getProcAddress(lib,"simGetInt32Param",false));
    simGetUInt64Parameter=(ptrSimGetUInt64Param)(_getProcAddress(lib,"simGetUInt64Param",false));
    simSetFloatingParameter=(ptrSimSetFloatParam)(_getProcAddress(lib,"simSetFloatParam",true));
    simGetFloatingParameter=(ptrSimGetFloatParam)(_getProcAddress(lib,"simGetFloatParam",true));
    simSetFloatParameter=(ptrSimSetFloatParam)(_getProcAddress(lib,"simSetFloatParam",true));
    simGetFloatParameter=(ptrSimGetFloatParam)(_getProcAddress(lib,"simGetFloatParam",true));
    simSetStringParameter=(ptrSimSetStringParam)(_getProcAddress(lib,"simSetStringParam",false));
    simGetStringParameter=(ptrSimGetStringParam)(_getProcAddress(lib,"simGetStringParam",false));
    simSetArrayParameter=(ptrSimSetArrayParam)(_getProcAddress(lib,"simSetArrayParam",true));
    simGetArrayParameter=(ptrSimGetArrayParam)(_getProcAddress(lib,"simGetArrayParam",true));
    simGetEngineFloatParameter=(ptrSimGetEngineFloatParam)(_getProcAddress(lib,"simGetEngineFloatParam",true));
    simGetEngineInt32Parameter=(ptrSimGetEngineInt32Param)(_getProcAddress(lib,"simGetEngineInt32Param",false));
    simGetEngineBoolParameter=(ptrSimGetEngineBoolParam)(_getProcAddress(lib,"simGetEngineBoolParam",false));
    simSetEngineFloatParameter=(ptrSimSetEngineFloatParam)(_getProcAddress(lib,"simSetEngineFloatParam",true));
    simSetEngineInt32Parameter=(ptrSimSetEngineInt32Param)(_getProcAddress(lib,"simSetEngineInt32Param",false));
    simSetEngineBoolParameter=(ptrSimSetEngineBoolParam)(_getProcAddress(lib,"simSetEngineBoolParam",false));
    simIsHandleValid=(ptrSimIsHandle)(_getProcAddress(lib,"simIsHandle",false));
    simSetIntegerSignal=(ptrSimSetInt32Signal)(_getProcAddress(lib,"simSetInt32Signal",false));
    simGetIntegerSignal=(ptrSimGetInt32Signal)(_getProcAddress(lib,"simGetInt32Signal",false));
    simClearIntegerSignal=(ptrSimClearInt32Signal)(_getProcAddress(lib,"simClearInt32Signal",false));
    simSetStringNamedParam=(ptrSimSetNamedStringParam)(_getProcAddress(lib,"simSetStringNamedParam",false));
    simGetStringNamedParam=(ptrSimGetNamedStringParam)(_getProcAddress(lib,"simGetStringNamedParam",false));

    char *ps=std::getenv("COPPELIASIMPLUGIN_IGNORE_MISSING_SYMBOLS");
    if (ps!=nullptr)
        return(1);

    char couldNotFind[]="Could not find function";

    if (simGetMaterialId==nullptr)
    {
        printf("%s simGetMaterialId\n",couldNotFind);
        return 0;
    }
    if (simGetShapeMaterial==nullptr)
    {
        printf("%s simGetShapeMaterial\n",couldNotFind);
        return 0;
    }
    if (simHandleVarious==nullptr)
    {
        printf("%s simHandleVarious\n",couldNotFind);
        return 0;
    }
    if (simSerialPortOpen==nullptr)
    {
        printf("%s simSerialPortOpen\n",couldNotFind);
        return 0;
    }
    if (simSerialPortClose==nullptr)
    {
        printf("%s simSerialPortClose\n",couldNotFind);
        return 0;
    }
    if (simSerialPortSend==nullptr)
    {
        printf("%s simSerialPortSend\n",couldNotFind);
        return 0;
    }
    if (simSerialPortRead==nullptr)
    {
        printf("%s simSerialPortRead\n",couldNotFind);
        return 0;
    }
    if (simJointGetForce==nullptr)
    {
        printf("%s simJointGetForce\n",couldNotFind);
        return 0;
    }
    if (simGetPathPlanningHandle==nullptr)
    {
        printf("%s simGetPathPlanningHandle\n",couldNotFind);
        return 0;
    }
    if (simGetMotionPlanningHandle==nullptr)
    {
        printf("%s simGetMotionPlanningHandle\n",couldNotFind);
        return 0;
    }
    if (simGetMpConfigForTipPose==nullptr)
    {
        printf("%s simGetMpConfigForTipPose\n",couldNotFind);
        return 0;
    }
    if (simFindMpPath==nullptr)
    {
        printf("%s simFindMpPath\n",couldNotFind);
        return 0;
    }
    if (simSimplifyMpPath==nullptr)
    {
        printf("%s simSimplifyMpPath\n",couldNotFind);
        return 0;
    }
    if (simGetMpConfigTransition==nullptr)
    {
        printf("%s simGetMpConfigTransition\n",couldNotFind);
        return 0;
    }
    if (simFindIkPath==nullptr)
    {
        printf("%s simFindIkPath\n",couldNotFind);
        return 0;
    }
    if (simCreateMotionPlanning==nullptr)
    {
        printf("%s simCreateMotionPlanning\n",couldNotFind);
        return 0;
    }
    if (simRemoveMotionPlanning==nullptr)
    {
        printf("%s simRemoveMotionPlanning\n",couldNotFind);
        return 0;
    }
    if (simSearchPath==nullptr)
    {
        printf("%s simSearchPath\n",couldNotFind);
        return 0;
    }
    if (simInitializePathSearch==nullptr)
    {
        printf("%s simInitializePathSearch\n",couldNotFind);
        return 0;
    }
    if (simPerformPathSearchStep==nullptr)
    {
        printf("%s simPerformPathSearchStep\n",couldNotFind);
        return 0;
    }
    if (simLockInterface==nullptr)
    {
        printf("%s simLockInterface\n",couldNotFind);
        return 0;
    }
    if (simCopyPasteSelectedObjects==nullptr)
    {
        printf("%s simCopyPasteSelectedObjects\n",couldNotFind);
        return 0;
    }
    if (simResetPath==nullptr)
    {
        printf("%s simResetPath\n",couldNotFind);
        return 0;
    }
    if (simHandlePath==nullptr)
    {
        printf("%s simHandlePath\n",couldNotFind);
        return 0;
    }
    if (simResetJoint==nullptr)
    {
        printf("%s simResetJoint\n",couldNotFind);
        return 0;
    }
    if (simHandleJoint==nullptr)
    {
        printf("%s simHandleJoint\n",couldNotFind);
        return 0;
    }
    if (simAppendScriptArrayEntry==nullptr)
    {
        printf("%s simAppendScriptArrayEntry\n",couldNotFind);
        return 0;
    }
    if (simClearScriptVariable==nullptr)
    {
        printf("%s simClearScriptVariable\n",couldNotFind);
        return 0;
    }
    if (simAddSceneCustomData==nullptr)
    {
        printf("%s simAddSceneCustomData\n",couldNotFind);
        return 0;
    }
    if (simGetSceneCustomDataLength==nullptr)
    {
        printf("%s simGetSceneCustomDataLength\n",couldNotFind);
        return 0;
    }
    if (simGetSceneCustomData==nullptr)
    {
        printf("%s simGetSceneCustomData\n",couldNotFind);
        return 0;
    }
    if (simAddObjectCustomData==nullptr)
    {
        printf("%s simAddObjectCustomData\n",couldNotFind);
        return 0;
    }
    if (simGetObjectCustomDataLength==nullptr)
    {
        printf("%s simGetObjectCustomDataLength\n",couldNotFind);
        return 0;
    }
    if (simGetObjectCustomData==nullptr)
    {
        printf("%s simGetObjectCustomData\n",couldNotFind);
        return 0;
    }
    if (simCreateUI==nullptr)
    {
        printf("%s simCreateUI\n",couldNotFind);
        return 0;
    }
    if (simCreateUIButton==nullptr)
    {
        printf("%s simCreateUIButton\n",couldNotFind);
        return 0;
    }
    if (simGetUIHandle==nullptr)
    {
        printf("%s simGetUIHandle\n",couldNotFind);
        return 0;
    }
    if (simGetUIProperty==nullptr)
    {
        printf("%s simGetUIProperty\n",couldNotFind);
        return 0;
    }
    if (simGetUIEventButton==nullptr)
    {
        printf("%s simGetUIEventButton\n",couldNotFind);
        return 0;
    }
    if (simSetUIProperty==nullptr)
    {
        printf("%s simSetUIProperty\n",couldNotFind);
        return 0;
    }
    if (simGetUIButtonProperty==nullptr)
    {
        printf("%s simGetUIButtonProperty\n",couldNotFind);
        return 0;
    }
    if (simSetUIButtonProperty==nullptr)
    {
        printf("%s simSetUIButtonProperty\n",couldNotFind);
        return 0;
    }
    if (simGetUIButtonSize==nullptr)
    {
        printf("%s simGetUIButtonSize\n",couldNotFind);
        return 0;
    }
    if (simSetUIButtonLabel==nullptr)
    {
        printf("%s simSetUIButtonLabel\n",couldNotFind);
        return 0;
    }
    if (simGetUIButtonLabel==nullptr)
    {
        printf("%s simGetUIButtonLabel\n",couldNotFind);
        return 0;
    }
    if (simSetUISlider==nullptr)
    {
        printf("%s simSetUISlider\n",couldNotFind);
        return 0;
    }
    if (simGetUISlider==nullptr)
    {
        printf("%s simGetUISlider\n",couldNotFind);
        return 0;
    }
    if (simSetUIButtonColor==nullptr)
    {
        printf("%s simSetUIButtonColor\n",couldNotFind);
        return 0;
    }
    if (simSetUIButtonTexture==nullptr)
    {
        printf("%s simSetUIButtonTexture\n",couldNotFind);
        return 0;
    }
    if (simCreateUIButtonArray==nullptr)
    {
        printf("%s simCreateUIButtonArray\n",couldNotFind);
        return 0;
    }
    if (simSetUIButtonArrayColor==nullptr)
    {
        printf("%s simSetUIButtonArrayColor\n",couldNotFind);
        return 0;
    }
    if (simDeleteUIButtonArray==nullptr)
    {
        printf("%s simDeleteUIButtonArray\n",couldNotFind);
        return 0;
    }
    if (simRemoveUI==nullptr)
    {
        printf("%s simRemoveUI\n",couldNotFind);
        return 0;
    }
    if (simSetUIPosition==nullptr)
    {
        printf("%s simSetUIPosition\n",couldNotFind);
        return 0;
    }
    if (simGetUIPosition==nullptr)
    {
        printf("%s simGetUIPosition\n",couldNotFind);
        return 0;
    }
    if (simLoadUI==nullptr)
    {
        printf("%s simLoadUI\n",couldNotFind);
        return 0;
    }
    if (simSaveUI==nullptr)
    {
        printf("%s simSaveUI\n",couldNotFind);
        return 0;
    }
    if (simHandleGeneralCallbackScript==nullptr)
    {
        printf("%s simHandleGeneralCallbackScript\n",couldNotFind);
        return 0;
    }
    if (simRegisterCustomLuaFunction==nullptr)
    {
        printf("%s simRegisterCustomLuaFunction\n",couldNotFind);
        return 0;
    }
    if (simRegisterCustomLuaVariable==nullptr)
    {
        printf("%s simRegisterCustomLuaVariable\n",couldNotFind);
        return 0;
    }
    if (simRegisterContactCallback==nullptr)
    {
        printf("%s simRegisterContactCallback\n",couldNotFind);
        return 0;
    }
    if (simGetMechanismHandle==nullptr)
    {
        printf("%s simGetMechanismHandle\n",couldNotFind);
        return 0;
    }
    if (simHandleMechanism==nullptr)
    {
        printf("%s simHandleMechanism\n",couldNotFind);
        return 0;
    }
    if (simHandleCustomizationScripts==nullptr)
    {
        printf("%s simHandleCustomizationScripts\n",couldNotFind);
        return 0;
    }
    if (simSetVisionSensorFilter==nullptr)
    {
        printf("%s simSetVisionSensorFilter\n",couldNotFind);
        return 0;
    }
    if (simGetVisionSensorFilter==nullptr)
    {
        printf("%s simGetVisionSensorFilter\n",couldNotFind);
        return 0;
    }
    if (simGetScriptSimulationParameter==nullptr)
    {
        printf("%s simGetScriptSimulationParameter\n",couldNotFind);
        return 0;
    }
    if (simSetScriptSimulationParameter==nullptr)
    {
        printf("%s simSetScriptSimulationParameter\n",couldNotFind);
        return 0;
    }
    if (simSetJointForce==nullptr)
    {
        printf("%s simSetJointForce\n",couldNotFind);
        return 0;
    }
    if (simHandleMill==nullptr)
    {
        printf("%s simHandleMill\n",couldNotFind);
        return 0;
    }
    if (simResetMill==nullptr)
    {
        printf("%s simResetMill\n",couldNotFind);
        return 0;
    }
    if (simResetMilling==nullptr)
    {
        printf("%s simResetMilling\n",couldNotFind);
        return 0;
    }
    if (simApplyMilling==nullptr)
    {
        printf("%s simApplyMilling\n",couldNotFind);
        return 0;
    }
    if (_simGetParentFollowsDynamic==nullptr)
    {
        printf("%s _simGetParentFollowsDynamic\n",couldNotFind);
        return 0;
    }
    if (simGetNameSuffix==nullptr)
    {
        printf("%s simGetNameSuffix\n",couldNotFind);
        return 0;
    }
    if (simSetNameSuffix==nullptr)
    {
        printf("%s simSetNameSuffix\n",couldNotFind);
        return 0;
    }
    if (simAddStatusbarMessage==nullptr)
    {
        printf("%s simAddStatusbarMessage\n",couldNotFind);
        return 0;
    }
    if (simGetScriptRawBuffer==nullptr)
    {
        printf("%s simGetScriptRawBuffer\n",couldNotFind);
        return 0;
    }
    if (simSetScriptRawBuffer==nullptr)
    {
        printf("%s simSetScriptRawBuffer\n",couldNotFind);
        return 0;
    }
    if (simReleaseScriptRawBuffer==nullptr)
    {
        printf("%s simReleaseScriptRawBuffer\n",couldNotFind);
        return 0;
    }
    if (simSetShapeMassAndInertia==nullptr)
    {
        printf("%s simSetShapeMassAndInertia\n",couldNotFind);
        return 0;
    }
    if (simGetShapeMassAndInertia==nullptr)
    {
        printf("%s simGetShapeMassAndInertia\n",couldNotFind);
        return 0;
    }
    if (simCheckIkGroup==nullptr)
    {
        printf("%s simCheckIkGroup\n",couldNotFind);
        return 0;
    }
    if (simCreateIkGroup==nullptr)
    {
        printf("%s simCreateIkGroup\n",couldNotFind);
        return 0;
    }
    if (simRemoveIkGroup==nullptr)
    {
        printf("%s simRemoveIkGroup\n",couldNotFind);
        return 0;
    }
    if (simCreateIkElement==nullptr)
    {
        printf("%s simCreateIkElement\n",couldNotFind);
        return 0;
    }
    if (simExportIk==nullptr)
    {
        printf("%s simExportIk\n",couldNotFind);
        return 0;
    }
    if (simComputeJacobian==nullptr)
    {
        printf("%s simComputeJacobian\n",couldNotFind);
        return 0;
    }
    if (simGetConfigForTipPose==nullptr)
    {
        printf("%s simGetConfigForTipPose\n",couldNotFind);
        return 0;
    }
    if (simGenerateIkPath==nullptr)
    {
        printf("%s simGenerateIkPath\n",couldNotFind);
        return 0;
    }
    if (simGetIkGroupHandle==nullptr)
    {
        printf("%s simGetIkGroupHandle\n",couldNotFind);
        return 0;
    }
    if (simGetIkGroupMatrix==nullptr)
    {
        printf("%s simGetIkGroupMatrix\n",couldNotFind);
        return 0;
    }
    if (simHandleIkGroup==nullptr)
    {
        printf("%s simHandleIkGroup\n",couldNotFind);
        return 0;
    }
    if (simSetIkGroupProperties==nullptr)
    {
        printf("%s simSetIkGroupProperties\n",couldNotFind);
        return 0;
    }
    if (simSetIkElementProperties==nullptr)
    {
        printf("%s simSetIkElementProperties\n",couldNotFind);
        return 0;
    }
    if (simSetThreadIsFree==nullptr)
    {
        printf("%s simSetThreadIsFree\n",couldNotFind);
        return 0;
    }
    if (simTubeOpen==nullptr)
    {
        printf("%s simTubeOpen\n",couldNotFind);
        return 0;
    }
    if (simTubeClose==nullptr)
    {
        printf("%s simTubeClose\n",couldNotFind);
        return 0;
    }
    if (simTubeWrite==nullptr)
    {
        printf("%s simTubeWrite\n",couldNotFind);
        return 0;
    }
    if (simTubeRead==nullptr)
    {
        printf("%s simTubeRead\n",couldNotFind);
        return 0;
    }
    if (simTubeStatus==nullptr)
    {
        printf("%s simTubeStatus\n",couldNotFind);
        return 0;
    }
    if (simSendData==nullptr)
    {
        printf("%s simSendData\n",couldNotFind);
        return 0;
    }
    if (simReceiveData==nullptr)
    {
        printf("%s simReceiveData\n",couldNotFind);
        return 0;
    }
    if (simGetPositionOnPath==nullptr)
    {
        printf("%s simGetPositionOnPath\n",couldNotFind);
        return 0;
    }
    if (simGetDataOnPath==nullptr)
    {
        printf("%s simGetDataOnPath\n",couldNotFind);
        return 0;
    }
    if (simGetOrientationOnPath==nullptr)
    {
        printf("%s simGetOrientationOnPath\n",couldNotFind);
        return 0;
    }
    if (simGetClosestPositionOnPath==nullptr)
    {
        printf("%s simGetClosestPositionOnPath\n",couldNotFind);
        return 0;
    }
    if (simGetPathPosition==nullptr)
    {
        printf("%s simGetPathPosition\n",couldNotFind);
        return 0;
    }
    if (simSetPathPosition==nullptr)
    {
        printf("%s simSetPathPosition\n",couldNotFind);
        return 0;
    }
    if (simGetPathLength==nullptr)
    {
        printf("%s simGetPathLength\n",couldNotFind);
        return 0;
    }
    if (simCreatePath==nullptr)
    {
        printf("%s simCreatePath\n",couldNotFind);
        return 0;
    }
    if (simInsertPathCtrlPoints==nullptr)
    {
        printf("%s simInsertPathCtrlPoints\n",couldNotFind);
        return 0;
    }
    if (simCutPathCtrlPoints==nullptr)
    {
        printf("%s simCutPathCtrlPoints\n",couldNotFind);
        return 0;
    }
    if (simGetThreadId==nullptr)
    {
        printf("%s simGetThreadId\n",couldNotFind);
        return 0;
    }
    if (simSwitchThread==nullptr)
    {
        printf("%s simSwitchThread\n",couldNotFind);
        return 0;
    }
    if (simLockResources==nullptr)
    {
        printf("%s simLockResources\n",couldNotFind);
        return 0;
    }
    if (simUnlockResources==nullptr)
    {
        printf("%s simUnlockResources\n",couldNotFind);
        return 0;
    }
    if (simGetUserParameter==nullptr)
    {
        printf("%s simGetUserParameter\n",couldNotFind);
        return 0;
    }
    if (simSetUserParameter==nullptr)
    {
        printf("%s simSetUserParameter\n",couldNotFind);
        return 0;
    }
    if (simSetPathTargetNominalVelocity==nullptr)
    {
        printf("%s simSetPathTargetNominalVelocity\n",couldNotFind);
        return 0;
    }
    if (simGetCollectionHandle==nullptr)
    {
        printf("%s simGetCollectionHandle\n",couldNotFind);
        return 0;
    }
    if (simRemoveCollection==nullptr)
    {
        printf("%s simRemoveCollection\n",couldNotFind);
        return 0;
    }
    if (simEmptyCollection==nullptr)
    {
        printf("%s simEmptyCollection\n",couldNotFind);
        return 0;
    }
    if (simGetCollectionName==nullptr)
    {
        printf("%s simGetCollectionName\n",couldNotFind);
        return 0;
    }
    if (simSetCollectionName==nullptr)
    {
        printf("%s simSetCollectionName\n",couldNotFind);
        return 0;
    }
    if (simCreateCollection==nullptr)
    {
        printf("%s simCreateCollection\n",couldNotFind);
        return 0;
    }
    if (simAddObjectToCollection==nullptr)
    {
        printf("%s simAddObjectToCollection\n",couldNotFind);
        return 0;
    }
    if (simHandleCollision==nullptr)
    {
        printf("%s simHandleCollision\n",couldNotFind);
        return 0;
    }
    if (simReadCollision==nullptr)
    {
        printf("%s simReadCollision\n",couldNotFind);
        return 0;
    }
    if (simHandleDistance==nullptr)
    {
        printf("%s simHandleDistance\n",couldNotFind);
        return 0;
    }
    if (simReadDistance==nullptr)
    {
        printf("%s simReadDistance\n",couldNotFind);
        return 0;
    }
    if (simGetCollisionHandle==nullptr)
    {
        printf("%s simGetCollisionHandle\n",couldNotFind);
        return 0;
    }
    if (simGetDistanceHandle==nullptr)
    {
        printf("%s simGetDistanceHandle\n",couldNotFind);
        return 0;
    }
    if (simResetCollision==nullptr)
    {
        printf("%s simResetCollision\n",couldNotFind);
        return 0;
    }
    if (simResetDistance==nullptr)
    {
        printf("%s simResetDistance\n",couldNotFind);
        return 0;
    }
    if (simAddBanner==nullptr)
    {
        printf("%s simAddBanner\n",couldNotFind);
        return 0;
    }
    if (simRemoveBanner==nullptr)
    {
        printf("%s simRemoveBanner\n",couldNotFind);
        return 0;
    }
    if (simAddGhost==nullptr)
    {
        printf("%s simAddGhost\n",couldNotFind);
        return 0;
    }
    if (simModifyGhost==nullptr)
    {
        printf("%s simModifyGhost\n",couldNotFind);
        return 0;
    }
    if (simSetGraphUserData==nullptr)
    {
        printf("%s simSetGraphUserData\n",couldNotFind);
        return 0;
    }
    if (simCopyMatrix==nullptr)
    {
        printf("%s simCopyMatrix\n",couldNotFind);
        return 0;
    }
    if (simGetObjectIntParameter==nullptr)
    {
        printf("%s simGetObjectIntParameter\n",couldNotFind);
        return 0;
    }
    if (simSetObjectIntParameter==nullptr)
    {
        printf("%s simSetObjectIntParameter\n",couldNotFind);
        return 0;
    }
    if (simGetObjectInt32Parameter==nullptr)
    {
        printf("%s simGetObjectInt32Parameter\n",couldNotFind);
        return 0;
    }
    if (simSetObjectInt32Parameter==nullptr)
    {
        printf("%s simSetObjectInt32Parameter\n",couldNotFind);
        return 0;
    }
    if (simGetObjectFloatParameter==nullptr)
    {
        printf("%s simGetObjectFloatParameter\n",couldNotFind);
        return 0;
    }
    if (simSetObjectFloatParameter==nullptr)
    {
        printf("%s simSetObjectFloatParameter\n",couldNotFind);
        return 0;
    }
    if (simGetObjectStringParameter==nullptr)
    {
        printf("%s simGetObjectStringParameter\n",couldNotFind);
        return 0;
    }
    if (simSetObjectStringParameter==nullptr)
    {
        printf("%s simSetObjectStringParameter\n",couldNotFind);
        return 0;
    }
    if (simSetBooleanParameter==nullptr)
    {
        printf("%s simSetBooleanParameter\n",couldNotFind);
        return 0;
    }
    if (simGetBooleanParameter==nullptr)
    {
        printf("%s simGetBooleanParameter\n",couldNotFind);
        return 0;
    }
    if (simSetBoolParameter==nullptr)
    {
        printf("%s simSetBoolParameter\n",couldNotFind);
        return 0;
    }
    if (simGetBoolParameter==nullptr)
    {
        printf("%s simGetBoolParameter\n",couldNotFind);
        return 0;
    }
    if (simSetIntegerParameter==nullptr)
    {
        printf("%s simSetIntegerParameter\n",couldNotFind);
        return 0;
    }
    if (simGetIntegerParameter==nullptr)
    {
        printf("%s simGetIntegerParameter\n",couldNotFind);
        return 0;
    }
    if (simSetInt32Parameter==nullptr)
    {
        printf("%s simSetInt32Parameter\n",couldNotFind);
        return 0;
    }
    if (simGetInt32Parameter==nullptr)
    {
        printf("%s simGetInt32Parameter\n",couldNotFind);
        return 0;
    }
    if (simGetUInt64Parameter==nullptr)
    {
        printf("%s simGetUInt64Parameter\n",couldNotFind);
        return 0;
    }
    if (simSetFloatingParameter==nullptr)
    {
        printf("%s simSetFloatingParameter\n",couldNotFind);
        return 0;
    }
    if (simGetFloatingParameter==nullptr)
    {
        printf("%s simGetFloatingParameter\n",couldNotFind);
        return 0;
    }
    if (simSetFloatParameter==nullptr)
    {
        printf("%s simSetFloatParameter\n",couldNotFind);
        return 0;
    }
    if (simGetFloatParameter==nullptr)
    {
        printf("%s simGetFloatParameter\n",couldNotFind);
        return 0;
    }
    if (simSetStringParameter==nullptr)
    {
        printf("%s simSetStringParameter\n",couldNotFind);
        return 0;
    }
    if (simGetStringParameter==nullptr)
    {
        printf("%s simGetStringParameter\n",couldNotFind);
        return 0;
    }
    if (simSetArrayParameter==nullptr)
    {
        printf("%s simSetArrayParameter\n",couldNotFind);
        return 0;
    }
    if (simGetArrayParameter==nullptr)
    {
        printf("%s simGetArrayParameter\n",couldNotFind);
        return 0;
    }
    if (simGetEngineFloatParameter==nullptr)
    {
        printf("%s simGetEngineFloatParameter\n",couldNotFind);
        return 0;
    }
    if (simGetEngineInt32Parameter==nullptr)
    {
        printf("%s simGetEngineInt32Parameter\n",couldNotFind);
        return 0;
    }
    if (simGetEngineBoolParameter==nullptr)
    {
        printf("%s simGetEngineBoolParameter\n",couldNotFind);
        return 0;
    }
    if (simSetEngineFloatParameter==nullptr)
    {
        printf("%s simSetEngineFloatParameter\n",couldNotFind);
        return 0;
    }
    if (simSetEngineInt32Parameter==nullptr)
    {
        printf("%s simSetEngineInt32Parameter\n",couldNotFind);
        return 0;
    }
    if (simSetEngineBoolParameter==nullptr)
    {
        printf("%s simSetEngineBoolParameter\n",couldNotFind);
        return 0;
    }
    if (simIsHandleValid==nullptr)
    {
        printf("%s simIsHandleValid\n",couldNotFind);
        return 0;
    }
    if (simSetIntegerSignal==nullptr)
    {
        printf("%s simSetIntegerSignal\n",couldNotFind);
        return 0;
    }
    if (simGetIntegerSignal==nullptr)
    {
        printf("%s simGetIntegerSignal\n",couldNotFind);
        return 0;
    }
    if (simClearIntegerSignal==nullptr)
    {
        printf("%s simClearIntegerSignal\n",couldNotFind);
        return 0;
    }
    if (simGetObjectName==nullptr)
    {
        printf("%s simGetObjectName\n",couldNotFind);
        return 0;
    }
    if (simSetObjectName==nullptr)
    {
        printf("%s simSetObjectName\n",couldNotFind);
        return 0;
    }
    if (simGetScriptName==nullptr)
    {
        printf("%s simGetScriptName\n",couldNotFind);
        return 0;
    }
    if (simGetScriptHandle==nullptr)
    {
        printf("%s simGetScriptHandle\n",couldNotFind);
        return 0;
    }
    if (simSetScriptVariable==nullptr)
    {
        printf("%s simSetScriptVariable\n",couldNotFind);
        return 0;
    }
    if (simGetObjectHandle==nullptr)
    {
        printf("%s simGetObjectHandle\n",couldNotFind);
        return 0;
    }
    if (simGetObjectHandleEx==nullptr)
    {
        printf("%s simGetObjectHandleEx\n",couldNotFind);
        return 0;
    }
    if (simGetScript==nullptr)
    {
        printf("%s simGetScript\n",couldNotFind);
        return 0;
    }
    if (simGetScriptAssociatedWithObject==nullptr)
    {
        printf("%s simGetScriptAssociatedWithObject\n",couldNotFind);
        return 0;
    }
    if (simGetCustomizationScriptAssociatedWithObject==nullptr)
    {
        printf("%s simGetCustomizationScriptAssociatedWithObject\n",couldNotFind);
        return 0;
    }
    if (simGetObjectAssociatedWithScript==nullptr)
    {
        printf("%s simGetObjectAssociatedWithScript\n",couldNotFind);
        return 0;
    }
    if (simGetObjectConfiguration==nullptr)
    {
        printf("%s simGetObjectConfiguration\n",couldNotFind);
        return 0;
    }
    if (simSetObjectConfiguration==nullptr)
    {
        printf("%s simSetObjectConfiguration\n",couldNotFind);
        return 0;
    }
    if (simGetConfigurationTree==nullptr)
    {
        printf("%s simGetConfigurationTree\n",couldNotFind);
        return 0;
    }
    if (simSetConfigurationTree==nullptr)
    {
        printf("%s simSetConfigurationTree\n",couldNotFind);
        return 0;
    }
    if (simEnableEventCallback==nullptr)
    {
        printf("%s simEnableEventCallback\n",couldNotFind);
        return 0;
    }
    if (simSetObjectSizeValues==nullptr)
    {
        printf("%s simSetObjectSizeValues\n",couldNotFind);
        return 0;
    }
    if (simGetObjectSizeValues==nullptr)
    {
        printf("%s simGetObjectSizeValues\n",couldNotFind);
        return 0;
    }
    if (simRMLPosition==nullptr)
    {
        printf("%s simRMLPosition\n",couldNotFind);
        return 0;
    }
    if (simRMLVelocity==nullptr)
    {
        printf("%s simRMLVelocity\n",couldNotFind);
        return 0;
    }
    if (simRMLPos==nullptr)
    {
        printf("%s simRMLPos\n",couldNotFind);
        return 0;
    }
    if (simRMLVel==nullptr)
    {
        printf("%s simRMLVel\n",couldNotFind);
        return 0;
    }
    if (simRMLStep==nullptr)
    {
        printf("%s simRMLStep\n",couldNotFind);
        return 0;
    }
    if (simRMLRemove==nullptr)
    {
        printf("%s simRMLRemove\n",couldNotFind);
        return 0;
    }
    if (simGetSystemTimeInMilliseconds==nullptr)
    {
        printf("%s simGetSystemTimeInMilliseconds\n",couldNotFind);
        return 0;
    }
    if (simGetSystemTimeInMs==nullptr)
    {
        printf("%s simGetSystemTimeInMs\n",couldNotFind);
        return 0;
    }
    if (simFileDialog==nullptr)
    {
        printf("%s simFileDialog\n",couldNotFind);
        return 0;
    }
    if (simMsgBox==nullptr)
    {
        printf("%s simMsgBox\n",couldNotFind);
        return 0;
    }
    if (simDisplayDialog==nullptr)
    {
        printf("%s simDisplayDialog\n",couldNotFind);
        return 0;
    }
    if (simGetDialogResult==nullptr)
    {
        printf("%s simGetDialogResult\n",couldNotFind);
        return 0;
    }
    if (simGetDialogInput==nullptr)
    {
        printf("%s simGetDialogInput\n",couldNotFind);
        return 0;
    }
    if (simEndDialog==nullptr)
    {
        printf("%s simEndDialog\n",couldNotFind);
        return 0;
    }
    if (simIsObjectInSelection==nullptr)
    {
        printf("%s simIsObjectInSelection\n",couldNotFind);
        return 0;
    }
    if (simAddObjectToSelection==nullptr)
    {
        printf("%s simAddObjectToSelection\n",couldNotFind);
        return 0;
    }
    if (simRemoveObjectFromSelection==nullptr)
    {
        printf("%s simRemoveObjectFromSelection\n",couldNotFind);
        return 0;
    }
    if (simGetObjectSelectionSize==nullptr)
    {
        printf("%s simGetObjectSelectionSize\n",couldNotFind);
        return 0;
    }
    if (simGetObjectLastSelection==nullptr)
    {
        printf("%s simGetObjectLastSelection\n",couldNotFind);
        return 0;
    }
    if (simGetObjectSelection==nullptr)
    {
        printf("%s simGetObjectSelection\n",couldNotFind);
        return 0;
    }
    if (simScaleSelectedObjects==nullptr)
    {
        printf("%s simScaleSelectedObjects\n",couldNotFind);
        return 0;
    }
    if (simDeleteSelectedObjects==nullptr)
    {
        printf("%s simDeleteSelectedObjects\n",couldNotFind);
        return 0;
    }
    if (simSetStringNamedParam==nullptr)
    {
        printf("%s simSetStringNamedParam\n",couldNotFind);
        return 0;
    }
    if (simGetStringNamedParam==nullptr)
    {
        printf("%s simGetStringNamedParam\n",couldNotFind);
        return 0;
    }
    if (simGetObjectUniqueIdentifier==nullptr)
    {
        printf("%s simGetObjectUniqueIdentifier\n",couldNotFind);
        return 0;
    }
    if (_simSetDynamicJointLocalTransformationPart2==nullptr)
    {
        printf("%s _simSetDynamicJointLocalTransformationPart2\n",couldNotFind);
        return 0;
    }
    if (_simSetDynamicForceSensorLocalTransformationPart2==nullptr)
    {
        printf("%s _simSetDynamicForceSensorLocalTransformationPart2\n",couldNotFind);
        return 0;
    }
    if (_simSetDynamicJointLocalTransformationPart2IsValid==nullptr)
    {
        printf("%s _simSetDynamicJointLocalTransformationPart2IsValid\n",couldNotFind);
        return 0;
    }
    if (_simSetDynamicForceSensorLocalTransformationPart2IsValid==nullptr)
    {
        printf("%s _simSetDynamicForceSensorLocalTransformationPart2IsValid\n",couldNotFind);
        return 0;
    }
    if (_simGetDynamicForceSensorLocalTransformationPart2==nullptr)
    {
        printf("%s _simGetDynamicForceSensorLocalTransformationPart2\n",couldNotFind);
        return 0;
    }
    if (_simIsForceSensorBroken==nullptr)
    {
        printf("%s _simIsForceSensorBroken\n",couldNotFind);
        return 0;
    }
    if (simBreakForceSensor==nullptr)
    {
        printf("%s simBreakForceSensor\n",couldNotFind);
        return 0;
    }
    if (simSetScriptAttribute==nullptr)
    {
        printf("%s simSetScriptAttribute\n",couldNotFind);
        return 0;
    }
    if (simGetScriptAttribute==nullptr)
    {
        printf("%s simGetScriptAttribute\n",couldNotFind);
        return 0;
    }
    if (simSetScriptText==nullptr)
    {
        printf("%s simSetScriptText\n",couldNotFind);
        return 0;
    }
    if (simGetScriptText==nullptr)
    {
        printf("%s simGetScriptText\n",couldNotFind);
        return 0;
    }
    if (simGetScriptProperty==nullptr)
    {
        printf("%s simGetScriptProperty\n",couldNotFind);
        return 0;
    }
    if (simGetJointMaxForce==nullptr)
    {
        printf("%s simGetJointMaxForce\n",couldNotFind);
        return 0;
    }
    if (simSetJointMaxForce==nullptr)
    {
        printf("%s simSetJointMaxForce\n",couldNotFind);
        return 0;
    }
    if (_simSetGeomProxyDynamicsFullRefreshFlag==nullptr)
    {
        printf("%s _simSetGeomProxyDynamicsFullRefreshFlag\n",couldNotFind);
        return 0;
    }
    if (_simGetGeomProxyDynamicsFullRefreshFlag==nullptr)
    {
        printf("%s _simGetGeomProxyDynamicsFullRefreshFlag\n",couldNotFind);
        return 0;
    }
    if (simRemoveObject==nullptr)
    {
        printf("%s simRemoveObject\n",couldNotFind);
        return 0;
    }
    if (_simSetShapeIsStaticAndNotRespondableButDynamicTag==nullptr)
    {
        printf("%s _simSetShapeIsStaticAndNotRespondableButDynamicTag\n",couldNotFind);
        return 0;
    }
    if (_simGetShapeIsStaticAndNotRespondableButDynamicTag==nullptr)
    {
        printf("%s _simGetShapeIsStaticAndNotRespondableButDynamicTag\n",couldNotFind);
        return 0;
    }
    if (simGetVisionSensorResolution==nullptr)
    {
        printf("%s simGetVisionSensorResolution\n",couldNotFind);
        return 0;
    }
    if (simGetVisionSensorImage==nullptr)
    {
        printf("%s simGetVisionSensorImage\n",couldNotFind);
        return 0;
    }
    if (simGetVisionSensorCharImage==nullptr)
    {
        printf("%s simGetVisionSensorCharImage\n",couldNotFind);
        return 0;
    }
    if (simSetVisionSensorImage==nullptr)
    {
        printf("%s simSetVisionSensorImage\n",couldNotFind);
        return 0;
    }
    if (simSetVisionSensorCharImage==nullptr)
    {
        printf("%s simSetVisionSensorCharImage\n",couldNotFind);
        return 0;
    }
    if (simGetVisionSensorDepthBuffer==nullptr)
    {
        printf("%s simGetVisionSensorDepthBuffer\n",couldNotFind);
        return 0;
    }
    if (simCreatePureShape==nullptr)
    {
        printf("%s simCreatePureShape\n",couldNotFind);
        return 0;
    }
    if (simBroadcastMessage==nullptr)
    {
        printf("%s simBroadcastMessage\n",couldNotFind);
        return 0;
    }
    if (simSendModuleMessage==nullptr)
    {
        printf("%s simSendModuleMessage\n",couldNotFind);
        return 0;
    }
    if (_simIsDynamicMotorEnabled==nullptr)
    {
        printf("%s _simIsDynamicMotorEnabled\n",couldNotFind);
        return 0;
    }
    if (_simIsDynamicMotorPositionCtrlEnabled==nullptr)
    {
        printf("%s _simIsDynamicMotorPositionCtrlEnabled\n",couldNotFind);
        return 0;
    }
    if (_simIsDynamicMotorTorqueModulationEnabled==nullptr)
    {
        printf("%s _simIsDynamicMotorTorqueModulationEnabled\n",couldNotFind);
        return 0;
    }
    if (_simGetMotorPid==nullptr)
    {
        printf("%s _simGetMotorPid\n",couldNotFind);
        return 0;
    }
    if (_simGetContactCallbackCount==nullptr)
    {
        printf("%s _simGetContactCallbackCount\n",couldNotFind);
        return 0;
    }
    if (_simGetContactCallback==nullptr)
    {
        printf("%s _simGetContactCallback\n",couldNotFind);
        return 0;
    }
    if (simBuildMatrixQ==nullptr)
    {
        printf("%s simBuildMatrixQ\n",couldNotFind);
        return 0;
    }
    if (simGetQuaternionFromMatrix==nullptr)
    {
        printf("%s simGetQuaternionFromMatrix\n",couldNotFind);
        return 0;
    }
    if (_simGetPrincipalMomentOfInertia==nullptr)
    {
        printf("%s _simGetPrincipalMomentOfInertia\n",couldNotFind);
        return 0;
    }
    if (_simGetLocalInertiaFrame==nullptr)
    {
        printf("%s _simGetLocalInertiaFrame\n",couldNotFind);
        return 0;
    }
    if (_simGetJointCallbackCallOrder==nullptr)
    {
        printf("%s _simGetJointCallbackCallOrder\n",couldNotFind);
        return 0;
    }
    if (simSetDoubleSignal==nullptr)
    {
        printf("%s simSetDoubleSignal\n",couldNotFind);
        return 0;
    }
    if (simGetDoubleSignal==nullptr)
    {
        printf("%s simGetDoubleSignal\n",couldNotFind);
        return 0;
    }
    if (simClearDoubleSignal==nullptr)
    {
        printf("%s simClearDoubleSignal\n",couldNotFind);
        return 0;
    }
    if (simAddParticleObject==nullptr)
    {
        printf("%s simAddParticleObject\n",couldNotFind);
        return 0;
    }
    if (simRemoveParticleObject==nullptr)
    {
        printf("%s simRemoveParticleObject\n",couldNotFind);
        return 0;
    }
    if (simAddParticleObjectItem==nullptr)
    {
        printf("%s simAddParticleObjectItem\n",couldNotFind);
        return 0;
    }
    if (simGetShapeVertex==nullptr)
    {
        printf("%s simGetShapeVertex\n",couldNotFind);
        return 0;
    }
    if (simGetShapeTriangle==nullptr)
    {
        printf("%s simGetShapeTriangle\n",couldNotFind);
        return 0;
    }
}
