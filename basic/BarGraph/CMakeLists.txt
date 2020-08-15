cmake_minimum_required(VERSION 3.15)
project(14_BarGraph)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(14_BarGraph
        graph.cpp
        graph.hpp
        item.hpp
        main.cpp
        row.cpp
        row.hpp
        rowNest.hpp
        tools.cpp
        tools.hpp)
