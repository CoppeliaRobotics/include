#if !defined(SIMTYPES_INCLUDED_)
#define SIMTYPES_INCLUDED_

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

struct SSyncRt
{
    unsigned char objTypes[3];
    int objHandles[3];
};

#endif // !defined(SIMTYPES_INCLUDED_)
