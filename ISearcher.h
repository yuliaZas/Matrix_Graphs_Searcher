//
// Created by miri on 12/01/19.
//

#ifndef MILE_STONE2_ISEARCHER_H
#define MILE_STONE2_ISEARCHER_H

#include "ISearchable.h"
#include <vector>

template <class T>
class ISearcher {
public:
    virtual std::vector<State<T>*> search(ISearchable<T>* searchable) = 0;
    virtual int getNumberOfNodes() = 0;

};


#endif //MILE_STONE2_ISEARCHER_H
