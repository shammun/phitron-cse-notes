// Floyd-Warshall again, this time asked a different question: does the graph
// contain a negative cycle - a loop you can walk round for ever, getting cheaper
// each time? Bellman-Ford answered this in Module 9 by doing one extra relaxation
// round. The matrix answers it even more cheaply, in one glance at the diagonal.
//
// Everything down to the triple loop is exactly floyd-warshall.cpp; read the
// comments there for why k is outermost and why INT_MAX is checked before adding.
// The new part is at the bottom.

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                adj_mat[i][j] = 0;
            } else{
                adj_mat[i][j] = INT_MAX;
            }
        }
    }

    while(e--){
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c;
        // adj_mat[b][a] = c; // for undirected graph
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
                if(adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]){
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
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
    bool cycle = false;
    
    for(int i=0; i<n; i++){
        if(adj_mat[i][i] < 0){
            cycle = true;
        }
    }

    // If a negative cycle exists the numbers in the table are meaningless - every
    // pair that can reach the cycle has no "shortest" distance at all, because the
    // cost can always be driven lower. So we say so instead of printing the chart.
    if(cycle){
        cout << "Negative weighted cycle detected" << endl;
    } else{
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(adj_mat[i][j] == INT_MAX){
                    cout << "INF ";
                } else{
                    cout << adj_mat[i][j] << " ";
                }
            }
            cout << endl;
        }
    }


    return 0;
}