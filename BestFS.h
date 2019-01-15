//
// Created by miri on 14/01/19.
//

#ifndef MILE_STONE2_BESTFS_H
#define MILE_STONE2_BESTFS_H

#include "Searcher.h"
template <class T>
class BestFS :
        public Searcher<T>{
private:
    priority_queue<State<T>*, vector<State<T>*>, CMPstates<T>> open;
    priority_queue<State<T>*, vector<State<T>*>, CMPstates<T>> close;
    int numberOfNodes;

    int getFinalPathCost(ISearchable<T>* searchable);
public:

BestFS() {
    numberOfNodes = 0;
}

virtual std::vector<State<T>*> search(ISearchable<T>* searchable) {
    // initialize a state n for current state
    State<T>* n;
    // initialize a vector of states s for n's successors
    vector<State<T>*> s;
    // push the initial state to the queue open
    open.push(searchable->getInitialState());
    while(!open.empty()){
        // put in n the state with the lowest priority in open
        n = this->pop(&open, &this->numberOfNodes);
        close.push(n);
        // if the algorithm got to the goal state
        if (n->equals(*searchable->getGoalState()))
        {
            // put the path from the start to the goal in solution and finish
            return searchable->getFinalPath();
        }
        else {
            // place in s, n's successors
            s = searchable->getAllPossibleStates(n);
            // foe each successor s
            for(State<T>* S: s){
                // if s in not in open and not in close
                if(!this->isInQueue(&this->open,S) && !this->isInQueue(&this->close,S)){
                    // save that we came to s from n
                    S->setPrev(n);
                    // change the path cost of S
                    S->setPathCost(n->getPathCost()+S->getCost());
                    this->open.push(S);
                }
                else{
                    if(searchable->pathIsBetter(S,n)){
                        if(this->isInQueue(&this->open,S)){
                            this->setPriority(&this->open, S->getCost() + n->getPathCost(), S);
                        }
                        else{
                            this->open.push(S);
                        }
                    }
                }
            }
        }
    }
    // return a solution which contains the final path
    return searchable->getFinalPath();
}

vector<T> getFinalPath(ISearchable<T>* searchable) {
    return vector<T>();
}
int getNumberOfNodes(){
    return this->numberOfNodes;
}
};

#endif //MILE_STONE2_BESTFS_H
