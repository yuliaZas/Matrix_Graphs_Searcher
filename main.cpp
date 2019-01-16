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
    vector<vector<int>> mat = mi.matrixInter("  8, 0, 8, 6\n"
                                             " 4,10, 2, 3\n"
                                             " 1, 5, 8, 9\n"
                                             " 8, 6, 2, 4");
    vector<vector<int>> mat2 = mi.matrixInter(" 10, 1, 7\n"
                                             "  6, 6, 9\n"
                                             " 9, 6,4");
    vector<vector<int>> mat3 = mi.matrixInter(" 10, 7, 7\n"
                                              "  2, 3, 5\n"
                                              " 7,10, 8");
    vector<vector<int>> mat4 = mi.matrixInter("  7, 9, 4, 3, 7\n"
                                              " 6, 6, 4,-1, 3\n"
                                              " 9, 0, 0, 5, 9\n"
                                              " 1, 7, 4, 2, 9\n"
                                              " 0, 6, 3, 6, 7");
    vector<vector<int>> mat5 = mi.matrixInter("   0,10, 8,-1, 1\n"
                                              "2, 3, 5, 0, 6\n"
                                              " 8, 6,-1, 4, 0\n"
                                              " 1, 9,10, 5, 7\n"
                                              "8, 0, 9, 1, 9");
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
//    BestFS<pair<int, int>> best;
//   best.search(&maze);
//    DFS<pair<int,int>> dfs;
//    dfs.search(&maze);
//    BFS<pair<int,int>> dfs;
//    dfs.search(&maze);
    return  0;
}