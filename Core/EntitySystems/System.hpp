//
// Created by kolterdyx on 10/11/22.
//

#ifndef CEMENTENGINE_SYSTEM_HPP
#define CEMENTENGINE_SYSTEM_HPP

#include "../globals.hpp"

namespace ecs {
    class System {
    public:
        std::set<Entity> entities;
    };
}


#endif //CEMENTENGINE_SYSTEM_HPP
