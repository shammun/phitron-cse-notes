/*

Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether 
the graph contains any cycle or not. The Graph is represented as an adjacency list, where 
adj[i] contains all the vertices that are directly connected to vertex i.

NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between 
vertex i and vertex j, both j will be adj[i] and i will be in adj[j].

Examples:

*/

// detect_cycle_in_undirected_graph_dfs.cpp in the shape GFG asks for: the graph
// arrives as adj (a vector of vectors), and we return true/false instead of
// printing. The rule is the same: while walking DFS, meeting a neighbour that is
// ALREADY visited and is NOT the node we just came from means there is a second
// way back to it, i.e. a cycle.

class Solution {
    public:
      // DFS from src. parent = the node we arrived from (-1 for a start node).
      // Returns true as soon as a cycle is found anywhere below src.
      bool dfs(int src, int parent, vector<bool>& vis, vector<vector<int>>& adj){
          vis[src] = true;
          
          for(int child : adj[src]){
              // Seen before, and not simply the edge we walked in on: cycle.
              // (The parent is always visited, because an undirected edge is
              // stored both ways; that edge alone is not a cycle.)
              if(vis[child] && parent != child){
                  return true;
              }
              // New node: go deeper, with src as its parent. If the deeper
              // search found a cycle, pass the good news straight up.
              if(!vis[child]){
                  if(dfs(child, src, vis, adj)){
                      return true;
                  }
              }
          }
          
          return false;   // explored everything below src, no cycle
      }
      
      bool isCycle(vector<vector<int>>& adj) {
          // Code here
          int n = adj.size();          // number of vertices
          vector<bool> vis(n, false);  // local, so every call starts clean
          
          // The graph may be in several pieces, and the cycle may live in any
          // of them: start a DFS from every node not yet visited.
          for(int i=0; i<n; i++){
              if(!vis[i]){
                  if(dfs(i, -1, vis, adj)){
                      return true;
                  }
              }
          }
          return false;   // O(V + E)
      }
  };