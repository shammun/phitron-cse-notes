/*

https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/shortest-distance-2

Shortest Distance

Problem Statement

You'll be given a graph of N nodes and E edges. For each edge, you'll be given A, B and W which means there is an 
edge from A to B only and which will cost W.

Also, you'll be given Q queries, for each query you'll be given X and Y, where X is the source and Y is the 
destination. You need to print the minimum cost from X to Y for each query. If there is no connection between X 
and Y, print -1.

Note: There can be multiple edges from one node to another. Make sure you handle this one.

Input Format
- First line will contain N and E.
- Next E lines will contain A, B and W.
- After that you'll get Q.
- Next Q queries will contain X and Y.

Constraints
1. 1 <= N <= 100
2. 1 <= E <= 10^5
3. 1 <= A, B <= N
4. 1 <= W <= 10^9
5. 1 <= Q <= 10^5
6. 1 <= X, Y <= N

Output Format
- Output the minimum cost for each query.

Sample Input 0
4 7
1 2 10
2 3 5
3 4 2
4 2 3
3 1 7
2 1 1
1 4 4
6
1 2
4 1
3 1
1 4
2 4
4 2

Sample Output 0
7
4
6
4
5
3

Sample Input 1
4 4
1 2 4
2 3 4
3 1 2
1 2 10
6
1 2
2 1
1 3
3 1
2 3
3 2

Sample Output 1
4
6
8
2
4
6

*/

// Solution idea (Floyd-Warshall, Module 10).
// Many (X, Y) questions about the same small graph (N <= 100): instead of
// running a single-source algorithm per query, compute the cheapest cost
// between EVERY pair once, then each query is a table lookup.
//
// Trace with Sample 1: edges 1->2 (4, then 10: keep 4), 2->3 (4), 3->1 (2).
// Query 2 -> 1: direct none; via 3: 4 + 2 = 6. Query 1 -> 3: 4 + 4 = 8.

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here
#include <climits>      // LLONG_MAX marks "no path known"

using namespace std;    // write cout, min without std::

// adj_mat[i][j] starts as the direct edge cost and ends as the cheapest cost
// from i to j. The array is changed in place (arrays are passed by address).
void floyd_warshall(long long adj_mat[105][105], int n){
    // k = the node we now allow as a stop in the middle of a route.
    // After round k, adj_mat[i][j] is the best route whose middle stops are
    // only from 1..k. When k reaches n, every route is allowed.
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){          // i = start node
            for(int j=1; j<=n; j++){      // j = end node
                // Is "i to k, then k to j" cheaper than what we have for i to j?
                // Both halves must exist; adding to LLONG_MAX would overflow.
                if(adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]){
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];   // go via k
                }
            }
        }
    }
}

int main(){
    int n, e;          // nodes, edges
    cin >> n >> e;

    long long adj_mat[105][105];   // adjacency matrix (Module 1), 1-based

    // Start: 0 from a node to itself, "infinity" everywhere else.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                adj_mat[i][j] = 0;
            } else{
                adj_mat[i][j] = LLONG_MAX;
            }
        }
    }

    while(e--){        // read the e edges
        int a, b;      // from, to
        long long c;   // cost (up to 10^9)
        cin >> a >> b >> c;
        // The same pair can be given twice (the sample has 1 -> 2 with cost 4
        // and with cost 10). Keep only the cheaper edge; a plain assignment
        // would let the later, dearer one overwrite it.
        adj_mat[a][b] = min(adj_mat[a][b], c);   // directed: a -> b only
    }

    // Build the all-pairs table. Passing adj_mat passes the address of its
    // first row, so the function fills THIS array.
    floyd_warshall(adj_mat, n);

    int q;             // number of queries
    cin >> q;

    // Every question is now just a look-up in the finished table.
    while(q--){
        int X, Y;      // source, destination
        cin >> X >> Y;

        if(adj_mat[X][Y] == LLONG_MAX){
            cout << -1 << endl;        // still "infinity": no route at all
        } else{
            cout << adj_mat[X][Y] << endl;
        }
    }

    // Cost: O(N^3) once (10^6 steps for N = 100), then O(1) per query.
    return 0;
}
