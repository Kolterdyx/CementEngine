//
// Created by kolterdyx on 2/11/22.
//
#include "SceneStateManager.hpp"

namespace Cement {
    void SceneStateManager::addScene(const std::shared_ptr<Scene> &scene) {
        if (_scenes.empty()) {
            _currentScene = scene->getId();
        }
        _scenes[scene->getId()] = scene;
    }

    void SceneStateManager::removeScene(UUID id) {
        if (_scenes.find(id) != _scenes.end()) {
            if (_currentScene == id) {
                _currentScene = 0;
            }
            _scenes[id]->onDestroy();
            _scenes.erase(id);
        }

    }

    void SceneStateManager::setCurrentScene(UUID id) {
        if (id > 0)
            _currentScene = id;
        else
            throw std::invalid_argument("Scene id cannot be 0");
    }

    std::shared_ptr<Scene> SceneStateManager::getCurrentScene() {
        if (_scenes.find(_currentScene) != _scenes.end()) {
            return _scenes[_currentScene];
        }
        return nullptr;
    }

    SceneStateManager::SceneStateManager() {
        _currentScene = 0;
    }

    void SceneStateManager::updateCurrentScene() {
        if (_scenes.find(_currentScene) != _scenes.end()) {
            _scenes[_currentScene]->update();
        }
    }
}
