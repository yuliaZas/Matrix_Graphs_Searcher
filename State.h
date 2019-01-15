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
    double pathCost;
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

    void setPrev(State* prev) {
        this->prevState = prev;

    }
    double getCost() const {
        return this->cost;
    }

    void setCost(double Cost) {
        this->cost = Cost;
    }

    T getState(){
        return this->state;
    }
    State<T> getPrev(){
        return *this->prevState;
    }
    void setPathCost(double newPathCost){
        this->pathCost = newPathCost;
    }
    double getPathCost(){
        return this->pathCost;
    }
};

template<class T>
class CMPstates{
public:
    bool operator()(const State<T> &s1,const State<T> &s2 )const{
        return s1.getCost() > s2.getCost();
    }
};


#endif //FLIGHT_SIMULATOR_STATE_H