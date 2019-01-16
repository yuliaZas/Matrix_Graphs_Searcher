//
// Created by Yulia.
//

#ifndef UNTITLED2_SEARCHABLESOLVER_H
#define UNTITLED2_SEARCHABLESOLVER_H

#include "Solver.h"
#include "ISearcher.h"
#include "ISearchable.h"

using namespace std;

/**
 * This class is makes solver searchable.
 */
class SearchableSolver :
        public Solver<ISearchable<pair<int, int>>*,vector<State<pair<int, int>>*>> {
private:
    ISearcher<pair<int,int>> *searcher;
public:
    /**
    * CTOR
    * @param searcher the search method to solve.
    */
    SearchableSolver(ISearcher<pair<int, int>> *searcher1);

    /**
     * Solves the problem by searching with the provided method.
     * @param searchable - The structure we need to search in.
     * @return directions to solution.
     */
    vector<State<pair<int, int>>*> solveProblem(ISearchable<pair<int, int>>* searchable) override;
};


#endif //UNTITLED2_SEARCHABLESOLVER_H
