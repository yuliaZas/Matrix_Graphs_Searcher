//
// Created by miri on 07/01/19.
//

#ifndef FLIGHT_SIMULATOR_STATE_H
#define FLIGHT_SIMULATOR_STATE_H

#include <string>
#include <limits>
template <class T>
class State {
private:
    T state;
    double cost;
    State<T> *prevState;

public:
//    bool operator <(const State<T>  &s)const {
//        return this->cost > s->cost;
//    }
    bool equals(State s);
    State<T>(){}

    State<T>(T state, double cost) {
        this->state = state;
        this->cost = cost;
        this->prevState = NULL;
    }

    void setPrev(State prev) {
        this->prevState = &prev;
        this->cost = this->cost + prev.cost;

    }
    double getCost() {
        return this->cost;
    }

    void setCost(double Cost) {
        this->cost = Cost;
    }

    T getState(){
        return this->state;
    }

};




#endif //FLIGHT_SIMULATOR_STATE_H