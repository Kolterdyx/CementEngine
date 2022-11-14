//
// Created by kolterdyx on 10/11/22.
//

#include "EntityComponentSystem.hpp"

namespace ecs {
    EntityComponentSystem::EntityComponentSystem() {
        componentManager = std::make_unique<ComponentManager>();
        entityManager = std::make_unique<EntityManager>();
        systemManager = std::make_unique<SystemManager>();
    }

    void EntityComponentSystem::destroyEntity(Entity entity) {
        entityManager->destroyEntity(entity);

        componentManager->entityDestroyed(entity);

        systemManager->entityDestroyed(entity);
    }

    Entity EntityComponentSystem::createEntity() {
        return entityManager->createEntity();
    }
} // ecs