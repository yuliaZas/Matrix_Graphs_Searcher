//
// Created by miri on 07/01/19.
//

#include "State.h"




template<class T>
bool State<T>::equals(State s) {

    return false;
}




template<>
bool State<int>::equals(State<int> s) {

    return this->state == s.state;
}
template<>
bool State<double >::equals(State<double > s) {

    return this->state == s.state;
}
template<>
bool State<std::string>::equals(State<std::string> s) {

    return this->state == s.state;
}