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

        virtual LIBRARY loadSimLibrary();

        virtual void onInit();
        virtual void onCleanup();
        virtual void onMsg(int message, int *auxiliaryData, void *customData) final;
        virtual void onUIInit();
        virtual void onUICleanup();
        virtual void onUIMsg(int message, int *auxiliaryData, void *customData);

        virtual void onInstancePass(const InstancePassFlags &flags);
        virtual void onInstanceSwitch(int sceneID);
        virtual void onInstanceAboutToSwitch(int sceneID);
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
        virtual void onScriptStateDestroyed(int scriptID);

        virtual void onUIPass();
        virtual void onUIMenuItemSelected(int itemHandle, int itemState);

    private:
        std::string name_;
    };
}

#define SIM_PLUGIN(className_) \
namespace sim { \
::className_ *plugin; \
sim::PluginInfo *pluginInfo; \
} \
SIM_DLLEXPORT unsigned char simInit(void *reservedPointer, int reservedInt) \
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
        sim::pluginInfo->lib = sim::plugin->loadSimLibrary(); \
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
SIM_DLLEXPORT void simMsg(int message, int *auxiliaryData, void *customData) \
{ \
    try \
    { \
        if(sim::plugin) \
        { \
            return sim::plugin->onMsg(message, auxiliaryData, customData); \
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
SIM_DLLEXPORT void simMsg_ui(int message, int *auxiliaryData, void *customData) \
{ \
    try \
    { \
        if(sim::plugin) \
        { \
            return sim::plugin->onUIMsg(message, auxiliaryData, customData); \
        } \
    } \
    catch(std::exception &ex) \
    { \
        sim::addLog(sim_verbosity_errors, ex.what()); \
    } \
}

#endif // SIMPLUSPLUS_PLUGIN_H_INCLUDED
