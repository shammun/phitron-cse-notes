// Floyd-Warshall: the cheapest route between EVERY pair of nodes, all at once.
//
// Dijkstra (Module 7) and Bellman-Ford (Module 9) each fill in one ROW of the
// distance chart: you pick a starting node and learn the cost to all the others.
// Here we want the whole chart, so we keep the chart itself as an n x n matrix
// and keep improving it in place.
//
// adj_mat[i][j] always means "the cheapest cost from i to j that I know of so
// far". It starts out as the direct road only. Each round of the outer loop lets
// one more node be used as a stop-over in the middle, so after the last round
// every pair has been allowed to go through every node and the chart is final.
//
// Time O(n^3) - three nested loops, each n long. Space O(n^2) for the matrix.

#include <iostream>
#include <queue>    // not used here; carried over from the earlier graph files
#include <cstring>  // same - Dijkstra/BFS needed these, Floyd-Warshall does not
#include <vector>

using namespace std;

int main(){
    int n, e;        // n = number of nodes, e = number of directed edges
    cin >> n >> e;

    // The chart: one row and one column per node. Note this is a variable length
    // array - its size is only known while the program runs. g++ allows that,
    // standard C++ does not, so for a big n a fixed-size global array is safer.
    int adj_mat[n][n];

    // The starting chart. Staying where you are costs nothing, so the diagonal is
    // 0. Every other pair is "no route known yet", written as INT_MAX, the biggest
    // int there is. INT_MAX really lives in <climits>, which this file never
    // includes; it only compiles because one of the headers above drags <climits>
    // in. Adding #include <climits> would make that safe instead of lucky.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                adj_mat[i][j] = 0;
            } else{
                adj_mat[i][j] = INT_MAX;
            }
        }
    }

    // e lines of "a b c": a road from a to b costing c. Only [a][b] is written,
    // because the graph is directed. The commented line below is what an
    // undirected graph would need. Plain assignment means a second road between
    // the same pair overwrites the first, even if the first was cheaper; when
    // that can happen, use min() instead (see shortest_route_2.cpp).
    while(e--){
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c;
        // adj_mat[b][a] = c; // for undirected graph
    }

    // The heart of the algorithm.
    //
    // k is the stop-over node and it MUST be the outermost loop. After round k
    // has finished, every pair i,j holds the best route that uses only nodes
    // 0..k in the middle. If k sat inside, a pair could be settled before the
    // stop-over node it actually needs had had its turn.
    //
    // i is where we start, j is where we want to end up: "is going i -> k -> j
    // cheaper than the best i -> j I have?"
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // The commented one-liner reads better but is a trap: an unknown
                // leg costs INT_MAX, and INT_MAX + anything positive overflows
                // into a negative number, which then looks like a bargain. So both
                // legs are checked for INT_MAX before they are added together.
                // adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
                if(adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]){
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    // Print the finished chart. Row i, column j is the answer for i -> j. A cell
    // still holding INT_MAX was never improved, so there is no route at all from
    // i to j - print INF rather than a meaningless huge number.
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

    return 0;
}