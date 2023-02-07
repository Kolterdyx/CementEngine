cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 14)

set(PROJECT_NAME CementEngine)
set(PROJECT_TEST_NAME ${PROJECT_NAME}Test)

project(${PROJECT_NAME})

include_directories(Core)

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

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost)
find_package(Box2D)
#add_subdirectory(Box2D-CMake)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

set(CementCoreSources
        Core/globals.hpp
        Core/Events/EventDispatcher.hpp
        Core/Events/EventDispatcher.tpp
        Core/Scenes/Scene.cpp
        Core/Scenes/Scene.hpp
        Core/Scenes/Scene.tpp
        Core/Scenes/SceneManager.cpp
        Core/Scenes/SceneManager.hpp
        Core/EntityComponentSystem/Entity.cpp
        Core/EntityComponentSystem/Entity.hpp
        Core/UUID/UUID.hpp
        Core/UUID/UUID.cpp
        Core/Scenes/SceneManager.tpp
        Core/Events/Event.cpp
        Core/Events/Event.hpp
        Core/Math/Vector2f.cpp
        Core/Math/Vector2f.hpp
        Core/Math/Math.cpp
        Core/Math/Math.hpp Core/Physics/Conversions.cpp Core/Physics/Conversions.hpp Core/Application.cpp Core/Application.hpp Core/Physics/Box2DDebugDraw.cpp Core/Physics/Box2DDebugDraw.hpp Core/globals.cpp)

set(TestSources
        test/TestEventSystem.cpp
        test/TestSceneSystem.cpp
        )

set(AppSources
        App/main.cpp
        App/MyApp.cpp
        App/MyApp.hpp
        App/scenes/PhysicsTestScene.cpp
        App/scenes/PhysicsTestScene.hpp
        )

add_executable(${PROJECT_NAME} ${CementCoreSources} ${AppSources})

add_executable(${PROJECT_TEST_NAME} ${CementCoreSources} ${TestSources})

#include_directories(Box2D-CMake/box2d/include)

target_link_libraries(${PROJECT_NAME} PRIVATE EnTT::EnTT)
target_link_libraries(${PROJECT_NAME} PRIVATE Box2D)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system sfml-network sfml-audio)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
    target_link_libraries(${PROJECT_TEST_NAME} ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Boost not found")
endif()

target_link_libraries(${PROJECT_TEST_NAME} PRIVATE Box2D)
target_link_libraries(${PROJECT_TEST_NAME} PRIVATE sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
target_link_libraries(${PROJECT_TEST_NAME} PRIVATE Catch2::Catch2WithMain)
target_link_libraries(${PROJECT_TEST_NAME} PRIVATE EnTT::EnTT)

