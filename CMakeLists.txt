cmake_minimum_required(VERSION 3.13)
project(mile_stone2)

set(CMAKE_CXX_STANDARD 14)

add_executable(mile_stone2 main.cpp State.cpp State.h ISearchable.cpp ISearchable.h matrixMaze.cpp matrixMaze.h solution.cpp solution.h)