cmake_minimum_required(VERSION 3.20)
project(std_generator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(01_sequences 01_sequences.cpp)
add_executable(02_interleave 02_interleave.cpp)
add_executable(03_tree 03_tree.cpp)
