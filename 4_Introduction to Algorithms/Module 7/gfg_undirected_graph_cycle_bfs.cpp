/*

Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether 
the graph contains any cycle or not. The Graph is represented as an adjacency list, where 
adj[i] contains all the vertices that are directly connected to vertex i.

NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between 
vertex i and vertex j, both j will be adj[i] and i will be in adj[j].

Examples:

*/

// This is Module 6's Practice Day problem 1: the same GFG cycle question as
// Module 6's extra_problem_undirected_graph_cycle_dfs.cpp, but solved with BFS
// as that practice day asked. The rule does not change: reaching a node that
// is already visited, and that is not the node we came from, means there are
// two different ways to reach it, so the graph has a cycle.
//
// What BFS needs extra: DFS gets the parent for free as a function argument,
// but BFS takes nodes out of a queue much later than it discovers them. So
// each node travels through the queue together with its parent: {node, parent}.

class Solution {
    public:
      // Function to detect cycle in an undirected graph.
      // BFS over the piece of the graph that contains src. (The parent
      // argument is unused: the parents come out of the queue instead.)
      bool bfs(int src, int parent, vector<bool>& vis, vector<vector<int>>& adj){
          queue<pair<int, int>> q;
          q.push({src, -1});   // the start node has no parent: -1
          vis[src] = true;

          while(!q.empty()){
            int curr = q.front().first;    // the node explored now
            int par = q.front().second;    // the node that discovered curr
            q.pop();

            for(int child : adj[curr]){
                // Visited, and not simply the edge back to curr's own parent:
                // someone else reached child first, so there is a cycle.
                // It must be par, the parent of THIS node. Comparing with the
                // function argument, which is always -1, would call every
                // undirected edge a cycle.
                if(vis[child] && par != child){
                    return true;
                }
                if(!vis[child]){
                    q.push({child, curr});   // curr becomes child's parent
                    vis[child] = true;       // mark on push, as in Module 2
                }
            }
          }

          return false;   // this piece has no cycle
      }

      bool isCycle(vector<vector<int>>& adj) {
          // Code here
          int n = adj.size();          // number of vertices
          vector<bool> vis(n, false);

          // The graph may be split into pieces: try every unvisited node.
          for(int i=0; i<n; i++){
              if(!vis[i]){
                  if(bfs(i, -1, vis, adj)){
                      return true;
                  }
              }
          }
          return false;   // O(V + E)
      }
  };
