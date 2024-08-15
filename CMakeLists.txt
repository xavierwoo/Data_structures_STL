cmake_minimum_required(VERSION 3.28)
project(data_structures_stl)

set(CMAKE_CXX_STANDARD 20)

include_directories(data_structures_stl)

add_executable(data_structures_stl
        data_structures_stl/hbut_algorithms.hpp
        data_structures_stl/hbut_b_tree.h
        data_structures_stl/hbut_binary_tree.h
        data_structures_stl/hbut_calculator.cpp
        data_structures_stl/hbut_calculator.hpp
        data_structures_stl/hbut_forward_list.h
        data_structures_stl/hbut_graph.h
        data_structures_stl/hbut_heap.h
        data_structures_stl/hbut_list.h
        data_structures_stl/hbut_queue.h
        data_structures_stl/hbut_stack.h
        data_structures_stl/hbut_tree.h
        data_structures_stl/hbut_vector.h
        data_structures_stl/main.cpp
        data_structures_stl/preliminaries.cpp
        data_structures_stl/preliminaries.hpp
        data_structures_stl/test.cpp
        data_structures_stl/test.hpp
        data_structures_stl/hbut_algorithms.cpp)
