// Floyd-Warshall again, this time asked a different question: does the graph
// contain a negative cycle - a loop you can walk round for ever, getting cheaper
// each time? Bellman-Ford answered this in Module 9 by doing one extra relaxation
// round. The matrix answers it even more cheaply, in one glance at the diagonal.
//
// Everything down to the triple loop is exactly floyd-warshall.cpp; the key
// points are repeated below so this file stands on its own.
// The new part is at the bottom.
//
// Example input (3 nodes, 3 directed edges forming the loop 0->1->2->0):
//   3 3
//   0 1 1
//   1 2 -3
//   2 0 1
// Going round the loop costs 1 - 3 + 1 = -1, so adj_mat[0][0] ends up negative
// and the program prints "Negative weighted cycle detected".

#include <iostream>   // cin, cout, endl
#include <queue>      // not used here; left over from the Dijkstra files
#include <cstring>    // not used here either (memset lives there)
#include <vector>     // not used here; the matrix is a plain array

using namespace std;  // write cout instead of std::cout

int main(){
    int n, e;          // n = number of nodes (0..n-1), e = number of edges
    cin >> n >> e;
    // The distance chart: adj_mat[i][j] = cheapest known cost from i to j.
    // Its size comes from the input at run time (a "variable length array");
    // g++ accepts this, standard C++ does not.
    int adj_mat[n][n];

    // Fill the starting chart: 0 on the diagonal (i to itself costs nothing),
    // INT_MAX ("no route known") everywhere else. INT_MAX is the biggest int;
    // it comes from <climits>, which one of the headers above pulls in.
    for(int i=0; i<n; i++){          // every row
        for(int j=0; j<n; j++){      // every column
            if(i == j){
                adj_mat[i][j] = 0;
            } else{
                adj_mat[i][j] = INT_MAX;
            }
        }
    }

    // Read e directed edges "a b c": a road from a to b with cost c (c may be
    // negative - that is the whole point of this file).
    while(e--){                      // runs exactly e times
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c;           // direct road a -> b
        // adj_mat[b][a] = c; // for undirected graph
        // (Left off: this graph is directed. Note an undirected negative edge
        // would itself be a negative cycle a -> b -> a.)
    }

    // Floyd-Warshall. k = stop-over node (outermost, so that after round k
    // every pair knows its best route using middle nodes 0..k), i = start,
    // j = end. Each step asks: is i -> k -> j cheaper than what i -> j has?
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // Short version, unsafe because INT_MAX + something overflows:
                // adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
                // So both legs are checked to be real (not INT_MAX) first, and
                // only then added and compared. && stops at the first false
                // test, so the addition never happens with an INT_MAX leg.
                if(adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]){
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];   // cheaper: keep it
                }
            }
        }
    }

    // checking for negative cycle
    //
    // adj_mat[i][i] started at 0: standing still costs nothing. The triple loop
    // only ever lowers a cell, and the only way to lower [i][i] is to find a real
    // route that leaves i and comes back to i for a total below zero. That route
    // is a negative cycle. So one negative number anywhere on the diagonal is the
    // whole test - we do not have to hunt for the cycle itself.
    //
    // A cycle that costs exactly 0 does NOT count: the diagonal stays at 0, not
    // below it, and walking such a loop never makes anything cheaper.
    bool cycle = false;   // assume no negative cycle until we see one

    for(int i=0; i<n; i++){          // look at every diagonal cell
        if(adj_mat[i][i] < 0){       // i can come back to itself for < 0
            cycle = true;            // found one
        }
    }

    // If a negative cycle exists the numbers in the table are meaningless - every
    // pair that can reach the cycle has no "shortest" distance at all, because the
    // cost can always be driven lower. So we say so instead of printing the chart.
    if(cycle){
        cout << "Negative weighted cycle detected" << endl;
    } else{
        // No negative cycle: print the chart, one row per line.
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(adj_mat[i][j] == INT_MAX){   // never reached
                    cout << "INF ";
                } else{
                    cout << adj_mat[i][j] << " ";   // the shortest cost i -> j
                }
            }
            cout << endl;   // end of row i
        }
    }


    return 0;   // success
}