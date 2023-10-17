cmake_minimum_required(VERSION 3.24)
project(test C)

set(CMAKE_C_STANDARD 23)

add_executable(test src/main.c)
include_directories(headers)
