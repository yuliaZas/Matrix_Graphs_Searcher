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
    double priority;
    State<T> *prevState;
    //void setPriority(double prevPriority);

public:
    //State(T state, double cost);
    //void setPrev(State prev);
    bool equals(State s);
    //double getPriority();
    State<T>(){}

    State<T>(T state, double cost) {
        this->state = state;
        this->cost = cost;
        this->priority =std::numeric_limits<double>::infinity();
        this->prevState = NULL;
    }

    void setPrev(State prev) {
        this->prevState = &prev;
        State::setPriority(prev.priority);

    }
    double getPriority() {
        return this->priority;
    }

    void setPriority(double prevPriority) {
        this->priority = this->cost + prevPriority;
    }

    T getState(){
        return this->state;
    }
};




#endif //FLIGHT_SIMULATOR_STATE_H