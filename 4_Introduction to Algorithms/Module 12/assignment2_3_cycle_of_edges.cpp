/*

https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/cycle-of-edges

Cycle of Edges

Problem Statement

You will be given an undirected graph where there will be N nodes and E edges. You need to tell the number of 
edges that can create a cycle in the graph.

Note: Duplicate edges as input can not be possible. The value of nodes are from 1 to N.

Input Format
- First line will contain N and E.
- Next E lines will contain A and B which means there is a edge between A and B.

Constraints
1. 1 <= N <= 10^5
2. 1 <= E <= 10^6
3. 1 <= A, B <= N

Output Format
- Output the number of edges that can create a cycle.

Sample Input 0
5 7
1 2
2 3
3 4
4 5
4 1
2 4
5 3

Sample Output 0
3

Sample Input 1
3 3
1 2
2 3
1 3

Sample Output 1
1

*/

// Solution idea (DSU, Module 11).
// Add the edges one by one. If both ends already share a leader, they were
// connected before this edge arrived, so the edge closes a cycle: count it.
// Otherwise the edge joins two separate groups: union them.
//
// DSU in one line: every group has a LEADER; par[x] points one step towards
// it, and par[x] == -1 means x is the leader. Same leader = same group.
//
// Trace with Sample 1: 1-2 (merge), 2-3 (merge), 1-3 (same leader -> count 1).

#include <iostream>     // cin, cout, endl
#include <queue>        // not used here
#include <cstring>      // memset
#include <vector>       // not used here

using namespace std;    // no std:: prefix

int par[100005];          // par[x] = x's parent in its group's tree; -1 = x is a leader
int group_size[100005];   // group_size[leader] = how many nodes that group holds

// Walk up to the leader, and on the way back point every node straight at it
// (path compression), so the next find() on these nodes takes one step.
// Base case: par == -1 -> node is the leader.
int find(int node){
    if(par[node]==-1){
        return node;
    }
    int leader = find(par[node]);   // the parent's leader is our leader
    par[node] = leader;             // shortcut for next time
    return leader;
}

// Union by size: hang the smaller tree under the bigger one's leader, so the
// trees stay shallow. (main only calls this when the leaders differ.)
void dsu_union(int node1, int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);

    if(group_size[leader1] >= group_size[leader2]){   // group 1 is bigger/equal
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    } else{                                           // group 2 is bigger
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main(){
    // memset fills bytes; 0xFF in every byte makes each int -1.
    memset(par, -1, sizeof(par));   // everyone starts as the leader of a group of one
    // Every group starts with size 1. This must be a loop: memset fills BYTES,
    // so memset(group_size, 1, ...) would make each int 0x01010101 = 16843009.
    for(int i=0; i<100005; i++){
        group_size[i] = 1;
    }

    int n, e;          // nodes, edges
    cin >> n >> e;

    int edges = 0;   // edges that closed a cycle

    while(e--){        // read and process each edge
        int a, b;
        cin >> a >> b;
        int leader1 = find(a);     // a's group
        int leader2 = find(b);     // b's group
        if(leader1==leader2){
            edges++;           // a and b were already connected: this edge is extra
        } else{
            dsu_union(a, b);   // first link between the two groups
        }
    }

    cout << edges << endl;     // how many edges closed a cycle

    // Cost: about O(E * alpha(N)), practically linear.
    // (alpha is the inverse Ackermann function: at most 4 for any real N.)
    return 0;
}
