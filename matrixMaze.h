//
// Created by miri on 07/01/19.
//

#ifndef FLIGHT_SIMULATOR_MATRIXMAZE_H
#define FLIGHT_SIMULATOR_MATRIXMAZE_H


#include "ISearchable.h"
#include "State.h"
#include <string>
#include <limits>
// maze size (n)
const int SIZE = 10;
using namespace std;
class matrixMaze:
        public ISearchable<pair<int,int>> {
private:
    State<pair<int,int>> maze[SIZE][SIZE];
    int mazeCost[SIZE][SIZE];
    State<pair<int,int>> initialState;
    State<pair<int,int>> goalState;
public:
    matrixMaze(int Cost[SIZE][SIZE]);
    matrixMaze(int Cost[SIZE][SIZE],State<pair<int,int>> initialState, State<pair<int,int>> goalState);
    State<pair<int,int>> getInitialState();
    State<pair<int,int>> getGoalState();
    std::vector<State<pair<int,int>>> getAllPossibleStates(State<pair<int,int>> s);

};


#endif //FLIGHT_SIMULATOR_MATRIXMAZE_H