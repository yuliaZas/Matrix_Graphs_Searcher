//
// Created by Yulia.
//

#ifndef UNTITLED2_CACHEMANAGER_H
#define UNTITLED2_CACHEMANAGER_H

#include <string>

using namespace std;

class CacheManager {
public:
    /**
     * Check if solution exist's.
     * @param problem The problem.
     * @return true or false if solution exist's.
     */
    virtual bool solutionExists(string problem) = 0;

    /**
     * Getter for the solution from memory.
     * @param problem The problem to solve.
     * @return The solution as a string.
     */
    virtual std::string getSolution(string problem) = 0;

    /**
     * Save a pair of problem and solution.
     * @param problem The problem.
     * @param solution The solution.
     */
    virtual void saveSolution(string problem, string solution) = 0;
};


#endif //UNTITLED2_CACHEMANAGER_H
