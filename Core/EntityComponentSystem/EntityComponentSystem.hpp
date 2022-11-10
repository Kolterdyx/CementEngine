//
// Created by kolterdyx on 10/11/22.
//

#ifndef CEMENTENGINE_ENTITYCOMPONENTSYSTEM_HPP
#define CEMENTENGINE_ENTITYCOMPONENTSYSTEM_HPP

#include "../globals.hpp"
#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"

namespace ecs {

    class EntityComponentSystem {
    private:
        std::unique_ptr<ComponentManager> componentManager;
        std::unique_ptr<EntityManager> entityManager;
        std::unique_ptr<SystemManager> systemManager;


    public:
        EntityComponentSystem();

        Entity createEntity();

        void destroyEntity(Entity entity);

        template<typename T>
        void registerComponent();

        template<typename T>
        void addComponent(Entity entity, T component);

        template<typename T>
        void removeComponent(Entity entity);

        template<typename T>
        T& getComponent(Entity entity);

        template<typename T>
        ComponentType getComponentType();

        template<typename T>
        std::shared_ptr<T> registerSystem();

        template<typename T>
        void setSystemSignature(Signature signature);

    };

    template<typename T>
    void EntityComponentSystem::registerComponent() {
        componentManager->registerComponent<T>();
    }

    template<typename T>
    void EntityComponentSystem::addComponent(Entity entity, T component) {
        componentManager->addComponent<T>(entity, component);

        auto signature = entityManager->getSignature(entity);
        signature.set(componentManager->getComponentType<T>(), true);
        entityManager->setSignature(entity, signature);

        systemManager->entitySignatureChanged(entity, signature);
    }

    template<typename T>
    void EntityComponentSystem::removeComponent(Entity entity) {
        componentManager->removeComponent<T>(entity);

        auto signature = entityManager->getSignature(entity);
        signature.set(componentManager->getComponentType<T>(), false);
        entityManager->setSignature(entity, signature);

        systemManager->entitySignatureChanged(entity, signature);
    }


    template<typename T>
    ComponentType EntityComponentSystem::getComponentType() {
        return componentManager->getComponentType<T>();
    }

    template<typename T>
    T& EntityComponentSystem::getComponent(Entity entity) {
        return componentManager->getComponent<T>(entity);
    }

    template<typename T>
    std::shared_ptr<T> EntityComponentSystem::registerSystem() {
        return systemManager->registerSystem<T>();
    }

    template<typename T>
    void EntityComponentSystem::setSystemSignature(Signature signature) {
        systemManager->setSignature<T>(signature);
    }
} // ecs

#endif //CEMENTENGINE_ENTITYCOMPONENTSYSTEM_HPP
