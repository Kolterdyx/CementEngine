
#include "Scene.hpp"

namespace Cement {
    UUID Scene::getId() const {
        return _id;
    }

    Scene::Scene() : _id(generateUUID()) {
    }

    Scene::Scene(const Scene &other) : _id(other._id) {
    }

    void Scene::removeEntity(UUID entity) {
        entityRegistry.destroy(handles[entity]);
        entities.erase(entity);
        handles.erase(entity);
    }
}
