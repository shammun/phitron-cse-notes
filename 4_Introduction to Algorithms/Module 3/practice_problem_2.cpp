/*

Question: You will be given an undirected graph as input. You need to tell the number 
of components in this graph.

Input:
6 5
0 1
0 2
0 3
2 3
4 5

Output:
2

Input:
9 7
0 1
0 2
0 3
2 3
4 5
6 8
7 6

Output:
3

Input:
7 7
0 1
1 2
2 3
1 3
4 0
0 5
5 6

Output:
1

Input:
10 5
1 2
2 3
1 3
4 0
5 6

Output:
6 
(Because 7 8 and 9 nodes are not connected, but they are also components)


*/

// Idea: a component is one piece of the graph. Loop over every node; whenever
// a node is still unvisited, it must belong to a piece we have not seen yet, so
// count one component and let a DFS mark that whole piece. The next unvisited
// node found by the loop is then in yet another piece.
//
// Example 4: 10 nodes, pieces {1,2,3} {0,4} {5,6} and the lonely 7, 8, 9 -> 6.

#include <iostream>     // cin and cout
#include <vector>       // vector, for the adjacency lists
#include <algorithm>    // not used here; part of the usual template
#include <cstring>      // memset

using namespace std;    // write vector, cout... without std::

vector<int> adj_list[1005];   // adj_list[u] = neighbours of u (array of vectors)
bool vis[1005];               // vis[u] = u already belongs to a piece we counted

// Plain recursive DFS: marks every node of src's piece.
// Base case: no unvisited neighbour -> loop does nothing, the call returns.
void dfs(int src){
    vis[src] = true;                  // mark this node

    for(int child : adj_list[src]){   // each neighbour of src
        if(!vis[child]){              // not marked yet?
            dfs(child);               // mark it and everything behind it
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;             // n nodes (0..n-1), e edges

    while(e--){                // repeat e times
        int a, b;
        cin >> a >> b;         // edge a - b
        adj_list[a].push_back(b);   // b is a neighbour of a
        adj_list[b].push_back(a);   // a is a neighbour of b (undirected)
    }

    memset(vis, false, sizeof(vis));   // every byte 0 -> every entry false

    // count is a local here, so it hides std::count from <algorithm> inside
    // main and there is no clash; a name like num_components would be clearer.
    int count = 0;             // pieces found so far
    // Go over ALL n nodes, not only the ones named in edges: a node with no
    // edges at all is still a component of size 1.
    for(int i = 0; i<n; i++){
        if(!vis[i]){     // first node of a piece we have not seen
            dfs(i);      // swallow i's whole piece
            count++;     // ...and count that piece once
        }
    }

    cout << count << endl;   // Cost: O(V + E), every node and edge seen once

    return 0;                // normal end of program
}
