
#ifndef CEMENTENGINE_ENTITY_HPP
#define CEMENTENGINE_ENTITY_HPP

#include <entt/entt.hpp>
#include <utility>
#include "../globals.hpp"
#include "../UUID/UUID.hpp"

namespace Cement {


    class Entity {
    private:
        UUID _id;


    public:

        explicit Entity(UUID id) : _id(id) {}

        virtual void init() = 0;

        [[nodiscard]] UUID getId() const;


    };
} // Cement

#endif //CEMENTENGINE_ENTITY_HPP
