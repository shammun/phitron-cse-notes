/*

https://leetcode.com/problems/find-if-path-exists-in-graph/description/

There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1
(inclusive). The edges in the graph are
represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a
bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at
most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex
destination.

Given edges and the integers n, source, and destination, return true if there is a valid path
from source to destination, or false otherwise.

Example 1

Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2

Example 2

Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.


*/

// Idea: a plain graph (not a grid) given as an edge list. Build the adjacency
// list from it (Module 1), run a DFS from source, and report whether the
// destination got visited. The DFS stops going deeper once it has been found.
//
// Example 2: 0-1-2 and 3-5-4 are two separate pieces, so 0 cannot reach 5.
//
// Adjacency list: adj[u] is a vector holding every neighbour of u. For
// example 1 (edges 0-1, 1-2, 2-0) it ends up as
//   adj[0] = {1, 2}   adj[1] = {0, 2}   adj[2] = {1, 0}
//
// Tiny trace of example 1 (source 0, destination 2):
//   dfs(0): vis[0]=true, 0 != 2; child 1 unvisited -> dfs(1)
//   dfs(1): vis[1]=true, 1 != 2; child 0 visited, child 2 unvisited -> dfs(2)
//   dfs(2): vis[2]=true, 2 == 2 -> found = true, return  => answer true.
//
// No #include or "using namespace std;" here: LeetCode's hidden driver code
// already includes the standard library and opens namespace std.

// LeetCode creates an object of this class and calls validPath() on it.
class Solution {
    public:                                   // members below are usable from outside the class
        // n can be 2 * 10^5, so the arrays are large. (Together they are several
        // megabytes, which is why such an object should not be made as a local
        // variable inside a function: the stack is small. As class members they
        // live wherever LeetCode puts the Solution object.)
        // adj is an ARRAY of 200005 vectors: adj[u] = neighbour list of node u.
        vector<int> adj[200005];
        bool vis[200005];                     // vis[u] = true once DFS has entered node u

        // found is passed by reference (&): every recursive call shares the
        // same bool, so a find deep down is seen by everyone above.
        // dfs(node): visit node and everything reachable from it (until found).
        // Base case: node is the destination -> set found and stop.
        // The recursion also ends naturally when all children are visited.
        void dfs(int node, int destination, bool &found){
            vis[node] = true;                 // mark on entry, so a cycle cannot loop forever
            if(node == destination){          // reached the target?
                found = true;                 // tell every caller (shared through &)
                return;           // no need to go any further from here
            }

            // Range-for: child takes each value stored in adj[node], one per pass.
            for(int child : adj[node]){
                if(!vis[child]){              // only step into nodes not seen before
                    dfs(child, destination, found);   // trust it to explore everything reachable from child
                }
            }
        }

        // Called by LeetCode. n = number of nodes, edges = list of {u, v} pairs.
        // Returns true if destination can be reached from source.
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            // Each edge is a 2-element vector {u, v}; the graph is undirected,
            // so it goes into both lists.
            // "auto" lets the compiler work out the type (vector<int> here);
            // each edge is copied into the loop variable, which is fine for 2 ints.
            for(auto edge : edges){
                adj[edge[0]].push_back(edge[1]);   // push_back appends to the end: v is a neighbour of u
                adj[edge[1]].push_back(edge[0]);   // and u is a neighbour of v
            }

            // memset sets every byte of vis to 0 (false); sizeof(vis) = its size in
            // bytes. Class members are not zeroed automatically, so this is needed.
            memset(vis, false, sizeof(vis));
            bool found = false;               // nothing found yet
            dfs(source, destination, found);  // explore from source; may flip found to true
            return found;         // same as asking vis[destination]; Cost O(n + E)
        }
    };                                        // a class definition ends with ;
