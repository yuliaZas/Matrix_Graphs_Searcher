//
// Created by Yulia.
//

#ifndef UNTITLED2_MATRIXINTERPETER_H
#define UNTITLED2_MATRIXINTERPETER_H

#include <string>
#include <sstream>
#include <vector>

using namespace std;

/*Interpreter matrix from string with commas to int matrix*/
class MatrixInterpreter {
private:

public:
    /**
     * Interpreter string matrix with comma separators in line to math matrix in int
     * @param sMat the matrix to interpreter
     * @return the math matrix
     */
    vector<vector<int>> matrixInter(string sMat);
};


#endif //UNTITLED2_MATRIXINTERPETER_H
