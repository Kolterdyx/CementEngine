//
// Created by kolterdyx on 1/11/22.
//

#ifndef CEMENTENGINE_BASEEVENT_HPP
#define CEMENTENGINE_BASEEVENT_HPP


class BaseEvent {
public:

    using EventType = const char *;

    virtual EventType type() const = 0;
};


#endif //CEMENTENGINE_BASEEVENT_HPP
