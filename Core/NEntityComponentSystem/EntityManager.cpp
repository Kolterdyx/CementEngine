//
// Created by kolterdyx on 10/11/22.
//

#include "EntityManager.hpp"

namespace ecs {

    EntityManager::EntityManager() {
        for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
            availableEntities.push(entity + 1);
        }
    }

    Entity EntityManager::createEntity() {
        CEMENT_ASSERT(livingEntityCount < MAX_ENTITIES, "Too many entities in existence.");

        Entity id = availableEntities.front();
        availableEntities.pop();
        livingEntityCount++;
        return id;
    }

    void EntityManager::destroyEntity(Entity entity) {
        CEMENT_ASSERT(entity < MAX_ENTITIES, "Entity ID out of range");
        signatures[entity].reset();
        availableEntities.push(entity);
        livingEntityCount--;
    }

    void EntityManager::setSignature(Entity entity, Signature signature) {
        CEMENT_ASSERT(entity < MAX_ENTITIES, "Entity ID out of range");

        signatures[entity] = signature;
    }

    Signature EntityManager::getSignature(Entity entity) {
        CEMENT_ASSERT(entity < MAX_ENTITIES, "Entity ID out of range");
        return signatures[entity];
    }
}