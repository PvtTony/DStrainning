cmake_minimum_required(VERSION 3.10)
project(sort)

set(CMAKE_CXX_STANDARD 11)

add_executable(sort main.cpp quicksort.h quicksort.cpp common.h common.cpp)