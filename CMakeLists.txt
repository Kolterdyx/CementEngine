cmake_minimum_required(VERSION 3.23)
set(PROJECT_NAME CementEngine)
set(PROJECT_TEST_NAME ${PROJECT_NAME}Test)

project(${PROJECT_NAME})


Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1
)

FetchContent_Declare(
        EnTT
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG        v3.11.0
)

FetchContent_MakeAvailable(Catch2)
FetchContent_MakeAvailable(EnTT)

set(CMAKE_CXX_STANDARD 14)

set(CementCoreSources
        Core/globals.hpp
        Core/EventSystem/Event.hpp
        Core/SceneSystem/SceneSystem.hpp
        Core/SceneSystem/Scene.cpp
        Core/SceneSystem/Scene.hpp
        Core/SceneSystem/SceneStateManager.cpp
        Core/SceneSystem/SceneStateManager.hpp
        Core/EntityComponentSystem/Entity.hpp)

set(TestSources
        test/TestEventSystem.cpp
        test/TestSceneSystem.cpp
        )

add_executable(${PROJECT_NAME}
        main.cpp
        ${CementCoreSources}
        )

add_executable(${PROJECT_TEST_NAME} ${CementCoreSources} ${TestSources})

# Main executable linked libraries
target_link_libraries(${PROJECT_NAME} PRIVATE EnTT::EnTT)

# Test linked libraries
target_link_libraries(${PROJECT_TEST_NAME} PRIVATE Catch2::Catch2WithMain)
target_link_libraries(${PROJECT_TEST_NAME} PRIVATE EnTT::EnTT)
