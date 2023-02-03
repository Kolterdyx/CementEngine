
#include "SceneManager.hpp"

namespace Cement {

    void SceneManager::removeScene(UUID id) {
        if (_scenes.find(id) != _scenes.end()) {
            if (_currentScene == id) {
                _currentScene = nilUUID();
            }
            _scenes[id]->onDestroy();
            _scenes.erase(id);
        }

    }

    void SceneManager::setCurrentScene(UUID id) {
        if (_scenes.find(id) != _scenes.end())
            _currentScene = id;
        else
            throw std::invalid_argument("Scene id cannot be 0");
    }

    std::shared_ptr<Scene> SceneManager::getCurrentScene() {
        return getScene(_currentScene);
    }

    void SceneManager::updateCurrentScene() {
        if (_scenes.find(_currentScene) != _scenes.end()) {
            _scenes[_currentScene]->update();
        }
    }

    std::shared_ptr<Scene> SceneManager::getScene(UUID id) {
        if (_scenes.find(id) != _scenes.end()) {
            return _scenes[id];
        }
        return nullptr;
    }

    SceneManager::SceneManager() {
        _currentScene = nilUUID();
    }
}
