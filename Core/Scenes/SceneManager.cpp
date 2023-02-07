
#include "SceneManager.hpp"

namespace Cement {

    void SceneManager::removeScene(UUID id) {
        if (_scenes.find(id) != _scenes.end()) {
            if (_currentScene == id) {
                _currentScene = nilUUID();
            }
            (*_scenes[id].get())->onDestroy();
            _scenes[id].reset();
            _scenes.erase(id);
        }

    }

    void SceneManager::setCurrentScene(UUID id) {
        if (_scenes.find(id) != _scenes.end())
            _currentScene = id;
        else
            throw std::invalid_argument("Scene id cannot be 0");
    }

    std::shared_ptr<Scene*> SceneManager::getCurrentScene() {
        return getScene(_currentScene);
    }

    void SceneManager::updateCurrentScene() {
        static sf::Clock clock;
        sf::Time elapsed = clock.restart();

        if (_scenes.find(_currentScene) != _scenes.end()) {
            (*_scenes[_currentScene].get())->onUpdate(elapsed.asSeconds());
        }
    }

    std::shared_ptr<Scene*> SceneManager::getScene(UUID id) {
        if (_scenes.find(id) != _scenes.end()) {
            return _scenes[id];
        }
        return nullptr;
    }

    SceneManager::SceneManager(sf::RenderWindow *window) : _window(window) {
        this->_currentScene = nilUUID();
    }

    sf::RenderWindow *SceneManager::getWindow() {
        return _window;
    }

    SceneManager::~SceneManager() {
        for (auto &scene : _scenes) {
            removeScene(scene.first);
        }
    }
}
