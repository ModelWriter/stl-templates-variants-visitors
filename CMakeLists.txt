cmake_minimum_required(VERSION 3.15)
project(variants-visitors-stl)

set(CMAKE_CXX_STANDARD 17)

include_directories(. variants templates stl)


add_compile_options(-O1 -g -Wall -Wextra -Wpedantic -Wnull-dereference -Wnon-virtual-dtor)


add_executable(constructor_destructor
        HowTo.cpp)

add_executable(templates
        templates/templates.cpp)

add_executable(stl_for_each
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_for_each.cpp)

add_executable(stl_transform
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_transform.cpp)

add_executable(stl_find
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_find.cpp)

add_executable(stl_count
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_count.cpp)

add_executable(stl_find_first_of
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_find_first_of.cpp)

add_executable(stl_all_any_none_of
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_all_any_none_of.cpp)

add_executable(stl_copy
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_copy.cpp)

add_executable(stl_generate
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_generate.cpp)

add_executable(stl_remove
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_remove.cpp)

add_executable(stl_max_element
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_max_element.cpp)

add_executable(stl_min_element
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_min_element.cpp)

add_executable(stl_min
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_min.cpp)

add_executable(stl_minmax_element
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_mimmax_element.cpp)

add_executable(stl_max
        utility.cpp
        utility.hpp
        stl/stl.cpp
        stl/stl.hpp
        stl/stl_max.cpp)

add_executable(visitor_pattern
        utility.hpp
        utility.cpp
        visitors/ast.cpp
        visitors/ast.hpp
        visitors/main.cpp
        visitors/visitor.hpp
        visitors/printerVisitor.hpp
        visitors/evaluatorVisitor.hpp)

add_executable(var_vanilla
        variants/Variants.cpp)

add_executable(var_overload_1
        variants/Variants1.cpp)

add_executable(var_overload_2
        variants/Variants2.cpp)

add_executable(var_overload_3
        variants/Variants3.cpp)