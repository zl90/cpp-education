# set the minimum version of cmake for building this project
cmake_minimum_required(VERSION 3.22.1)

# set the project name
project(Hello)

# set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set C++-specific flags
set(CMAKE_CXX_FLAGS "-Wall -Werror -O2 -march=native")

# add the executable we want to build
add_executable(hello_world hello_world.cpp)