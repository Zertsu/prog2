cmake_minimum_required(VERSION 3.24)
project(hf03-01 C)

set(CMAKE_C_STANDARD 23)

add_executable(hf03-01 src/main.c src/BankAccount.c)
include_directories(headers)
