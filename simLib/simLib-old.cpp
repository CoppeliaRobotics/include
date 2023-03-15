ptr_simGetJointOdeParameters _simGetJointOdeParameters=nullptr;
ptr_simGetJointBulletParameters _simGetJointBulletParameters=nullptr;
ptr_simGetOdeMaxContactFrictionCFMandERP _simGetOdeMaxContactFrictionCFMandERP=nullptr;
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

#ifdef SIM_INTERFACE_OLD
#include "simLib-old2.cpp"
#endif

int getSimProcAddressesOld(LIBRARY lib)
{
#ifdef SIM_INTERFACE_OLD
    if (getSimProcAddressesOld2(lib)==0)
        return(0);
#endif

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

    char *ps=std::getenv("COPPELIASIMPLUGIN_IGNORE_MISSING_SYMBOLS");
    if (ps!=nullptr)
        return(1);

    char couldNotFind[]="Could not find function";

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
    return 1;
}
