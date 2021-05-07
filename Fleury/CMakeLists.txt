cmake_minimum_required(VERSION 3.17)
project(Fleury)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(Fleury
        main.cpp
        ColaCircular.h
        ColaCircular.tpp
        Grafica.h
        Grafica.tpp
        Pila.h
        Pila.tpp
        )