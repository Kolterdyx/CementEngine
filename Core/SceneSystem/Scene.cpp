
#include "Scene.hpp"

namespace Cement {
    UUID Scene::getId() const {
        return _id;
    }

    Scene::Scene() : _id(generateUUID()) {
    }

    void Scene::removeEntity(UUID entity) {
        entityRegistry.destroy(handles[entity]);
        entities.erase(entity);
        handles.erase(entity);
    }
}
