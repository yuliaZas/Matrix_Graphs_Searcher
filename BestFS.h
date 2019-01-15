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
    priority_queue<State<T>, vector<State<T>>, CMPstates<T>> open;
    priority_queue<State<T>, vector<State<T>>, CMPstates<T>> close;
    int numberOfNodes;
    vector<T> getFinalPath(ISearchable<T> searchable);
    int getFinalPathCost(ISearchable<T> searchable);
public:
    BestFS();
    solution<T> search(ISearchable<T> searchable);

};

template<class T>
BestFS<T>::BestFS() {
numberOfNodes = 0;
}

template<class T>
solution<T> BestFS<T>::search(ISearchable<T> searchable) {
    // initialize a state n for current state
    State<T> n;
    // initialize a vector of states s for n's successors
    vector<State<T>> s;
    // push the initial state to the queue open
    open.push(searchable.getInitialState());
    while(!open.empty()){
        // put in n the state with the lowest priority in open
        n = pop(open);
        // if the algorithm got to the goal state
        if (n == searchable.getGoalState())
        {
            // put the path from the start to the goal in solution and finish
            solution<T> solution(searchable.getFinalPath());
            return solution;
        }
        else{
            // place in s, n's successors
            s = searchable.getAllPossibleStates(n);
            // foe each successor s
            for(State<T> S: s){
                // if s in not in open and not in close
                if(!isInQueue(open,S) && !isInQueue(close,S)){
                    // save that we came to s from n
                    S.setPrev(n);
                    open.push(S);
                }
                else{

                }
            }
        }
    }
    // return a solution which contains the final path
    solution<T> solution(searchable.getFinalPath());
    return solution;
}

template<class T>
vector<T> BestFS<T>::getFinalPath(ISearchable<T> searchable) {
    return vector<T>();
}


#endif //MILE_STONE2_BESTFS_H
