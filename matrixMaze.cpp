//
// Created by miri on 07/01/19.
//

#include "matrixMaze.h"

matrixMaze::matrixMaze(vector<vector<int>> Cost){
    for (int i = 0;i < SIZE;i++){
        for (int j = 0;j < SIZE;j++){
            // place in the member maze cost the cost of this node
            //this->mazeCost[i][j] = Cost[i][j];
            // creat new state to match this node and place it in the maze matrix
            State<pair<int,int>> s(pair<int,int>(i,j), Cost[i][j]);
            s.setPathCost(0);
            this->maze[i][j] = s;

        }
    }
    this->initialState = this->maze[0][0];
    this->goalState = this->maze[SIZE - 1][SIZE - 1];
}
matrixMaze::matrixMaze(vector<vector<int>> Cost, State <pair<int, int>> initialState, State <pair<int, int>> goalState) {
    for (int i = 0;i < SIZE;i++){
        for (int j = 0;j < SIZE;j++){
            //this->mazeCost[i][j] = Cost[i][j];
            State<pair<int,int>> s(pair<int,int>(i,j), Cost[i][j]);
            s.setPathCost(0);
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
    if (this->maze[i+1][j].getCost() != std::numeric_limits<int>::infinity() && i+1 < SIZE){
        bros.insert(bros.end(),this->maze[i+1][j]);
    }
    if (this->maze[i-1][j].getCost() != std::numeric_limits<int>::infinity() && i-1 >= 0){
        bros.insert(bros.end(),this->maze[i-1][j]);
    }
    if (this->maze[i][j+1].getCost() != std::numeric_limits<int>::infinity() && j+1 < SIZE){
        bros.insert(bros.end(),this->maze[i][j+1]);
    }
    if (this->maze[i][j-1].getCost() != std::numeric_limits<int>::infinity() && j-1 >= 0){
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
    return this->getGoalState().getPathCost();
}

bool matrixMaze::pathIsBetter(State<std::pair<int, int>> currentState, State<std::pair<int, int>> maybeNewPrev) {
    return currentState.getPathCost() > maybeNewPrev.getCost() + this->maze[currentState.getState().first][currentState.getState().second].getCost();
}

