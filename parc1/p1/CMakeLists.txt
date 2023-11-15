cmake_minimum_required(VERSION 3.24)
project(p1 C)

set(CMAKE_C_STANDARD 23)

add_executable(p1 src/main.c src/Team.c)
include_directories(headers)
