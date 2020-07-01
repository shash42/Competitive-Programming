cmake_minimum_required(VERSION 3.15)
project(CPL)

#set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_FLAGS "-std=c++17 -O0 -g -Wall -pedantic -fsanitize=address -fsanitize=undefined")

add_executable(A "/home/shashwat/Documents/CPL/Upsolve/ASC 06/A.cpp")
add_executable(B "/home/shashwat/Documents/CPL/Upsolve/ASC 06/B.cpp")
add_executable(C "/home/shashwat/Documents/CPL/Upsolve/ASC 06/C.cpp")