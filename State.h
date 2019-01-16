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
    // for A*
    double priority;
    State<T> *prevState;

public:

    bool equals(State s);
    State<T>(){}

    State<T>(T state, double cost) {
        this->state = state;
        this->cost = cost;
        this->priority = 0;
        this->prevState = NULL;
    }


    double getPriority() const{
        return priority;
    }


    void setPriority(double priority) {
        State::priority = priority;
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
    State<T>* getPrev(){
        return this->prevState;
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
    bool operator()(const State<T>* s1,const State<T>* s2 )const{
        return s1->getCost() > s2->getCost();
    }
};

template<class T>
class CMPhuristics{
public:
    bool operator()(const State<T>* s1,const State<T>* s2 )const{
        return s1->getPriority() > s2->getPriority();
    }
};


#endif //FLIGHT_SIMULATOR_STATE_H