//
// Created by Yulia.
//

#ifndef UNTITLED2_FILECACHEMANAGER_H
#define UNTITLED2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

class FileCacheManager : public CacheManager {
private:
    string filePath;
    std::unordered_map<std::string, std::string> solutionMap;

public:
    /**
     * CTOR that force the string param be a string.
     * @param path the path to the file with the problems and their solutions.
     */
    explicit FileCacheManager(string path);

    bool solutionExists(string problem) override;

    string getSolution(string problem) override;

    void saveSolution(string problem, string solution) override;
    /**
     * In chrage of loading the file with the problems and their solutions.
     */
    void solutionsLoader();
    /**
     * Distructor.
     */
    ~FileCacheManager() {};
};


#endif //UNTITLED2_FILECACHEMANAGER_H
