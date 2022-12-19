//
// Created by kolterdyx on 19/12/22.
//

#include "Entity.hpp"

namespace Cement {
    entt::entity Entity::getEntityHandler() const {
        return entityHandler;
    }

    UUID Entity::getId() const {
        return _id;
    }
}