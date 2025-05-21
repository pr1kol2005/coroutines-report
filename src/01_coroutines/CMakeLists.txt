cmake_minimum_required(VERSION 3.20)
project(coroutines_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(01_example 01_example.cpp)
add_executable(02_goal 02_goal.cpp)
