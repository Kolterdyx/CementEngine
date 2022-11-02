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
        Core/EventSystem/EventDispatcher.cpp
        Core/EventSystem/EventDispatcher.hpp
        Core/EventSystem/BaseEvent.hpp
        Core/SceneSystem/SceneSystem.hpp
        Core/SceneSystem/BaseScene.cpp
        Core/SceneSystem/BaseScene.hpp
        Core/SceneSystem/SceneStateManager.cpp
        Core/SceneSystem/SceneStateManager.hpp
        Core/ComponentSystem/ComponentSystem.hpp
)

add_executable(CementEngine
        main.cpp
        ${CementSources}
)

set(TestSources
        test/TestEventSystem.cpp
        test/TestSceneSystem.cpp
)

add_executable(tests ${TestSources} ${CementSources})

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
