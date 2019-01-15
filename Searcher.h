//
// Created by miri on 12/01/19.
//

#ifndef MILE_STONE2_SEARCHER_H
#define MILE_STONE2_SEARCHER_H


#include "ISearchable.h"
#include "solution.h"
#include "ISearcher.h"
#include <queue>

using namespace std;

template <class T>
class Searcher : public ISearcher<T> {

public:

virtual std::vector<State<T>> search(ISearchable<T>* searchable)=0;

virtual void setPriority(priority_queue<State<T>, vector<State<T>>, CMPstates<T>> *pq, double newPriorty,
                              State<T> state) {
    priority_queue<State<T>, vector<State<T>>, CMPstates<T>> tempQueue;
    State<T> tempState;
    while(!pq->empty()){
        tempState = pq->top();
        pq->pop();
        if (tempState.equals(state)){
            tempState.setPathCost(newPriorty);
        }
        tempQueue.push(tempState);
    }
    pq->swap(tempQueue);
}

virtual bool isInQueue(priority_queue<State<T>, vector<State<T>>, CMPstates<T>> *pq, State<T> state) {
    bool isInQueue = false;
    priority_queue<State<T>, vector<State<T>>, CMPstates<T>> tempQueue;
    State<T> tempState;
    while(!pq->empty()){
        tempState = pq->top();
        pq->pop();
        if (tempState.equals(state)){
            isInQueue = true;
        }
        tempQueue.push(tempState);
    }
    pq->swap(tempQueue);
    return isInQueue;

}

virtual State<T> pop(priority_queue<State<T>, vector<State<T>>, CMPstates<T>> *pq, int *numberOfNodes) {
    State<T> topState = pq->top();
    pq->pop();
    ++(*numberOfNodes);
    return topState;
}

};

#endif //MILE_STONE2_SEARCHER_H
