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
#include "DFS.h"
#include "BFS.h"
using namespace std;
int main(){
    MatrixInterpreter mi;
    vector<vector<int>> mat = mi.matrixInter(" 3, 7, 8\n"
                                             " 7, 8, 4\n"
                                             " 8, 0, 6");
    /*
     State<int> s1(12,2);
     State<int> s2(12,5);
    priority_queue<State<int>, vector<State<int>>, CMPstates<int>> pq;
    pq.push(s1);
    pq.push(s2);
     */
    matrixMaze maze(mat);
//    Astar<pair<int,int>> star;
//    star.search(&maze);
//    BestFS<pair<int, int>> best;
//    best.search(&maze);
//    DFS<pair<int,int>> dfs;
//    dfs.search(&maze);
    DFS<pair<int,int>> dfs;
    dfs.search(&maze);
    return  0;
}