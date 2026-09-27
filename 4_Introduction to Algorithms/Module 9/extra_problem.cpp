// GeeksforGeeks: "Distance from the Source (Bellman-Ford Algorithm)".
//
// Given V nodes, a list of directed weighted edges and a source, return the
// shortest distance to every node, or {-1} if a negative cycle is reachable.
//
// It is bellman_ford_cycle.cpp wearing the shape the judge asks for: the answer
// is returned as a vector instead of printed, and the whole thing sits inside a
// class Solution, which is how GFG and LeetCode hand you a problem. Two small
// differences are worth noticing as you read.
//
// Example input (1 test case; 3 nodes, 3 edges "u v w"; then the source):
//   1
//   3 3
//   0 1 5
//   1 2 -2
//   0 2 6
//   0
// Output: 0 5 3      (node 2: 0 -> 1 -> 2 costs 5 - 2 = 3, cheaper than 6)

#include <iostream>   // cin / cout
#include <queue>      // not used here; course template line
#include <cstring>    // not used here; course template line
#include <vector>     // vector, used for the edges and for the answer

using namespace std;  // lets us write vector / cout without std::

// The judge's wrapper class. We only fill in the one member function.
class Solution {
    public:           // public: main (outside the class) is allowed to call it
      /*  Function to implement Bellman Ford
       *   edges: vector of vectors which represents the graph
       *   src: source vertex
       *   V: number of vertices
       *   returns: dist, where dist[i] is the cheapest cost src -> i
       *            (10^8 if i cannot be reached), or {-1} for a negative cycle
       */
      // vector<vector<int>>& edges: the & means "by reference": the function
      // works on the caller's vector directly instead of copying all of it.
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
          // Code here
          // Difference one: infinity is 10^8, not INT_MAX. The problem promises
          // that no real distance comes anywhere near it, and a number this far
          // from the top of int leaves room to add a weight without overflowing.
          // The guard below is still written, and still worth writing.
          //
          // Difference two: dist is a local vector sized V, not a global array.
          // A fresh one per call means no leftovers between test cases. With a
          // global array (as in the earlier files) you would have to reset it
          // yourself, with a loop or memset, before every new test case.
          // vector<int> dist(V, 100000000): V cells, each set to 100000000.
          vector<int> dist(V, 100000000);
          dist[src] = 0;   // the source costs nothing to reach
          
          // The n-1 settling rounds. A shortest path never repeats a node, so it
          // uses at most V-1 edges, and each round pushes every path one edge
          // further towards being correct. V-1 rounds therefore settle them all.
          for(int i=0; i< V-1; i++){
              // edge is a copy of one inner vector {u, v, w}.
              for(auto edge : edges){
                  int u = edge[0];   // from
                  int v = edge[1];   // to
                  int w = edge[2];   // weight
                  // Relax: if reaching u and taking this edge beats the best
                  // route to v so far, keep the cheaper number.
                  // (First part: skip u if it is still "infinity", unreached.)
                  if(dist[u] != 100000000 && dist[u] + w < dist[v]){
                      dist[v] = dist[u] + w;
                  }
              }
          }
          // Trace with the example: round 1 sets dist[1]=5, dist[2]=5-2=3
          // (then 0->2 offers 6, not better). Round 2 changes nothing.
          
          // The extra round. After V-1 rounds nothing honest can improve, so an
          // improvement here proves a reachable negative cycle: a loop you can
          // walk round to lower the total again and again, with no cheapest
          // route to settle on. The problem wants {-1} in that case.
          for(auto edge : edges){
              int u = edge[0];
              int v = edge[1];
              int w = edge[2];
              if(dist[u] != 100000000 && dist[u] + w < dist[v]){
                  // {-1} builds a vector holding the single value -1 and
                  // returns it straight away, ending the function.
                  return {-1};
              }
          }
          return dist;   // nodes never reached keep the 10^8, as the judge expects
      }
  };

  // Driver Code Starts.

// Below this line is the judge's own test harness, not part of the solution.
int main() {
    // How many test cases follow. (The copy first pasted here had
    // cin.ignore() in place of cin >> t, which left t holding garbage and
    // printed nothing; reading t is all the driver needs.)
    int t;
    cin >> t;
    while (t--) {        // runs once per test case, t times in total
        int N, m;
        cin >> N >> m;   // nodes and edges for this test case
        
        // The edge list the judge uses is a vector<vector<int>>: each inner
        // vector is {u, v, w}. Same idea as the Edge class, spelled differently.
        vector<vector<int>> edges;
        
        for (int i = 0; i < m; i++) {    // read the m edges one by one
            int u, v, w;
            cin >> u >> v >> w;
            
            vector<int> edge(3);         // a vector of 3 ints, all 0 for now
            edge[0] = u;                 // from
            edge[1] = v;                 // to
            edge[2] = w;                 // weight
            edges.push_back(edge);       // append this edge to the list
        }
        
        int src;
        cin >> src;      // the source node
        // cin.ignore() throws away the next character (the newline after src).
        // It only matters if getline were used next; here it is harmless.
        cin.ignore();
        
        Solution obj;    // make a Solution object so we can call its method
        vector<int> res = obj.bellmanFord(N, edges, src);   // the answer
        
        // Print the answers separated by single spaces, with no trailing space:
        // that is what the i != res.size() - 1 test is for.
        // size_t is an unsigned type, the same type size() returns, so the
        // comparison i < res.size() does not mix signed and unsigned.
        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i];
            if (i != res.size() - 1) cout << " ";
        }
        cout << "\n";    // "\n" = newline (no flush, faster than endl)
    }
    return 0;            // program ended normally
}

// Driver Code Ends