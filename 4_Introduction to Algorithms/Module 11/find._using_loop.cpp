// The same find() as find_using_recursion.cpp, written as a loop instead.
// The parent array, the -1 marker and the hand-built group are all unchanged:
// par[x] is the node above x in its group, and par[x] == -1 means x has
// nothing above it, so x is the group's LEADER. Two nodes are in the same group
// exactly when climbing from each of them ends at the same leader.
//
// What the change buys: no recursion means no call stack. The recursive version
// keeps one stack frame per step, so a chain of a million nodes can overflow the
// stack; this one uses a single variable however tall the tree is. Space drops
// from O(height) to O(1). The number of steps, and so the running time, is the
// same.

#include <iostream>   // cout, endl
#include <queue>      // not used here
#include <cstring>    // memset
#include <vector>     // not used here
using namespace std;  // write cout instead of std::cout
int par[1005];        // par[x] = parent of x, or -1 if x is a leader

// Keep stepping to the parent while there is one. The moment par[node] is -1 we
// are standing on the leader, so node itself is the answer.
// `node` is a copy of the argument, so moving it does not disturb the caller.
int find(int node){
    while(par[node] != -1){   // node still has a parent above it
        node = par[node];     // climb one step
    }
    return node;              // no parent: this is the leader
}

int main(){
    // memset fills every BYTE of par with 0xFF; four such bytes make the int
    // -1, so every node starts as its own leader.
    memset(par, -1, sizeof(par));
    // Build one small group by hand:  4 -> 5 -> 3 -> 1, and 0, 2 -> 1.
    par[0] = 1;    // 0's parent is 1
    par[1] = -1;   // 1 is the leader
    par[2] = 1;    // 2's parent is 1
    par[3] = 1;    // 3's parent is 1
    par[4] = 5;    // 4's parent is 5
    par[5] = 3;    // 5's parent is 3

    // Same tree, same walk 4 -> 5 -> 3 -> 1, same answer: 1.
    // Notice that neither this version nor the recursive one changes the tree,
    // so the next find(4) would do all four steps again. find_optimized.cpp fixes
    // exactly that.
    cout << find(4) << endl;   // prints 1

    return 0;   // success
}