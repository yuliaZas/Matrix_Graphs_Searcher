//
// Created by Yulia.
//

#ifndef UNTITLED2_SOLVER_H
#define UNTITLED2_SOLVER_H

/**
 * Define's a Solver.
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
     * Destructor.
     */
    virtual ~Solver(){};
};


#endif //UNTITLED2_SOLVER_H
