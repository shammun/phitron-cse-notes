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


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

// Mark every city reachable from node. adj and vis are passed by reference
// (&), so the function works on main's vectors instead of copies.
void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
    vis[node] = true;
    for(int child : adj[node]){
        if(!vis[child]){
            dfs(child, adj, vis);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    // Cities are numbered 1..n, so the vectors need n + 1 slots: index n must
    // exist, and index 0 is simply never used.
    vector<vector<int>> adj(n + 1);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);   // roads go both ways
        adj[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    vector<int> components;   // one representative city per component

    // A city that no earlier DFS reached starts a new component: remember it,
    // then flood its whole component.
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            components.push_back(i);
            dfs(i, adj, vis);
        }
    }

    int k = components.size() - 1;   // roads needed
    cout << k << endl;

    // Link each representative to the next one: a chain through every piece.
    for(int i=0; i<k; i++){
        cout << components[i] << " " << components[i+1] << endl;
    }

    // O(n + m) time and memory.
    return 0;
}
