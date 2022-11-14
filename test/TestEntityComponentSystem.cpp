//
// Created by kolterdyx on 10/11/22.
//

#include "../Core/NEntityComponentSystem/EntityComponentSystem.hpp"
#include "catch2/catch_test_macros.hpp"

using namespace Cement;

TEST_CASE("Test the Entity Component System", "[Entity Component System]") {
    ecs::EntityComponentSystem ECS;

    SECTION("Components") {
        typedef struct TestComp {} TestComp;
         SECTION("Register component") {
            ECS.registerComponent<TestComp>();
            REQUIRE(ECS.getComponentType<TestComp>() >= 0);
        }

        SECTION("Register component twice") {
            bool fail = false;
            try {
                ECS.registerComponent<TestComp>();
                ECS.registerComponent<TestComp>();
            } catch(const AssertionFail& e) {
                fail = true;
            }
            REQUIRE(fail == true);
        }
    }

    SECTION("Systems") {
        class TestSystem : public ecs::IEntitySystem {};
        SECTION("Register system") {
            ECS.registerSystem<TestSystem>();
        }

        SECTION("Register system twice") {
            bool fail = false;
            try {
                ECS.registerSystem<TestSystem>();
                ECS.registerSystem<TestSystem>();
            } catch(const AssertionFail& e) {
                fail = true;
            }
            REQUIRE(fail == true);
        }
    }

    SECTION("Entities") {

        struct TestComp1 {
            int x = 0;
        };
        struct TestComp2 {
            int x = 0;
        };

        ECS.registerComponent<TestComp1>();
        ECS.registerComponent<TestComp2>();

        SECTION("Create one entity") {
            Entity entity = ECS.createEntity();
            REQUIRE(entity > 0);
        }

        SECTION("Create multiple entities") {
            Entity entities[10];
            for (unsigned long & entity : entities) {
                entity = ECS.createEntity();
            }
            for (auto entity : entities) {
                REQUIRE(entity > 0);
            }
        }

        SECTION("Add components to entities") {
            Entity entity1 = ECS.createEntity();
            Entity entity2 = ECS.createEntity();
            Entity entity3 = ECS.createEntity();
            SECTION("Add one component") {
                bool fail = false;
                try  {
                    ECS.addComponent(entity1, TestComp1());
                } catch (const std::exception& e) {
                    fail = true;
                }
                REQUIRE(fail == false);
            }

            SECTION("Add two components") {
                bool fail = false;
                try  {
                    ECS.addComponent(entity1, TestComp1());
                    ECS.addComponent(entity1, TestComp2());
                } catch (const std::exception& e) {
                    fail = true;
                }
                REQUIRE(fail == false);
            }

            SECTION("Add the same component twice") {
                bool fail = false;
                try  {
                    ECS.addComponent(entity1, TestComp1());
                    ECS.addComponent(entity1, TestComp1());
                } catch (const std::exception& e) {
                    fail = true;
                }
                REQUIRE(fail == true);
            }

            SECTION("Get registered component from entity") {
                ECS.addComponent(entity1, TestComp1());
                bool fail = false;
                try  {
                    ECS.getComponent<TestComp1>(entity1);
                } catch (const AssertionFail& e) {
                    fail = true;
                }
                REQUIRE(fail == false);
            }

            SECTION("Get unregistered component from entity") {
                struct TestCompUnregistered {};
                bool fail = false;
                try  {
                    ECS.getComponent<TestCompUnregistered>(entity2);
                } catch (const AssertionFail& e) {
                    fail = true;
                }
                REQUIRE(fail == true);
            }

            SECTION("Get component not present in entity") {
                bool fail = false;
                try  {
                    ECS.getComponent<TestComp1>(entity1);
                } catch (const AssertionFail& e) {
                    fail = true;
                }
                REQUIRE(fail == true);
            }

        }
    }

}