//
// Created by kolterdyx on 2/11/22.
//

#ifndef CEMENTENGINE_SCENESTATEMANAGER_HPP
#define CEMENTENGINE_SCENESTATEMANAGER_HPP

#include <unordered_map>
#include <memory>
#include "Scene.hpp"
#include "../UUID/UUID.hpp"

namespace Cement {
    class SceneStateManager {

    private:
        std::unordered_map<UUID, std::shared_ptr<Scene>> _scenes;

        UUID _currentScene;

    public:

        void addScene(const std::shared_ptr<Scene> &scene);

        void removeScene(UUID id);

        void setCurrentScene(UUID id);

        void updateCurrentScene();

        std::shared_ptr<Scene> getCurrentScene();

        SceneStateManager();

    };
}

#endif //CEMENTENGINE_SCENESTATEMANAGER_HPP
