cmake_minimum_required(VERSION 3.9)
project(lab_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab_2
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/lab_2
        cmake-build-debug/lab_2.cbp
        cmake-build-debug/Makefile
        a.out
        budgets.txt
        CMakeLists.txt
        expenses.txt
        lab_2.c)
