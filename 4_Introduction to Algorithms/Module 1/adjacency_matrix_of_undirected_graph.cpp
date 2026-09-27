// The adjacency matrix again, this time for an UNDIRECTED graph.
//
// Same n x n table as adjacency_matrix_for_directed_graph.cpp. The one change:
// an undirected edge can be walked both ways, so every edge is written into the
// table twice, [a][b] and [b][a]. That makes the table symmetric about its
// diagonal, which is a quick way to recognise an undirected graph's matrix.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>

using namespace std;

int main(){
    int n, e;
    cin >> n >> e; // n = number of vertices, e = number of edges

    int adj_mat[n][n];   // row = one end of an edge, column = the other end

    // Clear the table: a local array holds garbage until we write to it.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adj_mat[i][j] = 0;
        }
    }

    // Optional: mark each node as connected to itself (one cell per node).
    for(int i=0; i<n; i++){
        adj_mat[i][i] = 1;
    }

    /*
    
    // Shortcut for setting all elements to 0 (memset lives in <cstring>)
    memset(adj_mat, 0, sizeof(adj_mat));
    
    */

    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        // One road, two cells: a can reach b AND b can reach a.
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1; // directed graph will not have this line
    }

    // Print the table. Compare row k with column k: they are always equal here.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
