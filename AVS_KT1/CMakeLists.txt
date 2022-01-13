cmake_minimum_required(VERSION 3.20)
project(projects)

set(CMAKE_CXX_STANDARD 17)

add_executable(projects Source/main.cpp Source/container.cpp Headers/container.h Source/tree.cpp Headers/tree.h Source/plant.cpp Headers/plant.h Source/flower.cpp Headers/flower.h Source/shrub.cpp Source/shrub.cpp Headers/shrub.h Headers/random.h)
