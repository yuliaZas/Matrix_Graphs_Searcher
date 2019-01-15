//
// Created by miri on 07/01/19.
//

#ifndef FLIGHT_SIMULATOR_ISEARCHABLE_H
#define FLIGHT_SIMULATOR_ISEARCHABLE_H

#include "State.h"
#include <vector>

template <class T>
class ISearchable {

public:
    virtual State<T> getInitialState() = 0;
    virtual State<T> getGoalState() = 0;
    virtual std::vector<State<T>> getAllPossibleStates(State<T> s) = 0;
    virtual std::vector<State<T>> getFinalPath() = 0;
    virtual int getFinalPathCost() = 0;
    virtual bool pathIsBetter(State<T> currentState, State<T> maybeNewPrev)= 0;
};




#endif //FLIGHT_SIMULATOR_ISEARCHABLE_H