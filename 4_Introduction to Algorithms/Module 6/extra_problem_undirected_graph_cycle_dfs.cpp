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
//
// There is no #include, no using namespace std and no main() here: this is only
// the class GFG's judge asks for. The judge's own hidden code supplies the
// headers, builds adj from the input, creates a Solution and calls isCycle().
// (So this file does not compile on its own.)
//
// Example: adj = {{1}, {0, 2}, {1}} is the path 0-1-2 -> false.
//          adj = {{1, 2}, {0, 2}, {0, 1}} is a triangle -> true.

class Solution {        // GFG's required wrapper; the methods below are its members
    public:             // public: the judge's code, outside the class, may call them
      // DFS from src. parent = the node we arrived from (-1 for a start node).
      // Returns true as soon as a cycle is found anywhere below src.
      // vis and adj are passed by reference (&): the function works on the
      // caller's own vectors instead of making a copy on every call, so marks
      // made here are seen everywhere and no time is wasted copying.
      // Here parent is a plain parameter, not an array: each call carries its
      // own value on the call stack, which is all the DFS needs.
      bool dfs(int src, int parent, vector<bool>& vis, vector<vector<int>>& adj){
          vis[src] = true;   // entered src

          for(int child : adj[src]){   // each neighbour of src
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
                      return true;   // stop early; every caller returns true in turn
                  }
              }
          }

          return false;   // explored everything below src, no cycle
      }

      // Entry point called by the judge. Returns true if the graph has a cycle.
      bool isCycle(vector<vector<int>>& adj) {
          // Code here
          int n = adj.size();          // number of vertices
          vector<bool> vis(n, false);  // local, so every call starts clean

          // The graph may be in several pieces, and the cycle may live in any
          // of them: start a DFS from every node not yet visited.
          for(int i=0; i<n; i++){
              if(!vis[i]){
                  if(dfs(i, -1, vis, adj)){   // -1 = "no parent", never a real vertex
                      return true;
                  }
              }
          }
          return false;   // O(V + E)
      }
  };                     // a class definition must end with a semicolon