add_library(generator generator.cpp)

target_compile_features(generator PUBLIC cxx_std_20)

target_include_directories(generator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# target_compile_options(generator PRIVATE -Wall -Wextra -Wpedantic)
