//
// Created by Yulia.
//

#ifndef UNTITLED2_SOLVERTOSEARCHERBLE_H
#define UNTITLED2_SOLVERTOSEARCHERBLE_H

#include "Solver.h"
#include "ISearcher.h"
#include "ISearchable.h"

using namespace std;

/**
 * This class is makes solver searchable.
 */

class SolverToSearchable :
        public Solver<ISearchable<pair<int,int>>*,State<pair<int,int>>*> {

};


#endif //UNTITLED2_SOLVERTOSEARCHERBLE_H
