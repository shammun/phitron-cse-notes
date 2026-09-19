// find() with PATH COMPRESSION - the third version, and the one used from here
// on. The parent array and the -1 marker are as in find_using_recursion.cpp.
//
// What changed: the recursion already visits every node between `node` and the
// leader, so on the way back down it re-points each of them straight at the
// leader. The tall chain is flattened as a side effect of asking the question.
//
// What it buys: the first find(4) still costs four steps, but afterwards 4, 5 and
// 3 all hang directly under 1, so every later find on them costs one step. Work
// done once is never repeated. Together with union by size (union.cpp) this makes
// find effectively constant time in practice - the O(logn) note below is the safe
// pessimistic figure.

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int par[1005];

int find(int node){ // O(logn)
    // Same stopping point: no parent means this node is the leader.
    if(par[node] == -1){
        return node;
    }
    // Ask upwards first...
    int leader = find(par[node]);
    // ...then shorten this node's own link before handing the answer back. This
    // single line is the whole optimisation. It is safe because re-pointing a node
    // at its own leader cannot change which group it belongs to.
    par[node] = leader;
    return leader;
}

int main(){
    memset(par, -1, sizeof(par));
    par[0] = 1;
    par[1] = -1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;

    // Before the call:  4 -> 5 -> 3 -> 1
    // After the call:   4 -> 1, 5 -> 1, 3 -> 1
    // The printed answer is still 1; what changed is the shape of the tree, which
    // this program does not print. A second find(4) would finish in one step.
    cout << find(4) << endl;

    return 0;
}