#include "Plugin.h"

#include <string>
#include <vector>
#include <cstring>
#include <iostream>

namespace sim
{
    void Plugin::setName(const std::string &name)
    {
        name_ = name;
    }

    std::string Plugin::name() const
    {
        return name_;
    }

    void Plugin::setExtVersion(const std::string &s)
    {
        sim::setModuleInfo(sim_moduleinfo_extversionstr, s);
    }

    void Plugin::setExtVersion(int i)
    {
        sim::setModuleInfo(sim_moduleinfo_extversionint, i);
    }

    void Plugin::setBuildDate(const std::string &s)
    {
        sim::setModuleInfo(sim_moduleinfo_builddatestr, s);
    }

    void Plugin::setVerbosity(int i)
    {
        sim::setModuleInfo(sim_moduleinfo_verbosity, i);
    }

    int Plugin::getVerbosity()
    {
        return sim::getModuleInfoInt(sim_moduleinfo_verbosity);
    }

    void Plugin::onInit()
    {
    }

    void Plugin::onCleanup()
    {
    }

    void Plugin::onMsg(int message, int *auxiliaryData, void *customData)
    {
        int errorModeSaved = sim::getInt32Param(sim_intparam_error_report_mode);
        sim::setInt32Param(sim_intparam_error_report_mode, sim_api_errormessage_ignore);

        switch(message)
        {
        case sim_message_eventcallback_instancepass:
            /*
            Called once every main client application loop pass.
            auxiliaryData[0] contains event flags of events that happened since last time.
            If you react to some of below event flags, make sure you do not react to their
            equivalent event callback message (e.g. sim_message_eventcallback_sceneloaded is
            similar to below's bit3 set)
            */
            {
                InstancePassFlags flags;
                flags.objectsErased         = (auxiliaryData[0] & (1 <<  0)) > 0;
                flags.objectsCreated        = (auxiliaryData[0] & (1 <<  1)) > 0;
                flags.modelLoaded           = (auxiliaryData[0] & (1 <<  2)) > 0;
                flags.sceneLoaded           = (auxiliaryData[0] & (1 <<  3)) > 0;
                flags.undoCalled            = (auxiliaryData[0] & (1 <<  4)) > 0;
                flags.redoCalled            = (auxiliaryData[0] & (1 <<  5)) > 0;
                flags.sceneSwitched         = (auxiliaryData[0] & (1 <<  6)) > 0;
                flags.editModeActive        = (auxiliaryData[0] & (1 <<  7)) > 0;
                flags.objectsScaled         = (auxiliaryData[0] & (1 <<  8)) > 0;
                flags.selectionStateChanged = (auxiliaryData[0] & (1 <<  9)) > 0;
                flags.keyPressed            = (auxiliaryData[0] & (1 << 10)) > 0;
                flags.simulationStarted     = (auxiliaryData[0] & (1 << 11)) > 0;
                flags.simulationEnded       = (auxiliaryData[0] & (1 << 12)) > 0;
                flags.scriptCreated         = (auxiliaryData[0] & (1 << 13)) > 0;
                flags.scriptErased          = (auxiliaryData[0] & (1 << 14)) > 0;

                onInstancePass(flags);
            }
            break;
        case sim_message_eventcallback_instanceswitch:
            /*
            scene was switched (react to this message in a similar way as you would react to
            a full scene content change)

            auxiliaryData[0]: do not use
            auxiliaryData[1]=current scene unique ID
            */
            {
                onInstanceSwitch(auxiliaryData[1]);
            }
            break;
        case sim_message_eventcallback_instanceabouttoswitch:
            /*
            we are about to switch to a different scene

            auxiliaryData[0]: do not use
            auxiliaryData[1]=next scene unique ID
            */
            {
                onInstanceAboutToSwitch(auxiliaryData[1]);
            }
            break;
        case sim_message_eventcallback_scenesave:
            /*
            about to save a scene
            */
            {
                onSceneSave();
            }
            break;
        case sim_message_eventcallback_modelsave:
            /*
            about to save a model (current selection will be saved)
            */
            {
                onModelSave();
            }
            break;
        case sim_message_eventcallback_abouttoundo:
            /*
            the undo button was hit and a previous state is about to be restored
            */
            {
                onAboutToUndo();
            }
            break;
        case sim_message_eventcallback_undoperformed:
            /*
            the undo button was hit and a previous state was restored
            */
            {
                onUndo();
            }
            break;
        case sim_message_eventcallback_abouttoredo:
            /*
            the redo button was hit and a future state is about to be restored
            */
            {
                onAboutToRedo();
            }
            break;
        case sim_message_eventcallback_redoperformed:
            /*
            the redo button was hit and a future state was restored
            */
            {
                onRedo();
            }
            break;
        case sim_message_eventcallback_simulationabouttostart:
            /*
            simulation will start
            */
            {
                onSimulationAboutToStart();
            }
            break;
        case sim_message_eventcallback_simulationabouttoend:
            /*
            simulation will end
            */
            {
                onSimulationAboutToEnd();
            }
            break;
        case sim_message_eventcallback_simulationended:
            /*
            simulation has ended
            */
            {
                onSimulationEnded();
            }
            break;
        case sim_message_eventcallback_sceneloaded:
            /*
            called after a scene was loaded
            */
            {
                onSceneLoaded();
            }
            break;
        case sim_message_eventcallback_modelloaded:
            /*
            called after a model was loaded
            */
            {
                onModelLoaded();
            }
            break;
        case sim_message_eventcallback_scriptstatedestroyed:
            {
                onScriptStateDestroyed(auxiliaryData[0]);
            }
            break;
        }

        // Keep following unchanged:
        sim::setInt32Param(sim_intparam_error_report_mode, errorModeSaved);
    }

    void Plugin::onUIInit()
    {
    }

    void Plugin::onUICleanup()
    {
    }

    void Plugin::onUIMsg(int message, int *auxiliaryData, void *customData)
    {
        switch(message)
        {
        case 0 /*sim_message_eventcallback_uipass*/:
            {
                onUIPass();
            }
            break;
        case sim_message_eventcallback_menuitemselected:
            /*
            (called from the UI thread)
            auxiliaryData[0]=handle of the item
            auxiliaryData[1]=state of the item
            */
            {
                onUIMenuItemSelected(auxiliaryData[0], auxiliaryData[1]);
            }
            break;
        }
    }

    LIBRARY Plugin::loadSimLibrary()
    {
        LIBRARY lib = NULL;
        char curDirAndFile[1024];
#ifdef _WIN32
#ifdef QT_COMPIL
        _getcwd(curDirAndFile, sizeof(curDirAndFile));
#else
        ::GetModuleFileNameA(NULL, curDirAndFile, 1023);
        ::PathRemoveFileSpecA(curDirAndFile);
#endif
#elif defined (__linux) || defined (__APPLE__)
        getcwd(curDirAndFile, sizeof(curDirAndFile));
#endif
        std::string currentDirAndPath(curDirAndFile);
        std::string temp(currentDirAndPath);
#ifdef _WIN32
        temp += "\\coppeliaSim.dll";
#elif defined (__linux)
        temp += "/libcoppeliaSim.so";
#elif defined (__APPLE__)
        temp += "/libcoppeliaSim.dylib";
#endif
        lib = ::loadSimLibrary(temp.c_str());
        if(lib == NULL)
        {
            throw std::runtime_error("could not find or correctly load the CoppeliaSim library");
        }
        if(::getSimProcAddresses(lib)==0)
        {
            ::unloadSimLibrary(lib);
            throw std::runtime_error("could not find all required functions in the CoppeliaSim library");
        }
        return lib;
    }

    void Plugin::onInstancePass(const InstancePassFlags &flags)
    {
    }

    void Plugin::onInstanceSwitch(int sceneID)
    {
    }

    void Plugin::onInstanceAboutToSwitch(int sceneID)
    {
    }

    void Plugin::onSceneSave()
    {
    }

    void Plugin::onModelSave()
    {
    }

    void Plugin::onAboutToUndo()
    {
    }

    void Plugin::onUndo()
    {
    }

    void Plugin::onAboutToRedo()
    {
    }

    void Plugin::onRedo()
    {
    }

    void Plugin::onSimulationAboutToStart()
    {
    }

    void Plugin::onSimulationAboutToEnd()
    {
    }

    void Plugin::onSimulationEnded()
    {
    }

    void Plugin::onSceneLoaded()
    {
    }

    void Plugin::onModelLoaded()
    {
    }

    void Plugin::onScriptStateDestroyed(int scriptID)
    {
    }

    void Plugin::onUIPass()
    {
    }

    void Plugin::onUIMenuItemSelected(int itemHandle, int itemState)
    {
    }
}
