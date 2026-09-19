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

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>

using namespace std;

int main(){
    int n, e;
    cin >> n >> e; // n = number of vertices, e = number of edges

    // An array of n vectors, one per node, all empty to begin with. Read it as
    // "for each node, a growable list of neighbours". Node numbers start at 0 so
    // a node number can be used directly as the index here.
    vector<int> adj_list[n];

    while(e--){
        int a, b;
        cin >> a >> b;
        // One edge, written down twice: once in a's list and once in b's. That
        // is what "undirected" means here, the road can be walked either way, so
        // both endpoints must know about it.
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // directed graph will not have this line
    }

    // Print each node with its neighbours. The inner loop reads the whole list of
    // node i, so the neighbours come out in the order the edges were read, not in
    // sorted order. A list makes no promise about order, only about membership.
    for(int i=0; i<n; i++){
        cout << i << " -> ";
        for(int x : adj_list[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    // Two things worth remembering from this file:
    //   adj_list[x].size() is the degree of x, how many edges touch it;
    //   the total of all the sizes is 2e for an undirected graph, because every
    //   edge was stored twice.

    return 0;
}