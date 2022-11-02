//
// Created by kolterdyx on 1/11/22.
//

#include <cstdio>
#include <iostream>
#include "EventDispatcher.hpp"

void EventDispatcher::subscribe(const BaseEvent::EventType &descriptor, EventDispatcher::SlotType &&slot) {
    _observers[descriptor].push_back(slot);
}

void EventDispatcher::post(const BaseEvent &event) const {
    auto type = event.type();

    // Ignore events for which we do not have an observer (yet).
    if (_observers.find(type) == _observers.end())
        return;

    auto &&observers = _observers.at(type);

    for (auto &&observer: observers)
        observer(event);

}
