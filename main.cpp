//
// Created by miri on 09/01/19.
//
#include <limits>
#include <vector>
#include <queue>
#include "matrixMaze.h"
#include "Searcher.h"
#include "MatrixInterpreter.h"
using namespace std;
int main(){
    MatrixInterpreter mi;
    vector<vector<int>> mat = mi.matrixInter( "4, 2, 9, 5, 7\n4, 0,10, 8, 1\n");
    int i = 0;
    /*
     State<int> s1(12,2);
     State<int> s2(12,5);
    priority_queue<State<int>, vector<State<int>>, CMPstates<int>> pq;
    pq.push(s1);
    pq.push(s2);
     */
    return  0;
}