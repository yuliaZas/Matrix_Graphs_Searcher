//
// Created by Yulia.
//

#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int stream1) {}

MyTestClientHandler::MyTestClientHandler(Solver<ISearchable<std::pair<int, int>> *,
        State<std::pair<int, int>> *> *solver, CacheManager *cacheManager) {

    this->cacheManager = cacheManager;
    this->solver = solver;
}
