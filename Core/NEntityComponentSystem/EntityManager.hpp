//
// Created by kolterdyx on 10/11/22.
//

#ifndef CEMENTENGINE_ENTITYMANAGER_HPP
#define CEMENTENGINE_ENTITYMANAGER_HPP


#include <queue>
#include <array>
#include "../globals.hpp"

namespace Cement::ecs {

    class EntityManager {
    private:
        // Queue of unused entity IDs
        std::queue<Entity> availableEntities{};

        // Array of signatures where the index corresponds to the entity ID
        std::array<Signature, MAX_ENTITIES> signatures{};

        // Total living entities - used to keep limits on how many exist
        uint32_t livingEntityCount{};

    public:
        EntityManager();

        Entity createEntity();

        void destroyEntity(Entity entity);

        void setSignature(Entity entity, Signature signature);

        Signature getSignature(Entity entity);
    };
}

#endif //CEMENTENGINE_ENTITYMANAGER_HPP
