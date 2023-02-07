
#ifndef CEMENTENGINE_EVENTDISPATCHER_HPP
#define CEMENTENGINE_EVENTDISPATCHER_HPP

#include <entt/entt.hpp>
#include <entt/signal/sigh.hpp>

namespace Cement {

    class EventDispatcher : public entt::dispatcher {
    public:

        /**
         * @brief Emit an event
         * @tparam E The type of the event
         * @param event The event to emit. Can be any struct/class that you define.
         */
        template<typename E, typename... Args>
        void emit(Args ...args);

        /**
         * @brief Subscribe a listener to an event
         * @tparam T The type of the event
         * @param listener The listener to subscribe
         */
        template<typename E, typename L, typename L::F>
        auto subscribe(L listener);

        /**
         * @brief Unsubscribe a listener from an event
         * @tparam T The type of the event
         * @param listener The listener to unsubscribe
         */
        template<typename E, typename L, typename F>
        static void unsubscribe(L listener, F &callback);

    };
}

#include "EventDispatcher.tpp"

#endif //CEMENTENGINE_EVENTDISPATCHER_HPP
