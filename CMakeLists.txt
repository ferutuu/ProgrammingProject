cmake_minimum_required(VERSION 3.28)
project(LibraryManagement C)

set(CMAKE_C_STANDARD 23)

add_executable(LibraryManagement main.c
        library.c)
