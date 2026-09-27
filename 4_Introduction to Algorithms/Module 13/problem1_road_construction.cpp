/*

https://cses.fi/problemset/task/1676/

Road Construction

There are n cities and initially no roads between them. However, every day a new road will be 
constructed, and there will be a total of m roads.
A component is a group of cities where there is a route between any two cities using the roads. After 
each day, your task is to find the number of components and the size of the largest component.

Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 
1,2, ...,n.

Then, there are m lines describing the new roads. Each line has two integers a and b: a new road is 
constructed between cities a and b.
You may assume that every road will be constructed between two different cities.

Output
Print m lines: the required information after each day.

Constraints
1. 1 <= n <= 10^5
2. 1 <= m <= 2X10^5
3. 1 <= a,b <= n

Example

Input:
5 3
1 2
1 3
4 5

Output:
4 2
3 3
2 3


*/

// Solution idea (DSU, Module 11).
// Roads only ever get ADDED, which is exactly what DSU is good at. Keep two
// running numbers instead of recounting after each day:
//   cmp      = how many components there are (starts at n, one per city);
//   max_size = the size of the biggest component (starts at 1).
// A road inside one component changes nothing. A road between two components
// merges them: one component fewer, and the merged size may be a new record.
//
// DSU reminder: each group has a LEADER. par[x] points one step towards it,
// and par[x] == -1 means x is the leader. Same leader = same component.
//
// Trace with the example (n = 5):
//   road 1-2: merge {1},{2}   -> cmp 4, biggest 2   -> "4 2"
//   road 1-3: merge {1,2},{3} -> cmp 3, biggest 3   -> "3 3"
//   road 4-5: merge {4},{5}   -> cmp 2, biggest 3   -> "2 3"

#include <iostream>   // cin, cout, endl
#include <queue>      // not used here
#include <cstring>    // not used here
#include <vector>     // not used here

using namespace std;  // no std:: prefix (also gives us max)

int par[100005];          // par[x] = parent of x; -1 means x is a leader
int group_size[100005];   // size of the group, kept at its leader
int cmp, max_size;        // the two answers, updated as roads arrive

// Leader of node's group, with path compression.
// Base case: no parent -> node is the leader. Otherwise the parent's leader is
// ours; we point node straight at it so the next lookup is one step.
int find(int node){
    if(par[node] == -1){
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

// Merge the components of node1 and node2 and keep cmp / max_size up to date.
void dsu_union(int node1, int node2){
    int leader1 = find(node1);   // component of node1
    int leader2 = find(node2);   // component of node2

    // Same component already: the road adds no new connection, so both
    // answers stay as they were.
    if(leader1 == leader2){
        return;
    }

    // Union by size; the merged group's new size is the only size that grew,
    // so it is the only one that can beat the current record.
    if(group_size[leader1] >= group_size[leader2]){
        par[leader2] = leader1;                          // 2 goes under 1
        group_size[leader1] += group_size[leader2];      // 1's group grows
        max_size = max(max_size, group_size[leader1]);   // new record?
    } else{
        par[leader1] = leader2;                          // 1 goes under 2
        group_size[leader2] += group_size[leader1];
        max_size = max(max_size, group_size[leader2]);
    }
    cmp--;   // two components became one
}

int main(){
    int n, e;       // cities, roads (called m in the statement)
    cin >> n >> e;
    cmp = n;        // day 0: no roads, every city alone
    max_size = 1;   // biggest component is a single city

    // Cities are numbered 1..n: each starts as its own leader, size 1.
    for(int i=1; i<=n; i++){
        par[i] = -1;
        group_size[i] = 1;
    }

    // One road per day, and one answer line per day.
    // (For 2 * 10^5 lines, "\n" would be faster than endl, which also flushes.)
    while(e--){
        int a, b;               // the new road a - b
        cin >> a >> b;
        dsu_union(a, b);        // merge if they were apart
        cout << cmp << " " << max_size << endl;
    }

    // Cost: about O(m * alpha(n)); recounting components with BFS every day
    // would be O(m * (n + m)), far too slow for 2 * 10^5 roads.
    // (No "return 0;": main alone may leave it out, and then returns 0.)
}
