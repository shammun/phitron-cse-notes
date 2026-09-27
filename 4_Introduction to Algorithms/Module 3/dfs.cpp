// Depth-first search (DFS): the other way to walk a graph.
//
// BFS spread out in rings, held back by a queue. DFS does the opposite: from the
// node you are standing on, step into the first unvisited neighbour immediately,
// and from there into its first unvisited neighbour, and so on until there is
// nowhere new to go. Only then do you back up one step and try the next branch.
//
// There is no queue here, and no stack written by hand either. The recursion does
// the remembering: each call to dfs() is paused while its child call runs, and the
// call stack holds the list of nodes we still have to come back to. "Back up one
// step" is simply a function returning to its caller.
//
// visited[] has the same job as in BFS: without it, two nodes joined in a cycle
// would call each other for ever until the program runs out of stack.
//
// Tiny trace. Input:
//   5 4
//   0 1
//   0 2
//   1 3
//   2 4
// adj_list: 0:[1,2]  1:[0,3]  2:[0,4]  3:[1]  4:[2]
// dfs(0) prints 0, goes into 1, prints 1, goes into 3, prints 3; 3 has nothing new,
// returns to 1; 1 has nothing new, returns to 0; 0 tries 2, prints 2, goes to 4.
// Output: 0 1 3 2 4

#include <iostream>     // cin and cout
#include <vector>       // vector: growable array; one per node for the adjacency list
#include <algorithm>    // not used here; part of the usual template
#include <string>       // not used here; part of the usual template
#include <stack>        // not used: the recursion is our stack
#include <queue>        // not used: DFS needs no queue
// NOTE: memset (used in main) is declared in <cstring>, which is not included.
// Some compilers reach it through <iostream>; GCC 8 (MinGW) does not and stops
// with "'memset' was not declared". Fix: add #include <cstring>.

using namespace std;    // allows vector, cout... without writing std::

// Adjacency list: adj_list[u] holds every node joined to u by an edge. It is an
// ARRAY of 1005 vectors, so nodes 0..1004 each get their own growable list.
vector<int> adj_list[1005];
bool vis[1005];         // vis[u] = true once dfs has entered u

// Visit src and everything reachable from it that is not visited yet.
// Base case: there is no explicit "if ... return" - when every neighbour is
// already visited the loop simply does nothing and the function ends.
// Trust: each dfs(child) call returns only after it has visited child's whole
// unvisited branch.
void dfs(int src){
    cout << src << " ";   // printed on the way IN, so this is the entry order
    vis[src] = true;      // mark before recursing, or a cycle sends us round again

    // Range-based for: child takes each value in adj_list[src] in turn.
    for(int child : adj_list[src]){
        if(!vis[child]){  // ! = "not": only neighbours we have never entered
            // Go deep straight away. This call will finish the whole branch under
            // child before control ever comes back here and tries the next one.
            dfs(child);
        }
    }
    // Falling off the end of the loop is the backtrack: nothing new under src, so
    // return to whoever called us and let them carry on with their own list.
}

int main(){
    int n, e;
    cin >> n >> e;            // n = number of nodes (0..n-1), e = number of edges

    while(e--){               // runs e times: e-- tests e, then lowers it by one
        int a, b;
        cin >> a >> b;        // one edge between a and b
        adj_list[a].push_back(b);   // push_back adds b to the end of a's list
        adj_list[b].push_back(a);   // undirected: the edge works both ways
    }
    memset(vis, false, sizeof(vis));   // set every vis[] entry to false (0 bytes)
    dfs(0);                            // start the walk at node 0

    // Cost is the same as BFS, O(V + E), because each node is entered once and
    // each edge is looked at once from each end. The difference is only the order
    // and where the memory goes: a queue for BFS, the recursion stack for DFS.
    // That stack is worth watching, since a path of 100000 nodes means 100000
    // nested calls.

    return 0;   // normal end of program
}