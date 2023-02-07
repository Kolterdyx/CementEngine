//
// Created by kolterdyx on 7/02/23.
//

#include "MyApp.hpp"
#include "scenes/PhysicsTestScene.hpp"

void MyApp::onCreate() {
    Application::onCreate();

    Cement::UUID physicsScene = sceneManager.createScene<PhysicsTestScene>();
    sceneManager.setCurrentScene(physicsScene);

}

MyApp::MyApp(const std::string &title, unsigned int width, unsigned int height) : Application(title, width, height) {

}
