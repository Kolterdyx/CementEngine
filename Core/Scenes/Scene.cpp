
#include "Scene.hpp"
#include "Components.hpp"

namespace Cement {
    UUID Scene::getId() const {
        return _id;
    }

    Scene::Scene(Scene &other) : _id(other._id), world(other.world), window(other.window) {
        entityRegistry.swap(other.entityRegistry);
//        entities.swap(other.entities);
        handles.swap(other.handles);
    }

    void Scene::removeEntity(UUID entity) {
        entityRegistry.destroy(handles[entity]);
//        entities.erase(entity);
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
        int32 flags = 0;
        flags += b2Draw::e_shapeBit;
        flags += b2Draw::e_jointBit;
        flags += b2Draw::e_aabbBit;
        flags += b2Draw::e_pairBit;
        flags += b2Draw::e_centerOfMassBit;
        _debugDraw->SetFlags(flags);
        getWorld()->SetDebugDraw(_debugDraw);

        auto bodyCompEntities = view<BodyComponent>();
        for (auto entity : bodyCompEntities) {
            auto &bodyComp = getComponent<BodyComponent>(uuids[entity]);
            bodyComp.body = getWorld()->CreateBody(&bodyComp.bodyDef);
            bodyComp.body->CreateFixture(&bodyComp.fixtureDef);
        }
    }
}
