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
        Core/EntityComponentSystem/ComponentSystem.hpp
        Core/EntityComponentSystem/ComponentArray.hpp
        Core/EntityComponentSystem/EntityManager.cpp
        Core/EntityComponentSystem/EntityManager.hpp
        Core/EntityComponentSystem/ComponentManager.hpp
        Core/EntityComponentSystem/EntityComponentSystem.cpp
        Core/EntityComponentSystem/EntityComponentSystem.hpp
        Core/EntityComponentSystem/SystemManager.cpp
        Core/EntityComponentSystem/SystemManager.hpp
        Core/EntitySystems/MovementSystem.cpp
        Core/EntitySystems/MovementSystem.hpp
        Core/EntitySystems/System.cpp
        Core/EntitySystems/System.hpp
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
