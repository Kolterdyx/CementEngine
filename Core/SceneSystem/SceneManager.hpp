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

        void addScene(const std::shared_ptr<Scene> &scene);

        void removeScene(UUID id);

        void setCurrentScene(UUID id);

        std::shared_ptr<Scene> getScene(UUID id);

        void updateCurrentScene();

        std::shared_ptr<Scene> getCurrentScene();

    };
}

#endif //CEMENTENGINE_SCENEMANAGER_HPP
