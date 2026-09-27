/*

Shortest Routes II   (CSES 1672)

There are n cities and m roads between them. Every road joins two cities, can
be driven in both directions, and has a length. Two cities may be joined by
more than one road, and a road may even start and end in the same city. Then
q questions follow: for two cities, how long is the shortest route between
them? If there is no route at all, the answer is -1.

The questions come one after another and there can be many of them, so we do
not run a shortest-path search per question. Floyd-Warshall fills one table
with the shortest distance between every pair of cities, and after that each
question is a single lookup.

Input
The first line has three numbers n, m and q: cities, roads and questions.
The cities are numbered 1, 2, ..., n.
The next m lines each have three numbers a, b and c: a road of length c
between cities a and b.
The last q lines each have two numbers s and d: the two cities of a question.
n is small enough for an n x n table and for the n^3 triple loop (a few
hundred), while m and q can be much larger.

Output
For every question, print one line: the length of the shortest route, or -1 if
the cities are not connected.

Example

input
4 3 3
1 2 5
2 3 2
1 3 10
1 3
3 1
1 4

output
7
7
-1

Going 1 -> 2 -> 3 costs 5 + 2 = 7, which beats the direct road of length 10.
The roads are two-way, so 3 -> 1 costs the same. City 4 has no road at all, so
the third answer is -1.

*/

// <bits/stdc++.h>: a g++ header that includes the entire standard library
// (iostream, vector, algorithm for min, ...) in one line. Contest shortcut.
#include <bits/stdc++.h>
// So we can write cout/vector/min instead of std::cout/std::vector/std::min.
using namespace std;

/* A road can be long and a route can use many of them, so distances are
   long long. INF is 1e18/4 and not LLONG_MAX on purpose: inside the triple
   loop we add two table entries together, and INF + INF must still fit in a
   long long instead of overflowing into a negative number. Two of these still
   add up to 5e17, far below the long long limit. */
const long long INF = 1e18 / 4;

int main() {
    int n, m, q;           // cities, roads, questions
    cin >> n >> m >> q;    // read all three from the first line

    /* (n+1) x (n+1) so that the cities can keep their own numbers 1..n and
       row 0 / column 0 simply stay unused. */
    // A vector of n+1 rows; each row is itself vector<long long>(n+1, INF),
    // i.e. n+1 cells all set to INF. dist[i][j] = cheapest known i -> j cost.
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));
    // Loop over every city i and set the diagonal cell.
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;   // staying where you are costs nothing
    }

    // Read the m roads; while(m--) runs the body exactly m times.
    while(m--) {
        int a, b;       // the two end cities
        long long c;    // road length
        cin >> a >> b >> c;
        /* min, not plain assignment: there can be several roads between the
           same two cities, and a later expensive road must not wipe out a
           cheaper one that was read before it. */
        // min(x, y) returns the smaller of the two (from <algorithm>).
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);   // the roads are two-way
    }

    // Floyd-Warshall. k = the city we now also allow as a stop-over in the
    // middle of a route. It must be the OUTER loop: after round k, dist[i][j]
    // is the best route whose middle cities are all among 1..k. Round k only
    // needs rounds 1..k-1 to be finished, which the outer loop guarantees.
    // i = start city, j = end city. Total work n*n*n steps.
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            /* If k itself cannot be reached from i, no route through k can
               exist, so the whole inner row can be skipped. This also keeps
               INF values from being added up needlessly. */
            if(dist[i][k] == INF) continue;
            for(int j = 1; j <= n; j++) {
                // Is "i -> k, then k -> j" cheaper than the best i -> j so far?
                // Example: dist[1][3]=10, dist[1][2]=5, dist[2][3]=2; in round
                // k=2 we find 5+2=7 < 10, so dist[1][3] becomes 7.
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];   // take the detour
                }
            }
        }
    }

    // Answer each question with one table lookup.
    while(q--) {
        int s, d;          // start and destination of this question
        cin >> s >> d;
        if(dist[s][d] == INF) {   // never improved: s and d are not connected
            cout << -1 << "\n";   // '\n' instead of endl: q can be huge and
        } else {                  // endl flushes the output every time
            cout << dist[s][d] << "\n";   // the shortest length
        }
    }

    return 0;   // program finished successfully
}
