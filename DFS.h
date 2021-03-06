//
// Created by miri on 16/01/19.
//

#ifndef MILE_STONE2_DFS_H
#define MILE_STONE2_DFS_H

#include "Searcher.h"

template <class T>
class DFS :public Searcher<T>{
private:

    stack<State<T>*> open;
    stack<State<T>*> close;
    int numberOfNodes;

    int getFinalPathCost(ISearchable<T>* searchable);
public:
    DFS(){
        numberOfNodes = 0;
    }
    int getNumberOfNodes(){
        return this->numberOfNodes;
    }
    std::vector<State<T>*> search(ISearchable<T>* searchable){
        State<T>* currentState;
        vector<State<T>*> moves;
        open.push(searchable->getInitialState());
        while(!open.empty()){
            currentState = this->pop(&open, &this->numberOfNodes);
            close.push(currentState);
            if(currentState->equals(*searchable->getGoalState())){
                return searchable->getFinalPath();
            }

                moves = searchable->getAllPossibleStates(currentState);
                for(State<T>* move:moves){
                    if(!this->isInQueue(&close, move)&& !this->isInQueue(&open, move)){
                        move->setPrev(currentState);
                        move->setPathCost(currentState->getPathCost() + move->getCost());
                        open.push(move);
                    }

                }

        }
    }
};


#endif //MILE_STONE2_DFS_H
