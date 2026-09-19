// Dijkstra's algorithm, the version you should actually use.
//
// Put this file next to dijkstra_naive.cpp: the relaxation test, the dis array and
// the loop over neighbours are letter for letter the same. One thing changed. The
// plain queue became a min-priority queue, the one built in priority_queue_of_
// pairs.cpp, and the pair was flipped from {node, distance} to {distance, node} so
// that the heap orders by distance.
//
// Why that one swap matters. The FIFO queue handed back whichever node had waited
// longest, which has nothing to do with being close, so a node kept being improved
// and re-expanded. The heap always hands back the node with the smallest known
// distance. Every other node still waiting is at least that far away, and edge
// weights are never negative, so no route through them can come back cheaper:
// that smallest distance is final the moment it is popped. Each node therefore
// needs to be expanded only once, and the cost falls to O((V + E) log V).
//
// That argument is exactly where Dijkstra breaks on negative edges. A later,
// negative edge could make a longer-looking route cheaper after all, so "final
// when popped" stops being true. That is Bellman-Ford's job, in Module 9.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>
using namespace std;

vector<pair<int, int>> adj_list[105];
int dis[105];

void dijkstra(int src){
    // greater<> makes it a min-heap: the smallest pair comes out on top.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});   // {distance, node}: distance first, so the heap sorts on it
    dis[src] = 0;

    while(!pq.empty()){
        pair<int, int> par = pq.top();   // the closest node still waiting
        pq.pop();
        int par_node = par.second;   // the flipped pair: node in .second
        int par_dist = par.first;    // and its distance in .first

        // A node is pushed again each time its distance improves, so the heap can
        // hold several copies of the same node with different distances. The old,
        // larger copies are stale: by the time they surface, dis[par_node] is
        // already smaller, and expanding them only redoes work that is finished.
        // The standard guard is one line here:
        //     if(par_dist > dis[par_node]) continue;
        // Leaving it out does not give wrong answers, because the relaxation test
        // below simply fails for every neighbour of a stale pair. It just costs a
        // pass over that node's edges. On a big graph it is worth adding.

        for(auto child : adj_list[par_node]){
            int child_node = child.first;
            int child_dist = child.second;

            if(par_dist + child_dist < dis[child_node]){
                dis[child_node] = par_dist + child_dist;
                // Push {distance, node}, in that order, or the heap will sort by
                // node number and quietly stop being Dijkstra.
                pq.push({dis[child_node], child_node});
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    

    while(e--){
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    for(int i=0; i<n; i++){
        dis[i] = INT_MAX;   // infinity until a route is found
    }

    dijkstra(0);

    // This is the printing loop that dijkstra_naive.cpp forgot. On the sample the
    // answer for node 1 is 7, not 10: Dijkstra preferred 0-2-1 (3 + 4) over the
    // single edge 0-1 that costs 10. A node left at INT_MAX would mean no route
    // exists at all.
    for(int i=0; i<n; i++){
        cout << i << "->" << dis[i] << endl;
    }

    return 0;
}