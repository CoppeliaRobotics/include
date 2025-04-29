#ifndef SIMPLUSPLUS_LIB_H_INCLUDED
#define SIMPLUSPLUS_LIB_H_INCLUDED

#if __cplusplus < 201703L
    #error simPlusPlus needs at least a C++17 compliant compiler
#endif

#include <optional>
#include <string>
#include <vector>
#include <array>
#include <stdexcept>
#include <boost/format.hpp>

#include <simLib/simLib.h>

#ifdef HAVE_JSONCONS
#include <jsoncons/json.hpp>
#endif // HAVE_JSONCONS

namespace sim
{
    using handle_t = int;

    struct PluginInfo
    {
        LIBRARY lib;
        std::string name;
        std::string nameAndVersion;
        int version;
    };

    namespace util
    {
        static std::string sprintf(boost::format &fmt)
        {
            return fmt.str();
        }

        template<typename Arg, typename... Args>
        std::string sprintf(boost::format &fmt, Arg &&arg, Args &&...args)
        {
            return sprintf(fmt % std::forward<Arg>(arg), std::forward<Args>(args)...);
        }

        template<typename... Args>
        std::string sprintf(const std::string &msg, Args &&...args)
        {
            return msg;
        }

        template<typename Arg, typename... Args>
        std::string sprintf(const std::string &fmt, Arg &&arg, Args &&...args)
        {
            boost::format f(fmt);
            return sprintf(f, std::forward<Arg>(arg), std::forward<Args>(args)...);
        }
    } // namespace util

	/*! \brief A basic exception class
	 */
    struct exception : public ::std::exception
    {
        std::string s;

        template<typename... Arguments>
        exception(const std::string &fmt, Arguments&&... args)
            : s(util::sprintf(fmt, std::forward<Arguments>(args)...))
        {
        }

        ~exception() throw()
        {
        }

        const char * what() const throw()
        {
            return s.c_str();
        }
    };

    struct api_error : public exception
    {
        std::string func;
        std::string error;

        api_error(const std::string &func_);
        api_error(const std::string &func_, const std::string &error_);

        ~api_error() throw()
        {
        }
    };

    extern PluginInfo *pluginInfo;


    void enableStackDebug();
    void disableStackDebug();
    bool isStackDebugEnabled();

    int programVersion();
    std::string versionString(int v);



    // runSimulator

    // runSimulatorEx

    // getSimulatorMessage

    void * getMainWindow(int type);

    std::string getLastError();

    void setBoolParam(int parameter, bool value);

    bool getBoolParam(int parameter);

    void setInt32Param(int parameter, int value);

    int getInt32Param(int parameter);

    unsigned long long int getUInt64Param(int parameter);

    void setStringParam(int parameter, char *value);
    void setStringParam(int parameter, const std::string &value);

    std::string getStringParam(int parameter);

    void setNamedStringParam(const std::string &parameter, const std::string &value);
    void setNamedBoolParam(const std::string &parameter, bool value);
    void setNamedFloatParam(const std::string &parameter, double value);
    void setNamedInt32Param(const std::string &parameter, int value);

    std::optional<std::string> getNamedStringParam(const std::string &parameter);
    std::optional<bool> getNamedBoolParam(const std::string &parameter);
    std::optional<double> getNamedFloatParam(const std::string &parameter);
    std::optional<int> getNamedInt32Param(const std::string &parameter);

    handle_t getObject(const char *objectPath, int index, handle_t proxy, int options);
    handle_t getObject(const std::string &objectPath, int index, handle_t proxy, int options);
    handle_t getObject(const std::string &objectPath, int index, handle_t proxy, bool noError);
    handle_t getObject(const std::string &objectPath, int index = -1, handle_t proxy = -1);

    long long int getObjectUid(handle_t objectHandle);

    handle_t getObjectFromUid(long long int uid, int options);
    handle_t getObjectFromUid(long long int uid, bool noError);

    handle_t getScriptHandleEx(int scriptType, handle_t objHandle = -1, std::optional<std::string> scriptName = {});

    void removeObjects(const std::vector<handle_t> &objectHandles);

    int removeModel(handle_t objectHandle);

    std::string getObjectAlias(handle_t objectHandle, int options);

    void setObjectAlias(handle_t objectHandle, const std::string &alias, int options = 0);

    handle_t getObjectParent(handle_t objectHandle);

    handle_t getObjectChild(handle_t objectHandle, int index);
    std::vector<handle_t> getObjectChildren(handle_t objectHandle);

    void setObjectParent(handle_t objectHandle, handle_t parentObjectHandle, bool keepInPlace);

    int getObjectType(handle_t objectHandle);

    int getJointType(handle_t objectHandle);

    // reservedCommand

    int getSimulationState();

    void loadScene(const char *filename);
    void loadScene(const std::string &filename);

    void closeScene();

    void saveScene(const char *filename);
    void saveScene(const std::string &filename);

    handle_t loadModel(const char *filename);
    handle_t loadModel(const std::string &filename);

    void saveModel(handle_t baseOfModelHandle, const char *filename);
    void saveModel(handle_t baseOfModelHandle, const std::string &filename);

    bool doesFileExist(const char *filename);
    bool doesFileExist(const std::string &filename);

    std::vector<handle_t> getObjectSel();

    int setObjectSel(const handle_t *handles, int count);
    int setObjectSel(const std::vector<handle_t> &handles);

    // associateScriptWithObject

    // handleMainScript

    // resetScript

    // addScript

    // removeScript

    // refreshDialogs

    // resetProximitySensor

    void * createBuffer(int size);

    void releaseBuffer(const void *buffer);

    bool checkCollision(handle_t entity1Handle, handle_t entity2Handle);

    // getRealTimeSimulation

    // isRealTimeSimulationStepNeeded

    // getSimulationPassesPerRenderingPass

    // advanceSimulationByOneStep

    // startSimulation

    // stopSimulation

    // pauseSimulation

    // getPluginName

    // adjustView

    void setLastError(const std::string &msg);

    // resetGraph

    // destroyGraphCurve

    // duplicateGraphCurveToStatic

    // setNavigationMode

    // getNavigationMode

    // setPage

    // getPage

    int registerScriptCallbackFunction(const std::string &funcNameAtPluginName, const std::string &callTips, void (*callBack)(struct SScriptCallBack *cb));
    int registerScriptCallbackFunction(const std::string &funcNameAtPluginName, void (*callBack)(struct SScriptCallBack *cb));

    int registerScriptVariableRaw(const std::string &varName, const char *varValue, int stackID);
    int registerScriptVariableRaw(const std::string &varName, const std::string &varValue, int stackID);
    int registerScriptVariable(const std::string &varName, const char *varValue, int stackID);
    int registerScriptVariable(const std::string &varName, const std::string &varValue, int stackID);
    template<typename T>
    int registerScriptVariable(const std::string &varName, const T &varValue, int stackID)
    {
        return registerScriptVariableRaw(varName, std::to_string(varValue), stackID);
    }

    // registerScriptFuncHook

    void copyPasteObjects(std::vector<handle_t> &shapeHandles, int options);
    std::vector<handle_t> copyPasteObjects(const std::vector<handle_t> &shapeHandles, int options);

    // removeDrawingObject

    int announceSceneContentChange();

    // setInt32Signal

    // getInt32Signal

    // clearInt32Signal

    // clearFloatSignal

    // setStringSignal

    // getStringSignal

    // clearStringSignal

    // getSignalName

    void setObjectProperty(handle_t objectHandle, int prop);

    int getObjectProperty(handle_t objectHandle);

    // setObjectSpecialProperty

    // getObjectSpecialProperty

    // setExplicitHandling

    // getExplicitHandling

    handle_t getLinkDummy(handle_t dummyHandle);

    void setLinkDummy(handle_t dummyHandle, handle_t linkedDummyHandle);

    void setModelProperty(handle_t objectHandle, int modelProperty);

    int getModelProperty(handle_t objectHandle);

    void resetDynamicObject(handle_t objectHandle);

    void setJointMode(handle_t jointHandle, int jointMode);

    int getJointMode(handle_t jointHandle);

    // serialOpen

    // serialClose

    // serialSend

    // serialRead

    // serialCheck

    // auxiliaryConsoleClose

    // auxiliaryConsoleShow

    // auxiliaryConsolePrint

    int getObjectInt32Param(handle_t objectHandle, int parameterID);

    void setObjectInt32Param(handle_t objectHandle, int parameterID, int parameter);

    std::string getObjectStringParam(handle_t objectHandle, int parameterID);

    void setObjectStringParam(handle_t objectHandle, int parameterID, const std::string &parameter);

    // setSimulationPassesPerRenderingPass

    void persistentDataWrite(const std::string &dataName, const std::string &dataValue, int options = 0);

    std::string persistentDataRead(const std::string &dataName);

    bool isHandle(handle_t generalObjectHandle, int generalObjectType);

    // resetVisionSensor

    void setVisionSensorImg(handle_t sensorHandle, const unsigned char *img, int options = 0, std::array<int, 2> pos = {0, 0}, std::array<int, 2> size = {0, 0});

    // ruckigRemove

    handle_t groupShapes(const std::vector<handle_t> &shapeHandles, bool merge = false);

    std::vector<handle_t> ungroupShape(handle_t shapeHandle);

    void quitSimulator();

    void setShapeMaterial(handle_t shapeHandle, handle_t materialIdOrShapeHandle);

    // getTextureId

    // readTexture

    void writeCustomDataBlock(handle_t objectHandle, const char *tagName, const char *data, int dataSize);
    void writeCustomDataBlock(handle_t objectHandle, const std::string &tagName, const std::string &data);

    char * readCustomDataBlock(handle_t objectHandle, const char *tagName, int *dataSize);
    std::optional<std::string> readCustomDataBlock(handle_t objectHandle, const std::string &tagName);

    char * readCustomDataBlockTags(handle_t objectHandle, int *tagCount);
    std::vector<std::string> readCustomDataBlockTags(handle_t objectHandle);

    handle_t getObjects(int index, int objectType);
    std::vector<handle_t> getObjects(int objectType);

    std::vector<handle_t> getObjectsInTree(handle_t treeBaseHandle, int objectType, int options = 0);

    // getShapeTextureId

    // createCollectionEx

    // addItemToCollection

    // destroyCollection

    // getCollectionObjects

    int getScriptInt32Param(handle_t scriptHandle, int parameterID);

    int setScriptInt32Param(handle_t scriptHandle, int parameterID, int parameter);

    std::string getScriptStringParam(handle_t scriptHandle, int parameterID);
    std::optional<std::string> getScriptStringParamOpt(handle_t scriptHandle, int parameterID);

    int setScriptStringParam(handle_t scriptHandle, int parameterID, const std::string &parameter);

    // reorientShapeBoundingBox

    // saveImage

    unsigned char * loadImage(int *resolution, int options, const char *filename, void *reserved);
    unsigned char * loadImage(int *resolution, int options, const std::string &filename, void *reserved);

    unsigned char * getScaledImage(const unsigned char *imageIn, const int *resolutionIn, int *resolutionOut, int options);
    unsigned char * getScaledImage(const unsigned char *imageIn, std::array<int, 2> resolutionIn, int *resolutionOut, int options);

    void callScriptFunctionEx(int scriptHandle, const std::string &functionName, int stackID);

    // getExtensionString

    handle_t createStack();

    void releaseStack(handle_t stackHandle);

    handle_t copyStack(handle_t stackHandle);

    void pushNullOntoStack(handle_t stackHandle);

    void pushBoolOntoStack(handle_t stackHandle, bool value);

    void pushInt32OntoStack(handle_t stackHandle, int value);

    void pushInt64OntoStack(handle_t stackHandle, long long int value);

    void pushStringOntoStack(handle_t stackHandle, const char *value, int stringSize);
    void pushStringOntoStack(handle_t stackHandle, const std::string &value);
    void pushTextOntoStack(handle_t stackHandle, const char *value);
    void pushTextOntoStack(handle_t stackHandle, const std::string &value);
    void pushBufferOntoStack(handle_t stackHandle, const char *value, int bufferSize);
    void pushBufferOntoStack(handle_t stackHandle, const uint8_t *value, int bufferSize);
    void pushBufferOntoStack(handle_t stackHandle, const std::string &value);
    void pushBufferOntoStack(handle_t stackHandle, const std::vector<uint8_t> &value);

    void pushUInt8TableOntoStack(handle_t stackHandle, const unsigned char *values, int valueCnt);
    void pushUInt8TableOntoStack(handle_t stackHandle, const std::vector<unsigned char> &values);

    void pushInt32TableOntoStack(handle_t stackHandle, const int *values, int valueCnt);
    void pushInt32TableOntoStack(handle_t stackHandle, const std::vector<int> &values);

    void pushInt64TableOntoStack(handle_t stackHandle, const long long int *values, int valueCnt);
    void pushInt64TableOntoStack(handle_t stackHandle, const std::vector<long long int> &values);

    void pushTableOntoStack(handle_t stackHandle);

    void insertDataIntoStackTable(handle_t stackHandle);

    int getStackSize(handle_t stackHandle);

    int popStackItem(handle_t stackHandle, int count);

    void moveStackItemToTop(handle_t stackHandle, int cIndex);

    int getStackItemType(handle_t stackHandle, int cIndex);

    int getStackBoolValue(handle_t stackHandle, bool *boolValue);

    int getStackInt32Value(handle_t stackHandle, int *numberValue);

    int getStackInt64Value(handle_t stackHandle, long long int *numberValue);

    char * getStackStringValue(handle_t stackHandle, int *stringSize);
    int getStackStringValue(handle_t stackHandle, std::string *stringValue);

    int getStackStringType(handle_t stackHandle, int cIndex);

    int getStackTableInfo(handle_t stackHandle, int infoType);

    int getStackUInt8Table(handle_t stackHandle, unsigned char *array, int count);
    int getStackUInt8Table(handle_t stackHandle, std::vector<unsigned char> *v);

    int getStackInt32Table(handle_t stackHandle, int *array, int count);
    int getStackInt32Table(handle_t stackHandle, std::vector<int> *v);

    int getStackInt64Table(handle_t stackHandle, long long int *array, int count);

    void unfoldStackTable(handle_t stackHandle);

    void debugStack(handle_t stackHandle, int index = -1);

    int getEngineInt32Param(int paramId, handle_t objectHandle, const void *object);

    bool getEngineBoolParam(int paramId, handle_t objectHandle, const void *object);

    void setEngineInt32Param(int paramId, handle_t objectHandle, const void *object, int val);

    void setEngineBoolParam(int paramId, handle_t objectHandle, const void *object, bool val);

    // insertObjectIntoOctree

    // subtractObjectFromOctree

    // openTextEditor

    // packTable

    // unpackTable

    // setReferencedHandles

    // getReferencedHandles

    void executeScriptString(handle_t scriptHandle, const std::string &code, int stackID);

    std::vector<std::string> getApiFunc(handle_t scriptHandle, const std::string &apiWord);

    std::string getApiInfo(handle_t scriptHandle, const std::string &apiWord);

    void setPluginInfo(const std::string &moduleName, int infoType, const std::string &stringInfo);
    void setPluginInfo(const std::string &moduleName, int infoType, int intInfo);
    void setPluginInfo(int infoType, const std::string &stringInfo);
    void setPluginInfo(int infoType, int intInfo);

    void getPluginInfo(const std::string &moduleName, int infoType, std::string &stringInfo);
    void getPluginInfo(const std::string &moduleName, int infoType, int &intInfo);
    std::string getPluginInfoStr(const std::string &moduleName, int infoType);
    int getPluginInfoInt(const std::string &moduleName, int infoType);
    void getPluginInfo(int infoType, std::string &stringInfo);
    void getPluginInfo(int infoType, int &intInfo);
    std::string getPluginInfoStr(int infoType);
    int getPluginInfoInt(int infoType);

    std::vector<std::string> getPersistentDataTags();

    int eventNotification(const std::string &event);

    void addLog(std::optional<std::string> pluginName, int verbosityLevel, std::optional<std::string> logMsg);
    template<typename... Arguments>
    void addLog(int verbosity, const std::string &fmt, Arguments&&... args)
    {
        addLog(pluginInfo->nameAndVersion, verbosity, util::sprintf(fmt, std::forward<Arguments>(args)...));
    }

    bool isDynamicallyEnabled(handle_t objectHandle);

    bool initScript(handle_t scriptHandle);

    int moduleEntry(int handle, const char *label, int state);
    int moduleEntry(int handle, const std::string &label, int state);
    int moduleEntry(const std::string &label, int state);
    int moduleEntry(int handle, int state);

    bool checkExecAuthorization(const char *what, const char *args);
    bool checkExecAuthorization(const std::string &what, const std::string &args);

    void pushFloatOntoStack(handle_t stackHandle, float value);

    void pushFloatTableOntoStack(handle_t stackHandle, const float *values, int valueCnt);
    void pushFloatTableOntoStack(handle_t stackHandle, const std::vector<float> &values);

    int getStackFloatValue(handle_t stackHandle, float *numberValue);

    int getStackFloatTable(handle_t stackHandle, float *array, int count);
    int getStackFloatTable(handle_t stackHandle, std::vector<float> *v);

    // getVisionSensorDepth

    // setVisionSensorDepth

    // checkVisionSensorEx

    // ruckigPos

    // ruckigVel

    // ruckigStep

    void pushDoubleOntoStack(handle_t stackHandle, double value);

    void pushDoubleTableOntoStack(handle_t stackHandle, const double *values, int valueCnt);
    void pushDoubleTableOntoStack(handle_t stackHandle, const std::vector<double> &values);

    int getStackDoubleValue(handle_t stackHandle, double *numberValue);

    int getStackDoubleTable(handle_t stackHandle, double *array, int count);
    int getStackDoubleTable(handle_t stackHandle, std::vector<double> *v);

    // extLaunchUIThread

    // extCanInitSimThread

    // extSimThreadInit

    // extSimThreadDestroy

    // extPostExitRequest

    // extGetExitRequest

    // extStep

    // _setDynamicSimulationIconCode

    // _setDynamicObjectFlagForVisualization

    // _getObjectListSize

    // _getObjectFromIndex

    // _getObjectID

    // _getObjectType

    // _getObjectChildren

    // _getGeomProxyFromShape

    // _getParentObject

    // _getObject

    // _getIkGroupObject

    // _mpHandleIkGroupObject

    // _isShapeDynamicallyStatic

    // _getTreeDynamicProperty

    // _getDummyLinkType

    // _getJointMode

    // _isJointInHybridOperation

    // _disableDynamicTreeForManipulation

    // _isShapeDynamicallyRespondable

    // _getDynamicCollisionMask

    // _getLastParentForLocalGlobalCollidable

    // _getStartSleeping

    // _getWasPutToSleepOnce

    // _getDynamicsFullRefreshFlag

    // _setDynamicsFullRefreshFlag

    // _clearAdditionalForceAndTorque

    // _getJointType

    // _getGeomWrapFromGeomProxy

    // _getPurePrimitiveType

    // _isGeomWrapGeometric

    // _isGeomWrapConvex

    // _getGeometricCount

    // _getAllGeometrics

    // _makeDynamicAnnouncement

    // _getTimeDiffInMs

    // _doEntitiesCollide

    // _getJointDynCtrlMode

    // floatingViewRemove

    int getShapeViz(handle_t shapeHandle, int index, struct SShapeVizInfo *info);

    void setArrayParam(int parameter, std::array<double, 3> value);

    std::array<double, 3> getArrayParam(int parameter);

    // setFloatSignal

    // getFloatSignal

    void setFloatParam(int parameter, double value);

    double getFloatParam(int parameter);

    double getObjectFloatParam(handle_t objectHandle, int parameterID);

    void setObjectFloatParam(handle_t objectHandle, int parameterID, double parameter);

    // getObjectFloatArrayParam

    // setObjectFloatArrayParam

    double getEngineFloatParam(int paramId, handle_t objectHandle, const void *object);

    void setEngineFloatParam(int paramId, handle_t objectHandle, const void *object, double val);

    void transformImage(unsigned char *image, const int *resolution, int options);
    void transformImage(unsigned char *image, std::array<int, 2> resolution, int options);

    // getOctreeVoxels

    std::vector<double> getPointCloudPoints(handle_t pointCloudHandle);

    void getObjectMatrix(handle_t objectHandle, handle_t relativeToObjectHandle, double *matrix);
    std::array<double, 12> getObjectMatrix(handle_t objectHandle, handle_t relativeToObjectHandle);

    void setObjectMatrix(handle_t objectHandle, handle_t relativeToObjectHandle, const double *matrix);
    void setObjectMatrix(handle_t objectHandle, handle_t relativeToObjectHandle, const std::array<double, 12> &matrix);

    void getObjectPose(handle_t objectHandle, handle_t relativeToObjectHandle, double *pose);
    std::array<double, 7> getObjectPose(handle_t objectHandle, handle_t relativeToObjectHandle);

    void setObjectPose(handle_t objectHandle, handle_t relativeToObjectHandle, const double *pose);
    void setObjectPose(handle_t objectHandle, handle_t relativeToObjectHandle, std::array<double, 7> pose);

    void getObjectPosition(handle_t objectHandle, handle_t relativeToObjectHandle, double *position);
    std::array<double, 3> getObjectPosition(handle_t objectHandle, handle_t relativeToObjectHandle);

    void setObjectPosition(handle_t objectHandle, handle_t relativeToObjectHandle, const double *position);
    void setObjectPosition(handle_t objectHandle, handle_t relativeToObjectHandle, const std::array<double, 3> &position);

    void getObjectOrientation(handle_t objectHandle, handle_t relativeToObjectHandle, double *eulerAngles);
    std::array<double, 3> getObjectOrientation(handle_t objectHandle, handle_t relativeToObjectHandle);

    void setObjectOrientation(handle_t objectHandle, handle_t relativeToObjectHandle, const double *eulerAngles);
    void setObjectOrientation(handle_t objectHandle, handle_t relativeToObjectHandle, const std::array<double, 3> &eulerAngles);

    double getJointPosition(handle_t objectHandle);

    void setJointPosition(handle_t objectHandle, double position);

    void setJointTargetPosition(handle_t objectHandle, double targetPosition);

    double getJointTargetPosition(handle_t objectHandle);

    double getJointTargetForce(handle_t jointHandle);

    void setJointTargetForce(handle_t objectHandle, double forceOrTorque, bool signedValue);

    void getObjectChildPose(handle_t objectHandle, double *pose);
    std::array<double, 7> getObjectChildPose(handle_t objectHandle);

    void setObjectChildPose(handle_t objectHandle, const double *pose);
    void setObjectChildPose(handle_t objectHandle, std::array<double, 7> pose);

    void getJointInterval(handle_t objectHandle, bool *cyclic, double *interval);
    std::array<double, 2> getJointInterval(handle_t objectHandle, bool *cyclic);

    void setJointInterval(handle_t objectHandle, bool cyclic, const double *interval);
    void setJointInterval(handle_t objectHandle, bool cyclic, std::array<double, 2> interval);

    // buildIdentityMatrix

    // buildMatrix

    // buildPose

    // getEulerAnglesFromMatrix

    // invertMatrix

    std::array<double, 12> multiplyMatrices(std::array<double, 12> matrixIn1, std::array<double, 12> matrixIn2);

    std::array<double, 7> multiplyPoses(std::array<double, 7> poseIn1, std::array<double, 7> poseIn2);

    std::array<double, 7> invertPose(std::array<double, 7> pose);

    std::array<double, 7> interpolatePoses(std::array<double, 7> poseIn1, std::array<double, 7> poseIn2, double interpolFactor);

    std::array<double, 12> poseToMatrix(std::array<double, 7> poseIn);

    std::array<double, 7> matrixToPose(std::array<double, 12> matrixIn);

    std::array<double, 12> interpolateMatrices(std::array<double, 12> matrixIn1, std::array<double, 12> matrixIn2, double interpolFactor);

    void transformVector(const double *matrix, double *vect);
    std::array<double, 3> transformVector(std::array<double, 12> matrix, std::array<double, 3> vect);

    double getSimulationTime();

    double getSystemTime();

    // handleProximitySensor

    // readProximitySensor

    // handleDynamics

    // checkProximitySensor

    // checkProximitySensorEx

    // checkProximitySensorEx2

    // checkCollisionEx

    // checkDistance

    // setSimulationTimeStep

    double getSimulationTimeStep();

    // adjustRealTimeTimer

    // floatingViewAdd

    // handleGraph

    // setGraphStreamTransformation

    // addGraphCurve

    // setGraphStreamValue

    // setJointTargetVelocity

    // getJointTargetVelocity

    // scaleObjects

    // addDrawingObject

    // addGraphStream

    // addDrawingObjectItem

    // getObjectSizeFactor

    // readForceSensor

    // setLightParameters

    int getLightParameters(handle_t objectHandle);
    int getLightParameters(handle_t objectHandle, std::array<double, 3> &diffuse);
    int getLightParameters(handle_t objectHandle, std::array<double, 3> &diffuse, std::array<double, 3> &specular);

    // getVelocity

    std::pair<std::array<double, 3>, std::array<double, 3>> getObjectVelocity(handle_t objectHandle);

    // getJointVelocity

    // addForceAndTorque

    // addForce

    void setObjectColor(handle_t objectHandle, int index, int colorComponent, const float *rgbData);
    void setObjectColor(handle_t objectHandle, int index, int colorComponent, const std::array<float, 3> &rgbData);

    std::optional<std::array<float, 3>> getObjectColor(handle_t objectHandle, int index, int colorComponent);

    void setShapeColor(handle_t shapeHandle, const char *colorName, int colorComponent, const float *rgbData);
    void setShapeColor(handle_t shapeHandle, std::optional<std::string> colorName, int colorComponent, const std::array<float, 3> &rgbData);

    std::optional<std::array<float, 3>> getShapeColor(handle_t shapeHandle, std::optional<std::string> colorName, int colorComponent);
    std::optional<std::array<float, 3>> getShapeColor(handle_t shapeHandle, int colorComponent);

    // getContactInfo

    // auxiliaryConsoleOpen

    handle_t importShape(const char *pathAndFilename, int options, double scalingFactor);
    handle_t importShape(const std::string &pathAndFilename, int options, double scalingFactor);

    // importMesh

    // exportMesh

    handle_t createMeshShape(int options, double shadingAngle, const double *vertices, int verticesSize, const int *indices, int indicesSize);
    handle_t createMeshShape(int options, double shadingAngle, const std::vector<double> &vertices, const std::vector<int> &indices);

    handle_t createPrimitiveShape(int primitiveType, const double *sizes, int options);
    handle_t createPrimitiveShape(int primitiveType, std::array<double, 3> sizes, int options);

    handle_t createHeightfieldShape(int options, double shadingAngle, int xPointCount, int yPointCount, double xSize, const double *heights);
    handle_t createHeightfieldShape(int options, double shadingAngle, int xPointCount, int yPointCount, double xSize, const std::vector<double> &heights);

    void getShapeMesh(handle_t shapeHandle, double **vertices, int *verticesSize, int **indices, int *indicesSize, double **normals = nullptr);
    void getShapeMesh(handle_t shapeHandle, std::vector<double> vertices, std::vector<int> indices, std::optional<std::vector<double>> normals = {});

    handle_t createJoint(int jointType, int jointMode, int options, const double *sizes);
    handle_t createJoint(int jointType, int jointMode, int options = 0, std::optional<std::array<double, 2>> sizes = {});

    handle_t createDummy(double size = 0.01);

    handle_t createForceSensor(int options, const int *intParams, const double *floatParams);
    handle_t createForceSensor(int options, int type, int valueCount, int thresholdCount, double size, double forceThreshold, double torqueThreshold);

    handle_t createVisionSensor(int options, const int *intParams, const double *floatParams);
    handle_t createVisionSensor(int options, std::array<int, 2> resolution, double clipNear, double clipFar, double viewAngleOrOrthoSize, double xSize, std::array<float, 3> nullPixelColor);

    handle_t createProximitySensor(int sensorType, int options, const int *intParams, const double *floatParams);
    handle_t createProximitySensor(int sensorType, int options, int faceCount, int faceCountFar, int subdivisions, int subdivisionsFar, int randDetSampleCountPerReading, int randDetIndividualRayDetCntForTrig, double offset, double range, std::array<double, 2> size, std::array<double, 2> sizeFar, double insideGap, double radius, double radiusFar, double angle, double thresholdAngle, double smallestDetDist, double sensPointSize);

    std::pair<std::array<double, 3>, double> getRotationAxis(std::array<double, 12> matrixStart, std::array<double, 12> matrixGoal);
    std::pair<std::array<double, 3>, double> getRotationAxis(std::array<double, 7> matrixStart, std::array<double, 7> matrixGoal);

    // rotateAroundAxis

    // getJointForce

    // cameraFitToView

    // handleVisionSensor

    // readVisionSensor

    // checkVisionSensor

    unsigned char * getVisionSensorImg(handle_t sensorHandle, int options, double rgbaCutOff, std::array<int, 2> pos = {0, 0}, std::array<int, 2> size = {0, 0}, std::array<int, 2> *resolution = nullptr);

    std::array<int, 2> getVisionSensorRes(handle_t visionSensorHandle);

    std::array<double, 4> getObjectQuaternion(handle_t objectHandle, handle_t relativeToObjectHandle);

    void setObjectQuaternion(handle_t objectHandle, handle_t relativeToObjectHandle, const std::array<double, 4> &quaternion);

    // convexDecompose

    void writeTexture(int textureId, int options, const char *data, int posX = 0, int posY = 0, int sizeX = 0, int sizeY = 0, double interpol = 0.0);

    // createTexture

    // getShapeGeomInfo

    // scaleObject

    // setShapeTexture

    // getQHull

    // getDecimatedMesh

    // computeMassAndInertia

    // createOctree

    handle_t createPointCloud(double maxVoxelSize, int maxPtCntPerVoxel, int options, double pointSize);

    // setPointCloudOptions

    // getPointCloudOptions

    // insertVoxelsIntoOctree

    // removeVoxelsFromOctree

    // insertPointsIntoPointCloud

    // removePointsFromPointCloud

    // intersectPointsWithPointCloud

    int insertObjectIntoPointCloud(handle_t pointCloudHandle, handle_t objectHandle, int options, double gridSize, std::optional<std::array<unsigned char, 3>> color = {}, std::optional<float> duplicateTolerance = {});

    // subtractObjectFromPointCloud

    bool checkOctreePointOccupancy(handle_t octreeHandle, int options, const double *pts, int ptCnt, unsigned int *tag = nullptr, unsigned long long int *location = nullptr);
    bool checkOctreePointOccupancy(handle_t octreeHandle, int options, const std::vector<double> &pts, unsigned int *tag = nullptr, unsigned long long int *location = nullptr);

    // applyTexture

    // setJointDependency

    // getJointDependency

    double getShapeMass(handle_t shapeHandle);

    void setShapeMass(handle_t shapeHandle, double mass);

    void getShapeInertia(handle_t shapeHandle, double *inertiaMatrix, double *transformationMatrix);
    std::pair<std::array<double, 9>, std::array<double, 12>> getShapeInertia(handle_t shapeHandle);

    void setShapeInertia(handle_t shapeHandle, const double *inertiaMatrix, const double *transformationMatrix);
    void setShapeInertia(handle_t shapeHandle, std::array<double, 9> inertiaMatrix, std::array<double, 12> transformationMatrix);

    // generateShapeFromPath

    // getClosestPosOnPath

    // extCallScriptFunction

    // getObjectLocalTransformation

    // setObjectLocalTransformation

    // dynReportObjectCumulativeTransformation

    // setObjectCumulativeTransformation

    // getObjectCumulativeTransformation

    // setJointVelocity

    // setJointPosition

    // getJointPosition

    // setDynamicMotorPositionControlTargetPosition

    // getInitialDynamicVelocity

    // setInitialDynamicVelocity

    // getInitialDynamicAngVelocity

    // setInitialDynamicAngVelocity

    // setShapeDynamicVelocity

    // getAdditionalForceAndTorque

    // getJointPositionInterval

    // getDynamicMotorTargetPosition

    // getDynamicMotorTargetVelocity

    // getDynamicMotorMaxForce

    // getDynamicMotorUpperLimitVelocity

    // setDynamicMotorReflectedPositionFromDynamicEngine

    // setJointSphericalTransformation

    // addForceSensorCumulativeForcesAndTorques

    // addJointCumulativeForcesOrTorques

    // getMass

    // getLocalInertiaInfo

    // getPurePrimitiveSizes

    // getVerticesLocalFrame

    // getHeightfieldData

    // getCumulativeMeshes

    // getGravity

    // getDistanceBetweenEntitiesIfSmaller

    // handleJointControl

    // handleCustomContact

    // getPureHollowScaling

    // dynCallback

    void setBoolProperty(handle_t target, const std::string &pname, bool value);

    bool getBoolProperty(handle_t target, const std::string &pname);

    void setIntProperty(handle_t target, const std::string &pname, int value);

    int getIntProperty(handle_t target, const std::string &pname);

    void setFloatProperty(handle_t target, const std::string &pname, double value);

    double getFloatProperty(handle_t target, const std::string &pname);

    void setStringProperty(handle_t target, const std::string &pname, const std::string &value);

    std::string getStringProperty(handle_t target, const std::string &pname);

    void setBufferProperty(handle_t target, const std::string &pname, const std::string &value);

    std::string getBufferProperty(handle_t target, const std::string &pname);

    void setVector3Property(handle_t target, const std::string &pname, std::array<double, 3> value);

    std::array<double, 3> getVector3Property(handle_t target, const std::string &pname);

    void setQuaternionProperty(handle_t target, const std::string &pname, std::array<double, 4> value);

    std::array<double, 4> getQuaternionProperty(handle_t target, const std::string &pname);

    void setPoseProperty(handle_t target, const std::string &pname, std::array<double, 7> value);

    std::array<double, 7> getPoseProperty(handle_t target, const std::string &pname);

    void setColorProperty(handle_t target, const std::string &pname, std::array<float, 3> value);

    std::array<float, 3> getColorProperty(handle_t target, const std::string &pname);

    void setFloatArrayProperty(handle_t target, const std::string &pname, const std::vector<double> &value);

    std::vector<double> getFloatArrayProperty(handle_t target, const std::string &pname);

    void setIntArrayProperty(handle_t target, const std::string &pname, const std::vector<int> &value);

    std::vector<int> getIntArrayProperty(handle_t target, const std::string &pname);

#if 0
    void setFloatArray2Property(handle_t target, const std::string &pname, const std::array<double, 2> &value);

    std::array<double, 2> getFloatArray2Property(handle_t target, const std::string &pname);

    void setFloatArray3Property(handle_t target, const std::string &pname, const std::array<double, 3> &value);

    std::array<double, 3> getFloatArray3Property(handle_t target, const std::string &pname);
#endif

    void setIntArray2Property(handle_t target, const std::string &pname, const std::array<int, 2> &value);

    std::array<int, 2> getIntArray2Property(handle_t target, const std::string &pname);

    void removeProperty(handle_t target, const std::string &pname);

    bool getPropertyName(handle_t target, int index, std::string &pname);
    bool getPropertyName(handle_t target, int index, std::string &pname, SPropertyOptions &opts);
    bool getPropertyName(handle_t target, int index, std::string &pname, std::string &pclass);
    bool getPropertyName(handle_t target, int index, std::string &pname, std::string &pclass, SPropertyOptions &opts);

    bool getPropertyInfo(handle_t target, const std::string &pname, SPropertyInfo &info);
    bool getPropertyInfo(handle_t target, const std::string &pname, SPropertyInfo &info, SPropertyOptions &opts);

#ifdef HAVE_JSONCONS
    void pushObjectOntoStack(handle_t stackHandle, const jsoncons::json &obj);

    void pushArrayOntoStack(handle_t stackHandle, const jsoncons::json& arr);

    void pushValueOntoStack(handle_t stackHandle, const jsoncons::json& value);

    int getStackValue(handle_t stackHandle, jsoncons::json *value);
#endif
} // namespace sim

#endif // SIMPLUSPLUS_LIB_H_INCLUDED
