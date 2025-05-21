cmake_minimum_required(VERSION 3.20)
project(std_generator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_COMPILER "g++-14" CACHE FILEPATH "C++ compiler" FORCE)

add_executable(01_lazy 01_lazy.cpp)
add_executable(02_vector 02_vector.cpp)
add_executable(03_tree 03_tree.cpp)

target_compile_options(01_lazy PRIVATE -std=c++23)
target_compile_options(02_vector PRIVATE -std=c++23)
target_compile_options(03_tree PRIVATE -std=c++23)

# g++-14 -std=c++23 03_tree.cpp -o build/03_tree;
