cmake_minimum_required(VERSION 3.5.1)
project(lab_4_task_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab_4
        io.c
        io.h
        lab_4.c
        buffer.c
        buffer.h
        memory.c
        memory.h)
