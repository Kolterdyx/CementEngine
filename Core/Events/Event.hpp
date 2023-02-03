//
// Created by kolterdyx on 19/12/22.
//

#ifndef CEMENTENGINE_EVENT_HPP
#define CEMENTENGINE_EVENT_HPP

namespace Cement::Event {

    /**
     * @brief The base class for all events
     */
    class Event {
    public:
        virtual ~Event() = default;
    };
}


#endif //CEMENTENGINE_EVENT_HPP
