
#ifndef CEMENTENGINE_EVENTMANAGER_HPP
#define CEMENTENGINE_EVENTMANAGER_HPP

#include <entt/entt.hpp>

namespace Cement::Event {

    class EventManager {
    private:
        static entt::dispatcher dispatcher;
    public:

        EventManager() = delete;

        template<typename T>
        static void emit(T &event);

        template<typename T>
        static void subscribe(T &listener);

        template<typename T>
        static void unsubscribe(T &listener);
    };
}

#include "EventManager.tpp"

#endif //CEMENTENGINE_EVENTMANAGER_HPP
