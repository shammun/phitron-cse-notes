#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
// bellman-ford.cpp plus the one extra round that catches a negative cycle.
using namespace std;
// Everything down to line 35 is that file unchanged; the new part starts at 37.
int dis[1005];            // cheapest cost known so far from the source to node i
vector<Edge> edge_list;
// ^ the same BUG as in bellman-ford.cpp: Edge is used before the class exists.
class Edge{
    public:
        int a, b, c;      // the edge a -> b costs c, and c may be negative
        Edge(int a, int b, int c){
            this->a = a;
            this->b = b;
            this->c = c;
        }
};
// The fix is the same too: move this class Edge block above line 9.
// A negative cycle is a loop whose weights add up to less than zero.
void bellman_ford(int n){
    for(int i=0; i<n-1; i++){   // the n-1 settling rounds, as before
        // relaxing edges
        for(auto ed : edge_list){
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            // Guard first, or INT_MAX + c wraps round to a huge negative number.
            if(dis[a] != INT_MAX && dis[a] + c < dis[b]){
                dis[b] = dis[a] + c;
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
            cout << i << "->" << dis[i] << endl;
        }
    }
}
// Reading the graph: one flat edge list, exactly as in bellman-ford.cpp.
int main(){
    int n, e;
    cin >> n >> e;
    // e directed edges a b c. Here 1 -> 2 costs -4 and 2 -> 1 costs +1: a -3 loop.
    while(e--){
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    /*
    for(aut edge : edge_list){
        cout << edge.a << " " << edge.b << " " << edge.c << endl;
    }
    */

    for(int i=0; i<n;i++){
        dis[i] = INT_MAX;   // unreachable until proved otherwise
    }
    dis[0] = 0;

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
    bellman_ford(n);

    

    return 0;
}