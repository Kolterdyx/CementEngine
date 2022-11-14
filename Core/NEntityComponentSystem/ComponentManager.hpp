//
// Created by kolterdyx on 10/11/22.
//

#ifndef CEMENTENGINE_COMPONENTMANAGER_HPP
#define CEMENTENGINE_COMPONENTMANAGER_HPP

#include "../globals.hpp"
#include "ComponentArray.hpp"

namespace Cement::ecs {
    class ComponentManager {

    private:
        std::unordered_map<const char *, ComponentType> componentTypes{};

        std::unordered_map<const char *, std::shared_ptr<IComponentArray>> componentArrays{};

        ComponentType nextComponentType{};

        template<typename T>
        std::shared_ptr<ComponentArray<T>> getComponentArray() {
            const char *typeName = typeid(T).name();

            CEMENT_ASSERT(componentTypes.find(typeName) != componentTypes.end(), "Component not registered before use");

            return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeName]);
        }

    public:
        template<typename T>
        void registerComponent();

        template<typename T>
        ComponentType getComponentType();

        template<typename T>
        void addComponent(Entity entity, T component);

        template<typename T>
        void removeComponent(Entity entity);

        template<typename T>
        T &getComponent(Entity entity);

        void entityDestroyed(Entity entity) {
            for (auto const& pair : componentArrays)
            {
                auto const& component = pair.second;

                component->entityDestroyed(entity);
            }
        };
    };

    template<typename T>
    void ComponentManager::registerComponent() {
        const char *typeName = typeid(T).name();

        CEMENT_ASSERT(componentTypes.find(typeName) == componentTypes.end(), "Registering component type more than once");

        componentTypes.insert({typeName, nextComponentType});

        componentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});

        nextComponentType++;
    }

    template<typename T>
    ComponentType ComponentManager::getComponentType() {
        const char *typeName = typeid(T).name();

        CEMENT_ASSERT(componentTypes.find(typeName) != componentTypes.end(), "Component not registered before use");

        return componentTypes[typeName];
    }

    template<typename T>
    void ComponentManager::addComponent(Entity entity, T component) {
        getComponentArray<T>()->insertData(entity, component);
    }

    template<typename T>
    void ComponentManager::removeComponent(Entity entity) {
        getComponentArray<T>()->removeData(entity);
    }

    template<typename T>
    T &ComponentManager::getComponent(Entity entity) {
        return getComponentArray<T>()->getData(entity);
    }
}

#endif //CEMENTENGINE_COMPONENTMANAGER_HPP
