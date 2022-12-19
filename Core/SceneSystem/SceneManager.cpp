
#include "SceneManager.hpp"

namespace Cement {


    void SceneManager::addScene(const std::shared_ptr<Scene> &scene) {
        if (_currentScene.is_nil()) {
            _currentScene = scene->getId();
        }
        _scenes[scene->getId()] = scene;
    }

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
        if (_scenes.find(_currentScene) != _scenes.end()) {
            return _scenes[_currentScene];
        }
        return nullptr;
    }

    void SceneManager::updateCurrentScene() {
        if (_scenes.find(_currentScene) != _scenes.end()) {
            _scenes[_currentScene]->update();
        }
    }

    std::shared_ptr<Scene> SceneManager::getScene(UUID id) {
        return _scenes[id];
    }
}
