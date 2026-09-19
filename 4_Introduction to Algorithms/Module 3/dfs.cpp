// Depth-first search (DFS): the other way to walk a graph.
//
// BFS spread out in rings, held back by a queue. DFS does the opposite: from the
// node you are standing on, step into the first unvisited neighbour immediately,
// and from there into its first unvisited neighbour, and so on until there is
// nowhere new to go. Only then do you back up one step and try the next branch.
//
// There is no queue here, and no stack written by hand either. The recursion does
// the remembering: each call to dfs() is paused while its child call runs, and the
// call stack holds the list of nodes we still have to come back to. "Back up one
// step" is simply a function returning to its caller.
//
// visited[] has the same job as in BFS: without it, two nodes joined in a cycle
// would call each other for ever until the program runs out of stack.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

vector<int> adj_list[1005];
bool vis[1005];

void dfs(int src){
    cout << src << " ";   // printed on the way IN, so this is the entry order
    vis[src] = true;      // mark before recursing, or a cycle sends us round again

    for(int child : adj_list[src]){
        if(!vis[child]){
            // Go deep straight away. This call will finish the whole branch under
            // child before control ever comes back here and tries the next one.
            dfs(child);
        }
    }
    // Falling off the end of the loop is the backtrack: nothing new under src, so
    // return to whoever called us and let them carry on with their own list.
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
    dfs(0);

    // Cost is the same as BFS, O(V + E), because each node is entered once and
    // each edge is looked at once from each end. The difference is only the order
    // and where the memory goes: a queue for BFS, the recursion stack for DFS.
    // That stack is worth watching, since a path of 100000 nodes means 100000
    // nested calls.

    return 0;
}