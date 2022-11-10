//
// Created by kolterdyx on 10/11/22.
//

#ifndef CEMENTENGINE_COMPONENTARRAY_HPP
#define CEMENTENGINE_COMPONENTARRAY_HPP

#include "../globals.hpp"
namespace ecs {
    class IComponentArray
    {
    public:
        virtual ~IComponentArray() = default;
        virtual void entityDestroyed(Entity entity) = 0;
    };

    template<typename T>
    class ComponentArray : public IComponentArray {
    private:
        std::array<T, MAX_ENTITIES> componentArray;

        std::unordered_map<Entity, size_t> entityToIndexMap;

        std::unordered_map<size_t, Entity> indexToEntityMap;

        size_t size{};

    public:
        void insertData(Entity entity, T component);

        void removeData(Entity entity);

        T& getData(Entity entity);

        void entityDestroyed(Entity entity) override;
    };

    template<typename T>
    void ComponentArray<T>::insertData(Entity entity, T component) {
        assert(entityToIndexMap.find(entity) == entityToIndexMap.end() && "Component added to same entity more than once");

        size_t newIndex = size;
        entityToIndexMap[entity] = newIndex;
        indexToEntityMap[newIndex] = entity;
        componentArray[newIndex] = component;
        size++;

    }

    template<typename T>
    void ComponentArray<T>::removeData(Entity entity) {
        assert(entityToIndexMap.find(entity) != entityToIndexMap.end() && "Removing non-existent component.");

        size_t indexOfRemovedEntity = entityToIndexMap[entity];
        size_t indexOfLastElement = size - 1;
        componentArray[indexOfRemovedEntity] = componentArray[indexOfLastElement];

        Entity entityOfLastElement = indexToEntityMap[indexOfLastElement];
        entityToIndexMap[entityOfLastElement] = indexOfLastElement;
        indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

        entityToIndexMap.erase(entity);
        indexToEntityMap.erase(indexOfLastElement);

        size--;
    }

    template<typename T>
    T &ComponentArray<T>::getData(Entity entity) {
        return componentArray[entity];
    }

    template<typename T>
    void ComponentArray<T>::entityDestroyed(Entity entity) {
        if (entityToIndexMap.find(entity) != entityToIndexMap.end())
        {
            removeData(entity);
        }
    }
}

#endif //CEMENTENGINE_COMPONENTARRAY_HPP
