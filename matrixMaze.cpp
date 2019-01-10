//
// Created by miri on 07/01/19.
//

#include "matrixMaze.h"

matrixMaze::matrixMaze(int Cost[SIZE][SIZE]){
    for (int i = 0;i < SIZE;i++){
        for (int j = 0;j < SIZE;j++){
            this->mazeCost[i][j] = Cost[i][j];
            State<pair<int,int>> s(pair<int,int>(i,j), this->mazeCost[i][j]);
            this->maze[i][j] = s;
        }
    }
}

State<pair<int,int>> matrixMaze::getInitialState() {
    return this->maze[0][0];
}

State<pair<int,int>> matrixMaze::getGoalState() {
    return this->maze[SIZE - 1][SIZE - 1];
}

std::vector<State<pair<int,int>>> matrixMaze::getAllPossibleStates(State<pair<int,int>> s) {
    // prepare an empty list of states to insert all the options to.
    vector<State<pair<int,int>>> bros = vector<State<pair<int,int>>>();
    // for readability place line and row of s in i and j.
    int i = s.getState().first;
    int j = s.getState().second;
    


    return bros;
}