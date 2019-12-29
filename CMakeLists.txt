cmake_minimum_required(VERSION 3.15)
project(variants-visitors-stl)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_subdirectory(functors)
add_subdirectory(stl)
add_subdirectory(variants)
add_subdirectory(visitors)
add_subdirectory(smart_pointer)
add_subdirectory(raii)
add_subdirectory(containers)
add_subdirectory(contracts)
add_subdirectory(const_expression)
add_subdirectory(static_assert)
add_subdirectory(type_support_supported_operations)

add_compile_options(-O2 -g -Wall -Wextra -Wpedantic -Wnull-dereference -Wnon-virtual-dtor)


add_executable(constructor_destructor
        HowTo.cpp)



