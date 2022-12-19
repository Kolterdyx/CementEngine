//
// Created by kolterdyx on 14/11/22.
//

#ifndef CEMENTENGINE_ENTITY_HPP
#define CEMENTENGINE_ENTITY_HPP

#include <entt/entt.hpp>
#include <utility>
#include "../globals.hpp"
#include "../UUID/UUID.hpp"

namespace Cement {

    class Entity {
    private:
        entt::entity entityHandler;
        entt::registry &m_Registry;
        UUID _id;


    public:
        Entity() = delete;

        explicit Entity(entt::registry &m_Registry) : m_Registry(m_Registry) {
            entityHandler = m_Registry.create();
        }

        [[nodiscard]] entt::entity getEntityHandler() const;

        virtual void init() = 0;

        template<typename T>
        void addComponent();

        template<typename T>
        void removeComponent();

        template<typename T>
        bool hasComponent();

        template<typename... T>
        bool hasComponents();

        [[nodiscard]] UUID getId() const;

        void destroy() {
            m_Registry.destroy(entityHandler);
        }

    };
} // Cement

#include "Entity.tpp"

#endif //CEMENTENGINE_ENTITY_HPP
