cmake_minimum_required(VERSION 3.17)
project(PruebaCola)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(PruebaCola main.cpp
        ColaCircular.tpp
        ColaCircular.h
        GestionCola.cpp
        GestionCola.h
        Utilerias.h
        Utilerias.tpp
        )