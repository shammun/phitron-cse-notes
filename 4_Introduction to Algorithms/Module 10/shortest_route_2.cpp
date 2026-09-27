// CSES 1672 - Shortest Routes II.  https://cses.fi/problemset/task/1672
//
// n cities, e two-way roads, then q questions of the form "how cheap is it to get
// from s to d?". Running Dijkstra once per question would be far too slow. Build
// the whole chart once with Floyd-Warshall (O(n^3)) and every question after that
// is a single table lookup.
//
// Two things differ from floyd-warshall.cpp:
//   * the cities are numbered 1..n here, not 0..n-1;
//   * the distances need long long. Up to 500 cities with roads of a billion each
//     can add up past what an int holds, so a route total is stored as long long.

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>   // for min()
#include <climits>     // LLONG_MAX

using namespace std;

// The distance chart. Cities are numbered 1..n (n <= 500), so the array needs
// index n itself: size n+1 at least, and 505 leaves a little room. It lives
// outside main because 505 x 505 long longs is about 2 MB, which is too much
// for the stack of a function but fine for a global.
long long int adj_mat[505][505];

int main(){
    int n, e, q;       // cities, roads, questions
    cin >> n >> e >> q;

    // Same starting chart as before, but over 1..n because CSES numbers cities
    // from 1. LLONG_MAX is the long long version of INT_MAX and means "no route
    // known yet" (from <climits>).
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j){
                adj_mat[i][j] = 0;
            } else{
                adj_mat[i][j] = LLONG_MAX;
            }
        }
    }

    // Read the roads. min() rather than plain assignment, because CSES allows
    // several roads between the same two cities: a later, dearer road must not
    // wipe out a cheaper one already read.
    // Both directions are filled because the roads are two-way.
    // Note the second line reads adj_mat[a][b], not adj_mat[b][a]. It still gives
    // the right answer, but only because the line above has just set [a][b] to the
    // cheapest value and the two cells are always kept equal. Writing
    // min(adj_mat[b][a], c) would say what is meant.
    while(e--){
        long long int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], c);
        adj_mat[b][a] = min(adj_mat[a][b], c); // we have undirected graph here
    }

    // The same triple loop, over 1..n. This is the expensive part and it runs
    // once, before any question is read - that is the whole point of the file.
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                // adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
                if(adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]){
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    // Each question is now O(1): the answer is already sitting in the table.
    // A cell still at LLONG_MAX means d cannot be reached from s at all, and CSES
    // wants -1 for that case.
    while(q--){
        int s, d;
        cin >> s >> d;
        if(adj_mat[s][d] == LLONG_MAX){
            cout << "-1" << endl;
        } else {
            cout << adj_mat[s][d] << endl;
        }
    }

    return 0;
}