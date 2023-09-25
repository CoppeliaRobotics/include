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
    return 1;
}
