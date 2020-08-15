cmake_minimum_required(VERSION 3.15)
project(12_BracketsWithMove)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(12_BracketsWithMove
        brackets.cpp
        brackets.hpp
        main.cpp
        stack.cpp
        stack.hpp
        token.cpp
        token.hpp
        tools.cpp
        tools.hpp)
