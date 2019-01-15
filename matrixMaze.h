//
// Created by miri on 07/01/19.
//

#ifndef FLIGHT_SIMULATOR_MATRIXMAZE_H
#define FLIGHT_SIMULATOR_MATRIXMAZE_H


#include "ISearchable.h"
#include "State.h"
#include <string>
#include <limits>
#include <vector>

using namespace std;
class matrixMaze:
        public ISearchable<pair<int,int>> {
private:
    vector<vector<State<pair<int,int>>*>> maze;
    //int mazeCost[SIZE][SIZE];
    State<pair<int,int>>* initialState;
    State<pair<int,int>>* goalState;
public:
    matrixMaze(vector<vector<int>> Cost);
    matrixMaze(vector<vector<int>> Cost,State<pair<int,int>>* initialState, State<pair<int,int>>* goalState);
    State<pair<int,int>>* getInitialState();
    State<pair<int,int>>* getGoalState();
    std::vector<State<pair<int,int>>*> getAllPossibleStates(State<pair<int,int>>* s);
    std::vector<State<std::pair<int, int>>*> getFinalPath();
    int getFinalPathCost();
    bool pathIsBetter(State<std::pair<int, int>>* currentState, State<std::pair<int, int>>* maybeNewPrev);
};


#endif //FLIGHT_SIMULATOR_MATRIXMAZE_H