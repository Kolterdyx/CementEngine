//
// Created by kolterdyx on 2/11/22.
//

#ifndef CEMENTENGINE_SCENEMANAGER_HPP
#define CEMENTENGINE_SCENEMANAGER_HPP

#include <unordered_map>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.hpp"
#include "UUID/UUID.hpp"


namespace Cement {

    class SceneManager {

    private:

        std::unordered_map<UUID, std::shared_ptr<Scene*>> _scenes;
        sf::RenderWindow *_window;

        UUID _currentScene{};

    public:

        explicit SceneManager(sf::RenderWindow *window);

        ~SceneManager();

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
        std::shared_ptr<Scene*> getScene(UUID id);

        /**
         * @brief Update the current scene. Calls Scene::onUpdate()
         */
        void updateCurrentScene();

        /**
         * @brief Get the current scene
         * @return The current scene
         */
        std::shared_ptr<Scene*> getCurrentScene();

        /**
         * @brief Get the render window
         */
        sf::RenderWindow *getWindow();

    };
}

#include "SceneManager.tpp"

#endif //CEMENTENGINE_SCENEMANAGER_HPP
