//
// Created by kolterdyx on 2/11/22.
//

#include "Core/EntityComponentSystem/EntityComponentSystem.hpp"

int main() {

    ecs::EntityComponentSystem ECS;

    struct TestComp {
        int x;
        int y;
    };

    ECS.registerComponent<TestComp>();
    ECS.registerComponent<TestComp>();

    return 0;
}
