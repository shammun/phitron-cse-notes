/*

Question: You will be given an undirected graph as input. Then you will be given a node 
N. You need to tell the number of nodes that can be visited from node N.

Input:
6 5
0 1
0 2
0 3
2 3
4 5
2

Output:
4

Input:
6 5
0 1
0 2
0 3
2 3
4 5
4

Output:
2

Input:
7 6
0 1
1 2
2 3
1 3
4 0
5 6
1

Output:
5

*/

// Idea: "how many nodes can be visited from N" is the size of N's connected
// piece. One DFS from N enters every node of that piece exactly once, so add
// 1 each time dfs() is entered and the total is the answer (N itself included).
//
// Example 1: from node 2 the DFS reaches 2, 0, 1, 3 -> 4. Nodes 4 and 5 form a
// separate piece and are never entered.

#include <iostream>     // cin and cout
#include <vector>       // vector: growable array, one per node for the adjacency list
#include <algorithm>    // not used here; part of the usual template
#include <cstring>      // memset

using namespace std;    // write vector, cout... without the std:: prefix

// Adjacency list: an array of 1005 vectors; adj_list[u] lists u's neighbours.
vector<int> adj_list[1005];
bool vis[1005];         // vis[u] = dfs has already entered node u
// Named cnt, not count: with "using namespace std" a global called count would
// clash with the library's std::count and the compiler refuses to guess.
int cnt = 0;            // nodes entered so far

// Enter src, count it, then go deep into each unvisited neighbour.
// Base case: no unvisited neighbour -> the loop does nothing and we return.
// Trust: dfs(child) returns only after counting child's whole unvisited branch.
void dfs(int src){
    vis[src] = true;    // mark on entry so no node is counted twice
    cnt++;              // one more node reached

    // Go as deep as possible through each unvisited neighbour.
    // Range-based for: child takes each value of adj_list[src] in turn.
    for(int child : adj_list[src]){
        if(!vis[child]){    // never entered before?
            dfs(child);     // enter it (and everything behind it)
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;          // n nodes (0..n-1), e edges

    while(e--){             // repeat e times (tests e, then decreases it)
        int a, b;
        cin >> a >> b;      // one edge a - b
        adj_list[a].push_back(b);   // push_back appends: b is a neighbour of a
        adj_list[b].push_back(a);   // undirected
    }

    int start_node;
    cin >> start_node;      // the node N from the question

    // memset fills every byte of vis with 0, i.e. every entry becomes false.
    // (Globals already start at 0; this just makes the reset explicit.)
    memset(vis, false, sizeof(vis));

    // Do NOT declare a new "int cnt = 0;" here: a local with the same name
    // would hide the global one that dfs() increases, and we would print 0.
    dfs(start_node);        // visit N's whole piece, counting as we go

    cout << cnt << endl;    // Cost: O(V + E)

    return 0;               // normal end of program
}
