cmake_minimum_required(VERSION 3.24)
project(extra C)

set(CMAKE_C_STANDARD 23)

add_executable(extra src/main.c src/Maze.c)
include_directories(headers)
