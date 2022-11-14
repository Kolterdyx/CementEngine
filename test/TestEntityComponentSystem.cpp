//
// Created by kolterdyx on 10/11/22.
//

#include "../Core/EntityComponentSystem/EntityComponentSystem.hpp"
#include "catch2/catch_test_macros.hpp"

TEST_CASE("Test the Entity Component IEntitySystem", "[Entity Component IEntitySystem]") {
    ecs::EntityComponentSystem ECS;

    SECTION("Create one entity") {
        Entity entity = ECS.createEntity();
        REQUIRE(entity > 0);
    }

    SECTION("Create multiple entities") {
        Entity entities[10];
        for (int i=0; i < 10; i++)
            entities[i] = ECS.createEntity();
        for (auto entity : entities)
            REQUIRE(entity > 0);
    }

    SECTION("Register component") {
        typedef struct TestComp {
            int x;
            int y;
        } TestComp;
        ECS.registerComponent<TestComp>();

        REQUIRE(ECS.getComponentType<TestComp>() >= 0);
    }

    SECTION("Register component twice") {
        typedef struct TestComp {
            int x;
            int y;
        } TestComp;
        bool fail = false;
        try {
            ECS.registerComponent<TestComp>();
            ECS.registerComponent<TestComp>();
        } catch(const std::runtime_error& e) {
            fail = true;
        }
        REQUIRE(fail);
    }

    SECTION("Register system") {
        class TestSystem : public ecs::IEntitySystem {

        };
        ECS.registerSystem<TestSystem>();
    }


}