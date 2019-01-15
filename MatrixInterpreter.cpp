//
// Created by Yulia.
//

#include "MatrixInterpreter.h"

vector<vector<int>> MatrixInterpreter::matrixInter(string sMat) {


    vector<vector<int>> matrix;

    stringstream linesP;
    stringstream singleLine;
    linesP.str(sMat);

    while (linesP.good()){
        vector<int> parsedRow;
        string tempL;
        getline(linesP, tempL, '\n');

        if (!tempL.empty()) {
            singleLine.str(tempL);

            while (singleLine.good()) {
                string tempV;
                getline(singleLine, tempV, ',');
                parsedRow.push_back(stoi(tempV));
            }
            singleLine.clear();
            matrix.push_back(parsedRow);
        }
    }

    return matrix;
}