#include "../Core/SceneSystem/SceneSystem.hpp"
#include "catch2/catch_test_macros.hpp"


TEST_CASE("Test the Scene System", "[Scene System]") {

    class TestScene : public BaseScene {
    public:
        int n;

        TestScene(unsigned int i) : BaseScene(i) {
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

    SECTION("Test basic scene creation") {
        SceneStateManager manager;
        std::shared_ptr<BaseScene> scene = std::make_shared<TestScene>(1);
        manager.addScene(scene);
        std::shared_ptr<BaseScene> cScene = manager.getCurrentScene();
        REQUIRE(cScene != nullptr);
        REQUIRE(cScene->getId() == 1);
    }

    SECTION("Test scene removal") {
        SceneStateManager manager;
        std::shared_ptr<BaseScene> scene = std::make_shared<TestScene>(1);
        manager.addScene(scene);
        std::shared_ptr<BaseScene> cScene = manager.getCurrentScene();
        REQUIRE(cScene != nullptr);
        REQUIRE(cScene->getId() == 1);
        manager.removeScene(1);
        cScene = manager.getCurrentScene();
        REQUIRE(cScene == nullptr);
    }

    SECTION("Test scene switching") {
        SceneStateManager manager;
        std::shared_ptr<BaseScene> scene1 = std::make_shared<TestScene>(1);
        std::shared_ptr<BaseScene> scene2 = std::make_shared<TestScene>(2);
        manager.addScene(scene1);
        manager.addScene(scene2);
        std::shared_ptr<BaseScene> cScene = manager.getCurrentScene();
        REQUIRE(cScene != nullptr);
        REQUIRE(cScene->getId() == 1);
        manager.setCurrentScene(2);
        cScene = manager.getCurrentScene();
        REQUIRE(cScene != nullptr);
        REQUIRE(cScene->getId() == 2);
    }

    SECTION("Test scene update") {
        SceneStateManager manager;
        std::shared_ptr<BaseScene> scene = std::make_shared<TestScene>(1);
        manager.addScene(scene);
        std::shared_ptr<BaseScene> cScene = manager.getCurrentScene();
        REQUIRE(cScene != nullptr);
        REQUIRE(cScene->getId() == 1);
        REQUIRE(((TestScene *) cScene.get())->n == 0);
        manager.updateCurrentScene();
        REQUIRE(((TestScene *) cScene.get())->n == 1);
        manager.updateCurrentScene();
        REQUIRE(((TestScene *) cScene.get())->n == 2);
    }

    SECTION("Test multiple scene update") {
        SceneStateManager manager;
        std::shared_ptr<BaseScene> scene1 = std::make_shared<TestScene>(1);
        std::shared_ptr<BaseScene> scene2 = std::make_shared<TestScene>(2);
        manager.addScene(scene1);
        manager.addScene(scene2);
        std::shared_ptr<BaseScene> cScene = manager.getCurrentScene();
        REQUIRE(cScene != nullptr);
        REQUIRE(cScene->getId() == 1);
        REQUIRE(((TestScene *) cScene.get())->n == 0);
        manager.updateCurrentScene();
        REQUIRE(((TestScene *) cScene.get())->n == 1);
        manager.updateCurrentScene();
        REQUIRE(((TestScene *) cScene.get())->n == 2);
        manager.setCurrentScene(2);
        cScene = manager.getCurrentScene();
        REQUIRE(cScene != nullptr);
        REQUIRE(cScene->getId() == 2);
        REQUIRE(((TestScene *) cScene.get())->n == 0);
        manager.updateCurrentScene();
        REQUIRE(((TestScene *) cScene.get())->n == 1);
        manager.updateCurrentScene();
        REQUIRE(((TestScene *) cScene.get())->n == 2);
    }
}