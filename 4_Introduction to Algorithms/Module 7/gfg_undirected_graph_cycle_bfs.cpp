/*

Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether 
the graph contains any cycle or not. The Graph is represented as an adjacency list, where 
adj[i] contains all the vertices that are directly connected to vertex i.

NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between 
vertex i and vertex j, both j will be adj[i] and i will be in adj[j].

Examples:

*/

class Solution {
    public:
      // Function to detect cycle in an undirected graph.
      bool bfs(int src, int parent, vector<bool>& vis, vector<vector<int>>& adj){
          queue<pair<int, int>> q;
          q.push({src, -1});
          vis[src] = true;

          while(!q.empty()){
            int curr = q.front().first;
            int par = q.front().second;
            q.pop();

            for(int child : adj[curr]){
                if(vis[child] && parent != child){
                    return true;
                }
                if(!vis[child]){
                    q.push({child, curr});
                    vis[child] = true;
                }
            }
          }

          return false;
      }
      
      bool isCycle(vector<vector<int>>& adj) {
          // Code here
          int n = adj.size();
          vector<bool> vis(V, false);
          
          for(int i=0; i<n; i++){
              if(!vis[i]){
                  if(bfs(i, -1, vis, adj)){
                      return true;
                  }
              }
          }
          return false;
      }
  };