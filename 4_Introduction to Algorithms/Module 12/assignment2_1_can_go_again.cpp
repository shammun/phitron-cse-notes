/*

https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/can-go-again

Can Go Again?

Problem Statement

You will be given N numbers of nodes, E numbers of edges in a graph. For each edge you will be given A, B and 
W which means there is a connection from A to B only and for which you need to give W cost. The value of nodes 
could be from 1 to N.

You will be given a source node S. Then you will be given a test case T, for each test case you will be given a 
destination node D. You need to tell the minimum cost from source node to destination. If there is no possible 
path from S to D then print Not Possible.

Note: If there is a negative weight cycle in the graph, then no answer would be correct. So print one line only - 
"Negative Cycle Detected".

Input Format

First line will contain  and .
Next  lines will contain ,  and .
Next line will contain source node .
Next line will contain , the number of test cases.
For each test case, you will get .

Constraints

1. 1 <= N <= 1000
2. 1 <= E <= 10^6
3. 1 <= S <= N
4. 1 <= T <= 10^3
5. 1 <= D <= N
6. -10^9 <= W <= 10^9

Output Format

Output the minimum cost for each test case.
Sample Input 0
5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
1
5
1
2
3
4
5

Sample Output 0
0
-1
-2
-5
0

Sample Input 1
5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
5
5
1
2
3
4
5

Sample Output 1
Not Possible
Not Possible
Not Possible
Not Possible
0

Sample Input 2
5 8
1 2 -2
1 3 -10
3 2 1
2 4 7
4 3 -3
4 5 5
2 5 2
4 1 1
1
5
1
2
3
4
5

Sample Output 2
Negative Cycle Detected

*/

// Solution idea (Bellman-Ford, Module 9).
// Edges are one-way and may be negative, so Dijkstra is out: it assumes a
// settled node can never get cheaper, and a negative edge breaks that promise.
// Bellman-Ford does not care about the sign. It relaxes every edge n-1 times,
// then does one extra round: if anything still improves, a negative cycle is
// reachable and no "minimum cost" exists, which is exactly the special message.
//
// "Relaxing" edge a -> b (cost c) means: if reaching a and then taking this
// edge is cheaper than the best known way to b, remember that cheaper cost.
//
// Trace with Sample 0 (source 1): after the rounds dis[1]=0, dis[3]=-2,
// dis[2]=-2+1=-1, dis[4]=-2-3=-5, dis[5]=-1+2=1... and 4->5 gives -5+5=0,
// so dis[5]=0. Output 0, -1, -2, -5, 0.

#include <iostream>     // cin, cout, endl
#include <vector>       // vector - the edge list
#include <climits>      // LLONG_MAX, our "infinity"

using namespace std;    // no std:: prefix

// One directed edge a -> b with cost c, stored as an object (the edge list of
// Module 1). Bellman-Ford only ever loops over edges, so a list is all it needs.
class Edge{
    public:            // members usable from outside the class
    int a, b, c;       // from, to, cost (|c| <= 10^9 fits in an int)
    // Constructor: runs when an Edge is created, e.g. Edge(1, 2, 10).
    // The parameters have the same names as the members, so "this->a" means
    // "the member a of this object" and plain "a" means the parameter.
    Edge(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;  // every edge of the graph, global so all code sees it
// long long, not int: a path can use up to 999 edges of cost up to 10^9 each,
// which is far past the int limit of about 2.1 * 10^9.
long long dis[1005];    // dis[x] = cheapest known cost from the source to x

// Fills dis[] and returns true if a negative cycle is reachable from source.
bool bellman_ford(int n, int source){
    dis[source] = 0;    // the source costs nothing to reach

    // n-1 rounds (i = 1 .. n-1). A cheapest path visits each node at most once,
    // so it has at most n-1 edges, and every round fixes at least one more edge
    // of it. After n-1 rounds every honest distance is final.
    for(int i=1; i<n; i++){
        // Range-for: "edge" is a copy of each Edge in the list in turn.
        for(auto edge : edge_list){
            int a = edge.a;   // start of the edge
            int b = edge.b;   // end of the edge
            int c = edge.c;   // its cost

            // Relax a -> b. The LLONG_MAX guard matters twice: an unreached a
            // has no route to extend, and LLONG_MAX + a positive c would overflow.
            if(dis[a] != LLONG_MAX && dis[a] + c < dis[b]){
                dis[b] = dis[a] + c;   // cheaper route to b found
            }
        }
    }

    // The extra round. Nothing honest can improve any more, so an improvement
    // now means a loop whose total is negative: walk it again and it gets cheaper.
    for(auto edge : edge_list){
        int a = edge.a;
        int b = edge.b;
        int c = edge.c;

        if(dis[a] != LLONG_MAX && dis[a] + c < dis[b]){
            return true;    // still improving: negative cycle
        }
    }

    return false;           // everything settled: no reachable negative cycle
}

int main(){
    int n, e;              // nodes, edges
    cin >> n >> e;

    for(int i=0; i<e; i++){    // read the e edges
        int a, b, c;
        cin >> a >> b >> c;
        // Edge(a, b, c) builds a temporary object; push_back copies it to the
        // end of the list.
        edge_list.push_back(Edge(a, b, c));   // one-way: only a -> b is stored
    }

    // Nodes are numbered 1..n; every one starts "not reached yet".
    for(int i=1; i<=n;i++){
        dis[i] = LLONG_MAX;
    }

    int source;            // the start node S
    cin >> source;

    int t;                 // number of queries
    cin >> t;

    // One run from the source answers every query: only the destination changes.
    bool negative_cycle = bellman_ford(n, source);

    // With a negative cycle the problem wants a single line and nothing else,
    // so we stop before reading or answering any query.
    if(negative_cycle){
        cout << "Negative Cycle Detected" << endl;
        return 0;          // end the program here
    }

    while(t--){            // answer the t queries
        int dest;          // destination D
        cin >> dest;

        if(source == dest){
            cout << 0 << endl;                 // staying put costs nothing
        } else if(dis[dest] == LLONG_MAX){
            cout << "Not Possible" << endl;    // never reached from the source
        } else {
            cout << dis[dest] << endl;         // the cheapest cost
        }
    }

    // Cost: O(n * E) for Bellman-Ford, then O(1) per query.
    return 0;
}
