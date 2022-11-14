cmake_minimum_required(VERSION 3.23)
project(CementEngine)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 14)

set(CementSources
        Core/globals.hpp
        Core/EventSystem/EventDispatcher.cpp
        Core/EventSystem/EventDispatcher.hpp
        Core/EventSystem/BaseEvent.hpp
        Core/SceneSystem/SceneSystem.hpp
        Core/SceneSystem/BaseScene.cpp
        Core/SceneSystem/BaseScene.hpp
        Core/SceneSystem/SceneStateManager.cpp
        Core/SceneSystem/SceneStateManager.hpp
        Core/NEntityComponentSystem/ComponentSystem.hpp
        Core/NEntityComponentSystem/ComponentArray.hpp
        Core/NEntityComponentSystem/EntityManager.cpp
        Core/NEntityComponentSystem/EntityManager.hpp
        Core/NEntityComponentSystem/ComponentManager.hpp
        Core/NEntityComponentSystem/EntityComponentSystem.cpp
        Core/NEntityComponentSystem/EntityComponentSystem.hpp
        Core/NEntityComponentSystem/SystemManager.cpp
        Core/NEntityComponentSystem/SystemManager.hpp
        Core/EntitySystems/MovementSystem.cpp
        Core/EntitySystems/MovementSystem.hpp
        Core/EntitySystems/IEntitySystem.hpp
        )

set(TestSources
        test/TestEventSystem.cpp
        test/TestSceneSystem.cpp
        test/TestEntityComponentSystem.cpp
        )

add_executable(CementEngine
        main.cpp
        ${CementSources}
        )

add_executable(CementEngineTests ${TestSources} ${CementSources})

target_link_libraries(CementEngineTests PRIVATE Catch2::Catch2WithMain)
