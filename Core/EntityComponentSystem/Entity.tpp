//
// Created by kolterdyx on 19/12/22.
//

#ifndef CEMENTENGINE_ENTITY_TPP
#define CEMENTENGINE_ENTITY_TPP

namespace Cement {
    template<typename T>
    void Entity::addComponent() {
        CEMENT_ASSERT(!hasComponent<T>(), "Entity already has given component");
        m_Registry.emplace<T>(entityHandler);
    }

    template<typename T>
    void Entity::removeComponent() {
        CEMENT_ASSERT(hasComponent<T>(), "Entity does not have given component");
        m_Registry.erase<T>(entityHandler);
    }

    template<typename T>
    bool Entity::hasComponent() {
        return m_Registry.any_of<T>(entityHandler);
    }

    template<typename... T>
    bool Entity::hasComponents() {
        return m_Registry.all_of<T...>(entityHandler);
    }
}

#endif //CEMENTENGINE_ENTITY_TPP
