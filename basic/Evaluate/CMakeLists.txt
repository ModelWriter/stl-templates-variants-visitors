cmake_minimum_required(VERSION 3.15)
project(Evaluate)

add_executable(basic-evaluate
        eval.cpp eval.hpp flexT.hpp main.cpp operator.hpp stackT.hpp tools.cpp tools.hpp)
