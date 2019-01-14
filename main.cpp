//
// Created by miri on 09/01/19.
//
#include <limits>
#include <vector>
#include <queue>
#include "matrixMaze.h"
#include "Searcher.h"
using namespace std;
int main(){
     State<int> s1(12,2);
     State<int> s2(12,5);
    priority_queue<State<int>, vector<State<int>>, CMPstates<int>> pq;
    pq.push(s1);
    pq.push(s2);
    return  0;
}