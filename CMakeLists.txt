cmake_minimum_required(VERSION 3.31)
project(cpp_sandbox)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_sandbox main.cpp)
add_executable(headers-and-imports headers-and-imports.cpp utils.cpp)
add_executable(classes Thing.cpp Thing.h
        classes.cpp
        Point.cpp
        Point.h)
add_executable(memory-management memory-management.cpp)
add_executable(raii raii.cpp)
add_executable(smart-pointers smart-pointers.cpp)
add_executable(polymorphism polymorphism.cpp)
