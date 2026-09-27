// The first way to store a graph: the adjacency matrix, for a DIRECTED graph.
//
// Picture an n x n table with one row and one column per node. The cell in row a,
// column b answers one yes/no question: "is there an arrow from a to b?". A 1 means
// yes, a 0 means no. Asking about one edge is a single look, O(1), but the table
// always costs n x n cells, however few edges the graph really has.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>

using namespace std;

int main(){
    int n, e;
    cin >> n >> e; // n = number of vertices, e = number of edges

    // The table itself. Nodes are numbered 0..n-1, so a node number can be used
    // directly as a row or column index.
    int adj_mat[n][n];

    // A local array starts full of leftover garbage, so clear every cell to 0
    // ("no edge yet") before writing any edges in.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adj_mat[i][j] = 0;
        }
    }

    // Optional convention: every node can "reach itself", so mark the diagonal.
    // The loop runs over the n nodes (i < n), one diagonal cell per node.
    for(int i=0; i<n; i++){
        adj_mat[i][i] = 1;
    }

    /*
    
    // Shortcut for setting all elements to 0 (memset lives in <cstring>)
    memset(adj_mat, 0, sizeof(adj_mat));
    
    */

    // Read the e arrows. "a b" means you can go from a to b, and only that way,
    // so only the cell [a][b] is set. Row = from, column = to.
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
    }

    // Print the table row by row. Because arrows are one-way, the table is
    // usually NOT symmetric: [a][b] can be 1 while [b][a] is 0.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
