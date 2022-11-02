//
// Created by kolterdyx on 1/11/22.
//

#ifndef CEMENTENGINE_EVENTDISPATCHER_HPP
#define CEMENTENGINE_EVENTDISPATCHER_HPP


#include <functional>
#include <map>
#include <vector>
#include "BaseEvent.hpp"

class EventDispatcher {

public:
    using SlotType = std::function<void(const BaseEvent &)>;

    void subscribe(const BaseEvent::EventType &descriptor, SlotType &&slot);

    void post(const BaseEvent &event) const;

private:

    std::map<BaseEvent::EventType, std::vector<SlotType> > _observers;


};


#endif //CEMENTENGINE_EVENTDISPATCHER_HPP
