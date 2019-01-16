cmake_minimum_required(VERSION 3.13)
project(mile_stone2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread")
add_executable(mile_stone2 main.cpp State.cpp State.h ISearchable.cpp ISearchable.h matrixMaze.cpp matrixMaze.h ISearcher.cpp ISearcher.h Searcher.cpp Searcher.h BestFS.cpp BestFS.h
        FileCacheManager.cpp FileCacheManager.h MatrixInterpreter.cpp MatrixInterpreter.h MySerialServer.cpp MySerialServer.h MyTestClientHandler.cpp MyTestClientHandler.h
        Server.h CacheManager.h Astar.cpp Astar.h)