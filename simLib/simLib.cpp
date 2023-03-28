#include "simLib.h"
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#if defined (__linux) || defined (__APPLE__)
    #include <dlfcn.h>
#endif

#ifndef SIM_LIBRARY

ptrSimAddLog _addLog=nullptr;

int simAddLog(const char* pluginName,int verbosityLevel,const char* logMsg)
{
    if (_addLog==nullptr)
    {
        std::string m("[");
        if (strcmp(pluginName,"CoppeliaSimClient")!=0)
            m+="simExt";
        m+=pluginName;
        m+="]   ";
        m+=logMsg;
        printf("%s\n",m.c_str());
        return(1);
    }
    return(_addLog(pluginName,verbosityLevel,logMsg));
}

ptrSimRunSimulator simRunSimulator=nullptr;
ptrSimRunSimulatorEx simRunSimulatorEx=nullptr;
ptrSimGetSimulatorMessage simGetSimulatorMessage=nullptr;
ptrSimGetMainWindow simGetMainWindow=nullptr;
ptrSimGetLastError simGetLastError=nullptr;
ptrSimLoadModule simLoadModule=nullptr;
ptrSimUnloadModule simUnloadModule=nullptr;
ptrSimSetBoolParam simSetBoolParam=nullptr;
ptrSimGetBoolParam simGetBoolParam=nullptr;
ptrSimSetInt32Param simSetInt32Param=nullptr;
ptrSimGetInt32Param simGetInt32Param=nullptr;
ptrSimGetUInt64Param simGetUInt64Param=nullptr;
ptrSimSetFloatParam simSetFloatParam=nullptr;
ptrSimGetFloatParam simGetFloatParam=nullptr;
ptrSimSetStringParam simSetStringParam=nullptr;
ptrSimGetStringParam simGetStringParam=nullptr;
ptrSimSetArrayParam simSetArrayParam=nullptr;
ptrSimGetArrayParam simGetArrayParam=nullptr;
ptrSimSetNamedStringParam simSetNamedStringParam=nullptr;
ptrSimGetNamedStringParam simGetNamedStringParam=nullptr;
ptrSimGetObject simGetObject=nullptr;
ptrSimGetObjectUid simGetObjectUid=nullptr;
ptrSimGetObjectFromUid simGetObjectFromUid=nullptr;
ptrSimGetScriptHandleEx simGetScriptHandleEx=nullptr;
ptrSimRemoveObjects simRemoveObjects=nullptr;
ptrSimRemoveModel simRemoveModel=nullptr;
ptrSimGetObjectAlias simGetObjectAlias=nullptr;
ptrSimSetObjectAlias simSetObjectAlias=nullptr;
ptrSimGetObjectMatrix simGetObjectMatrix=nullptr;
ptrSimSetObjectMatrix simSetObjectMatrix=nullptr;
ptrSimGetObjectPose simGetObjectPose=nullptr;
ptrSimSetObjectPose simSetObjectPose=nullptr;
ptrSimGetObjectPosition simGetObjectPosition=nullptr;
ptrSimSetObjectPosition simSetObjectPosition=nullptr;
ptrSimGetObjectOrientation simGetObjectOrientation=nullptr;
ptrSimSetObjectOrientation simSetObjectOrientation=nullptr;
ptrSimGetJointPosition simGetJointPosition=nullptr;
ptrSimSetJointPosition simSetJointPosition=nullptr;
ptrSimSetJointTargetPosition simSetJointTargetPosition=nullptr;
ptrSimGetJointTargetPosition simGetJointTargetPosition=nullptr;
ptrSimGetObjectChildPose simGetObjectChildPose=nullptr;
ptrSimSetObjectChildPose simSetObjectChildPose=nullptr;
ptrSimGetJointInterval simGetJointInterval=nullptr;
ptrSimSetJointInterval simSetJointInterval=nullptr;
ptrSimGetObjectParent simGetObjectParent=nullptr;
ptrSimGetObjectChild simGetObjectChild=nullptr;
ptrSimSetObjectParent simSetObjectParent=nullptr;
ptrSimGetObjectType simGetObjectType=nullptr;
ptrSimGetJointType simGetJointType=nullptr;
ptrSimBuildIdentityMatrix simBuildIdentityMatrix=nullptr;
ptrSimBuildMatrix simBuildMatrix=nullptr;
ptrSimBuildPose simBuildPose=nullptr;
ptrSimGetEulerAnglesFromMatrix simGetEulerAnglesFromMatrix=nullptr;
ptrSimInvertMatrix simInvertMatrix=nullptr;
ptrSimMultiplyMatrices simMultiplyMatrices=nullptr;
ptrSimMultiplyPoses simMultiplyPoses=nullptr;
ptrSimInvertPose simInvertPose=nullptr;
ptrSimInterpolatePoses simInterpolatePoses=nullptr;
ptrSimPoseToMatrix simPoseToMatrix=nullptr;
ptrSimMatrixToPose simMatrixToPose=nullptr;
ptrSimInterpolateMatrices simInterpolateMatrices=nullptr;
ptrSimTransformVector simTransformVector=nullptr;
ptrSimReservedCommand simReservedCommand=nullptr;
ptrSimGetSimulationTime simGetSimulationTime=nullptr;
ptrSimGetSimulationState simGetSimulationState=nullptr;
ptrSimGetSystemTime simGetSystemTime=nullptr;
ptrSimLoadScene simLoadScene=nullptr;
ptrSimCloseScene simCloseScene=nullptr;
ptrSimSaveScene simSaveScene=nullptr;
ptrSimLoadModel simLoadModel=nullptr;
ptrSimSaveModel simSaveModel=nullptr;
ptrSimDoesFileExist simDoesFileExist=nullptr;
ptrSimGetObjectSel simGetObjectSel=nullptr;
ptrSimSetObjectSel simSetObjectSel=nullptr;
ptrSimHandleProximitySensor simHandleProximitySensor=nullptr;
ptrSimReadProximitySensor simReadProximitySensor=nullptr;
ptrSimHandleDynamics simHandleDynamics=nullptr;
ptrSimAssociateScriptWithObject simAssociateScriptWithObject=nullptr;
ptrSimHandleMainScript simHandleMainScript=nullptr;
ptrSimResetScript simResetScript=nullptr;
ptrSimAddScript simAddScript=nullptr;
ptrSimRemoveScript simRemoveScript=nullptr;
ptrSimRefreshDialogs simRefreshDialogs=nullptr;
ptrSimResetProximitySensor simResetProximitySensor=nullptr;
ptrSimCheckProximitySensor simCheckProximitySensor=nullptr;
ptrSimCheckProximitySensorEx simCheckProximitySensorEx=nullptr;
ptrSimCheckProximitySensorEx2 simCheckProximitySensorEx2=nullptr;
ptrSimCreateBuffer simCreateBuffer=nullptr;
ptrSimReleaseBuffer simReleaseBuffer=nullptr;
ptrSimCheckCollision simCheckCollision=nullptr;
ptrSimCheckCollisionEx simCheckCollisionEx=nullptr;
ptrSimCheckDistance simCheckDistance=nullptr;
ptrSimSetSimulationTimeStep simSetSimulationTimeStep=nullptr;
ptrSimGetSimulationTimeStep simGetSimulationTimeStep=nullptr;
ptrSimGetRealTimeSimulation simGetRealTimeSimulation=nullptr;
ptrSimIsRealTimeSimulationStepNeeded simIsRealTimeSimulationStepNeeded=nullptr;
ptrSimAdjustRealTimeTimer simAdjustRealTimeTimer=nullptr;
ptrSimGetSimulationPassesPerRenderingPass simGetSimulationPassesPerRenderingPass=nullptr;
ptrSimAdvanceSimulationByOneStep simAdvanceSimulationByOneStep=nullptr;
ptrSimStartSimulation simStartSimulation=nullptr;
ptrSimStopSimulation simStopSimulation=nullptr;
ptrSimPauseSimulation simPauseSimulation=nullptr;
ptrSimGetModuleName simGetModuleName=nullptr;
ptrSimFloatingViewAdd simFloatingViewAdd=nullptr;
ptrSimFloatingViewRemove simFloatingViewRemove=nullptr;
ptrSimAdjustView simAdjustView=nullptr;
ptrSimSetLastError simSetLastError=nullptr;
ptrSimHandleGraph simHandleGraph=nullptr;
ptrSimResetGraph simResetGraph=nullptr;
ptrSimAddGraphStream simAddGraphStream=nullptr;
ptrSimDestroyGraphCurve simDestroyGraphCurve=nullptr;
ptrSimSetGraphStreamTransformation simSetGraphStreamTransformation=nullptr;
ptrSimDuplicateGraphCurveToStatic simDuplicateGraphCurveToStatic=nullptr;
ptrSimAddGraphCurve simAddGraphCurve=nullptr;
ptrSimSetGraphStreamValue simSetGraphStreamValue=nullptr;
ptrSimSetNavigationMode simSetNavigationMode=nullptr;
ptrSimGetNavigationMode simGetNavigationMode=nullptr;
ptrSimSetPage simSetPage=nullptr;
ptrSimGetPage simGetPage=nullptr;
ptrSimRegisterScriptCallbackFunction simRegisterScriptCallbackFunction=nullptr;
ptrSimRegisterScriptVariable simRegisterScriptVariable=nullptr;
ptrSimRegisterScriptFuncHook simRegisterScriptFuncHook=nullptr;
ptrSimSetJointTargetVelocity simSetJointTargetVelocity=nullptr;
ptrSimGetJointTargetVelocity simGetJointTargetVelocity=nullptr;
ptrSimCopyPasteObjects simCopyPasteObjects=nullptr;
ptrSimScaleObjects simScaleObjects=nullptr;
ptrSimAddDrawingObject simAddDrawingObject=nullptr;
ptrSimRemoveDrawingObject simRemoveDrawingObject=nullptr;
ptrSimAddDrawingObjectItem simAddDrawingObjectItem=nullptr;
ptrSimGetObjectSizeFactor simGetObjectSizeFactor=nullptr;
ptrSimAnnounceSceneContentChange simAnnounceSceneContentChange=nullptr;
ptrSimSetInt32Signal simSetInt32Signal=nullptr;
ptrSimGetInt32Signal simGetInt32Signal=nullptr;
ptrSimClearInt32Signal simClearInt32Signal=nullptr;
ptrSimSetFloatSignal simSetFloatSignal=nullptr;
ptrSimGetFloatSignal simGetFloatSignal=nullptr;
ptrSimClearFloatSignal simClearFloatSignal=nullptr;
ptrSimSetStringSignal simSetStringSignal=nullptr;
ptrSimGetStringSignal simGetStringSignal=nullptr;
ptrSimClearStringSignal simClearStringSignal=nullptr;
ptrSimGetSignalName simGetSignalName=nullptr;
ptrSimSetObjectProperty simSetObjectProperty=nullptr;
ptrSimGetObjectProperty simGetObjectProperty=nullptr;
ptrSimSetObjectSpecialProperty simSetObjectSpecialProperty=nullptr;
ptrSimGetObjectSpecialProperty simGetObjectSpecialProperty=nullptr;
ptrSimReadForceSensor simReadForceSensor=nullptr;
ptrSimSetLightParameters simSetLightParameters=nullptr;
ptrSimGetLightParameters simGetLightParameters=nullptr;
ptrSimGetVelocity simGetVelocity=nullptr;
ptrSimGetObjectVelocity simGetObjectVelocity=nullptr;
ptrSimGetJointVelocity simGetJointVelocity=nullptr;
ptrSimAddForceAndTorque simAddForceAndTorque=nullptr;
ptrSimAddForce simAddForce=nullptr;
ptrSimSetExplicitHandling simSetExplicitHandling=nullptr;
ptrSimGetExplicitHandling simGetExplicitHandling=nullptr;
ptrSimGetLinkDummy simGetLinkDummy=nullptr;
ptrSimSetLinkDummy simSetLinkDummy=nullptr;
ptrSimSetModelProperty simSetModelProperty=nullptr;
ptrSimGetModelProperty simGetModelProperty=nullptr;
ptrSimSetObjectColor simSetObjectColor=nullptr;
ptrSimGetObjectColor simGetObjectColor=nullptr;
ptrSimSetShapeColor simSetShapeColor=nullptr;
ptrSimGetShapeColor simGetShapeColor=nullptr;
ptrSimResetDynamicObject simResetDynamicObject=nullptr;
ptrSimSetJointMode simSetJointMode=nullptr;
ptrSimGetJointMode simGetJointMode=nullptr;
ptrSimSerialOpen simSerialOpen=nullptr;
ptrSimSerialClose simSerialClose=nullptr;
ptrSimSerialSend simSerialSend=nullptr;
ptrSimSerialRead simSerialRead=nullptr;
ptrSimSerialCheck simSerialCheck=nullptr;
ptrSimGetContactInfo simGetContactInfo=nullptr;
ptrSimAuxiliaryConsoleOpen simAuxiliaryConsoleOpen=nullptr;
ptrSimAuxiliaryConsoleClose simAuxiliaryConsoleClose=nullptr;
ptrSimAuxiliaryConsoleShow simAuxiliaryConsoleShow=nullptr;
ptrSimAuxiliaryConsolePrint simAuxiliaryConsolePrint=nullptr;
ptrSimImportShape simImportShape=nullptr;
ptrSimImportMesh simImportMesh=nullptr;
ptrSimExportMesh simExportMesh=nullptr;
ptrSimCreateShape simCreateShape=nullptr;
ptrSimCreateMeshShape simCreateMeshShape=nullptr;
ptrSimCreatePrimitiveShape simCreatePrimitiveShape=nullptr;
ptrSimCreateHeightfieldShape simCreateHeightfieldShape=nullptr;
ptrSimGetShapeMesh simGetShapeMesh=nullptr;
ptrSimCreateJoint simCreateJoint=nullptr;
ptrSimCreateDummy simCreateDummy=nullptr;
ptrSimCreateProximitySensor simCreateProximitySensor=nullptr;
ptrSimCreateForceSensor simCreateForceSensor=nullptr;
ptrSimCreateVisionSensor simCreateVisionSensor=nullptr;
ptrSimGetObjectInt32Param simGetObjectInt32Param=nullptr;
ptrSimSetObjectInt32Param simSetObjectInt32Param=nullptr;
ptrSimGetObjectFloatParam simGetObjectFloatParam=nullptr;
ptrSimSetObjectFloatParam simSetObjectFloatParam=nullptr;
ptrSimGetObjectFloatArrayParam simGetObjectFloatArrayParam=nullptr;
ptrSimSetObjectFloatArrayParam simSetObjectFloatArrayParam=nullptr;
ptrSimGetObjectStringParam simGetObjectStringParam=nullptr;
ptrSimSetObjectStringParam simSetObjectStringParam=nullptr;
ptrSimGetScriptInt32Param simGetScriptInt32Param=nullptr;
ptrSimSetScriptInt32Param simSetScriptInt32Param=nullptr;
ptrSimGetScriptStringParam simGetScriptStringParam=nullptr;
ptrSimSetScriptStringParam simSetScriptStringParam=nullptr;
ptrSimSetSimulationPassesPerRenderingPass simSetSimulationPassesPerRenderingPass=nullptr;
ptrSimGetRotationAxis simGetRotationAxis=nullptr;
ptrSimRotateAroundAxis simRotateAroundAxis=nullptr;
ptrSimGetJointForce simGetJointForce=nullptr;
ptrSimGetJointTargetForce simGetJointTargetForce=nullptr;
ptrSimSetJointTargetForce simSetJointTargetForce=nullptr;
ptrSimCameraFitToView simCameraFitToView=nullptr;
ptrSimPersistentDataWrite simPersistentDataWrite=nullptr;
ptrSimPersistentDataRead simPersistentDataRead=nullptr;
ptrSimIsHandle simIsHandle=nullptr;
ptrSimHandleVisionSensor simHandleVisionSensor=nullptr;
ptrSimReadVisionSensor simReadVisionSensor=nullptr;
ptrSimResetVisionSensor simResetVisionSensor=nullptr;
ptrSimCheckVisionSensor simCheckVisionSensor=nullptr;
ptrSimCheckVisionSensorEx simCheckVisionSensorEx=nullptr;
ptrSimGetVisionSensorImg simGetVisionSensorImg=nullptr;
ptrSimSetVisionSensorImg simSetVisionSensorImg=nullptr;
ptrSimGetVisionSensorDepth simGetVisionSensorDepth=nullptr;
ptrSimGetVisionSensorRes simGetVisionSensorRes=nullptr;
ptr_simSetVisionSensorDepth _simSetVisionSensorDepth=nullptr;
ptrSimGetObjectQuaternion simGetObjectQuaternion=nullptr;
ptrSimSetObjectQuaternion simSetObjectQuaternion=nullptr;
ptrSimRuckigPos simRuckigPos=nullptr;
ptrSimRuckigVel simRuckigVel=nullptr;
ptrSimRuckigStep simRuckigStep=nullptr;
ptrSimRuckigRemove simRuckigRemove=nullptr;
ptrSimGroupShapes simGroupShapes=nullptr;
ptrSimUngroupShape simUngroupShape=nullptr;
ptrSimConvexDecompose simConvexDecompose=nullptr;
ptrSimQuitSimulator simQuitSimulator=nullptr;
ptrSimSetShapeMaterial simSetShapeMaterial=nullptr;
ptrSimGetTextureId simGetTextureId=nullptr;
ptrSimReadTexture simReadTexture=nullptr;
ptrSimWriteTexture simWriteTexture=nullptr;
ptrSimCreateTexture simCreateTexture=nullptr;
ptrSimWriteCustomDataBlock simWriteCustomDataBlock=nullptr;
ptrSimReadCustomDataBlock simReadCustomDataBlock=nullptr;
ptrSimReadCustomDataBlockTags simReadCustomDataBlockTags=nullptr;
ptrSimGetShapeGeomInfo simGetShapeGeomInfo=nullptr;
ptrSimGetObjects simGetObjects=nullptr;
ptrSimGetObjectsInTree simGetObjectsInTree=nullptr;
ptrSimScaleObject simScaleObject=nullptr;
ptrSimSetShapeTexture simSetShapeTexture=nullptr;
ptrSimGetShapeTextureId simGetShapeTextureId=nullptr;
ptrSimCreateCollectionEx simCreateCollectionEx=nullptr;
ptrSimAddItemToCollection simAddItemToCollection=nullptr;
ptrSimDestroyCollection simDestroyCollection=nullptr;
ptrSimGetCollectionObjects simGetCollectionObjects=nullptr;
ptrSimAlignShapeBB simAlignShapeBB=nullptr;
ptrSimRelocateShapeFrame simRelocateShapeFrame=nullptr;

ptrSimSaveImage simSaveImage=nullptr;
ptrSimLoadImage simLoadImage=nullptr;
ptrSimGetScaledImage simGetScaledImage=nullptr;
ptrSimTransformImage simTransformImage=nullptr;
ptrSimGetQHull simGetQHull=nullptr;
ptrSimGetDecimatedMesh simGetDecimatedMesh=nullptr;
ptrSimCallScriptFunctionEx simCallScriptFunctionEx=nullptr;
ptrSimGetExtensionString simGetExtensionString=nullptr;
ptrSimComputeMassAndInertia simComputeMassAndInertia=nullptr;
ptrSimCreateStack simCreateStack=nullptr;
ptrSimReleaseStack simReleaseStack=nullptr;
ptrSimCopyStack simCopyStack=nullptr;
ptrSimPushNullOntoStack simPushNullOntoStack=nullptr;
ptrSimPushBoolOntoStack simPushBoolOntoStack=nullptr;
ptrSimPushInt32OntoStack simPushInt32OntoStack=nullptr;
ptrSimPushInt64OntoStack simPushInt64OntoStack=nullptr;
ptrSimPushFloatOntoStack simPushFloatOntoStack=nullptr;
ptrSimPushDoubleOntoStack simPushDoubleOntoStack=nullptr;
ptrSimPushStringOntoStack simPushStringOntoStack=nullptr;
ptrSimPushUInt8TableOntoStack simPushUInt8TableOntoStack=nullptr;
ptrSimPushInt32TableOntoStack simPushInt32TableOntoStack=nullptr;
ptrSimPushInt64TableOntoStack simPushInt64TableOntoStack=nullptr;
ptrSimPushFloatTableOntoStack simPushFloatTableOntoStack=nullptr;
ptrSimPushDoubleTableOntoStack simPushDoubleTableOntoStack=nullptr;
ptrSimPushTableOntoStack simPushTableOntoStack=nullptr;
ptrSimInsertDataIntoStackTable simInsertDataIntoStackTable=nullptr;
ptrSimGetStackSize simGetStackSize=nullptr;
ptrSimPopStackItem simPopStackItem=nullptr;
ptrSimMoveStackItemToTop simMoveStackItemToTop=nullptr;
ptrSimIsStackValueNull simIsStackValueNull=nullptr;
ptrSimGetStackBoolValue simGetStackBoolValue=nullptr;
ptrSimGetStackInt32Value simGetStackInt32Value=nullptr;
ptrSimGetStackInt64Value simGetStackInt64Value=nullptr;
ptrSimGetStackFloatValue simGetStackFloatValue=nullptr;
ptrSimGetStackDoubleValue simGetStackDoubleValue=nullptr;
ptrSimGetStackStringValue simGetStackStringValue=nullptr;
ptrSimGetStackTableInfo simGetStackTableInfo=nullptr;
ptrSimGetStackUInt8Table simGetStackUInt8Table=nullptr;
ptrSimGetStackInt32Table simGetStackInt32Table=nullptr;
ptrSimGetStackInt64Table simGetStackInt64Table=nullptr;
ptrSimGetStackFloatTable simGetStackFloatTable=nullptr;
ptrSimGetStackDoubleTable simGetStackDoubleTable=nullptr;
ptrSimUnfoldStackTable simUnfoldStackTable=nullptr;
ptrSimDebugStack simDebugStack=nullptr;
ptrSimGetEngineFloatParam simGetEngineFloatParam=nullptr;
ptrSimGetEngineInt32Param simGetEngineInt32Param=nullptr;
ptrSimGetEngineBoolParam simGetEngineBoolParam=nullptr;
ptrSimSetEngineFloatParam simSetEngineFloatParam=nullptr;
ptrSimSetEngineInt32Param simSetEngineInt32Param=nullptr;
ptrSimSetEngineBoolParam simSetEngineBoolParam=nullptr;
ptrSimCreateOctree simCreateOctree=nullptr;
ptrSimCreatePointCloud simCreatePointCloud=nullptr;
ptrSimSetPointCloudOptions simSetPointCloudOptions=nullptr;
ptrSimGetPointCloudOptions simGetPointCloudOptions=nullptr;
ptrSimInsertVoxelsIntoOctree simInsertVoxelsIntoOctree=nullptr;
ptrSimRemoveVoxelsFromOctree simRemoveVoxelsFromOctree=nullptr;
ptrSimInsertPointsIntoPointCloud simInsertPointsIntoPointCloud=nullptr;
ptrSimRemovePointsFromPointCloud simRemovePointsFromPointCloud=nullptr;
ptrSimIntersectPointsWithPointCloud simIntersectPointsWithPointCloud=nullptr;
ptrSimGetOctreeVoxels simGetOctreeVoxels=nullptr;
ptrSimGetPointCloudPoints simGetPointCloudPoints=nullptr;
ptrSimInsertObjectIntoOctree simInsertObjectIntoOctree=nullptr;
ptrSimSubtractObjectFromOctree simSubtractObjectFromOctree=nullptr;
ptrSimInsertObjectIntoPointCloud simInsertObjectIntoPointCloud=nullptr;
ptrSimSubtractObjectFromPointCloud simSubtractObjectFromPointCloud=nullptr;
ptrSimCheckOctreePointOccupancy simCheckOctreePointOccupancy=nullptr;
ptrSimOpenTextEditor simOpenTextEditor=nullptr;
ptrSimPackTable simPackTable=nullptr;
ptrSimUnpackTable simUnpackTable=nullptr;
ptrSimSetReferencedHandles simSetReferencedHandles=nullptr;
ptrSimGetReferencedHandles simGetReferencedHandles=nullptr;
ptrSimGetShapeViz simGetShapeViz=nullptr;
ptrSimExecuteScriptString simExecuteScriptString=nullptr;
ptrSimGetApiFunc simGetApiFunc=nullptr;
ptrSimGetApiInfo simGetApiInfo=nullptr;
ptrSimSetModuleInfo simSetModuleInfo=nullptr;
ptrSimGetModuleInfo simGetModuleInfo=nullptr;
ptrSimIsDeprecated simIsDeprecated=nullptr;
ptrSimGetPersistentDataTags simGetPersistentDataTags=nullptr;
ptrSimEventNotification simEventNotification=nullptr;
ptrSimApplyTexture simApplyTexture=nullptr;
ptrSimSetJointDependency simSetJointDependency=nullptr;
ptrSimGetJointDependency simGetJointDependency=nullptr;
ptrSimGetShapeMass simGetShapeMass=nullptr;
ptrSimSetShapeMass simSetShapeMass=nullptr;
ptrSimGetShapeInertia simGetShapeInertia=nullptr;
ptrSimSetShapeInertia simSetShapeInertia=nullptr;
ptrSimIsDynamicallyEnabled simIsDynamicallyEnabled=nullptr;
ptrSimGenerateShapeFromPath simGenerateShapeFromPath=nullptr;
ptrSimGetClosestPosOnPath simGetClosestPosOnPath=nullptr;
ptrSimInitScript simInitScript=nullptr;
ptrSimModuleEntry simModuleEntry=nullptr;
ptrSimCheckExecAuthorization simCheckExecAuthorization=nullptr;
ptrSimExtCallScriptFunction simExtCallScriptFunction=nullptr;

// Following courtesy of Stephen James:
ptrSimExtLaunchUIThread simExtLaunchUIThread=nullptr;
ptrSimExtCanInitSimThread simExtCanInitSimThread=nullptr;
ptrSimExtSimThreadInit simExtSimThreadInit=nullptr;
ptrSimExtSimThreadDestroy simExtSimThreadDestroy=nullptr;
ptrSimExtPostExitRequest simExtPostExitRequest=nullptr;
ptrSimExtGetExitRequest simExtGetExitRequest=nullptr;
ptrSimExtStep simExtStep=nullptr;

ptr_simSetDynamicSimulationIconCode _simSetDynamicSimulationIconCode=nullptr;
ptr_simSetDynamicObjectFlagForVisualization _simSetDynamicObjectFlagForVisualization=nullptr;
ptr_simGetObjectListSize _simGetObjectListSize=nullptr;
ptr_simGetObjectFromIndex _simGetObjectFromIndex=nullptr;
ptr_simGetObjectID _simGetObjectID=nullptr;
ptr_simGetObjectType _simGetObjectType=nullptr;
ptr_simGetObjectChildren _simGetObjectChildren=nullptr;
ptr_simGetParentObject _simGetParentObject=nullptr;
ptr_simGetObject _simGetObject=nullptr;
ptr_simGetIkGroupObject _simGetIkGroupObject=nullptr;
ptr_simMpHandleIkGroupObject _simMpHandleIkGroupObject=nullptr;
ptr_simGetObjectLocalTransformation _simGetObjectLocalTransformation=nullptr;
ptr_simSetObjectLocalTransformation _simSetObjectLocalTransformation=nullptr;
ptr_simDynReportObjectCumulativeTransformation _simDynReportObjectCumulativeTransformation=nullptr;
ptr_simSetObjectCumulativeTransformation _simSetObjectCumulativeTransformation=nullptr;
ptr_simGetObjectCumulativeTransformation _simGetObjectCumulativeTransformation=nullptr;
ptr_simIsShapeDynamicallyStatic _simIsShapeDynamicallyStatic=nullptr;
ptr_simGetTreeDynamicProperty _simGetTreeDynamicProperty=nullptr;
ptr_simGetDummyLinkType _simGetDummyLinkType=nullptr;
ptr_simGetJointMode _simGetJointMode=nullptr;
ptr_simIsJointInHybridOperation _simIsJointInHybridOperation=nullptr;
ptr_simDisableDynamicTreeForManipulation _simDisableDynamicTreeForManipulation=nullptr;
ptr_simIsShapeDynamicallyRespondable _simIsShapeDynamicallyRespondable=nullptr;
ptr_simGetDynamicCollisionMask _simGetDynamicCollisionMask=nullptr;
ptr_simGetLastParentForLocalGlobalCollidable _simGetLastParentForLocalGlobalCollidable=nullptr;
ptr_simSetJointVelocity _simSetJointVelocity=nullptr;
ptr_simSetJointPosition _simSetJointPosition=nullptr;
ptr_simGetJointPosition _simGetJointPosition=nullptr;
ptr_simSetDynamicMotorPositionControlTargetPosition _simSetDynamicMotorPositionControlTargetPosition=nullptr;
ptr_simGetInitialDynamicVelocity _simGetInitialDynamicVelocity=nullptr;
ptr_simSetInitialDynamicVelocity _simSetInitialDynamicVelocity=nullptr;
ptr_simGetInitialDynamicAngVelocity _simGetInitialDynamicAngVelocity=nullptr;
ptr_simSetInitialDynamicAngVelocity _simSetInitialDynamicAngVelocity=nullptr;
ptr_simGetStartSleeping _simGetStartSleeping=nullptr;
ptr_simGetWasPutToSleepOnce _simGetWasPutToSleepOnce=nullptr;
ptr_simGetDynamicsFullRefreshFlag _simGetDynamicsFullRefreshFlag=nullptr;
ptr_simSetDynamicsFullRefreshFlag _simSetDynamicsFullRefreshFlag=nullptr;
ptr_simSetShapeDynamicVelocity _simSetShapeDynamicVelocity=nullptr;
ptr_simGetAdditionalForceAndTorque _simGetAdditionalForceAndTorque=nullptr;
ptr_simClearAdditionalForceAndTorque _simClearAdditionalForceAndTorque=nullptr;
ptr_simGetJointPositionInterval _simGetJointPositionInterval=nullptr;
ptr_simGetJointType _simGetJointType=nullptr;
ptr_simGetDynamicMotorTargetPosition _simGetDynamicMotorTargetPosition=nullptr;
ptr_simGetDynamicMotorTargetVelocity _simGetDynamicMotorTargetVelocity=nullptr;
ptr_simGetDynamicMotorMaxForce _simGetDynamicMotorMaxForce=nullptr;
ptr_simGetDynamicMotorUpperLimitVelocity _simGetDynamicMotorUpperLimitVelocity=nullptr;
ptr_simSetDynamicMotorReflectedPositionFromDynamicEngine _simSetDynamicMotorReflectedPositionFromDynamicEngine=nullptr;
ptr_simSetJointSphericalTransformation _simSetJointSphericalTransformation=nullptr;
ptr_simAddForceSensorCumulativeForcesAndTorques _simAddForceSensorCumulativeForcesAndTorques=nullptr;
ptr_simAddJointCumulativeForcesOrTorques _simAddJointCumulativeForcesOrTorques=nullptr;
ptr_simGetGeomWrapFromGeomProxy _simGetGeomWrapFromGeomProxy=nullptr;
ptr_simGetMass _simGetMass=nullptr;
ptr_simGetLocalInertiaInfo _simGetLocalInertiaInfo=nullptr;
ptr_simGetPurePrimitiveType _simGetPurePrimitiveType=nullptr;
ptr_simIsGeomWrapGeometric _simIsGeomWrapGeometric=nullptr;
ptr_simIsGeomWrapConvex _simIsGeomWrapConvex=nullptr;
ptr_simGetGeometricCount _simGetGeometricCount=nullptr;
ptr_simGetAllGeometrics _simGetAllGeometrics=nullptr;
ptr_simGetPurePrimitiveSizes _simGetPurePrimitiveSizes=nullptr;
ptr_simMakeDynamicAnnouncement _simMakeDynamicAnnouncement=nullptr;
ptr_simGetVerticesLocalFrame _simGetVerticesLocalFrame=nullptr;
ptr_simGetHeightfieldData _simGetHeightfieldData=nullptr;
ptr_simGetCumulativeMeshes _simGetCumulativeMeshes=nullptr;
ptr_simGetGravity _simGetGravity=nullptr;
ptr_simGetTimeDiffInMs _simGetTimeDiffInMs=nullptr;
ptr_simDoEntitiesCollide _simDoEntitiesCollide=nullptr;
ptr_simGetDistanceBetweenEntitiesIfSmaller _simGetDistanceBetweenEntitiesIfSmaller=nullptr;
ptr_simHandleJointControl _simHandleJointControl=nullptr;
ptr_simHandleCustomContact _simHandleCustomContact=nullptr;
ptr_simGetPureHollowScaling _simGetPureHollowScaling=nullptr;
ptr_simGetJointDynCtrlMode _simGetJointDynCtrlMode=nullptr;
ptr_simDynCallback _simDynCallback=nullptr;

LIBRARY loadSimLibrary(const char* pathAndFilename)
{
    #ifdef QT_FRAMEWORK
        QLibrary* lib=new QLibrary(pathAndFilename);
        if (!lib->load())
        {
            qCritical() << "error: library (" << pathAndFilename << ") load:" << lib->errorString();
            delete lib;
            lib=nullptr;
        }
        return lib;
    #else
        #ifdef _WIN32
            return LoadLibraryA(pathAndFilename);
        #elif defined (__linux) || defined (__APPLE__)
            auto lib = dlopen(pathAndFilename,RTLD_LAZY);
            if (!lib)
            {
                auto err = dlerror();
                if (err)
                    fprintf(stderr, "error: dlopen(%s): %s\n", pathAndFilename, err);
            }
            return lib;
        #endif
    #endif // QT_FRAMEWORK
}

void unloadSimLibrary(LIBRARY lib)
{
    #ifdef QT_FRAMEWORK
        if (lib!=0)
        {
            if (!lib->unload())
                qCritical() << "error: library unload:" << lib->errorString();
            delete lib;
        }
    #else
        #ifdef _WIN32
            if (lib!=0)
                FreeLibrary(lib);
        #elif defined (__linux) || defined (__APPLE__)
            if (dlclose(lib) != 0)
            {
                auto err = dlerror();
                if (err)
                    fprintf(stderr, "error: dlclose: %s\n", err);
            }
        #endif
    #endif // QT_FRAMEWORK
}

FARPROC _getProcAddress(LIBRARY lib,const char* funcName,bool hasSingleAndDoublePrecisionFunc)
{
    FARPROC retVal=nullptr;
    std::string fn(funcName);
#ifndef SIM_INTERFACE_SINGLE
    if (hasSingleAndDoublePrecisionFunc)
        fn+="_D";
#endif
#ifdef QT_FRAMEWORK
    retVal=(void*)lib->resolve(fn.c_str());
#else
#ifdef _WIN32
    retVal=GetProcAddress(lib,fn.c_str());
#elif defined (__linux) || defined (__APPLE__)
    retVal=dlsym(lib,fn.c_str());
#endif
#endif
    return(retVal);
}

#include "simLib-old.cpp"

int getSimProcAddresses(LIBRARY lib)
{
    if (getSimProcAddressesOld(lib)==0)
        return(0);

    _addLog=(ptrSimAddLog)(_getProcAddress(lib,"simAddLog",false));
    simRunSimulator=(ptrSimRunSimulator)(_getProcAddress(lib,"simRunSimulator",false));
    simRunSimulatorEx=(ptrSimRunSimulatorEx)(_getProcAddress(lib,"simRunSimulatorEx",false));
    simGetSimulatorMessage=(ptrSimGetSimulatorMessage)(_getProcAddress(lib,"simGetSimulatorMessage",false));
    simGetMainWindow=(ptrSimGetMainWindow)(_getProcAddress(lib,"simGetMainWindow",false));
    simGetLastError=(ptrSimGetLastError)(_getProcAddress(lib,"simGetLastError",false));
    simLoadModule=(ptrSimLoadModule)(_getProcAddress(lib,"simLoadModule",false));
    simUnloadModule=(ptrSimUnloadModule)(_getProcAddress(lib,"simUnloadModule",false));
    simSetBoolParam=(ptrSimSetBoolParam)(_getProcAddress(lib,"simSetBoolParam",false));
    simGetBoolParam=(ptrSimGetBoolParam)(_getProcAddress(lib,"simGetBoolParam",false));
    simSetInt32Param=(ptrSimSetInt32Param)(_getProcAddress(lib,"simSetInt32Param",false));
    simGetInt32Param=(ptrSimGetInt32Param)(_getProcAddress(lib,"simGetInt32Param",false));
    simGetUInt64Param=(ptrSimGetUInt64Param)(_getProcAddress(lib,"simGetUInt64Param",false));
    simSetStringParam=(ptrSimSetStringParam)(_getProcAddress(lib,"simSetStringParam",false));
    simGetStringParam=(ptrSimGetStringParam)(_getProcAddress(lib,"simGetStringParam",false));
    simSetArrayParam=(ptrSimSetArrayParam)(_getProcAddress(lib,"simSetArrayParam",true));
    simGetArrayParam=(ptrSimGetArrayParam)(_getProcAddress(lib,"simGetArrayParam",true));
    simSetNamedStringParam=(ptrSimSetNamedStringParam)(_getProcAddress(lib,"simSetNamedStringParam",false));
    simGetNamedStringParam=(ptrSimGetNamedStringParam)(_getProcAddress(lib,"simGetNamedStringParam",false));
    simGetObject=(ptrSimGetObject)(_getProcAddress(lib,"simGetObject",false));
    simGetObjectUid=(ptrSimGetObjectUid)(_getProcAddress(lib,"simGetObjectUid",false));
    simGetObjectFromUid=(ptrSimGetObjectFromUid)(_getProcAddress(lib,"simGetObjectFromUid",false));
    simGetScriptHandleEx=(ptrSimGetScriptHandleEx)(_getProcAddress(lib,"simGetScriptHandleEx",false));
    simRemoveObjects=(ptrSimRemoveObjects)(_getProcAddress(lib,"simRemoveObjects",false));
    simRemoveModel=(ptrSimRemoveModel)(_getProcAddress(lib,"simRemoveModel",false));
    simGetObjectAlias=(ptrSimGetObjectAlias)(_getProcAddress(lib,"simGetObjectAlias",false));
    simSetObjectAlias=(ptrSimSetObjectAlias)(_getProcAddress(lib,"simSetObjectAlias",false));
    simGetObjectParent=(ptrSimGetObjectParent)(_getProcAddress(lib,"simGetObjectParent",false));
    simGetObjectChild=(ptrSimGetObjectChild)(_getProcAddress(lib,"simGetObjectChild",false));
    simSetObjectParent=(ptrSimSetObjectParent)(_getProcAddress(lib,"simSetObjectParent",false));
    simGetObjectType=(ptrSimGetObjectType)(_getProcAddress(lib,"simGetObjectType",false));
    simGetJointType=(ptrSimGetJointType)(_getProcAddress(lib,"simGetJointType",false));
    simReservedCommand=(ptrSimReservedCommand)(_getProcAddress(lib,"simReservedCommand",false));
    simGetSimulationState=(ptrSimGetSimulationState)(_getProcAddress(lib,"simGetSimulationState",false));
    simLoadScene=(ptrSimLoadScene)(_getProcAddress(lib,"simLoadScene",false));
    simCloseScene=(ptrSimCloseScene)(_getProcAddress(lib,"simCloseScene",false));
    simSaveScene=(ptrSimSaveScene)(_getProcAddress(lib,"simSaveScene",false));
    simLoadModel=(ptrSimLoadModel)(_getProcAddress(lib,"simLoadModel",false));
    simSaveModel=(ptrSimSaveModel)(_getProcAddress(lib,"simSaveModel",false));
    simDoesFileExist=(ptrSimDoesFileExist)(_getProcAddress(lib,"simDoesFileExist",false));
    simGetObjectSel=(ptrSimGetObjectSel)(_getProcAddress(lib,"simGetObjectSel",false));
    simSetObjectSel=(ptrSimSetObjectSel)(_getProcAddress(lib,"simSetObjectSel",false));
    simAssociateScriptWithObject=(ptrSimAssociateScriptWithObject)(_getProcAddress(lib,"simAssociateScriptWithObject",false));
    simHandleMainScript=(ptrSimHandleMainScript)(_getProcAddress(lib,"simHandleMainScript",false));
    simResetScript=(ptrSimResetScript)(_getProcAddress(lib,"simResetScript",false));
    simAddScript=(ptrSimAddScript)(_getProcAddress(lib,"simAddScript",false));
    simRemoveScript=(ptrSimRemoveScript)(_getProcAddress(lib,"simRemoveScript",false));
    simRefreshDialogs=(ptrSimRefreshDialogs)(_getProcAddress(lib,"simRefreshDialogs",false));
    simResetProximitySensor=(ptrSimResetProximitySensor)(_getProcAddress(lib,"simResetProximitySensor",false));
    simCreateBuffer=(ptrSimCreateBuffer)(_getProcAddress(lib,"simCreateBuffer",false));
    simReleaseBuffer=(ptrSimReleaseBuffer)(_getProcAddress(lib,"simReleaseBuffer",false));
    simCheckCollision=(ptrSimCheckCollision)(_getProcAddress(lib,"simCheckCollision",false));
    simGetRealTimeSimulation=(ptrSimGetRealTimeSimulation)(_getProcAddress(lib,"simGetRealTimeSimulation",false));
    simIsRealTimeSimulationStepNeeded=(ptrSimIsRealTimeSimulationStepNeeded)(_getProcAddress(lib,"simIsRealTimeSimulationStepNeeded",false));
    simGetSimulationPassesPerRenderingPass=(ptrSimGetSimulationPassesPerRenderingPass)(_getProcAddress(lib,"simGetSimulationPassesPerRenderingPass",false));
    simAdvanceSimulationByOneStep=(ptrSimAdvanceSimulationByOneStep)(_getProcAddress(lib,"simAdvanceSimulationByOneStep",false));
    simStartSimulation=(ptrSimStartSimulation)(_getProcAddress(lib,"simStartSimulation",false));
    simStopSimulation=(ptrSimStopSimulation)(_getProcAddress(lib,"simStopSimulation",false));
    simPauseSimulation=(ptrSimPauseSimulation)(_getProcAddress(lib,"simPauseSimulation",false));
    simGetModuleName=(ptrSimGetModuleName)(_getProcAddress(lib,"simGetModuleName",false));
    simAdjustView=(ptrSimAdjustView)(_getProcAddress(lib,"simAdjustView",false));
    simSetLastError=(ptrSimSetLastError)(_getProcAddress(lib,"simSetLastError",false));
    simResetGraph=(ptrSimResetGraph)(_getProcAddress(lib,"simResetGraph",false));
    simDestroyGraphCurve=(ptrSimDestroyGraphCurve)(_getProcAddress(lib,"simDestroyGraphCurve",false));
    simDuplicateGraphCurveToStatic=(ptrSimDuplicateGraphCurveToStatic)(_getProcAddress(lib,"simDuplicateGraphCurveToStatic",false));
    simSetNavigationMode=(ptrSimSetNavigationMode)(_getProcAddress(lib,"simSetNavigationMode",false));
    simGetNavigationMode=(ptrSimGetNavigationMode)(_getProcAddress(lib,"simGetNavigationMode",false));
    simSetPage=(ptrSimSetPage)(_getProcAddress(lib,"simSetPage",false));
    simGetPage=(ptrSimGetPage)(_getProcAddress(lib,"simGetPage",false));
    simRegisterScriptCallbackFunction=(ptrSimRegisterScriptCallbackFunction)(_getProcAddress(lib,"simRegisterScriptCallbackFunction",false));
    simRegisterScriptVariable=(ptrSimRegisterScriptVariable)(_getProcAddress(lib,"simRegisterScriptVariable",false));
    simRegisterScriptFuncHook=(ptrSimRegisterScriptFuncHook)(_getProcAddress(lib,"simRegisterScriptFuncHook",false));
    simCopyPasteObjects=(ptrSimCopyPasteObjects)(_getProcAddress(lib,"simCopyPasteObjects",false));
    simRemoveDrawingObject=(ptrSimRemoveDrawingObject)(_getProcAddress(lib,"simRemoveDrawingObject",false));
    simAnnounceSceneContentChange=(ptrSimAnnounceSceneContentChange)(_getProcAddress(lib,"simAnnounceSceneContentChange",false));
    simSetInt32Signal=(ptrSimSetInt32Signal)(_getProcAddress(lib,"simSetInt32Signal",false));
    simGetInt32Signal=(ptrSimGetInt32Signal)(_getProcAddress(lib,"simGetInt32Signal",false));
    simClearInt32Signal=(ptrSimClearInt32Signal)(_getProcAddress(lib,"simClearInt32Signal",false));
    simClearFloatSignal=(ptrSimClearFloatSignal)(_getProcAddress(lib,"simClearFloatSignal",false));
    simSetStringSignal=(ptrSimSetStringSignal)(_getProcAddress(lib,"simSetStringSignal",false));
    simGetStringSignal=(ptrSimGetStringSignal)(_getProcAddress(lib,"simGetStringSignal",false));
    simClearStringSignal=(ptrSimClearStringSignal)(_getProcAddress(lib,"simClearStringSignal",false));
    simGetSignalName=(ptrSimGetSignalName)(_getProcAddress(lib,"simGetSignalName",false));
    simSetObjectProperty=(ptrSimSetObjectProperty)(_getProcAddress(lib,"simSetObjectProperty",false));
    simGetObjectProperty=(ptrSimGetObjectProperty)(_getProcAddress(lib,"simGetObjectProperty",false));
    simSetObjectSpecialProperty=(ptrSimSetObjectSpecialProperty)(_getProcAddress(lib,"simSetObjectSpecialProperty",false));
    simGetObjectSpecialProperty=(ptrSimGetObjectSpecialProperty)(_getProcAddress(lib,"simGetObjectSpecialProperty",false));
    simSetExplicitHandling=(ptrSimSetExplicitHandling)(_getProcAddress(lib,"simSetExplicitHandling",false));
    simGetExplicitHandling=(ptrSimGetExplicitHandling)(_getProcAddress(lib,"simGetExplicitHandling",false));
    simGetLinkDummy=(ptrSimGetLinkDummy)(_getProcAddress(lib,"simGetLinkDummy",false));
    simSetLinkDummy=(ptrSimSetLinkDummy)(_getProcAddress(lib,"simSetLinkDummy",false));
    simSetModelProperty=(ptrSimSetModelProperty)(_getProcAddress(lib,"simSetModelProperty",false));
    simGetModelProperty=(ptrSimGetModelProperty)(_getProcAddress(lib,"simGetModelProperty",false));
    simResetDynamicObject=(ptrSimResetDynamicObject)(_getProcAddress(lib,"simResetDynamicObject",false));
    simSetJointMode=(ptrSimSetJointMode)(_getProcAddress(lib,"simSetJointMode",false));
    simGetJointMode=(ptrSimGetJointMode)(_getProcAddress(lib,"simGetJointMode",false));
    simSerialOpen=(ptrSimSerialOpen)(_getProcAddress(lib,"simSerialOpen",false));
    simSerialClose=(ptrSimSerialClose)(_getProcAddress(lib,"simSerialClose",false));
    simSerialSend=(ptrSimSerialSend)(_getProcAddress(lib,"simSerialSend",false));
    simSerialRead=(ptrSimSerialRead)(_getProcAddress(lib,"simSerialRead",false));
    simSerialCheck=(ptrSimSerialCheck)(_getProcAddress(lib,"simSerialCheck",false));
    simAuxiliaryConsoleClose=(ptrSimAuxiliaryConsoleClose)(_getProcAddress(lib,"simAuxiliaryConsoleClose",false));
    simAuxiliaryConsoleShow=(ptrSimAuxiliaryConsoleShow)(_getProcAddress(lib,"simAuxiliaryConsoleShow",false));
    simAuxiliaryConsolePrint=(ptrSimAuxiliaryConsolePrint)(_getProcAddress(lib,"simAuxiliaryConsolePrint",false));
    simGetObjectInt32Param=(ptrSimGetObjectInt32Param)(_getProcAddress(lib,"simGetObjectInt32Param",false));
    simSetObjectInt32Param=(ptrSimSetObjectInt32Param)(_getProcAddress(lib,"simSetObjectInt32Param",false));
    simGetObjectStringParam=(ptrSimGetObjectStringParam)(_getProcAddress(lib,"simGetObjectStringParam",false));
    simSetObjectStringParam=(ptrSimSetObjectStringParam)(_getProcAddress(lib,"simSetObjectStringParam",false));
    simGetScriptInt32Param=(ptrSimGetScriptInt32Param)(_getProcAddress(lib,"simGetScriptInt32Param",false));
    simSetScriptInt32Param=(ptrSimSetScriptInt32Param)(_getProcAddress(lib,"simSetScriptInt32Param",false));
    simGetScriptStringParam=(ptrSimGetScriptStringParam)(_getProcAddress(lib,"simGetScriptStringParam",false));
    simSetScriptStringParam=(ptrSimSetScriptStringParam)(_getProcAddress(lib,"simSetScriptStringParam",false));
    simSetSimulationPassesPerRenderingPass=(ptrSimSetSimulationPassesPerRenderingPass)(_getProcAddress(lib,"simSetSimulationPassesPerRenderingPass",false));
    simPersistentDataWrite=(ptrSimPersistentDataWrite)(_getProcAddress(lib,"simPersistentDataWrite",false));
    simPersistentDataRead=(ptrSimPersistentDataRead)(_getProcAddress(lib,"simPersistentDataRead",false));
    simIsHandle=(ptrSimIsHandle)(_getProcAddress(lib,"simIsHandle",false));
    simResetVisionSensor=(ptrSimResetVisionSensor)(_getProcAddress(lib,"simResetVisionSensor",false));
    simSetVisionSensorImg=(ptrSimSetVisionSensorImg)(_getProcAddress(lib,"simSetVisionSensorImg",false));
    simRuckigPos=(ptrSimRuckigPos)(_getProcAddress(lib,"simRuckigPos",false));
    simRuckigVel=(ptrSimRuckigVel)(_getProcAddress(lib,"simRuckigVel",false));
    simRuckigStep=(ptrSimRuckigStep)(_getProcAddress(lib,"simRuckigStep",false));
    simRuckigRemove=(ptrSimRuckigRemove)(_getProcAddress(lib,"simRuckigRemove",false));
    simGroupShapes=(ptrSimGroupShapes)(_getProcAddress(lib,"simGroupShapes",false));
    simUngroupShape=(ptrSimUngroupShape)(_getProcAddress(lib,"simUngroupShape",false));
    simQuitSimulator=(ptrSimQuitSimulator)(_getProcAddress(lib,"simQuitSimulator",false));
    simSetShapeMaterial=(ptrSimSetShapeMaterial)(_getProcAddress(lib,"simSetShapeMaterial",false));
    simGetTextureId=(ptrSimGetTextureId)(_getProcAddress(lib,"simGetTextureId",false));
    simReadTexture=(ptrSimReadTexture)(_getProcAddress(lib,"simReadTexture",false));
    simWriteCustomDataBlock=(ptrSimWriteCustomDataBlock)(_getProcAddress(lib,"simWriteCustomDataBlock",false));
    simReadCustomDataBlock=(ptrSimReadCustomDataBlock)(_getProcAddress(lib,"simReadCustomDataBlock",false));
    simReadCustomDataBlockTags=(ptrSimReadCustomDataBlockTags)(_getProcAddress(lib,"simReadCustomDataBlockTags",false));
    simGetObjects=(ptrSimGetObjects)(_getProcAddress(lib,"simGetObjects",false));
    simGetObjectsInTree=(ptrSimGetObjectsInTree)(_getProcAddress(lib,"simGetObjectsInTree",false));
    simGetShapeTextureId=(ptrSimGetShapeTextureId)(_getProcAddress(lib,"simGetShapeTextureId",false));
    simCreateCollectionEx=(ptrSimCreateCollectionEx)(_getProcAddress(lib,"simCreateCollectionEx",false));
    simAddItemToCollection=(ptrSimAddItemToCollection)(_getProcAddress(lib,"simAddItemToCollection",false));
    simDestroyCollection=(ptrSimDestroyCollection)(_getProcAddress(lib,"simDestroyCollection",false));
    simGetCollectionObjects=(ptrSimGetCollectionObjects)(_getProcAddress(lib,"simGetCollectionObjects",false));
    simAlignShapeBB=(ptrSimAlignShapeBB)(_getProcAddress(lib,"simAlignShapeBB",false));
    simRelocateShapeFrame=(ptrSimRelocateShapeFrame)(_getProcAddress(lib,"simRelocateShapeFrame",false));
    simSaveImage=(ptrSimSaveImage)(_getProcAddress(lib,"simSaveImage",false));
    simLoadImage=(ptrSimLoadImage)(_getProcAddress(lib,"simLoadImage",false));
    simGetScaledImage=(ptrSimGetScaledImage)(_getProcAddress(lib,"simGetScaledImage",false));
    simCallScriptFunctionEx=(ptrSimCallScriptFunctionEx)(_getProcAddress(lib,"simCallScriptFunctionEx",false));
    simGetExtensionString=(ptrSimGetExtensionString)(_getProcAddress(lib,"simGetExtensionString",false));
    simCreateStack=(ptrSimCreateStack)(_getProcAddress(lib,"simCreateStack",false));
    simReleaseStack=(ptrSimReleaseStack)(_getProcAddress(lib,"simReleaseStack",false));
    simCopyStack=(ptrSimCopyStack)(_getProcAddress(lib,"simCopyStack",false));
    simPushNullOntoStack=(ptrSimPushNullOntoStack)(_getProcAddress(lib,"simPushNullOntoStack",false));
    simPushBoolOntoStack=(ptrSimPushBoolOntoStack)(_getProcAddress(lib,"simPushBoolOntoStack",false));
    simPushInt32OntoStack=(ptrSimPushInt32OntoStack)(_getProcAddress(lib,"simPushInt32OntoStack",false));
    simPushInt64OntoStack=(ptrSimPushInt64OntoStack)(_getProcAddress(lib,"simPushInt64OntoStack",false));
    simPushFloatOntoStack=(ptrSimPushFloatOntoStack)(_getProcAddress(lib,"simPushFloatOntoStack",false));
    simPushDoubleOntoStack=(ptrSimPushDoubleOntoStack)(_getProcAddress(lib,"simPushDoubleOntoStack",false));
    simPushStringOntoStack=(ptrSimPushStringOntoStack)(_getProcAddress(lib,"simPushStringOntoStack",false));
    simPushUInt8TableOntoStack=(ptrSimPushUInt8TableOntoStack)(_getProcAddress(lib,"simPushUInt8TableOntoStack",false));
    simPushInt32TableOntoStack=(ptrSimPushInt32TableOntoStack)(_getProcAddress(lib,"simPushInt32TableOntoStack",false));
    simPushInt64TableOntoStack=(ptrSimPushInt64TableOntoStack)(_getProcAddress(lib,"simPushInt64TableOntoStack",false));
    simPushFloatTableOntoStack=(ptrSimPushFloatTableOntoStack)(_getProcAddress(lib,"simPushFloatTableOntoStack",false));
    simPushDoubleTableOntoStack=(ptrSimPushDoubleTableOntoStack)(_getProcAddress(lib,"simPushDoubleTableOntoStack",false));
    simPushTableOntoStack=(ptrSimPushTableOntoStack)(_getProcAddress(lib,"simPushTableOntoStack",false));
    simInsertDataIntoStackTable=(ptrSimInsertDataIntoStackTable)(_getProcAddress(lib,"simInsertDataIntoStackTable",false));
    simGetStackSize=(ptrSimGetStackSize)(_getProcAddress(lib,"simGetStackSize",false));
    simPopStackItem=(ptrSimPopStackItem)(_getProcAddress(lib,"simPopStackItem",false));
    simMoveStackItemToTop=(ptrSimMoveStackItemToTop)(_getProcAddress(lib,"simMoveStackItemToTop",false));
    simIsStackValueNull=(ptrSimIsStackValueNull)(_getProcAddress(lib,"simIsStackValueNull",false));
    simGetStackBoolValue=(ptrSimGetStackBoolValue)(_getProcAddress(lib,"simGetStackBoolValue",false));
    simGetStackInt32Value=(ptrSimGetStackInt32Value)(_getProcAddress(lib,"simGetStackInt32Value",false));
    simGetStackInt64Value=(ptrSimGetStackInt64Value)(_getProcAddress(lib,"simGetStackInt64Value",false));
    simGetStackFloatValue=(ptrSimGetStackFloatValue)(_getProcAddress(lib,"simGetStackFloatValue",false));
    simGetStackDoubleValue=(ptrSimGetStackDoubleValue)(_getProcAddress(lib,"simGetStackDoubleValue",false));
    simGetStackStringValue=(ptrSimGetStackStringValue)(_getProcAddress(lib,"simGetStackStringValue",false));
    simGetStackTableInfo=(ptrSimGetStackTableInfo)(_getProcAddress(lib,"simGetStackTableInfo",false));
    simGetStackUInt8Table=(ptrSimGetStackUInt8Table)(_getProcAddress(lib,"simGetStackUInt8Table",false));
    simGetStackInt32Table=(ptrSimGetStackInt32Table)(_getProcAddress(lib,"simGetStackInt32Table",false));
    simGetStackInt64Table=(ptrSimGetStackInt64Table)(_getProcAddress(lib,"simGetStackInt64Table",false));
    simGetStackFloatTable=(ptrSimGetStackFloatTable)(_getProcAddress(lib,"simGetStackFloatTable",false));
    simGetStackDoubleTable=(ptrSimGetStackDoubleTable)(_getProcAddress(lib,"simGetStackDoubleTable",false));
    simUnfoldStackTable=(ptrSimUnfoldStackTable)(_getProcAddress(lib,"simUnfoldStackTable",false));
    simDebugStack=(ptrSimDebugStack)(_getProcAddress(lib,"simDebugStack",false));
    simGetEngineInt32Param=(ptrSimGetEngineInt32Param)(_getProcAddress(lib,"simGetEngineInt32Param",false));
    simGetEngineBoolParam=(ptrSimGetEngineBoolParam)(_getProcAddress(lib,"simGetEngineBoolParam",false));
    simSetEngineInt32Param=(ptrSimSetEngineInt32Param)(_getProcAddress(lib,"simSetEngineInt32Param",false));
    simSetEngineBoolParam=(ptrSimSetEngineBoolParam)(_getProcAddress(lib,"simSetEngineBoolParam",false));
    simInsertObjectIntoOctree=(ptrSimInsertObjectIntoOctree)(_getProcAddress(lib,"simInsertObjectIntoOctree",false));
    simSubtractObjectFromOctree=(ptrSimSubtractObjectFromOctree)(_getProcAddress(lib,"simSubtractObjectFromOctree",false));
    simOpenTextEditor=(ptrSimOpenTextEditor)(_getProcAddress(lib,"simOpenTextEditor",false));
    simPackTable=(ptrSimPackTable)(_getProcAddress(lib,"simPackTable",false));
    simUnpackTable=(ptrSimUnpackTable)(_getProcAddress(lib,"simUnpackTable",false));
    simSetReferencedHandles=(ptrSimSetReferencedHandles)(_getProcAddress(lib,"simSetReferencedHandles",false));
    simGetReferencedHandles=(ptrSimGetReferencedHandles)(_getProcAddress(lib,"simGetReferencedHandles",false));
    simExecuteScriptString=(ptrSimExecuteScriptString)(_getProcAddress(lib,"simExecuteScriptString",false));
    simGetApiFunc=(ptrSimGetApiFunc)(_getProcAddress(lib,"simGetApiFunc",false));
    simGetApiInfo=(ptrSimGetApiInfo)(_getProcAddress(lib,"simGetApiInfo",false));
    simSetModuleInfo=(ptrSimSetModuleInfo)(_getProcAddress(lib,"simSetModuleInfo",false));
    simGetModuleInfo=(ptrSimGetModuleInfo)(_getProcAddress(lib,"simGetModuleInfo",false));
    simIsDeprecated=(ptrSimIsDeprecated)(_getProcAddress(lib,"simIsDeprecated",false));
    simGetPersistentDataTags=(ptrSimGetPersistentDataTags)(_getProcAddress(lib,"simGetPersistentDataTags",false));
    simEventNotification=(ptrSimEventNotification)(_getProcAddress(lib,"simEventNotification",false));
    simIsDynamicallyEnabled=(ptrSimIsDynamicallyEnabled)(_getProcAddress(lib,"simIsDynamicallyEnabled",false));
    simInitScript=(ptrSimInitScript)(_getProcAddress(lib,"simInitScript",false));
    simModuleEntry=(ptrSimModuleEntry)(_getProcAddress(lib,"simModuleEntry",false));
    simCheckExecAuthorization=(ptrSimCheckExecAuthorization)(_getProcAddress(lib,"simCheckExecAuthorization",false));
    simExtLaunchUIThread=(ptrSimExtLaunchUIThread)(_getProcAddress(lib,"simExtLaunchUIThread",false));
    simExtCanInitSimThread=(ptrSimExtCanInitSimThread)(_getProcAddress(lib,"simExtCanInitSimThread",false));
    simExtSimThreadInit=(ptrSimExtSimThreadInit)(_getProcAddress(lib,"simExtSimThreadInit",false));
    simExtSimThreadDestroy=(ptrSimExtSimThreadDestroy)(_getProcAddress(lib,"simExtSimThreadDestroy",false));
    simExtPostExitRequest=(ptrSimExtPostExitRequest)(_getProcAddress(lib,"simExtPostExitRequest",false));
    simExtGetExitRequest=(ptrSimExtGetExitRequest)(_getProcAddress(lib,"simExtGetExitRequest",false));
    simExtStep=(ptrSimExtStep)(_getProcAddress(lib,"simExtStep",false));
    _simSetDynamicSimulationIconCode=(ptr_simSetDynamicSimulationIconCode)(_getProcAddress(lib,"_simSetDynamicSimulationIconCode",false));
    _simSetDynamicObjectFlagForVisualization=(ptr_simSetDynamicObjectFlagForVisualization)(_getProcAddress(lib,"_simSetDynamicObjectFlagForVisualization",false));
    _simGetObjectListSize=(ptr_simGetObjectListSize)(_getProcAddress(lib,"_simGetObjectListSize",false));
    _simGetObjectFromIndex=(ptr_simGetObjectFromIndex)(_getProcAddress(lib,"_simGetObjectFromIndex",false));
    _simGetObjectID=(ptr_simGetObjectID)(_getProcAddress(lib,"_simGetObjectID",false));
    _simGetObjectType=(ptr_simGetObjectType)(_getProcAddress(lib,"_simGetObjectType",false));
    _simGetObjectChildren=(ptr_simGetObjectChildren)(_getProcAddress(lib,"_simGetObjectChildren",false));
    _simGetParentObject=(ptr_simGetParentObject)(_getProcAddress(lib,"_simGetParentObject",false));
    _simGetObject=(ptr_simGetObject)(_getProcAddress(lib,"_simGetObject",false));
    _simGetIkGroupObject=(ptr_simGetIkGroupObject)(_getProcAddress(lib,"_simGetIkGroupObject",false));
    _simMpHandleIkGroupObject=(ptr_simMpHandleIkGroupObject)(_getProcAddress(lib,"_simMpHandleIkGroupObject",false));
    _simIsShapeDynamicallyStatic=(ptr_simIsShapeDynamicallyStatic)(_getProcAddress(lib,"_simIsShapeDynamicallyStatic",false));
    _simGetTreeDynamicProperty=(ptr_simGetTreeDynamicProperty)(_getProcAddress(lib,"_simGetTreeDynamicProperty",false));
    _simGetDummyLinkType=(ptr_simGetDummyLinkType)(_getProcAddress(lib,"_simGetDummyLinkType",false));
    _simGetJointMode=(ptr_simGetJointMode)(_getProcAddress(lib,"_simGetJointMode",false));
    _simIsJointInHybridOperation=(ptr_simIsJointInHybridOperation)(_getProcAddress(lib,"_simIsJointInHybridOperation",false));
    _simDisableDynamicTreeForManipulation=(ptr_simDisableDynamicTreeForManipulation)(_getProcAddress(lib,"_simDisableDynamicTreeForManipulation",false));
    _simIsShapeDynamicallyRespondable=(ptr_simIsShapeDynamicallyRespondable)(_getProcAddress(lib,"_simIsShapeDynamicallyRespondable",false));
    _simGetDynamicCollisionMask=(ptr_simGetDynamicCollisionMask)(_getProcAddress(lib,"_simGetDynamicCollisionMask",false));
    _simGetLastParentForLocalGlobalCollidable=(ptr_simGetLastParentForLocalGlobalCollidable)(_getProcAddress(lib,"_simGetLastParentForLocalGlobalCollidable",false));
    _simGetStartSleeping=(ptr_simGetStartSleeping)(_getProcAddress(lib,"_simGetStartSleeping",false));
    _simGetWasPutToSleepOnce=(ptr_simGetWasPutToSleepOnce)(_getProcAddress(lib,"_simGetWasPutToSleepOnce",false));
    _simGetDynamicsFullRefreshFlag=(ptr_simGetDynamicsFullRefreshFlag)(_getProcAddress(lib,"_simGetDynamicsFullRefreshFlag",false));
    _simSetDynamicsFullRefreshFlag=(ptr_simSetDynamicsFullRefreshFlag)(_getProcAddress(lib,"_simSetDynamicsFullRefreshFlag",false));
    _simClearAdditionalForceAndTorque=(ptr_simClearAdditionalForceAndTorque)(_getProcAddress(lib,"_simClearAdditionalForceAndTorque",false));
    _simGetJointType=(ptr_simGetJointType)(_getProcAddress(lib,"_simGetJointType",false));
    _simGetGeomWrapFromGeomProxy=(ptr_simGetGeomWrapFromGeomProxy)(_getProcAddress(lib,"_simGetGeomWrapFromGeomProxy",false));
    _simGetPurePrimitiveType=(ptr_simGetPurePrimitiveType)(_getProcAddress(lib,"_simGetPurePrimitiveType",false));
    _simIsGeomWrapGeometric=(ptr_simIsGeomWrapGeometric)(_getProcAddress(lib,"_simIsGeomWrapGeometric",false));
    _simIsGeomWrapConvex=(ptr_simIsGeomWrapConvex)(_getProcAddress(lib,"_simIsGeomWrapConvex",false));
    _simGetGeometricCount=(ptr_simGetGeometricCount)(_getProcAddress(lib,"_simGetGeometricCount",false));
    _simGetAllGeometrics=(ptr_simGetAllGeometrics)(_getProcAddress(lib,"_simGetAllGeometrics",false));
    _simMakeDynamicAnnouncement=(ptr_simMakeDynamicAnnouncement)(_getProcAddress(lib,"_simMakeDynamicAnnouncement",false));
    _simGetTimeDiffInMs=(ptr_simGetTimeDiffInMs)(_getProcAddress(lib,"_simGetTimeDiffInMs",false));
    _simDoEntitiesCollide=(ptr_simDoEntitiesCollide)(_getProcAddress(lib,"_simDoEntitiesCollide",false));
    _simGetJointDynCtrlMode=(ptr_simGetJointDynCtrlMode)(_getProcAddress(lib,"_simGetJointDynCtrlMode",false));
    simFloatingViewRemove=(ptrSimFloatingViewRemove)(_getProcAddress(lib,"simFloatingViewRemove",false));
    /* previously single precision functions: */
    simGetShapeViz=(ptrSimGetShapeViz)(_getProcAddress(lib,"simGetShapeViz",true));
    simGetVisionSensorDepth=(ptrSimGetVisionSensorDepth)(_getProcAddress(lib,"simGetVisionSensorDepth",false));
    _simSetVisionSensorDepth=(ptr_simSetVisionSensorDepth)(_getProcAddress(lib,"_simSetVisionSensorDepth",false));
    simSetFloatSignal=(ptrSimSetFloatSignal)(_getProcAddress(lib,"simSetFloatSignal",true));
    simGetFloatSignal=(ptrSimGetFloatSignal)(_getProcAddress(lib,"simGetFloatSignal",true));
    simSetFloatParam=(ptrSimSetFloatParam)(_getProcAddress(lib,"simSetFloatParam",true));
    simGetFloatParam=(ptrSimGetFloatParam)(_getProcAddress(lib,"simGetFloatParam",true));
    simGetObjectFloatParam=(ptrSimGetObjectFloatParam)(_getProcAddress(lib,"simGetObjectFloatParam",true));
    simSetObjectFloatParam=(ptrSimSetObjectFloatParam)(_getProcAddress(lib,"simSetObjectFloatParam",true));
    simGetObjectFloatArrayParam=(ptrSimGetObjectFloatArrayParam)(_getProcAddress(lib,"simGetObjectFloatArrayParam",true));
    simSetObjectFloatArrayParam=(ptrSimSetObjectFloatArrayParam)(_getProcAddress(lib,"simSetObjectFloatArrayParam",true));
    simGetEngineFloatParam=(ptrSimGetEngineFloatParam)(_getProcAddress(lib,"simGetEngineFloatParam",true));
    simSetEngineFloatParam=(ptrSimSetEngineFloatParam)(_getProcAddress(lib,"simSetEngineFloatParam",true));
    simTransformImage=(ptrSimTransformImage)(_getProcAddress(lib,"simTransformImage",true));
    simGetOctreeVoxels=(ptrSimGetOctreeVoxels)(_getProcAddress(lib,"simGetOctreeVoxels",true));
    simGetPointCloudPoints=(ptrSimGetPointCloudPoints)(_getProcAddress(lib,"simGetPointCloudPoints",true));
    simGetObjectMatrix=(ptrSimGetObjectMatrix)(_getProcAddress(lib,"simGetObjectMatrix",true));
    simSetObjectMatrix=(ptrSimSetObjectMatrix)(_getProcAddress(lib,"simSetObjectMatrix",true));
    simGetObjectPose=(ptrSimGetObjectPose)(_getProcAddress(lib,"simGetObjectPose",true));
    simSetObjectPose=(ptrSimSetObjectPose)(_getProcAddress(lib,"simSetObjectPose",true));
    simGetObjectPosition=(ptrSimGetObjectPosition)(_getProcAddress(lib,"simGetObjectPosition",true));
    simSetObjectPosition=(ptrSimSetObjectPosition)(_getProcAddress(lib,"simSetObjectPosition",true));
    simGetObjectOrientation=(ptrSimGetObjectOrientation)(_getProcAddress(lib,"simGetObjectOrientation",true));
    simSetObjectOrientation=(ptrSimSetObjectOrientation)(_getProcAddress(lib,"simSetObjectOrientation",true));
    simGetJointPosition=(ptrSimGetJointPosition)(_getProcAddress(lib,"simGetJointPosition",true));
    simSetJointPosition=(ptrSimSetJointPosition)(_getProcAddress(lib,"simSetJointPosition",true));
    simSetJointTargetPosition=(ptrSimSetJointTargetPosition)(_getProcAddress(lib,"simSetJointTargetPosition",true));
    simGetJointTargetPosition=(ptrSimGetJointTargetPosition)(_getProcAddress(lib,"simGetJointTargetPosition",true));
    simGetObjectChildPose=(ptrSimGetObjectChildPose)(_getProcAddress(lib,"simGetObjectChildPose",true));
    simSetObjectChildPose=(ptrSimSetObjectChildPose)(_getProcAddress(lib,"simSetObjectChildPose",true));
    simGetJointInterval=(ptrSimGetJointInterval)(_getProcAddress(lib,"simGetJointInterval",true));
    simSetJointInterval=(ptrSimSetJointInterval)(_getProcAddress(lib,"simSetJointInterval",true));
    simGetJointTargetForce=(ptrSimGetJointTargetForce)(_getProcAddress(lib,"simGetJointTargetForce",true));
    simSetJointTargetForce=(ptrSimSetJointTargetForce)(_getProcAddress(lib,"simSetJointTargetForce",true));
    simBuildIdentityMatrix=(ptrSimBuildIdentityMatrix)(_getProcAddress(lib,"simBuildIdentityMatrix",true));
    simBuildMatrix=(ptrSimBuildMatrix)(_getProcAddress(lib,"simBuildMatrix",true));
    simBuildPose=(ptrSimBuildPose)(_getProcAddress(lib,"simBuildPose",true));
    simGetEulerAnglesFromMatrix=(ptrSimGetEulerAnglesFromMatrix)(_getProcAddress(lib,"simGetEulerAnglesFromMatrix",true));
    simInvertMatrix=(ptrSimInvertMatrix)(_getProcAddress(lib,"simInvertMatrix",true));
    simMultiplyMatrices=(ptrSimMultiplyMatrices)(_getProcAddress(lib,"simMultiplyMatrices",true));
    simMultiplyPoses=(ptrSimMultiplyPoses)(_getProcAddress(lib,"simMultiplyPoses",true));
    simInvertPose=(ptrSimInvertPose)(_getProcAddress(lib,"simInvertPose",true));
    simInterpolatePoses=(ptrSimInterpolatePoses)(_getProcAddress(lib,"simInterpolatePoses",true));
    simPoseToMatrix=(ptrSimPoseToMatrix)(_getProcAddress(lib,"simPoseToMatrix",true));
    simMatrixToPose=(ptrSimMatrixToPose)(_getProcAddress(lib,"simMatrixToPose",true));
    simInterpolateMatrices=(ptrSimInterpolateMatrices)(_getProcAddress(lib,"simInterpolateMatrices",true));
    simTransformVector=(ptrSimTransformVector)(_getProcAddress(lib,"simTransformVector",true));
    simGetSimulationTime=(ptrSimGetSimulationTime)(_getProcAddress(lib,"simGetSimulationTime",true));
    simGetSystemTime=(ptrSimGetSystemTime)(_getProcAddress(lib,"simGetSystemTime",true));
    simHandleProximitySensor=(ptrSimHandleProximitySensor)(_getProcAddress(lib,"simHandleProximitySensor",true));
    simReadProximitySensor=(ptrSimReadProximitySensor)(_getProcAddress(lib,"simReadProximitySensor",true));
    simHandleDynamics=(ptrSimHandleDynamics)(_getProcAddress(lib,"simHandleDynamics",true));
    simCheckProximitySensor=(ptrSimCheckProximitySensor)(_getProcAddress(lib,"simCheckProximitySensor",true));
    simCheckProximitySensorEx=(ptrSimCheckProximitySensorEx)(_getProcAddress(lib,"simCheckProximitySensorEx",true));
    simCheckProximitySensorEx2=(ptrSimCheckProximitySensorEx2)(_getProcAddress(lib,"simCheckProximitySensorEx2",true));
    simCheckCollisionEx=(ptrSimCheckCollisionEx)(_getProcAddress(lib,"simCheckCollisionEx",true));
    simCheckDistance=(ptrSimCheckDistance)(_getProcAddress(lib,"simCheckDistance",true));
    simSetSimulationTimeStep=(ptrSimSetSimulationTimeStep)(_getProcAddress(lib,"simSetSimulationTimeStep",true));
    simGetSimulationTimeStep=(ptrSimGetSimulationTimeStep)(_getProcAddress(lib,"simGetSimulationTimeStep",true));
    simAdjustRealTimeTimer=(ptrSimAdjustRealTimeTimer)(_getProcAddress(lib,"simAdjustRealTimeTimer",true));
    simFloatingViewAdd=(ptrSimFloatingViewAdd)(_getProcAddress(lib,"simFloatingViewAdd",true));
    simHandleGraph=(ptrSimHandleGraph)(_getProcAddress(lib,"simHandleGraph",true));
    simSetGraphStreamTransformation=(ptrSimSetGraphStreamTransformation)(_getProcAddress(lib,"simSetGraphStreamTransformation",true));
    simAddGraphCurve=(ptrSimAddGraphCurve)(_getProcAddress(lib,"simAddGraphCurve",true));
    simSetGraphStreamValue=(ptrSimSetGraphStreamValue)(_getProcAddress(lib,"simSetGraphStreamValue",true));
    simSetJointTargetVelocity=(ptrSimSetJointTargetVelocity)(_getProcAddress(lib,"simSetJointTargetVelocity",true));
    simGetJointTargetVelocity=(ptrSimGetJointTargetVelocity)(_getProcAddress(lib,"simGetJointTargetVelocity",true));
    simScaleObjects=(ptrSimScaleObjects)(_getProcAddress(lib,"simScaleObjects",true));
    simAddDrawingObject=(ptrSimAddDrawingObject)(_getProcAddress(lib,"simAddDrawingObject",true));
    simAddGraphStream=(ptrSimAddGraphStream)(_getProcAddress(lib,"simAddGraphStream",true));
    simAddDrawingObjectItem=(ptrSimAddDrawingObjectItem)(_getProcAddress(lib,"simAddDrawingObjectItem",true));
    simGetObjectSizeFactor=(ptrSimGetObjectSizeFactor)(_getProcAddress(lib,"simGetObjectSizeFactor",true));
    simReadForceSensor=(ptrSimReadForceSensor)(_getProcAddress(lib,"simReadForceSensor",true));
    simSetLightParameters=(ptrSimSetLightParameters)(_getProcAddress(lib,"simSetLightParameters",false));
    simGetLightParameters=(ptrSimGetLightParameters)(_getProcAddress(lib,"simGetLightParameters",true));
    simGetVelocity=(ptrSimGetVelocity)(_getProcAddress(lib,"simGetVelocity",true));
    simGetObjectVelocity=(ptrSimGetObjectVelocity)(_getProcAddress(lib,"simGetObjectVelocity",true));
    simGetJointVelocity=(ptrSimGetJointVelocity)(_getProcAddress(lib,"simGetJointVelocity",true));
    simAddForceAndTorque=(ptrSimAddForceAndTorque)(_getProcAddress(lib,"simAddForceAndTorque",true));
    simAddForce=(ptrSimAddForce)(_getProcAddress(lib,"simAddForce",true));
    simSetObjectColor=(ptrSimSetObjectColor)(_getProcAddress(lib,"simSetObjectColor",false));
    simGetObjectColor=(ptrSimGetObjectColor)(_getProcAddress(lib,"simGetObjectColor",false));
    simSetShapeColor=(ptrSimSetShapeColor)(_getProcAddress(lib,"simSetShapeColor",false));
    simGetShapeColor=(ptrSimGetShapeColor)(_getProcAddress(lib,"simGetShapeColor",false));
    simGetContactInfo=(ptrSimGetContactInfo)(_getProcAddress(lib,"simGetContactInfo",true));
    simAuxiliaryConsoleOpen=(ptrSimAuxiliaryConsoleOpen)(_getProcAddress(lib,"simAuxiliaryConsoleOpen",false));
    simImportShape=(ptrSimImportShape)(_getProcAddress(lib,"simImportShape",true));
    simImportMesh=(ptrSimImportMesh)(_getProcAddress(lib,"simImportMesh",true));
    simExportMesh=(ptrSimExportMesh)(_getProcAddress(lib,"simExportMesh",true));
    simCreateShape=(ptrSimCreateShape)(_getProcAddress(lib,"simCreateShape",false));
    simCreateMeshShape=(ptrSimCreateMeshShape)(_getProcAddress(lib,"simCreateMeshShape",true));
    simCreatePrimitiveShape=(ptrSimCreatePrimitiveShape)(_getProcAddress(lib,"simCreatePrimitiveShape",true));
    simCreateHeightfieldShape=(ptrSimCreateHeightfieldShape)(_getProcAddress(lib,"simCreateHeightfieldShape",true));
    simGetShapeMesh=(ptrSimGetShapeMesh)(_getProcAddress(lib,"simGetShapeMesh",true));
    simCreateJoint=(ptrSimCreateJoint)(_getProcAddress(lib,"simCreateJoint",true));
    simCreateDummy=(ptrSimCreateDummy)(_getProcAddress(lib,"simCreateDummy",true));
    simCreateProximitySensor=(ptrSimCreateProximitySensor)(_getProcAddress(lib,"simCreateProximitySensor",true));
    simCreateForceSensor=(ptrSimCreateForceSensor)(_getProcAddress(lib,"simCreateForceSensor",true));
    simCreateVisionSensor=(ptrSimCreateVisionSensor)(_getProcAddress(lib,"simCreateVisionSensor",true));
    simGetRotationAxis=(ptrSimGetRotationAxis)(_getProcAddress(lib,"simGetRotationAxis",true));
    simRotateAroundAxis=(ptrSimRotateAroundAxis)(_getProcAddress(lib,"simRotateAroundAxis",true));
    simGetJointForce=(ptrSimGetJointForce)(_getProcAddress(lib,"simGetJointForce",true));
    simCameraFitToView=(ptrSimCameraFitToView)(_getProcAddress(lib,"simCameraFitToView",true));
    simHandleVisionSensor=(ptrSimHandleVisionSensor)(_getProcAddress(lib,"simHandleVisionSensor",true));
    simReadVisionSensor=(ptrSimReadVisionSensor)(_getProcAddress(lib,"simReadVisionSensor",true));
    simCheckVisionSensor=(ptrSimCheckVisionSensor)(_getProcAddress(lib,"simCheckVisionSensor",true));
    simCheckVisionSensorEx=(ptrSimCheckVisionSensorEx)(_getProcAddress(lib,"simCheckVisionSensorEx",false));
    simGetVisionSensorImg=(ptrSimGetVisionSensorImg)(_getProcAddress(lib,"simGetVisionSensorImg",true));
    simGetVisionSensorRes=(ptrSimGetVisionSensorRes)(_getProcAddress(lib,"simGetVisionSensorRes",false));
    simGetObjectQuaternion=(ptrSimGetObjectQuaternion)(_getProcAddress(lib,"simGetObjectQuaternion",true));
    simSetObjectQuaternion=(ptrSimSetObjectQuaternion)(_getProcAddress(lib,"simSetObjectQuaternion",true));
    simConvexDecompose=(ptrSimConvexDecompose)(_getProcAddress(lib,"simConvexDecompose",true));
    simWriteTexture=(ptrSimWriteTexture)(_getProcAddress(lib,"simWriteTexture",true));
    simCreateTexture=(ptrSimCreateTexture)(_getProcAddress(lib,"simCreateTexture",true));
    simGetShapeGeomInfo=(ptrSimGetShapeGeomInfo)(_getProcAddress(lib,"simGetShapeGeomInfo",true));
    simScaleObject=(ptrSimScaleObject)(_getProcAddress(lib,"simScaleObject",true));
    simSetShapeTexture=(ptrSimSetShapeTexture)(_getProcAddress(lib,"simSetShapeTexture",true));
    simGetQHull=(ptrSimGetQHull)(_getProcAddress(lib,"simGetQHull",true));
    simGetDecimatedMesh=(ptrSimGetDecimatedMesh)(_getProcAddress(lib,"simGetDecimatedMesh",true));
    simComputeMassAndInertia=(ptrSimComputeMassAndInertia)(_getProcAddress(lib,"simComputeMassAndInertia",true));
    simCreateOctree=(ptrSimCreateOctree)(_getProcAddress(lib,"simCreateOctree",true));
    simCreatePointCloud=(ptrSimCreatePointCloud)(_getProcAddress(lib,"simCreatePointCloud",true));
    simSetPointCloudOptions=(ptrSimSetPointCloudOptions)(_getProcAddress(lib,"simSetPointCloudOptions",true));
    simGetPointCloudOptions=(ptrSimGetPointCloudOptions)(_getProcAddress(lib,"simGetPointCloudOptions",true));
    simInsertVoxelsIntoOctree=(ptrSimInsertVoxelsIntoOctree)(_getProcAddress(lib,"simInsertVoxelsIntoOctree",true));
    simRemoveVoxelsFromOctree=(ptrSimRemoveVoxelsFromOctree)(_getProcAddress(lib,"simRemoveVoxelsFromOctree",true));
    simInsertPointsIntoPointCloud=(ptrSimInsertPointsIntoPointCloud)(_getProcAddress(lib,"simInsertPointsIntoPointCloud",true));
    simRemovePointsFromPointCloud=(ptrSimRemovePointsFromPointCloud)(_getProcAddress(lib,"simRemovePointsFromPointCloud",true));
    simIntersectPointsWithPointCloud=(ptrSimIntersectPointsWithPointCloud)(_getProcAddress(lib,"simIntersectPointsWithPointCloud",true));
    simInsertObjectIntoPointCloud=(ptrSimInsertObjectIntoPointCloud)(_getProcAddress(lib,"simInsertObjectIntoPointCloud",true));
    simSubtractObjectFromPointCloud=(ptrSimSubtractObjectFromPointCloud)(_getProcAddress(lib,"simSubtractObjectFromPointCloud",true));
    simCheckOctreePointOccupancy=(ptrSimCheckOctreePointOccupancy)(_getProcAddress(lib,"simCheckOctreePointOccupancy",true));
    simApplyTexture=(ptrSimApplyTexture)(_getProcAddress(lib,"simApplyTexture",true));
    simSetJointDependency=(ptrSimSetJointDependency)(_getProcAddress(lib,"simSetJointDependency",true));
    simGetJointDependency=(ptrSimGetJointDependency)(_getProcAddress(lib,"simGetJointDependency",true));
    simGetShapeMass=(ptrSimGetShapeMass)(_getProcAddress(lib,"simGetShapeMass",true));
    simSetShapeMass=(ptrSimSetShapeMass)(_getProcAddress(lib,"simSetShapeMass",true));
    simGetShapeInertia=(ptrSimGetShapeInertia)(_getProcAddress(lib,"simGetShapeInertia",true));
    simSetShapeInertia=(ptrSimSetShapeInertia)(_getProcAddress(lib,"simSetShapeInertia",true));
    simGenerateShapeFromPath=(ptrSimGenerateShapeFromPath)(_getProcAddress(lib,"simGenerateShapeFromPath",true));
    simGetClosestPosOnPath=(ptrSimGetClosestPosOnPath)(_getProcAddress(lib,"simGetClosestPosOnPath",true));
    simExtCallScriptFunction=(ptrSimExtCallScriptFunction)(_getProcAddress(lib,"simExtCallScriptFunction",true));
    _simGetObjectLocalTransformation=(ptr_simGetObjectLocalTransformation)(_getProcAddress(lib,"_simGetObjectLocalTransformation",true));
    _simSetObjectLocalTransformation=(ptr_simSetObjectLocalTransformation)(_getProcAddress(lib,"_simSetObjectLocalTransformation",true));
    _simDynReportObjectCumulativeTransformation=(ptr_simDynReportObjectCumulativeTransformation)(_getProcAddress(lib,"_simDynReportObjectCumulativeTransformation",true));
    _simSetObjectCumulativeTransformation=(ptr_simSetObjectCumulativeTransformation)(_getProcAddress(lib,"_simSetObjectCumulativeTransformation",true));
    _simGetObjectCumulativeTransformation=(ptr_simGetObjectCumulativeTransformation)(_getProcAddress(lib,"_simGetObjectCumulativeTransformation",true));
    _simSetJointVelocity=(ptr_simSetJointVelocity)(_getProcAddress(lib,"_simSetJointVelocity",true));
    _simSetJointPosition=(ptr_simSetJointPosition)(_getProcAddress(lib,"_simSetJointPosition",true));
    _simGetJointPosition=(ptr_simGetJointPosition)(_getProcAddress(lib,"_simGetJointPosition",true));
    _simSetDynamicMotorPositionControlTargetPosition=(ptr_simSetDynamicMotorPositionControlTargetPosition)(_getProcAddress(lib,"_simSetDynamicMotorPositionControlTargetPosition",true));
    _simGetInitialDynamicVelocity=(ptr_simGetInitialDynamicVelocity)(_getProcAddress(lib,"_simGetInitialDynamicVelocity",true));
    _simSetInitialDynamicVelocity=(ptr_simSetInitialDynamicVelocity)(_getProcAddress(lib,"_simSetInitialDynamicVelocity",true));
    _simGetInitialDynamicAngVelocity=(ptr_simGetInitialDynamicAngVelocity)(_getProcAddress(lib,"_simGetInitialDynamicAngVelocity",true));
    _simSetInitialDynamicAngVelocity=(ptr_simSetInitialDynamicAngVelocity)(_getProcAddress(lib,"_simSetInitialDynamicAngVelocity",true));
    _simSetShapeDynamicVelocity=(ptr_simSetShapeDynamicVelocity)(_getProcAddress(lib,"_simSetShapeDynamicVelocity",true));
    _simGetAdditionalForceAndTorque=(ptr_simGetAdditionalForceAndTorque)(_getProcAddress(lib,"_simGetAdditionalForceAndTorque",true));
    _simGetJointPositionInterval=(ptr_simGetJointPositionInterval)(_getProcAddress(lib,"_simGetJointPositionInterval",true));
    _simGetDynamicMotorTargetPosition=(ptr_simGetDynamicMotorTargetPosition)(_getProcAddress(lib,"_simGetDynamicMotorTargetPosition",true));
    _simGetDynamicMotorTargetVelocity=(ptr_simGetDynamicMotorTargetVelocity)(_getProcAddress(lib,"_simGetDynamicMotorTargetVelocity",true));
    _simGetDynamicMotorMaxForce=(ptr_simGetDynamicMotorMaxForce)(_getProcAddress(lib,"_simGetDynamicMotorMaxForce",true));
    _simGetDynamicMotorUpperLimitVelocity=(ptr_simGetDynamicMotorUpperLimitVelocity)(_getProcAddress(lib,"_simGetDynamicMotorUpperLimitVelocity",true));
    _simSetDynamicMotorReflectedPositionFromDynamicEngine=(ptr_simSetDynamicMotorReflectedPositionFromDynamicEngine)(_getProcAddress(lib,"_simSetDynamicMotorReflectedPositionFromDynamicEngine",true));
    _simSetJointSphericalTransformation=(ptr_simSetJointSphericalTransformation)(_getProcAddress(lib,"_simSetJointSphericalTransformation",true));
    _simAddForceSensorCumulativeForcesAndTorques=(ptr_simAddForceSensorCumulativeForcesAndTorques)(_getProcAddress(lib,"_simAddForceSensorCumulativeForcesAndTorques",true));
    _simAddJointCumulativeForcesOrTorques=(ptr_simAddJointCumulativeForcesOrTorques)(_getProcAddress(lib,"_simAddJointCumulativeForcesOrTorques",true));
    _simGetMass=(ptr_simGetMass)(_getProcAddress(lib,"_simGetMass",true));
    _simGetLocalInertiaInfo=(ptr_simGetLocalInertiaInfo)(_getProcAddress(lib,"_simGetLocalInertiaInfo",true));
    _simGetPurePrimitiveSizes=(ptr_simGetPurePrimitiveSizes)(_getProcAddress(lib,"_simGetPurePrimitiveSizes",true));
    _simGetVerticesLocalFrame=(ptr_simGetVerticesLocalFrame)(_getProcAddress(lib,"_simGetVerticesLocalFrame",true));
    _simGetHeightfieldData=(ptr_simGetHeightfieldData)(_getProcAddress(lib,"_simGetHeightfieldData",true));
    _simGetCumulativeMeshes=(ptr_simGetCumulativeMeshes)(_getProcAddress(lib,"_simGetCumulativeMeshes",true));
    _simGetGravity=(ptr_simGetGravity)(_getProcAddress(lib,"_simGetGravity",true));
    _simGetDistanceBetweenEntitiesIfSmaller=(ptr_simGetDistanceBetweenEntitiesIfSmaller)(_getProcAddress(lib,"_simGetDistanceBetweenEntitiesIfSmaller",true));
    _simHandleJointControl=(ptr_simHandleJointControl)(_getProcAddress(lib,"_simHandleJointControl",true));
    _simHandleCustomContact=(ptr_simHandleCustomContact)(_getProcAddress(lib,"_simHandleCustomContact",true));
    _simGetPureHollowScaling=(ptr_simGetPureHollowScaling)(_getProcAddress(lib,"_simGetPureHollowScaling",true));
    _simDynCallback=(ptr_simDynCallback)(_getProcAddress(lib,"_simDynCallback",true));

    char *ps=std::getenv("COPPELIASIMPLUGIN_IGNORE_MISSING_SYMBOLS");
    if (ps!=nullptr)
        return(1);

    char couldNotFind[]="Could not find function";
    if (simRunSimulator==nullptr)
    {
        printf("%s simRunSimulator\n",couldNotFind);
        return 0;
    }
    if (simRunSimulatorEx==nullptr)
    {
        printf("%s simRunSimulatorEx\n",couldNotFind);
        return 0;
    }
    if (simGetSimulatorMessage==nullptr)
    {
        printf("%s simGetSimulatorMessage\n",couldNotFind);
        return 0;
    }
    if (simGetMainWindow==nullptr)
    {
        printf("%s simGetMainWindow\n",couldNotFind);
        return 0;
    }
    if (simGetLastError==nullptr)
    {
        printf("%s simGetLastError\n",couldNotFind);
        return 0;
    }
    if (simLoadModule==nullptr)
    {
        printf("%s simLoadModule\n",couldNotFind);
        return 0;
    }
    if (simUnloadModule==nullptr)
    {
        printf("%s simUnloadModule\n",couldNotFind);
        return 0;
    }
    if (simSetBoolParam==nullptr)
    {
        printf("%s simSetBoolParam\n",couldNotFind);
        return 0;
    }
    if (simGetBoolParam==nullptr)
    {
        printf("%s simGetBoolParam\n",couldNotFind);
        return 0;
    }
    if (simSetInt32Param==nullptr)
    {
        printf("%s simSetInt32Param\n",couldNotFind);
        return 0;
    }
    if (simGetInt32Param==nullptr)
    {
        printf("%s simGetInt32Param\n",couldNotFind);
        return 0;
    }
    if (simGetUInt64Param==nullptr)
    {
        printf("%s simGetUInt64Param\n",couldNotFind);
        return 0;
    }
    if (simSetFloatParam==nullptr)
    {
        printf("%s simSetFloatParam\n",couldNotFind);
        return 0;
    }
    if (simGetFloatParam==nullptr)
    {
        printf("%s simGetFloatParam\n",couldNotFind);
        return 0;
    }
    if (simSetStringParam==nullptr)
    {
        printf("%s simSetStringParam\n",couldNotFind);
        return 0;
    }
    if (simGetStringParam==nullptr)
    {
        printf("%s simGetStringParam\n",couldNotFind);
        return 0;
    }
    if (simSetArrayParam==nullptr)
    {
        printf("%s simSetArrayParam\n",couldNotFind);
        return 0;
    }
    if (simGetArrayParam==nullptr)
    {
        printf("%s simGetArrayParam\n",couldNotFind);
        return 0;
    }
    if (simSetNamedStringParam==nullptr)
    {
        printf("%s simSetNamedStringParam\n",couldNotFind);
        return 0;
    }
    if (simGetNamedStringParam==nullptr)
    {
        printf("%s simGetNamedStringParam\n",couldNotFind);
        return 0;
    }
    if (simGetObject==nullptr)
    {
        printf("%s simGetObject\n",couldNotFind);
        return 0;
    }
    if (simGetObjectUid==nullptr)
    {
        printf("%s simGetObjectUid\n",couldNotFind);
        return 0;
    }
    if (simGetObjectFromUid==nullptr)
    {
        printf("%s simGetObjectFromUid\n",couldNotFind);
        return 0;
    }
    if (simGetScriptHandleEx==nullptr)
    {
        printf("%s simGetScriptHandleEx\n",couldNotFind);
        return 0;
    }
    if (simRemoveObjects==nullptr)
    {
        printf("%s simRemoveObjects\n",couldNotFind);
        return 0;
    }
    if (simRemoveModel==nullptr)
    {
        printf("%s simRemoveModel\n",couldNotFind);
        return 0;
    }
    if (simGetObjectAlias==nullptr)
    {
        printf("%s simGetObjectAlias\n",couldNotFind);
        return 0;
    }
    if (simSetObjectAlias==nullptr)
    {
        printf("%s simSetObjectAlias\n",couldNotFind);
        return 0;
    }
    if (simGetObjectMatrix==nullptr)
    {
        printf("%s simGetObjectMatrix\n",couldNotFind);
        return 0;
    }
    if (simSetObjectMatrix==nullptr)
    {
        printf("%s simSetObjectMatrix\n",couldNotFind);
        return 0;
    }
    if (simGetObjectPose==nullptr)
    {
        printf("%s simGetObjectPose\n",couldNotFind);
        return 0;
    }
    if (simSetObjectPose==nullptr)
    {
        printf("%s simSetObjectPose\n",couldNotFind);
        return 0;
    }
    if (simGetObjectPosition==nullptr)
    {
        printf("%s simGetObjectPosition\n",couldNotFind);
        return 0;
    }
    if (simSetObjectPosition==nullptr)
    {
        printf("%s simSetObjectPosition\n",couldNotFind);
        return 0;
    }
    if (simGetObjectOrientation==nullptr)
    {
        printf("%s simGetObjectOrientation\n",couldNotFind);
        return 0;
    }
    if (simSetObjectOrientation==nullptr)
    {
        printf("%s simSetObjectOrientation\n",couldNotFind);
        return 0;
    }
    if (simGetJointPosition==nullptr)
    {
        printf("%s simGetJointPosition\n",couldNotFind);
        return 0;
    }
    if (simSetJointPosition==nullptr)
    {
        printf("%s simSetJointPosition\n",couldNotFind);
        return 0;
    }
    if (simSetJointTargetPosition==nullptr)
    {
        printf("%s simSetJointTargetPosition\n",couldNotFind);
        return 0;
    }
    if (simGetJointTargetPosition==nullptr)
    {
        printf("%s simGetJointTargetPosition\n",couldNotFind);
        return 0;
    }
    if (simGetObjectChildPose==nullptr)
    {
        printf("%s simGetObjectChildPose\n",couldNotFind);
        return 0;
    }
    if (simSetObjectChildPose==nullptr)
    {
        printf("%s simSetObjectChildPose\n",couldNotFind);
        return 0;
    }
    if (simGetJointInterval==nullptr)
    {
        printf("%s simGetJointInterval\n",couldNotFind);
        return 0;
    }
    if (simSetJointInterval==nullptr)
    {
        printf("%s simSetJointInterval\n",couldNotFind);
        return 0;
    }
    if (simGetObjectParent==nullptr)
    {
        printf("%s simGetObjectParent\n",couldNotFind);
        return 0;
    }
    if (simGetObjectChild==nullptr)
    {
        printf("%s simGetObjectChild\n",couldNotFind);
        return 0;
    }
    if (simSetObjectParent==nullptr)
    {
        printf("%s simSetObjectParent\n",couldNotFind);
        return 0;
    }
    if (simGetObjectType==nullptr)
    {
        printf("%s simGetObjectType\n",couldNotFind);
        return 0;
    }
    if (simGetJointType==nullptr)
    {
        printf("%s simGetJointType\n",couldNotFind);
        return 0;
    }
    if (simBuildIdentityMatrix==nullptr)
    {
        printf("%s simBuildIdentityMatrix\n",couldNotFind);
        return 0;
    }
    if (simBuildMatrix==nullptr)
    {
        printf("%s simBuildMatrix\n",couldNotFind);
        return 0;
    }
    if (simBuildPose==nullptr)
    {
        printf("%s simBuildPose\n",couldNotFind);
        return 0;
    }
    if (simGetEulerAnglesFromMatrix==nullptr)
    {
        printf("%s simGetEulerAnglesFromMatrix\n",couldNotFind);
        return 0;
    }
    if (simInvertMatrix==nullptr)
    {
        printf("%s simInvertMatrix\n",couldNotFind);
        return 0;
    }
    if (simMultiplyMatrices==nullptr)
    {
        printf("%s simMultiplyMatrices\n",couldNotFind);
        return 0;
    }
    if (simMultiplyPoses==nullptr)
    {
        printf("%s simMultiplyPoses\n",couldNotFind);
        return 0;
    }
    if (simInvertPose==nullptr)
    {
        printf("%s simInvertPose\n",couldNotFind);
        return 0;
    }
    if (simInterpolatePoses==nullptr)
    {
        printf("%s simInterpolatePoses\n",couldNotFind);
        return 0;
    }
    if (simPoseToMatrix==nullptr)
    {
        printf("%s simPoseToMatrix\n",couldNotFind);
        return 0;
    }
    if (simMatrixToPose==nullptr)
    {
        printf("%s simMatrixToPose\n",couldNotFind);
        return 0;
    }
    if (simInterpolateMatrices==nullptr)
    {
        printf("%s simInterpolateMatrices\n",couldNotFind);
        return 0;
    }
    if (simTransformVector==nullptr)
    {
        printf("%s simTransformVector\n",couldNotFind);
        return 0;
    }
    if (simReservedCommand==nullptr)
    {
        printf("%s simReservedCommand\n",couldNotFind);
        return 0;
    }
    if (simGetSimulationTime==nullptr)
    {
        printf("%s simGetSimulationTime\n",couldNotFind);
        return 0;
    }
    if (simGetSimulationState==nullptr)
    {
        printf("%s simGetSimulationState\n",couldNotFind);
        return 0;
    }
    if (simGetSystemTime==nullptr)
    {
        printf("%s simGetSystemTime\n",couldNotFind);
        return 0;
    }
    if (simLoadScene==nullptr)
    {
        printf("%s simLoadScene\n",couldNotFind);
        return 0;
    }
    if (simCloseScene==nullptr)
    {
        printf("%s simCloseScene\n",couldNotFind);
        return 0;
    }
    if (simSaveScene==nullptr)
    {
        printf("%s simSaveScene\n",couldNotFind);
        return 0;
    }
    if (simLoadModel==nullptr)
    {
        printf("%s simLoadModel\n",couldNotFind);
        return 0;
    }
    if (simSaveModel==nullptr)
    {
        printf("%s simSaveModel\n",couldNotFind);
        return 0;
    }
    if (simDoesFileExist==nullptr)
    {
        printf("%s simDoesFileExist\n",couldNotFind);
        return 0;
    }
    if (simGetObjectSel==nullptr)
    {
        printf("%s simGetObjectSel\n",couldNotFind);
        return 0;
    }
    if (simSetObjectSel==nullptr)
    {
        printf("%s simSetObjectSel\n",couldNotFind);
        return 0;
    }
    if (simHandleProximitySensor==nullptr)
    {
        printf("%s simHandleProximitySensor\n",couldNotFind);
        return 0;
    }
    if (simReadProximitySensor==nullptr)
    {
        printf("%s simReadProximitySensor\n",couldNotFind);
        return 0;
    }
    if (simHandleDynamics==nullptr)
    {
        printf("%s simHandleDynamics\n",couldNotFind);
        return 0;
    }
    if (simAssociateScriptWithObject==nullptr)
    {
        printf("%s simAssociateScriptWithObject\n",couldNotFind);
        return 0;
    }
    if (simHandleMainScript==nullptr)
    {
        printf("%s simHandleMainScript\n",couldNotFind);
        return 0;
    }
    if (simResetScript==nullptr)
    {
        printf("%s simResetScript\n",couldNotFind);
        return 0;
    }
    if (simAddScript==nullptr)
    {
        printf("%s simAddScript\n",couldNotFind);
        return 0;
    }
    if (simRemoveScript==nullptr)
    {
        printf("%s simRemoveScript\n",couldNotFind);
        return 0;
    }
    if (simRefreshDialogs==nullptr)
    {
        printf("%s simRefreshDialogs\n",couldNotFind);
        return 0;
    }
    if (simResetProximitySensor==nullptr)
    {
        printf("%s simResetProximitySensor\n",couldNotFind);
        return 0;
    }
    if (simCheckProximitySensor==nullptr)
    {
        printf("%s simCheckProximitySensor\n",couldNotFind);
        return 0;
    }
    if (simCheckProximitySensorEx==nullptr)
    {
        printf("%s simCheckProximitySensorEx\n",couldNotFind);
        return 0;
    }
    if (simCheckProximitySensorEx2==nullptr)
    {
        printf("%s simCheckProximitySensorEx2\n",couldNotFind);
        return 0;
    }
    if (simCreateBuffer==nullptr)
    {
        printf("%s simCreateBuffer\n",couldNotFind);
        return 0;
    }
    if (simReleaseBuffer==nullptr)
    {
        printf("%s simReleaseBuffer\n",couldNotFind);
        return 0;
    }
    if (simCheckCollision==nullptr)
    {
        printf("%s simCheckCollision\n",couldNotFind);
        return 0;
    }
    if (simCheckCollisionEx==nullptr)
    {
        printf("%s simCheckCollisionEx\n",couldNotFind);
        return 0;
    }
    if (simCheckDistance==nullptr)
    {
        printf("%s simCheckDistance\n",couldNotFind);
        return 0;
    }
    if (simSetSimulationTimeStep==nullptr)
    {
        printf("%s simSetSimulationTimeStep\n",couldNotFind);
        return 0;
    }
    if (simGetSimulationTimeStep==nullptr)
    {
        printf("%s simGetSimulationTimeStep\n",couldNotFind);
        return 0;
    }
    if (simGetRealTimeSimulation==nullptr)
    {
        printf("%s simGetRealTimeSimulation\n",couldNotFind);
        return 0;
    }
    if (simIsRealTimeSimulationStepNeeded==nullptr)
    {
        printf("%s simIsRealTimeSimulationStepNeeded\n",couldNotFind);
        return 0;
    }
    if (simAdjustRealTimeTimer==nullptr)
    {
        printf("%s simAdjustRealTimeTimer\n",couldNotFind);
        return 0;
    }
    if (simGetSimulationPassesPerRenderingPass==nullptr)
    {
        printf("%s simGetSimulationPassesPerRenderingPass\n",couldNotFind);
        return 0;
    }
    if (simAdvanceSimulationByOneStep==nullptr)
    {
        printf("%s simAdvanceSimulationByOneStep\n",couldNotFind);
        return 0;
    }
    if (simStartSimulation==nullptr)
    {
        printf("%s simStartSimulation\n",couldNotFind);
        return 0;
    }
    if (simStopSimulation==nullptr)
    {
        printf("%s simStopSimulation\n",couldNotFind);
        return 0;
    }
    if (simPauseSimulation==nullptr)
    {
        printf("%s simPauseSimulation\n",couldNotFind);
        return 0;
    }
    if (simGetModuleName==nullptr)
    {
        printf("%s simGetModuleName\n",couldNotFind);
        return 0;
    }
    if (simFloatingViewAdd==nullptr)
    {
        printf("%s simFloatingViewAdd\n",couldNotFind);
        return 0;
    }
    if (simFloatingViewRemove==nullptr)
    {
        printf("%s simFloatingViewRemove\n",couldNotFind);
        return 0;
    }
    if (simAdjustView==nullptr)
    {
        printf("%s simAdjustView\n",couldNotFind);
        return 0;
    }
    if (simSetLastError==nullptr)
    {
        printf("%s simSetLastError\n",couldNotFind);
        return 0;
    }
    if (simHandleGraph==nullptr)
    {
        printf("%s simHandleGraph\n",couldNotFind);
        return 0;
    }
    if (simResetGraph==nullptr)
    {
        printf("%s simResetGraph\n",couldNotFind);
        return 0;
    }
    if (simAddGraphStream==nullptr)
    {
        printf("%s simAddGraphStream\n",couldNotFind);
        return 0;
    }
    if (simDestroyGraphCurve==nullptr)
    {
        printf("%s simDestroyGraphCurve\n",couldNotFind);
        return 0;
    }
    if (simSetGraphStreamTransformation==nullptr)
    {
        printf("%s simSetGraphStreamTransformation\n",couldNotFind);
        return 0;
    }
    if (simDuplicateGraphCurveToStatic==nullptr)
    {
        printf("%s simDuplicateGraphCurveToStatic\n",couldNotFind);
        return 0;
    }
    if (simAddGraphCurve==nullptr)
    {
        printf("%s simAddGraphCurve\n",couldNotFind);
        return 0;
    }
    if (simSetGraphStreamValue==nullptr)
    {
        printf("%s simSetGraphStreamValue\n",couldNotFind);
        return 0;
    }
    if (simSetNavigationMode==nullptr)
    {
        printf("%s simSetNavigationMode\n",couldNotFind);
        return 0;
    }
    if (simGetNavigationMode==nullptr)
    {
        printf("%s simGetNavigationMode\n",couldNotFind);
        return 0;
    }
    if (simSetPage==nullptr)
    {
        printf("%s simSetPage\n",couldNotFind);
        return 0;
    }
    if (simGetPage==nullptr)
    {
        printf("%s simGetPage\n",couldNotFind);
        return 0;
    }
    if (simRegisterScriptCallbackFunction==nullptr)
    {
        printf("%s simRegisterScriptCallbackFunction\n",couldNotFind);
        return 0;
    }
    if (simRegisterScriptVariable==nullptr)
    {
        printf("%s simRegisterScriptVariable\n",couldNotFind);
        return 0;
    }
    if (simRegisterScriptFuncHook==nullptr)
    {
        printf("%s simRegisterScriptFuncHook\n",couldNotFind);
        return 0;
    }
    if (simSetJointTargetVelocity==nullptr)
    {
        printf("%s simSetJointTargetVelocity\n",couldNotFind);
        return 0;
    }
    if (simGetJointTargetVelocity==nullptr)
    {
        printf("%s simGetJointTargetVelocity\n",couldNotFind);
        return 0;
    }
    if (simCopyPasteObjects==nullptr)
    {
        printf("%s simCopyPasteObjects\n",couldNotFind);
        return 0;
    }
    if (simScaleObjects==nullptr)
    {
        printf("%s simScaleObjects\n",couldNotFind);
        return 0;
    }
    if (simAddDrawingObject==nullptr)
    {
        printf("%s simAddDrawingObject\n",couldNotFind);
        return 0;
    }
    if (simRemoveDrawingObject==nullptr)
    {
        printf("%s simRemoveDrawingObject\n",couldNotFind);
        return 0;
    }
    if (simAddDrawingObjectItem==nullptr)
    {
        printf("%s simAddDrawingObjectItem\n",couldNotFind);
        return 0;
    }
    if (simGetObjectSizeFactor==nullptr)
    {
        printf("%s simGetObjectSizeFactor\n",couldNotFind);
        return 0;
    }
    if (simAnnounceSceneContentChange==nullptr)
    {
        printf("%s simAnnounceSceneContentChange\n",couldNotFind);
        return 0;
    }
    if (simSetInt32Signal==nullptr)
    {
        printf("%s simSetInt32Signal\n",couldNotFind);
        return 0;
    }
    if (simGetInt32Signal==nullptr)
    {
        printf("%s simGetInt32Signal\n",couldNotFind);
        return 0;
    }
    if (simClearInt32Signal==nullptr)
    {
        printf("%s simClearInt32Signal\n",couldNotFind);
        return 0;
    }
    if (simSetFloatSignal==nullptr)
    {
        printf("%s simSetFloatSignal\n",couldNotFind);
        return 0;
    }
    if (simGetFloatSignal==nullptr)
    {
        printf("%s simGetFloatSignal\n",couldNotFind);
        return 0;
    }
    if (simClearFloatSignal==nullptr)
    {
        printf("%s simClearFloatSignal\n",couldNotFind);
        return 0;
    }
    if (simSetStringSignal==nullptr)
    {
        printf("%s simSetStringSignal\n",couldNotFind);
        return 0;
    }
    if (simGetStringSignal==nullptr)
    {
        printf("%s simGetStringSignal\n",couldNotFind);
        return 0;
    }
    if (simClearStringSignal==nullptr)
    {
        printf("%s simClearStringSignal\n",couldNotFind);
        return 0;
    }
    if (simGetSignalName==nullptr)
    {
        printf("%s simGetSignalName\n",couldNotFind);
        return 0;
    }
    if (simSetObjectProperty==nullptr)
    {
        printf("%s simSetObjectProperty\n",couldNotFind);
        return 0;
    }
    if (simGetObjectProperty==nullptr)
    {
        printf("%s simGetObjectProperty\n",couldNotFind);
        return 0;
    }
    if (simSetObjectSpecialProperty==nullptr)
    {
        printf("%s simSetObjectSpecialProperty\n",couldNotFind);
        return 0;
    }
    if (simGetObjectSpecialProperty==nullptr)
    {
        printf("%s simGetObjectSpecialProperty\n",couldNotFind);
        return 0;
    }
    if (simReadForceSensor==nullptr)
    {
        printf("%s simReadForceSensor\n",couldNotFind);
        return 0;
    }
    if (simSetLightParameters==nullptr)
    {
        printf("%s simSetLightParameters\n",couldNotFind);
        return 0;
    }
    if (simGetLightParameters==nullptr)
    {
        printf("%s simGetLightParameters\n",couldNotFind);
        return 0;
    }
    if (simGetVelocity==nullptr)
    {
        printf("%s simGetVelocity\n",couldNotFind);
        return 0;
    }
    if (simGetObjectVelocity==nullptr)
    {
        printf("%s simGetObjectVelocity\n",couldNotFind);
        return 0;
    }
    if (simGetJointVelocity==nullptr)
    {
        printf("%s simGetJointVelocity\n",couldNotFind);
        return 0;
    }
    if (simAddForceAndTorque==nullptr)
    {
        printf("%s simAddForceAndTorque\n",couldNotFind);
        return 0;
    }
    if (simAddForce==nullptr)
    {
        printf("%s simAddForce\n",couldNotFind);
        return 0;
    }
    if (simSetExplicitHandling==nullptr)
    {
        printf("%s simSetExplicitHandling\n",couldNotFind);
        return 0;
    }
    if (simGetExplicitHandling==nullptr)
    {
        printf("%s simGetExplicitHandling\n",couldNotFind);
        return 0;
    }
    if (simGetLinkDummy==nullptr)
    {
        printf("%s simGetLinkDummy\n",couldNotFind);
        return 0;
    }
    if (simSetLinkDummy==nullptr)
    {
        printf("%s simSetLinkDummy\n",couldNotFind);
        return 0;
    }
    if (simSetModelProperty==nullptr)
    {
        printf("%s simSetModelProperty\n",couldNotFind);
        return 0;
    }
    if (simGetModelProperty==nullptr)
    {
        printf("%s simGetModelProperty\n",couldNotFind);
        return 0;
    }
    if (simSetObjectColor==nullptr)
    {
        printf("%s simSetObjectColor\n",couldNotFind);
        return 0;
    }
    if (simGetObjectColor==nullptr)
    {
        printf("%s simGetObjectColor\n",couldNotFind);
        return 0;
    }
    if (simSetShapeColor==nullptr)
    {
        printf("%s simSetShapeColor\n",couldNotFind);
        return 0;
    }
    if (simGetShapeColor==nullptr)
    {
        printf("%s simGetShapeColor\n",couldNotFind);
        return 0;
    }
    if (simResetDynamicObject==nullptr)
    {
        printf("%s simResetDynamicObject\n",couldNotFind);
        return 0;
    }
    if (simSetJointMode==nullptr)
    {
        printf("%s simSetJointMode\n",couldNotFind);
        return 0;
    }
    if (simGetJointMode==nullptr)
    {
        printf("%s simGetJointMode\n",couldNotFind);
        return 0;
    }
    if (simSerialOpen==nullptr)
    {
        printf("%s simSerialOpen\n",couldNotFind);
        return 0;
    }
    if (simSerialClose==nullptr)
    {
        printf("%s simSerialClose\n",couldNotFind);
        return 0;
    }
    if (simSerialSend==nullptr)
    {
        printf("%s simSerialSend\n",couldNotFind);
        return 0;
    }
    if (simSerialRead==nullptr)
    {
        printf("%s simSerialRead\n",couldNotFind);
        return 0;
    }
    if (simSerialCheck==nullptr)
    {
        printf("%s simSerialCheck\n",couldNotFind);
        return 0;
    }
    if (simGetContactInfo==nullptr)
    {
        printf("%s simGetContactInfo\n",couldNotFind);
        return 0;
    }
    if (simAuxiliaryConsoleOpen==nullptr)
    {
        printf("%s simAuxiliaryConsoleOpen\n",couldNotFind);
        return 0;
    }
    if (simAuxiliaryConsoleClose==nullptr)
    {
        printf("%s simAuxiliaryConsoleClose\n",couldNotFind);
        return 0;
    }
    if (simAuxiliaryConsoleShow==nullptr)
    {
        printf("%s simAuxiliaryConsoleShow\n",couldNotFind);
        return 0;
    }
    if (simAuxiliaryConsolePrint==nullptr)
    {
        printf("%s simAuxiliaryConsolePrint\n",couldNotFind);
        return 0;
    }
    if (simImportShape==nullptr)
    {
        printf("%s simImportShape\n",couldNotFind);
        return 0;
    }
    if (simImportMesh==nullptr)
    {
        printf("%s simImportMesh\n",couldNotFind);
        return 0;
    }
    if (simExportMesh==nullptr)
    {
        printf("%s simExportMesh\n",couldNotFind);
        return 0;
    }
    if (simCreateShape==nullptr)
    {
        printf("%s simCreateShape\n",couldNotFind);
        return 0;
    }
    if (simCreateMeshShape==nullptr)
    {
        printf("%s simCreateMeshShape\n",couldNotFind);
        return 0;
    }
    if (simCreatePrimitiveShape==nullptr)
    {
        printf("%s simCreatePrimitiveShape\n",couldNotFind);
        return 0;
    }
    if (simCreateHeightfieldShape==nullptr)
    {
        printf("%s simCreateHeightfieldShape\n",couldNotFind);
        return 0;
    }
    if (simGetShapeMesh==nullptr)
    {
        printf("%s simGetShapeMesh\n",couldNotFind);
        return 0;
    }
    if (simCreateJoint==nullptr)
    {
        printf("%s simCreateJoint\n",couldNotFind);
        return 0;
    }
    if (simCreateDummy==nullptr)
    {
        printf("%s simCreateDummy\n",couldNotFind);
        return 0;
    }
    if (simCreateProximitySensor==nullptr)
    {
        printf("%s simCreateProximitySensor\n",couldNotFind);
        return 0;
    }
    if (simCreateVisionSensor==nullptr)
    {
        printf("%s simCreateVisionSensor\n",couldNotFind);
        return 0;
    }
    if (simCreateForceSensor==nullptr)
    {
        printf("%s simCreateForceSensor\n",couldNotFind);
        return 0;
    }
    if (simGetObjectInt32Param==nullptr)
    {
        printf("%s simGetObjectInt32Param\n",couldNotFind);
        return 0;
    }
    if (simSetObjectInt32Param==nullptr)
    {
        printf("%s simSetObjectInt32Param\n",couldNotFind);
        return 0;
    }
    if (simGetObjectFloatParam==nullptr)
    {
        printf("%s simGetObjectFloatParam\n",couldNotFind);
        return 0;
    }
    if (simSetObjectFloatParam==nullptr)
    {
        printf("%s simSetObjectFloatParam\n",couldNotFind);
        return 0;
    }
    if (simGetObjectFloatArrayParam==nullptr)
    {
        printf("%s simGetObjectFloatArrayParam\n",couldNotFind);
        return 0;
    }
    if (simSetObjectFloatArrayParam==nullptr)
    {
        printf("%s simSetObjectFloatArrayParam\n",couldNotFind);
        return 0;
    }
    if (simGetObjectStringParam==nullptr)
    {
        printf("%s simGetObjectStringParam\n",couldNotFind);
        return 0;
    }
    if (simSetObjectStringParam==nullptr)
    {
        printf("%s simSetObjectStringParam\n",couldNotFind);
        return 0;
    }
    if (simGetScriptInt32Param==nullptr)
    {
        printf("%s simGetScriptInt32Param\n",couldNotFind);
        return 0;
    }
    if (simSetScriptInt32Param==nullptr)
    {
        printf("%s simSetScriptInt32Param\n",couldNotFind);
        return 0;
    }
    if (simGetScriptStringParam==nullptr)
    {
        printf("%s simGetScriptStringParam\n",couldNotFind);
        return 0;
    }
    if (simSetScriptStringParam==nullptr)
    {
        printf("%s simSetScriptStringParam\n",couldNotFind);
        return 0;
    }
    if (simSetSimulationPassesPerRenderingPass==nullptr)
    {
        printf("%s simSetSimulationPassesPerRenderingPass\n",couldNotFind);
        return 0;
    }
    if (simGetRotationAxis==nullptr)
    {
        printf("%s simGetRotationAxis\n",couldNotFind);
        return 0;
    }
    if (simRotateAroundAxis==nullptr)
    {
        printf("%s simRotateAroundAxis\n",couldNotFind);
        return 0;
    }
    if (simGetJointForce==nullptr)
    {
        printf("%s simGetJointForce\n",couldNotFind);
        return 0;
    }
    if (simGetJointTargetForce==nullptr)
    {
        printf("%s simGetJointTargetForce\n",couldNotFind);
        return 0;
    }
    if (simSetJointTargetForce==nullptr)
    {
        printf("%s simSetJointTargetForce\n",couldNotFind);
        return 0;
    }
    if (simCameraFitToView==nullptr)
    {
        printf("%s simCameraFitToView\n",couldNotFind);
        return 0;
    }
    if (simPersistentDataWrite==nullptr)
    {
        printf("%s simPersistentDataWrite\n",couldNotFind);
        return 0;
    }
    if (simPersistentDataRead==nullptr)
    {
        printf("%s simPersistentDataRead\n",couldNotFind);
        return 0;
    }
    if (simIsHandle==nullptr)
    {
        printf("%s simIsHandle\n",couldNotFind);
        return 0;
    }
    if (simHandleVisionSensor==nullptr)
    {
        printf("%s simHandleVisionSensor\n",couldNotFind);
        return 0;
    }
    if (simReadVisionSensor==nullptr)
    {
        printf("%s simReadVisionSensor\n",couldNotFind);
        return 0;
    }
    if (simResetVisionSensor==nullptr)
    {
        printf("%s simResetVisionSensor\n",couldNotFind);
        return 0;
    }
    if (simCheckVisionSensor==nullptr)
    {
        printf("%s simCheckVisionSensor\n",couldNotFind);
        return 0;
    }
    if (simCheckVisionSensorEx==nullptr)
    {
        printf("%s simCheckVisionSensorEx\n",couldNotFind);
        return 0;
    }
    if (simGetVisionSensorImg==nullptr)
    {
        printf("%s simGetVisionSensorImg\n",couldNotFind);
        return 0;
    }
    if (simGetVisionSensorRes==nullptr)
    {
        printf("%s simGetVisionSensorRes\n",couldNotFind);
        return 0;
    }
    if (simSetVisionSensorImg==nullptr)
    {
        printf("%s simSetVisionSensorImg\n",couldNotFind);
        return 0;
    }
    if (simGetVisionSensorDepth==nullptr)
    {
        printf("%s simGetVisionSensorDepth\n",couldNotFind);
        return 0;
    }
    if (_simSetVisionSensorDepth==nullptr)
    {
        printf("%s _simSetVisionSensorDepth\n",couldNotFind);
        return 0;
    }
    if (simGetObjectQuaternion==nullptr)
    {
        printf("%s simGetObjectQuaternion\n",couldNotFind);
        return 0;
    }
    if (simSetObjectQuaternion==nullptr)
    {
        printf("%s simSetObjectQuaternion\n",couldNotFind);
        return 0;
    }
    if (simRuckigPos==nullptr)
    {
        printf("%s simRuckigPos\n",couldNotFind);
        return 0;
    }
    if (simRuckigVel==nullptr)
    {
        printf("%s simRuckigVel\n",couldNotFind);
        return 0;
    }
    if (simRuckigStep==nullptr)
    {
        printf("%s simRuckigStep\n",couldNotFind);
        return 0;
    }
    if (simRuckigRemove==nullptr)
    {
        printf("%s simRuckigRemove\n",couldNotFind);
        return 0;
    }
    if (simGroupShapes==nullptr)
    {
        printf("%s simGroupShapes\n",couldNotFind);
        return 0;
    }
    if (simUngroupShape==nullptr)
    {
        printf("%s simUngroupShape\n",couldNotFind);
        return 0;
    }
    if (simConvexDecompose==nullptr)
    {
        printf("%s simConvexDecompose\n",couldNotFind);
        return 0;
    }
    if (simQuitSimulator==nullptr)
    {
        printf("%s simQuitSimulator\n",couldNotFind);
        return 0;
    }
    if (simSetShapeMaterial==nullptr)
    {
        printf("%s simSetShapeMaterial\n",couldNotFind);
        return 0;
    }
    if (simGetTextureId==nullptr)
    {
        printf("%s simGetTextureId\n",couldNotFind);
        return 0;
    }
    if (simReadTexture==nullptr)
    {
        printf("%s simReadTexture\n",couldNotFind);
        return 0;
    }
    if (simWriteTexture==nullptr)
    {
        printf("%s simWriteTexture\n",couldNotFind);
        return 0;
    }
    if (simCreateTexture==nullptr)
    {
        printf("%s simCreateTexture\n",couldNotFind);
        return 0;
    }
    if (simWriteCustomDataBlock==nullptr)
    {
        printf("%s simWriteCustomDataBlock\n",couldNotFind);
        return 0;
    }
    if (simReadCustomDataBlock==nullptr)
    {
        printf("%s simReadCustomDataBlock\n",couldNotFind);
        return 0;
    }
    if (simReadCustomDataBlockTags==nullptr)
    {
        printf("%s simReadCustomDataBlockTags\n",couldNotFind);
        return 0;
    }
    if (simGetShapeGeomInfo==nullptr)
    {
        printf("%s simGetShapeGeomInfo\n",couldNotFind);
        return 0;
    }
    if (simGetObjects==nullptr)
    {
        printf("%s simGetObjects\n",couldNotFind);
        return 0;
    }
    if (simGetObjectsInTree==nullptr)
    {
        printf("%s simGetObjectsInTree\n",couldNotFind);
        return 0;
    }
    if (simScaleObject==nullptr)
    {
        printf("%s simScaleObject\n",couldNotFind);
        return 0;
    }
    if (simSetShapeTexture==nullptr)
    {
        printf("%s simSetShapeTexture\n",couldNotFind);
        return 0;
    }
    if (simGetShapeTextureId==nullptr)
    {
        printf("%s simGetShapeTextureId\n",couldNotFind);
        return 0;
    }
    if (simCreateCollectionEx==nullptr)
    {
        printf("%s simCreateCollectionEx\n",couldNotFind);
        return 0;
    }
    if (simAddItemToCollection==nullptr)
    {
        printf("%s simAddItemToCollection\n",couldNotFind);
        return 0;
    }
    if (simDestroyCollection==nullptr)
    {
        printf("%s simDestroyCollection\n",couldNotFind);
        return 0;
    }
    if (simGetCollectionObjects==nullptr)
    {
        printf("%s simGetCollectionObjects\n",couldNotFind);
        return 0;
    }
    if (simAlignShapeBB==nullptr)
    {
        printf("%s simAlignShapeBB\n",couldNotFind);
        return 0;
    }
    if (simRelocateShapeFrame==nullptr)
    {
        printf("%s simRelocateShapeFrame\n",couldNotFind);
        return 0;
    }
    if (simSaveImage==nullptr)
    {
        printf("%s simSaveImage\n",couldNotFind);
        return 0;
    }
    if (simLoadImage==nullptr)
    {
        printf("%s simLoadImage\n",couldNotFind);
        return 0;
    }
    if (simGetScaledImage==nullptr)
    {
        printf("%s simGetScaledImage\n",couldNotFind);
        return 0;
    }
    if (simTransformImage==nullptr)
    {
        printf("%s simTransformImage\n",couldNotFind);
        return 0;
    }
    if (simGetQHull==nullptr)
    {
        printf("%s simGetQHull\n",couldNotFind);
        return 0;
    }
    if (simGetDecimatedMesh==nullptr)
    {
        printf("%s simGetDecimatedMesh\n",couldNotFind);
        return 0;
    }
    if (simCallScriptFunctionEx==nullptr)
    {
        printf("%s simCallScriptFunctionEx\n",couldNotFind);
        return 0;
    }
    if (simGetExtensionString==nullptr)
    {
        printf("%s simGetExtensionString\n",couldNotFind);
        return 0;
    }
    if (simComputeMassAndInertia==nullptr)
    {
        printf("%s simComputeMassAndInertia\n",couldNotFind);
        return 0;
    }
    if (simCreateStack==nullptr)
    {
        printf("%s simCreateStack\n",couldNotFind);
        return 0;
    }
    if (simReleaseStack==nullptr)
    {
        printf("%s simReleaseStack\n",couldNotFind);
        return 0;
    }
    if (simCopyStack==nullptr)
    {
        printf("%s simCopyStack\n",couldNotFind);
        return 0;
    }
    if (simPushNullOntoStack==nullptr)
    {
        printf("%s simPushNullOntoStack\n",couldNotFind);
        return 0;
    }
    if (simPushBoolOntoStack==nullptr)
    {
        printf("%s simPushBoolOntoStack\n",couldNotFind);
        return 0;
    }
    if (simPushInt32OntoStack==nullptr)
    {
        printf("%s simPushInt32OntoStack\n",couldNotFind);
        return 0;
    }
    if (simPushInt64OntoStack==nullptr)
    {
        printf("%s simPushInt64OntoStack\n",couldNotFind);
        return 0;
    }
    if (simPushFloatOntoStack==nullptr)
    {
        printf("%s simPushFloatOntoStack\n",couldNotFind);
        return 0;
    }
    if (simPushDoubleOntoStack==nullptr)
    {
        printf("%s simPushDoubleOntoStack\n",couldNotFind);
        return 0;
    }
    if (simPushStringOntoStack==nullptr)
    {
        printf("%s simPushStringOntoStack\n",couldNotFind);
        return 0;
    }
    if (simPushUInt8TableOntoStack==nullptr)
    {
        printf("%s simPushUInt8TableOntoStack\n",couldNotFind);
        return 0;
    }
    if (simPushInt32TableOntoStack==nullptr)
    {
        printf("%s simPushInt32TableOntoStack\n",couldNotFind);
        return 0;
    }
    if (simPushInt64TableOntoStack==nullptr)
    {
        printf("%s simPushInt64TableOntoStack\n",couldNotFind);
        return 0;
    }
    if (simPushFloatTableOntoStack==nullptr)
    {
        printf("%s simPushFloatTableOntoStack\n",couldNotFind);
        return 0;
    }
    if (simPushDoubleTableOntoStack==nullptr)
    {
        printf("%s simPushDoubleTableOntoStack\n",couldNotFind);
        return 0;
    }
    if (simPushTableOntoStack==nullptr)
    {
        printf("%s simPushTableOntoStack\n",couldNotFind);
        return 0;
    }
    if (simInsertDataIntoStackTable==nullptr)
    {
        printf("%s simInsertDataIntoStackTable\n",couldNotFind);
        return 0;
    }
    if (simGetStackSize==nullptr)
    {
        printf("%s simGetStackSize\n",couldNotFind);
        return 0;
    }
    if (simPopStackItem==nullptr)
    {
        printf("%s simPopStackItem\n",couldNotFind);
        return 0;
    }
    if (simMoveStackItemToTop==nullptr)
    {
        printf("%s simMoveStackItemToTop\n",couldNotFind);
        return 0;
    }
    if (simIsStackValueNull==nullptr)
    {
        printf("%s simIsStackValueNull\n",couldNotFind);
        return 0;
    }
    if (simGetStackBoolValue==nullptr)
    {
        printf("%s simGetStackBoolValue\n",couldNotFind);
        return 0;
    }
    if (simGetStackInt32Value==nullptr)
    {
        printf("%s simGetStackInt32Value\n",couldNotFind);
        return 0;
    }
    if (simGetStackInt64Value==nullptr)
    {
        printf("%s simGetStackInt64Value\n",couldNotFind);
        return 0;
    }
    if (simGetStackFloatValue==nullptr)
    {
        printf("%s simGetStackFloatValue\n",couldNotFind);
        return 0;
    }
    if (simGetStackDoubleValue==nullptr)
    {
        printf("%s simGetStackDoubleValue\n",couldNotFind);
        return 0;
    }
    if (simGetStackStringValue==nullptr)
    {
        printf("%s simGetStackStringValue\n",couldNotFind);
        return 0;
    }
    if (simGetStackTableInfo==nullptr)
    {
        printf("%s simGetStackTableInfo\n",couldNotFind);
        return 0;
    }
    if (simGetStackUInt8Table==nullptr)
    {
        printf("%s simGetStackUInt8Table\n",couldNotFind);
        return 0;
    }
    if (simGetStackInt32Table==nullptr)
    {
        printf("%s simGetStackInt32Table\n",couldNotFind);
        return 0;
    }
    if (simGetStackInt64Table==nullptr)
    {
        printf("%s simGetStackInt64Table\n",couldNotFind);
        return 0;
    }
    if (simGetStackFloatTable==nullptr)
    {
        printf("%s simGetStackFloatTable\n",couldNotFind);
        return 0;
    }
    if (simGetStackDoubleTable==nullptr)
    {
        printf("%s simGetStackDoubleTable\n",couldNotFind);
        return 0;
    }
    if (simUnfoldStackTable==nullptr)
    {
        printf("%s simUnfoldStackTable\n",couldNotFind);
        return 0;
    }
    if (simDebugStack==nullptr)
    {
        printf("%s simDebugStack\n",couldNotFind);
        return 0;
    }
    if (simGetEngineFloatParam==nullptr)
    {
        printf("%s simGetEngineFloatParam\n",couldNotFind);
        return 0;
    }
    if (simGetEngineInt32Param==nullptr)
    {
        printf("%s simGetEngineInt32Param\n",couldNotFind);
        return 0;
    }
    if (simGetEngineBoolParam==nullptr)
    {
        printf("%s simGetEngineBoolParam\n",couldNotFind);
        return 0;
    }
    if (simSetEngineFloatParam==nullptr)
    {
        printf("%s simSetEngineFloatParam\n",couldNotFind);
        return 0;
    }
    if (simSetEngineInt32Param==nullptr)
    {
        printf("%s simSetEngineInt32Param\n",couldNotFind);
        return 0;
    }
    if (simSetEngineBoolParam==nullptr)
    {
        printf("%s simSetEngineBoolParam\n",couldNotFind);
        return 0;
    }
    if (simCreateOctree==nullptr)
    {
        printf("%s simCreateOctree\n",couldNotFind);
        return 0;
    }
    if (simCreatePointCloud==nullptr)
    {
        printf("%s simCreatePointCloud\n",couldNotFind);
        return 0;
    }
    if (simSetPointCloudOptions==nullptr)
    {
        printf("%s simSetPointCloudOptions\n",couldNotFind);
        return 0;
    }
    if (simGetPointCloudOptions==nullptr)
    {
        printf("%s simGetPointCloudOptions\n",couldNotFind);
        return 0;
    }
    if (simInsertVoxelsIntoOctree==nullptr)
    {
        printf("%s simInsertVoxelsIntoOctree\n",couldNotFind);
        return 0;
    }
    if (simRemoveVoxelsFromOctree==nullptr)
    {
        printf("%s simRemoveVoxelsFromOctree\n",couldNotFind);
        return 0;
    }
    if (simInsertPointsIntoPointCloud==nullptr)
    {
        printf("%s simInsertPointsIntoPointCloud\n",couldNotFind);
        return 0;
    }
    if (simRemovePointsFromPointCloud==nullptr)
    {
        printf("%s simRemovePointsFromPointCloud\n",couldNotFind);
        return 0;
    }
    if (simIntersectPointsWithPointCloud==nullptr)
    {
        printf("%s simIntersectPointsWithPointCloud\n",couldNotFind);
        return 0;
    }
    if (simGetOctreeVoxels==nullptr)
    {
        printf("%s simGetOctreeVoxels\n",couldNotFind);
        return 0;
    }
    if (simGetPointCloudPoints==nullptr)
    {
        printf("%s simGetPointCloudPoints\n",couldNotFind);
        return 0;
    }
    if (simInsertObjectIntoOctree==nullptr)
    {
        printf("%s simInsertObjectIntoOctree\n",couldNotFind);
        return 0;
    }
    if (simSubtractObjectFromOctree==nullptr)
    {
        printf("%s simSubtractObjectFromOctree\n",couldNotFind);
        return 0;
    }
    if (simInsertObjectIntoPointCloud==nullptr)
    {
        printf("%s simInsertObjectIntoPointCloud\n",couldNotFind);
        return 0;
    }
    if (simSubtractObjectFromPointCloud==nullptr)
    {
        printf("%s simSubtractObjectFromPointCloud\n",couldNotFind);
        return 0;
    }
    if (simCheckOctreePointOccupancy==nullptr)
    {
        printf("%s simCheckOctreePointOccupancy\n",couldNotFind);
        return 0;
    }
    if (simOpenTextEditor==nullptr)
    {
        printf("%s simOpenTextEditor\n",couldNotFind);
        return 0;
    }
    if (simPackTable==nullptr)
    {
        printf("%s simPackTable\n",couldNotFind);
        return 0;
    }
    if (simUnpackTable==nullptr)
    {
        printf("%s simUnpackTable\n",couldNotFind);
        return 0;
    }
    if (simSetReferencedHandles==nullptr)
    {
        printf("%s simSetReferencedHandles\n",couldNotFind);
        return 0;
    }
    if (simGetReferencedHandles==nullptr)
    {
        printf("%s simGetReferencedHandles\n",couldNotFind);
        return 0;
    }
    if (simGetShapeViz==nullptr)
    {
        printf("%s simGetShapeViz\n",couldNotFind);
        return 0;
    }
    if (simExecuteScriptString==nullptr)
    {
        printf("%s simExecuteScriptString\n",couldNotFind);
        return 0;
    }
    if (simGetApiFunc==nullptr)
    {
        printf("%s simGetApiFunc\n",couldNotFind);
        return 0;
    }
    if (simGetApiInfo==nullptr)
    {
        printf("%s simGetApiInfo\n",couldNotFind);
        return 0;
    }
    if (simSetModuleInfo==nullptr)
    {
        printf("%s simSetModuleInfo\n",couldNotFind);
        return 0;
    }
    if (simGetModuleInfo==nullptr)
    {
        printf("%s simGetModuleInfo\n",couldNotFind);
        return 0;
    }
    if (simIsDeprecated==nullptr)
    {
        printf("%s simIsDeprecated\n",couldNotFind);
        return 0;
    }
    if (simGetPersistentDataTags==nullptr)
    {
        printf("%s simGetPersistentDataTags\n",couldNotFind);
        return 0;
    }
    if (simEventNotification==nullptr)
    {
        printf("%s simEventNotification\n",couldNotFind);
        return 0;
    }
    if (simApplyTexture==nullptr)
    {
        printf("%s simApplyTexture\n",couldNotFind);
        return 0;
    }
    if (simSetJointDependency==nullptr)
    {
        printf("%s simSetJointDependency\n",couldNotFind);
        return 0;
    }
    if (simGetJointDependency==nullptr)
    {
        printf("%s simGetJointDependency\n",couldNotFind);
        return 0;
    }
    if (simGetShapeMass==nullptr)
    {
        printf("%s simGetShapeMass\n",couldNotFind);
        return 0;
    }
    if (simSetShapeMass==nullptr)
    {
        printf("%s simSetShapeMass\n",couldNotFind);
        return 0;
    }
    if (simGetShapeInertia==nullptr)
    {
        printf("%s simGetShapeInertia\n",couldNotFind);
        return 0;
    }
    if (simSetShapeInertia==nullptr)
    {
        printf("%s simSetShapeInertia\n",couldNotFind);
        return 0;
    }
    if (simIsDynamicallyEnabled==nullptr)
    {
        printf("%s simIsDynamicallyEnabled\n",couldNotFind);
        return 0;
    }
    if (simGenerateShapeFromPath==nullptr)
    {
        printf("%s simGenerateShapeFromPath\n",couldNotFind);
        return 0;
    }
    if (simGetClosestPosOnPath==nullptr)
    {
        printf("%s simGetClosestPosOnPath\n",couldNotFind);
        return 0;
    }
    if (simInitScript==nullptr)
    {
        printf("%s simInitScript\n",couldNotFind);
        return 0;
    }
    if (simModuleEntry==nullptr)
    {
        printf("%s simModuleEntry\n",couldNotFind);
        return 0;
    }
    if (simCheckExecAuthorization==nullptr)
    {
        printf("%s simCheckExecAuthorization\n",couldNotFind);
        return 0;
    }
    if (simExtCallScriptFunction==nullptr)
    {
        printf("%s simExtCallScriptFunction\n",couldNotFind);
        return 0;
    }
    if (simExtLaunchUIThread==nullptr)
    {
        printf("%s simExtLaunchUIThread\n",couldNotFind);
        return 0;
    }
    if (simExtCanInitSimThread==nullptr)
    {
        printf("%s simExtCanInitSimThread\n",couldNotFind);
        return 0;
    }
    if (simExtSimThreadInit==nullptr)
    {
        printf("%s simExtSimThreadInit\n",couldNotFind);
        return 0;
    }
    if (simExtSimThreadDestroy==nullptr)
    {
        printf("%s simExtSimThreadDestroy\n",couldNotFind);
        return 0;
    }
    if (simExtPostExitRequest==nullptr)
    {
        printf("%s simExtPostExitRequest\n",couldNotFind);
        return 0;
    }
    if (simExtGetExitRequest==nullptr)
    {
        printf("%s simExtGetExitRequest\n",couldNotFind);
        return 0;
    }
    if (simExtStep==nullptr)
    {
        printf("%s simExtStep\n",couldNotFind);
        return 0;
    }
    if (_simSetDynamicSimulationIconCode==nullptr)
    {
        printf("%s _simSetDynamicSimulationIconCode\n",couldNotFind);
        return 0;
    }
    if (_simSetDynamicObjectFlagForVisualization==nullptr)
    {
        printf("%s _simSetDynamicObjectFlagForVisualization\n",couldNotFind);
        return 0;
    }
    if (_simGetObjectListSize==nullptr)
    {
        printf("%s _simGetObjectListSize\n",couldNotFind);
        return 0;
    }
    if (_simGetObjectFromIndex==nullptr)
    {
        printf("%s _simGetObjectFromIndex\n",couldNotFind);
        return 0;
    }
    if (_simGetObjectID==nullptr)
    {
        printf("%s _simGetObjectID\n",couldNotFind);
        return 0;
    }
    if (_simGetObjectType==nullptr)
    {
        printf("%s _simGetObjectType\n",couldNotFind);
        return 0;
    }
    if (_simGetObjectChildren==nullptr)
    {
        printf("%s _simGetObjectChildren\n",couldNotFind);
        return 0;
    }
    if (_simGetParentObject==nullptr)
    {
        printf("%s _simGetParentObject\n",couldNotFind);
        return 0;
    }
    if (_simGetObject==nullptr)
    {
        printf("%s _simGetObject\n",couldNotFind);
        return 0;
    }
    if (_simGetIkGroupObject==nullptr)
    {
        printf("%s _simGetIkGroupObject\n",couldNotFind);
        return 0;
    }
    if (_simMpHandleIkGroupObject==nullptr)
    {
        printf("%s _simMpHandleIkGroupObject\n",couldNotFind);
        return 0;
    }
    if (_simGetObjectLocalTransformation==nullptr)
    {
        printf("%s _simGetObjectLocalTransformation\n",couldNotFind);
        return 0;
    }
    if (_simSetObjectLocalTransformation==nullptr)
    {
        printf("%s _simSetObjectLocalTransformation\n",couldNotFind);
        return 0;
    }
    if (_simDynReportObjectCumulativeTransformation==nullptr)
    {
        printf("%s _simDynReportObjectCumulativeTransformation\n",couldNotFind);
        return 0;
    }
    if (_simSetObjectCumulativeTransformation==nullptr)
    {
        printf("%s _simSetObjectCumulativeTransformation\n",couldNotFind);
        return 0;
    }
    if (_simGetObjectCumulativeTransformation==nullptr)
    {
        printf("%s _simGetObjectCumulativeTransformation\n",couldNotFind);
        return 0;
    }
    if (_simIsShapeDynamicallyStatic==nullptr)
    {
        printf("%s _simIsShapeDynamicallyStatic\n",couldNotFind);
        return 0;
    }
    if (_simGetTreeDynamicProperty==nullptr)
    {
        printf("%s _simGetTreeDynamicProperty\n",couldNotFind);
        return 0;
    }
    if (_simGetDummyLinkType==nullptr)
    {
        printf("%s _simGetDummyLinkType\n",couldNotFind);
        return 0;
    }
    if (_simGetJointMode==nullptr)
    {
        printf("%s _simGetJointMode\n",couldNotFind);
        return 0;
    }
    if (_simIsJointInHybridOperation==nullptr)
    {
        printf("%s _simIsJointInHybridOperation\n",couldNotFind);
        return 0;
    }
    if (_simDisableDynamicTreeForManipulation==nullptr)
    {
        printf("%s _simDisableDynamicTreeForManipulation\n",couldNotFind);
        return 0;
    }
    if (_simIsShapeDynamicallyRespondable==nullptr)
    {
        printf("%s _simIsShapeDynamicallyRespondable\n",couldNotFind);
        return 0;
    }
    if (_simGetDynamicCollisionMask==nullptr)
    {
        printf("%s _simGetDynamicCollisionMask\n",couldNotFind);
        return 0;
    }
    if (_simGetLastParentForLocalGlobalCollidable==nullptr)
    {
        printf("%s _simGetLastParentForLocalGlobalCollidable\n",couldNotFind);
        return 0;
    }
    if (_simSetJointVelocity==nullptr)
    {
        printf("%s _simSetJointVelocity\n",couldNotFind);
        return 0;
    }
    if (_simSetJointPosition==nullptr)
    {
        printf("%s _simSetJointPosition\n",couldNotFind);
        return 0;
    }
    if (_simGetJointPosition==nullptr)
    {
        printf("%s _simGetJointPosition\n",couldNotFind);
        return 0;
    }
    if (_simSetDynamicMotorPositionControlTargetPosition==nullptr)
    {
        printf("%s _simSetDynamicMotorPositionControlTargetPosition\n",couldNotFind);
        return 0;
    }
    if (_simGetInitialDynamicVelocity==nullptr)
    {
        printf("%s _simGetInitialDynamicVelocity\n",couldNotFind);
        return 0;
    }
    if (_simSetInitialDynamicVelocity==nullptr)
    {
        printf("%s _simSetInitialDynamicVelocity\n",couldNotFind);
        return 0;
    }
    if (_simGetInitialDynamicAngVelocity==nullptr)
    {
        printf("%s _simGetInitialDynamicAngVelocity\n",couldNotFind);
        return 0;
    }
    if (_simSetInitialDynamicAngVelocity==nullptr)
    {
        printf("%s _simSetInitialDynamicAngVelocity\n",couldNotFind);
        return 0;
    }
    if (_simGetStartSleeping==nullptr)
    {
        printf("%s _simGetStartSleeping\n",couldNotFind);
        return 0;
    }
    if (_simGetWasPutToSleepOnce==nullptr)
    {
        printf("%s _simGetWasPutToSleepOnce\n",couldNotFind);
        return 0;
    }
    if (_simGetDynamicsFullRefreshFlag==nullptr)
    {
        printf("%s _simGetDynamicsFullRefreshFlag\n",couldNotFind);
        return 0;
    }
    if (_simSetDynamicsFullRefreshFlag==nullptr)
    {
        printf("%s _simSetDynamicsFullRefreshFlag\n",couldNotFind);
        return 0;
    }
    if (_simSetShapeDynamicVelocity==nullptr)
    {
        printf("%s _simSetShapeDynamicVelocity\n",couldNotFind);
        return 0;
    }
    if (_simGetAdditionalForceAndTorque==nullptr)
    {
        printf("%s _simGetAdditionalForceAndTorque\n",couldNotFind);
        return 0;
    }
    if (_simClearAdditionalForceAndTorque==nullptr)
    {
        printf("%s _simClearAdditionalForceAndTorque\n",couldNotFind);
        return 0;
    }
    if (_simGetJointPositionInterval==nullptr)
    {
        printf("%s _simGetJointPositionInterval\n",couldNotFind);
        return 0;
    }
    if (_simGetJointType==nullptr)
    {
        printf("%s _simGetJointType\n",couldNotFind);
        return 0;
    }
    if (_simGetDynamicMotorTargetPosition==nullptr)
    {
        printf("%s _simGetDynamicMotorTargetPosition\n",couldNotFind);
        return 0;
    }
    if (_simGetDynamicMotorTargetVelocity==nullptr)
    {
        printf("%s _simGetDynamicMotorTargetVelocity\n",couldNotFind);
        return 0;
    }
    if (_simGetDynamicMotorMaxForce==nullptr)
    {
        printf("%s _simGetDynamicMotorMaxForce\n",couldNotFind);
        return 0;
    }
    if (_simGetDynamicMotorUpperLimitVelocity==nullptr)
    {
        printf("%s _simGetDynamicMotorUpperLimitVelocity\n",couldNotFind);
        return 0;
    }
    if (_simSetDynamicMotorReflectedPositionFromDynamicEngine==nullptr)
    {
        printf("%s _simSetDynamicMotorReflectedPositionFromDynamicEngine\n",couldNotFind);
        return 0;
    }
    if (_simSetJointSphericalTransformation==nullptr)
    {
        printf("%s _simSetJointSphericalTransformation\n",couldNotFind);
        return 0;
    }
    if (_simAddForceSensorCumulativeForcesAndTorques==nullptr)
    {
        printf("%s _simAddForceSensorCumulativeForcesAndTorques\n",couldNotFind);
        return 0;
    }
    if (_simAddJointCumulativeForcesOrTorques==nullptr)
    {
        printf("%s _simAddJointCumulativeForcesOrTorques\n",couldNotFind);
        return 0;
    }
    if (_simGetGeomWrapFromGeomProxy==nullptr)
    {
        printf("%s _simGetGeomWrapFromGeomProxy\n",couldNotFind);
        return 0;
    }
    if (_simGetMass==nullptr)
    {
        printf("%s _simGetMass\n",couldNotFind);
        return 0;
    }
    if (_simGetLocalInertiaInfo==nullptr)
    {
        printf("%s _simGetLocalInertiaInfo\n",couldNotFind);
        return 0;
    }
    if (_simGetPurePrimitiveType==nullptr)
    {
        printf("%s _simGetPurePrimitiveType\n",couldNotFind);
        return 0;
    }
    if (_simIsGeomWrapGeometric==nullptr)
    {
        printf("%s _simIsGeomWrapGeometric\n",couldNotFind);
        return 0;
    }
    if (_simIsGeomWrapConvex==nullptr)
    {
        printf("%s _simIsGeomWrapConvex\n",couldNotFind);
        return 0;
    }
    if (_simGetGeometricCount==nullptr)
    {
        printf("%s _simGetGeometricCount\n",couldNotFind);
        return 0;
    }
    if (_simGetAllGeometrics==nullptr)
    {
        printf("%s _simGetAllGeometrics\n",couldNotFind);
        return 0;
    }
    if (_simGetPurePrimitiveSizes==nullptr)
    {
        printf("%s _simGetPurePrimitiveSizes\n",couldNotFind);
        return 0;
    }
    if (_simMakeDynamicAnnouncement==nullptr)
    {
        printf("%s _simMakeDynamicAnnouncement\n",couldNotFind);
        return 0;
    }
    if (_simGetVerticesLocalFrame==nullptr)
    {
        printf("%s _simGetVerticesLocalFrame\n",couldNotFind);
        return 0;
    }
    if (_simGetHeightfieldData==nullptr)
    {
        printf("%s _simGetHeightfieldData\n",couldNotFind);
        return 0;
    }
    if (_simGetCumulativeMeshes==nullptr)
    {
        printf("%s _simGetCumulativeMeshes\n",couldNotFind);
        return 0;
    }
    if (_simGetGravity==nullptr)
    {
        printf("%s _simGetGravity\n",couldNotFind);
        return 0;
    }
    if (_simGetTimeDiffInMs==nullptr)
    {
        printf("%s _simGetTimeDiffInMs\n",couldNotFind);
        return 0;
    }
    if (_simDoEntitiesCollide==nullptr)
    {
        printf("%s _simDoEntitiesCollide\n",couldNotFind);
        return 0;
    }
    if (_simGetDistanceBetweenEntitiesIfSmaller==nullptr)
    {
        printf("%s _simGetDistanceBetweenEntitiesIfSmaller\n",couldNotFind);
        return 0;
    }
    if (_simHandleJointControl==nullptr)
    {
        printf("%s _simHandleJointControl\n",couldNotFind);
        return 0;
    }
    if (_simHandleCustomContact==nullptr)
    {
        printf("%s _simHandleCustomContact\n",couldNotFind);
        return 0;
    }
    if (_simGetPureHollowScaling==nullptr)
    {
        printf("%s _simGetPureHollowScaling\n",couldNotFind);
        return 0;
    }
    if (_simGetJointDynCtrlMode==nullptr)
    {
        printf("%s _simGetJointDynCtrlMode\n",couldNotFind);
        return 0;
    }
    if (_simDynCallback==nullptr)
    {
        printf("%s _simDynCallback\n",couldNotFind);
        return 0;
    }
    return 1;
}

#endif // SIM_LIBRARY
