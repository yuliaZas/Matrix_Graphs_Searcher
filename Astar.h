//
// Created by miri on 16/01/19.
//

#ifndef MILE_STONE2_ASTAR_H
#define MILE_STONE2_ASTAR_H

#include "Searcher.h"
template <class T>
class Astar: public Searcher<T> {
private:
    priority_queue<State<T>*, vector<State<T>*>, CMPhuristics<T>> open;
    priority_queue<State<T>*, vector<State<T>*>, CMPhuristics<T>> close;
    int numberOfNodes;
public:
    Astar(){
        this->numberOfNodes = 0;
    }
    virtual std::vector<State<T>*> search(ISearchable<T>* searchable){
        State<T>* currentState;
        vector<State<T>*> succsseors;
        int new_cost;
        // push the start state to open
        open.push(searchable->getInitialState());
        while(!open.empty()){
            // pop from the queue the state with the best priority
            currentState = this->pop(&open, &this->numberOfNodes);
            close.push(currentState);
            // put in successesors all the possible states to go to from the current state
            succsseors = searchable->getAllPossibleStates(currentState);
            for(State<T>* s: succsseors) {
                // if this state is the goal state, finish
                if (s->equals(*searchable->getGoalState())){
                    s->setPrev(currentState);
                    return searchable->getFinalPath();
                }else{
                    // calculate the cost that could be
                    new_cost = currentState->getPathCost() + s->getCost();
                    // if its a new node or the new cost is better then the previews cost
                    if ((!this->isInQueue(&open, s) && !this->isInQueue(&close, s)) || new_cost < s->getPathCost()){
                        s->setPathCost(new_cost);
                        s->setPriority(searchable->huristics(s, searchable->getGoalState()) + new_cost);
                        if(this->isInQueue(&open, s))
                        {
                            this->setPriority(&open, s);
                        }else{
                            open.push(s);
                        }
                        s->setPrev(currentState);
                    }
                }
            }
        }
        return searchable->getFinalPath();
    }
    int getNumberOfNodes(){
        return this->numberOfNodes;
    }
};


#endif //MILE_STONE2_ASTAR_H
