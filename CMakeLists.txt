cmake_minimum_required(VERSION 3.8)
project(Project_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.c
        mergesort.c
        sorter.c
        Sorter.h
        test.c)

add_executable(Project_2 ${SOURCE_FILES})