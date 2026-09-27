// The first way to store a graph: the adjacency matrix, for a DIRECTED graph.
//
// Picture an n x n table with one row and one column per node. The cell in row a,
// column b answers one yes/no question: "is there an arrow from a to b?". A 1 means
// yes, a 0 means no. Asking about one edge is a single look, O(1), but the table
// always costs n x n cells, however few edges the graph really has.
//
// Example input (3 nodes, 2 arrows):     Output (diagonal is 1, see below):
//   3 2                                  1 1 0
//   0 1                                  0 1 1
//   1 2                                  0 0 1
// Row 0 has a 1 in column 1 (arrow 0->1), but row 1 column 0 stays 0:
// there is no arrow back from 1 to 0.

#include <iostream>     // cin / cout for input and output
#include <vector>       // vector (not used in this file; course template line)
#include <algorithm>    // sort, max, min ... (not used here; template line)
#include <string>       // std::string (not used here; template line)
#include <stack>        // std::stack (not used here; template line)

using namespace std;    // lets us write cout instead of std::cout

int main(){
    int n, e;           // n = number of nodes, e = number of edges (arrows)
    cin >> n >> e; // n = number of vertices, e = number of edges

    // The table itself. Nodes are numbered 0..n-1, so a node number can be used
    // directly as a row or column index.
    // int adj_mat[n][n] is a 2D array whose size comes from input at run time
    // (a "variable length array"). Standard C++ does not allow that, but g++
    // accepts it as an extension, which is why the course uses it. It lives on
    // the stack, so it is fine for small n (a few thousand at most).
    int adj_mat[n][n];

    // A local array starts full of leftover garbage, so clear every cell to 0
    // ("no edge yet") before writing any edges in.
    // Outer loop picks row i, inner loop walks every column j of that row.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adj_mat[i][j] = 0;      // cell (i, j) = "no arrow from i to j"
        }
    }

    // Optional convention: every node can "reach itself", so mark the diagonal.
    // The loop runs over the n nodes (i < n), one diagonal cell per node.
    for(int i=0; i<n; i++){
        adj_mat[i][i] = 1;          // diagonal cell: row i, column i
    }

    /*
    
    // Shortcut for setting all elements to 0 (memset lives in <cstring>)
    // memset fills the array's raw bytes with the byte 0; an int made of four
    // zero bytes is 0, so the whole table becomes 0 in one call. sizeof(adj_mat)
    // is the table size in bytes. It is commented out because the loop above
    // already did the job. (memset only works like this for 0 and -1.)
    memset(adj_mat, 0, sizeof(adj_mat));
    
    */

    // Read the e arrows. "a b" means you can go from a to b, and only that way,
    // so only the cell [a][b] is set. Row = from, column = to.
    for(int i=0; i<e; i++){         // one pass = one arrow read and stored
        int a, b;                   // a = start node, b = end node
        cin >> a >> b;
        adj_mat[a][b] = 1;          // mark "a -> b exists"; [b][a] is left alone
    }

    // Print the table row by row. Because arrows are one-way, the table is
    // usually NOT symmetric: [a][b] can be 1 while [b][a] is 0.
    for(int i=0; i<n; i++){             // row i = arrows going OUT of node i
        for(int j=0; j<n; j++){         // column j = is there an arrow into j?
            cout << adj_mat[i][j] << " ";   // print the cell and a space
        }
        cout << endl;                   // row finished: move to a new line
    }

    return 0;                           // program ended normally
}
