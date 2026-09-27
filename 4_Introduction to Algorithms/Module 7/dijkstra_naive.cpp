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
//
// Sample input (n = 3 nodes, e = 3 edges, each edge "a b weight"):
//     3 3
//     0 1 10
//     0 2 3
//     2 1 4
// Output:
//     0->0
//     1->7
//     2->3
//
// Trace of the queue on that sample ({node, distance} pairs):
//   start: dis = {0, INF, INF}, queue = [{0,0}]
//   pop {0,0}: edge 0-1 (10): 0+10 < INF -> dis[1]=10, push {1,10}
//              edge 0-2 (3):  0+3  < INF -> dis[2]=3,  push {2,3}
//   pop {1,10}: edge 1-0: 10+10 < 0? no.  edge 1-2: 10+4 < 3? no.
//   pop {2,3}:  edge 2-0: 3+3 < 0? no.   edge 2-1: 3+4 = 7 < 10 -> dis[1]=7, push {1,7}
//   pop {1,7}:  nothing improves. Queue empty, done.
//   Node 1 was expanded TWICE (once with 10, once with 7): that is the waste.

#include <iostream>     // cin (read input) and cout (print output)
#include <vector>       // vector: an array that can grow with push_back
#include <algorithm>    // general helpers (min, max, sort); not really needed here
#include <string>       // string type; not used here, left from a template
#include <stack>        // stack; not used here, left from a template
#include <queue>        // queue (FIFO) and priority_queue; this file uses queue
using namespace std;    // lets us write cout, vector, pair... instead of std::cout, std::vector...

// The weighted adjacency list. adj_list is an ARRAY of 105 vectors, one per node
// (nodes 0..104 fit). adj_list[u] lists every edge that leaves u, and each entry is
// a pair {neighbour, weight}: .first = the node at the other end, .second = the
// cost of that edge. It is global so dijkstra() and main() can both see it, and
// globals start out empty/zero automatically.
vector<pair<int, int>> adj_list[105];   // {neighbour, weight}, as in Module 6
int dis[105];                           // best cost known so far to each node

// dijkstra(src): fills dis[] with the cheapest cost from src to every node.
// Parameter src = the start node. Returns nothing (the answer is left in dis[]).
// Before calling, main must set every dis[i] to INT_MAX ("not reached yet").
void dijkstra(int src){
    // A plain queue: first in, first out. It knows nothing about distances.
    // Each item is a pair {node, distance-when-pushed}.
    queue<pair<int, int>> q;
    q.push({src, 0});   // here the pair is {node, distance}; {a, b} builds a pair
    dis[src] = 0;       // reaching the source costs nothing

    // Keep going while there is still some node whose news has not been spread.
    // One pass = take the oldest waiting node and try to improve its neighbours.
    while(!q.empty()){                  // empty() is true when nothing is left
        pair<int, int> par = q.front(); // front() looks at the oldest item (does not remove it)
        q.pop();                        // pop() removes that oldest item
        int par_node = par.first;       // the node we are standing at ("parent")
        int par_dist = par.second;      // the cost with which it was pushed

        // Range-for: child takes each pair in adj_list[par_node] in turn, i.e.
        // each edge leaving par_node. auto lets the compiler work out the type
        // (here pair<int,int>) so we do not have to spell it.
        for(auto child : adj_list[par_node]){
            int child_node = child.first;    // .first is the neighbour
            int child_dist = child.second;   // .second is the weight of the edge

            // The relaxation test. Note there is no visited array anywhere in
            // Dijkstra: a node is not "done" once seen, it is done once nothing
            // can improve its distance. This if is what decides that.
            // Reads: "cost to reach par_node + this edge" beats the best so far?
            if(par_dist + child_dist < dis[child_node]){
                dis[child_node] = par_dist + child_dist;   // write down the better cost
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
    int n, e;          // n = number of nodes (numbered 0..n-1), e = number of edges
    cin >> n >> e;     // cin >> skips spaces/newlines and reads the next whole number


    // Read the e edges. while(e--) runs exactly e times: it tests e, then
    // subtracts 1, so it stops after the test sees 0.
    while(e--){
        int a, b, c;             // an edge between a and b that costs c
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});   // push_back adds {b, c} to the end of a's list
        adj_list[b].push_back({a, c});   // undirected, both ways cost the same
    }

    // Infinity has to be a real number, and INT_MAX is the usual stand-in: any
    // genuine path is cheaper, so the first route found always wins the test.
    // (INT_MAX = 2147483647, the largest int; it comes from <climits>, which
    // <iostream> happens to pull in with g++.)
    // The trap that comes with it: never add anything to a distance that is still
    // INT_MAX, or it overflows and wraps round to a negative. Here the addition
    // uses par_dist, which came out of the queue and is therefore a real cost, so
    // the file is safe. Bellman-Ford in Module 9 needs an explicit guard.
    for(int i=0; i<n; i++){
        dis[i] = INT_MAX;        // nobody has been reached yet
    }

    dijkstra(0);                 // run from node 0; afterwards dis[i] is the answer for i

    // Print the answer: the cheapest cost from node 0 to every node.
    // (Watch out: this loop is easy to paste as a second copy of the INT_MAX
    // loop above, which silently wipes the answers and prints nothing.)
    // A node still showing 2147483647 (INT_MAX) cannot be reached from 0.
    for(int i=0; i<n; i++){
        cout << i << "->" << dis[i] << endl;   // endl = newline + flush the output
    }

    return 0;                    // 0 tells the system the program finished normally
}
