//
// Created by miri on 12/01/19.
//

#ifndef MILE_STONE2_SOLUTION_H
#define MILE_STONE2_SOLUTION_H

#include <vector>
template <class T>
class solution {
private:
    std::vector<T> solutionVector;
public:
    solution(std::vector<T> solVec ){
        this->solutionVector = solVec;
    }
    solution(){
        this->solutionVector = new std::vector<T>;
    }
    std::vector<T> getSolution(){
        return this->solutionVector;
    }
    void setSolution(std::vector<T> solution){
        this->solutionVector = solution;
    }
};


#endif //MILE_STONE2_SOLUTION_H
