cmake_minimum_required(VERSION 3.26)
project(Problems C)

set(CMAKE_C_STANDARD 11)

add_executable(Problems _5_longestPalindromicSubstring.c)
target_link_libraries(Problems m)