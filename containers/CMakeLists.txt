cmake_minimum_required(VERSION 3.15)
project(22b_Evaluate)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(22b_Evaluate
        eval.cpp
        eval.hpp
        flexT.hpp
        main.cpp
        operator.hpp
        stackT.hpp
        tools.cpp
        tools.hpp)
