cmake_minimum_required(VERSION 3.15)
project(30f_Variants)

set(CMAKE_CXX_STANDARD 17)

include_directories(. variants)


add_compile_options(-O1 -g -Wall -Wextra -Wpedantic -Wnull-dereference -Wnon-virtual-dtor)


add_executable(HowTo
        HowTo.cpp)

add_executable(visitor_pattern
        tools.hpp
        tools.cpp
        visitors/ast.cpp
        visitors/ast.hpp
        visitors/main.cpp
        visitors/visitor.hpp
        visitors/printerVisitor.hpp
        visitors/evaluatorVisitor.hpp)

add_executable(var
        variants/Variants.cpp)

add_executable(var_overload_1
        variants/Variants1.cpp)

add_executable(var_overload_2
        variants/Variants2.cpp)

add_executable(var_overload_3
        variants/Variants3.cpp)