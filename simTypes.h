#if !defined(SIMTYPES_INCLUDED_)
#define SIMTYPES_INCLUDED_

#include <cstddef>

// Temp, during transition from float to double:
#define floatFloat float
//#define switchToDouble true
#ifndef switchToDouble
#define interfaceIsSinglePrecision true
#define floatDouble float
#else
#define DOUBLESERIALIZATIONOPERATION
#define floatDouble double
#endif
#ifdef interfaceIsSinglePrecision
#define SIMDOUBLE float
#else
#define SIMDOUBLE double
#endif

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
    floatDouble* vertices;
    int verticesSize;
    int* indices;
    int indicesSize;
    floatDouble shadingAngle;
    floatDouble* normals;
    floatDouble colors[9];
    char* texture; /*rgba*/
    int textureId;
    int textureRes[2];
    floatDouble* textureCoords;
    int textureApplyMode;
    int textureOptions; /* not just textures options */
    floatDouble transparency;
    int options;
};

struct SLuaCallBack
{
    int objectID;
    bool* inputBool;
    int* inputInt;
    floatFloat* inputFloat;
    char* inputChar;
    int inputArgCount;
    int* inputArgTypeAndSize;
    bool* outputBool;
    int* outputInt;
    floatFloat* outputFloat;
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

struct SSyncMsg
{
    unsigned char msg;
    void* data;
    size_t dataSize;
};

struct SSyncRt
{
    unsigned char objTypes[3];
    int objHandles[3];
};

typedef int (*contactCallback)(int,int,int,int*,float*);
typedef int (*jointCtrlCallback)(int,int,int,const int*,const float*,float*);

/* do not use anymore: */
typedef bool simBool;
typedef void simVoid;
typedef unsigned char simUChar;
typedef int simInt;
typedef char simChar;
typedef unsigned int simUInt;
typedef long long int simInt64;
typedef unsigned long long int simUInt64;
typedef double simDouble;
typedef float simFloat;

#endif // !defined(SIMTYPES_INCLUDED_)
