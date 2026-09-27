// bellman-ford.cpp plus the one extra round that catches a negative cycle.
//
// A negative cycle is a loop whose weights add up to less than zero. If the
// source can reach one, "shortest path" has no answer: every trip round the loop
// makes the total smaller still. This file runs the usual n-1 rounds, then ONE
// more sweep that only checks: if any edge can still be relaxed, a negative
// cycle exists. Everything up to the end of the n-1 rounds is the same as
// bellman-ford.cpp; the new part is the extra check sweep inside bellman_ford.
//
// Example input with a negative cycle (3 nodes, 3 directed edges a b c):
//   3 3
//   0 1 2
//   1 2 -4
//   2 1 1
// Here 1 -> 2 costs -4 and 2 -> 1 costs +1: the loop 1 -> 2 -> 1 totals -3.
// Output: Negative weighted cycle detected
// Change "2 1 1" to "2 1 5" (loop total +1) and the output becomes:
//   No negative weighted cycle detected
//   0->0
//   1->2
//   2->-2

#include <iostream>   // cin / cout. With g++ it also brings in INT_MAX
                      // (strictly, INT_MAX belongs to <climits>).
#include <queue>      // not used here; course template line
#include <cstring>    // memset; not used here; course template line
#include <vector>     // vector: holds the edge list
using namespace std;  // lets us write vector / cout without std::

// Global array (starts at 0); cells for nodes 0..1004. Set to INT_MAX in main.
int dis[1005];            // cheapest cost known so far from the source to node i

// One directed, weighted edge.
class Edge{
    public:               // fields readable from outside the class
        int a, b, c;      // the edge a -> b costs c, and c may be negative
        // Constructor: Edge(a, b, c) makes an object with these three values.
        Edge(int a, int b, int c){
            this->a = a;  // this->a is the field; plain a is the parameter
            this->b = b;
            this->c = c;
        }
};
// A class must be declared before vector<Edge> can mention it.
vector<Edge> edge_list;
// ^ the graph as one flat list of edges, as in bellman-ford.cpp.

// bellman_ford(n): n = number of nodes. Runs n-1 relaxing rounds on dis[],
// then one checking round, and prints either the distances or a warning.
void bellman_ford(int n){
    for(int i=0; i<n-1; i++){   // the n-1 settling rounds, as before
        // relaxing edges
        for(auto ed : edge_list){   // ed = a copy of each edge in turn
            int a, b, c;
            a = ed.a;               // from
            b = ed.b;               // to
            c = ed.c;               // cost
            // Guard first, or INT_MAX + c wraps round to a huge negative number.
            // (&& skips the addition when a is still unreached.)
            if(dis[a] != INT_MAX && dis[a] + c < dis[b]){
                dis[b] = dis[a] + c;    // cheaper route to b found: keep it
            }
        }
    }
    // One more sweep, identical to the ones above except that it changes nothing.
    // checking for negative cycle by running an extra iteration
    bool cycle = false;   // "did anything still get cheaper?"
    for(auto ed : edge_list){
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
        // Same relax test, but here we only ASK; nothing is ever written.
        if(dis[a] != INT_MAX && dis[a] + c < dis[b]){
            cycle = true;
            break;   // one improvement is proof enough; no need to look further
        }
    }
    if(cycle){
        // dis is meaningless now, so it is not printed: no shortest path exists.
        cout << "Negative weighted cycle detected" << endl;
    } else { // print when there is no negative cycle
        cout << "No negative weighted cycle detected" << endl;
        for(int i=0; i<n; i++) {
            cout << i << "->" << dis[i] << endl;   // "node->cost"
        }
    }
}

// Reading the graph: one flat edge list, exactly as in bellman-ford.cpp.
int main(){
    int n, e;
    cin >> n >> e;        // n nodes, e directed edges
    // e directed edges a b c (see the example at the top of the file).
    // while(e--) runs the body exactly e times.
    while(e--){
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));   // build an Edge and append it
    }

    // Debug print of the edges, switched off. ("aut" is a typo for "auto";
    // fix it before un-commenting or it will not compile.)
    /*
    for(aut edge : edge_list){
        cout << edge.a << " " << edge.b << " " << edge.c << endl;
    }
    */

    for(int i=0; i<n;i++){
        dis[i] = INT_MAX;   // unreachable until proved otherwise
    }
    dis[0] = 0;             // node 0 is the source: cost 0 to reach itself

    // Why one extra round is exactly the right test.
    //
    // A shortest path uses at most n-1 edges, so after n-1 rounds every distance
    // that CAN settle has settled, and another sweep must find nothing to improve.
    // That is the whole argument, and it only holds if there is no negative cycle.
    //
    // Now suppose there is one. Take the route to a node on that cycle and send it
    // round the loop once more: the total drops, because the loop's weights add up
    // to a negative number. Send it round again and it drops again. There is no
    // cheapest route, only cheaper and cheaper ones, so nothing can ever settle.
    // Some edge of that cycle is therefore still improvable no matter how many
    // rounds have been run, including this extra one.
    //
    // So: the extra round finds an improvement if and only if a negative cycle is
    // reachable from the source. Note the "reachable from the source" - a negative
    // cycle sitting in a part of the graph the source cannot get to is never
    // relaxed, so it is never noticed. To find those as well, start every node at
    // distance 0 instead of only the source.
    //
    // Trace with the example (edges in order 0-1, 1-2, 2-1; n-1 = 2 rounds):
    //   round 1: dis[1]=2, then dis[2]=2-4=-2, then dis[1]=-2+1=-1
    //   round 2: dis[2]=-1-4=-5, then dis[1]=-5+1=-4   -> dis = {0, -4, -5}
    //   extra:   1 -> 2 gives -4-4=-8 < -5, still improvable -> cycle reported.
    bellman_ford(n);

    

    return 0;               // program ended normally
}