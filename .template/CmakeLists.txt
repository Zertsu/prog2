cmake_minimum_required(VERSION 3.24)
project(<PNAME> C)

set(CMAKE_C_STANDARD 23)

add_executable(<PNAME> src/main.c)
include_directories(headers)
