//
// Created by Yulia.
//

#include "StringReverser.h"

string StringReverser::problemSolver(const string problem) {
    string solution = problem;
    reverse(solution.begin(),solution.end());
    return solution;
}