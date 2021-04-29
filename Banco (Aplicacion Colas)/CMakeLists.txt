cmake_minimum_required(VERSION 3.17)
project(PruebaCola)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(PruebaCola main.cpp
        Cola.tpp
        Cola.h
        Persona.cpp
        Persona.h
        ColaMedieval.cpp
        ColaMedieval.h
        )