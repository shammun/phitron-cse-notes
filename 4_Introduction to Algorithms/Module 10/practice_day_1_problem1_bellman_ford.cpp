/*

https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

Bellman-Ford

Given a weighted and directed graph of v vertices and edges, Find the shortest distance of all the vertex's from the source 
vertex, src and return a list of integers where the ith integer denotes the distance of the ith node from the source node. If a 
vertices can't be reach from the s then mark the distance as 10^8.
Note: If there exist a path to a negative weighted cycle from the source node then return {-1}.

Examples:

Input: edges = [[0,1,9]], src = 0

Output: [0, 9]
Explanation: Shortest distance of all nodes from source is printed

Input: edges = [[0,1,5], [1,0,3], [1,2,-1], [2,0,1]], src = 2
Output: [1, 6, 0]
Explanation: For nodes 2 to 0, we can follow the path: 2-0. This has a distance of 1. For nodes 2 to 1, we cam follow the path: 
2-0-1, which has a distance of 1+5 = 6,

Constraints:
1 ≤ V ≤ 500
1 ≤ E ≤ V*(V-1)
-1000 ≤ data of nodes, weight ≤ 1000
0 ≤ S < V

*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
      /*  Function to implement Bellman Ford
       *   edges: vector of vectors which represents the graph
       *   src: source vertex
       *   V: number of vertices
       */
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
          // Code here
          vector<int> dist(V, 100000000);
          dist[src] = 0;
          
          for(int i=0; i< V-1; i++){
              for(auto edge : edges){
                  int u = edge[0];
                  int v = edge[1];
                  int w = edge[2];
                  if(dist[u] != 100000000 && dist[u] + w < dist[v]){
                      dist[v] = dist[u] + w;
                  }
              }
          }
          
          for(auto edge : edges){
              int u = edge[0];
              int v = edge[1];
              int w = edge[2];
              if(dist[u] != 100000000 && dist[u] + w < dist[v]){
                  return {-1};
              }
          }
          return dist;
      }
  };