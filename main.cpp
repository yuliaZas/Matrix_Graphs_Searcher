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
    int** mat = mi.matrixInter( "4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8\n4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4\n")
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