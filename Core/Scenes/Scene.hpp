
#ifndef CEMENTENGINE_SCENE_HPP
#define CEMENTENGINE_SCENE_HPP

#include <stdexcept>
#include <vector>
#include "../EntityComponentSystem/Entity.hpp"
#include "../UUID/UUID.hpp"
#include "box2d/box2d.h"
#include "../Physics/Conversions.hpp"

namespace Cement {


    class Scene {

    private:
        UUID _id;
        std::unordered_map<UUID, std::unique_ptr<Entity>> entities;
        std::unordered_map<UUID, entt::entity> handles;
        entt::registry entityRegistry;

		b2World world;

    public:

        /**
         * @brief onCreate() is called when the scene is created. Override this method to initialize your scene.
         */
        virtual void onCreate() {};

        /**
         * @brief onDestroy() is called when the scene is destroyed. Override this method to initialize your scene.
         */
        virtual void onDestroy() {};

        /**
         * @brief update() is called by the scene manager every frame. Override this method to update your scene.
         */
        virtual void update() {};

        /**
         * @brief load() is called by the scene manager when the scene is loaded. Override this method to load your scene.
         */
        virtual void load() {};

        /**
         * @brief Get the UUID of the scene
         * @return The UUID of the scene
         */
        [[nodiscard]] UUID getId() const;

        Scene();

        Scene(const Scene &other);

        /**
         * @brief Create an entity in the scene
         * @tparam T The class of the entity to create (must be a subclass of Entity)
         * @param args The arguments to pass to the entity constructor
         * @return The UUID of the created entity
         */
        template<typename T, typename... Args>
        UUID createEntity(Args... args);

        /**
         * @brief Remove an entity from the scene
         * @param id The UUID of the entity to remove
         */
        void removeEntity(UUID entity);

        // API for entt::registry

        /**
         * @brief See if an entity has any components from a given set of components.
         * @tparam T The types of the components to check for
         * @param entity The UUID of the entity to check
         * @return True if the entity has any of the given components, false otherwise
         */
        template<typename... T>
        bool hasAnyComponents(UUID entity);

        /**
         * @brief See if an entity has all components from a given set of components.
         * @tparam T The types of the components to check for
         * @param entity The UUID of the entity to check
         * @return True if the entity has all of the given components, false otherwise
         */
        template<typename... T>
        bool hasAllComponents(UUID entity);

        /**
         * @brief Add a component to an entity
         * @tparam T The type of the component to add
         * @param entity The UUID of the entity to add the component to
         * @param args The arguments to pass to the component constructor
         * @return A reference to the added component
         */
        template<typename T>
        T &addComponent(UUID entity);

        /**
         * @brief Remove a component from an entity
         * @tparam T The type of the component to remove
         * @param entity The UUID of the entity to remove the component from
         */
        template<typename T>
        void removeComponent(UUID entity);

        /**
         * @brief Get a component from an entity
         * @tparam T The type of the component to get
         * @param entity The UUID of the entity to get the component from
         * @return A reference to the component
         */
        template<typename T>
        T &getComponent(UUID entity);

        /**
         * @brief See if an entity has a given component
         * @tparam T The type of the component to check for
         * @param entity The UUID of the entity to get the component from
         * @return True if the entity has the given component, false otherwise
         */
        template<typename T>
        bool hasComponent(UUID entity);

        /**
         * @brief Get a view of all entities with a given set of components
         * @tparam T The types of the components to check for
         * @return A view of all entities with the given components
         */
        template<typename... T>
        auto view();
    };
}

#include "Scene.tpp"

#endif //CEMENTENGINE_SCENE_HPP
