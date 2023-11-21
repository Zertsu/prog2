cmake_minimum_required(VERSION 3.24)
project(f1 C)

set(CMAKE_C_STANDARD 23)

add_executable(f1 src/main.c)
include_directories(headers)
