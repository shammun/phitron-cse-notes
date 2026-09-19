#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
// Bellman-Ford: shortest paths from one source, even when a weight is negative.
using namespace std;
// (Dijkstra cannot do that. The note at the end of this file explains why.)
int dis[1005];            // dis[i] = cheapest cost known so far to node i
vector<Edge> edge_list;
// ^ the whole graph in one flat list - and a BUG: Edge is not yet known here.
class Edge{
    public:
        int a, b, c;      // the edge a -> b costs c, and c may be negative
        Edge(int a, int b, int c){
            this->a = a;  // this-> is needed: the parameter hides the field
            this->b = b;
            this->c = c;
        }
};
// The fix: move this class Edge block above line 9, then the file compiles.
// Relax one edge a -> b of cost c: take the cheaper of dis[b] and dis[a] + c.
void bellman_ford(int n){
    for(int i=0; i<n-1; i++){   // n-1 rounds; why n-1 is explained at the end
        // relaxing edges: one sweep over every edge, in any order
        for(auto ed : edge_list){
            int a, b, c;
            a = ed.a;   // from
            b = ed.b;   // to
            c = ed.c;   // cost
            // The guard comes first: INT_MAX + c overflows and wraps round to a
            if(dis[a] != INT_MAX && dis[a] + c < dis[b]){ // big negative, a fake bargain
                dis[b] = dis[a] + c;
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
    while(e--){
        int a, b, c;
        cin >> a >> b >> c;   // then Edge(a, b, c) builds one edge object
        edge_list.push_back(Edge(a, b, c));
    }

    // Handy while learning: print the edges back to check they were read right.
    /*
    for(aut edge : edge_list){
        cout << edge.a << " " << edge.b << " " << edge.c << endl;
    }
    */

    // Everything starts out unreachable, at infinity, except the source.
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
    bellman_ford(n);

    // A node still showing INT_MAX has no route from the source at all.
    for(int i=0; i<n; i++) {
        cout << i << "->" << dis[i] << endl;
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

    return 0;
}