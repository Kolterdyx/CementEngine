cmake_minimum_required(VERSION 3.23)
project(CementEngine)

find_package(Catch2 3 REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(CementSources
        Core/EventSystem/EventDispatcher.cpp
        Core/EventSystem/EventDispatcher.hpp
        Core/EventSystem/BaseEvent.hpp
        Core/SceneSystem/SceneSystem.hpp
        Core/SceneSystem/SceneSystem.hpp
)

set(TestSources
        test/framework/UnitTest.cpp
        test/framework/UnitTest.hpp
        test/framework/color.hpp
        test/TestEventSystem.hpp
        test/TestSceneSystem.hpp
)

add_executable(CementEngine
        main.cpp
        ${CementSources}
)

add_executable(TestCementEngine
        tests.cpp
        ${CementSources}
        ${TestSources}
)
