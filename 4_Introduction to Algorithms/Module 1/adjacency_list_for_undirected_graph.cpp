// The third way to store a graph: the adjacency list.
//
// The matrix files kept an n x n table and wrote a 1 where an edge existed. That
// table always costs n x n cells, even when the graph has only a handful of edges.
// The adjacency list keeps nothing but the edges that are really there: one list
// per node, holding that node's neighbours. Memory drops from O(n*n) to O(n + e),
// and the question a search actually asks, "who are the neighbours of 3?", is
// answered by reading one list instead of scanning a whole row.
//
// This is the storage every BFS and DFS from Module 2 onwards will use.
//
// Example input (4 nodes, 3 edges):      Output:
//   4 3                                  0 -> 1 2
//   0 1                                  1 -> 0 3
//   0 2                                  2 -> 0
//   1 3                                  3 -> 1

#include <iostream>     // cin / cout for input and output
#include <vector>       // vector: a growable array; each node's list is one
#include <algorithm>    // sort, max, min ... (not used here; course template line)
#include <string>       // std::string (not used here; template line)
#include <stack>        // std::stack (not used here; template line)

using namespace std;    // lets us write vector / cout without the std:: prefix

int main(){
    int n, e;           // n = number of nodes, e = number of edges
    cin >> n >> e; // n = number of vertices, e = number of edges

    // An array of n vectors, one per node, all empty to begin with. Read it as
    // "for each node, a growable list of neighbours". Node numbers start at 0 so
    // a node number can be used directly as the index here.
    // (An array whose size n comes from input is a g++ extension, not standard
    // C++, but it works with g++ and the course uses it. adj_list[i] is a
    // vector<int>: the neighbour list of node i.)
    vector<int> adj_list[n];

    // Read the e edges. while(e--) tests e, then subtracts 1, so the body runs
    // exactly e times (for e = 3: runs at 3, 2, 1, stops at 0).
    while(e--){
        int a, b;                   // the two ends of one edge
        cin >> a >> b;
        // One edge, written down twice: once in a's list and once in b's. That
        // is what "undirected" means here, the road can be walked either way, so
        // both endpoints must know about it.
        adj_list[a].push_back(b);   // add b at the end of a's neighbour list
        adj_list[b].push_back(a); // directed graph will not have this line
    }

    // Print each node with its neighbours. The inner loop reads the whole list of
    // node i, so the neighbours come out in the order the edges were read, not in
    // sorted order. A list makes no promise about order, only about membership.
    for(int i=0; i<n; i++){             // one pass = one node's line
        cout << i << " -> ";            // the node itself
        // Range-for: x takes each value stored in adj_list[i], front to back.
        for(int x : adj_list[i]){
            cout << x << " ";           // one neighbour of i
        }
        cout << endl;                   // finish this node's line
    }

    // Two things worth remembering from this file:
    //   adj_list[x].size() is the degree of x, how many edges touch it;
    //   the total of all the sizes is 2e for an undirected graph, because every
    //   edge was stored twice.

    return 0;                           // program ended normally
}