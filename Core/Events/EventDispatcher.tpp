
#ifndef CEMENTENGINE_EVENTDISPATCHER_TPP
#define CEMENTENGINE_EVENTDISPATCHER_TPP

#include "EventDispatcher.hpp"

namespace Cement::Event {

    template<typename E, typename... Args>
    void EventDispatcher::emit(Args ...args) {
        trigger(E{args...});
    }

    template<typename E, typename L, typename L::F>
    auto EventDispatcher::subscribe(L listener) {
        throw std::runtime_error("Not implemented");
    }

    template<typename E, typename L, typename F>
    void EventDispatcher::unsubscribe(L listener, F &callback) {
        throw std::runtime_error("Not implemented");
    }
}

#endif //CEMENTENGINE_EVENTDISPATCHER_TPP
