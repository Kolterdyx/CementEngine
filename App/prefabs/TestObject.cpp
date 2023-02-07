
#include "TestObject.hpp"
#include "Physics/Conversions.hpp"

void TestObject::init(Cement::Math::Vector2f position) {

    Cement::BodyComponent &body = addComponent<Cement::BodyComponent>();
    body.bodyDef.type = b2_dynamicBody;
    body.bodyDef.position = Cement::Conversions::vec2ToB2Vec2(position);
    body.bodyDef.angle = 0;
    body.bodyDef.linearVelocity.Set(0, 0);
    body.bodyDef.angularVelocity = 0;
    body.bodyDef.linearDamping = 0;
    body.bodyDef.angularDamping = 0;
    body.bodyDef.allowSleep = true;
    body.bodyDef.awake = true;
    body.bodyDef.fixedRotation = false;
    body.bodyDef.bullet = false;
    body.bodyDef.active = true;
    body.bodyDef.gravityScale = 1;
    body.shape = new b2PolygonShape();
    auto polygonShape = (b2PolygonShape *) body.shape;
    polygonShape->SetAsBox(1, 1);
    body.fixtureDef.shape = body.shape;
    body.fixtureDef.friction = 0.3;
    body.fixtureDef.restitution = 0.5;
    body.fixtureDef.density = 1;
    body.fixtureDef.isSensor = false;
    body.fixtureDef.filter.categoryBits = 0x0001;
    body.fixtureDef.filter.maskBits = 0xFFFF;
    body.fixtureDef.filter.groupIndex = 0;

    addComponent<Cement::RenderComponent>();
    Cement::RenderComponent &render = getComponent<Cement::RenderComponent>();
    render.shape = new sf::RectangleShape(sf::Vector2f(2, 2));
    render.shape->setOrigin(1, 1);
    render.shape->setFillColor(sf::Color::Red);
}
