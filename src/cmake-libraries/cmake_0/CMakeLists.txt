# set the minimum version of cmake for building this project
cmake_minimum_required(VERSION 3.22.1)

# set the project name
project(Math)

# add the library we want to build
add_library(math SHARED add.cpp multiply.cpp)

# add the executable we want to build
add_executable(main main.cpp)

# specify that we need to link against our created library
target_link_libraries(main math)