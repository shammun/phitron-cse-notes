// Does an undirected graph contain a cycle? DFS version.
//
// The rule is exactly the one from detect_cycle_in_undirected_graph_bfs.cpp: a
// neighbour that is already visited and is not the node we came from means there
// is a second way into it, which closes a cycle. The edge back to our own
// discoverer has to be excused, because an undirected edge is stored in both
// lists and would otherwise be reported on every single step.
//
// Only the walk changes, from a queue to recursion. Here parent[src] is the node
// whose loop called us, so it is precisely the one to skip.
//
// Sample input: the path 0-1-2-3-4
//   5 4
//   0 1
//   1 2
//   2 3
//   3 4
// Output: No Cycle   (add the edge 4 0 and it becomes Cycle Detected)

#include <iostream>     // cin, cout
#include <vector>       // vector, for the adjacency lists
#include <algorithm>    // not used here (class template)
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // not used here
// BUG: memset (used in main) is declared in <cstring>, which is not included.
// Some compilers pull it in through <iostream> by accident, but many (including
// the g++ this repo is checked with) stop with "'memset' was not declared in this
// scope". Fix: add #include <cstring> here.

using namespace std;    // write cin/cout/vector without std::

bool vis[105];              // vis[x] = has DFS already entered x?
vector<int> adj_list[105];  // adj_list[x] = all neighbours of x
int parent[105];            // parent[x] = node whose dfs call discovered x; -1 = start node
bool cycle;                 // becomes true as soon as a cycle is seen

// Depth-first search from src. Recursion: each call marks src, then dives into
// every unvisited neighbour; the call stack itself remembers the path back.
// It stops (returns) when every neighbour of src has been checked.
void dfs(int src){
    vis[src] = true;                      // entered src
    for(int child : adj_list[src]){       // each neighbour of src
        // Visited already, and not the node we arrived from: a cycle.
        if(vis[child] && parent[src] != child){
            cycle = true;
        }
        if(!vis[child]){
            // Set the parent BEFORE the call, because the call will immediately
            // start looking at child's own neighbours and will ask parent[child]
            // the moment it sees src again in child's list.
            parent[child] = src;
            dfs(child);                   // explore everything reachable from child, then come back
        }
    }
}

int main(){
    int n, e;                       // n nodes (0..n-1), e edges
    cin >> n >> e;
    while(e--){                     // runs e times
        int a, b;
        cin >> a >> b;              // edge between a and b
        adj_list[a].push_back(b);   // a knows b
        adj_list[b].push_back(a);   // b knows a (undirected)
    }
    // memset fills every byte: false -> all 0; -1 -> all bytes 0xFF, which reads
    // back as the int -1 (this trick only works for 0 and -1).
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));   // a start node has no parent

    cycle = false;
    // Every unvisited node starts a new search, so no separate piece is missed.
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(cycle){
        cout << "Cycle Detected" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }

    // A useful fact to check the answer against: an undirected graph with no
    // cycle is a forest, and a forest on n nodes has fewer than n edges. So the
    // path 0-1-2-3-4 here, 5 nodes and 4 edges, cannot possibly hold a cycle.

    return 0;   // normal exit
}