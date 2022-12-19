//
// Created by kolterdyx on 14/11/22.
//

#ifndef CEMENTENGINE_ENTITY_HPP
#define CEMENTENGINE_ENTITY_HPP

#include <entt/entt.hpp>
#include <utility>
#include "../globals.hpp"

namespace Cement {

    class Entity {
    private:
        entt::entity entityHandler;
        entt::registry &m_Registry;

    public:
        Entity() = delete;

        explicit Entity(entt::registry &m_Registry) : m_Registry(m_Registry) {
            entityHandler = m_Registry.create();
        }

        entt::entity getEntityHandler() const;

        virtual void init() = 0;

        template<typename T>
        void addComponent();

        template<typename T>
        void removeComponent();

        template<typename T>
        bool hasComponent();

        template<typename... T>
        bool hasComponents();

        void destroy() {
            m_Registry.destroy(entityHandler);
        }

    };

    entt::entity Entity::getEntityHandler() const {
        return entityHandler;
    }

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

} // Cement

#endif //CEMENTENGINE_ENTITY_HPP
