cmake_minimum_required(VERSION 3.3)
project(Tromino_hugger)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Quadrant.cpp Quadrant.h)
add_executable(Tromino_hugger ${SOURCE_FILES})