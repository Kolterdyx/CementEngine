cmake_minimum_required(VERSION 3.0)

project(Box2D)

file(GLOB_RECURSE Box2D_SRC
	box2d/src/*.h
	box2d/src/*.cpp
	box2d/include/*.h
	box2d/extern/*.h
)
include_directories(box2d/include)

add_library(Box2D STATIC ${Box2D_SRC})

target_include_directories(Box2D PUBLIC "Box2D")
