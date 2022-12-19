//
// Created by kolterdyx on 1/11/22.
//

#ifndef CEMENTENGINE_EVENT_HPP
#define CEMENTENGINE_EVENT_HPP

#include <entt/entt.hpp>

namespace Cement::Event {

    class EventManager {
    private:
        static entt::dispatcher dispatcher;
    public:

        EventManager() = delete;

        template<typename T>
        static void emit(T &event) {
            dispatcher.trigger<T>(event);
        }

        template<typename T>
        static void subscribe(T &listener) {
            dispatcher.sink<T>().connect<&T::receive>(listener);
        }

        template<typename T>
        static void unsubscribe(T &listener) {
            dispatcher.sink<T>().disconnect<&T::receive>(listener);
        }
    };
}

#endif //CEMENTENGINE_EVENT_HPP
