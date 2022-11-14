//
// Created by kolterdyx on 14/11/22.
//

#ifndef CEMENTENGINE_ENTITY_HPP
#define CEMENTENGINE_ENTITY_HPP

#include <entt/entt.hpp>

namespace Cement {

    class Entity {
    private:
        entt::entity entityHandler;

        std::weak_ref<entt::registry> m_Registry;
    };

} // Cement

#endif //CEMENTENGINE_ENTITY_HPP
