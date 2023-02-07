
#include "Scene.hpp"

namespace Cement {
    UUID Scene::getId() const {
        return _id;
    }

    Scene::Scene(Scene &other) : _id(other._id), world(other.world), window(other.window) {
        entityRegistry.swap(other.entityRegistry);
        entities.swap(other.entities);
        handles.swap(other.handles);
    }

    void Scene::removeEntity(UUID entity) {
        entityRegistry.destroy(handles[entity]);
        entities.erase(entity);
        handles.erase(entity);
    }

    b2World *Scene::getWorld() {
        return world;
    }

    Scene::Scene() : world(new b2World(Conversions::vec2ToB2Vec2(Vector2f(0, 0)))) {
        _id = generateUUID();
    }

    sf::RenderWindow *Scene::getWindow() {
        return window;
    }

    void Scene::setWindow(sf::RenderWindow *window) {
       this->window = window;
    }

    Scene::~Scene() {
        delete _debugDraw;
        delete world;
    }

    Box2DDebugDraw *Scene::getDebugDraw() {
        return _debugDraw;
    }

    void Scene::onCreate() {
        _debugDraw = new Box2DDebugDraw(window);

        getWorld()->SetDebugDraw(_debugDraw);

    }
}
