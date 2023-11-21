cmake_minimum_required(VERSION 3.24)
project(hf2 C)

set(CMAKE_C_STANDARD 23)

add_executable(hf2 src/main.c)
include_directories(headers)
