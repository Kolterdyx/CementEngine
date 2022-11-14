//
// Created by kolterdyx on 1/11/22.
//

#ifndef CEMENTENGINE_BASEEVENT_HPP
#define CEMENTENGINE_BASEEVENT_HPP

namespace Cement {
    class BaseEvent {
    public:

        using EventType = const char *;

        virtual EventType getType() const = 0;
    };
}

#endif //CEMENTENGINE_BASEEVENT_HPP
