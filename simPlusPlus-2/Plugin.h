#ifndef SIMPLUSPLUS_PLUGIN_H_INCLUDED
#define SIMPLUSPLUS_PLUGIN_H_INCLUDED

#if __cplusplus <= 199711L
    #error simPlusPlus needs at least a C++11 compliant compiler
#endif

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <boost/format.hpp>

#include "Lib.h"

#ifdef _WIN32
    #ifdef QT_COMPIL
        #include <direct.h>
    #else
        #include <shlwapi.h>
        #pragma comment(lib, "Shlwapi.lib")
    #endif
#endif /* _WIN32 */
#if defined (__linux) || defined (__APPLE__)
    #include <unistd.h>
#define _stricmp strcasecmp
#endif /* __linux || __APPLE__ */

#include <simLib/simExp.h> // for SIM_DLLEXPORT
#include <simLib/simTypes.h> // for SIM_DLLEXPORT

#ifdef HAVE_JSONCONS
#include <jsoncons/json.hpp>
#endif // HAVE_JSONCONS

namespace sim
{
    extern sim::PluginInfo *pluginInfo;

    struct InstancePassFlags
    {
        bool objectsErased;
        bool objectsCreated;
        bool modelLoaded;
        bool sceneLoaded;
        bool undoCalled;
        bool redoCalled;
        bool sceneSwitched;
        bool editModeActive;
        bool objectsScaled;
        bool selectionStateChanged;
        bool keyPressed;
        bool simulationStarted;
        bool simulationEnded;
        bool scriptCreated;
        bool scriptErased;
    };

    struct EventInfo
    {
        std::string event;
        long seq;
        long uid;
        int handle;
    };

    class Plugin
    {
    public:
        void setName(const std::string &name);
        std::string name() const;
        void setExtVersion(const std::string &s);
        void setExtVersion(int i);
        void setBuildDate(const std::string &s);
        void setVerbosity(int i);
        int getVerbosity();
        void init();

        virtual LIBRARY loadSimLibrary(const char *coppeliaSimLibPath);

        virtual void onInit();
        virtual void onCleanup();
        virtual void onMsg(SSimMsg *msg) final;
        virtual void onUIInit();
        virtual void onUICleanup();
        virtual void onUIMsg(SSimMsg_ui *msg) final;

        virtual void onInstancePass(const InstancePassFlags &flags);
        virtual void onInstanceSwitch(int sceneID, int oldSceneID);
        virtual void onInstanceAboutToSwitch(int sceneID, int oldSceneID);
        virtual void onSceneSave();
        virtual void onModelSave();
        virtual void onAboutToUndo();
        virtual void onUndo();
        virtual void onAboutToRedo();
        virtual void onRedo();
        virtual void onSimulationAboutToStart();
        virtual void onSimulationAboutToEnd();
        virtual void onSimulationEnded();
        virtual void onSceneLoaded();
        virtual void onModelLoaded();
        virtual void onScriptStateAboutToBeDestroyed(int scriptHandle, long long scriptUid);
        virtual void onScriptAboutToBeDestroyed(int scriptHandle, long long scriptUid);
        virtual void onSimulationBeforeInit();
        virtual void onSimulationAfterInit();
        virtual void onSimulationBeforeActuation();
        virtual void onSimulationAfterActuation();
        virtual void onSimulationBeforeSensing();
        virtual void onSimulationAfterSensing();
        virtual void onSimulationBeforeCleanup();
        virtual void onSimulationAfterCleanup();
        virtual void onEvents(void *data, size_t size);
#ifdef HAVE_JSONCONS
        virtual void onEvent(const jsoncons::json &event);
        virtual void onEvent(const EventInfo &info, const jsoncons::json &data);
        virtual void onObjectAdded(const EventInfo &info, const jsoncons::json &data);
        virtual void onObjectChanged(const EventInfo &info, const jsoncons::json &data);
        virtual void onObjectRemoved(const EventInfo &info, const jsoncons::json &data);
        virtual void onDrawingObjectAdded(const EventInfo &info, const jsoncons::json &data);
        virtual void onDrawingObjectChanged(const EventInfo &info, const jsoncons::json &data);
        virtual void onDrawingObjectRemoved(const EventInfo &info, const jsoncons::json &data);
        virtual void onEnvironmentChanged(const EventInfo &info, const jsoncons::json &data);
        virtual void onAppSettingsChanged(const EventInfo &info, const jsoncons::json &data);
        virtual void onSimulationChanged(const EventInfo &info, const jsoncons::json &data);
        virtual void onAppSession(const EventInfo &info, const jsoncons::json &data);
        virtual void onGenesisBegin(const EventInfo &info, const jsoncons::json &data);
        virtual void onGenesisEnd(const EventInfo &info, const jsoncons::json &data);
#endif // HAVE_JSONCONS

        virtual void onUIPass();
        virtual void onUIMenuItemSelected(int itemHandle, int itemState);

    private:
        std::string name_;
    };
}

std::ostream& operator<<(std::ostream &os, const sim::EventInfo &obj);

#define SIM_PLUGIN(className_) \
namespace sim { \
::className_ *plugin; \
sim::PluginInfo *pluginInfo; \
} \
SIM_DLLEXPORT int simInit(SSimInit *initInfo) \
{ \
    try \
    { \
        sim::pluginInfo = new sim::PluginInfo; \
        sim::pluginInfo->name = PLUGIN_NAME; \
        sim::pluginInfo->version = PLUGIN_VERSION; \
        sim::pluginInfo->nameAndVersion = sim::pluginInfo->name; \
        if(sim::pluginInfo->version > 0) \
        { \
            sim::pluginInfo->nameAndVersion += "-"; \
            sim::pluginInfo->nameAndVersion += std::to_string(sim::pluginInfo->version); \
        } \
        sim::plugin = new className_; \
        sim::plugin->setName(sim::pluginInfo->name); \
        sim::pluginInfo->lib = sim::plugin->loadSimLibrary(initInfo->coppeliaSimLibPath); \
        sim::plugin->onInit(); \
        return std::max(1, sim::pluginInfo->version); \
    } \
    catch(std::exception &ex) \
    { \
        sim::addLog(sim_verbosity_errors, ex.what()); \
        return 0; \
    } \
} \
SIM_DLLEXPORT void simCleanup() \
{ \
    try \
    { \
        if(sim::plugin) \
        { \
            sim::plugin->onCleanup(); \
            delete sim::plugin; \
            sim::plugin = nullptr; \
        } \
    } \
    catch(std::exception &ex) \
    { \
        sim::addLog(sim_verbosity_errors, ex.what()); \
    } \
    unloadSimLibrary(sim::pluginInfo->lib); \
    delete sim::pluginInfo; \
    sim::pluginInfo = nullptr; \
} \
SIM_DLLEXPORT void simMsg(SSimMsg *msg) \
{ \
    try \
    { \
        if(sim::plugin) \
        { \
            return sim::plugin->onMsg(msg); \
        } \
    } \
    catch(std::exception &ex) \
    { \
        sim::addLog(sim_verbosity_errors, ex.what()); \
    } \
}
#define SIM_UI_PLUGIN(className_) \
SIM_PLUGIN(className_); \
SIM_DLLEXPORT void simInit_ui() \
{ \
    try \
    { \
        if(sim::plugin) \
        { \
            return sim::plugin->onUIInit(); \
        } \
    } \
    catch(std::exception &ex) \
    { \
        sim::addLog(sim_verbosity_errors, ex.what()); \
    } \
} \
SIM_DLLEXPORT void simCleanup_ui() \
{ \
    try \
    { \
        if(sim::plugin) \
        { \
            return sim::plugin->onUICleanup(); \
        } \
    } \
    catch(std::exception &ex) \
    { \
        sim::addLog(sim_verbosity_errors, ex.what()); \
    } \
} \
SIM_DLLEXPORT void simMsg_ui(SSimMsg_ui *msg) \
{ \
    try \
    { \
        if(sim::plugin) \
        { \
            return sim::plugin->onUIMsg(msg); \
        } \
    } \
    catch(std::exception &ex) \
    { \
        sim::addLog(sim_verbosity_errors, ex.what()); \
    } \
}

#endif // SIMPLUSPLUS_PLUGIN_H_INCLUDED
