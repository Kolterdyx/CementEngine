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

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost)

set(CMAKE_CXX_STANDARD 14)

set(CementCoreSources
        Core/globals.hpp
        Core/EventSystem/EventManager.hpp
        Core/EventSystem/EventManager.tpp
        Core/SceneSystem/Scene.cpp
        Core/SceneSystem/Scene.hpp
        Core/SceneSystem/Scene.tpp
        Core/SceneSystem/SceneManager.cpp
        Core/SceneSystem/SceneManager.hpp
        Core/EntityComponentSystem/Entity.cpp
        Core/EntityComponentSystem/Entity.hpp
        Core/UUID/UUID.hpp
        Core/UUID/UUID.cpp)

set(TestSources
        test/TestEventSystem.cpp
        test/TestSceneSystem.cpp
        )

add_executable(${PROJECT_NAME}
        Editor/main.cpp
        ${CementCoreSources}
        )

add_executable(${PROJECT_TEST_NAME} ${CementCoreSources} ${TestSources})

target_link_libraries(${PROJECT_NAME} PRIVATE EnTT::EnTT)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
    target_link_libraries(${PROJECT_TEST_NAME} ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Boost not found")
endif()

target_link_libraries(${PROJECT_TEST_NAME} PRIVATE Catch2::Catch2WithMain)
target_link_libraries(${PROJECT_TEST_NAME} PRIVATE EnTT::EnTT)
