//
// Created by kolterdyx on 7/02/23.
//


#include "PhysicsTestScene.hpp"



void PhysicsTestScene::onCreate() {
    Scene::onCreate();

    int32 flags = 0;
    flags += b2Draw::e_shapeBit;
    flags += b2Draw::e_jointBit;
    flags += b2Draw::e_aabbBit;
    flags += b2Draw::e_pairBit;
    flags += b2Draw::e_centerOfMassBit;
    getDebugDraw()->SetFlags(flags);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(2.0f, 2.0f);
    b2Body *body = getWorld()->CreateBody(&bodyDef);
    getWorld()->SetGravity(b2Vec2(0.0f, 10.0f));

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    body->CreateFixture(&fixtureDef);
    bodies.push_back(body);

}

void PhysicsTestScene::onUpdate(float delta) {
    getWorld()->Step(delta, 6, 2);
    getWorld()->DrawDebugData();
}

void PhysicsTestScene::onDestroy() {
}
