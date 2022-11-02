#include "../Core/SceneSystem/SceneSystem.hpp"
#include "catch2/catch_test_macros.hpp"


TEST_CASE("Test the Scene System", "[Scene System]") {

    class TestScene : public BaseScene {
    public:
        TestScene(unsigned int i) : BaseScene(i) {}

        void onCreate() override {
        }

        void onDestroy() override {
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

}
