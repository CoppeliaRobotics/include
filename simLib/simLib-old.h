typedef int (__cdecl *ptrSimAddModuleMenuEntry)(const char* entryLabel,int itemCount,int* itemHandles);
typedef int (__cdecl *ptrSimSetModuleMenuItemState)(int itemHandle,int state,const char* label);
typedef int (__cdecl *ptrSimAddPointCloud)(int pageMask,int layerMask,int objectHandle,int options,SIMDOUBLE pointSize,int ptCnt,const SIMDOUBLE* pointCoordinates,const char* defaultColors,const char* pointColors,const SIMDOUBLE* pointNormals);
typedef int (__cdecl *ptrSimModifyPointCloud)(int pointCloudHandle,int operation,const int* intParam,const SIMDOUBLE* floatParam);
typedef void (__cdecl *ptr_simGetJointOdeParameters)(const void* joint,SIMDOUBLE* stopERP,SIMDOUBLE* stopCFM,SIMDOUBLE* bounce,SIMDOUBLE* fudge,SIMDOUBLE* normalCFM);
typedef void (__cdecl *ptr_simGetJointBulletParameters)(const void* joint,SIMDOUBLE* stopERP,SIMDOUBLE* stopCFM,SIMDOUBLE* normalCFM);
typedef void (__cdecl *ptr_simGetOdeMaxContactFrictionCFMandERP)(const void* geomInfo,int* maxContacts,SIMDOUBLE* friction,SIMDOUBLE* cfm,SIMDOUBLE* erp);
typedef bool (__cdecl *ptr_simGetBulletCollisionMargin)(const void* geomInfo,SIMDOUBLE* margin,int* otherProp);
typedef SIMDOUBLE (__cdecl *ptr_simGetBulletRestitution)(const void* geomInfo);
typedef void (__cdecl *ptr_simGetVortexParameters)(const void* object,int version,SIMDOUBLE* floatParams,int* intParams);
typedef void (__cdecl *ptr_simGetNewtonParameters)(const void* object,int* version,SIMDOUBLE* floatParams,int* intParams);
typedef void (__cdecl *ptr_simGetDamping)(const void* geomInfo,SIMDOUBLE* linDamping,SIMDOUBLE* angDamping);
typedef SIMDOUBLE (__cdecl *ptr_simGetFriction)(const void* geomInfo);
typedef bool (__cdecl *ptr_simGetBulletStickyContact)(const void* geomInfo);
typedef int (__cdecl *ptrSimCallScriptFunction)(int scriptHandleOrType,const char* functionNameAtScriptName,SLuaCallBack* data,const char* reservedSetToNull);
typedef int (__cdecl *ptrSimGetJointMatrix)(int objectHandle,SIMDOUBLE* matrix);
typedef int (__cdecl *ptrSimSetSphericalJointMatrix)(int objectHandle,const SIMDOUBLE* matrix);
typedef const void* (__cdecl *ptr_simGetGeomProxyFromShape)(const void* shape);
typedef int (__cdecl *ptrSimReorientShapeBoundingBox)(int shapeHandle,int relativeToHandle,int reservedSetToZero);

extern ptrSimAddModuleMenuEntry simAddModuleMenuEntry;
extern ptrSimSetModuleMenuItemState simSetModuleMenuItemState;
extern ptrSimAddPointCloud simAddPointCloud;
extern ptrSimModifyPointCloud simModifyPointCloud;
extern ptr_simGetJointOdeParameters _simGetJointOdeParameters;
extern ptr_simGetJointBulletParameters _simGetJointBulletParameters;
extern ptr_simGetOdeMaxContactFrictionCFMandERP _simGetOdeMaxContactFrictionCFMandERP;
extern ptr_simGetBulletCollisionMargin _simGetBulletCollisionMargin;
extern ptr_simGetBulletStickyContact _simGetBulletStickyContact;
extern ptr_simGetBulletRestitution _simGetBulletRestitution;
extern ptr_simGetVortexParameters _simGetVortexParameters;
extern ptr_simGetNewtonParameters _simGetNewtonParameters;
extern ptr_simGetDamping _simGetDamping;
extern ptr_simGetFriction _simGetFriction;
extern ptrSimCallScriptFunction simCallScriptFunction;
extern ptrSimGetJointMatrix simGetJointMatrix;
extern ptrSimSetSphericalJointMatrix simSetSphericalJointMatrix;
extern ptr_simGetGeomProxyFromShape _simGetGeomProxyFromShape;
extern ptrSimReorientShapeBoundingBox simReorientShapeBoundingBox;

#ifdef SIM_INTERFACE_OLD
#include "simLib-old2.h"
#endif
