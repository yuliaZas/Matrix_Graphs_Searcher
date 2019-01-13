//
// Created by miri on 12/01/19.
//

#ifndef MILE_STONE2_ISEARCHER_H
#define MILE_STONE2_ISEARCHER_H

#include "ISearchable.h"
#include "solution.h"
#include <vector>

template <class T>
class ISearcher {
public:
    solution<std::vector<T>> search(ISearchable<T> searchable);
    int getNumberOfNodes();

};


#endif //MILE_STONE2_ISEARCHER_H
