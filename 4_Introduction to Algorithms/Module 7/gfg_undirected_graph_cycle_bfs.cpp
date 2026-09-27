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
//
// Tiny example. Triangle 0-1, 1-2, 2-0: adj = {{1,2},{0,2},{0,1}}.
//   pop {0,-1}: 1 unvisited -> push {1,0}; 2 unvisited -> push {2,0}
//   pop {1,0}:  child 0 is visited but 0 is 1's parent -> fine;
//               child 2 is visited and 2 != 0 -> CYCLE, return true.
// A plain path 0-1-2 never hits that case, because the only visited
// neighbour each node sees is its own parent.
//
// There is no main and no #include here: GFG's hidden driver code includes
// the libraries (vector, queue, ...), reads the graph, and calls isCycle.

class Solution {        // GFG wants the answer inside a class named Solution
    public:             // public: the driver code outside the class may call these
      // Function to detect cycle in an undirected graph.
      // BFS over the piece of the graph that contains src. (The parent
      // argument is unused: the parents come out of the queue instead.)
      // vis and adj are passed by reference (&): the function works on the
      // caller's vectors, so marks made here stay visible to isCycle, and the
      // big adjacency list is not copied.
      // Returns true as soon as a cycle is seen, false if this piece has none.
      bool bfs(int src, int parent, vector<bool>& vis, vector<vector<int>>& adj){
          queue<pair<int, int>> q;   // FIFO queue of {node, parent-of-node}
          q.push({src, -1});   // the start node has no parent: -1
          vis[src] = true;     // mark when pushed, so no node enters the queue twice

          // One pass = take the oldest node and look at all its neighbours.
          // Ends when the whole piece containing src has been explored.
          while(!q.empty()){
            int curr = q.front().first;    // the node explored now
            int par = q.front().second;    // the node that discovered curr
            q.pop();                       // remove it from the queue

            // Range-for: child takes each neighbour of curr in turn.
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

      // isCycle: the function GFG calls. adj[i] = list of neighbours of i.
      // Returns true if any piece of the graph has a cycle.
      bool isCycle(vector<vector<int>>& adj) {
          // Code here
          int n = adj.size();          // number of vertices
          vector<bool> vis(n, false);  // n slots, all "not visited yet"

          // The graph may be split into pieces: try every unvisited node.
          // Each BFS marks its whole piece, so every piece is searched once.
          for(int i=0; i<n; i++){
              if(!vis[i]){
                  if(bfs(i, -1, vis, adj)){
                      return true;     // one cycle anywhere is enough
                  }
              }
          }
          return false;   // O(V + E): every node and edge is looked at a constant number of times
      }
  };
