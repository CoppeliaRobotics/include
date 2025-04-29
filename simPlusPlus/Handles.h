#ifndef SIMPLUSPLUS_HANDLES_H_INCLUDED
#define SIMPLUSPLUS_HANDLES_H_INCLUDED

#include <string>
#include <map>
#include <set>
#include <sstream>

#include <simPlusPlus/Lib.h>

namespace sim
{
    /*! \brief A tool for converting pointers to strings and vice versa.
     */
    template<typename T, class TCompare = std::less<T>>
    struct Handles
    {
    private:
        template<typename U>
        static void * toPtr(U* object)
        {
            return object;
        }

        template<typename U>
        static void * toPtr(std::shared_ptr<U> object)
        {
            return object.get();
        }

        template<typename U>
        static void * toPtr(std::weak_ptr<U> object)
        {
            if(auto p = object.lock())
                return p.get();
            else
                return nullptr;
        }

        static bool equals(const T &a, const T &b)
        {
            auto cmp = TCompare{};
            return !cmp(a, b) && !cmp(b, a);
        }

    public:
        Handles() : typeString_("ptr") {}

        Handles(const std::string &typeString) : typeString_(typeString) {}

        std::string toHandle(T object)
        {
            std::stringstream ss;
            ss << typeString_ << ':' << toPtr(object);
            return ss.str();
        }

        std::string add(T object)
        {
            std::string handle = toHandle(object);
            auto it = handleToObject_.find(handle);
            if(it != handleToObject_.end())
            {
                if(!equals(it->second, object))
                    throw std::runtime_error("fatal error: handle already exists but points to different object");
            }
            else
            {
                handleToObject_[handle] = object;
            }
            return handle;
        }

        std::string add(T object, int scriptID)
        {
            int sceneID = getSceneID(scriptID);
            sceneToScriptObjects_[sceneID][scriptID].insert(object);
            objectToSceneScripts_[object][sceneID] = scriptID;
            return add(object);
        }

        T remove(T object)
        {
            std::string handle = toHandle(object);
            auto it0 = handleToObject_.find(handle);
            if(it0 == handleToObject_.end())
                throw std::runtime_error("invalid object handle");
            handleToObject_.erase(it0);
            auto it = objectToSceneScripts_.find(object);
            if(it == objectToSceneScripts_.end()) return object;
            for(const auto &m : it->second)
            {
                int sceneID = m.first;
                int scriptID = m.second;
                auto it1 = sceneToScriptObjects_.find(sceneID);
                if(it1 == sceneToScriptObjects_.end()) continue;
                auto it2 = it1->second.find(scriptID);
                if(it2 == it1->second.end()) continue;
                it2->second.erase(object);
            }
            objectToSceneScripts_.erase(it);
            return object;
        }

        T get(const std::string &handle) const
        {
            auto it = handleToObject_.find(handle);
            if(it == handleToObject_.end())
                throw std::runtime_error("invalid object handle");
            return it->second;
        }

        T get(const std::string &handle, T defaultValue) const
        {
            auto it = handleToObject_.find(handle);
            if(it == handleToObject_.end())
                return defaultValue;
            return it->second;
        }

        std::set<T> find(int scriptID) const
        {
            int sceneID = getSceneID(scriptID);
            auto it = sceneToScriptObjects_.find(sceneID);
            if(it == sceneToScriptObjects_.end()) return {};
            auto it2 = it->second.find(scriptID);
            if(it2 == it->second.end()) return {};
            return it2->second;
        }

        std::set<T> findBySceneOfScript(int scriptID) const
        {
            return findByScene(getSceneID(scriptID));
        }

        std::set<T> findByScene(int sceneID) const
        {
            auto it = sceneToScriptObjects_.find(sceneID);
            if(it == sceneToScriptObjects_.end()) return {};
            std::set<T> ret;
            for(const auto &x : it->second)
                for(auto object : x.second)
                    ret.insert(object);
            return ret;
        }

        std::set<T> all() const
        {
            std::set<T> ret;
            for(const auto &x : objectToSceneScripts_)
                ret.insert(x.first);
            return ret;
        }

        std::set<std::string> handles() const
        {
            std::set<std::string> ret;
            for(const auto &x : objectToSceneScripts_)
                ret.insert(toHandle(x.first));
            return ret;
        }

    private:
        static int getSceneID(int scriptID)
        {
            int scriptType = sim::getScriptInt32Param(scriptID, sim_scriptintparam_type);
            if(0
                    || scriptType == sim_scripttype_main
                    || scriptType == sim_scripttype_simulation
                    || scriptType == sim_scripttype_customization
            )
                return sim::getInt32Param(sim_intparam_scene_unique_id);
            else
                return -1;
        }

        // handle -> object
        std::map<std::string, T> handleToObject_;

        // sceneID -> (scriptID -> [objects])
        std::map<int, std::map<int, std::set<T, TCompare>>> sceneToScriptObjects_;

        // object -> (sceneID -> scriptID)
        std::map<T, std::map<int, int>, TCompare> objectToSceneScripts_;

        const std::string typeString_;
    };

    template<typename T>
    using WeakHandles = Handles<T, std::owner_less<T>>;
}

#endif // SIMPLUSPLUS_HANDLES_H_INCLUDED
