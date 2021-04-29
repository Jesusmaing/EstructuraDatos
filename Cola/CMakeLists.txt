cmake_minimum_required(VERSION 3.17)
project(Cola)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Cola main.cpp cmake-build-debug/Cola.tpp cmake-build-debug/Cola.h)