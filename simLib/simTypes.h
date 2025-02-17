#if !defined(SIMTYPES_INCLUDED_)
#define SIMTYPES_INCLUDED_

#ifdef __cplusplus
#include <cstring>
#else
#include <string.h>
#endif

#ifndef UID
#if defined(SIM_UNIFIED_HANDLES)
#define UID long long int
#else
#define UID int
#endif
#endif

struct S_UID
{
    int objectType; // e.g. sim_objecttype_sceneobject, etc.
    UID uid;
};

struct S_OID
{
    int objectType; // e.g. sim_objecttype_sceneobject, etc.
    int oldHandle;
};

struct SSimInit
{
    const char* pluginName;
    const char* coppeliaSimLibPath;
};


struct SSimMsg
{
    int msgId;
    int* auxData;
    void* auxPointer;
};


struct SSimMsg_ui
{
    int msgId;
    int* auxData;
    void* auxPointer;
};


struct SScriptCallBack
{
    int objectID;
    int scriptID;
    int stackID;
    char waitUntilZero; /* do not use */
    char* raiseErrorWithMessage; /* do not use */
    char* source;
    int line;
};


struct SShapeVizInfo
{
    double* vertices;
    int verticesSize;
    int* indices;
    int indicesSize;
    double shadingAngle;
    double* normals;
    float colors[9];
    char* texture; /*rgba*/
    int textureId;
    int textureRes[2];
    float* textureCoords;
    int textureApplyMode;
    int textureOptions; /* not just textures options */
    double transparency;
    int options;
};


struct SShapeVizInfof
{
    float* vertices;
    int verticesSize;
    int* indices;
    int indicesSize;
    float shadingAngle;
    float* normals;
    float colors[9];
    char* texture; /*rgba*/
    int textureId;
    int textureRes[2];
    float* textureCoords;
    int textureApplyMode;
    int textureOptions; /* not just textures options */
    float transparency;
    int options;
};


struct SLuaCallBack
{
    int objectID;
    bool* inputBool;
    int* inputInt;
    float* inputFloat;
    char* inputChar;
    int inputArgCount;
    int* inputArgTypeAndSize;
    bool* outputBool;
    int* outputInt;
    float* outputFloat;
    char* outputChar;
    int outputArgCount;
    int* outputArgTypeAndSize;
    char waitUntilZero;
    char* inputCharBuff;
    char* outputCharBuff;
    int scriptID;
    double* inputDouble;
    double* outputDouble;
};


struct SProperty {
    const char* name;
    int type;
    int flags;
    const char* shortInfoTxt;
    const char* infoTxt;
};


#define SPropertyInfo_init(s) do { \
    memset((s), 0, sizeof(SPropertyInfo)); \
    (s)->structSize = sizeof(SPropertyInfo); \
    (s)->type = -1; \
    (s)->flags = 0; \
    (s)->shortInfoTxt = nullptr; \
    (s)->infoTxt = nullptr; \
} while(0)

struct SPropertyInfo {
    int structSize; /* init. to sizeof(SPropertyInfo) */
    int type; /* default: -1, no such property */
    int flags;
    char* shortInfoTxt;
    char* infoTxt;
#ifdef __cplusplus
    SPropertyInfo() { SPropertyInfo_init(this); }
#endif // __cplusplus
};


#define SPropertyOptions_init(s) do { \
    memset((s), 0, sizeof(SPropertyOptions)); \
    (s)->structSize = sizeof(SPropertyOptions); \
    (s)->objectType = -1; \
    (s)->shortInfoTxt = false; \
    (s)->prefix = nullptr; \
} while(0)

struct SPropertyOptions {
    int structSize; /* init. to sizeof(SPropertyOptions) */
    int objectType; /* default: -1 */
    bool shortInfoTxt; /* default: -1 */
    const char* prefix; /* default: null */
#ifdef __cplusplus
    SPropertyOptions() { SPropertyOptions_init(this); }
    // "fluent" API:
    SPropertyOptions& setObjectType(int t) { objectType = t; return *this; }
#endif // __cplusplus
};

#endif // !defined(SIMTYPES_INCLUDED_)
