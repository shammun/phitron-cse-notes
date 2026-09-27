// How many separate pieces does the graph fall into?
//
// A graph need not be one connected whole. It can be several islands with no edge
// between them, and each island is called a connected component.
//
// One DFS paints exactly one island: it reaches everything joined to its starting
// node, and nothing else. So the counting is almost free. Walk through the nodes
// 0, 1, 2, ... n-1; every time you meet a node that is still unvisited, you have
// found an island nobody has painted yet, so start a DFS there and add one to the
// count. Nodes of that island are then all marked, so the loop walks past them
// without starting anything, and the next count only happens on a genuinely new
// island. The number of times a search had to be started IS the number of pieces.
//
// The same trick works with BFS; nothing here depends on going deep.
//
// Tiny trace. Input "6 3 / 0 1 / 1 2 / 4 5":
//   i=0 unvisited -> dfs paints 0,1,2, count=1
//   i=1, i=2 already painted -> skipped
//   i=3 unvisited (no edges) -> dfs paints 3, count=2
//   i=4 unvisited -> dfs paints 4,5, count=3
// Output: 3

#include <iostream>     // cin and cout
#include <vector>       // vector, for the adjacency lists
#include <algorithm>    // not used here (but see the note on std::count below)
#include <string>       // not used here; part of the usual template
#include <stack>        // not used: recursion is the stack
#include <queue>        // not used: no BFS here
// NOTE: memset (used in main) lives in <cstring>, which is not included here.
// Some compilers reach it through <iostream>; GCC 8 (MinGW) reports "'memset'
// was not declared". Fix: add #include <cstring>.

using namespace std;    // use vector, cout... without std::

vector<int> adj_list[1005];   // adj_list[u] = list of u's neighbours (array of vectors)
bool vis[1005];               // vis[u] = u has been painted by some dfs

// The DFS of dfs.cpp with the printing switched off: here we only care about the
// marks it leaves behind in vis, not about the order it walked in.
// After dfs(src) returns, every node in src's component has vis == true.
void dfs(int src){
    // cout << src << " ";   (printing turned off; it would show the visit order)
    vis[src] = true;         // paint this node

    for(int child : adj_list[src]){   // each neighbour of src
        if(!vis[child]){              // not painted yet?
            dfs(child);               // paint it and everything behind it
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;             // n nodes (numbered 0..n-1), e edges

    while(e--){                // repeat e times
        int a, b;
        cin >> a >> b;         // an edge between a and b
        adj_list[a].push_back(b);   // record b as a neighbour of a
        adj_list[b].push_back(a);   // and a as a neighbour of b (undirected)
    }
    memset(vis, false, sizeof(vis));   // nothing painted yet

    // This loop over every node is the point of the file. bfs(0) or dfs(0) alone
    // would only ever see the piece that holds node 0 and would miss the rest.
    int count = 0;             // components found so far
    for(int i=0; i<n; i++){    // look at every node, including ones with no edges
        if(!vis[i]){           // not painted -> belongs to an island not seen yet
            dfs(i);      // paints the whole island that i belongs to
            count++;     // one more island found
        }
    }

    cout << count << endl;     // the number of connected components

    // Two small things to carry away.
    // First, naming a variable count while using namespace std is asking for
    // trouble, because std::count is a real function from <algorithm>; here the
    // local name wins, but in other code the clash bites. num_components reads
    // better and is safe.
    // Second, to get the SIZE of each island as well, set a counter to zero just
    // before each dfs(i) and increase it inside dfs; after the call it holds how
    // many nodes that island has.

    return 0;   // normal end of program
}