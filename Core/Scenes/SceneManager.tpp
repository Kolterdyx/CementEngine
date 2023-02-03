//
// Created by kolterdyx on 19/12/22.
//

#ifndef CEMENTENGINE_SCENEMANAGER_TPP
#define CEMENTENGINE_SCENEMANAGER_TPP

#include <iostream>

namespace Cement {
    template<typename T, typename... Args>
    UUID SceneManager::createScene(Args... args) {
        T scene(args...);
        CEMENT_ASSERT(dynamic_cast<Scene *>(&scene) != nullptr, "Class passed is not a subclass of Scene");
        _scenes[scene.getId()] = std::make_shared<T>(scene);
        if (_currentScene.is_nil()) {
            _currentScene = scene.getId();
        }
        return scene.getId();
    }
}

#endif //CEMENTENGINE_SCENEMANAGER_TPP
