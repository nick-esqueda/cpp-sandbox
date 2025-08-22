cmake_minimum_required(VERSION 3.31)
project(cpp_sandbox)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_sandbox main.cpp)
add_executable(headers-and-imports headers-and-imports.cpp utils.cpp)
add_executable(classes Thing.cpp Thing.h
        classes.cpp)
add_executable(memory-management memory-management.cpp)
