// Shortest paths with weights, first attempt: a plain queue.
//
// Module 2 got shortest distances out of BFS because every edge cost one step, so
// the ring a node came out in was its distance. Put weights on the edges and that
// collapses: the direct edge 0-1 here costs 10, while going 0-2-1 costs 3 + 4 = 7,
// two edges but a cheaper trip. Counting edges is no longer the right answer.
//
// What still works is relaxation. Keep dis[v], the cheapest cost found to v so
// far, starting at infinity for everybody except the source. Whenever you are at
// u and see an edge u-v of weight w, ask: is dis[u] + w cheaper than what I have
// written down for v? If it is, write the better number down and put v back in
// the queue so its own neighbours can be re-examined with the improvement.
//
// This file does exactly that with an ordinary FIFO queue, and it gets the right
// answers. The price is that a node can be pulled out and re-processed many times,
// once for every improvement that ever reaches it, and each of those improvements
// ripples outwards again. dijkstra_optimized.cpp fixes it with one change: take
// the node with the smallest known distance out first, instead of the oldest.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>
using namespace std;

vector<pair<int, int>> adj_list[105];   // {neighbour, weight}, as in Module 6
int dis[105];                           // best cost known so far to each node

void dijkstra(int src){
    // A plain queue: first in, first out. It knows nothing about distances.
    queue<pair<int, int>> q;
    q.push({src, 0});   // here the pair is {node, distance}
    dis[src] = 0;       // reaching the source costs nothing

    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();
        int par_node = par.first;
        int par_dist = par.second;

        for(auto child : adj_list[par_node]){
            int child_node = child.first;    // .first is the neighbour
            int child_dist = child.second;   // .second is the weight of the edge

            // The relaxation test. Note there is no visited array anywhere in
            // Dijkstra: a node is not "done" once seen, it is done once nothing
            // can improve its distance. This if is what decides that.
            if(par_dist + child_dist < dis[child_node]){
                dis[child_node] = par_dist + child_dist;
                // Pushed again with the improved figure, because everything
                // reachable through it just got cheaper too and has to hear
                // about it. This is where the wasted work comes from.
                q.push({child_node, dis[child_node]});
            }
        }
    }
    // It ends because dis only ever goes down and cannot go below the true
    // shortest distance, so eventually no test succeeds and nothing is pushed.
}

int main(){
    int n, e;
    cin >> n >> e;
    

    while(e--){
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});   // undirected, both ways cost the same
    }

    // Infinity has to be a real number, and INT_MAX is the usual stand-in: any
    // genuine path is cheaper, so the first route found always wins the test.
    // The trap that comes with it: never add anything to a distance that is still
    // INT_MAX, or it overflows and wraps round to a negative. Here the addition
    // uses par_dist, which came out of the queue and is therefore a real cost, so
    // the file is safe. Bellman-Ford in Module 9 needs an explicit guard.
    for(int i=0; i<n; i++){
        dis[i] = INT_MAX;
    }

    dijkstra(0);

    // A copy-paste slip: this loop was meant to PRINT the answers, but it repeats
    // the initialisation instead and wipes them. That is why the program prints
    // nothing at all. It should be the line from dijkstra_optimized.cpp:
    //     cout << i << "->" << dis[i] << endl;
    // The distances it worked out, and then threw away, are 0, 7, 3, 9.
    for(int i=0; i<n; i++){
        dis[i] = INT_MAX;
    }

    return 0;
}