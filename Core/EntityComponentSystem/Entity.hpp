
#ifndef CEMENTENGINE_ENTITY_HPP
#define CEMENTENGINE_ENTITY_HPP

#include <entt/entt.hpp>
#include <utility>
#include "globals.hpp"
#include "UUID/UUID.hpp"
#include "Scenes/Scene.hpp"

namespace Cement {

    class Entity {
    private:
        UUID _id;
        Scene *parentScene;

    protected:
        /**
         * @brief Add a component to the entity
         */
        template<typename T>
        T &addComponent() {
            return parentScene->addComponent<T>(_id);
        }

        /**
         * @brief Remove a component from the entity
         */
        template<typename T>
        void removeComponent() {
            parentScene->removeComponent<T>(_id);
        }

        /**
         * @brief Get a component from the entity
         */
        template<typename T>
        T &getComponent() {
            return parentScene->getComponent<T>(_id);
        }

        void create(UUID id, Scene *parentScene) {
            _id = id;
            this->parentScene = parentScene;
        }

        Entity() : _id(generateUUID()) {
        }

    public:

        /**
         * @brief Entity "constructor". Override this method to initialize your entity (add components, etc.)
         */
        void init() {}

        /**
         * @brief Get the UUID of the entity
         */
        [[nodiscard]] UUID getId() const;

        friend Scene;

    };
} // Cement

#endif //CEMENTENGINE_ENTITY_HPP
