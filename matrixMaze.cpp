//
// Created by miri on 07/01/19.
//

#include "matrixMaze.h"

matrixMaze::matrixMaze(vector<vector<int>> Cost){
    this->maze = vector<vector<State<pair<int, int>>*>>();
    for (int i = 0;i < Cost.size();i++){
        vector<State<pair<int, int>>*> vector1;
        for (int j = 0;j < Cost[i].size();j++){
            // place in the member maze cost the cost of this node
            //this->mazeCost[i][j] = Cost[i][j];
            // creat new state to match this node and place it in the maze matrix
            State<pair<int,int>> *s = new State<pair<int, int>>(pair<int,int>(i,j), Cost[i][j]);
            s->setPathCost(s->getCost());
            vector1.insert(vector1.end(), s);


        }
        this->maze.insert(this->maze.end(), vector1);
    }
    this->initialState = this->maze[0][0];
    this->goalState = this->maze[this->maze.size()-1][this->maze.size()-1];
}
matrixMaze::matrixMaze(vector<vector<int>> Cost, State <pair<int, int>>* _initialState, State <pair<int, int>>* _goalState) {
    this->maze = vector<vector<State<pair<int, int>>*>>();
    for (int i = 0;i < Cost.size();i++){
        vector<State<pair<int, int>>*> vector1;
        for (int j = 0;j < Cost[i].size();j++){
            // place in the member maze cost the cost of this node
            //this->mazeCost[i][j] = Cost[i][j];
            // creat new state to match this node and place it in the maze matrix
            State<pair<int,int>> *s = new State<pair<int, int>>(pair<int,int>(i,j), Cost[i][j]);
            s->setPathCost(s->getCost());
            vector1.insert(vector1.end(), s);


        }
        this->maze.insert(this->maze.end(), vector1);
    }
    this->initialState = this->maze[_initialState->getState().first][_initialState->getState().second];

    this->goalState = this->maze[_goalState->getState().first][_goalState->getState().second];
}
State<pair<int,int>>* matrixMaze::getInitialState() {
    return this->initialState;
}

State<pair<int,int>>* matrixMaze::getGoalState() {
    return this->goalState;
}

std::vector<State<pair<int,int>>*>matrixMaze:: getAllPossibleStates(State<pair<int,int>>* s){
    // prepare an empty list of states to insert all the options to.
    vector<State<pair<int,int>>*> bros = vector<State<pair<int,int>>*>();
    // for readability place line and row of s in i and j.
    int i = s->getState().first;
    int j = s->getState().second;
    // check if the closest cells are not walls and if not add then to the possible options
    if(i+1 < this->maze.size()){
        if (this->maze[i+1][j]->getCost() != -1){
            bros.insert(bros.end(),this->maze[i+1][j]);
        }
    }
    if(i-1 >= 0){
        if (this->maze[i-1][j]->getCost() != -1 ){
            bros.insert(bros.end(),this->maze[i-1][j]);
        }
    }
    if(j+1 < this->maze.size()){
        if (this->maze[i][j+1]->getCost() != -1){
            bros.insert(bros.end(),this->maze[i][j+1]);
        }
    }
    if(j-1 >= 0){
        if (this->maze[i][j-1]->getCost() != -1){
            bros.insert(bros.end(),this->maze[i][j-1]);
        }
    }

    return bros;
}

std::vector<State<std::pair<int, int>>*>matrixMaze:: getFinalPath() {
    // initialize a new vector to hold the final path
    std::vector<State<std::pair<int, int>>*> path;
    // initialize the state with the last state
    State<std::pair<int, int>>* currState = this->getGoalState();
    // go thought all the states in the path
    while(currState->getState() != this->getInitialState()->getState()){
        // insert the state to the vector
        path.insert(path.begin(), currState);
        currState = currState->getPrev();
    }
    return path;
}


int matrixMaze::getFinalPathCost() {
    return this->getGoalState()->getPathCost();
}

bool matrixMaze::pathIsBetter(State<std::pair<int, int>>* currentState, State<std::pair<int, int>>* maybeNewPrev) {
    return currentState->getPathCost() > maybeNewPrev->getPathCost() + currentState->getCost();
}
// calculate the huristics value for A* algo
int matrixMaze::huristics(State<pair<int,int>>* currentState, State<pair<int,int>>* goalState){
    return abs(currentState->getState().first - goalState->getState().first) + abs(currentState->getState().second - goalState->getState().second);
}

