cmake_minimum_required(VERSION 3.24)
project(hf01 C)

set(CMAKE_C_STANDARD 23)

add_executable(hf01 src/main.c)
include_directories(headers)
