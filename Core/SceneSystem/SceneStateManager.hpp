//
// Created by kolterdyx on 2/11/22.
//

#ifndef CEMENTENGINE_SCENESTATEMANAGER_HPP
#define CEMENTENGINE_SCENESTATEMANAGER_HPP

#include <unordered_map>
#include <memory>
#include "BaseScene.hpp"

namespace Cement {
    class SceneStateManager {

    private:
        std::unordered_map<uint32_t, std::shared_ptr<BaseScene>> _scenes;

        uint32_t _currentScene;

    public:

        void addScene(const std::shared_ptr<BaseScene> &scene);

        void removeScene(uint32_t id);

        void setCurrentScene(uint32_t id);

        void updateCurrentScene();

        std::shared_ptr<BaseScene> getCurrentScene();

        SceneStateManager();

    };
}

#endif //CEMENTENGINE_SCENESTATEMANAGER_HPP
