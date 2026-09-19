/*

Distance from the Source (Bellman-Ford)   (GeeksforGeeks)

A directed graph has V vertices, numbered 0 .. V-1, and a list of edges. Each
edge is given as three numbers u, v, w: an edge from u to v of weight w. The
weights may be negative. Starting from a vertex src, report the shortest
distance to every vertex, in vertex order. A vertex that cannot be reached
from src gets the judge's "infinity" value 100000000 (10^8). If a negative
cycle can be reached from src, no shortest distance exists, and the answer is
the single value -1.

Why Bellman-Ford and not Dijkstra: Dijkstra settles a vertex for good the
moment it is taken out of the priority queue, and a negative edge can make a
settled distance wrong later. Bellman-Ford makes no such promise; it simply
relaxes every edge again and again.

Input (for this file's small test driver)
The first line has V and E: the number of vertices and the number of edges.
The next E lines each have u, v and w.
The last line has src.

Output
The word "dist =" followed by the distance of vertex 0, 1, ..., V-1, or
"dist = -1" when a reachable negative cycle makes the answer meaningless.

Example

input
3 4
0 1 5
1 0 3
1 2 -1
2 0 1
2

output
dist = 1 6 0

Vertex 2 is the source, so its distance is 0. The edge 2 -> 0 costs 1. From
there the edge 0 -> 1 costs 5, so vertex 1 sits at 1 + 5 = 6.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      /*  Function to implement Bellman Ford
       *   edges: vector of vectors which represents the graph
       *   src: source vertex
       *   V: number of vertices
       */
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
          const int INF = 100000000;   // the value the judge asks for

          vector<int> dist(V, INF);
          dist[src] = 0;

          /* A shortest path that does not repeat a vertex uses at most V-1
             edges, and one full pass over the edge list fixes at least one
             more edge of every such path. V-1 passes are therefore enough. */
          for(int i = 0; i < V - 1; i++) {
              for(auto edge : edges) {
                  int u = edge[0];
                  int v = edge[1];
                  int w = edge[2];
                  /* The dist[u] != INF guard matters: u may be unreachable,
                     and a negative w would otherwise turn the fake INF into a
                     smaller number and make v look reachable. */
                  if(dist[u] != INF && dist[u] + w < dist[v]) {
                      dist[v] = dist[u] + w;
                  }
              }
          }

          /* One extra pass. Nothing should improve any more. If something
             still does, the improvement can be repeated forever, which means
             a negative cycle sits on the way from src. */
          for(auto edge : edges) {
              int u = edge[0];
              int v = edge[1];
              int w = edge[2];
              if(dist[u] != INF && dist[u] + w < dist[v]) {
                  return {-1};
              }
          }

          return dist;
      }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    for(int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cin >> src;

    Solution ob;
    vector<int> dist = ob.bellmanFord(V, edges, src);

    cout << "dist =";
    for(int x : dist) {
        cout << " " << x;
    }
    cout << endl;

    return 0;
}
