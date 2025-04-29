#include "Plugin.h"

#include <string>
#include <vector>
#include <cstring>
#include <iostream>

#ifdef HAVE_JSONCONS
#include <jsoncons_ext/cbor/cbor.hpp>
#endif // HAVE_JSONCONS

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
        sim::setPluginInfo(sim_moduleinfo_extversionstr, s);
    }

    void Plugin::setExtVersion(int i)
    {
        sim::setPluginInfo(sim_moduleinfo_extversionint, i);
    }

    void Plugin::setBuildDate(const std::string &s)
    {
        sim::setPluginInfo(sim_moduleinfo_builddatestr, s);
    }

    void Plugin::setVerbosity(int i)
    {
        sim::setPluginInfo(sim_moduleinfo_verbosity, i);
    }

    int Plugin::getVerbosity()
    {
        return sim::getPluginInfoInt(sim_moduleinfo_verbosity);
    }

    void Plugin::onInit()
    {
    }

    void Plugin::onCleanup()
    {
    }

    void Plugin::onMsg(SSimMsg *msg)
    {
        int errorModeSaved = sim::getInt32Param(sim_intparam_error_report_mode);
        sim::setInt32Param(sim_intparam_error_report_mode, sim_api_errormessage_ignore);

        switch(msg->msgId)
        {
        case sim_message_eventcallback_instancepass:
            /*
            Called once every main client application loop pass.
            msg->auxData[0] contains event flags of events that happened since last time.
            If you react to some of below event flags, make sure you do not react to their
            equivalent event callback message (e.g. sim_message_eventcallback_sceneloaded is
            similar to below's bit3 set)
            */
            {
                InstancePassFlags flags;
                flags.objectsErased         = (msg->auxData[0] & (1 <<  0)) > 0;
                flags.objectsCreated        = (msg->auxData[0] & (1 <<  1)) > 0;
                flags.modelLoaded           = (msg->auxData[0] & (1 <<  2)) > 0;
                flags.sceneLoaded           = (msg->auxData[0] & (1 <<  3)) > 0;
                flags.undoCalled            = (msg->auxData[0] & (1 <<  4)) > 0;
                flags.redoCalled            = (msg->auxData[0] & (1 <<  5)) > 0;
                flags.sceneSwitched         = (msg->auxData[0] & (1 <<  6)) > 0;
                flags.editModeActive        = (msg->auxData[0] & (1 <<  7)) > 0;
                flags.objectsScaled         = (msg->auxData[0] & (1 <<  8)) > 0;
                flags.selectionStateChanged = (msg->auxData[0] & (1 <<  9)) > 0;
                flags.keyPressed            = (msg->auxData[0] & (1 << 10)) > 0;
                flags.simulationStarted     = (msg->auxData[0] & (1 << 11)) > 0;
                flags.simulationEnded       = (msg->auxData[0] & (1 << 12)) > 0;
                flags.scriptCreated         = (msg->auxData[0] & (1 << 13)) > 0;
                flags.scriptErased          = (msg->auxData[0] & (1 << 14)) > 0;

                onInstancePass(flags);
            }
            break;
        case sim_message_eventcallback_instanceswitch:
            /*
            scene was switched (react to this message in a similar way as you would react to
            a full scene content change)

            msg->auxData[0]: do not use
            msg->auxData[1]=current scene unique ID
            msg->auxData[2]=old scene unique ID
            */
            {
                onInstanceSwitch(msg->auxData[1], msg->auxData[2]);
            }
            break;
        case sim_message_eventcallback_instanceabouttoswitch:
            /*
            we are about to switch to a different scene

            msg->auxData[0]: do not use
            msg->auxData[1]=next scene unique ID
            msg->auxData[2]=old scene unique ID
            */
            {
                onInstanceAboutToSwitch(msg->auxData[1], msg->auxData[2]);
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
        case sim_message_eventcallback_scriptstateabouttobedestroyed:
            {
                int scriptHandle = msg->auxData[0];
                long long scriptUid = (static_cast<long long>(msg->auxData[2]) << 32) | (static_cast<unsigned int>(msg->auxData[1]));
                onScriptStateAboutToBeDestroyed(scriptHandle, scriptUid);
            }
            break;
        case sim_message_eventcallback_scriptabouttobedestroyed:
            {
                int scriptHandle = msg->auxData[0];
                long long scriptUid = (static_cast<long long>(msg->auxData[2]) << 32) | (static_cast<unsigned int>(msg->auxData[1]));
                onScriptAboutToBeDestroyed(scriptHandle, scriptUid);
            }
            break;
        case sim_message_eventcallback_simulationinit:
            /*
            called before/after the main script's init. auxData[0]=0:before, auxData[0]=1:after
            */
            {
                if(msg->auxData[0] == 0) onSimulationBeforeInit();
                if(msg->auxData[0] == 1) onSimulationAfterInit();
            }
            break;
        case sim_message_eventcallback_simulationactuation:
            /*
            called before/after the main script's actuation. auxData[0]=0:before, auxData[0]=1:after
            */
            {
                if(msg->auxData[0] == 0) onSimulationBeforeActuation();
                if(msg->auxData[0] == 1) onSimulationAfterActuation();
            }
            break;
        case sim_message_eventcallback_simulationsensing:
            /*
            called before/after the main script's sensing. auxData[0]=0:before, auxData[0]=1:after
            */
            {
                if(msg->auxData[0] == 0) onSimulationBeforeSensing();
                if(msg->auxData[0] == 1) onSimulationAfterSensing();
            }
            break;
        case sim_message_eventcallback_simulationcleanup:
            /*
            called before/after the main script's cleanup. auxData[0]=0:before, auxData[0]=1:after
            */
            {
                if(msg->auxData[0] == 0) onSimulationBeforeCleanup();
                if(msg->auxData[0] == 1) onSimulationAfterCleanup();
            }
            break;
        case sim_message_eventcallback_events:
            {
                onEvents(msg->auxPointer, msg->auxData[1]);
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

    void Plugin::onUIMsg(SSimMsg_ui *msg)
    {
        switch(msg->msgId)
        {
        case 0 /*sim_message_eventcallback_uipass*/:
            {
                onUIPass();
            }
            break;
        case sim_message_eventcallback_menuitemselected:
            /*
            (called from the UI thread)
            msg->auxData[0]=handle of the item
            msg->auxData[1]=state of the item
            */
            {
                onUIMenuItemSelected(msg->auxData[0], msg->auxData[1]);
            }
            break;
        }
    }

    LIBRARY Plugin::loadSimLibrary(const char *coppeliaSimLibPath)
    {
        LIBRARY lib = ::loadSimLibrary(coppeliaSimLibPath);
        if(lib == NULL)
        {
            throw std::runtime_error("could not find or correctly load the CoppeliaSim library");
        }
        if(::getSimProcAddresses(lib) == 0)
        {
            ::unloadSimLibrary(lib);
            throw std::runtime_error("could not find all required functions in the CoppeliaSim library");
        }
        return lib;
    }

    void Plugin::onInstancePass(const InstancePassFlags &flags)
    {
    }

    void Plugin::onInstanceSwitch(int sceneID, int oldSceneID)
    {
    }

    void Plugin::onInstanceAboutToSwitch(int sceneID, int oldSceneID)
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

    void Plugin::onScriptStateAboutToBeDestroyed(int scriptHandle, long long scriptUid)
    {
    }

    void Plugin::onScriptAboutToBeDestroyed(int scriptHandle, long long scriptUid)
    {
    }

    void Plugin::onSimulationBeforeInit()
    {
    }

    void Plugin::onSimulationAfterInit()
    {
    }

    void Plugin::onSimulationBeforeActuation()
    {
    }

    void Plugin::onSimulationAfterActuation()
    {
    }

    void Plugin::onSimulationBeforeSensing()
    {
    }

    void Plugin::onSimulationAfterSensing()
    {
    }

    void Plugin::onSimulationBeforeCleanup()
    {
    }

    void Plugin::onSimulationAfterCleanup()
    {
    }

    void Plugin::onEvents(void *data, size_t size)
    {
#ifdef HAVE_JSONCONS
        auto u8data = reinterpret_cast<const uint8_t*>(data);
        jsoncons::json msg = jsoncons::cbor::decode_cbor<jsoncons::json>(u8data, u8data + size);
        for(size_t i = 0; i < msg.size(); i++)
            onEvent(msg[i]);
#endif // HAVE_JSONCONS
    }

#ifdef HAVE_JSONCONS
    void Plugin::onEvent(const jsoncons::json &event)
    {
        EventInfo info;
        info.event = event["event"].as<std::string>();
        info.seq = event["seq"].as<long>();
        info.uid = event.contains("uid") ? event["uid"].as<long>() : -1;
        info.handle = event.contains("handle") ? event["handle"].as<int>() : -1;
        onEvent(info, event["data"]);
    }

    void Plugin::onEvent(const EventInfo &info, const jsoncons::json &data)
    {
        if(info.event == "objectAdded")
            onObjectAdded(info, data);
        else if(info.event == "objectChanged")
            onObjectChanged(info, data);
        else if(info.event == "objectRemoved")
            onObjectRemoved(info, data);
        else if(info.event == "drawingObjectAdded")
            onDrawingObjectAdded(info, data);
        else if(info.event == "drawingObjectChanged")
            onDrawingObjectChanged(info, data);
        else if(info.event == "drawingObjectRemoved")
            onDrawingObjectRemoved(info, data);
        else if(info.event == "environmentChanged")
            onEnvironmentChanged(info, data);
        else if(info.event == "appSettingsChanged")
            onAppSettingsChanged(info, data);
        else if(info.event == "simulationChanged")
            onSimulationChanged(info, data);
        else if(info.event == "appSession")
            onAppSession(info, data);
        else if(info.event == "genesisBegin")
            onGenesisBegin(info, data);
        else if(info.event == "genesisEnd")
            onGenesisEnd(info, data);
    }

    void Plugin::onObjectAdded(const EventInfo &info, const jsoncons::json &data)
    {
    }

    void Plugin::onObjectChanged(const EventInfo &info, const jsoncons::json &data)
    {
    }

    void Plugin::onObjectRemoved(const EventInfo &info, const jsoncons::json &data)
    {
    }

    void Plugin::onDrawingObjectAdded(const EventInfo &info, const jsoncons::json &data)
    {
    }

    void Plugin::onDrawingObjectChanged(const EventInfo &info, const jsoncons::json &data)
    {
    }

    void Plugin::onDrawingObjectRemoved(const EventInfo &info, const jsoncons::json &data)
    {
    }

    void Plugin::onEnvironmentChanged(const EventInfo &info, const jsoncons::json &data)
    {
    }

    void Plugin::onAppSettingsChanged(const EventInfo &info, const jsoncons::json &data)
    {
    }

    void Plugin::onSimulationChanged(const EventInfo &info, const jsoncons::json &data)
    {
    }

    void Plugin::onAppSession(const EventInfo &info, const jsoncons::json &data)
    {
    }

    void Plugin::onGenesisBegin(const EventInfo &info, const jsoncons::json &data)
    {
    }

    void Plugin::onGenesisEnd(const EventInfo &info, const jsoncons::json &data)
    {
    }
#endif // HAVE_JSONCONS

    void Plugin::onUIPass()
    {
    }

    void Plugin::onUIMenuItemSelected(int itemHandle, int itemState)
    {
    }
}

std::ostream& operator<<(std::ostream &os, const sim::EventInfo &info)
{
    os << "sim::EventInfo(event=" << info.event << ", seq=" << info.seq << ", uid=" << info.uid << ", handle=" << info.handle << ")";
    return os;
}
