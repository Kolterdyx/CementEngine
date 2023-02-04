cmake_minimum_required(VERSION 3.0)

project(box2d)

file(GLOB_RECURSE Box2D_SRC
	box2d/src/*.h
	box2d/src/*.cpp
	box2d/include/*.h
	box2d/extern/*.h
)
include_directories(box2d/include)

message(STATUS "Box2D_SRC: ${Box2D_SRC}")
add_library(box2d STATIC ${Box2D_SRC})

target_include_directories(box2d PUBLIC "box2d")
