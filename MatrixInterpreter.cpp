//
// Created by Yulia.
//

#include "MatrixInterpreter.h"

int** MatrixInterpreter::matrixInter(string sMat) {
    int** matrix;
    vector<vector<int>> matrixRows;

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
            matrixRows.push_back(parsedRow);
        }
    }

    int i = 0, j = 0;
    for (auto it1 = matrixRows.begin(); it1 != matrixRows.end() ; ++it1) {
        for (auto it2 = matrixRows.begin(); it2 != matrixRows.end() ; ++it2) {
            matrix[i][j] = matrixRows.at(i).at(j);
            ++j;
        }
        ++i;
        j = 0;
    }

    return matrix;
}