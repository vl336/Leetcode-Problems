cmake_minimum_required(VERSION 3.26)
project(Problems C)

set(CMAKE_C_STANDARD 11)

add_executable(Problems _9_palindromeNumber.c)
target_link_libraries(Problems m)