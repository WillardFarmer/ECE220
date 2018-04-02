cmake_minimum_required(VERSION 3.5)
project(lab_4_task2 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab_4_task2
        buffer.c
        buffer.h
        io.c
        io.h
        lab_4.c
        memory.c
        memory.h)