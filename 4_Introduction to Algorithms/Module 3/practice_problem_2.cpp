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

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>      // memset

using namespace std;

vector<int> adj_list[1005];
bool vis[1005];

// Plain recursive DFS: marks every node of src's piece.
void dfs(int src){
    vis[src] = true;

    for(int child : adj_list[src]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;

    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));

    int count = 0;
    // Go over ALL n nodes, not only the ones named in edges: a node with no
    // edges at all is still a component of size 1.
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            dfs(i);      // swallow i's whole piece
            count++;     // ...and count that piece once
        }
    }

    cout << count << endl;   // Cost: O(V + E), every node and edge seen once

    return 0;
}