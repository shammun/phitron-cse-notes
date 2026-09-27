// Bellman-Ford: shortest paths from one source, even when a weight is negative.
// (Dijkstra cannot do that. The note at the end of this file explains why.)
//
// Idea in one line: "relax" every edge, over and over, n-1 times. Relaxing the
// edge a -> b of cost c means: if going to a and then taking this edge is
// cheaper than the best known way to b, remember the cheaper cost for b.
//
// Example input (4 nodes, 4 directed edges, source is always node 0):
//   4 4
//   0 1 4
//   0 2 5
//   2 1 -3
//   1 3 2
// Output:
//   0->0
//   1->2      (0 -> 2 -> 1 costs 5 + (-3) = 2, cheaper than the direct 4)
//   2->5
//   3->4      (0 -> 2 -> 1 -> 3 costs 2 + 2 = 4)

#include <iostream>   // cin / cout. With g++ it also happens to bring in INT_MAX
                      // (strictly, INT_MAX belongs to <climits>).
#include <queue>      // queue / priority_queue (not used here; course template)
#include <cstring>    // memset (not used here; course template)
#include <vector>     // vector: the growable array that holds the edge list
using namespace std;  // lets us write vector / cout without the std:: prefix

// A global array: globals start at 0 automatically, and 1005 cells means node
// numbers up to 1004 fit. dis is reset to INT_MAX in main before it is used.
int dis[1005];            // dis[i] = cheapest cost known so far to node i

// Edge: a small class that bundles the three numbers describing one edge.
class Edge{
    public:               // public: code outside the class may read a, b, c
        int a, b, c;      // the edge a -> b costs c, and c may be negative
        // Constructor: runs when we write Edge(a, b, c) and fills the fields.
        Edge(int a, int b, int c){
            this->a = a;  // this-> is needed: the parameter hides the field
            // (this is a pointer to the object being built; this->a is its
            //  field a, while plain a is the parameter.)
            this->b = b;  // store the destination
            this->c = c;  // store the cost
        }
};
// A class must be declared before vector<Edge> can mention it.
// The whole graph in one flat list of Edge objects (an "edge list"). It is
// global, so both bellman_ford and main can use it; it starts empty.
vector<Edge> edge_list;

// bellman_ford(n): n = number of nodes. Reads edge_list and improves dis[]
// in place; returns nothing (void). Before calling, dis must hold 0 for the
// source and INT_MAX ("not reached yet") for everything else.
void bellman_ford(int n){
    // Outer loop: i counts rounds, 0 .. n-2, so exactly n-1 rounds.
    for(int i=0; i<n-1; i++){   // n-1 rounds; why n-1 is explained at the end
        // relaxing edges: one sweep over every edge, in any order
        // auto ed : edge_list -> ed is a copy of each Edge in turn.
        for(auto ed : edge_list){
            int a, b, c;
            a = ed.a;   // from
            b = ed.b;   // to
            c = ed.c;   // cost
            // Relax a -> b. The guard dis[a] != INT_MAX comes first: if a is not
            // reached yet there is nothing to extend, and INT_MAX + c would
            // overflow and wrap round to a big negative number, a fake bargain.
            // && stops early, so dis[a] + c is only computed when a IS reached.
            if(dis[a] != INT_MAX && dis[a] + c < dis[b]){
                dis[b] = dis[a] + c;   // found a cheaper route to b: keep it
            }
        }
    }
}

// No adjacency list here: the algorithm only ever sweeps over all edges.
int main(){
    int n, e;
    cin >> n >> e;      // n nodes, then e directed edges
    // One line per edge, a b c, stored once because the edge is one-way. They are
    // simply appended in input order; the order they are relaxed in never matters.
    // while(e--) runs the body exactly e times (test e, then subtract 1).
    while(e--){
        int a, b, c;
        cin >> a >> b >> c;   // then Edge(a, b, c) builds one edge object
        edge_list.push_back(Edge(a, b, c));   // append it to the end of the list
    }

    // Handy while learning: print the edges back to check they were read right.
    // (Note: "aut" is a typo for "auto"; fix it before un-commenting.)
    /*
    for(aut edge : edge_list){
        cout << edge.a << " " << edge.b << " " << edge.c << endl;
    }
    */

    // Everything starts out unreachable, at infinity, except the source.
    // INT_MAX is the largest int (2147483647); here it stands for "infinity".
    for(int i=0; i<n;i++){
        dis[i] = INT_MAX;
    }
    dis[0] = 0;   // node 0 is the source here; reaching it costs nothing

    // Why n-1 rounds, and why that is enough.
    //
    // A shortest path can never visit the same node twice, because cutting the
    // repeat out would only make it cheaper. So it touches at most n nodes and
    // therefore uses at most n-1 edges.
    //
    // Now watch what one round buys. Before any round, every path of 0 edges is
    // correct (only the source). A full sweep over all edges relaxes, among
    // others, the last edge of every shortest path that uses 1 edge, so after
    // round 1 every 1-edge shortest path is correct. After round 2 every 2-edge
    // one is, and so on. The edges may be swept in any order: a round can only
    // ever improve things, never spoil them, and the worst case is that just one
    // more edge of each path settles per round.
    //
    // Since no shortest path is longer than n-1 edges, n-1 rounds settle them all.
    //
    // Trace with the example at the top (edges in order 0-1, 0-2, 2-1, 1-3):
    //   start:   dis = {0, INF, INF, INF}
    //   round 1: 0->1 gives dis[1]=4; 0->2 gives dis[2]=5;
    //            2->1 gives 5-3=2 < 4 so dis[1]=2; 1->3 gives dis[3]=4
    //   rounds 2 and 3 change nothing: dis = {0, 2, 5, 4}
    bellman_ford(n);

    // A node still showing INT_MAX has no route from the source at all.
    for(int i=0; i<n; i++) {
        cout << i << "->" << dis[i] << endl;   // "node->cost", one per line
    }

    // Cost: e edges swept n-1 times, so O(V * E). Slower than Dijkstra's
    // O((V + E) log V), and that is the trade. Dijkstra is fast because it
    // assumes a node's distance is final as soon as it is the closest one left,
    // which a negative edge further on can make false. Bellman-Ford assumes
    // nothing and just keeps relaxing, so negative weights do not bother it.
    //
    // It does have a limit: if a cycle has a negative total weight, going round
    // it again is always cheaper and there is no shortest path to speak of. One
    // extra round spots that; bellman_ford_cycle.cpp is the same file with that
    // round added.

    return 0;             // program ended normally
}