
#include "Scene.hpp"

namespace Cement {
    UUID Scene::getId() const {
        return _id;
    }

    Scene::Scene() : _id(generateUUID()), world(Conversions::vec2ToB2Vec2(Vector2f(0, 9.8f * 32))) {
    }

    Scene::Scene(const Scene &other) : _id(other._id), world(Conversions::vec2ToB2Vec2(Vector2f(0, 9.8f * 32))) {
    }

    void Scene::removeEntity(UUID entity) {
        entityRegistry.destroy(handles[entity]);
        entities.erase(entity);
        handles.erase(entity);
    }
}
