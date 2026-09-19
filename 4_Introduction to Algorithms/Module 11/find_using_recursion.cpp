// Disjoint Set Union (DSU), also called Union-Find: a way of keeping track of
// which items are in the same group, when groups keep merging.
//
// The whole idea rests on one trick. Every group picks one member as its LEADER,
// and every other member remembers one node above it, its parent. Follow the
// parents upwards and you always end at the leader. Two items are in the same
// group exactly when they end at the same leader - so "are these two together?"
// becomes "do they have the same leader?".
//
// par[x] holds the parent of x, and par[x] == -1 is the marker for "x has no
// parent, so x IS a leader". Nothing else is stored: no lists, no edges, just one
// int per node.
//
// This first file only does the climbing half (find). Joining two groups comes
// later, in union.cpp.

#include <iostream>
#include <queue>
#include <cstring>   // for memset
#include <vector>
using namespace std;

// One parent slot per node. It is global, so it starts as all zeros - which would
// wrongly mean "everyone's parent is node 0", hence the memset in main().
int par[1005];

// find(node): climb from node up to the leader of its group and return it.
// If node has no parent it is already the leader - that is the stopping point of
// the recursion, and without it the calls would never end.
// Otherwise ask the same question one step up and pass the answer back down.
// Cost: one call per step, so O(height of the tree).
int find(int node){
    if(par[node] == -1){
        return node;
    }
    return find(par[node]);
}

int main(){
    // memset writes the same BYTE over the whole block. -1 as a byte is 11111111,
    // and an int made of four such bytes is also -1, so this really does set every
    // par[i] to -1: at the start each node is alone and is its own leader.
    // (The same trick with 1 instead of -1 does NOT work - see union.cpp.)
    memset(par, -1, sizeof(par));
    par[0] = 1;
    par[1] = -1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;

    // Now a small group is built by hand, to have something to climb:
    //
    //            1            <- leader, par[1] = -1
    //           /|\
    //          0 2 3
    //              |
    //              5
    //              |
    //              4
    //
    // find(4) walks 4 -> 5 -> 3 -> 1 and stops at 1, because par[1] is -1.
    // Four calls, four steps: that is why a tall tree makes find slow, and why the
    // next two files work on making it shorter.
    cout << find(4) << endl;

    return 0;
}