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

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

vector<int> adj_list[1005];
bool vis[1005];

// The DFS of dfs.cpp with the printing switched off: here we only care about the
// marks it leaves behind in vis, not about the order it walked in.
void dfs(int src){
    // cout << src << " ";
    vis[src] = true;

    for(int child : adj_list[src]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;

    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    
    // This loop over every node is the point of the file. bfs(0) or dfs(0) alone
    // would only ever see the piece that holds node 0 and would miss the rest.
    int count = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);      // paints the whole island that i belongs to
            count++;     // one more island found
        }
    }

    cout << count << endl;

    // Two small things to carry away.
    // First, naming a variable count while using namespace std is asking for
    // trouble, because std::count is a real function from <algorithm>; here the
    // local name wins, but in other code the clash bites. num_components reads
    // better and is safe.
    // Second, to get the SIZE of each island as well, set a counter to zero just
    // before each dfs(i) and increase it inside dfs; after the call it holds how
    // many nodes that island has.
    
    return 0;
}