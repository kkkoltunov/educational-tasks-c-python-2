cmake_minimum_required(VERSION 3.20)
project(AVS_KT2)

set(CMAKE_CXX_STANDARD 17)

add_executable(AVS_KT2 Sources/main.cpp Sources/container.cpp Headers/container.h Sources/tree.cpp Headers/tree.h Sources/plant.cpp Headers/plant.h Sources/flower.cpp Headers/flower.h Sources/shrub.cpp Sources/shrub.cpp Headers/shrub.h Headers/random.h)
