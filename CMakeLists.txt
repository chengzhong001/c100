cmake_minimum_required(VERSION 3.10)
project(c100)

set(CMAKE_CXX_STANDARD  17)

file(GLOB_RECURSE src_files src/*.cpp)
add_executable(${PROJECT_NAME} ${src_files})
