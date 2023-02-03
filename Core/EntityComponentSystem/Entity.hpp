
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

        /**
         * @brief Default constructor. Do not use this constructor. Use the Scene::createEntity() method instead.
         */
        explicit Entity(UUID id) : _id(id) {}

        /**
         * @brief Entity "constructor". Override this method to initialize your entity (add components, etc.)
         */
        virtual void init() = 0;

        /**
         * @brief Get the UUID of the entity
         */
        [[nodiscard]] UUID getId() const;


    };
} // Cement

#endif //CEMENTENGINE_ENTITY_HPP
