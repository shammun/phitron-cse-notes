/*

https://cses.fi/problemset/task/1666/

Building Roads

Byteland has n cities, and m roads between them. The goal is to construct new roads so that there
is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads
should be built.

Input
The first input line has two integers n and m: the number of cities and roads. The cities are
numbered 1,2, ...,n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is
a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.

Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.
Constraints

1. 1 <= n <= 10^5
2. 1 <= m <= 2x10^5
3. 1 <= a,b <= n

Example
Input:
4 2
1 2
3 4

Output:
1
2 3

*/

// Building Roads, as it turned up on the Dijkstra practice day. No weights are
// involved, so no Dijkstra is needed: it is a components question (Module 3).
// Each group of cities that can already reach each other is one component.
// Joining the components in a chain (first to second, second to third, ...)
// connects everything, and fewer than (components - 1) roads can never do it.
// So: find one city in every component, then link neighbours in that list.
//
// Trace on the example: components are {1,2} and {3,4}.
//   i=1: not visited -> representative 1, DFS marks 1 and 2.
//   i=2: already visited, skip.
//   i=3: not visited -> representative 3, DFS marks 3 and 4.
//   components = {1, 3}, k = 1, prints "1 3".
// That differs from the sample's "2 3", but any valid answer is accepted.


#include <iostream>     // cin, cout
#include <vector>       // vector: growable array
#include <algorithm>    // not needed here, left from a template
#include <string>       // not needed here, left from a template
#include <stack>        // not needed here, left from a template
#include <queue>        // not needed here (this file uses DFS, not BFS)
using namespace std;    // write vector instead of std::vector

// Mark every city reachable from node. adj and vis are passed by reference
// (&), so the function works on main's vectors instead of copies.
// Recursion: there is no explicit base case; the recursion stops by itself
// when every neighbour is already visited (the for loop makes no call).
// Each call trusts that dfs(child) will mark child's whole unvisited region.
void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
    vis[node] = true;               // mark first, so we never come back here
    for(int child : adj[node]){     // every city joined to node by a road
        if(!vis[child]){            // not reached yet?
            dfs(child, adj, vis);   // go there and keep going deeper
        }
    }
}

int main(){
    int n, m;          // n cities, m existing roads
    cin >> n >> m;

    // Cities are numbered 1..n, so the vectors need n + 1 slots: index n must
    // exist, and index 0 is simply never used.
    // adj[x] = list of cities directly connected to x (adjacency list).
    vector<vector<int>> adj(n + 1);

    // Read the m roads.
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);   // roads go both ways
        adj[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);   // vis[x] = has some DFS reached x? all false at start
    vector<int> components;   // one representative city per component

    // A city that no earlier DFS reached starts a new component: remember it,
    // then flood its whole component.
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            components.push_back(i);   // i is the first city seen of a new component
            dfs(i, adj, vis);          // mark all of that component
        }
    }

    // c components need c - 1 new roads to be chained together.
    // size() returns an unsigned number, but it is at least 1 here (n >= 1),
    // so subtracting 1 cannot go below zero.
    int k = components.size() - 1;   // roads needed
    cout << k << endl;               // endl = newline and flush

    // Link each representative to the next one: a chain through every piece.
    for(int i=0; i<k; i++){
        cout << components[i] << " " << components[i+1] << endl;
    }

    // O(n + m) time and memory.
    // Note: with n up to 1e5, a long chain of cities makes the recursion 1e5
    // calls deep. Each call uses only a little stack memory, so this passes on
    // CSES, but on a system with a tiny stack an iterative BFS would be safer.
    return 0;
}
