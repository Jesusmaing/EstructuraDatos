cmake_minimum_required(VERSION 3.17)
project(Grafos)

set(CMAKE_CXX_STANDARD 98)

add_executable(Grafos
        main.cpp
        Grafica.tpp
        Grafica.h
        Utilerias.h
        Utilerias.tpp
        GestionLista.h
        GestionLista.cpp
        Vector.cpp
        Vector.h
        )