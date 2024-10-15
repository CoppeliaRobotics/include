ptrSimRunSimulator simRunSimulator=nullptr;
ptrSimRunSimulatorEx simRunSimulatorEx=nullptr;
ptr_simGetJointOdeParameters _simGetJointOdeParameters=nullptr;
ptr_simGetJointBulletParameters _simGetJointBulletParameters=nullptr;
ptr_simGetOdeMaxContactFrictionCFMandERP _simGetOdeMaxContactFrictionCFMandERP=nullptr;
ptrSimExtLaunchUIThread simExtLaunchUIThread=nullptr;
ptrSimExtCanInitSimThread simExtCanInitSimThread=nullptr;
ptrSimExtSimThreadInit simExtSimThreadInit=nullptr;
ptrSimExtSimThreadDestroy simExtSimThreadDestroy=nullptr;
ptrSimExtPostExitRequest simExtPostExitRequest=nullptr;
ptrSimExtGetExitRequest simExtGetExitRequest=nullptr;
ptrSimExtStep simExtStep=nullptr;
ptrSimExtCallScriptFunction simExtCallScriptFunction=nullptr;
ptr_simGetBulletCollisionMargin _simGetBulletCollisionMargin=nullptr;
ptr_simGetBulletStickyContact _simGetBulletStickyContact=nullptr;
ptr_simGetBulletRestitution _simGetBulletRestitution=nullptr;
ptr_simGetVortexParameters _simGetVortexParameters=nullptr;
ptr_simGetNewtonParameters _simGetNewtonParameters=nullptr;
ptr_simGetDamping _simGetDamping=nullptr;
ptr_simGetFriction _simGetFriction=nullptr;
ptrSimCallScriptFunction simCallScriptFunction=nullptr;
ptrSimAddPointCloud simAddPointCloud=nullptr;
ptrSimModifyPointCloud simModifyPointCloud=nullptr;
ptrSimAddModuleMenuEntry simAddModuleMenuEntry=nullptr;
ptrSimSetModuleMenuItemState simSetModuleMenuItemState=nullptr;
ptrSimGetJointMatrix simGetJointMatrix=nullptr;
ptrSimSetSphericalJointMatrix simSetSphericalJointMatrix=nullptr;
ptr_simGetGeomProxyFromShape _simGetGeomProxyFromShape=nullptr;
ptrSimReorientShapeBoundingBox simReorientShapeBoundingBox=nullptr;
ptrSimIsDeprecated simIsDeprecated=nullptr;
ptrSimLoadModule simLoadModule=nullptr;
ptrSimUnloadModule simUnloadModule=nullptr;
ptrSimGetModuleName simGetModuleName=nullptr;
ptrSimSetModuleInfo simSetModuleInfo=nullptr;
ptrSimGetModuleInfo simGetModuleInfo=nullptr;
ptrSimIsStackValueNull simIsStackValueNull=nullptr;
ptrSimIsRealTimeSimulationStepNeeded simIsRealTimeSimulationStepNeeded=nullptr;
ptrSimAdjustRealTimeTimer simAdjustRealTimeTimer=nullptr;
ptrSimSetSimulationPassesPerRenderingPass simSetSimulationPassesPerRenderingPass=nullptr;
ptrSimGetSimulationPassesPerRenderingPass simGetSimulationPassesPerRenderingPass=nullptr;
ptrSimAdvanceSimulationByOneStep simAdvanceSimulationByOneStep=nullptr;
ptrSimHandleMainScript simHandleMainScript=nullptr;
ptrSimGetScriptInt32Param simGetScriptInt32Param=nullptr;
ptrSimSetScriptInt32Param simSetScriptInt32Param=nullptr;
ptrSimGetScriptStringParam simGetScriptStringParam=nullptr;
ptrSimSetScriptStringParam simSetScriptStringParam=nullptr;
ptrSimAddScript simAddScript=nullptr;
ptrSimRemoveScript simRemoveScript=nullptr;
ptrSimAssociateScriptWithObject simAssociateScriptWithObject=nullptr;
ptrSimPersistentDataWrite simPersistentDataWrite=nullptr;
ptrSimPersistentDataRead simPersistentDataRead=nullptr;
ptrSimGetPersistentDataTags simGetPersistentDataTags=nullptr;
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
ptrSimSetLightParameters simSetLightParameters=nullptr;
ptrSimGetLightParameters simGetLightParameters=nullptr;
ptrSimGetObjectInt32Param simGetObjectInt32Param=nullptr;
ptrSimSetObjectInt32Param simSetObjectInt32Param=nullptr;
ptrSimGetObjectFloatParam simGetObjectFloatParam=nullptr;
ptrSimSetObjectFloatParam simSetObjectFloatParam=nullptr;
ptrSimGetObjectFloatArrayParam simGetObjectFloatArrayParam=nullptr;
ptrSimSetObjectFloatArrayParam simSetObjectFloatArrayParam=nullptr;
ptrSimGetObjectStringParam simGetObjectStringParam=nullptr;
ptrSimSetObjectStringParam simSetObjectStringParam=nullptr;
ptrSimWriteCustomDataBlock simWriteCustomDataBlock=nullptr;
ptrSimReadCustomDataBlock simReadCustomDataBlock=nullptr;
ptrSimReadCustomDataBlockTags simReadCustomDataBlockTags=nullptr;
ptrSimGetEngineFloatParam simGetEngineFloatParam=nullptr;
ptrSimGetEngineInt32Param simGetEngineInt32Param=nullptr;
ptrSimGetEngineBoolParam simGetEngineBoolParam=nullptr;
ptrSimSetEngineFloatParam simSetEngineFloatParam=nullptr;
ptrSimSetEngineInt32Param simSetEngineInt32Param=nullptr;
ptrSimSetEngineBoolParam simSetEngineBoolParam=nullptr;
ptrSimSetObjectProperty simSetObjectProperty=nullptr;
ptrSimGetObjectProperty simGetObjectProperty=nullptr;
ptrSimSetObjectSpecialProperty simSetObjectSpecialProperty=nullptr;
ptrSimGetObjectSpecialProperty simGetObjectSpecialProperty=nullptr;
ptrSimSetModelProperty simSetModelProperty=nullptr;
ptrSimGetModelProperty simGetModelProperty=nullptr;

#ifdef SIM_INTERFACE_OLD
#include "simLib-old2.cpp"
#endif

int getSimProcAddressesOld(LIBRARY lib)
{
#ifdef SIM_INTERFACE_OLD
    if (getSimProcAddressesOld2(lib)==0)
        return(0);
#endif

    simRunSimulator=(ptrSimRunSimulator)(_getProcAddress(lib,"simRunSimulator",false));
    simRunSimulatorEx=(ptrSimRunSimulatorEx)(_getProcAddress(lib,"simRunSimulatorEx",false));
    simExtLaunchUIThread=(ptrSimExtLaunchUIThread)(_getProcAddress(lib,"simExtLaunchUIThread",false));
    simExtCanInitSimThread=(ptrSimExtCanInitSimThread)(_getProcAddress(lib,"simExtCanInitSimThread",false));
    simExtSimThreadInit=(ptrSimExtSimThreadInit)(_getProcAddress(lib,"simExtSimThreadInit",false));
    simExtSimThreadDestroy=(ptrSimExtSimThreadDestroy)(_getProcAddress(lib,"simExtSimThreadDestroy",false));
    simExtPostExitRequest=(ptrSimExtPostExitRequest)(_getProcAddress(lib,"simExtPostExitRequest",false));
    simExtGetExitRequest=(ptrSimExtGetExitRequest)(_getProcAddress(lib,"simExtGetExitRequest",false));
    simExtStep=(ptrSimExtStep)(_getProcAddress(lib,"simExtStep",false));
    simExtCallScriptFunction=(ptrSimExtCallScriptFunction)(_getProcAddress(lib,"simExtCallScriptFunction",true));
    _simGetBulletStickyContact=(ptr_simGetBulletStickyContact)(_getProcAddress(lib,"_simGetBulletStickyContact",false));
    simCallScriptFunction=(ptrSimCallScriptFunction)(_getProcAddress(lib,"simCallScriptFunction",false));
    simAddModuleMenuEntry=(ptrSimAddModuleMenuEntry)(_getProcAddress(lib,"simAddModuleMenuEntry",false));
    simSetModuleMenuItemState=(ptrSimSetModuleMenuItemState)(_getProcAddress(lib,"simSetModuleMenuItemState",false));
    _simGetJointOdeParameters=(ptr_simGetJointOdeParameters)(_getProcAddress(lib,"_simGetJointOdeParameters",true));
    _simGetJointBulletParameters=(ptr_simGetJointBulletParameters)(_getProcAddress(lib,"_simGetJointBulletParameters",true));
    _simGetOdeMaxContactFrictionCFMandERP=(ptr_simGetOdeMaxContactFrictionCFMandERP)(_getProcAddress(lib,"_simGetOdeMaxContactFrictionCFMandERP",true));
    _simGetBulletCollisionMargin=(ptr_simGetBulletCollisionMargin)(_getProcAddress(lib,"_simGetBulletCollisionMargin",true));
    _simGetBulletRestitution=(ptr_simGetBulletRestitution)(_getProcAddress(lib,"_simGetBulletRestitution",true));
    _simGetVortexParameters=(ptr_simGetVortexParameters)(_getProcAddress(lib,"_simGetVortexParameters",true));
    _simGetNewtonParameters=(ptr_simGetNewtonParameters)(_getProcAddress(lib,"_simGetNewtonParameters",true));
    _simGetDamping=(ptr_simGetDamping)(_getProcAddress(lib,"_simGetDamping",true));
    _simGetFriction=(ptr_simGetFriction)(_getProcAddress(lib,"_simGetFriction",true));
    simAddPointCloud=(ptrSimAddPointCloud)(_getProcAddress(lib,"simAddPointCloud",true));
    simModifyPointCloud=(ptrSimModifyPointCloud)(_getProcAddress(lib,"simModifyPointCloud",true));
    simGetJointMatrix=(ptrSimGetJointMatrix)(_getProcAddress(lib,"simGetJointMatrix",true));
    simSetSphericalJointMatrix=(ptrSimSetSphericalJointMatrix)(_getProcAddress(lib,"simSetSphericalJointMatrix",true));
    _simGetGeomProxyFromShape=(ptr_simGetGeomProxyFromShape)(_getProcAddress(lib,"_simGetGeomProxyFromShape",false));
    simReorientShapeBoundingBox=(ptrSimReorientShapeBoundingBox)(_getProcAddress(lib,"simReorientShapeBoundingBox",false));
    simIsDeprecated=(ptrSimIsDeprecated)(_getProcAddress(lib,"simIsDeprecated",false));
    simLoadModule=(ptrSimLoadModule)(_getProcAddress(lib,"simLoadModule",false));
    simUnloadModule=(ptrSimUnloadModule)(_getProcAddress(lib,"simUnloadModule",false));
    simGetModuleName=(ptrSimGetModuleName)(_getProcAddress(lib,"simGetModuleName",false));
    simSetModuleInfo=(ptrSimSetModuleInfo)(_getProcAddress(lib,"simSetModuleInfo",false));
    simGetModuleInfo=(ptrSimGetModuleInfo)(_getProcAddress(lib,"simGetModuleInfo",false));
    simIsStackValueNull=(ptrSimIsStackValueNull)(_getProcAddress(lib,"simIsStackValueNull",false));
    simIsRealTimeSimulationStepNeeded=(ptrSimIsRealTimeSimulationStepNeeded)(_getProcAddress(lib,"simIsRealTimeSimulationStepNeeded",false));
    simAdjustRealTimeTimer=(ptrSimAdjustRealTimeTimer)(_getProcAddress(lib,"simAdjustRealTimeTimer",true));
    simSetSimulationPassesPerRenderingPass=(ptrSimSetSimulationPassesPerRenderingPass)(_getProcAddress(lib,"simSetSimulationPassesPerRenderingPass",false));
    simGetSimulationPassesPerRenderingPass=(ptrSimGetSimulationPassesPerRenderingPass)(_getProcAddress(lib,"simGetSimulationPassesPerRenderingPass",false));
    simAdvanceSimulationByOneStep=(ptrSimAdvanceSimulationByOneStep)(_getProcAddress(lib,"simAdvanceSimulationByOneStep",false));
    simHandleMainScript=(ptrSimHandleMainScript)(_getProcAddress(lib,"simHandleMainScript",false));
    simGetScriptInt32Param=(ptrSimGetScriptInt32Param)(_getProcAddress(lib,"simGetScriptInt32Param",false));
    simSetScriptInt32Param=(ptrSimSetScriptInt32Param)(_getProcAddress(lib,"simSetScriptInt32Param",false));
    simGetScriptStringParam=(ptrSimGetScriptStringParam)(_getProcAddress(lib,"simGetScriptStringParam",false));
    simSetScriptStringParam=(ptrSimSetScriptStringParam)(_getProcAddress(lib,"simSetScriptStringParam",false));
    simAddScript=(ptrSimAddScript)(_getProcAddress(lib,"simAddScript",false));
    simRemoveScript=(ptrSimRemoveScript)(_getProcAddress(lib,"simRemoveScript",false));
    simAssociateScriptWithObject=(ptrSimAssociateScriptWithObject)(_getProcAddress(lib,"simAssociateScriptWithObject",false));
    simPersistentDataWrite=(ptrSimPersistentDataWrite)(_getProcAddress(lib,"simPersistentDataWrite",false));
    simPersistentDataRead=(ptrSimPersistentDataRead)(_getProcAddress(lib,"simPersistentDataRead",false));
    simGetPersistentDataTags=(ptrSimGetPersistentDataTags)(_getProcAddress(lib,"simGetPersistentDataTags",false));
    simSetBoolParam=(ptrSimSetBoolParam)(_getProcAddress(lib,"simSetBoolParam",false));
    simGetBoolParam=(ptrSimGetBoolParam)(_getProcAddress(lib,"simGetBoolParam",false));
    simSetInt32Param=(ptrSimSetInt32Param)(_getProcAddress(lib,"simSetInt32Param",false));
    simGetInt32Param=(ptrSimGetInt32Param)(_getProcAddress(lib,"simGetInt32Param",false));
    simGetUInt64Param=(ptrSimGetUInt64Param)(_getProcAddress(lib,"simGetUInt64Param",false));
    simSetStringParam=(ptrSimSetStringParam)(_getProcAddress(lib,"simSetStringParam",false));
    simGetStringParam=(ptrSimGetStringParam)(_getProcAddress(lib,"simGetStringParam",false));
    simSetNamedStringParam=(ptrSimSetNamedStringParam)(_getProcAddress(lib,"simSetNamedStringParam",false));
    simGetNamedStringParam=(ptrSimGetNamedStringParam)(_getProcAddress(lib,"simGetNamedStringParam",false));
    simSetInt32Signal=(ptrSimSetInt32Signal)(_getProcAddress(lib,"simSetInt32Signal",false));
    simGetInt32Signal=(ptrSimGetInt32Signal)(_getProcAddress(lib,"simGetInt32Signal",false));
    simClearInt32Signal=(ptrSimClearInt32Signal)(_getProcAddress(lib,"simClearInt32Signal",false));
    simClearFloatSignal=(ptrSimClearFloatSignal)(_getProcAddress(lib,"simClearFloatSignal",false));
    simSetStringSignal=(ptrSimSetStringSignal)(_getProcAddress(lib,"simSetStringSignal",false));
    simGetStringSignal=(ptrSimGetStringSignal)(_getProcAddress(lib,"simGetStringSignal",false));
    simClearStringSignal=(ptrSimClearStringSignal)(_getProcAddress(lib,"simClearStringSignal",false));
    simGetSignalName=(ptrSimGetSignalName)(_getProcAddress(lib,"simGetSignalName",false));
    simGetObjectInt32Param=(ptrSimGetObjectInt32Param)(_getProcAddress(lib,"simGetObjectInt32Param",false));
    simSetObjectInt32Param=(ptrSimSetObjectInt32Param)(_getProcAddress(lib,"simSetObjectInt32Param",false));
    simGetObjectStringParam=(ptrSimGetObjectStringParam)(_getProcAddress(lib,"simGetObjectStringParam",false));
    simSetObjectStringParam=(ptrSimSetObjectStringParam)(_getProcAddress(lib,"simSetObjectStringParam",false));
    simWriteCustomDataBlock=(ptrSimWriteCustomDataBlock)(_getProcAddress(lib,"simWriteCustomDataBlock",false));
    simReadCustomDataBlock=(ptrSimReadCustomDataBlock)(_getProcAddress(lib,"simReadCustomDataBlock",false));
    simReadCustomDataBlockTags=(ptrSimReadCustomDataBlockTags)(_getProcAddress(lib,"simReadCustomDataBlockTags",false));
    simGetEngineInt32Param=(ptrSimGetEngineInt32Param)(_getProcAddress(lib,"simGetEngineInt32Param",false));
    simGetEngineBoolParam=(ptrSimGetEngineBoolParam)(_getProcAddress(lib,"simGetEngineBoolParam",false));
    simSetEngineInt32Param=(ptrSimSetEngineInt32Param)(_getProcAddress(lib,"simSetEngineInt32Param",false));
    simSetEngineBoolParam=(ptrSimSetEngineBoolParam)(_getProcAddress(lib,"simSetEngineBoolParam",false));
    simSetLightParameters=(ptrSimSetLightParameters)(_getProcAddress(lib,"simSetLightParameters",false));
    simSetArrayParam=(ptrSimSetArrayParam)(_getProcAddress(lib,"simSetArrayParam",true));
    simGetArrayParam=(ptrSimGetArrayParam)(_getProcAddress(lib,"simGetArrayParam",true));
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
    simGetLightParameters=(ptrSimGetLightParameters)(_getProcAddress(lib,"simGetLightParameters",true));
    simSetObjectProperty=(ptrSimSetObjectProperty)(_getProcAddress(lib,"simSetObjectProperty",false));
    simGetObjectProperty=(ptrSimGetObjectProperty)(_getProcAddress(lib,"simGetObjectProperty",false));
    simSetObjectSpecialProperty=(ptrSimSetObjectSpecialProperty)(_getProcAddress(lib,"simSetObjectSpecialProperty",false));
    simGetObjectSpecialProperty=(ptrSimGetObjectSpecialProperty)(_getProcAddress(lib,"simGetObjectSpecialProperty",false));
    simSetModelProperty=(ptrSimSetModelProperty)(_getProcAddress(lib,"simSetModelProperty",false));
    simGetModelProperty=(ptrSimGetModelProperty)(_getProcAddress(lib,"simGetModelProperty",false));

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
    if (_simGetJointOdeParameters==nullptr)
    {
        printf("%s _simGetJointOdeParameters\n",couldNotFind);
        return 0;
    }
    if (_simGetJointBulletParameters==nullptr)
    {
        printf("%s _simGetJointBulletParameters\n",couldNotFind);
        return 0;
    }
    if (_simGetOdeMaxContactFrictionCFMandERP==nullptr)
    {
        printf("%s _simGetOdeMaxContactFrictionCFMandERP\n",couldNotFind);
        return 0;
    }
    if (_simGetBulletCollisionMargin==nullptr)
    {
        printf("%s _simGetBulletCollisionMargin\n",couldNotFind);
        return 0;
    }
    if (_simGetBulletStickyContact==nullptr)
    {
        printf("%s _simGetBulletStickyContact\n",couldNotFind);
        return 0;
    }
    if (_simGetBulletRestitution==nullptr)
    {
        printf("%s _simGetBulletRestitution\n",couldNotFind);
        return 0;
    }
    if (_simGetVortexParameters==nullptr)
    {
        printf("%s _simGetVortexParameters\n",couldNotFind);
        return 0;
    }
    if (_simGetNewtonParameters==nullptr)
    {
        printf("%s _simGetNewtonParameters\n",couldNotFind);
        return 0;
    }
    if (_simGetDamping==nullptr)
    {
        printf("%s _simGetDamping\n",couldNotFind);
        return 0;
    }
    if (_simGetFriction==nullptr)
    {
        printf("%s _simGetFriction\n",couldNotFind);
        return 0;
    }
    if (simCallScriptFunction==nullptr)
    {
        printf("%s simCallScriptFunction\n",couldNotFind);
        return 0;
    }
    if (simAddPointCloud==nullptr)
    {
        printf("%s simAddPointCloud\n",couldNotFind);
        return 0;
    }
    if (simModifyPointCloud==nullptr)
    {
        printf("%s simModifyPointCloud\n",couldNotFind);
        return 0;
    }
    if (simAddModuleMenuEntry==nullptr)
    {
        printf("%s simAddModuleMenuEntry\n",couldNotFind);
        return 0;
    }
    if (simSetModuleMenuItemState==nullptr)
    {
        printf("%s simSetModuleMenuItemState\n",couldNotFind);
        return 0;
    }
    if (simGetJointMatrix==nullptr)
    {
        printf("%s simGetJointMatrix\n",couldNotFind);
        return 0;
    }
    if (simSetSphericalJointMatrix==nullptr)
    {
        printf("%s simSetSphericalJointMatrix\n",couldNotFind);
        return 0;
    }
    if (_simGetGeomProxyFromShape==nullptr)
    {
        printf("%s _simGetGeomProxyFromShape\n",couldNotFind);
        return 0;
    }
    if (simReorientShapeBoundingBox==nullptr)
    {
        printf("%s simReorientShapeBoundingBox\n",couldNotFind);
        return 0;
    }
    if (simIsDeprecated==nullptr)
    {
        printf("%s simIsDeprecated\n",couldNotFind);
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
    if (simGetModuleName==nullptr)
    {
        printf("%s simGetModuleName\n",couldNotFind);
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
    if (simIsStackValueNull==nullptr)
    {
        printf("%s simIsStackValueNull\n",couldNotFind);
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
    if (simSetSimulationPassesPerRenderingPass==nullptr)
    {
        printf("%s simSetSimulationPassesPerRenderingPass\n",couldNotFind);
        return 0;
    }
    if (simAdvanceSimulationByOneStep==nullptr)
    {
        printf("%s simAdvanceSimulationByOneStep\n",couldNotFind);
        return 0;
    }
    if (simHandleMainScript==nullptr)
    {
        printf("%s simHandleMainScript\n",couldNotFind);
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
    if (simAssociateScriptWithObject==nullptr)
    {
        printf("%s simAssociateScriptWithObject\n",couldNotFind);
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
    if (simGetPersistentDataTags==nullptr)
    {
        printf("%s simGetPersistentDataTags\n",couldNotFind);
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
    return 1;
}
