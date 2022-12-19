
#ifndef CEMENTENGINE_EVENTMANAGER_TPP
#define CEMENTENGINE_EVENTMANAGER_TPP

#include "EventManager.hpp"

namespace Cement::Event {

    template<typename T>
    void EventManager::emit(T &event) {
        dispatcher.trigger<T>(event);
    }

    template<typename T>
    void EventManager::subscribe(T &listener) {
        dispatcher.sink<T>().connect<&T::receive>(listener);
    }

    template<typename T>
    void EventManager::unsubscribe(T &listener) {
        dispatcher.sink<T>().disconnect<&T::receive>(listener);
    }
}

#endif //CEMENTENGINE_EVENTMANAGER_TPP
