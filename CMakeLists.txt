cmake_minimum_required(VERSION 3.28)
project(data_structures_stl)

set(CMAKE_CXX_STANDARD 20)

include_directories(data_structures_stl)

add_executable(data_structures_stl
        data_structures_stl/ds_algorithms.h
        data_structures_stl/ds_b_tree.h
        data_structures_stl/ds_binary_tree.h
        data_structures_stl/ds_Calculator.cpp
        data_structures_stl/ds_Calculator.hpp
        data_structures_stl/ds_forward_list.h
        data_structures_stl/ds_graph.h
        data_structures_stl/ds_heap.h
        data_structures_stl/ds_list.h
        data_structures_stl/ds_queue.h
        data_structures_stl/ds_stack.h
        data_structures_stl/ds_tree.h
        data_structures_stl/ds_vector.h
        data_structures_stl/main.cpp
        data_structures_stl/preliminaries.cpp
        data_structures_stl/preliminaries.hpp
        data_structures_stl/test.cpp
        data_structures_stl/test.hpp)
