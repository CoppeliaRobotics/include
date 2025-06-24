#include "simLib.h"
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#if defined (__linux) || defined (__APPLE__)
    #include <dlfcn.h>
#endif

#ifndef SIM_LIBRARY

SIM_API_SYMBOL(ptrSimAddLog) SIM_API_SYMBOL(_addLog) = nullptr;

int SIM_API_SYMBOL(simAddLog)(const char* pluginName,int verbosityLevel,const char* logMsg)
{
    if (SIM_API_SYMBOL(_addLog) == nullptr)
    {
        std::string m("[");
        if (pluginName!=nullptr)
        {
            if (strcmp(pluginName,"CoppeliaSimClient")!=0)
                m+="simExt";
            m+=pluginName;
        }
        else
            m+="unknown plugin";
        m+="]   ";
        m+=logMsg;
        printf("%s\n",m.c_str());
        return(1);
    }
    return(SIM_API_SYMBOL(_addLog)(pluginName,verbosityLevel,logMsg));
}

SIM_API_SYMBOL(ptrSimSetBoolProperty) SIM_API_SYMBOL(simSetBoolProperty) = nullptr;
SIM_API_SYMBOL(ptrSimGetBoolProperty) SIM_API_SYMBOL(simGetBoolProperty) = nullptr;
SIM_API_SYMBOL(ptrSimSetIntProperty) SIM_API_SYMBOL(simSetIntProperty) = nullptr;
SIM_API_SYMBOL(ptrSimGetIntProperty) SIM_API_SYMBOL(simGetIntProperty) = nullptr;
SIM_API_SYMBOL(ptrSimSetLongProperty) SIM_API_SYMBOL(simSetLongProperty) = nullptr;
SIM_API_SYMBOL(ptrSimGetLongProperty) SIM_API_SYMBOL(simGetLongProperty) = nullptr;
SIM_API_SYMBOL(ptrSimSetFloatProperty) SIM_API_SYMBOL(simSetFloatProperty) = nullptr;
SIM_API_SYMBOL(ptrSimGetFloatProperty) SIM_API_SYMBOL(simGetFloatProperty) = nullptr;
SIM_API_SYMBOL(ptrSimSetStringProperty) SIM_API_SYMBOL(simSetStringProperty) = nullptr;
SIM_API_SYMBOL(ptrSimGetStringProperty) SIM_API_SYMBOL(simGetStringProperty) = nullptr;
SIM_API_SYMBOL(ptrSimSetTableProperty) SIM_API_SYMBOL(simSetTableProperty) = nullptr;
SIM_API_SYMBOL(ptrSimGetTableProperty) SIM_API_SYMBOL(simGetTableProperty) = nullptr;
SIM_API_SYMBOL(ptrSimSetBufferProperty) SIM_API_SYMBOL(simSetBufferProperty) = nullptr;
SIM_API_SYMBOL(ptrSimGetBufferProperty) SIM_API_SYMBOL(simGetBufferProperty) = nullptr;
SIM_API_SYMBOL(ptrSimSetIntArray2Property) SIM_API_SYMBOL(simSetIntArray2Property) = nullptr;
SIM_API_SYMBOL(ptrSimGetIntArray2Property) SIM_API_SYMBOL(simGetIntArray2Property) = nullptr;
SIM_API_SYMBOL(ptrSimSetVector2Property) SIM_API_SYMBOL(simSetVector2Property) = nullptr;
SIM_API_SYMBOL(ptrSimGetVector2Property) SIM_API_SYMBOL(simGetVector2Property) = nullptr;
SIM_API_SYMBOL(ptrSimSetVector3Property) SIM_API_SYMBOL(simSetVector3Property) = nullptr;
SIM_API_SYMBOL(ptrSimGetVector3Property) SIM_API_SYMBOL(simGetVector3Property) = nullptr;
SIM_API_SYMBOL(ptrSimSetQuaternionProperty) SIM_API_SYMBOL(simSetQuaternionProperty) = nullptr;
SIM_API_SYMBOL(ptrSimGetQuaternionProperty) SIM_API_SYMBOL(simGetQuaternionProperty) = nullptr;
SIM_API_SYMBOL(ptrSimSetPoseProperty) SIM_API_SYMBOL(simSetPoseProperty) = nullptr;
SIM_API_SYMBOL(ptrSimGetPoseProperty) SIM_API_SYMBOL(simGetPoseProperty) = nullptr;
SIM_API_SYMBOL(ptrSimSetColorProperty) SIM_API_SYMBOL(simSetColorProperty) = nullptr;
SIM_API_SYMBOL(ptrSimGetColorProperty) SIM_API_SYMBOL(simGetColorProperty) = nullptr;
SIM_API_SYMBOL(ptrSimSetFloatArrayProperty) SIM_API_SYMBOL(simSetFloatArrayProperty) = nullptr;
SIM_API_SYMBOL(ptrSimGetFloatArrayProperty) SIM_API_SYMBOL(simGetFloatArrayProperty) = nullptr;
SIM_API_SYMBOL(ptrSimSetIntArrayProperty) SIM_API_SYMBOL(simSetIntArrayProperty) = nullptr;
SIM_API_SYMBOL(ptrSimGetIntArrayProperty) SIM_API_SYMBOL(simGetIntArrayProperty) = nullptr;
SIM_API_SYMBOL(ptrSimRemoveProperty) SIM_API_SYMBOL(simRemoveProperty) = nullptr;
SIM_API_SYMBOL(ptrSimGetPropertyName) SIM_API_SYMBOL(simGetPropertyName) = nullptr;
SIM_API_SYMBOL(ptrSimGetPropertyInfo) SIM_API_SYMBOL(simGetPropertyInfo) = nullptr;

SIM_API_SYMBOL(ptrSimRegCallback) SIM_API_SYMBOL(simRegCallback) = nullptr;
SIM_API_SYMBOL(ptrSimRunGui) SIM_API_SYMBOL(simRunGui) = nullptr;
SIM_API_SYMBOL(ptrSimInitialize) SIM_API_SYMBOL(simInitialize) = nullptr;
SIM_API_SYMBOL(ptrSimDeinitialize) SIM_API_SYMBOL(simDeinitialize) = nullptr;
SIM_API_SYMBOL(ptrSimPostExitRequest) SIM_API_SYMBOL(simPostExitRequest) = nullptr;
SIM_API_SYMBOL(ptrSimGetExitRequest) SIM_API_SYMBOL(simGetExitRequest) = nullptr;
SIM_API_SYMBOL(ptrSimLoop) SIM_API_SYMBOL(simLoop) = nullptr;
SIM_API_SYMBOL(ptrSimTest) SIM_API_SYMBOL(simTest) = nullptr;
SIM_API_SYMBOL(ptrSimGetSimulatorMessage) SIM_API_SYMBOL(simGetSimulatorMessage) = nullptr;
SIM_API_SYMBOL(ptrSimGetMainWindow) SIM_API_SYMBOL(simGetMainWindow) = nullptr;
SIM_API_SYMBOL(ptrSimGetLastError) SIM_API_SYMBOL(simGetLastError) = nullptr;
SIM_API_SYMBOL(ptrSimGetLastInfo) SIM_API_SYMBOL(simGetLastInfo) = nullptr;
SIM_API_SYMBOL(ptrSimGetObject) SIM_API_SYMBOL(simGetObject) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectUid) SIM_API_SYMBOL(simGetObjectUid) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectFromUid) SIM_API_SYMBOL(simGetObjectFromUid) = nullptr;
SIM_API_SYMBOL(ptrSimGetScriptHandleEx) SIM_API_SYMBOL(simGetScriptHandleEx) = nullptr;
SIM_API_SYMBOL(ptrSimRemoveObjects) SIM_API_SYMBOL(simRemoveObjects) = nullptr;
SIM_API_SYMBOL(ptrSimRemoveModel) SIM_API_SYMBOL(simRemoveModel) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectAlias) SIM_API_SYMBOL(simGetObjectAlias) = nullptr;
SIM_API_SYMBOL(ptrSimSetObjectAlias) SIM_API_SYMBOL(simSetObjectAlias) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectMatrix) SIM_API_SYMBOL(simGetObjectMatrix) = nullptr;
SIM_API_SYMBOL(ptrSimSetObjectMatrix) SIM_API_SYMBOL(simSetObjectMatrix) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectPose) SIM_API_SYMBOL(simGetObjectPose) = nullptr;
SIM_API_SYMBOL(ptrSimSetObjectPose) SIM_API_SYMBOL(simSetObjectPose) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectPosition) SIM_API_SYMBOL(simGetObjectPosition) = nullptr;
SIM_API_SYMBOL(ptrSimSetObjectPosition) SIM_API_SYMBOL(simSetObjectPosition) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectOrientation) SIM_API_SYMBOL(simGetObjectOrientation) = nullptr;
SIM_API_SYMBOL(ptrSimSetObjectOrientation) SIM_API_SYMBOL(simSetObjectOrientation) = nullptr;
SIM_API_SYMBOL(ptrSimGetJointPosition) SIM_API_SYMBOL(simGetJointPosition) = nullptr;
SIM_API_SYMBOL(ptrSimSetJointPosition) SIM_API_SYMBOL(simSetJointPosition) = nullptr;
SIM_API_SYMBOL(ptrSimSetJointTargetPosition) SIM_API_SYMBOL(simSetJointTargetPosition) = nullptr;
SIM_API_SYMBOL(ptrSimGetJointTargetPosition) SIM_API_SYMBOL(simGetJointTargetPosition) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectChildPose) SIM_API_SYMBOL(simGetObjectChildPose) = nullptr;
SIM_API_SYMBOL(ptrSimSetObjectChildPose) SIM_API_SYMBOL(simSetObjectChildPose) = nullptr;
SIM_API_SYMBOL(ptrSimGetJointInterval) SIM_API_SYMBOL(simGetJointInterval) = nullptr;
SIM_API_SYMBOL(ptrSimSetJointInterval) SIM_API_SYMBOL(simSetJointInterval) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectParent) SIM_API_SYMBOL(simGetObjectParent) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectChild) SIM_API_SYMBOL(simGetObjectChild) = nullptr;
SIM_API_SYMBOL(ptrSimSetObjectParent) SIM_API_SYMBOL(simSetObjectParent) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectType) SIM_API_SYMBOL(simGetObjectType) = nullptr;
SIM_API_SYMBOL(ptrSimGetJointType) SIM_API_SYMBOL(simGetJointType) = nullptr;
SIM_API_SYMBOL(ptrSimBuildIdentityMatrix) SIM_API_SYMBOL(simBuildIdentityMatrix) = nullptr;
SIM_API_SYMBOL(ptrSimBuildMatrix) SIM_API_SYMBOL(simBuildMatrix) = nullptr;
SIM_API_SYMBOL(ptrSimBuildPose) SIM_API_SYMBOL(simBuildPose) = nullptr;
SIM_API_SYMBOL(ptrSimGetEulerAnglesFromMatrix) SIM_API_SYMBOL(simGetEulerAnglesFromMatrix) = nullptr;
SIM_API_SYMBOL(ptrSimInvertMatrix) SIM_API_SYMBOL(simInvertMatrix) = nullptr;
SIM_API_SYMBOL(ptrSimMultiplyMatrices) SIM_API_SYMBOL(simMultiplyMatrices) = nullptr;
SIM_API_SYMBOL(ptrSimMultiplyPoses) SIM_API_SYMBOL(simMultiplyPoses) = nullptr;
SIM_API_SYMBOL(ptrSimInvertPose) SIM_API_SYMBOL(simInvertPose) = nullptr;
SIM_API_SYMBOL(ptrSimInterpolatePoses) SIM_API_SYMBOL(simInterpolatePoses) = nullptr;
SIM_API_SYMBOL(ptrSimPoseToMatrix) SIM_API_SYMBOL(simPoseToMatrix) = nullptr;
SIM_API_SYMBOL(ptrSimMatrixToPose) SIM_API_SYMBOL(simMatrixToPose) = nullptr;
SIM_API_SYMBOL(ptrSimInterpolateMatrices) SIM_API_SYMBOL(simInterpolateMatrices) = nullptr;
SIM_API_SYMBOL(ptrSimTransformVector) SIM_API_SYMBOL(simTransformVector) = nullptr;
SIM_API_SYMBOL(ptrSimReservedCommand) SIM_API_SYMBOL(simReservedCommand) = nullptr;
SIM_API_SYMBOL(ptrSimGetSimulationTime) SIM_API_SYMBOL(simGetSimulationTime) = nullptr;
SIM_API_SYMBOL(ptrSimGetSimulationState) SIM_API_SYMBOL(simGetSimulationState) = nullptr;
SIM_API_SYMBOL(ptrSimGetSystemTime) SIM_API_SYMBOL(simGetSystemTime) = nullptr;
SIM_API_SYMBOL(ptrSimLoadScene) SIM_API_SYMBOL(simLoadScene) = nullptr;
SIM_API_SYMBOL(ptrSimCloseScene) SIM_API_SYMBOL(simCloseScene) = nullptr;
SIM_API_SYMBOL(ptrSimSaveScene) SIM_API_SYMBOL(simSaveScene) = nullptr;
SIM_API_SYMBOL(ptrSimLoadModel) SIM_API_SYMBOL(simLoadModel) = nullptr;
SIM_API_SYMBOL(ptrSimSaveModel) SIM_API_SYMBOL(simSaveModel) = nullptr;
SIM_API_SYMBOL(ptrSimDoesFileExist) SIM_API_SYMBOL(simDoesFileExist) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectSel) SIM_API_SYMBOL(simGetObjectSel) = nullptr;
SIM_API_SYMBOL(ptrSimSetObjectSel) SIM_API_SYMBOL(simSetObjectSel) = nullptr;
SIM_API_SYMBOL(ptrSimHandleProximitySensor) SIM_API_SYMBOL(simHandleProximitySensor) = nullptr;
SIM_API_SYMBOL(ptrSimReadProximitySensor) SIM_API_SYMBOL(simReadProximitySensor) = nullptr;
SIM_API_SYMBOL(ptrSimHandleDynamics) SIM_API_SYMBOL(simHandleDynamics) = nullptr;
SIM_API_SYMBOL(ptrSimResetScript) SIM_API_SYMBOL(simResetScript) = nullptr;
SIM_API_SYMBOL(ptrSimRefreshDialogs) SIM_API_SYMBOL(simRefreshDialogs) = nullptr;
SIM_API_SYMBOL(ptrSimResetProximitySensor) SIM_API_SYMBOL(simResetProximitySensor) = nullptr;
SIM_API_SYMBOL(ptrSimCheckProximitySensor) SIM_API_SYMBOL(simCheckProximitySensor) = nullptr;
SIM_API_SYMBOL(ptrSimCheckProximitySensorEx) SIM_API_SYMBOL(simCheckProximitySensorEx) = nullptr;
SIM_API_SYMBOL(ptrSimCheckProximitySensorEx2) SIM_API_SYMBOL(simCheckProximitySensorEx2) = nullptr;
SIM_API_SYMBOL(ptrSimCreateBuffer) SIM_API_SYMBOL(simCreateBuffer) = nullptr;
SIM_API_SYMBOL(ptrSimReleaseBuffer) SIM_API_SYMBOL(simReleaseBuffer) = nullptr;
SIM_API_SYMBOL(ptrSimCheckCollision) SIM_API_SYMBOL(simCheckCollision) = nullptr;
SIM_API_SYMBOL(ptrSimCheckCollisionEx) SIM_API_SYMBOL(simCheckCollisionEx) = nullptr;
SIM_API_SYMBOL(ptrSimCheckDistance) SIM_API_SYMBOL(simCheckDistance) = nullptr;
SIM_API_SYMBOL(ptrSimSetSimulationTimeStep) SIM_API_SYMBOL(simSetSimulationTimeStep) = nullptr;
SIM_API_SYMBOL(ptrSimGetSimulationTimeStep) SIM_API_SYMBOL(simGetSimulationTimeStep) = nullptr;
SIM_API_SYMBOL(ptrSimGetRealTimeSimulation) SIM_API_SYMBOL(simGetRealTimeSimulation) = nullptr;
SIM_API_SYMBOL(ptrSimStartSimulation) SIM_API_SYMBOL(simStartSimulation) = nullptr;
SIM_API_SYMBOL(ptrSimStopSimulation) SIM_API_SYMBOL(simStopSimulation) = nullptr;
SIM_API_SYMBOL(ptrSimPauseSimulation) SIM_API_SYMBOL(simPauseSimulation) = nullptr;
SIM_API_SYMBOL(ptrSimFloatingViewAdd) SIM_API_SYMBOL(simFloatingViewAdd) = nullptr;
SIM_API_SYMBOL(ptrSimFloatingViewRemove) SIM_API_SYMBOL(simFloatingViewRemove) = nullptr;
SIM_API_SYMBOL(ptrSimAdjustView) SIM_API_SYMBOL(simAdjustView) = nullptr;
SIM_API_SYMBOL(ptrSimSetLastError) SIM_API_SYMBOL(simSetLastError) = nullptr;
SIM_API_SYMBOL(ptrSimHandleGraph) SIM_API_SYMBOL(simHandleGraph) = nullptr;
SIM_API_SYMBOL(ptrSimResetGraph) SIM_API_SYMBOL(simResetGraph) = nullptr;
SIM_API_SYMBOL(ptrSimAddGraphStream) SIM_API_SYMBOL(simAddGraphStream) = nullptr;
SIM_API_SYMBOL(ptrSimDestroyGraphCurve) SIM_API_SYMBOL(simDestroyGraphCurve) = nullptr;
SIM_API_SYMBOL(ptrSimSetGraphStreamTransformation) SIM_API_SYMBOL(simSetGraphStreamTransformation) = nullptr;
SIM_API_SYMBOL(ptrSimDuplicateGraphCurveToStatic) SIM_API_SYMBOL(simDuplicateGraphCurveToStatic) = nullptr;
SIM_API_SYMBOL(ptrSimAddGraphCurve) SIM_API_SYMBOL(simAddGraphCurve) = nullptr;
SIM_API_SYMBOL(ptrSimSetGraphStreamValue) SIM_API_SYMBOL(simSetGraphStreamValue) = nullptr;
SIM_API_SYMBOL(ptrSimSetNavigationMode) SIM_API_SYMBOL(simSetNavigationMode) = nullptr;
SIM_API_SYMBOL(ptrSimGetNavigationMode) SIM_API_SYMBOL(simGetNavigationMode) = nullptr;
SIM_API_SYMBOL(ptrSimSetPage) SIM_API_SYMBOL(simSetPage) = nullptr;
SIM_API_SYMBOL(ptrSimGetPage) SIM_API_SYMBOL(simGetPage) = nullptr;
SIM_API_SYMBOL(ptrSimRegisterScriptCallbackFunction) SIM_API_SYMBOL(simRegisterScriptCallbackFunction) = nullptr;
SIM_API_SYMBOL(ptrSimRegisterScriptVariable) SIM_API_SYMBOL(simRegisterScriptVariable) = nullptr;
SIM_API_SYMBOL(ptrSimRegisterScriptFuncHook) SIM_API_SYMBOL(simRegisterScriptFuncHook) = nullptr;
SIM_API_SYMBOL(ptrSimSetJointTargetVelocity) SIM_API_SYMBOL(simSetJointTargetVelocity) = nullptr;
SIM_API_SYMBOL(ptrSimGetJointTargetVelocity) SIM_API_SYMBOL(simGetJointTargetVelocity) = nullptr;
SIM_API_SYMBOL(ptrSimCopyPasteObjects) SIM_API_SYMBOL(simCopyPasteObjects) = nullptr;
SIM_API_SYMBOL(ptrSimScaleObjects) SIM_API_SYMBOL(simScaleObjects) = nullptr;
SIM_API_SYMBOL(ptrSimAddDrawingObject) SIM_API_SYMBOL(simAddDrawingObject) = nullptr;
SIM_API_SYMBOL(ptrSimRemoveDrawingObject) SIM_API_SYMBOL(simRemoveDrawingObject) = nullptr;
SIM_API_SYMBOL(ptrSimAddDrawingObjectItem) SIM_API_SYMBOL(simAddDrawingObjectItem) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectSizeFactor) SIM_API_SYMBOL(simGetObjectSizeFactor) = nullptr;
SIM_API_SYMBOL(ptrSimAnnounceSceneContentChange) SIM_API_SYMBOL(simAnnounceSceneContentChange) = nullptr;
SIM_API_SYMBOL(ptrSimReadForceSensor) SIM_API_SYMBOL(simReadForceSensor) = nullptr;
SIM_API_SYMBOL(ptrSimGetVelocity) SIM_API_SYMBOL(simGetVelocity) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectVelocity) SIM_API_SYMBOL(simGetObjectVelocity) = nullptr;
SIM_API_SYMBOL(ptrSimGetJointVelocity) SIM_API_SYMBOL(simGetJointVelocity) = nullptr;
SIM_API_SYMBOL(ptrSimAddForceAndTorque) SIM_API_SYMBOL(simAddForceAndTorque) = nullptr;
SIM_API_SYMBOL(ptrSimAddForce) SIM_API_SYMBOL(simAddForce) = nullptr;
SIM_API_SYMBOL(ptrSimSetExplicitHandling) SIM_API_SYMBOL(simSetExplicitHandling) = nullptr;
SIM_API_SYMBOL(ptrSimGetExplicitHandling) SIM_API_SYMBOL(simGetExplicitHandling) = nullptr;
SIM_API_SYMBOL(ptrSimGetLinkDummy) SIM_API_SYMBOL(simGetLinkDummy) = nullptr;
SIM_API_SYMBOL(ptrSimSetLinkDummy) SIM_API_SYMBOL(simSetLinkDummy) = nullptr;
SIM_API_SYMBOL(ptrSimSetObjectColor) SIM_API_SYMBOL(simSetObjectColor) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectColor) SIM_API_SYMBOL(simGetObjectColor) = nullptr;
SIM_API_SYMBOL(ptrSimSetShapeColor) SIM_API_SYMBOL(simSetShapeColor) = nullptr;
SIM_API_SYMBOL(ptrSimGetShapeColor) SIM_API_SYMBOL(simGetShapeColor) = nullptr;
SIM_API_SYMBOL(ptrSimResetDynamicObject) SIM_API_SYMBOL(simResetDynamicObject) = nullptr;
SIM_API_SYMBOL(ptrSimSetJointMode) SIM_API_SYMBOL(simSetJointMode) = nullptr;
SIM_API_SYMBOL(ptrSimGetJointMode) SIM_API_SYMBOL(simGetJointMode) = nullptr;
SIM_API_SYMBOL(ptrSimSerialOpen) SIM_API_SYMBOL(simSerialOpen) = nullptr;
SIM_API_SYMBOL(ptrSimSerialClose) SIM_API_SYMBOL(simSerialClose) = nullptr;
SIM_API_SYMBOL(ptrSimSerialSend) SIM_API_SYMBOL(simSerialSend) = nullptr;
SIM_API_SYMBOL(ptrSimSerialRead) SIM_API_SYMBOL(simSerialRead) = nullptr;
SIM_API_SYMBOL(ptrSimSerialCheck) SIM_API_SYMBOL(simSerialCheck) = nullptr;
SIM_API_SYMBOL(ptrSimGetContactInfo) SIM_API_SYMBOL(simGetContactInfo) = nullptr;
SIM_API_SYMBOL(ptrSimAuxiliaryConsoleOpen) SIM_API_SYMBOL(simAuxiliaryConsoleOpen) = nullptr;
SIM_API_SYMBOL(ptrSimAuxiliaryConsoleClose) SIM_API_SYMBOL(simAuxiliaryConsoleClose) = nullptr;
SIM_API_SYMBOL(ptrSimAuxiliaryConsoleShow) SIM_API_SYMBOL(simAuxiliaryConsoleShow) = nullptr;
SIM_API_SYMBOL(ptrSimAuxiliaryConsolePrint) SIM_API_SYMBOL(simAuxiliaryConsolePrint) = nullptr;
SIM_API_SYMBOL(ptrSimImportShape) SIM_API_SYMBOL(simImportShape) = nullptr;
SIM_API_SYMBOL(ptrSimImportMesh) SIM_API_SYMBOL(simImportMesh) = nullptr;
SIM_API_SYMBOL(ptrSimExportMesh) SIM_API_SYMBOL(simExportMesh) = nullptr;
SIM_API_SYMBOL(ptrSimCreateShape) SIM_API_SYMBOL(simCreateShape) = nullptr;
SIM_API_SYMBOL(ptrSimCreateMeshShape) SIM_API_SYMBOL(simCreateMeshShape) = nullptr;
SIM_API_SYMBOL(ptrSimCreatePrimitiveShape) SIM_API_SYMBOL(simCreatePrimitiveShape) = nullptr;
SIM_API_SYMBOL(ptrSimCreateHeightfieldShape) SIM_API_SYMBOL(simCreateHeightfieldShape) = nullptr;
SIM_API_SYMBOL(ptrSimGetShapeMesh) SIM_API_SYMBOL(simGetShapeMesh) = nullptr;
SIM_API_SYMBOL(ptrSimCreateJoint) SIM_API_SYMBOL(simCreateJoint) = nullptr;
SIM_API_SYMBOL(ptrSimCreateDummy) SIM_API_SYMBOL(simCreateDummy) = nullptr;
SIM_API_SYMBOL(ptrSimCreateScript) SIM_API_SYMBOL(simCreateScript) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectHierarchyOrder) SIM_API_SYMBOL(simGetObjectHierarchyOrder) = nullptr;
SIM_API_SYMBOL(ptrSimSetObjectHierarchyOrder) SIM_API_SYMBOL(simSetObjectHierarchyOrder) = nullptr;
SIM_API_SYMBOL(ptrSimCreateProximitySensor) SIM_API_SYMBOL(simCreateProximitySensor) = nullptr;
SIM_API_SYMBOL(ptrSimCreateForceSensor) SIM_API_SYMBOL(simCreateForceSensor) = nullptr;
SIM_API_SYMBOL(ptrSimCreateVisionSensor) SIM_API_SYMBOL(simCreateVisionSensor) = nullptr;
SIM_API_SYMBOL(ptrSimGetRotationAxis) SIM_API_SYMBOL(simGetRotationAxis) = nullptr;
SIM_API_SYMBOL(ptrSimRotateAroundAxis) SIM_API_SYMBOL(simRotateAroundAxis) = nullptr;
SIM_API_SYMBOL(ptrSimGetJointForce) SIM_API_SYMBOL(simGetJointForce) = nullptr;
SIM_API_SYMBOL(ptrSimGetJointTargetForce) SIM_API_SYMBOL(simGetJointTargetForce) = nullptr;
SIM_API_SYMBOL(ptrSimSetJointTargetForce) SIM_API_SYMBOL(simSetJointTargetForce) = nullptr;
SIM_API_SYMBOL(ptrSimCameraFitToView) SIM_API_SYMBOL(simCameraFitToView) = nullptr;
SIM_API_SYMBOL(ptrSimIsHandle) SIM_API_SYMBOL(simIsHandle) = nullptr;
SIM_API_SYMBOL(ptrSimHandleVisionSensor) SIM_API_SYMBOL(simHandleVisionSensor) = nullptr;
SIM_API_SYMBOL(ptrSimReadVisionSensor) SIM_API_SYMBOL(simReadVisionSensor) = nullptr;
SIM_API_SYMBOL(ptrSimResetVisionSensor) SIM_API_SYMBOL(simResetVisionSensor) = nullptr;
SIM_API_SYMBOL(ptrSimCheckVisionSensor) SIM_API_SYMBOL(simCheckVisionSensor) = nullptr;
SIM_API_SYMBOL(ptrSimCheckVisionSensorEx) SIM_API_SYMBOL(simCheckVisionSensorEx) = nullptr;
SIM_API_SYMBOL(ptrSimGetVisionSensorImg) SIM_API_SYMBOL(simGetVisionSensorImg) = nullptr;
SIM_API_SYMBOL(ptrSimSetVisionSensorImg) SIM_API_SYMBOL(simSetVisionSensorImg) = nullptr;
SIM_API_SYMBOL(ptrSimGetVisionSensorDepth) SIM_API_SYMBOL(simGetVisionSensorDepth) = nullptr;
SIM_API_SYMBOL(ptrSimGetVisionSensorRes) SIM_API_SYMBOL(simGetVisionSensorRes) = nullptr;
SIM_API_SYMBOL(ptr_simSetVisionSensorDepth) SIM_API_SYMBOL(_simSetVisionSensorDepth) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectQuaternion) SIM_API_SYMBOL(simGetObjectQuaternion) = nullptr;
SIM_API_SYMBOL(ptrSimSetObjectQuaternion) SIM_API_SYMBOL(simSetObjectQuaternion) = nullptr;
SIM_API_SYMBOL(ptrSimRuckigPos) SIM_API_SYMBOL(simRuckigPos) = nullptr;
SIM_API_SYMBOL(ptrSimRuckigVel) SIM_API_SYMBOL(simRuckigVel) = nullptr;
SIM_API_SYMBOL(ptrSimRuckigStep) SIM_API_SYMBOL(simRuckigStep) = nullptr;
SIM_API_SYMBOL(ptrSimRuckigRemove) SIM_API_SYMBOL(simRuckigRemove) = nullptr;
SIM_API_SYMBOL(ptrSimGroupShapes) SIM_API_SYMBOL(simGroupShapes) = nullptr;
SIM_API_SYMBOL(ptrSimUngroupShape) SIM_API_SYMBOL(simUngroupShape) = nullptr;
SIM_API_SYMBOL(ptrSimConvexDecompose) SIM_API_SYMBOL(simConvexDecompose) = nullptr;
SIM_API_SYMBOL(ptrSimQuitSimulator) SIM_API_SYMBOL(simQuitSimulator) = nullptr;
SIM_API_SYMBOL(ptrSimSetShapeMaterial) SIM_API_SYMBOL(simSetShapeMaterial) = nullptr;
SIM_API_SYMBOL(ptrSimGetTextureId) SIM_API_SYMBOL(simGetTextureId) = nullptr;
SIM_API_SYMBOL(ptrSimReadTexture) SIM_API_SYMBOL(simReadTexture) = nullptr;
SIM_API_SYMBOL(ptrSimWriteTexture) SIM_API_SYMBOL(simWriteTexture) = nullptr;
SIM_API_SYMBOL(ptrSimCreateTexture) SIM_API_SYMBOL(simCreateTexture) = nullptr;
SIM_API_SYMBOL(ptrSimGetShapeGeomInfo) SIM_API_SYMBOL(simGetShapeGeomInfo) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjects) SIM_API_SYMBOL(simGetObjects) = nullptr;
SIM_API_SYMBOL(ptrSimGetObjectsInTree) SIM_API_SYMBOL(simGetObjectsInTree) = nullptr;
SIM_API_SYMBOL(ptrSimScaleObject) SIM_API_SYMBOL(simScaleObject) = nullptr;
SIM_API_SYMBOL(ptrSimSetShapeTexture) SIM_API_SYMBOL(simSetShapeTexture) = nullptr;
SIM_API_SYMBOL(ptrSimGetShapeTextureId) SIM_API_SYMBOL(simGetShapeTextureId) = nullptr;
SIM_API_SYMBOL(ptrSimCreateCollectionEx) SIM_API_SYMBOL(simCreateCollectionEx) = nullptr;
SIM_API_SYMBOL(ptrSimAddItemToCollection) SIM_API_SYMBOL(simAddItemToCollection) = nullptr;
SIM_API_SYMBOL(ptrSimDestroyCollection) SIM_API_SYMBOL(simDestroyCollection) = nullptr;
SIM_API_SYMBOL(ptrSimGetCollectionObjects) SIM_API_SYMBOL(simGetCollectionObjects) = nullptr;
SIM_API_SYMBOL(ptrSimAlignShapeBB) SIM_API_SYMBOL(simAlignShapeBB) = nullptr;
SIM_API_SYMBOL(ptrSimRelocateShapeFrame) SIM_API_SYMBOL(simRelocateShapeFrame) = nullptr;

SIM_API_SYMBOL(ptrSimSaveImage) SIM_API_SYMBOL(simSaveImage) = nullptr;
SIM_API_SYMBOL(ptrSimLoadImage) SIM_API_SYMBOL(simLoadImage) = nullptr;
SIM_API_SYMBOL(ptrSimGetScaledImage) SIM_API_SYMBOL(simGetScaledImage) = nullptr;
SIM_API_SYMBOL(ptrSimTransformImage) SIM_API_SYMBOL(simTransformImage) = nullptr;
SIM_API_SYMBOL(ptrSimGetQHull) SIM_API_SYMBOL(simGetQHull) = nullptr;
SIM_API_SYMBOL(ptrSimGetDecimatedMesh) SIM_API_SYMBOL(simGetDecimatedMesh) = nullptr;
SIM_API_SYMBOL(ptrSimCallScriptFunctionEx) SIM_API_SYMBOL(simCallScriptFunctionEx) = nullptr;
SIM_API_SYMBOL(ptrSimGetExtensionString) SIM_API_SYMBOL(simGetExtensionString) = nullptr;
SIM_API_SYMBOL(ptrSimComputeMassAndInertia) SIM_API_SYMBOL(simComputeMassAndInertia) = nullptr;
SIM_API_SYMBOL(ptrSimCreateStack) SIM_API_SYMBOL(simCreateStack) = nullptr;
SIM_API_SYMBOL(ptrSimReleaseStack) SIM_API_SYMBOL(simReleaseStack) = nullptr;
SIM_API_SYMBOL(ptrSimCopyStack) SIM_API_SYMBOL(simCopyStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushNullOntoStack) SIM_API_SYMBOL(simPushNullOntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushBoolOntoStack) SIM_API_SYMBOL(simPushBoolOntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushInt32OntoStack) SIM_API_SYMBOL(simPushInt32OntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushInt64OntoStack) SIM_API_SYMBOL(simPushInt64OntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushFloatOntoStack) SIM_API_SYMBOL(simPushFloatOntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushDoubleOntoStack) SIM_API_SYMBOL(simPushDoubleOntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushTextOntoStack) SIM_API_SYMBOL(simPushTextOntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushStringOntoStack) SIM_API_SYMBOL(simPushStringOntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushBufferOntoStack) SIM_API_SYMBOL(simPushBufferOntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushUInt8TableOntoStack) SIM_API_SYMBOL(simPushUInt8TableOntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushInt32TableOntoStack) SIM_API_SYMBOL(simPushInt32TableOntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushInt64TableOntoStack) SIM_API_SYMBOL(simPushInt64TableOntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushFloatTableOntoStack) SIM_API_SYMBOL(simPushFloatTableOntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushDoubleTableOntoStack) SIM_API_SYMBOL(simPushDoubleTableOntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimPushTableOntoStack) SIM_API_SYMBOL(simPushTableOntoStack) = nullptr;
SIM_API_SYMBOL(ptrSimInsertDataIntoStackTable) SIM_API_SYMBOL(simInsertDataIntoStackTable) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackSize) SIM_API_SYMBOL(simGetStackSize) = nullptr;
SIM_API_SYMBOL(ptrSimPopStackItem) SIM_API_SYMBOL(simPopStackItem) = nullptr;
SIM_API_SYMBOL(ptrSimMoveStackItemToTop) SIM_API_SYMBOL(simMoveStackItemToTop) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackItemType) SIM_API_SYMBOL(simGetStackItemType) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackStringType) SIM_API_SYMBOL(simGetStackStringType) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackBoolValue) SIM_API_SYMBOL(simGetStackBoolValue) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackInt32Value) SIM_API_SYMBOL(simGetStackInt32Value) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackInt64Value) SIM_API_SYMBOL(simGetStackInt64Value) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackFloatValue) SIM_API_SYMBOL(simGetStackFloatValue) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackDoubleValue) SIM_API_SYMBOL(simGetStackDoubleValue) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackStringValue) SIM_API_SYMBOL(simGetStackStringValue) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackTableInfo) SIM_API_SYMBOL(simGetStackTableInfo) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackUInt8Table) SIM_API_SYMBOL(simGetStackUInt8Table) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackInt32Table) SIM_API_SYMBOL(simGetStackInt32Table) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackInt64Table) SIM_API_SYMBOL(simGetStackInt64Table) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackFloatTable) SIM_API_SYMBOL(simGetStackFloatTable) = nullptr;
SIM_API_SYMBOL(ptrSimGetStackDoubleTable) SIM_API_SYMBOL(simGetStackDoubleTable) = nullptr;
SIM_API_SYMBOL(ptrSimUnfoldStackTable) SIM_API_SYMBOL(simUnfoldStackTable) = nullptr;
SIM_API_SYMBOL(ptrSimDebugStack) SIM_API_SYMBOL(simDebugStack) = nullptr;
SIM_API_SYMBOL(ptrSimCreateOctree) SIM_API_SYMBOL(simCreateOctree) = nullptr;
SIM_API_SYMBOL(ptrSimCreatePointCloud) SIM_API_SYMBOL(simCreatePointCloud) = nullptr;
SIM_API_SYMBOL(ptrSimSetPointCloudOptions) SIM_API_SYMBOL(simSetPointCloudOptions) = nullptr;
SIM_API_SYMBOL(ptrSimGetPointCloudOptions) SIM_API_SYMBOL(simGetPointCloudOptions) = nullptr;
SIM_API_SYMBOL(ptrSimInsertVoxelsIntoOctree) SIM_API_SYMBOL(simInsertVoxelsIntoOctree) = nullptr;
SIM_API_SYMBOL(ptrSimRemoveVoxelsFromOctree) SIM_API_SYMBOL(simRemoveVoxelsFromOctree) = nullptr;
SIM_API_SYMBOL(ptrSimInsertPointsIntoPointCloud) SIM_API_SYMBOL(simInsertPointsIntoPointCloud) = nullptr;
SIM_API_SYMBOL(ptrSimRemovePointsFromPointCloud) SIM_API_SYMBOL(simRemovePointsFromPointCloud) = nullptr;
SIM_API_SYMBOL(ptrSimIntersectPointsWithPointCloud) SIM_API_SYMBOL(simIntersectPointsWithPointCloud) = nullptr;
SIM_API_SYMBOL(ptrSimGetOctreeVoxels) SIM_API_SYMBOL(simGetOctreeVoxels) = nullptr;
SIM_API_SYMBOL(ptrSimGetPointCloudPoints) SIM_API_SYMBOL(simGetPointCloudPoints) = nullptr;
SIM_API_SYMBOL(ptrSimInsertObjectIntoOctree) SIM_API_SYMBOL(simInsertObjectIntoOctree) = nullptr;
SIM_API_SYMBOL(ptrSimSubtractObjectFromOctree) SIM_API_SYMBOL(simSubtractObjectFromOctree) = nullptr;
SIM_API_SYMBOL(ptrSimInsertObjectIntoPointCloud) SIM_API_SYMBOL(simInsertObjectIntoPointCloud) = nullptr;
SIM_API_SYMBOL(ptrSimSubtractObjectFromPointCloud) SIM_API_SYMBOL(simSubtractObjectFromPointCloud) = nullptr;
SIM_API_SYMBOL(ptrSimCheckOctreePointOccupancy) SIM_API_SYMBOL(simCheckOctreePointOccupancy) = nullptr;
SIM_API_SYMBOL(ptrSimOpenTextEditor) SIM_API_SYMBOL(simOpenTextEditor) = nullptr;
SIM_API_SYMBOL(ptrSimPackTable) SIM_API_SYMBOL(simPackTable) = nullptr;
SIM_API_SYMBOL(ptrSimUnpackTable) SIM_API_SYMBOL(simUnpackTable) = nullptr;
SIM_API_SYMBOL(ptrSimSetReferencedHandles) SIM_API_SYMBOL(simSetReferencedHandles) = nullptr;
SIM_API_SYMBOL(ptrSimGetReferencedHandles) SIM_API_SYMBOL(simGetReferencedHandles) = nullptr;
SIM_API_SYMBOL(ptrSimGetShapeViz) SIM_API_SYMBOL(simGetShapeViz) = nullptr;
SIM_API_SYMBOL(ptrSimExecuteScriptString) SIM_API_SYMBOL(simExecuteScriptString) = nullptr;
SIM_API_SYMBOL(ptrSimGetApiFunc) SIM_API_SYMBOL(simGetApiFunc) = nullptr;
SIM_API_SYMBOL(ptrSimGetApiInfo) SIM_API_SYMBOL(simGetApiInfo) = nullptr;
SIM_API_SYMBOL(ptrSimGetPluginName) SIM_API_SYMBOL(simGetPluginName) = nullptr;
SIM_API_SYMBOL(ptrSimSetPluginInfo) SIM_API_SYMBOL(simSetPluginInfo) = nullptr;
SIM_API_SYMBOL(ptrSimGetPluginInfo) SIM_API_SYMBOL(simGetPluginInfo) = nullptr;
SIM_API_SYMBOL(ptrSimEventNotification) SIM_API_SYMBOL(simEventNotification) = nullptr;
SIM_API_SYMBOL(ptrSimApplyTexture) SIM_API_SYMBOL(simApplyTexture) = nullptr;
SIM_API_SYMBOL(ptrSimSetJointDependency) SIM_API_SYMBOL(simSetJointDependency) = nullptr;
SIM_API_SYMBOL(ptrSimGetJointDependency) SIM_API_SYMBOL(simGetJointDependency) = nullptr;
SIM_API_SYMBOL(ptrSimGetShapeMass) SIM_API_SYMBOL(simGetShapeMass) = nullptr;
SIM_API_SYMBOL(ptrSimSetShapeMass) SIM_API_SYMBOL(simSetShapeMass) = nullptr;
SIM_API_SYMBOL(ptrSimGetShapeInertia) SIM_API_SYMBOL(simGetShapeInertia) = nullptr;
SIM_API_SYMBOL(ptrSimSetShapeInertia) SIM_API_SYMBOL(simSetShapeInertia) = nullptr;
SIM_API_SYMBOL(ptrSimIsDynamicallyEnabled) SIM_API_SYMBOL(simIsDynamicallyEnabled) = nullptr;
SIM_API_SYMBOL(ptrSimGenerateShapeFromPath) SIM_API_SYMBOL(simGenerateShapeFromPath) = nullptr;
SIM_API_SYMBOL(ptrSimGetClosestPosOnPath) SIM_API_SYMBOL(simGetClosestPosOnPath) = nullptr;
SIM_API_SYMBOL(ptrSimInitScript) SIM_API_SYMBOL(simInitScript) = nullptr;
SIM_API_SYMBOL(ptrSimModuleEntry) SIM_API_SYMBOL(simModuleEntry) = nullptr;
SIM_API_SYMBOL(ptrSimCheckExecAuthorization) SIM_API_SYMBOL(simCheckExecAuthorization) = nullptr;
SIM_API_SYMBOL(ptr_simSetDynamicSimulationIconCode) SIM_API_SYMBOL(_simSetDynamicSimulationIconCode) = nullptr;
SIM_API_SYMBOL(ptr_simSetDynamicObjectFlagForVisualization) SIM_API_SYMBOL(_simSetDynamicObjectFlagForVisualization) = nullptr;
SIM_API_SYMBOL(ptr_simGetObjectListSize) SIM_API_SYMBOL(_simGetObjectListSize) = nullptr;
SIM_API_SYMBOL(ptr_simGetObjectFromIndex) SIM_API_SYMBOL(_simGetObjectFromIndex) = nullptr;
SIM_API_SYMBOL(ptr_simGetObjectID) SIM_API_SYMBOL(_simGetObjectID) = nullptr;
SIM_API_SYMBOL(ptr_simGetObjectType) SIM_API_SYMBOL(_simGetObjectType) = nullptr;
SIM_API_SYMBOL(ptr_simGetObjectChildren) SIM_API_SYMBOL(_simGetObjectChildren) = nullptr;
SIM_API_SYMBOL(ptr_simGetParentObject) SIM_API_SYMBOL(_simGetParentObject) = nullptr;
SIM_API_SYMBOL(ptr_simGetObject) SIM_API_SYMBOL(_simGetObject) = nullptr;
SIM_API_SYMBOL(ptr_simGetIkGroupObject) SIM_API_SYMBOL(_simGetIkGroupObject) = nullptr;
SIM_API_SYMBOL(ptr_simMpHandleIkGroupObject) SIM_API_SYMBOL(_simMpHandleIkGroupObject) = nullptr;
SIM_API_SYMBOL(ptr_simGetObjectLocalTransformation) SIM_API_SYMBOL(_simGetObjectLocalTransformation) = nullptr;
SIM_API_SYMBOL(ptr_simSetObjectLocalTransformation) SIM_API_SYMBOL(_simSetObjectLocalTransformation) = nullptr;
SIM_API_SYMBOL(ptr_simDynReportObjectCumulativeTransformation) SIM_API_SYMBOL(_simDynReportObjectCumulativeTransformation) = nullptr;
SIM_API_SYMBOL(ptr_simSetObjectCumulativeTransformation) SIM_API_SYMBOL(_simSetObjectCumulativeTransformation) = nullptr;
SIM_API_SYMBOL(ptr_simGetObjectCumulativeTransformation) SIM_API_SYMBOL(_simGetObjectCumulativeTransformation) = nullptr;
SIM_API_SYMBOL(ptr_simIsShapeDynamicallyStatic) SIM_API_SYMBOL(_simIsShapeDynamicallyStatic) = nullptr;
SIM_API_SYMBOL(ptr_simGetTreeDynamicProperty) SIM_API_SYMBOL(_simGetTreeDynamicProperty) = nullptr;
SIM_API_SYMBOL(ptr_simGetDummyLinkType) SIM_API_SYMBOL(_simGetDummyLinkType) = nullptr;
SIM_API_SYMBOL(ptr_simGetJointMode) SIM_API_SYMBOL(_simGetJointMode) = nullptr;
SIM_API_SYMBOL(ptr_simIsJointInHybridOperation) SIM_API_SYMBOL(_simIsJointInHybridOperation) = nullptr;
SIM_API_SYMBOL(ptr_simDisableDynamicTreeForManipulation) SIM_API_SYMBOL(_simDisableDynamicTreeForManipulation) = nullptr;
SIM_API_SYMBOL(ptr_simIsShapeDynamicallyRespondable) SIM_API_SYMBOL(_simIsShapeDynamicallyRespondable) = nullptr;
SIM_API_SYMBOL(ptr_simGetDynamicCollisionMask) SIM_API_SYMBOL(_simGetDynamicCollisionMask) = nullptr;
SIM_API_SYMBOL(ptr_simGetLastParentForLocalGlobalCollidable) SIM_API_SYMBOL(_simGetLastParentForLocalGlobalCollidable) = nullptr;
SIM_API_SYMBOL(ptr_simSetJointVelocity) SIM_API_SYMBOL(_simSetJointVelocity) = nullptr;
SIM_API_SYMBOL(ptr_simSetJointPosition) SIM_API_SYMBOL(_simSetJointPosition) = nullptr;
SIM_API_SYMBOL(ptr_simGetJointPosition) SIM_API_SYMBOL(_simGetJointPosition) = nullptr;
SIM_API_SYMBOL(ptr_simSetDynamicMotorPositionControlTargetPosition) SIM_API_SYMBOL(_simSetDynamicMotorPositionControlTargetPosition) = nullptr;
SIM_API_SYMBOL(ptr_simGetInitialDynamicVelocity) SIM_API_SYMBOL(_simGetInitialDynamicVelocity) = nullptr;
SIM_API_SYMBOL(ptr_simSetInitialDynamicVelocity) SIM_API_SYMBOL(_simSetInitialDynamicVelocity) = nullptr;
SIM_API_SYMBOL(ptr_simGetInitialDynamicAngVelocity) SIM_API_SYMBOL(_simGetInitialDynamicAngVelocity) = nullptr;
SIM_API_SYMBOL(ptr_simSetInitialDynamicAngVelocity) SIM_API_SYMBOL(_simSetInitialDynamicAngVelocity) = nullptr;
SIM_API_SYMBOL(ptr_simGetStartSleeping) SIM_API_SYMBOL(_simGetStartSleeping) = nullptr;
SIM_API_SYMBOL(ptr_simGetWasPutToSleepOnce) SIM_API_SYMBOL(_simGetWasPutToSleepOnce) = nullptr;
SIM_API_SYMBOL(ptr_simGetDynamicsFullRefreshFlag) SIM_API_SYMBOL(_simGetDynamicsFullRefreshFlag) = nullptr;
SIM_API_SYMBOL(ptr_simSetDynamicsFullRefreshFlag) SIM_API_SYMBOL(_simSetDynamicsFullRefreshFlag) = nullptr;
SIM_API_SYMBOL(ptr_simSetShapeDynamicVelocity) SIM_API_SYMBOL(_simSetShapeDynamicVelocity) = nullptr;
SIM_API_SYMBOL(ptr_simGetAdditionalForceAndTorque) SIM_API_SYMBOL(_simGetAdditionalForceAndTorque) = nullptr;
SIM_API_SYMBOL(ptr_simClearAdditionalForceAndTorque) SIM_API_SYMBOL(_simClearAdditionalForceAndTorque) = nullptr;
SIM_API_SYMBOL(ptr_simGetJointPositionInterval) SIM_API_SYMBOL(_simGetJointPositionInterval) = nullptr;
SIM_API_SYMBOL(ptr_simGetJointType) SIM_API_SYMBOL(_simGetJointType) = nullptr;
SIM_API_SYMBOL(ptr_simGetDynamicMotorTargetPosition) SIM_API_SYMBOL(_simGetDynamicMotorTargetPosition) = nullptr;
SIM_API_SYMBOL(ptr_simGetDynamicMotorTargetVelocity) SIM_API_SYMBOL(_simGetDynamicMotorTargetVelocity) = nullptr;
SIM_API_SYMBOL(ptr_simGetDynamicMotorMaxForce) SIM_API_SYMBOL(_simGetDynamicMotorMaxForce) = nullptr;
SIM_API_SYMBOL(ptr_simGetDynamicMotorUpperLimitVelocity) SIM_API_SYMBOL(_simGetDynamicMotorUpperLimitVelocity) = nullptr;
SIM_API_SYMBOL(ptr_simSetDynamicMotorReflectedPositionFromDynamicEngine) SIM_API_SYMBOL(_simSetDynamicMotorReflectedPositionFromDynamicEngine) = nullptr;
SIM_API_SYMBOL(ptr_simSetJointSphericalTransformation) SIM_API_SYMBOL(_simSetJointSphericalTransformation) = nullptr;
SIM_API_SYMBOL(ptr_simAddForceSensorCumulativeForcesAndTorques) SIM_API_SYMBOL(_simAddForceSensorCumulativeForcesAndTorques) = nullptr;
SIM_API_SYMBOL(ptr_simAddJointCumulativeForcesOrTorques) SIM_API_SYMBOL(_simAddJointCumulativeForcesOrTorques) = nullptr;
SIM_API_SYMBOL(ptr_simGetGeomWrapFromGeomProxy) SIM_API_SYMBOL(_simGetGeomWrapFromGeomProxy) = nullptr;
SIM_API_SYMBOL(ptr_simGetMass) SIM_API_SYMBOL(_simGetMass) = nullptr;
SIM_API_SYMBOL(ptr_simGetLocalInertiaInfo) SIM_API_SYMBOL(_simGetLocalInertiaInfo) = nullptr;
SIM_API_SYMBOL(ptr_simGetPurePrimitiveType) SIM_API_SYMBOL(_simGetPurePrimitiveType) = nullptr;
SIM_API_SYMBOL(ptr_simIsGeomWrapGeometric) SIM_API_SYMBOL(_simIsGeomWrapGeometric) = nullptr;
SIM_API_SYMBOL(ptr_simIsGeomWrapConvex) SIM_API_SYMBOL(_simIsGeomWrapConvex) = nullptr;
SIM_API_SYMBOL(ptr_simGetGeometricCount) SIM_API_SYMBOL(_simGetGeometricCount) = nullptr;
SIM_API_SYMBOL(ptr_simGetAllGeometrics) SIM_API_SYMBOL(_simGetAllGeometrics) = nullptr;
SIM_API_SYMBOL(ptr_simGetPurePrimitiveSizes) SIM_API_SYMBOL(_simGetPurePrimitiveSizes) = nullptr;
SIM_API_SYMBOL(ptr_simMakeDynamicAnnouncement) SIM_API_SYMBOL(_simMakeDynamicAnnouncement) = nullptr;
SIM_API_SYMBOL(ptr_simGetVerticesLocalFrame) SIM_API_SYMBOL(_simGetVerticesLocalFrame) = nullptr;
SIM_API_SYMBOL(ptr_simGetHeightfieldData) SIM_API_SYMBOL(_simGetHeightfieldData) = nullptr;
SIM_API_SYMBOL(ptr_simGetCumulativeMeshes) SIM_API_SYMBOL(_simGetCumulativeMeshes) = nullptr;
SIM_API_SYMBOL(ptr_simGetGravity) SIM_API_SYMBOL(_simGetGravity) = nullptr;
SIM_API_SYMBOL(ptr_simGetTimeDiffInMs) SIM_API_SYMBOL(_simGetTimeDiffInMs) = nullptr;
SIM_API_SYMBOL(ptr_simDoEntitiesCollide) SIM_API_SYMBOL(_simDoEntitiesCollide) = nullptr;
SIM_API_SYMBOL(ptr_simGetDistanceBetweenEntitiesIfSmaller) SIM_API_SYMBOL(_simGetDistanceBetweenEntitiesIfSmaller) = nullptr;
SIM_API_SYMBOL(ptr_simHandleJointControl) SIM_API_SYMBOL(_simHandleJointControl) = nullptr;
SIM_API_SYMBOL(ptr_simHandleCustomContact) SIM_API_SYMBOL(_simHandleCustomContact) = nullptr;
SIM_API_SYMBOL(ptr_simGetPureHollowScaling) SIM_API_SYMBOL(_simGetPureHollowScaling) = nullptr;
SIM_API_SYMBOL(ptr_simGetJointDynCtrlMode) SIM_API_SYMBOL(_simGetJointDynCtrlMode) = nullptr;
SIM_API_SYMBOL(ptr_simDynCallback) SIM_API_SYMBOL(_simDynCallback) = nullptr;

LIBRARY SIM_API_SYMBOL(loadSimLibrary)(const char* pathAndFilename)
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

void SIM_API_SYMBOL(unloadSimLibrary)(LIBRARY lib)
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
    SIM_API_SYMBOL(_addLog)=nullptr;
}

static FARPROC _getProcAddress(LIBRARY lib,const char* funcName,bool hasSingleAndDoublePrecisionFunc, bool longHandles = false)
{
    FARPROC retVal=nullptr;
    std::string fn(funcName);
    if (hasSingleAndDoublePrecisionFunc)
        fn+="_D";
    if (longHandles)
        fn += "_L";
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

int SIM_API_SYMBOL(getSimProcAddresses)(LIBRARY lib)
{
    SIM_API_SYMBOL(simSetBoolProperty) = (SIM_API_SYMBOL(ptrSimSetBoolProperty))(_getProcAddress(lib, "simSetBoolProperty", false));
    SIM_API_SYMBOL(simGetBoolProperty) = (SIM_API_SYMBOL(ptrSimGetBoolProperty))(_getProcAddress(lib, "simGetBoolProperty", false));
    SIM_API_SYMBOL(simSetIntProperty) = (SIM_API_SYMBOL(ptrSimSetIntProperty))(_getProcAddress(lib, "simSetIntProperty", false));
    SIM_API_SYMBOL(simGetIntProperty) = (SIM_API_SYMBOL(ptrSimGetIntProperty))(_getProcAddress(lib, "simGetIntProperty", false));
    SIM_API_SYMBOL(simSetLongProperty) = (SIM_API_SYMBOL(ptrSimSetLongProperty))(_getProcAddress(lib, "simSetLongProperty", false));
    SIM_API_SYMBOL(simGetLongProperty) = (SIM_API_SYMBOL(ptrSimGetLongProperty))(_getProcAddress(lib, "simGetLongProperty", false));
    SIM_API_SYMBOL(simSetFloatProperty) = (SIM_API_SYMBOL(ptrSimSetFloatProperty))(_getProcAddress(lib, "simSetFloatProperty", false));
    SIM_API_SYMBOL(simGetFloatProperty) = (SIM_API_SYMBOL(ptrSimGetFloatProperty))(_getProcAddress(lib, "simGetFloatProperty", false));
    SIM_API_SYMBOL(simSetStringProperty) = (SIM_API_SYMBOL(ptrSimSetStringProperty))(_getProcAddress(lib, "simSetStringProperty", false));
    SIM_API_SYMBOL(simGetStringProperty) = (SIM_API_SYMBOL(ptrSimGetStringProperty))(_getProcAddress(lib, "simGetStringProperty2", false));
    SIM_API_SYMBOL(simSetTableProperty) = (SIM_API_SYMBOL(ptrSimSetTableProperty))(_getProcAddress(lib, "simSetTableProperty", false));
    SIM_API_SYMBOL(simGetTableProperty) = (SIM_API_SYMBOL(ptrSimGetTableProperty))(_getProcAddress(lib, "simGetTableProperty2", false));
    SIM_API_SYMBOL(simSetBufferProperty) = (SIM_API_SYMBOL(ptrSimSetBufferProperty))(_getProcAddress(lib, "simSetBufferProperty", false));
    SIM_API_SYMBOL(simGetBufferProperty) = (SIM_API_SYMBOL(ptrSimGetBufferProperty))(_getProcAddress(lib, "simGetBufferProperty2", false));
    SIM_API_SYMBOL(simSetIntArray2Property) = (SIM_API_SYMBOL(ptrSimSetIntArray2Property))(_getProcAddress(lib, "simSetIntArray2Property", false));
    SIM_API_SYMBOL(simGetIntArray2Property) = (SIM_API_SYMBOL(ptrSimGetIntArray2Property))(_getProcAddress(lib, "simGetIntArray2Property", false));
    SIM_API_SYMBOL(simSetVector2Property) = (SIM_API_SYMBOL(ptrSimSetVector2Property))(_getProcAddress(lib, "simSetVector2Property", false));
    SIM_API_SYMBOL(simGetVector2Property) = (SIM_API_SYMBOL(ptrSimGetVector2Property))(_getProcAddress(lib, "simGetVector2Property", false));
    SIM_API_SYMBOL(simSetVector3Property) = (SIM_API_SYMBOL(ptrSimSetVector3Property))(_getProcAddress(lib, "simSetVector3Property", false));
    SIM_API_SYMBOL(simGetVector3Property) = (SIM_API_SYMBOL(ptrSimGetVector3Property))(_getProcAddress(lib, "simGetVector3Property", false));
    SIM_API_SYMBOL(simSetQuaternionProperty) = (SIM_API_SYMBOL(ptrSimSetQuaternionProperty))(_getProcAddress(lib, "simSetQuaternionProperty", false));
    SIM_API_SYMBOL(simGetQuaternionProperty) = (SIM_API_SYMBOL(ptrSimGetQuaternionProperty))(_getProcAddress(lib, "simGetQuaternionProperty", false));
    SIM_API_SYMBOL(simSetPoseProperty) = (SIM_API_SYMBOL(ptrSimSetPoseProperty))(_getProcAddress(lib, "simSetPoseProperty", false));
    SIM_API_SYMBOL(simGetPoseProperty) = (SIM_API_SYMBOL(ptrSimGetPoseProperty))(_getProcAddress(lib, "simGetPoseProperty", false));
    SIM_API_SYMBOL(simSetColorProperty) = (SIM_API_SYMBOL(ptrSimSetColorProperty))(_getProcAddress(lib, "simSetColorProperty", false));
    SIM_API_SYMBOL(simGetColorProperty) = (SIM_API_SYMBOL(ptrSimGetColorProperty))(_getProcAddress(lib, "simGetColorProperty", false));
    SIM_API_SYMBOL(simSetFloatArrayProperty) = (SIM_API_SYMBOL(ptrSimSetFloatArrayProperty))(_getProcAddress(lib, "simSetFloatArrayProperty", false));
    SIM_API_SYMBOL(simGetFloatArrayProperty) = (SIM_API_SYMBOL(ptrSimGetFloatArrayProperty))(_getProcAddress(lib, "simGetFloatArrayProperty2", false));
    SIM_API_SYMBOL(simSetIntArrayProperty) = (SIM_API_SYMBOL(ptrSimSetIntArrayProperty))(_getProcAddress(lib, "simSetIntArrayProperty", false));
    SIM_API_SYMBOL(simGetIntArrayProperty) = (SIM_API_SYMBOL(ptrSimGetIntArrayProperty))(_getProcAddress(lib, "simGetIntArrayProperty2", false));
    SIM_API_SYMBOL(simRemoveProperty) = (SIM_API_SYMBOL(ptrSimRemoveProperty))(_getProcAddress(lib, "simRemoveProperty", false));
    SIM_API_SYMBOL(simGetPropertyName) = (SIM_API_SYMBOL(ptrSimGetPropertyName))(_getProcAddress(lib, "simGetPropertyName", false));
    SIM_API_SYMBOL(simGetPropertyInfo) = (SIM_API_SYMBOL(ptrSimGetPropertyInfo))(_getProcAddress(lib, "simGetPropertyInfo", false));

    SIM_API_SYMBOL(simRegCallback) = (SIM_API_SYMBOL(ptrSimRegCallback))(_getProcAddress(lib,"simRegCallback",false));
    SIM_API_SYMBOL(simRunGui) = (SIM_API_SYMBOL(ptrSimRunGui))(_getProcAddress(lib,"simRunGui",false));
    SIM_API_SYMBOL(simInitialize) = (SIM_API_SYMBOL(ptrSimInitialize))(_getProcAddress(lib,"simInitialize",false));
    SIM_API_SYMBOL(simDeinitialize) = (SIM_API_SYMBOL(ptrSimDeinitialize))(_getProcAddress(lib,"simDeinitialize",false));
    SIM_API_SYMBOL(simPostExitRequest) = (SIM_API_SYMBOL(ptrSimPostExitRequest))(_getProcAddress(lib,"simPostExitRequest",false));
    SIM_API_SYMBOL(simGetExitRequest) = (SIM_API_SYMBOL(ptrSimGetExitRequest))(_getProcAddress(lib,"simGetExitRequest",false));
    SIM_API_SYMBOL(simLoop) = (SIM_API_SYMBOL(ptrSimLoop))(_getProcAddress(lib,"simLoop",false));
    SIM_API_SYMBOL(_addLog) = (SIM_API_SYMBOL(ptrSimAddLog))(_getProcAddress(lib,"simAddLog",false));
    SIM_API_SYMBOL(simTest) = (SIM_API_SYMBOL(ptrSimTest))(_getProcAddress(lib,"simTest",false));
    SIM_API_SYMBOL(simGetSimulatorMessage) = (SIM_API_SYMBOL(ptrSimGetSimulatorMessage))(_getProcAddress(lib,"simGetSimulatorMessage",false));
    SIM_API_SYMBOL(simGetMainWindow) = (SIM_API_SYMBOL(ptrSimGetMainWindow))(_getProcAddress(lib,"simGetMainWindow",false));
    SIM_API_SYMBOL(simGetLastError) = (SIM_API_SYMBOL(ptrSimGetLastError))(_getProcAddress(lib,"simGetLastError",false));
    SIM_API_SYMBOL(simGetLastInfo) = (SIM_API_SYMBOL(ptrSimGetLastInfo))(_getProcAddress(lib,"simGetLastInfo",false));
    SIM_API_SYMBOL(simGetObject) = (SIM_API_SYMBOL(ptrSimGetObject))(_getProcAddress(lib,"simGetObject",false, LH));
    SIM_API_SYMBOL(simGetObjectUid) = (SIM_API_SYMBOL(ptrSimGetObjectUid))(_getProcAddress(lib,"simGetObjectUid",false, LH));
    SIM_API_SYMBOL(simGetObjectFromUid) = (SIM_API_SYMBOL(ptrSimGetObjectFromUid))(_getProcAddress(lib,"simGetObjectFromUid",false, LH));
    SIM_API_SYMBOL(simGetScriptHandleEx) = (SIM_API_SYMBOL(ptrSimGetScriptHandleEx))(_getProcAddress(lib,"simGetScriptHandleEx",false, LH));
    SIM_API_SYMBOL(simRemoveObjects) = (SIM_API_SYMBOL(ptrSimRemoveObjects))(_getProcAddress(lib,"simRemoveObjects",false, LH));
    SIM_API_SYMBOL(simRemoveModel) = (SIM_API_SYMBOL(ptrSimRemoveModel))(_getProcAddress(lib,"simRemoveModel",false, LH));
    SIM_API_SYMBOL(simGetObjectAlias) = (SIM_API_SYMBOL(ptrSimGetObjectAlias))(_getProcAddress(lib,"simGetObjectAlias",false, LH));
    SIM_API_SYMBOL(simSetObjectAlias) = (SIM_API_SYMBOL(ptrSimSetObjectAlias))(_getProcAddress(lib,"simSetObjectAlias",false, LH));
    SIM_API_SYMBOL(simGetObjectParent) = (SIM_API_SYMBOL(ptrSimGetObjectParent))(_getProcAddress(lib,"simGetObjectParent",false, LH));
    SIM_API_SYMBOL(simGetObjectChild) = (SIM_API_SYMBOL(ptrSimGetObjectChild))(_getProcAddress(lib,"simGetObjectChild",false, LH));
    SIM_API_SYMBOL(simSetObjectParent) = (SIM_API_SYMBOL(ptrSimSetObjectParent))(_getProcAddress(lib,"simSetObjectParent",false, LH));
    SIM_API_SYMBOL(simGetObjectType) = (SIM_API_SYMBOL(ptrSimGetObjectType))(_getProcAddress(lib,"simGetObjectType",false, LH));
    SIM_API_SYMBOL(simGetJointType) = (SIM_API_SYMBOL(ptrSimGetJointType))(_getProcAddress(lib,"simGetJointType",false, LH));
    SIM_API_SYMBOL(simReservedCommand) = (SIM_API_SYMBOL(ptrSimReservedCommand))(_getProcAddress(lib,"simReservedCommand",false));
    SIM_API_SYMBOL(simGetSimulationState) = (SIM_API_SYMBOL(ptrSimGetSimulationState))(_getProcAddress(lib,"simGetSimulationState",false));
    SIM_API_SYMBOL(simLoadScene) = (SIM_API_SYMBOL(ptrSimLoadScene))(_getProcAddress(lib,"simLoadScene",false));
    SIM_API_SYMBOL(simCloseScene) = (SIM_API_SYMBOL(ptrSimCloseScene))(_getProcAddress(lib,"simCloseScene",false));
    SIM_API_SYMBOL(simSaveScene) = (SIM_API_SYMBOL(ptrSimSaveScene))(_getProcAddress(lib,"simSaveScene",false));
    SIM_API_SYMBOL(simLoadModel) = (SIM_API_SYMBOL(ptrSimLoadModel))(_getProcAddress(lib,"simLoadModel",false, LH));
    SIM_API_SYMBOL(simSaveModel) = (SIM_API_SYMBOL(ptrSimSaveModel))(_getProcAddress(lib,"simSaveModel",false, LH));
    SIM_API_SYMBOL(simDoesFileExist) = (SIM_API_SYMBOL(ptrSimDoesFileExist))(_getProcAddress(lib,"simDoesFileExist",false));
    SIM_API_SYMBOL(simGetObjectSel) = (SIM_API_SYMBOL(ptrSimGetObjectSel))(_getProcAddress(lib,"simGetObjectSel",false, LH));
    SIM_API_SYMBOL(simSetObjectSel) = (SIM_API_SYMBOL(ptrSimSetObjectSel))(_getProcAddress(lib,"simSetObjectSel",false, LH));
    SIM_API_SYMBOL(simResetScript) = (SIM_API_SYMBOL(ptrSimResetScript))(_getProcAddress(lib,"simResetScript",false, LH));
    SIM_API_SYMBOL(simRefreshDialogs) = (SIM_API_SYMBOL(ptrSimRefreshDialogs))(_getProcAddress(lib,"simRefreshDialogs",false));
    SIM_API_SYMBOL(simResetProximitySensor) = (SIM_API_SYMBOL(ptrSimResetProximitySensor))(_getProcAddress(lib,"simResetProximitySensor",false, LH));
    SIM_API_SYMBOL(simCreateBuffer) = (SIM_API_SYMBOL(ptrSimCreateBuffer))(_getProcAddress(lib,"simCreateBuffer",false));
    SIM_API_SYMBOL(simReleaseBuffer) = (SIM_API_SYMBOL(ptrSimReleaseBuffer))(_getProcAddress(lib,"simReleaseBuffer",false));
    SIM_API_SYMBOL(simCheckCollision) = (SIM_API_SYMBOL(ptrSimCheckCollision))(_getProcAddress(lib,"simCheckCollision",false, LH));
    SIM_API_SYMBOL(simGetRealTimeSimulation) = (SIM_API_SYMBOL(ptrSimGetRealTimeSimulation))(_getProcAddress(lib,"simGetRealTimeSimulation",false));
    SIM_API_SYMBOL(simStartSimulation) = (SIM_API_SYMBOL(ptrSimStartSimulation))(_getProcAddress(lib,"simStartSimulation",false));
    SIM_API_SYMBOL(simStopSimulation) = (SIM_API_SYMBOL(ptrSimStopSimulation))(_getProcAddress(lib,"simStopSimulation",false));
    SIM_API_SYMBOL(simPauseSimulation) = (SIM_API_SYMBOL(ptrSimPauseSimulation))(_getProcAddress(lib,"simPauseSimulation",false));
    SIM_API_SYMBOL(simAdjustView) = (SIM_API_SYMBOL(ptrSimAdjustView))(_getProcAddress(lib,"simAdjustView",false, LH));
    SIM_API_SYMBOL(simSetLastError) = (SIM_API_SYMBOL(ptrSimSetLastError))(_getProcAddress(lib,"simSetLastError",false));
    SIM_API_SYMBOL(simResetGraph) = (SIM_API_SYMBOL(ptrSimResetGraph))(_getProcAddress(lib,"simResetGraph",false, LH));
    SIM_API_SYMBOL(simDestroyGraphCurve) = (SIM_API_SYMBOL(ptrSimDestroyGraphCurve))(_getProcAddress(lib,"simDestroyGraphCurve",false, LH));
    SIM_API_SYMBOL(simDuplicateGraphCurveToStatic) = (SIM_API_SYMBOL(ptrSimDuplicateGraphCurveToStatic))(_getProcAddress(lib,"simDuplicateGraphCurveToStatic",false, LH));
    SIM_API_SYMBOL(simSetNavigationMode) = (SIM_API_SYMBOL(ptrSimSetNavigationMode))(_getProcAddress(lib,"simSetNavigationMode",false));
    SIM_API_SYMBOL(simGetNavigationMode) = (SIM_API_SYMBOL(ptrSimGetNavigationMode))(_getProcAddress(lib,"simGetNavigationMode",false));
    SIM_API_SYMBOL(simSetPage) = (SIM_API_SYMBOL(ptrSimSetPage))(_getProcAddress(lib,"simSetPage",false));
    SIM_API_SYMBOL(simGetPage) = (SIM_API_SYMBOL(ptrSimGetPage))(_getProcAddress(lib,"simGetPage",false));
    SIM_API_SYMBOL(simRegisterScriptCallbackFunction) = (SIM_API_SYMBOL(ptrSimRegisterScriptCallbackFunction))(_getProcAddress(lib,"simRegisterScriptCallbackFunction",false));
    SIM_API_SYMBOL(simRegisterScriptVariable) = (SIM_API_SYMBOL(ptrSimRegisterScriptVariable))(_getProcAddress(lib,"simRegisterScriptVariable",false, LH));
    SIM_API_SYMBOL(simRegisterScriptFuncHook) = (SIM_API_SYMBOL(ptrSimRegisterScriptFuncHook))(_getProcAddress(lib,"simRegisterScriptFuncHook",false, LH));
    SIM_API_SYMBOL(simCopyPasteObjects) = (SIM_API_SYMBOL(ptrSimCopyPasteObjects))(_getProcAddress(lib,"simCopyPasteObjects",false, LH));
    SIM_API_SYMBOL(simRemoveDrawingObject) = (SIM_API_SYMBOL(ptrSimRemoveDrawingObject))(_getProcAddress(lib,"simRemoveDrawingObject",false, LH));
    SIM_API_SYMBOL(simAnnounceSceneContentChange) = (SIM_API_SYMBOL(ptrSimAnnounceSceneContentChange))(_getProcAddress(lib,"simAnnounceSceneContentChange",false));
    SIM_API_SYMBOL(simSetExplicitHandling) = (SIM_API_SYMBOL(ptrSimSetExplicitHandling))(_getProcAddress(lib,"simSetExplicitHandling",false, LH));
    SIM_API_SYMBOL(simGetExplicitHandling) = (SIM_API_SYMBOL(ptrSimGetExplicitHandling))(_getProcAddress(lib,"simGetExplicitHandling",false, LH));
    SIM_API_SYMBOL(simGetLinkDummy) = (SIM_API_SYMBOL(ptrSimGetLinkDummy))(_getProcAddress(lib,"simGetLinkDummy",false, LH));
    SIM_API_SYMBOL(simSetLinkDummy) = (SIM_API_SYMBOL(ptrSimSetLinkDummy))(_getProcAddress(lib,"simSetLinkDummy",false, LH));
    SIM_API_SYMBOL(simResetDynamicObject) = (SIM_API_SYMBOL(ptrSimResetDynamicObject))(_getProcAddress(lib,"simResetDynamicObject",false, LH));
    SIM_API_SYMBOL(simSetJointMode) = (SIM_API_SYMBOL(ptrSimSetJointMode))(_getProcAddress(lib,"simSetJointMode",false, LH));
    SIM_API_SYMBOL(simGetJointMode) = (SIM_API_SYMBOL(ptrSimGetJointMode))(_getProcAddress(lib,"simGetJointMode",false, LH));
    SIM_API_SYMBOL(simSerialOpen) = (SIM_API_SYMBOL(ptrSimSerialOpen))(_getProcAddress(lib,"simSerialOpen",false));
    SIM_API_SYMBOL(simSerialClose) = (SIM_API_SYMBOL(ptrSimSerialClose))(_getProcAddress(lib,"simSerialClose",false));
    SIM_API_SYMBOL(simSerialSend) = (SIM_API_SYMBOL(ptrSimSerialSend))(_getProcAddress(lib,"simSerialSend",false));
    SIM_API_SYMBOL(simSerialRead) = (SIM_API_SYMBOL(ptrSimSerialRead))(_getProcAddress(lib,"simSerialRead",false));
    SIM_API_SYMBOL(simSerialCheck) = (SIM_API_SYMBOL(ptrSimSerialCheck))(_getProcAddress(lib,"simSerialCheck",false));
    SIM_API_SYMBOL(simAuxiliaryConsoleClose) = (SIM_API_SYMBOL(ptrSimAuxiliaryConsoleClose))(_getProcAddress(lib,"simAuxiliaryConsoleClose",false));
    SIM_API_SYMBOL(simAuxiliaryConsoleShow) = (SIM_API_SYMBOL(ptrSimAuxiliaryConsoleShow))(_getProcAddress(lib,"simAuxiliaryConsoleShow",false));
    SIM_API_SYMBOL(simAuxiliaryConsolePrint) = (SIM_API_SYMBOL(ptrSimAuxiliaryConsolePrint))(_getProcAddress(lib,"simAuxiliaryConsolePrint",false));
    SIM_API_SYMBOL(simIsHandle) = (SIM_API_SYMBOL(ptrSimIsHandle))(_getProcAddress(lib,"simIsHandle",false, LH));
    SIM_API_SYMBOL(simResetVisionSensor) = (SIM_API_SYMBOL(ptrSimResetVisionSensor))(_getProcAddress(lib,"simResetVisionSensor",false, LH));
    SIM_API_SYMBOL(simSetVisionSensorImg) = (SIM_API_SYMBOL(ptrSimSetVisionSensorImg))(_getProcAddress(lib,"simSetVisionSensorImg",false, LH));
    SIM_API_SYMBOL(simRuckigPos) = (SIM_API_SYMBOL(ptrSimRuckigPos))(_getProcAddress(lib,"simRuckigPos",false));
    SIM_API_SYMBOL(simRuckigVel) = (SIM_API_SYMBOL(ptrSimRuckigVel))(_getProcAddress(lib,"simRuckigVel",false));
    SIM_API_SYMBOL(simRuckigStep) = (SIM_API_SYMBOL(ptrSimRuckigStep))(_getProcAddress(lib,"simRuckigStep",false));
    SIM_API_SYMBOL(simRuckigRemove) = (SIM_API_SYMBOL(ptrSimRuckigRemove))(_getProcAddress(lib,"simRuckigRemove",false));
    SIM_API_SYMBOL(simGroupShapes) = (SIM_API_SYMBOL(ptrSimGroupShapes))(_getProcAddress(lib,"simGroupShapes",false, LH));
    SIM_API_SYMBOL(simUngroupShape) = (SIM_API_SYMBOL(ptrSimUngroupShape))(_getProcAddress(lib,"simUngroupShape",false, LH));
    SIM_API_SYMBOL(simQuitSimulator) = (SIM_API_SYMBOL(ptrSimQuitSimulator))(_getProcAddress(lib,"simQuitSimulator",false));
    SIM_API_SYMBOL(simSetShapeMaterial) = (SIM_API_SYMBOL(ptrSimSetShapeMaterial))(_getProcAddress(lib,"simSetShapeMaterial",false, LH));
    SIM_API_SYMBOL(simGetTextureId) = (SIM_API_SYMBOL(ptrSimGetTextureId))(_getProcAddress(lib,"simGetTextureId",false, LH));
    SIM_API_SYMBOL(simReadTexture) = (SIM_API_SYMBOL(ptrSimReadTexture))(_getProcAddress(lib,"simReadTexture",false, LH));
    SIM_API_SYMBOL(simGetObjects) = (SIM_API_SYMBOL(ptrSimGetObjects))(_getProcAddress(lib,"simGetObjects",false, LH));
    SIM_API_SYMBOL(simGetObjectsInTree) = (SIM_API_SYMBOL(ptrSimGetObjectsInTree))(_getProcAddress(lib,"simGetObjectsInTree",false, LH));
    SIM_API_SYMBOL(simGetShapeTextureId) = (SIM_API_SYMBOL(ptrSimGetShapeTextureId))(_getProcAddress(lib,"simGetShapeTextureId",false, LH));
    SIM_API_SYMBOL(simCreateCollectionEx) = (SIM_API_SYMBOL(ptrSimCreateCollectionEx))(_getProcAddress(lib,"simCreateCollectionEx",false, LH));
    SIM_API_SYMBOL(simAddItemToCollection) = (SIM_API_SYMBOL(ptrSimAddItemToCollection))(_getProcAddress(lib,"simAddItemToCollection",false, LH));
    SIM_API_SYMBOL(simDestroyCollection) = (SIM_API_SYMBOL(ptrSimDestroyCollection))(_getProcAddress(lib,"simDestroyCollection",false, LH));
    SIM_API_SYMBOL(simGetCollectionObjects) = (SIM_API_SYMBOL(ptrSimGetCollectionObjects))(_getProcAddress(lib,"simGetCollectionObjects",false, LH));
    SIM_API_SYMBOL(simAlignShapeBB) = (SIM_API_SYMBOL(ptrSimAlignShapeBB))(_getProcAddress(lib,"simAlignShapeBB",false, LH));
    SIM_API_SYMBOL(simRelocateShapeFrame) = (SIM_API_SYMBOL(ptrSimRelocateShapeFrame))(_getProcAddress(lib,"simRelocateShapeFrame",false, LH));
    SIM_API_SYMBOL(simSaveImage) = (SIM_API_SYMBOL(ptrSimSaveImage))(_getProcAddress(lib,"simSaveImage",false));
    SIM_API_SYMBOL(simLoadImage) = (SIM_API_SYMBOL(ptrSimLoadImage))(_getProcAddress(lib,"simLoadImage",false));
    SIM_API_SYMBOL(simGetScaledImage) = (SIM_API_SYMBOL(ptrSimGetScaledImage))(_getProcAddress(lib,"simGetScaledImage",false));
    SIM_API_SYMBOL(simCallScriptFunctionEx) = (SIM_API_SYMBOL(ptrSimCallScriptFunctionEx))(_getProcAddress(lib,"simCallScriptFunctionEx",false, LH));
    SIM_API_SYMBOL(simGetExtensionString) = (SIM_API_SYMBOL(ptrSimGetExtensionString))(_getProcAddress(lib,"simGetExtensionString",false, LH));
    SIM_API_SYMBOL(simCreateStack) = (SIM_API_SYMBOL(ptrSimCreateStack))(_getProcAddress(lib,"simCreateStack",false, LH));
    SIM_API_SYMBOL(simReleaseStack) = (SIM_API_SYMBOL(ptrSimReleaseStack))(_getProcAddress(lib,"simReleaseStack",false, LH));
    SIM_API_SYMBOL(simCopyStack) = (SIM_API_SYMBOL(ptrSimCopyStack))(_getProcAddress(lib,"simCopyStack",false, LH));
    SIM_API_SYMBOL(simPushNullOntoStack) = (SIM_API_SYMBOL(ptrSimPushNullOntoStack))(_getProcAddress(lib,"simPushNullOntoStack",false, LH));
    SIM_API_SYMBOL(simPushBoolOntoStack) = (SIM_API_SYMBOL(ptrSimPushBoolOntoStack))(_getProcAddress(lib,"simPushBoolOntoStack",false, LH));
    SIM_API_SYMBOL(simPushInt32OntoStack) = (SIM_API_SYMBOL(ptrSimPushInt32OntoStack))(_getProcAddress(lib,"simPushInt32OntoStack",false, LH));
    SIM_API_SYMBOL(simPushInt64OntoStack) = (SIM_API_SYMBOL(ptrSimPushInt64OntoStack))(_getProcAddress(lib,"simPushInt64OntoStack",false, LH));
    SIM_API_SYMBOL(simPushFloatOntoStack) = (SIM_API_SYMBOL(ptrSimPushFloatOntoStack))(_getProcAddress(lib,"simPushFloatOntoStack",false, LH));
    SIM_API_SYMBOL(simPushDoubleOntoStack) = (SIM_API_SYMBOL(ptrSimPushDoubleOntoStack))(_getProcAddress(lib,"simPushDoubleOntoStack",false, LH));
    SIM_API_SYMBOL(simPushTextOntoStack) = (SIM_API_SYMBOL(ptrSimPushTextOntoStack))(_getProcAddress(lib,"simPushTextOntoStack",false, LH));
    SIM_API_SYMBOL(simPushStringOntoStack) = (SIM_API_SYMBOL(ptrSimPushStringOntoStack))(_getProcAddress(lib,"simPushStringOntoStack",false, LH));
    SIM_API_SYMBOL(simPushBufferOntoStack) = (SIM_API_SYMBOL(ptrSimPushBufferOntoStack))(_getProcAddress(lib,"simPushBufferOntoStack",false, LH));
    SIM_API_SYMBOL(simPushUInt8TableOntoStack) = (SIM_API_SYMBOL(ptrSimPushUInt8TableOntoStack))(_getProcAddress(lib,"simPushUInt8TableOntoStack",false, LH));
    SIM_API_SYMBOL(simPushInt32TableOntoStack) = (SIM_API_SYMBOL(ptrSimPushInt32TableOntoStack))(_getProcAddress(lib,"simPushInt32TableOntoStack",false, LH));
    SIM_API_SYMBOL(simPushInt64TableOntoStack) = (SIM_API_SYMBOL(ptrSimPushInt64TableOntoStack))(_getProcAddress(lib,"simPushInt64TableOntoStack",false, LH));
    SIM_API_SYMBOL(simPushFloatTableOntoStack) = (SIM_API_SYMBOL(ptrSimPushFloatTableOntoStack))(_getProcAddress(lib,"simPushFloatTableOntoStack",false, LH));
    SIM_API_SYMBOL(simPushDoubleTableOntoStack) = (SIM_API_SYMBOL(ptrSimPushDoubleTableOntoStack))(_getProcAddress(lib,"simPushDoubleTableOntoStack",false, LH));
    SIM_API_SYMBOL(simPushTableOntoStack) = (SIM_API_SYMBOL(ptrSimPushTableOntoStack))(_getProcAddress(lib,"simPushTableOntoStack",false, LH));
    SIM_API_SYMBOL(simInsertDataIntoStackTable) = (SIM_API_SYMBOL(ptrSimInsertDataIntoStackTable))(_getProcAddress(lib,"simInsertDataIntoStackTable",false, LH));
    SIM_API_SYMBOL(simGetStackSize) = (SIM_API_SYMBOL(ptrSimGetStackSize))(_getProcAddress(lib,"simGetStackSize",false, LH));
    SIM_API_SYMBOL(simPopStackItem) = (SIM_API_SYMBOL(ptrSimPopStackItem))(_getProcAddress(lib,"simPopStackItem",false, LH));
    SIM_API_SYMBOL(simMoveStackItemToTop) = (SIM_API_SYMBOL(ptrSimMoveStackItemToTop))(_getProcAddress(lib,"simMoveStackItemToTop",false, LH));
    SIM_API_SYMBOL(simGetStackItemType) = (SIM_API_SYMBOL(ptrSimGetStackItemType))(_getProcAddress(lib,"simGetStackItemType",false, LH));
    SIM_API_SYMBOL(simGetStackStringType) = (SIM_API_SYMBOL(ptrSimGetStackStringType))(_getProcAddress(lib,"simGetStackStringType",false, LH));
    SIM_API_SYMBOL(simGetStackBoolValue) = (SIM_API_SYMBOL(ptrSimGetStackBoolValue))(_getProcAddress(lib,"simGetStackBoolValue",false, LH));
    SIM_API_SYMBOL(simGetStackInt32Value) = (SIM_API_SYMBOL(ptrSimGetStackInt32Value))(_getProcAddress(lib,"simGetStackInt32Value",false, LH));
    SIM_API_SYMBOL(simGetStackInt64Value) = (SIM_API_SYMBOL(ptrSimGetStackInt64Value))(_getProcAddress(lib,"simGetStackInt64Value",false, LH));
    SIM_API_SYMBOL(simGetStackFloatValue) = (SIM_API_SYMBOL(ptrSimGetStackFloatValue))(_getProcAddress(lib,"simGetStackFloatValue",false, LH));
    SIM_API_SYMBOL(simGetStackDoubleValue) = (SIM_API_SYMBOL(ptrSimGetStackDoubleValue))(_getProcAddress(lib,"simGetStackDoubleValue",false, LH));
    SIM_API_SYMBOL(simGetStackStringValue) = (SIM_API_SYMBOL(ptrSimGetStackStringValue))(_getProcAddress(lib,"simGetStackStringValue",false, LH));
    SIM_API_SYMBOL(simGetStackTableInfo) = (SIM_API_SYMBOL(ptrSimGetStackTableInfo))(_getProcAddress(lib,"simGetStackTableInfo",false, LH));
    SIM_API_SYMBOL(simGetStackUInt8Table) = (SIM_API_SYMBOL(ptrSimGetStackUInt8Table))(_getProcAddress(lib,"simGetStackUInt8Table",false, LH));
    SIM_API_SYMBOL(simGetStackInt32Table) = (SIM_API_SYMBOL(ptrSimGetStackInt32Table))(_getProcAddress(lib,"simGetStackInt32Table",false, LH));
    SIM_API_SYMBOL(simGetStackInt64Table) = (SIM_API_SYMBOL(ptrSimGetStackInt64Table))(_getProcAddress(lib,"simGetStackInt64Table",false, LH));
    SIM_API_SYMBOL(simGetStackFloatTable) = (SIM_API_SYMBOL(ptrSimGetStackFloatTable))(_getProcAddress(lib,"simGetStackFloatTable",false, LH));
    SIM_API_SYMBOL(simGetStackDoubleTable) = (SIM_API_SYMBOL(ptrSimGetStackDoubleTable))(_getProcAddress(lib,"simGetStackDoubleTable",false, LH));
    SIM_API_SYMBOL(simUnfoldStackTable) = (SIM_API_SYMBOL(ptrSimUnfoldStackTable))(_getProcAddress(lib,"simUnfoldStackTable",false, LH));
    SIM_API_SYMBOL(simDebugStack) = (SIM_API_SYMBOL(ptrSimDebugStack))(_getProcAddress(lib,"simDebugStack",false, LH));
    SIM_API_SYMBOL(simInsertObjectIntoOctree) = (SIM_API_SYMBOL(ptrSimInsertObjectIntoOctree))(_getProcAddress(lib,"simInsertObjectIntoOctree",false, LH));
    SIM_API_SYMBOL(simSubtractObjectFromOctree) = (SIM_API_SYMBOL(ptrSimSubtractObjectFromOctree))(_getProcAddress(lib,"simSubtractObjectFromOctree",false, LH));
    SIM_API_SYMBOL(simOpenTextEditor) = (SIM_API_SYMBOL(ptrSimOpenTextEditor))(_getProcAddress(lib,"simOpenTextEditor",false));
    SIM_API_SYMBOL(simPackTable) = (SIM_API_SYMBOL(ptrSimPackTable))(_getProcAddress(lib,"simPackTable",false, LH));
    SIM_API_SYMBOL(simUnpackTable) = (SIM_API_SYMBOL(ptrSimUnpackTable))(_getProcAddress(lib,"simUnpackTable",false, LH));
    SIM_API_SYMBOL(simSetReferencedHandles) = (SIM_API_SYMBOL(ptrSimSetReferencedHandles))(_getProcAddress(lib,"simSetReferencedHandles",false, LH));
    SIM_API_SYMBOL(simGetReferencedHandles) = (SIM_API_SYMBOL(ptrSimGetReferencedHandles))(_getProcAddress(lib,"simGetReferencedHandles",false, LH));
    SIM_API_SYMBOL(simExecuteScriptString) = (SIM_API_SYMBOL(ptrSimExecuteScriptString))(_getProcAddress(lib,"simExecuteScriptString",false, LH));
    SIM_API_SYMBOL(simGetApiFunc) = (SIM_API_SYMBOL(ptrSimGetApiFunc))(_getProcAddress(lib,"simGetApiFunc",false, LH));
    SIM_API_SYMBOL(simGetApiInfo) = (SIM_API_SYMBOL(ptrSimGetApiInfo))(_getProcAddress(lib,"simGetApiInfo",false, LH));
    SIM_API_SYMBOL(simGetPluginName) = (SIM_API_SYMBOL(ptrSimGetPluginName))(_getProcAddress(lib,"simGetPluginName",false));
    SIM_API_SYMBOL(simSetPluginInfo) = (SIM_API_SYMBOL(ptrSimSetPluginInfo))(_getProcAddress(lib,"simSetPluginInfo",false));
    SIM_API_SYMBOL(simGetPluginInfo) = (SIM_API_SYMBOL(ptrSimGetPluginInfo))(_getProcAddress(lib,"simGetPluginInfo",false));
    SIM_API_SYMBOL(simEventNotification) = (SIM_API_SYMBOL(ptrSimEventNotification))(_getProcAddress(lib,"simEventNotification",false));
    SIM_API_SYMBOL(simIsDynamicallyEnabled) = (SIM_API_SYMBOL(ptrSimIsDynamicallyEnabled))(_getProcAddress(lib,"simIsDynamicallyEnabled",false, LH));
    SIM_API_SYMBOL(simInitScript) = (SIM_API_SYMBOL(ptrSimInitScript))(_getProcAddress(lib,"simInitScript",false, LH));
    SIM_API_SYMBOL(simModuleEntry) = (SIM_API_SYMBOL(ptrSimModuleEntry))(_getProcAddress(lib,"simModuleEntry",false));
    SIM_API_SYMBOL(simCheckExecAuthorization) = (SIM_API_SYMBOL(ptrSimCheckExecAuthorization))(_getProcAddress(lib,"simCheckExecAuthorization",false));
    SIM_API_SYMBOL(_simSetDynamicSimulationIconCode) = (SIM_API_SYMBOL(ptr_simSetDynamicSimulationIconCode))(_getProcAddress(lib,"_simSetDynamicSimulationIconCode",false));
    SIM_API_SYMBOL(_simSetDynamicObjectFlagForVisualization) = (SIM_API_SYMBOL(ptr_simSetDynamicObjectFlagForVisualization))(_getProcAddress(lib,"_simSetDynamicObjectFlagForVisualization",false));
    SIM_API_SYMBOL(_simGetObjectListSize) = (SIM_API_SYMBOL(ptr_simGetObjectListSize))(_getProcAddress(lib,"_simGetObjectListSize",false));
    SIM_API_SYMBOL(_simGetObjectFromIndex) = (SIM_API_SYMBOL(ptr_simGetObjectFromIndex))(_getProcAddress(lib,"_simGetObjectFromIndex",false));
    SIM_API_SYMBOL(_simGetObjectID) = (SIM_API_SYMBOL(ptr_simGetObjectID))(_getProcAddress(lib,"_simGetObjectID",false, LH));
    SIM_API_SYMBOL(_simGetObjectType) = (SIM_API_SYMBOL(ptr_simGetObjectType))(_getProcAddress(lib,"_simGetObjectType",false));
    SIM_API_SYMBOL(_simGetObjectChildren) = (SIM_API_SYMBOL(ptr_simGetObjectChildren))(_getProcAddress(lib,"_simGetObjectChildren",false));
    SIM_API_SYMBOL(_simGetParentObject) = (SIM_API_SYMBOL(ptr_simGetParentObject))(_getProcAddress(lib,"_simGetParentObject",false));
    SIM_API_SYMBOL(_simGetObject) = (SIM_API_SYMBOL(ptr_simGetObject))(_getProcAddress(lib,"_simGetObject",false, LH));
    SIM_API_SYMBOL(_simGetIkGroupObject) = (SIM_API_SYMBOL(ptr_simGetIkGroupObject))(_getProcAddress(lib,"_simGetIkGroupObject",false));
    SIM_API_SYMBOL(_simMpHandleIkGroupObject) = (SIM_API_SYMBOL(ptr_simMpHandleIkGroupObject))(_getProcAddress(lib,"_simMpHandleIkGroupObject",false));
    SIM_API_SYMBOL(_simIsShapeDynamicallyStatic) = (SIM_API_SYMBOL(ptr_simIsShapeDynamicallyStatic))(_getProcAddress(lib,"_simIsShapeDynamicallyStatic",false));
    SIM_API_SYMBOL(_simGetTreeDynamicProperty) = (SIM_API_SYMBOL(ptr_simGetTreeDynamicProperty))(_getProcAddress(lib,"_simGetTreeDynamicProperty",false));
    SIM_API_SYMBOL(_simGetDummyLinkType) = (SIM_API_SYMBOL(ptr_simGetDummyLinkType))(_getProcAddress(lib,"_simGetDummyLinkType",false, LH));
    SIM_API_SYMBOL(_simGetJointMode) = (SIM_API_SYMBOL(ptr_simGetJointMode))(_getProcAddress(lib,"_simGetJointMode",false));
    SIM_API_SYMBOL(_simIsJointInHybridOperation) = (SIM_API_SYMBOL(ptr_simIsJointInHybridOperation))(_getProcAddress(lib,"_simIsJointInHybridOperation",false));
    SIM_API_SYMBOL(_simDisableDynamicTreeForManipulation) = (SIM_API_SYMBOL(ptr_simDisableDynamicTreeForManipulation))(_getProcAddress(lib,"_simDisableDynamicTreeForManipulation",false));
    SIM_API_SYMBOL(_simIsShapeDynamicallyRespondable) = (SIM_API_SYMBOL(ptr_simIsShapeDynamicallyRespondable))(_getProcAddress(lib,"_simIsShapeDynamicallyRespondable",false));
    SIM_API_SYMBOL(_simGetDynamicCollisionMask) = (SIM_API_SYMBOL(ptr_simGetDynamicCollisionMask))(_getProcAddress(lib,"_simGetDynamicCollisionMask",false));
    SIM_API_SYMBOL(_simGetLastParentForLocalGlobalCollidable) = (SIM_API_SYMBOL(ptr_simGetLastParentForLocalGlobalCollidable))(_getProcAddress(lib,"_simGetLastParentForLocalGlobalCollidable",false));
    SIM_API_SYMBOL(_simGetStartSleeping) = (SIM_API_SYMBOL(ptr_simGetStartSleeping))(_getProcAddress(lib,"_simGetStartSleeping",false));
    SIM_API_SYMBOL(_simGetWasPutToSleepOnce) = (SIM_API_SYMBOL(ptr_simGetWasPutToSleepOnce))(_getProcAddress(lib,"_simGetWasPutToSleepOnce",false));
    SIM_API_SYMBOL(_simGetDynamicsFullRefreshFlag) = (SIM_API_SYMBOL(ptr_simGetDynamicsFullRefreshFlag))(_getProcAddress(lib,"_simGetDynamicsFullRefreshFlag",false));
    SIM_API_SYMBOL(_simSetDynamicsFullRefreshFlag) = (SIM_API_SYMBOL(ptr_simSetDynamicsFullRefreshFlag))(_getProcAddress(lib,"_simSetDynamicsFullRefreshFlag",false));
    SIM_API_SYMBOL(_simClearAdditionalForceAndTorque) = (SIM_API_SYMBOL(ptr_simClearAdditionalForceAndTorque))(_getProcAddress(lib,"_simClearAdditionalForceAndTorque",false));
    SIM_API_SYMBOL(_simGetJointType) = (SIM_API_SYMBOL(ptr_simGetJointType))(_getProcAddress(lib,"_simGetJointType",false));
    SIM_API_SYMBOL(_simGetGeomWrapFromGeomProxy) = (SIM_API_SYMBOL(ptr_simGetGeomWrapFromGeomProxy))(_getProcAddress(lib,"_simGetGeomWrapFromGeomProxy",false));
    SIM_API_SYMBOL(_simGetPurePrimitiveType) = (SIM_API_SYMBOL(ptr_simGetPurePrimitiveType))(_getProcAddress(lib,"_simGetPurePrimitiveType",false));
    SIM_API_SYMBOL(_simIsGeomWrapGeometric) = (SIM_API_SYMBOL(ptr_simIsGeomWrapGeometric))(_getProcAddress(lib,"_simIsGeomWrapGeometric",false));
    SIM_API_SYMBOL(_simIsGeomWrapConvex) = (SIM_API_SYMBOL(ptr_simIsGeomWrapConvex))(_getProcAddress(lib,"_simIsGeomWrapConvex",false));
    SIM_API_SYMBOL(_simGetGeometricCount) = (SIM_API_SYMBOL(ptr_simGetGeometricCount))(_getProcAddress(lib,"_simGetGeometricCount",false));
    SIM_API_SYMBOL(_simGetAllGeometrics) = (SIM_API_SYMBOL(ptr_simGetAllGeometrics))(_getProcAddress(lib,"_simGetAllGeometrics",false));
    SIM_API_SYMBOL(_simMakeDynamicAnnouncement) = (SIM_API_SYMBOL(ptr_simMakeDynamicAnnouncement))(_getProcAddress(lib,"_simMakeDynamicAnnouncement",false));
    SIM_API_SYMBOL(_simGetTimeDiffInMs) = (SIM_API_SYMBOL(ptr_simGetTimeDiffInMs))(_getProcAddress(lib,"_simGetTimeDiffInMs",false));
    SIM_API_SYMBOL(_simDoEntitiesCollide) = (SIM_API_SYMBOL(ptr_simDoEntitiesCollide))(_getProcAddress(lib,"_simDoEntitiesCollide",false, LH));
    SIM_API_SYMBOL(_simGetJointDynCtrlMode) = (SIM_API_SYMBOL(ptr_simGetJointDynCtrlMode))(_getProcAddress(lib,"_simGetJointDynCtrlMode",false));
    SIM_API_SYMBOL(simFloatingViewRemove) = (SIM_API_SYMBOL(ptrSimFloatingViewRemove))(_getProcAddress(lib,"simFloatingViewRemove",false));
    SIM_API_SYMBOL(simGetVisionSensorDepth) = (SIM_API_SYMBOL(ptrSimGetVisionSensorDepth))(_getProcAddress(lib,"simGetVisionSensorDepth",false, LH));
    SIM_API_SYMBOL(_simSetVisionSensorDepth) = (SIM_API_SYMBOL(ptr_simSetVisionSensorDepth))(_getProcAddress(lib,"_simSetVisionSensorDepth",false, LH));
    SIM_API_SYMBOL(simSetObjectColor) = (SIM_API_SYMBOL(ptrSimSetObjectColor))(_getProcAddress(lib,"simSetObjectColor",false, LH));
    SIM_API_SYMBOL(simGetObjectColor) = (SIM_API_SYMBOL(ptrSimGetObjectColor))(_getProcAddress(lib,"simGetObjectColor",false, LH));
    SIM_API_SYMBOL(simSetShapeColor) = (SIM_API_SYMBOL(ptrSimSetShapeColor))(_getProcAddress(lib,"simSetShapeColor",false, LH));
    SIM_API_SYMBOL(simGetShapeColor) = (SIM_API_SYMBOL(ptrSimGetShapeColor))(_getProcAddress(lib,"simGetShapeColor",false, LH));
    SIM_API_SYMBOL(simAuxiliaryConsoleOpen) = (SIM_API_SYMBOL(ptrSimAuxiliaryConsoleOpen))(_getProcAddress(lib,"simAuxiliaryConsoleOpen",false));
    SIM_API_SYMBOL(simCreateShape) = (SIM_API_SYMBOL(ptrSimCreateShape))(_getProcAddress(lib,"simCreateShape",false, LH));
    SIM_API_SYMBOL(simCreateScript) = (SIM_API_SYMBOL(ptrSimCreateScript))(_getProcAddress(lib,"simCreateScript",false, LH));
    SIM_API_SYMBOL(simGetObjectHierarchyOrder) = (SIM_API_SYMBOL(ptrSimGetObjectHierarchyOrder))(_getProcAddress(lib,"simGetObjectHierarchyOrder",false, LH));
    SIM_API_SYMBOL(simSetObjectHierarchyOrder) = (SIM_API_SYMBOL(ptrSimSetObjectHierarchyOrder))(_getProcAddress(lib,"simSetObjectHierarchyOrder",false, LH));
    SIM_API_SYMBOL(simCheckVisionSensorEx) = (SIM_API_SYMBOL(ptrSimCheckVisionSensorEx))(_getProcAddress(lib,"simCheckVisionSensorEx",false, LH));
    SIM_API_SYMBOL(simGetVisionSensorRes) = (SIM_API_SYMBOL(ptrSimGetVisionSensorRes))(_getProcAddress(lib,"simGetVisionSensorRes",false, LH));

    SIM_API_SYMBOL(simGetShapeViz) = (SIM_API_SYMBOL(ptrSimGetShapeViz))(_getProcAddress(lib,"simGetShapeViz",true, LH));
    SIM_API_SYMBOL(simTransformImage) = (SIM_API_SYMBOL(ptrSimTransformImage))(_getProcAddress(lib,"simTransformImage",true));
    SIM_API_SYMBOL(simGetOctreeVoxels) = (SIM_API_SYMBOL(ptrSimGetOctreeVoxels))(_getProcAddress(lib,"simGetOctreeVoxels",true, LH));
    SIM_API_SYMBOL(simGetPointCloudPoints) = (SIM_API_SYMBOL(ptrSimGetPointCloudPoints))(_getProcAddress(lib,"simGetPointCloudPoints",true, LH));
    SIM_API_SYMBOL(simGetObjectMatrix) = (SIM_API_SYMBOL(ptrSimGetObjectMatrix))(_getProcAddress(lib,"simGetObjectMatrix",true, LH));
    SIM_API_SYMBOL(simSetObjectMatrix) = (SIM_API_SYMBOL(ptrSimSetObjectMatrix))(_getProcAddress(lib,"simSetObjectMatrix",true, LH));
    SIM_API_SYMBOL(simGetObjectPose) = (SIM_API_SYMBOL(ptrSimGetObjectPose))(_getProcAddress(lib,"simGetObjectPose",true, LH));
    SIM_API_SYMBOL(simSetObjectPose) = (SIM_API_SYMBOL(ptrSimSetObjectPose))(_getProcAddress(lib,"simSetObjectPose",true, LH));
    SIM_API_SYMBOL(simGetObjectPosition) = (SIM_API_SYMBOL(ptrSimGetObjectPosition))(_getProcAddress(lib,"simGetObjectPosition",true, LH));
    SIM_API_SYMBOL(simSetObjectPosition) = (SIM_API_SYMBOL(ptrSimSetObjectPosition))(_getProcAddress(lib,"simSetObjectPosition",true, LH));
    SIM_API_SYMBOL(simGetObjectOrientation) = (SIM_API_SYMBOL(ptrSimGetObjectOrientation))(_getProcAddress(lib,"simGetObjectOrientation",true, LH));
    SIM_API_SYMBOL(simSetObjectOrientation) = (SIM_API_SYMBOL(ptrSimSetObjectOrientation))(_getProcAddress(lib,"simSetObjectOrientation",true, LH));
    SIM_API_SYMBOL(simGetJointPosition) = (SIM_API_SYMBOL(ptrSimGetJointPosition))(_getProcAddress(lib,"simGetJointPosition",true, LH));
    SIM_API_SYMBOL(simSetJointPosition) = (SIM_API_SYMBOL(ptrSimSetJointPosition))(_getProcAddress(lib,"simSetJointPosition",true, LH));
    SIM_API_SYMBOL(simSetJointTargetPosition) = (SIM_API_SYMBOL(ptrSimSetJointTargetPosition))(_getProcAddress(lib,"simSetJointTargetPosition",true, LH));
    SIM_API_SYMBOL(simGetJointTargetPosition) = (SIM_API_SYMBOL(ptrSimGetJointTargetPosition))(_getProcAddress(lib,"simGetJointTargetPosition",true, LH));
    SIM_API_SYMBOL(simGetObjectChildPose) = (SIM_API_SYMBOL(ptrSimGetObjectChildPose))(_getProcAddress(lib,"simGetObjectChildPose",true, LH));
    SIM_API_SYMBOL(simSetObjectChildPose) = (SIM_API_SYMBOL(ptrSimSetObjectChildPose))(_getProcAddress(lib,"simSetObjectChildPose",true, LH));
    SIM_API_SYMBOL(simGetJointInterval) = (SIM_API_SYMBOL(ptrSimGetJointInterval))(_getProcAddress(lib,"simGetJointInterval",true, LH));
    SIM_API_SYMBOL(simSetJointInterval) = (SIM_API_SYMBOL(ptrSimSetJointInterval))(_getProcAddress(lib,"simSetJointInterval",true, LH));
    SIM_API_SYMBOL(simGetJointTargetForce) = (SIM_API_SYMBOL(ptrSimGetJointTargetForce))(_getProcAddress(lib,"simGetJointTargetForce",true, LH));
    SIM_API_SYMBOL(simSetJointTargetForce) = (SIM_API_SYMBOL(ptrSimSetJointTargetForce))(_getProcAddress(lib,"simSetJointTargetForce",true, LH));
    SIM_API_SYMBOL(simBuildIdentityMatrix) = (SIM_API_SYMBOL(ptrSimBuildIdentityMatrix))(_getProcAddress(lib,"simBuildIdentityMatrix",true));
    SIM_API_SYMBOL(simBuildMatrix) = (SIM_API_SYMBOL(ptrSimBuildMatrix))(_getProcAddress(lib,"simBuildMatrix",true));
    SIM_API_SYMBOL(simBuildPose) = (SIM_API_SYMBOL(ptrSimBuildPose))(_getProcAddress(lib,"simBuildPose",true));
    SIM_API_SYMBOL(simGetEulerAnglesFromMatrix) = (SIM_API_SYMBOL(ptrSimGetEulerAnglesFromMatrix))(_getProcAddress(lib,"simGetEulerAnglesFromMatrix",true));
    SIM_API_SYMBOL(simInvertMatrix) = (SIM_API_SYMBOL(ptrSimInvertMatrix))(_getProcAddress(lib,"simInvertMatrix",true));
    SIM_API_SYMBOL(simMultiplyMatrices) = (SIM_API_SYMBOL(ptrSimMultiplyMatrices))(_getProcAddress(lib,"simMultiplyMatrices",true));
    SIM_API_SYMBOL(simMultiplyPoses) = (SIM_API_SYMBOL(ptrSimMultiplyPoses))(_getProcAddress(lib,"simMultiplyPoses",true));
    SIM_API_SYMBOL(simInvertPose) = (SIM_API_SYMBOL(ptrSimInvertPose))(_getProcAddress(lib,"simInvertPose",true));
    SIM_API_SYMBOL(simInterpolatePoses) = (SIM_API_SYMBOL(ptrSimInterpolatePoses))(_getProcAddress(lib,"simInterpolatePoses",true));
    SIM_API_SYMBOL(simPoseToMatrix) = (SIM_API_SYMBOL(ptrSimPoseToMatrix))(_getProcAddress(lib,"simPoseToMatrix",true));
    SIM_API_SYMBOL(simMatrixToPose) = (SIM_API_SYMBOL(ptrSimMatrixToPose))(_getProcAddress(lib,"simMatrixToPose",true));
    SIM_API_SYMBOL(simInterpolateMatrices) = (SIM_API_SYMBOL(ptrSimInterpolateMatrices))(_getProcAddress(lib,"simInterpolateMatrices",true));
    SIM_API_SYMBOL(simTransformVector) = (SIM_API_SYMBOL(ptrSimTransformVector))(_getProcAddress(lib,"simTransformVector",true));
    SIM_API_SYMBOL(simGetSimulationTime) = (SIM_API_SYMBOL(ptrSimGetSimulationTime))(_getProcAddress(lib,"simGetSimulationTime",true));
    SIM_API_SYMBOL(simGetSystemTime) = (SIM_API_SYMBOL(ptrSimGetSystemTime))(_getProcAddress(lib,"simGetSystemTime",true));
    SIM_API_SYMBOL(simHandleProximitySensor) = (SIM_API_SYMBOL(ptrSimHandleProximitySensor))(_getProcAddress(lib,"simHandleProximitySensor",true, LH));
    SIM_API_SYMBOL(simReadProximitySensor) = (SIM_API_SYMBOL(ptrSimReadProximitySensor))(_getProcAddress(lib,"simReadProximitySensor",true, LH));
    SIM_API_SYMBOL(simHandleDynamics) = (SIM_API_SYMBOL(ptrSimHandleDynamics))(_getProcAddress(lib,"simHandleDynamics",true));
    SIM_API_SYMBOL(simCheckProximitySensor) = (SIM_API_SYMBOL(ptrSimCheckProximitySensor))(_getProcAddress(lib,"simCheckProximitySensor",true, LH));
    SIM_API_SYMBOL(simCheckProximitySensorEx) = (SIM_API_SYMBOL(ptrSimCheckProximitySensorEx))(_getProcAddress(lib,"simCheckProximitySensorEx",true, LH));
    SIM_API_SYMBOL(simCheckProximitySensorEx2) = (SIM_API_SYMBOL(ptrSimCheckProximitySensorEx2))(_getProcAddress(lib,"simCheckProximitySensorEx2",true, LH));
    SIM_API_SYMBOL(simCheckCollisionEx) = (SIM_API_SYMBOL(ptrSimCheckCollisionEx))(_getProcAddress(lib,"simCheckCollisionEx",true, LH));
    SIM_API_SYMBOL(simCheckDistance) = (SIM_API_SYMBOL(ptrSimCheckDistance))(_getProcAddress(lib,"simCheckDistance",true, LH));
    SIM_API_SYMBOL(simSetSimulationTimeStep) = (SIM_API_SYMBOL(ptrSimSetSimulationTimeStep))(_getProcAddress(lib,"simSetSimulationTimeStep",true));
    SIM_API_SYMBOL(simGetSimulationTimeStep) = (SIM_API_SYMBOL(ptrSimGetSimulationTimeStep))(_getProcAddress(lib,"simGetSimulationTimeStep",true));
    SIM_API_SYMBOL(simFloatingViewAdd) = (SIM_API_SYMBOL(ptrSimFloatingViewAdd))(_getProcAddress(lib,"simFloatingViewAdd",true));
    SIM_API_SYMBOL(simHandleGraph) = (SIM_API_SYMBOL(ptrSimHandleGraph))(_getProcAddress(lib,"simHandleGraph",true, LH));
    SIM_API_SYMBOL(simSetGraphStreamTransformation) = (SIM_API_SYMBOL(ptrSimSetGraphStreamTransformation))(_getProcAddress(lib,"simSetGraphStreamTransformation",true, LH));
    SIM_API_SYMBOL(simAddGraphCurve) = (SIM_API_SYMBOL(ptrSimAddGraphCurve))(_getProcAddress(lib,"simAddGraphCurve",true, LH));
    SIM_API_SYMBOL(simSetGraphStreamValue) = (SIM_API_SYMBOL(ptrSimSetGraphStreamValue))(_getProcAddress(lib,"simSetGraphStreamValue",true, LH));
    SIM_API_SYMBOL(simSetJointTargetVelocity) = (SIM_API_SYMBOL(ptrSimSetJointTargetVelocity))(_getProcAddress(lib,"simSetJointTargetVelocity",true, LH));
    SIM_API_SYMBOL(simGetJointTargetVelocity) = (SIM_API_SYMBOL(ptrSimGetJointTargetVelocity))(_getProcAddress(lib,"simGetJointTargetVelocity",true, LH));
    SIM_API_SYMBOL(simScaleObjects) = (SIM_API_SYMBOL(ptrSimScaleObjects))(_getProcAddress(lib,"simScaleObjects",true, LH));
    SIM_API_SYMBOL(simAddDrawingObject) = (SIM_API_SYMBOL(ptrSimAddDrawingObject))(_getProcAddress(lib,"simAddDrawingObject",true, LH));
    SIM_API_SYMBOL(simAddGraphStream) = (SIM_API_SYMBOL(ptrSimAddGraphStream))(_getProcAddress(lib,"simAddGraphStream",true, LH));
    SIM_API_SYMBOL(simAddDrawingObjectItem) = (SIM_API_SYMBOL(ptrSimAddDrawingObjectItem))(_getProcAddress(lib,"simAddDrawingObjectItem",true, LH));
    SIM_API_SYMBOL(simGetObjectSizeFactor) = (SIM_API_SYMBOL(ptrSimGetObjectSizeFactor))(_getProcAddress(lib,"simGetObjectSizeFactor",true, LH));
    SIM_API_SYMBOL(simReadForceSensor) = (SIM_API_SYMBOL(ptrSimReadForceSensor))(_getProcAddress(lib,"simReadForceSensor",true, LH));
    SIM_API_SYMBOL(simGetVelocity) = (SIM_API_SYMBOL(ptrSimGetVelocity))(_getProcAddress(lib,"simGetVelocity",true, LH));
    SIM_API_SYMBOL(simGetObjectVelocity) = (SIM_API_SYMBOL(ptrSimGetObjectVelocity))(_getProcAddress(lib,"simGetObjectVelocity",true, LH));
    SIM_API_SYMBOL(simGetJointVelocity) = (SIM_API_SYMBOL(ptrSimGetJointVelocity))(_getProcAddress(lib,"simGetJointVelocity",true, LH));
    SIM_API_SYMBOL(simAddForceAndTorque) = (SIM_API_SYMBOL(ptrSimAddForceAndTorque))(_getProcAddress(lib,"simAddForceAndTorque",true, LH));
    SIM_API_SYMBOL(simAddForce) = (SIM_API_SYMBOL(ptrSimAddForce))(_getProcAddress(lib,"simAddForce",true, LH));
    SIM_API_SYMBOL(simGetContactInfo) = (SIM_API_SYMBOL(ptrSimGetContactInfo))(_getProcAddress(lib,"simGetContactInfo",true, LH));
    SIM_API_SYMBOL(simImportShape) = (SIM_API_SYMBOL(ptrSimImportShape))(_getProcAddress(lib,"simImportShape",true, LH));
    SIM_API_SYMBOL(simImportMesh) = (SIM_API_SYMBOL(ptrSimImportMesh))(_getProcAddress(lib,"simImportMesh",true));
    SIM_API_SYMBOL(simExportMesh) = (SIM_API_SYMBOL(ptrSimExportMesh))(_getProcAddress(lib,"simExportMesh",true));
    SIM_API_SYMBOL(simCreateMeshShape) = (SIM_API_SYMBOL(ptrSimCreateMeshShape))(_getProcAddress(lib,"simCreateMeshShape",true));
    SIM_API_SYMBOL(simCreatePrimitiveShape) = (SIM_API_SYMBOL(ptrSimCreatePrimitiveShape))(_getProcAddress(lib,"simCreatePrimitiveShape",true, LH));
    SIM_API_SYMBOL(simCreateHeightfieldShape) = (SIM_API_SYMBOL(ptrSimCreateHeightfieldShape))(_getProcAddress(lib,"simCreateHeightfieldShape",true, LH));
    SIM_API_SYMBOL(simGetShapeMesh) = (SIM_API_SYMBOL(ptrSimGetShapeMesh))(_getProcAddress(lib,"simGetShapeMesh",true, LH));
    SIM_API_SYMBOL(simCreateJoint) = (SIM_API_SYMBOL(ptrSimCreateJoint))(_getProcAddress(lib,"simCreateJoint",true, LH));
    SIM_API_SYMBOL(simCreateDummy) = (SIM_API_SYMBOL(ptrSimCreateDummy))(_getProcAddress(lib,"simCreateDummy",true, LH));
    SIM_API_SYMBOL(simCreateProximitySensor) = (SIM_API_SYMBOL(ptrSimCreateProximitySensor))(_getProcAddress(lib,"simCreateProximitySensor",true, LH));
    SIM_API_SYMBOL(simCreateForceSensor) = (SIM_API_SYMBOL(ptrSimCreateForceSensor))(_getProcAddress(lib,"simCreateForceSensor",true, LH));
    SIM_API_SYMBOL(simCreateVisionSensor) = (SIM_API_SYMBOL(ptrSimCreateVisionSensor))(_getProcAddress(lib,"simCreateVisionSensor",true, LH));
    SIM_API_SYMBOL(simGetRotationAxis) = (SIM_API_SYMBOL(ptrSimGetRotationAxis))(_getProcAddress(lib,"simGetRotationAxis",true));
    SIM_API_SYMBOL(simRotateAroundAxis) = (SIM_API_SYMBOL(ptrSimRotateAroundAxis))(_getProcAddress(lib,"simRotateAroundAxis",true));
    SIM_API_SYMBOL(simGetJointForce) = (SIM_API_SYMBOL(ptrSimGetJointForce))(_getProcAddress(lib,"simGetJointForce",true, LH));
    SIM_API_SYMBOL(simCameraFitToView) = (SIM_API_SYMBOL(ptrSimCameraFitToView))(_getProcAddress(lib,"simCameraFitToView",true, LH));
    SIM_API_SYMBOL(simHandleVisionSensor) = (SIM_API_SYMBOL(ptrSimHandleVisionSensor))(_getProcAddress(lib,"simHandleVisionSensor",true, LH));
    SIM_API_SYMBOL(simReadVisionSensor) = (SIM_API_SYMBOL(ptrSimReadVisionSensor))(_getProcAddress(lib,"simReadVisionSensor",true, LH));
    SIM_API_SYMBOL(simCheckVisionSensor) = (SIM_API_SYMBOL(ptrSimCheckVisionSensor))(_getProcAddress(lib,"simCheckVisionSensor",true, LH));
    SIM_API_SYMBOL(simGetVisionSensorImg) = (SIM_API_SYMBOL(ptrSimGetVisionSensorImg))(_getProcAddress(lib,"simGetVisionSensorImg",true, LH));
    SIM_API_SYMBOL(simGetObjectQuaternion) = (SIM_API_SYMBOL(ptrSimGetObjectQuaternion))(_getProcAddress(lib,"simGetObjectQuaternion",true, LH));
    SIM_API_SYMBOL(simSetObjectQuaternion) = (SIM_API_SYMBOL(ptrSimSetObjectQuaternion))(_getProcAddress(lib,"simSetObjectQuaternion",true, LH));
    SIM_API_SYMBOL(simConvexDecompose) = (SIM_API_SYMBOL(ptrSimConvexDecompose))(_getProcAddress(lib,"simConvexDecompose",true, LH));
    SIM_API_SYMBOL(simWriteTexture) = (SIM_API_SYMBOL(ptrSimWriteTexture))(_getProcAddress(lib,"simWriteTexture",true, LH));
    SIM_API_SYMBOL(simCreateTexture) = (SIM_API_SYMBOL(ptrSimCreateTexture))(_getProcAddress(lib,"simCreateTexture",true, LH));
    SIM_API_SYMBOL(simGetShapeGeomInfo) = (SIM_API_SYMBOL(ptrSimGetShapeGeomInfo))(_getProcAddress(lib,"simGetShapeGeomInfo",true, LH));
    SIM_API_SYMBOL(simScaleObject) = (SIM_API_SYMBOL(ptrSimScaleObject))(_getProcAddress(lib,"simScaleObject",true, LH));
    SIM_API_SYMBOL(simSetShapeTexture) = (SIM_API_SYMBOL(ptrSimSetShapeTexture))(_getProcAddress(lib,"simSetShapeTexture",true, LH));
    SIM_API_SYMBOL(simGetQHull) = (SIM_API_SYMBOL(ptrSimGetQHull))(_getProcAddress(lib,"simGetQHull",true));
    SIM_API_SYMBOL(simGetDecimatedMesh) = (SIM_API_SYMBOL(ptrSimGetDecimatedMesh))(_getProcAddress(lib,"simGetDecimatedMesh",true));
    SIM_API_SYMBOL(simComputeMassAndInertia) = (SIM_API_SYMBOL(ptrSimComputeMassAndInertia))(_getProcAddress(lib,"simComputeMassAndInertia",true, LH));
    SIM_API_SYMBOL(simCreateOctree) = (SIM_API_SYMBOL(ptrSimCreateOctree))(_getProcAddress(lib,"simCreateOctree",true, LH));
    SIM_API_SYMBOL(simCreatePointCloud) = (SIM_API_SYMBOL(ptrSimCreatePointCloud))(_getProcAddress(lib,"simCreatePointCloud",true, LH));
    SIM_API_SYMBOL(simSetPointCloudOptions) = (SIM_API_SYMBOL(ptrSimSetPointCloudOptions))(_getProcAddress(lib,"simSetPointCloudOptions",true, LH));
    SIM_API_SYMBOL(simGetPointCloudOptions) = (SIM_API_SYMBOL(ptrSimGetPointCloudOptions))(_getProcAddress(lib,"simGetPointCloudOptions",true, LH));
    SIM_API_SYMBOL(simInsertVoxelsIntoOctree) = (SIM_API_SYMBOL(ptrSimInsertVoxelsIntoOctree))(_getProcAddress(lib,"simInsertVoxelsIntoOctree",true, LH));
    SIM_API_SYMBOL(simRemoveVoxelsFromOctree) = (SIM_API_SYMBOL(ptrSimRemoveVoxelsFromOctree))(_getProcAddress(lib,"simRemoveVoxelsFromOctree",true, LH));
    SIM_API_SYMBOL(simInsertPointsIntoPointCloud) = (SIM_API_SYMBOL(ptrSimInsertPointsIntoPointCloud))(_getProcAddress(lib,"simInsertPointsIntoPointCloud",true, LH));
    SIM_API_SYMBOL(simRemovePointsFromPointCloud) = (SIM_API_SYMBOL(ptrSimRemovePointsFromPointCloud))(_getProcAddress(lib,"simRemovePointsFromPointCloud",true, LH));
    SIM_API_SYMBOL(simIntersectPointsWithPointCloud) = (SIM_API_SYMBOL(ptrSimIntersectPointsWithPointCloud))(_getProcAddress(lib,"simIntersectPointsWithPointCloud",true, LH));
    SIM_API_SYMBOL(simInsertObjectIntoPointCloud) = (SIM_API_SYMBOL(ptrSimInsertObjectIntoPointCloud))(_getProcAddress(lib,"simInsertObjectIntoPointCloud",true, LH));
    SIM_API_SYMBOL(simSubtractObjectFromPointCloud) = (SIM_API_SYMBOL(ptrSimSubtractObjectFromPointCloud))(_getProcAddress(lib,"simSubtractObjectFromPointCloud",true, LH));
    SIM_API_SYMBOL(simCheckOctreePointOccupancy) = (SIM_API_SYMBOL(ptrSimCheckOctreePointOccupancy))(_getProcAddress(lib,"simCheckOctreePointOccupancy",true, LH));
    SIM_API_SYMBOL(simApplyTexture) = (SIM_API_SYMBOL(ptrSimApplyTexture))(_getProcAddress(lib,"simApplyTexture",true, LH));
    SIM_API_SYMBOL(simSetJointDependency) = (SIM_API_SYMBOL(ptrSimSetJointDependency))(_getProcAddress(lib,"simSetJointDependency",true, LH));
    SIM_API_SYMBOL(simGetJointDependency) = (SIM_API_SYMBOL(ptrSimGetJointDependency))(_getProcAddress(lib,"simGetJointDependency",true, LH));
    SIM_API_SYMBOL(simGetShapeMass) = (SIM_API_SYMBOL(ptrSimGetShapeMass))(_getProcAddress(lib,"simGetShapeMass",true, LH));
    SIM_API_SYMBOL(simSetShapeMass) = (SIM_API_SYMBOL(ptrSimSetShapeMass))(_getProcAddress(lib,"simSetShapeMass",true, LH));
    SIM_API_SYMBOL(simGetShapeInertia) = (SIM_API_SYMBOL(ptrSimGetShapeInertia))(_getProcAddress(lib,"simGetShapeInertia",true, LH));
    SIM_API_SYMBOL(simSetShapeInertia) = (SIM_API_SYMBOL(ptrSimSetShapeInertia))(_getProcAddress(lib,"simSetShapeInertia",true, LH));
    SIM_API_SYMBOL(simGenerateShapeFromPath) = (SIM_API_SYMBOL(ptrSimGenerateShapeFromPath))(_getProcAddress(lib,"simGenerateShapeFromPath",true, LH));
    SIM_API_SYMBOL(simGetClosestPosOnPath) = (SIM_API_SYMBOL(ptrSimGetClosestPosOnPath))(_getProcAddress(lib,"simGetClosestPosOnPath",true));
    SIM_API_SYMBOL(_simGetObjectLocalTransformation) = (SIM_API_SYMBOL(ptr_simGetObjectLocalTransformation))(_getProcAddress(lib,"_simGetObjectLocalTransformation",true));
    SIM_API_SYMBOL(_simSetObjectLocalTransformation) = (SIM_API_SYMBOL(ptr_simSetObjectLocalTransformation))(_getProcAddress(lib,"_simSetObjectLocalTransformation",true));
    SIM_API_SYMBOL(_simDynReportObjectCumulativeTransformation) = (SIM_API_SYMBOL(ptr_simDynReportObjectCumulativeTransformation))(_getProcAddress(lib,"_simDynReportObjectCumulativeTransformation",true));
    SIM_API_SYMBOL(_simSetObjectCumulativeTransformation) = (SIM_API_SYMBOL(ptr_simSetObjectCumulativeTransformation))(_getProcAddress(lib,"_simSetObjectCumulativeTransformation",true));
    SIM_API_SYMBOL(_simGetObjectCumulativeTransformation) = (SIM_API_SYMBOL(ptr_simGetObjectCumulativeTransformation))(_getProcAddress(lib,"_simGetObjectCumulativeTransformation",true));
    SIM_API_SYMBOL(_simSetJointVelocity) = (SIM_API_SYMBOL(ptr_simSetJointVelocity))(_getProcAddress(lib,"_simSetJointVelocity",true));
    SIM_API_SYMBOL(_simSetJointPosition) = (SIM_API_SYMBOL(ptr_simSetJointPosition))(_getProcAddress(lib,"_simSetJointPosition",true));
    SIM_API_SYMBOL(_simGetJointPosition) = (SIM_API_SYMBOL(ptr_simGetJointPosition))(_getProcAddress(lib,"_simGetJointPosition",true));
    SIM_API_SYMBOL(_simSetDynamicMotorPositionControlTargetPosition) = (SIM_API_SYMBOL(ptr_simSetDynamicMotorPositionControlTargetPosition))(_getProcAddress(lib,"_simSetDynamicMotorPositionControlTargetPosition",true));
    SIM_API_SYMBOL(_simGetInitialDynamicVelocity) = (SIM_API_SYMBOL(ptr_simGetInitialDynamicVelocity))(_getProcAddress(lib,"_simGetInitialDynamicVelocity",true));
    SIM_API_SYMBOL(_simSetInitialDynamicVelocity) = (SIM_API_SYMBOL(ptr_simSetInitialDynamicVelocity))(_getProcAddress(lib,"_simSetInitialDynamicVelocity",true));
    SIM_API_SYMBOL(_simGetInitialDynamicAngVelocity) = (SIM_API_SYMBOL(ptr_simGetInitialDynamicAngVelocity))(_getProcAddress(lib,"_simGetInitialDynamicAngVelocity",true));
    SIM_API_SYMBOL(_simSetInitialDynamicAngVelocity) = (SIM_API_SYMBOL(ptr_simSetInitialDynamicAngVelocity))(_getProcAddress(lib,"_simSetInitialDynamicAngVelocity",true));
    SIM_API_SYMBOL(_simSetShapeDynamicVelocity) = (SIM_API_SYMBOL(ptr_simSetShapeDynamicVelocity))(_getProcAddress(lib,"_simSetShapeDynamicVelocity",true));
    SIM_API_SYMBOL(_simGetAdditionalForceAndTorque) = (SIM_API_SYMBOL(ptr_simGetAdditionalForceAndTorque))(_getProcAddress(lib,"_simGetAdditionalForceAndTorque",true));
    SIM_API_SYMBOL(_simGetJointPositionInterval) = (SIM_API_SYMBOL(ptr_simGetJointPositionInterval))(_getProcAddress(lib,"_simGetJointPositionInterval",true));
    SIM_API_SYMBOL(_simGetDynamicMotorTargetPosition) = (SIM_API_SYMBOL(ptr_simGetDynamicMotorTargetPosition))(_getProcAddress(lib,"_simGetDynamicMotorTargetPosition",true));
    SIM_API_SYMBOL(_simGetDynamicMotorTargetVelocity) = (SIM_API_SYMBOL(ptr_simGetDynamicMotorTargetVelocity))(_getProcAddress(lib,"_simGetDynamicMotorTargetVelocity",true));
    SIM_API_SYMBOL(_simGetDynamicMotorMaxForce) = (SIM_API_SYMBOL(ptr_simGetDynamicMotorMaxForce))(_getProcAddress(lib,"_simGetDynamicMotorMaxForce",true));
    SIM_API_SYMBOL(_simGetDynamicMotorUpperLimitVelocity) = (SIM_API_SYMBOL(ptr_simGetDynamicMotorUpperLimitVelocity))(_getProcAddress(lib,"_simGetDynamicMotorUpperLimitVelocity",true));
    SIM_API_SYMBOL(_simSetDynamicMotorReflectedPositionFromDynamicEngine) = (SIM_API_SYMBOL(ptr_simSetDynamicMotorReflectedPositionFromDynamicEngine))(_getProcAddress(lib,"_simSetDynamicMotorReflectedPositionFromDynamicEngine",true));
    SIM_API_SYMBOL(_simSetJointSphericalTransformation) = (SIM_API_SYMBOL(ptr_simSetJointSphericalTransformation))(_getProcAddress(lib,"_simSetJointSphericalTransformation",true));
    SIM_API_SYMBOL(_simAddForceSensorCumulativeForcesAndTorques) = (SIM_API_SYMBOL(ptr_simAddForceSensorCumulativeForcesAndTorques))(_getProcAddress(lib,"_simAddForceSensorCumulativeForcesAndTorques",true));
    SIM_API_SYMBOL(_simAddJointCumulativeForcesOrTorques) = (SIM_API_SYMBOL(ptr_simAddJointCumulativeForcesOrTorques))(_getProcAddress(lib,"_simAddJointCumulativeForcesOrTorques",true));
    SIM_API_SYMBOL(_simGetMass) = (SIM_API_SYMBOL(ptr_simGetMass))(_getProcAddress(lib,"_simGetMass",true));
    SIM_API_SYMBOL(_simGetLocalInertiaInfo) = (SIM_API_SYMBOL(ptr_simGetLocalInertiaInfo))(_getProcAddress(lib,"_simGetLocalInertiaInfo",true));
    SIM_API_SYMBOL(_simGetPurePrimitiveSizes) = (SIM_API_SYMBOL(ptr_simGetPurePrimitiveSizes))(_getProcAddress(lib,"_simGetPurePrimitiveSizes",true));
    SIM_API_SYMBOL(_simGetVerticesLocalFrame) = (SIM_API_SYMBOL(ptr_simGetVerticesLocalFrame))(_getProcAddress(lib,"_simGetVerticesLocalFrame",true));
    SIM_API_SYMBOL(_simGetHeightfieldData) = (SIM_API_SYMBOL(ptr_simGetHeightfieldData))(_getProcAddress(lib,"_simGetHeightfieldData",true));
    SIM_API_SYMBOL(_simGetCumulativeMeshes) = (SIM_API_SYMBOL(ptr_simGetCumulativeMeshes))(_getProcAddress(lib,"_simGetCumulativeMeshes",true));
    SIM_API_SYMBOL(_simGetGravity) = (SIM_API_SYMBOL(ptr_simGetGravity))(_getProcAddress(lib,"_simGetGravity",true));
    SIM_API_SYMBOL(_simGetDistanceBetweenEntitiesIfSmaller) = (SIM_API_SYMBOL(ptr_simGetDistanceBetweenEntitiesIfSmaller))(_getProcAddress(lib,"_simGetDistanceBetweenEntitiesIfSmaller",true, LH));
    SIM_API_SYMBOL(_simHandleJointControl) = (SIM_API_SYMBOL(ptr_simHandleJointControl))(_getProcAddress(lib,"_simHandleJointControl",true));
    SIM_API_SYMBOL(_simHandleCustomContact) = (SIM_API_SYMBOL(ptr_simHandleCustomContact))(_getProcAddress(lib,"_simHandleCustomContact",true, LH));
    SIM_API_SYMBOL(_simGetPureHollowScaling) = (SIM_API_SYMBOL(ptr_simGetPureHollowScaling))(_getProcAddress(lib,"_simGetPureHollowScaling",true));
    SIM_API_SYMBOL(_simDynCallback) = (SIM_API_SYMBOL(ptr_simDynCallback))(_getProcAddress(lib,"_simDynCallback",true));

    char *ps=std::getenv("COPPELIASIMPLUGIN_IGNORE_MISSING_SYMBOLS");
    if (ps!=nullptr)
        return(1);

    char couldNotFind[]="Could not find function";

    if (SIM_API_SYMBOL(simSetBoolProperty) == nullptr)
    {
        printf("%s simSetBoolProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetBoolProperty) == nullptr)
    {
        printf("%s simGetBoolProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetIntProperty) == nullptr)
    {
        printf("%s simSetIntProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetIntProperty) == nullptr)
    {
        printf("%s simGetIntProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetLongProperty) == nullptr)
    {
        printf("%s simSetLongProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetLongProperty) == nullptr)
    {
        printf("%s simGetLongProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetFloatProperty) == nullptr)
    {
        printf("%s simSetFloatProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetFloatProperty) == nullptr)
    {
        printf("%s simGetFloatProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetStringProperty) == nullptr)
    {
        printf("%s simSetStringProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStringProperty) == nullptr)
    {
        printf("%s simGetStringProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetTableProperty) == nullptr)
    {
        printf("%s simSetTableProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetTableProperty) == nullptr)
    {
        printf("%s simGetTableProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetBufferProperty) == nullptr)
    {
        printf("%s simSetBufferProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetBufferProperty) == nullptr)
    {
        printf("%s simGetBufferProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetIntArray2Property) == nullptr)
    {
        printf("%s simSetIntArray2Property\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetIntArray2Property) == nullptr)
    {
        printf("%s simGetIntArray2Property\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetVector2Property) == nullptr)
    {
        printf("%s simSetVector2Property\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetVector2Property) == nullptr)
    {
        printf("%s simGetVector2Property\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetVector3Property) == nullptr)
    {
        printf("%s simSetVector3Property\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetVector3Property) == nullptr)
    {
        printf("%s simGetVector3Property\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetQuaternionProperty) == nullptr)
    {
        printf("%s simSetQuaternionProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetQuaternionProperty) == nullptr)
    {
        printf("%s simGetQuaternionProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetPoseProperty) == nullptr)
    {
        printf("%s simSetPoseProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetPoseProperty) == nullptr)
    {
        printf("%s simGetPoseProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetColorProperty) == nullptr)
    {
        printf("%s simSetColorProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetColorProperty) == nullptr)
    {
        printf("%s simGetColorProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetFloatArrayProperty) == nullptr)
    {
        printf("%s simSetFloatArrayProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetFloatArrayProperty) == nullptr)
    {
        printf("%s simGetFloatArrayProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetIntArrayProperty) == nullptr)
    {
        printf("%s simSetIntArrayProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetIntArrayProperty) == nullptr)
    {
        printf("%s simGetIntArrayProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRemoveProperty) == nullptr)
    {
        printf("%s simRemoveProperty\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetPropertyName) == nullptr)
    {
        printf("%s simGetPropertyName\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetPropertyInfo) == nullptr)
    {
        printf("%s simGetPropertyInfo\n", couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRegCallback) == nullptr)
    {
        printf("%s simRegCallback\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRunGui) == nullptr)
    {
        printf("%s simRunGui\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simInitialize) == nullptr)
    {
        printf("%s simInitialize\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simDeinitialize) == nullptr)
    {
        printf("%s simDeinitialize\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPostExitRequest) == nullptr)
    {
        printf("%s simPostExitRequest\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetExitRequest) == nullptr)
    {
        printf("%s simGetExitRequest\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simLoop) == nullptr)
    {
        printf("%s simLoop\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simTest) == nullptr)
    {
        printf("%s simTest\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetSimulatorMessage) == nullptr)
    {
        printf("%s simGetSimulatorMessage\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetMainWindow) == nullptr)
    {
        printf("%s simGetMainWindow\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetLastError) == nullptr)
    {
        printf("%s simGetLastError\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetLastInfo) == nullptr)
    {
        printf("%s simGetLastInfo\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObject) == nullptr)
    {
        printf("%s simGetObject\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectUid) == nullptr)
    {
        printf("%s simGetObjectUid\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectFromUid) == nullptr)
    {
        printf("%s simGetObjectFromUid\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetScriptHandleEx) == nullptr)
    {
        printf("%s simGetScriptHandleEx\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRemoveObjects) == nullptr)
    {
        printf("%s simRemoveObjects\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRemoveModel) == nullptr)
    {
        printf("%s simRemoveModel\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectAlias) == nullptr)
    {
        printf("%s simGetObjectAlias\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetObjectAlias) == nullptr)
    {
        printf("%s simSetObjectAlias\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectMatrix) == nullptr)
    {
        printf("%s simGetObjectMatrix\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetObjectMatrix) == nullptr)
    {
        printf("%s simSetObjectMatrix\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectPose) == nullptr)
    {
        printf("%s simGetObjectPose\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetObjectPose) == nullptr)
    {
        printf("%s simSetObjectPose\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectPosition) == nullptr)
    {
        printf("%s simGetObjectPosition\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetObjectPosition) == nullptr)
    {
        printf("%s simSetObjectPosition\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectOrientation) == nullptr)
    {
        printf("%s simGetObjectOrientation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetObjectOrientation) == nullptr)
    {
        printf("%s simSetObjectOrientation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetJointPosition) == nullptr)
    {
        printf("%s simGetJointPosition\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetJointPosition) == nullptr)
    {
        printf("%s simSetJointPosition\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetJointTargetPosition) == nullptr)
    {
        printf("%s simSetJointTargetPosition\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetJointTargetPosition) == nullptr)
    {
        printf("%s simGetJointTargetPosition\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectChildPose) == nullptr)
    {
        printf("%s simGetObjectChildPose\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetObjectChildPose) == nullptr)
    {
        printf("%s simSetObjectChildPose\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetJointInterval) == nullptr)
    {
        printf("%s simGetJointInterval\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetJointInterval) == nullptr)
    {
        printf("%s simSetJointInterval\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectParent) == nullptr)
    {
        printf("%s simGetObjectParent\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectChild) == nullptr)
    {
        printf("%s simGetObjectChild\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetObjectParent) == nullptr)
    {
        printf("%s simSetObjectParent\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectType) == nullptr)
    {
        printf("%s simGetObjectType\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetJointType) == nullptr)
    {
        printf("%s simGetJointType\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simBuildIdentityMatrix) == nullptr)
    {
        printf("%s simBuildIdentityMatrix\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simBuildMatrix) == nullptr)
    {
        printf("%s simBuildMatrix\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simBuildPose) == nullptr)
    {
        printf("%s simBuildPose\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetEulerAnglesFromMatrix) == nullptr)
    {
        printf("%s simGetEulerAnglesFromMatrix\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simInvertMatrix) == nullptr)
    {
        printf("%s simInvertMatrix\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simMultiplyMatrices) == nullptr)
    {
        printf("%s simMultiplyMatrices\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simMultiplyPoses) == nullptr)
    {
        printf("%s simMultiplyPoses\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simInvertPose) == nullptr)
    {
        printf("%s simInvertPose\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simInterpolatePoses) == nullptr)
    {
        printf("%s simInterpolatePoses\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPoseToMatrix) == nullptr)
    {
        printf("%s simPoseToMatrix\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simMatrixToPose) == nullptr)
    {
        printf("%s simMatrixToPose\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simInterpolateMatrices) == nullptr)
    {
        printf("%s simInterpolateMatrices\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simTransformVector) == nullptr)
    {
        printf("%s simTransformVector\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simReservedCommand) == nullptr)
    {
        printf("%s simReservedCommand\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetSimulationTime) == nullptr)
    {
        printf("%s simGetSimulationTime\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetSimulationState) == nullptr)
    {
        printf("%s simGetSimulationState\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetSystemTime) == nullptr)
    {
        printf("%s simGetSystemTime\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simLoadScene) == nullptr)
    {
        printf("%s simLoadScene\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCloseScene) == nullptr)
    {
        printf("%s simCloseScene\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSaveScene) == nullptr)
    {
        printf("%s simSaveScene\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simLoadModel) == nullptr)
    {
        printf("%s simLoadModel\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSaveModel) == nullptr)
    {
        printf("%s simSaveModel\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simDoesFileExist) == nullptr)
    {
        printf("%s simDoesFileExist\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectSel) == nullptr)
    {
        printf("%s simGetObjectSel\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetObjectSel) == nullptr)
    {
        printf("%s simSetObjectSel\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simHandleProximitySensor) == nullptr)
    {
        printf("%s simHandleProximitySensor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simReadProximitySensor) == nullptr)
    {
        printf("%s simReadProximitySensor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simHandleDynamics) == nullptr)
    {
        printf("%s simHandleDynamics\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simResetScript) == nullptr)
    {
        printf("%s simResetScript\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRefreshDialogs) == nullptr)
    {
        printf("%s simRefreshDialogs\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simResetProximitySensor) == nullptr)
    {
        printf("%s simResetProximitySensor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCheckProximitySensor) == nullptr)
    {
        printf("%s simCheckProximitySensor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCheckProximitySensorEx) == nullptr)
    {
        printf("%s simCheckProximitySensorEx\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCheckProximitySensorEx2) == nullptr)
    {
        printf("%s simCheckProximitySensorEx2\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateBuffer) == nullptr)
    {
        printf("%s simCreateBuffer\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simReleaseBuffer) == nullptr)
    {
        printf("%s simReleaseBuffer\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCheckCollision) == nullptr)
    {
        printf("%s simCheckCollision\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCheckCollisionEx) == nullptr)
    {
        printf("%s simCheckCollisionEx\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCheckDistance) == nullptr)
    {
        printf("%s simCheckDistance\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetSimulationTimeStep) == nullptr)
    {
        printf("%s simSetSimulationTimeStep\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetSimulationTimeStep) == nullptr)
    {
        printf("%s simGetSimulationTimeStep\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetRealTimeSimulation) == nullptr)
    {
        printf("%s simGetRealTimeSimulation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simStartSimulation) == nullptr)
    {
        printf("%s simStartSimulation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simStopSimulation) == nullptr)
    {
        printf("%s simStopSimulation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPauseSimulation) == nullptr)
    {
        printf("%s simPauseSimulation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simFloatingViewAdd) == nullptr)
    {
        printf("%s simFloatingViewAdd\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simFloatingViewRemove) == nullptr)
    {
        printf("%s simFloatingViewRemove\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAdjustView) == nullptr)
    {
        printf("%s simAdjustView\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetLastError) == nullptr)
    {
        printf("%s simSetLastError\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simHandleGraph) == nullptr)
    {
        printf("%s simHandleGraph\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simResetGraph) == nullptr)
    {
        printf("%s simResetGraph\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAddGraphStream) == nullptr)
    {
        printf("%s simAddGraphStream\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simDestroyGraphCurve) == nullptr)
    {
        printf("%s simDestroyGraphCurve\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetGraphStreamTransformation) == nullptr)
    {
        printf("%s simSetGraphStreamTransformation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simDuplicateGraphCurveToStatic) == nullptr)
    {
        printf("%s simDuplicateGraphCurveToStatic\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAddGraphCurve) == nullptr)
    {
        printf("%s simAddGraphCurve\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetGraphStreamValue) == nullptr)
    {
        printf("%s simSetGraphStreamValue\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetNavigationMode) == nullptr)
    {
        printf("%s simSetNavigationMode\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetNavigationMode) == nullptr)
    {
        printf("%s simGetNavigationMode\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetPage) == nullptr)
    {
        printf("%s simSetPage\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetPage) == nullptr)
    {
        printf("%s simGetPage\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRegisterScriptCallbackFunction) == nullptr)
    {
        printf("%s simRegisterScriptCallbackFunction\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRegisterScriptVariable) == nullptr)
    {
        printf("%s simRegisterScriptVariable\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRegisterScriptFuncHook) == nullptr)
    {
        printf("%s simRegisterScriptFuncHook\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetJointTargetVelocity) == nullptr)
    {
        printf("%s simSetJointTargetVelocity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetJointTargetVelocity) == nullptr)
    {
        printf("%s simGetJointTargetVelocity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCopyPasteObjects) == nullptr)
    {
        printf("%s simCopyPasteObjects\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simScaleObjects) == nullptr)
    {
        printf("%s simScaleObjects\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAddDrawingObject) == nullptr)
    {
        printf("%s simAddDrawingObject\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRemoveDrawingObject) == nullptr)
    {
        printf("%s simRemoveDrawingObject\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAddDrawingObjectItem) == nullptr)
    {
        printf("%s simAddDrawingObjectItem\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectSizeFactor) == nullptr)
    {
        printf("%s simGetObjectSizeFactor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAnnounceSceneContentChange) == nullptr)
    {
        printf("%s simAnnounceSceneContentChange\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simReadForceSensor) == nullptr)
    {
        printf("%s simReadForceSensor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetVelocity) == nullptr)
    {
        printf("%s simGetVelocity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectVelocity) == nullptr)
    {
        printf("%s simGetObjectVelocity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetJointVelocity) == nullptr)
    {
        printf("%s simGetJointVelocity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAddForceAndTorque) == nullptr)
    {
        printf("%s simAddForceAndTorque\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAddForce) == nullptr)
    {
        printf("%s simAddForce\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetExplicitHandling) == nullptr)
    {
        printf("%s simSetExplicitHandling\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetExplicitHandling) == nullptr)
    {
        printf("%s simGetExplicitHandling\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetLinkDummy) == nullptr)
    {
        printf("%s simGetLinkDummy\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetLinkDummy) == nullptr)
    {
        printf("%s simSetLinkDummy\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetObjectColor) == nullptr)
    {
        printf("%s simSetObjectColor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectColor) == nullptr)
    {
        printf("%s simGetObjectColor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetShapeColor) == nullptr)
    {
        printf("%s simSetShapeColor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetShapeColor) == nullptr)
    {
        printf("%s simGetShapeColor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simResetDynamicObject) == nullptr)
    {
        printf("%s simResetDynamicObject\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetJointMode) == nullptr)
    {
        printf("%s simSetJointMode\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetJointMode) == nullptr)
    {
        printf("%s simGetJointMode\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSerialOpen) == nullptr)
    {
        printf("%s simSerialOpen\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSerialClose) == nullptr)
    {
        printf("%s simSerialClose\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSerialSend) == nullptr)
    {
        printf("%s simSerialSend\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSerialRead) == nullptr)
    {
        printf("%s simSerialRead\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSerialCheck) == nullptr)
    {
        printf("%s simSerialCheck\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetContactInfo) == nullptr)
    {
        printf("%s simGetContactInfo\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAuxiliaryConsoleOpen) == nullptr)
    {
        printf("%s simAuxiliaryConsoleOpen\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAuxiliaryConsoleClose) == nullptr)
    {
        printf("%s simAuxiliaryConsoleClose\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAuxiliaryConsoleShow) == nullptr)
    {
        printf("%s simAuxiliaryConsoleShow\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAuxiliaryConsolePrint) == nullptr)
    {
        printf("%s simAuxiliaryConsolePrint\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simImportShape) == nullptr)
    {
        printf("%s simImportShape\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simImportMesh) == nullptr)
    {
        printf("%s simImportMesh\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simExportMesh) == nullptr)
    {
        printf("%s simExportMesh\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateShape) == nullptr)
    {
        printf("%s simCreateShape\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateMeshShape) == nullptr)
    {
        printf("%s simCreateMeshShape\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreatePrimitiveShape) == nullptr)
    {
        printf("%s simCreatePrimitiveShape\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateHeightfieldShape) == nullptr)
    {
        printf("%s simCreateHeightfieldShape\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetShapeMesh) == nullptr)
    {
        printf("%s simGetShapeMesh\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateJoint) == nullptr)
    {
        printf("%s simCreateJoint\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateDummy) == nullptr)
    {
        printf("%s simCreateDummy\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateScript) == nullptr)
    {
        printf("%s simCreateScript\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectHierarchyOrder) == nullptr)
    {
        printf("%s simGetObjectHierarchyOrder\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetObjectHierarchyOrder) == nullptr)
    {
        printf("%s simSetObjectHierarchyOrder\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateProximitySensor) == nullptr)
    {
        printf("%s simCreateProximitySensor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateVisionSensor) == nullptr)
    {
        printf("%s simCreateVisionSensor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateForceSensor) == nullptr)
    {
        printf("%s simCreateForceSensor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetRotationAxis) == nullptr)
    {
        printf("%s simGetRotationAxis\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRotateAroundAxis) == nullptr)
    {
        printf("%s simRotateAroundAxis\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetJointForce) == nullptr)
    {
        printf("%s simGetJointForce\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetJointTargetForce) == nullptr)
    {
        printf("%s simGetJointTargetForce\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetJointTargetForce) == nullptr)
    {
        printf("%s simSetJointTargetForce\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCameraFitToView) == nullptr)
    {
        printf("%s simCameraFitToView\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simIsHandle) == nullptr)
    {
        printf("%s simIsHandle\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simHandleVisionSensor) == nullptr)
    {
        printf("%s simHandleVisionSensor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simReadVisionSensor) == nullptr)
    {
        printf("%s simReadVisionSensor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simResetVisionSensor) == nullptr)
    {
        printf("%s simResetVisionSensor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCheckVisionSensor) == nullptr)
    {
        printf("%s simCheckVisionSensor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCheckVisionSensorEx) == nullptr)
    {
        printf("%s simCheckVisionSensorEx\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetVisionSensorImg) == nullptr)
    {
        printf("%s simGetVisionSensorImg\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetVisionSensorRes) == nullptr)
    {
        printf("%s simGetVisionSensorRes\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetVisionSensorImg) == nullptr)
    {
        printf("%s simSetVisionSensorImg\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetVisionSensorDepth) == nullptr)
    {
        printf("%s simGetVisionSensorDepth\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetVisionSensorDepth) == nullptr)
    {
        printf("%s _simSetVisionSensorDepth\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectQuaternion) == nullptr)
    {
        printf("%s simGetObjectQuaternion\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetObjectQuaternion) == nullptr)
    {
        printf("%s simSetObjectQuaternion\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRuckigPos) == nullptr)
    {
        printf("%s simRuckigPos\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRuckigVel) == nullptr)
    {
        printf("%s simRuckigVel\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRuckigStep) == nullptr)
    {
        printf("%s simRuckigStep\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRuckigRemove) == nullptr)
    {
        printf("%s simRuckigRemove\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGroupShapes) == nullptr)
    {
        printf("%s simGroupShapes\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simUngroupShape) == nullptr)
    {
        printf("%s simUngroupShape\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simConvexDecompose) == nullptr)
    {
        printf("%s simConvexDecompose\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simQuitSimulator) == nullptr)
    {
        printf("%s simQuitSimulator\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetShapeMaterial) == nullptr)
    {
        printf("%s simSetShapeMaterial\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetTextureId) == nullptr)
    {
        printf("%s simGetTextureId\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simReadTexture) == nullptr)
    {
        printf("%s simReadTexture\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simWriteTexture) == nullptr)
    {
        printf("%s simWriteTexture\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateTexture) == nullptr)
    {
        printf("%s simCreateTexture\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetShapeGeomInfo) == nullptr)
    {
        printf("%s simGetShapeGeomInfo\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjects) == nullptr)
    {
        printf("%s simGetObjects\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetObjectsInTree) == nullptr)
    {
        printf("%s simGetObjectsInTree\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simScaleObject) == nullptr)
    {
        printf("%s simScaleObject\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetShapeTexture) == nullptr)
    {
        printf("%s simSetShapeTexture\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetShapeTextureId) == nullptr)
    {
        printf("%s simGetShapeTextureId\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateCollectionEx) == nullptr)
    {
        printf("%s simCreateCollectionEx\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAddItemToCollection) == nullptr)
    {
        printf("%s simAddItemToCollection\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simDestroyCollection) == nullptr)
    {
        printf("%s simDestroyCollection\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetCollectionObjects) == nullptr)
    {
        printf("%s simGetCollectionObjects\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simAlignShapeBB) == nullptr)
    {
        printf("%s simAlignShapeBB\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRelocateShapeFrame) == nullptr)
    {
        printf("%s simRelocateShapeFrame\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSaveImage) == nullptr)
    {
        printf("%s simSaveImage\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simLoadImage) == nullptr)
    {
        printf("%s simLoadImage\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetScaledImage) == nullptr)
    {
        printf("%s simGetScaledImage\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simTransformImage) == nullptr)
    {
        printf("%s simTransformImage\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetQHull) == nullptr)
    {
        printf("%s simGetQHull\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetDecimatedMesh) == nullptr)
    {
        printf("%s simGetDecimatedMesh\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCallScriptFunctionEx) == nullptr)
    {
        printf("%s simCallScriptFunctionEx\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetExtensionString) == nullptr)
    {
        printf("%s simGetExtensionString\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simComputeMassAndInertia) == nullptr)
    {
        printf("%s simComputeMassAndInertia\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateStack) == nullptr)
    {
        printf("%s simCreateStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simReleaseStack) == nullptr)
    {
        printf("%s simReleaseStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCopyStack) == nullptr)
    {
        printf("%s simCopyStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushNullOntoStack) == nullptr)
    {
        printf("%s simPushNullOntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushBoolOntoStack) == nullptr)
    {
        printf("%s simPushBoolOntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushInt32OntoStack) == nullptr)
    {
        printf("%s simPushInt32OntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushInt64OntoStack) == nullptr)
    {
        printf("%s simPushInt64OntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushFloatOntoStack) == nullptr)
    {
        printf("%s simPushFloatOntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushDoubleOntoStack) == nullptr)
    {
        printf("%s simPushDoubleOntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushTextOntoStack) == nullptr)
    {
        printf("%s simPushTextOntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushStringOntoStack) == nullptr)
    {
        printf("%s simPushStringOntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushBufferOntoStack) == nullptr)
    {
        printf("%s simPushBufferOntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushUInt8TableOntoStack) == nullptr)
    {
        printf("%s simPushUInt8TableOntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushInt32TableOntoStack) == nullptr)
    {
        printf("%s simPushInt32TableOntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushInt64TableOntoStack) == nullptr)
    {
        printf("%s simPushInt64TableOntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushFloatTableOntoStack) == nullptr)
    {
        printf("%s simPushFloatTableOntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushDoubleTableOntoStack) == nullptr)
    {
        printf("%s simPushDoubleTableOntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPushTableOntoStack) == nullptr)
    {
        printf("%s simPushTableOntoStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simInsertDataIntoStackTable) == nullptr)
    {
        printf("%s simInsertDataIntoStackTable\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackSize) == nullptr)
    {
        printf("%s simGetStackSize\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPopStackItem) == nullptr)
    {
        printf("%s simPopStackItem\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simMoveStackItemToTop) == nullptr)
    {
        printf("%s simMoveStackItemToTop\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackItemType) == nullptr)
    {
        printf("%s simGetStackItemType\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackStringType) == nullptr)
    {
        printf("%s simGetStackStringType\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackBoolValue) == nullptr)
    {
        printf("%s simGetStackBoolValue\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackInt32Value) == nullptr)
    {
        printf("%s simGetStackInt32Value\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackInt64Value) == nullptr)
    {
        printf("%s simGetStackInt64Value\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackFloatValue) == nullptr)
    {
        printf("%s simGetStackFloatValue\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackDoubleValue) == nullptr)
    {
        printf("%s simGetStackDoubleValue\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackStringValue) == nullptr)
    {
        printf("%s simGetStackStringValue\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackTableInfo) == nullptr)
    {
        printf("%s simGetStackTableInfo\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackUInt8Table) == nullptr)
    {
        printf("%s simGetStackUInt8Table\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackInt32Table) == nullptr)
    {
        printf("%s simGetStackInt32Table\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackInt64Table) == nullptr)
    {
        printf("%s simGetStackInt64Table\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackFloatTable) == nullptr)
    {
        printf("%s simGetStackFloatTable\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetStackDoubleTable) == nullptr)
    {
        printf("%s simGetStackDoubleTable\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simUnfoldStackTable) == nullptr)
    {
        printf("%s simUnfoldStackTable\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simDebugStack) == nullptr)
    {
        printf("%s simDebugStack\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreateOctree) == nullptr)
    {
        printf("%s simCreateOctree\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCreatePointCloud) == nullptr)
    {
        printf("%s simCreatePointCloud\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetPointCloudOptions) == nullptr)
    {
        printf("%s simSetPointCloudOptions\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetPointCloudOptions) == nullptr)
    {
        printf("%s simGetPointCloudOptions\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simInsertVoxelsIntoOctree) == nullptr)
    {
        printf("%s simInsertVoxelsIntoOctree\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRemoveVoxelsFromOctree) == nullptr)
    {
        printf("%s simRemoveVoxelsFromOctree\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simInsertPointsIntoPointCloud) == nullptr)
    {
        printf("%s simInsertPointsIntoPointCloud\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simRemovePointsFromPointCloud) == nullptr)
    {
        printf("%s simRemovePointsFromPointCloud\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simIntersectPointsWithPointCloud) == nullptr)
    {
        printf("%s simIntersectPointsWithPointCloud\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetOctreeVoxels) == nullptr)
    {
        printf("%s simGetOctreeVoxels\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetPointCloudPoints) == nullptr)
    {
        printf("%s simGetPointCloudPoints\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simInsertObjectIntoOctree) == nullptr)
    {
        printf("%s simInsertObjectIntoOctree\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSubtractObjectFromOctree) == nullptr)
    {
        printf("%s simSubtractObjectFromOctree\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simInsertObjectIntoPointCloud) == nullptr)
    {
        printf("%s simInsertObjectIntoPointCloud\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSubtractObjectFromPointCloud) == nullptr)
    {
        printf("%s simSubtractObjectFromPointCloud\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCheckOctreePointOccupancy) == nullptr)
    {
        printf("%s simCheckOctreePointOccupancy\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simOpenTextEditor) == nullptr)
    {
        printf("%s simOpenTextEditor\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simPackTable) == nullptr)
    {
        printf("%s simPackTable\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simUnpackTable) == nullptr)
    {
        printf("%s simUnpackTable\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetReferencedHandles) == nullptr)
    {
        printf("%s simSetReferencedHandles\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetReferencedHandles) == nullptr)
    {
        printf("%s simGetReferencedHandles\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetShapeViz) == nullptr)
    {
        printf("%s simGetShapeViz\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simExecuteScriptString) == nullptr)
    {
        printf("%s simExecuteScriptString\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetApiFunc) == nullptr)
    {
        printf("%s simGetApiFunc\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetApiInfo) == nullptr)
    {
        printf("%s simGetApiInfo\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetPluginName) == nullptr)
    {
        printf("%s simGetPluginName\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetPluginInfo) == nullptr)
    {
        printf("%s simSetPluginInfo\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetPluginInfo) == nullptr)
    {
        printf("%s simGetPluginInfo\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simEventNotification) == nullptr)
    {
        printf("%s simEventNotification\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simApplyTexture) == nullptr)
    {
        printf("%s simApplyTexture\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetJointDependency) == nullptr)
    {
        printf("%s simSetJointDependency\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetJointDependency) == nullptr)
    {
        printf("%s simGetJointDependency\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetShapeMass) == nullptr)
    {
        printf("%s simGetShapeMass\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetShapeMass) == nullptr)
    {
        printf("%s simSetShapeMass\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetShapeInertia) == nullptr)
    {
        printf("%s simGetShapeInertia\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simSetShapeInertia) == nullptr)
    {
        printf("%s simSetShapeInertia\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simIsDynamicallyEnabled) == nullptr)
    {
        printf("%s simIsDynamicallyEnabled\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGenerateShapeFromPath) == nullptr)
    {
        printf("%s simGenerateShapeFromPath\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simGetClosestPosOnPath) == nullptr)
    {
        printf("%s simGetClosestPosOnPath\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simInitScript) == nullptr)
    {
        printf("%s simInitScript\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simModuleEntry) == nullptr)
    {
        printf("%s simModuleEntry\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(simCheckExecAuthorization) == nullptr)
    {
        printf("%s simCheckExecAuthorization\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetDynamicSimulationIconCode) == nullptr)
    {
        printf("%s _simSetDynamicSimulationIconCode\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetDynamicObjectFlagForVisualization) == nullptr)
    {
        printf("%s _simSetDynamicObjectFlagForVisualization\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetObjectListSize) == nullptr)
    {
        printf("%s _simGetObjectListSize\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetObjectFromIndex) == nullptr)
    {
        printf("%s _simGetObjectFromIndex\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetObjectID) == nullptr)
    {
        printf("%s _simGetObjectID\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetObjectType) == nullptr)
    {
        printf("%s _simGetObjectType\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetObjectChildren) == nullptr)
    {
        printf("%s _simGetObjectChildren\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetParentObject) == nullptr)
    {
        printf("%s _simGetParentObject\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetObject) == nullptr)
    {
        printf("%s _simGetObject\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetIkGroupObject) == nullptr)
    {
        printf("%s _simGetIkGroupObject\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simMpHandleIkGroupObject) == nullptr)
    {
        printf("%s _simMpHandleIkGroupObject\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetObjectLocalTransformation) == nullptr)
    {
        printf("%s _simGetObjectLocalTransformation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetObjectLocalTransformation) == nullptr)
    {
        printf("%s _simSetObjectLocalTransformation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simDynReportObjectCumulativeTransformation) == nullptr)
    {
        printf("%s _simDynReportObjectCumulativeTransformation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetObjectCumulativeTransformation) == nullptr)
    {
        printf("%s _simSetObjectCumulativeTransformation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetObjectCumulativeTransformation) == nullptr)
    {
        printf("%s _simGetObjectCumulativeTransformation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simIsShapeDynamicallyStatic) == nullptr)
    {
        printf("%s _simIsShapeDynamicallyStatic\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetTreeDynamicProperty) == nullptr)
    {
        printf("%s _simGetTreeDynamicProperty\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetDummyLinkType) == nullptr)
    {
        printf("%s _simGetDummyLinkType\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetJointMode) == nullptr)
    {
        printf("%s _simGetJointMode\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simIsJointInHybridOperation) == nullptr)
    {
        printf("%s _simIsJointInHybridOperation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simDisableDynamicTreeForManipulation) == nullptr)
    {
        printf("%s _simDisableDynamicTreeForManipulation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simIsShapeDynamicallyRespondable) == nullptr)
    {
        printf("%s _simIsShapeDynamicallyRespondable\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetDynamicCollisionMask) == nullptr)
    {
        printf("%s _simGetDynamicCollisionMask\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetLastParentForLocalGlobalCollidable) == nullptr)
    {
        printf("%s _simGetLastParentForLocalGlobalCollidable\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetJointVelocity) == nullptr)
    {
        printf("%s _simSetJointVelocity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetJointPosition) == nullptr)
    {
        printf("%s _simSetJointPosition\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetJointPosition) == nullptr)
    {
        printf("%s _simGetJointPosition\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetDynamicMotorPositionControlTargetPosition) == nullptr)
    {
        printf("%s _simSetDynamicMotorPositionControlTargetPosition\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetInitialDynamicVelocity) == nullptr)
    {
        printf("%s _simGetInitialDynamicVelocity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetInitialDynamicVelocity) == nullptr)
    {
        printf("%s _simSetInitialDynamicVelocity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetInitialDynamicAngVelocity) == nullptr)
    {
        printf("%s _simGetInitialDynamicAngVelocity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetInitialDynamicAngVelocity) == nullptr)
    {
        printf("%s _simSetInitialDynamicAngVelocity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetStartSleeping) == nullptr)
    {
        printf("%s _simGetStartSleeping\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetWasPutToSleepOnce) == nullptr)
    {
        printf("%s _simGetWasPutToSleepOnce\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetDynamicsFullRefreshFlag) == nullptr)
    {
        printf("%s _simGetDynamicsFullRefreshFlag\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetDynamicsFullRefreshFlag) == nullptr)
    {
        printf("%s _simSetDynamicsFullRefreshFlag\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetShapeDynamicVelocity) == nullptr)
    {
        printf("%s _simSetShapeDynamicVelocity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetAdditionalForceAndTorque) == nullptr)
    {
        printf("%s _simGetAdditionalForceAndTorque\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simClearAdditionalForceAndTorque) == nullptr)
    {
        printf("%s _simClearAdditionalForceAndTorque\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetJointPositionInterval) == nullptr)
    {
        printf("%s _simGetJointPositionInterval\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetJointType) == nullptr)
    {
        printf("%s _simGetJointType\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetDynamicMotorTargetPosition) == nullptr)
    {
        printf("%s _simGetDynamicMotorTargetPosition\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetDynamicMotorTargetVelocity) == nullptr)
    {
        printf("%s _simGetDynamicMotorTargetVelocity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetDynamicMotorMaxForce) == nullptr)
    {
        printf("%s _simGetDynamicMotorMaxForce\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetDynamicMotorUpperLimitVelocity) == nullptr)
    {
        printf("%s _simGetDynamicMotorUpperLimitVelocity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetDynamicMotorReflectedPositionFromDynamicEngine) == nullptr)
    {
        printf("%s _simSetDynamicMotorReflectedPositionFromDynamicEngine\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simSetJointSphericalTransformation) == nullptr)
    {
        printf("%s _simSetJointSphericalTransformation\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simAddForceSensorCumulativeForcesAndTorques) == nullptr)
    {
        printf("%s _simAddForceSensorCumulativeForcesAndTorques\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simAddJointCumulativeForcesOrTorques) == nullptr)
    {
        printf("%s _simAddJointCumulativeForcesOrTorques\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetGeomWrapFromGeomProxy) == nullptr)
    {
        printf("%s _simGetGeomWrapFromGeomProxy\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetMass) == nullptr)
    {
        printf("%s _simGetMass\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetLocalInertiaInfo) == nullptr)
    {
        printf("%s _simGetLocalInertiaInfo\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetPurePrimitiveType) == nullptr)
    {
        printf("%s _simGetPurePrimitiveType\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simIsGeomWrapGeometric) == nullptr)
    {
        printf("%s _simIsGeomWrapGeometric\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simIsGeomWrapConvex) == nullptr)
    {
        printf("%s _simIsGeomWrapConvex\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetGeometricCount) == nullptr)
    {
        printf("%s _simGetGeometricCount\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetAllGeometrics) == nullptr)
    {
        printf("%s _simGetAllGeometrics\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetPurePrimitiveSizes) == nullptr)
    {
        printf("%s _simGetPurePrimitiveSizes\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simMakeDynamicAnnouncement) == nullptr)
    {
        printf("%s _simMakeDynamicAnnouncement\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetVerticesLocalFrame) == nullptr)
    {
        printf("%s _simGetVerticesLocalFrame\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetHeightfieldData) == nullptr)
    {
        printf("%s _simGetHeightfieldData\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetCumulativeMeshes) == nullptr)
    {
        printf("%s _simGetCumulativeMeshes\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetGravity) == nullptr)
    {
        printf("%s _simGetGravity\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetTimeDiffInMs) == nullptr)
    {
        printf("%s _simGetTimeDiffInMs\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simDoEntitiesCollide) == nullptr)
    {
        printf("%s _simDoEntitiesCollide\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetDistanceBetweenEntitiesIfSmaller) == nullptr)
    {
        printf("%s _simGetDistanceBetweenEntitiesIfSmaller\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simHandleJointControl) == nullptr)
    {
        printf("%s _simHandleJointControl\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simHandleCustomContact) == nullptr)
    {
        printf("%s _simHandleCustomContact\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetPureHollowScaling) == nullptr)
    {
        printf("%s _simGetPureHollowScaling\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simGetJointDynCtrlMode) == nullptr)
    {
        printf("%s _simGetJointDynCtrlMode\n",couldNotFind);
        return 0;
    }
    if (SIM_API_SYMBOL(_simDynCallback) == nullptr)
    {
        printf("%s _simDynCallback\n",couldNotFind);
        return 0;
    }

    return 1;
}

#endif // SIM_LIBRARY
