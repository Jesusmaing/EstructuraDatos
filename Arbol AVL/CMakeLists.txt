cmake_minimum_required(VERSION 3.17)
project(Arbol_AVL)

set(CMAKE_CXX_STANDARD 98)

add_executable(Arbol_AVL
        main.cpp
        AVL.h
        AVL.tpp
        Cola.h
        Cola.tpp
        GestionLista.h
        GestionLista.cpp
        Utilerias.h
        Utilerias.tpp
        Vector.cpp
        Vector.h)