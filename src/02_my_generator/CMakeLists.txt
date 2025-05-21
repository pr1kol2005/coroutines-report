cmake_minimum_required(VERSION 3.20)
project(std_generator_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(01_greedy 01_greedy.cpp)
add_executable(02_lazy 02_lazy.cpp)
add_executable(03_interleave_naive 03_interleave_naive.cpp)
add_executable(04_interleave_coro 04_interleave_coro.cpp)
add_executable(05_tree_naive 05_tree_naive.cpp)
add_executable(06_tree_coro 06_tree_coro.cpp)
