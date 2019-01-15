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
    this->initialState = this->maze[0][0];
    this->goalState = this->maze[SIZE - 1][SIZE - 1];
}
matrixMaze::matrixMaze(int Cost[SIZE][SIZE], State <pair<int, int>> initialState, State <pair<int, int>> goalState) {
    for (int i = 0;i < SIZE;i++){
        for (int j = 0;j < SIZE;j++){
            this->mazeCost[i][j] = Cost[i][j];
            State<pair<int,int>> s(pair<int,int>(i,j), this->mazeCost[i][j]);
            this->maze[i][j] = s;
        }
    }
    this->initialState = initialState;
    this->goalState = goalState;
}
State<pair<int,int>> matrixMaze::getInitialState() {
    return this->initialState;
}

State<pair<int,int>> matrixMaze::getGoalState() {
    return this->goalState;
}

std::vector<State<pair<int,int>>> matrixMaze::getAllPossibleStates(State<pair<int,int>> s) {
    // prepare an empty list of states to insert all the options to.
    vector<State<pair<int,int>>> bros = vector<State<pair<int,int>>>();
    // for readability place line and row of s in i and j.
    int i = s.getState().first;
    int j = s.getState().second;
    // check if the closest cells are not walls and if not add then to the possible options
    if (this->mazeCost[i+1][j] != std::numeric_limits<int>::infinity() && i+1 < SIZE){
        bros.insert(bros.end(),this->maze[i+1][j]);
    }
    if (this->mazeCost[i-1][j] != std::numeric_limits<int>::infinity() && i-1 > 0){
        bros.insert(bros.end(),this->maze[i-1][j]);
    }
    if (this->mazeCost[i][j+1] != std::numeric_limits<int>::infinity() && j+1 < SIZE){
        bros.insert(bros.end(),this->maze[i][j+1]);
    }
    if (this->mazeCost[i][j-1] != std::numeric_limits<int>::infinity() && j-1 > 0){
        bros.insert(bros.end(),this->maze[i][j-1]);
    }
    return bros;
}

std::vector<State<std::pair<int, int>>>matrixMaze:: getFinalPath() {
    // initialize a new vector to hold the final path
    std::vector<State<std::pair<int, int>>> path;
    // initialize the state with the last state
    State<std::pair<int, int>> currState = this->getGoalState();
    // go thought all the states in the path
    while(currState.getState() != this->getInitialState().getState()){
        // insert the state to the vector
        path.insert(path.begin(), currState);
        currState = currState.getPrev();
    }
    return path;
}


int matrixMaze::getFinalPathCost() {
    return this->getGoalState().getCost();
}

