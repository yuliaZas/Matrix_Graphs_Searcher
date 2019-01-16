//
// Created by Yulia.
//

#include "SearchableSolver.h"

SearchableSolver::SearchableSolver(ISearcher<pair<int, int>> *searcher1) : searcher(searcher1) {}

vector<State<pair<int, int>>*> SearchableSolver::solveProblem(ISearchable<pair<int, int>>* searchable) {
    return this->searcher->search(searchable);
}
