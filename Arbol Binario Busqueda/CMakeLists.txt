cmake_minimum_required(VERSION 3.17)
project(ArbolBinarioBusqueda)

set(CMAKE_CXX_STANDARD 98)

add_executable(ArbolBinarioBusqueda
        main.cpp
        AVL.tpp
        AVL.h
        Cola.h
        Cola.tpp
        GestionLista.cpp
        GestionLista.h
        Utilerias.tpp
        Utilerias.h
        Vector.h
        Vector.cpp
        )
