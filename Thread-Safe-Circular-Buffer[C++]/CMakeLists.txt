cmake_minimum_required(VERSION 3.10)
project(CircularBufferProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(circular_buffer main.cpp src/C-Buffer.cpp)