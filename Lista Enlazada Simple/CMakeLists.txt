cmake_minimum_required(VERSION 3.17)
project(ListaEnlazadaSimple)

set(CMAKE_CXX_STANDARD 98)

add_executable(Lista main.cpp
        ListaEnlazadaSimple.h
        ListaEnlazadaSimple.tpp
        Utilerias.tpp
        Utilerias.h
        GestionLista.cpp
        GestionLista.h
        )