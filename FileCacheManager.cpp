//
// Created by Yulia.
//

#include "FileCacheManager.h"
FileCacheManager::FileCacheManager(string path) {
    this->filePath = path;
    this->solutionsLoader();
}

bool FileCacheManager::solutionExists(string problem) {
    bool sol = this->solutionMap.count(problem);
    //checks if there is solution
    bool exist = sol > 0;
    return exist;
}

string FileCacheManager::getSolution(string problem) {
    if (this->solutionExists(problem)) {
        return this->solutionMap.at(problem);
    } else {
        //there is'nt a solution
        string non = "";
        return non;
    }
}

void FileCacheManager::saveSolution(string problem, string solution) {
    ofstream data;
    data.open(this->filePath, ios_base::app);

    pair<string, string> solProbPair;
    solProbPair.first  = problem;
    solProbPair.second = solution;
    this->solutionMap.insert(solProbPair);

    data << problem  << endl;
    data << solution << endl;

    data.close();
}

void FileCacheManager::solutionsLoader() {

    string problem;
    string solution;
    ifstream infoFromTheFile;
    infoFromTheFile.open(this->filePath);

    if (infoFromTheFile.good() == false) {
        return;
    }

    while (getline(infoFromTheFile, problem)) {
        getline(infoFromTheFile, solution);
        pair<string, string> solProbPair;
        solProbPair.first  = problem;
        solProbPair.second = solution;
        this->solutionMap.insert(solProbPair);
    }

    infoFromTheFile.close();
    return;
}
