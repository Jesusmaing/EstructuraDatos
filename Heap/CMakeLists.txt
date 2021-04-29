cmake_minimum_required(VERSION 3.19)
project(Heap)

set(CMAKE_CXX_STANDARD 98)

add_executable(Heap
        main.cpp
        GestionArbol.cpp
        GestionArbol.h
        Heap.h
        Heap.tpp
        Utilerias.h
        Utilerias.tpp
        Vector.cpp
        Vector.h)