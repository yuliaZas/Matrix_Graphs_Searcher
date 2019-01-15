//
// Created by miri on 09/01/19.
//
#include <limits>
#include <vector>
#include <queue>
#include "matrixMaze.h"
#include "Searcher.h"
#include "BestFS.h"
using namespace std;
int main(){
//     State<int> s1(12,2);
//     State<int> s2(10,5);
//    State<int> s3(11,1);
//    State<int> s4(9,3);
//    s2.setPrev(&s1);
//    s3.setPrev(&s2);
//    s4.setPrev(&s3);
//    priority_queue<State<int>, vector<State<int>>, CMPstates<int>> pq;
//    pq.push(s1);
//    pq.push(s2);
vector<vector<int>> cost;
vector<int> v1 = {7,8,9};
    vector<int> v2 = {4,5,6};
    vector<int> v3 = {1,2,3};
    cost.insert(cost.begin(), v1);
    cost.insert(cost.begin(), v2);
    cost.insert(cost.begin(), v3);
matrixMaze maze(cost);
//maze.getFinalPath();
BestFS<std::pair<int, int>> bfs;
    bfs.search(&maze);
    return  0;
}