// The same find() as find_using_recursion.cpp, written as a loop instead.
// The parent array, the -1 marker and the hand-built group are all unchanged -
// see find_using_recursion.cpp for what they mean.
//
// What the change buys: no recursion means no call stack. The recursive version
// keeps one stack frame per step, so a chain of a million nodes can overflow the
// stack; this one uses a single variable however tall the tree is. Space drops
// from O(height) to O(1). The number of steps, and so the running time, is the
// same.

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int par[1005];

// Keep stepping to the parent while there is one. The moment par[node] is -1 we
// are standing on the leader, so node itself is the answer.
// `node` is a copy of the argument, so moving it does not disturb the caller.
int find(int node){
    while(par[node] != -1){
        node = par[node];
    }
    return node;
}

int main(){
    memset(par, -1, sizeof(par));
    par[0] = 1;
    par[1] = -1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;

    // Same tree, same walk 4 -> 5 -> 3 -> 1, same answer: 1.
    // Notice that neither this version nor the recursive one changes the tree,
    // so the next find(4) would do all four steps again. find_optimized.cpp fixes
    // exactly that.
    cout << find(4) << endl;

    return 0;
}