cmake_minimum_required(VERSION 3.20)
project(std_generator_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(01_greedy 01_greedy.cpp)
add_executable(02_lazy 02_lazy.cpp)
add_executable(03_vector_naive 03_vector_naive.cpp)
add_executable(04_vector_coro 04_vector_coro.cpp)
add_executable(05_tree_naive 05_tree_naive.cpp)
add_executable(06_tree_coro 06_tree_coro.cpp)

# target_compile_options(01_greedy PRIVATE -Wall -Wextra)
# target_compile_options(02_lazy PRIVATE -Wall -Wextra)
# target_compile_options(03_vector_naive PRIVATE -Wall -Wextra)
# target_compile_options(04_vector_coro PRIVATE -Wall -Wextra)
# target_compile_options(05_tree_naive PRIVATE -Wall -Wextra)
# target_compile_options(06_tree_coro PRIVATE -Wall -Wextra)
