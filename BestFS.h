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

    return search(searchable);
}

template<class T>
vector<T> BestFS<T>::getFinalPath(ISearchable<T> searchable) {
    return vector<T>();
}


#endif //MILE_STONE2_BESTFS_H
