
#include "catch2/catch_test_macros.hpp"
#include "../Core/Scenes/Scene.hpp"
#include "../Core/Scenes/SceneManager.hpp"

using namespace Cement;

TEST_CASE("Test the Scene System", "[Scene System]") {

    class TestScene : public Scene {
    public:
        int n;

        explicit TestScene(unsigned int i) : Scene() {
            n = 0;
        }

        void onCreate() override {
        }

        void onDestroy() override {
        }

        void onUpdate(float delta) override {
            n++;
        }
    };

    SECTION("Test basic scene creation") {
        SceneManager manager(nullptr);
        UUID scene = manager.createScene<TestScene>(1);
        auto cScene = manager.getCurrentScene();
        REQUIRE(cScene.get() != nullptr);
        REQUIRE((*cScene)->getId().is_nil() == false);
        REQUIRE((*cScene)->getId() == scene);
    }

    SECTION("Test scene removal") {
        SceneManager manager(nullptr);
        UUID scene = manager.createScene<TestScene>(1);
        auto cScene = manager.getCurrentScene();
        REQUIRE(cScene.get() != nullptr);
        REQUIRE((*cScene)->getId() == scene);
        manager.removeScene(scene);
        cScene = manager.getCurrentScene();
        REQUIRE(cScene.get() == nullptr);
    }

    SECTION("Test scene switching") {
        SceneManager manager(nullptr);
        UUID scene1 = manager.createScene<TestScene>(1);
        UUID scene2 = manager.createScene<TestScene>(2);
        auto cScene = manager.getCurrentScene();
        REQUIRE(cScene.get() != nullptr);
        REQUIRE((*cScene)->getId() == scene1);
        manager.setCurrentScene(scene2);
        cScene = manager.getCurrentScene();
        REQUIRE(cScene.get() != nullptr);
        REQUIRE((*cScene)->getId() == scene2);
    }

    SECTION("Test scene onUpdate") {
        SceneManager manager(nullptr);
        UUID scene = manager.createScene<TestScene>(1);
        auto cScene = manager.getCurrentScene();
        REQUIRE(cScene != nullptr);
        REQUIRE((*cScene)->getId() == scene);
        REQUIRE(((TestScene *) *cScene.get())->n == 0);
        manager.updateCurrentScene();
        REQUIRE(((TestScene *) *cScene.get())->n == 1);
        manager.updateCurrentScene();
        REQUIRE(((TestScene *) *cScene.get())->n == 2);
    }

    SECTION("Test multiple scene onUpdate") {
        SceneManager manager(nullptr);
        UUID scene1 = manager.createScene<TestScene>(1);
        UUID scene2 = manager.createScene<TestScene>(1);
        auto cScene = manager.getCurrentScene();
        REQUIRE(cScene != nullptr);
        REQUIRE((*cScene)->getId() == scene1);
        REQUIRE(((TestScene *) *cScene.get())->n == 0);
        manager.updateCurrentScene();
        REQUIRE(((TestScene *) *cScene.get())->n == 1);
        manager.updateCurrentScene();
        REQUIRE(((TestScene *) *cScene.get())->n == 2);
        manager.setCurrentScene(scene2);
        cScene = manager.getCurrentScene();
        REQUIRE(cScene != nullptr);
        REQUIRE((*cScene)->getId() == scene2);
        REQUIRE(((TestScene *) *cScene.get())->n == 0);
        manager.updateCurrentScene();
        REQUIRE(((TestScene *) *cScene.get())->n == 1);
        manager.updateCurrentScene();
        REQUIRE(((TestScene *) *cScene.get())->n == 2);
    }
}