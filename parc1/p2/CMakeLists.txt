cmake_minimum_required(VERSION 3.24)
project(p2 C)

set(CMAKE_C_STANDARD 23)

add_executable(p2 src/main.c src/Student.c)
include_directories(headers)
