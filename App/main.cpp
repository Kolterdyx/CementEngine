#include "MyApp.hpp"

int main() {

    MyApp app("Test", 800, 600);

    app.onCreate();

    app.run();

//    b2World world(b2Vec2(0.0f, 10.0f));
//
//    sf::RenderWindow window;
//
//    window.create(sf::VideoMode(800, 600), "Test");
//    auto *debugDraw = new Box2DDebugDraw(&window);
//
//    int32 flags = 0;
//    flags += b2Draw::e_shapeBit;
//    flags += b2Draw::e_jointBit;
//    flags += b2Draw::e_aabbBit;
//    flags += b2Draw::e_pairBit;
//    flags += b2Draw::e_centerOfMassBit;
//
//    debugDraw->SetFlags(flags);
//
//    world.SetDebugDraw(debugDraw);
//    b2Body *body;
//    b2BodyDef bodyDef;
//    bodyDef.type = b2_dynamicBody;
//    bodyDef.position.Set(10.0f, 10.0f);
//    body = world.CreateBody(&bodyDef);
//
//    b2PolygonShape dynamicBox;
//    dynamicBox.SetAsBox(1.0f, 1.0f);
//
//    b2FixtureDef fixtureDef;
//    fixtureDef.shape = &dynamicBox;
//    fixtureDef.density = 1.0f;
//    fixtureDef.friction = 0.3f;
//
//    body->CreateFixture(&fixtureDef);
//
//    auto start = std::chrono::high_resolution_clock::now();
//    while (window.isOpen()) {
//        window.clear();
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//
//        auto end = std::chrono::high_resolution_clock::now();
//        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//        start = end;
//        world.Step(duration.count() / 1000000.0f, 6, 2);
//
//        window.setTitle("Test: " + std::to_string((int) std::roundf(1. / (duration.count() / 1000000.0f))));
//
//        world.DrawDebugData();
//        window.display();
//    }


    return 0;
}
