//
// Created by miri on 09/01/19.
//
#include <limits>
#include <vector>
#include <queue>
#include "matrixMaze.h"
#include "Searcher.h"
#include "MatrixInterpreter.h"
#include "Astar.h"
#include "BestFS.h"
using namespace std;
int main(){
    MatrixInterpreter mi;
    vector<vector<int>> mat = mi.matrixInter(" 4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8\n"
                                             " 4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4\n"
                                             " 4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7\n"
                                             " 3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7\n"
                                             " 0, 3, 7, 3, 7,10, 4, 8, 9, 1, 1\n"
                                             " 7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9\n"
                                             " 6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8\n"
                                             "10, 8, 0, 2, 3, 8, 0,10,10, 2, 7\n"
                                             " 5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1\n"
                                             " 7, 7, 5,10, 8,10, 1, 6, 9, 9, 1\n"
                                             " 5,10, 1,10, 7, 7, 3,10, 8, 0, 6");
    int i = mat.at(7).at(5);
    /*
     State<int> s1(12,2);
     State<int> s2(12,5);
    priority_queue<State<int>, vector<State<int>>, CMPstates<int>> pq;
    pq.push(s1);
    pq.push(s2);
     */
    matrixMaze maze(mat);
    Astar<pair<int,int>> star;
    star.search(&maze);
    BestFS<pair<int, int>> best;
    best.search(&maze);
    return  0;
}