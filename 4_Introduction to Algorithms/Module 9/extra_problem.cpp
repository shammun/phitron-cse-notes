// GeeksforGeeks: "Distance from the Source (Bellman-Ford Algorithm)".
//
// Given V nodes, a list of directed weighted edges and a source, return the
// shortest distance to every node, or {-1} if a negative cycle is reachable.
//
// It is bellman_ford_cycle.cpp wearing the shape the judge asks for: the answer
// is returned as a vector instead of printed, and the whole thing sits inside a
// class Solution, which is how GFG and LeetCode hand you a problem. Two small
// differences are worth noticing as you read.

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

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
          // Difference one: infinity is 10^8, not INT_MAX. The problem promises
          // that no real distance comes anywhere near it, and a number this far
          // from the top of int leaves room to add a weight without overflowing.
          // The guard below is still written, and still worth writing.
          //
          // Difference two: dist is a local vector sized V, not a global array.
          // A fresh one per call means no leftovers between test cases, which is
          // what the memset calls were doing in the earlier files.
          vector<int> dist(V, 100000000);
          dist[src] = 0;
          
          // The n-1 settling rounds. A shortest path never repeats a node, so it
          // uses at most V-1 edges, and each round pushes every path one edge
          // further towards being correct. V-1 rounds therefore settle them all.
          for(int i=0; i< V-1; i++){
              for(auto edge : edges){
                  int u = edge[0];   // from
                  int v = edge[1];   // to
                  int w = edge[2];   // weight
                  // Relax: if reaching u and taking this edge beats the best
                  // route to v so far, keep the cheaper number.
                  if(dist[u] != 100000000 && dist[u] + w < dist[v]){
                      dist[v] = dist[u] + w;
                  }
              }
          }
          
          // The extra round. After V-1 rounds nothing honest can improve, so an
          // improvement here proves a reachable negative cycle: a loop you can
          // walk round to lower the total again and again, with no cheapest
          // route to settle on. The problem wants {-1} in that case.
          for(auto edge : edges){
              int u = edge[0];
              int v = edge[1];
              int w = edge[2];
              if(dist[u] != 100000000 && dist[u] + w < dist[v]){
                  return {-1};
              }
          }
          return dist;   // nodes never reached keep the 10^8, as the judge expects
      }
  };

  // Driver Code Starts.

// Below this line is the judge's own test harness, not part of the solution.
int main() {
    // BUG: t is declared and never given a value, so it holds whatever was in
    // that memory. The line should be cin >> t; instead, cin.ignore() throws
    // away a single character. On this run t happened to be 0 or negative, the
    // while loop did not run once, and the program printed nothing at all.
    // The Solution class above is fine; only the driver is broken.
    int t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;   // nodes and edges for this test case
        
        // The edge list the judge uses is a vector<vector<int>>: each inner
        // vector is {u, v, w}. Same idea as the Edge class, spelled differently.
        vector<vector<int>> edges;
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            
            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }
        
        int src;
        cin >> src;
        cin.ignore();
        
        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);
        
        // Print the answers separated by single spaces, with no trailing space:
        // that is what the i != res.size() - 1 test is for.
        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i];
            if (i != res.size() - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}

// Driver Code Ends