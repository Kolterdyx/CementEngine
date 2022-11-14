//
// Created by kolterdyx on 10/11/22.
//

#ifndef CEMENTENGINE_IENTITYSYSTEM_HPP
#define CEMENTENGINE_IENTITYSYSTEM_HPP

#include "../globals.hpp"

namespace Cement::ecs {
    class IEntitySystem {
    public:
        std::set<Entity> entities;
    };
}


#endif //CEMENTENGINE_IENTITYSYSTEM_HPP
