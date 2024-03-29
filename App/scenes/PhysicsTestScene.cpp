//
// Created by kolterdyx on 7/02/23.
//


#include "PhysicsTestScene.hpp"
#include "../prefabs/TestObject.hpp"


void PhysicsTestScene::onCreate() {

    createEntity<TestObject>(Vector2f(400, 300));
	getWorld()->SetGravity(b2Vec2(0, 9.8));
    Scene::onCreate();
}

void PhysicsTestScene::onUpdate(float delta) {
	Scene::onUpdate(delta);
    getWorld()->Step(delta, 6, 2);
    getWorld()->DrawDebugData();
    Cement::sleep(1);
    getWindow()->setTitle("Test: " + std::to_string((int) std::roundf(1. / delta)));
}

void PhysicsTestScene::onDestroy() {
}
