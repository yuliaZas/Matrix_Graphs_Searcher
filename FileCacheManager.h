//
// Created by Yulia.
//

#ifndef UNTITLED2_FILECACHEMANAGER_H
#define UNTITLED2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>

using namespace std;

class FileCacheManager : public CacheManager {
public:
    bool solutionExists(string problem) override;

    string getSolution(string problem) override;

    void saveSolution(string problem, string solution) override;
};


#endif //UNTITLED2_FILECACHEMANAGER_H
