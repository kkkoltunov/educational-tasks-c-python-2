cmake_minimum_required(VERSION 3.20)
project(AVS_KT4)

set(CMAKE_CXX_STANDARD 14)

add_executable(AVS_KT4 main.c input.c data.h extdata.h inrnd.c output.c other.c)
