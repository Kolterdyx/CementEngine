//
// Created by kolterdyx on 2/11/22.
//
#include "Scene.hpp"

namespace Cement {
    uint32_t Scene::getId() const {
        return _id;
    }

    Scene::Scene(uint32_t id) {
        if (id == 0) {
            throw std::invalid_argument("Scene id cannot be 0");
        }
        this->_id = id;
    }

    Scene::Scene() {
        _id = 0;
    }

    void Scene::removeEntity(entt::entity entity) {
        for (auto it = entities.begin(); it != entities.end(); ++it) {
            if (it->getEntityHandler() == entity) {
                entities.erase(it);
                return;
            }
        }
        entityRegistry.destroy(entity);
    }
}
