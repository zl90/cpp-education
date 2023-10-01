# set the minimum version of cmake for building this project
cmake_minimum_required(VERSION 3.22.1)

# set the project name
project(Threads)

# set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable we want to build
add_executable(threads threads.cpp)

# set our thread settings
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(threads Threads::Threads)