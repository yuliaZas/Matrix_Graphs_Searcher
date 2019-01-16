//
// Created by Yulia.
//

#ifndef UNTITLED2_MYTESTCLIENTHANDLER_H
#define UNTITLED2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include "matrixMaze.h"
#include "MyParallelServer.h"
#include "SearchableSolver.h"
#include "BestFS.h"
#include <string>
#include <string.h>
#include <thread>
#include <algorithm>
#include <sstream>
#include <unistd.h>


class MyTestClientHandler : public ClientHandler {
private:
    //// Members:
    Solver<ISearchable<std::pair<int,int>>*,State<std::pair<int,int>>*> *solver;
    CacheManager *cacheManager;

public:
    //// Constructor:
    MyTestClientHandler
    (Solver<ISearchable<std::pair<int, int>> *,State<std::pair<int, int>> *> *solver,
    CacheManager *cacheManager);

    void handleClient(int stream1) override;
};


#endif //UNTITLED2_MYTESTCLIENTHANDLER_H
