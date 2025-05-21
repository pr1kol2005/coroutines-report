cmake_minimum_required(VERSION 3.20)
project(std_generator_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(generator)

add_executable(01_sequences 01_sequences.cpp)
add_executable(02_interleave 02_interleave.cpp)
add_executable(03_tree 03_tree.cpp)

target_link_libraries(01_sequences PRIVATE generator)
target_link_libraries(02_interleave PRIVATE generator)
target_link_libraries(03_tree PRIVATE generator)

# target_compile_options(01_sequences PRIVATE -Wall -Wextra -Wpedantic)
# target_compile_options(02_interleave PRIVATE -Wall -Wextra -Wpedantic)
# target_compile_options(03_tree PRIVATE -Wall -Wextra -Wpedantic)

target_include_directories(01_sequences PRIVATE generator)
target_include_directories(02_interleave PRIVATE generator)
target_include_directories(03_tree PRIVATE generator)
