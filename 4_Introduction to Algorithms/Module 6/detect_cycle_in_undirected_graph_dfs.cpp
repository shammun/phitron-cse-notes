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

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

bool vis[105];
vector<int> adj_list[105];
int parent[105];
bool cycle;

void dfs(int src){
    vis[src] = true;
    for(int child : adj_list[src]){
        // Visited already, and not the node we arrived from: a cycle.
        if(vis[child] && parent[src] != child){
            cycle = true;
        }
        if(!vis[child]){
            // Set the parent BEFORE the call, because the call will immediately
            // start looking at child's own neighbours and will ask parent[child]
            // the moment it sees src again in child's list.
            parent[child] = src;
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

    return 0;
}