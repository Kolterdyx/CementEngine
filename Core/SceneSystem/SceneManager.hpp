//
// Created by kolterdyx on 2/11/22.
//

#ifndef CEMENTENGINE_SCENEMANAGER_HPP
#define CEMENTENGINE_SCENEMANAGER_HPP

#include <unordered_map>
#include <memory>
#include "Scene.hpp"
#include "../UUID/UUID.hpp"


namespace Cement {

    class SceneManager {

    private:
        std::unordered_map<UUID, std::shared_ptr<Scene>> _scenes;

        UUID _currentScene;

    public:

        SceneManager();

        /**
         * @brief Add a scene to the scene manager
         * @tparam T The Class of the scene to add (must be a subclass of Scene)
         * @param args The arguments to pass to the scene constructor
         */
        template<typename T, typename... Args>
        UUID createScene(Args... args);

        /**
         * @brief Remove a scene from the scene manager
         * @param id The UUID of the scene to remove
         */
        void removeScene(UUID id);

        /**
         * @brief Set the current scene
         * @param id The UUID of the scene to set as current
         */
        void setCurrentScene(UUID id);

        /**
         * @brief Get a scene from the scene manager
         * @param id The UUID of the scene to get
         * @return The scene
         */
        std::shared_ptr<Scene> getScene(UUID id);

        /**
         * @brief Update the current scene. Calls Scene::update()
         */
        void updateCurrentScene();

        /**
         * @brief Get the current scene
         * @return The current scene
         */
        std::shared_ptr<Scene> getCurrentScene();

    };
}

#include "SceneManager.tpp"

#endif //CEMENTENGINE_SCENEMANAGER_HPP
