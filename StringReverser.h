//
// Created by Yulia.
//

#ifndef UNTITLED2_STRINGREVERSER_H
#define UNTITLED2_STRINGREVERSER_H

#include "Solver.h"
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

/*This solver that gets a string and returns the reverse of it.*/

class StringReverser : public Solver<string,string> {
public:

    /**
     * Reverse a string.
     * @param problem The string to reverse.
     * @return the reversed string.
     */
    string problemSolver(const string problem);
};


#endif //UNTITLED2_STRINGREVERSER_H
