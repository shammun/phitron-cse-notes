// The adjacency matrix again, this time for an UNDIRECTED graph.
//
// Same n x n table as adjacency_matrix_for_directed_graph.cpp. The one change:
// an undirected edge can be walked both ways, so every edge is written into the
// table twice, [a][b] and [b][a]. That makes the table symmetric about its
// diagonal, which is a quick way to recognise an undirected graph's matrix.
//
// Example input (3 nodes, 2 edges):      Output:
//   3 2                                  1 1 0
//   0 1                                  1 1 1
//   1 2                                  0 1 1
// Row 0 column 1 and row 1 column 0 are BOTH 1: the edge 0-1 works both ways.

#include <iostream>     // cin / cout for input and output
#include <vector>       // vector (not used in this file; course template line)
#include <algorithm>    // sort, max, min ... (not used here; template line)
#include <string>       // std::string (not used here; template line)
#include <stack>        // std::stack (not used here; template line)

using namespace std;    // lets us write cout instead of std::cout

int main(){
    int n, e;           // n = number of nodes, e = number of edges
    cin >> n >> e; // n = number of vertices, e = number of edges

    // An n x n table whose size is known only at run time. Standard C++ does
    // not allow this ("variable length array"), but g++ accepts it, so the
    // course uses it for small n. Nodes are 0..n-1 and are used as indexes.
    int adj_mat[n][n];   // row = one end of an edge, column = the other end

    // Clear the table: a local array holds garbage until we write to it.
    for(int i=0; i<n; i++){             // every row i ...
        for(int j=0; j<n; j++){         // ... and every column j in it
            adj_mat[i][j] = 0;          // 0 = "no edge between i and j"
        }
    }

    // Optional: mark each node as connected to itself (one cell per node).
    for(int i=0; i<n; i++){
        adj_mat[i][i] = 1;              // the diagonal cell (i, i)
    }

    /*
    
    // Shortcut for setting all elements to 0 (memset lives in <cstring>)
    // memset writes the byte 0 into every byte of the table, which makes every
    // int 0. Left commented out because the loop above already cleared it.
    memset(adj_mat, 0, sizeof(adj_mat));
    
    */

    // Read the e edges; one pass of the loop handles one edge "a b".
    for(int i=0; i<e; i++){
        int a, b;                       // the two ends of this edge
        cin >> a >> b;
        // One road, two cells: a can reach b AND b can reach a.
        adj_mat[a][b] = 1;              // a -> b
        adj_mat[b][a] = 1; // directed graph will not have this line
    }

    // Print the table. Compare row k with column k: they are always equal here.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << adj_mat[i][j] << " ";   // one cell followed by a space
        }
        cout << endl;                       // end of row i: new line
    }

    return 0;                               // program ended normally
}
