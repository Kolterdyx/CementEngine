//
// Created by kolterdyx on 14/11/22.
//

#ifndef CEMENTENGINE_ENTITYCOMPONENSYSTEM_HPP
#define CEMENTENGINE_ENTITYCOMPONENSYSTEM_HPP

#include <entt/entt.hpp>

namespace Cement {

    class EntityComponenSystem {

        void test() {
            entt::registry m_Registry;

            struct pos {};
            struct vel {};

            entt::entity e = m_Registry.create();


        }
    };

} // Cement

#endif //CEMENTENGINE_ENTITYCOMPONENSYSTEM_HPP
