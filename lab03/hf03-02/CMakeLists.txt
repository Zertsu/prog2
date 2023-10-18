cmake_minimum_required(VERSION 3.24)
project(hf03-02 C)

set(CMAKE_C_STANDARD 23)

add_executable(hf03-02 src/main.c src/Book.c)
include_directories(headers)
