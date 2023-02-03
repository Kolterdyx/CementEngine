//
// Created by kolterdyx on 2/11/22.
//

#include "../Core/SceneSystem/SceneManager.hpp"

using namespace Cement;

class TestScene : public Scene {
public:
    int n;

    TestScene(unsigned int i) : Scene() {
        n = 0;
    }

    void onCreate() override {
    }

    void onDestroy() override {
    }

    void update() override {
        n++;
    }
};

int main() {

    SceneManager manager = SceneManager();

    CEMENT_ASSERT(manager.getCurrentScene() == nullptr, "Current scene is not null");

    UUID scene = manager.createScene<TestScene>(1);
    std::shared_ptr<Scene> cScene = manager.getCurrentScene();
    CEMENT_ASSERT(cScene.get() != nullptr, "Current scene is null");
    CEMENT_ASSERT(cScene->getId().is_nil() == false, "Current scene id is nil");
    CEMENT_ASSERT(cScene->getId() == scene, "Current scene id is not equal to scene id");

    std::cout << "Test 1 passed: " << cScene->getId()  << std::endl;


    return 0;
}
