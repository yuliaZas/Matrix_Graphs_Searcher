//
// Created by Yulia.
//

#ifndef UNTITLED2_MYCLIENTHANDLER_H
#define UNTITLED2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include "matrixMaze.h"
#include "MyParallelServer.h"
#include "SearchableSolver.h"
#include "MatrixInterpreter.h"
#include "BestFS.h"
#include <string>
#include <string.h>
#include <thread>
#include <algorithm>
#include <sstream>
#include <unistd.h>
#include <mutex>

using namespace std;
std::mutex mtx;

class MyClientHandler : public ClientHandler {
private:
    Solver<ISearchable<pair<int,int>>*,State<pair<int,int>>*> *solver;
    CacheManager *cacheManager;

public:
    /**
     * CTOR
     * @param solver the solver
     * @param cacheManager the cache manager
     */
    MyClientHandler
            (Solver<ISearchable<std::pair<int, int>> *,State<std::pair<int, int>> *> *solver,
             CacheManager *cacheManager);
    /*override*/
    void handleClient(int stream1) override;
    /**
    * Get solution and return it as a string of directions.
    * @param path The last State in the path.
    * @return string of directions.
    */
    string pathGetter(State<pair<int,int>>* path);
    /**
    * Reads data from client.
    * @param socket The socket we connected to.
    * @return string - The data we have.
    */
    string dataReader(int socket);
    /**
    * Returns hash of a string.
    * @param string1 The string to get hash for.
    * @return The hash value.
    */
    size_t GetHashOfString(string string1);
    /**
     * help func that convert string to pair
     * @param str the string to convert
     * @return the pair
     */
    pair<int,int> strToIntPair(string str);
};


#endif //UNTITLED2_MYCLIENTHANDLER_H
