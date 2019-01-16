//
// Created by Yulia.
//

#ifndef UNTITLED2_SOLVER_H
#define UNTITLED2_SOLVER_H

/**
 * Defines a Solver.
 * @tparam Problem The problem.
 * @tparam Solution The solution.
 */
template <class Problem, class Solution>

class Solver {
public:
    /**
     * The solver method.
     * @return Solution.
     */
    virtual Solution solveProblem(Problem) = 0;

    /**
     * DTOR.
     */
    virtual ~Solver(){};
};


#endif //UNTITLED2_SOLVER_H
