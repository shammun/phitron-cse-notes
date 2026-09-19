// Does an undirected graph contain a cycle? BFS version.
//
// A cycle means there are two different ways to reach the same node. So while
// exploring node par, meeting a neighbour that is ALREADY visited looks like the
// answer: somebody else got there first, by another route.
//
// Except for one case, and it is the case that happens on every single edge. The
// graph is undirected, so the edge that brought us to par is stored in par's list
// too. Standing on par we will always see our own discoverer sitting there,
// already visited, and that is not a second route, it is the same road looked at
// backwards. So the node that discovered par, parent[par], must be excused.
//
// That gives the rule: a visited neighbour that is NOT par's parent means a cycle.
//
// Note this is why a parent array is needed here at all, and why the same rule
// cannot be used on a directed graph (see detect_cycle_in_directed_graph_dfs.cpp):
// there, arrows 0->2 and 1->2 make 2 visited twice with no cycle anywhere.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

bool vis[105];
vector<int> adj_list[105];
int parent[105];   // parent[x] = the node that discovered x; -1 for a start node
bool cycle;        // global so bfs() can raise the flag from anywhere

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]){
            // Already seen, and not the node we came from: a second way in.
            if(vis[child] && parent[par] != child){
                cycle = true;
                // No break: the search is allowed to finish. The flag is enough,
                // and the rest of the graph still has to be marked for the loop
                // in main to work out which components are left.
            }
            // The ordinary BFS step, unchanged from Module 2 except for the one
            // extra line that remembers who did the discovering.
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
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
        adj_list[b].push_back(a);   // undirected, so both lists hold the edge
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    cycle = false;
    // Start a search from every node that is still unvisited, because the cycle
    // may sit in a piece of the graph that node 0 cannot reach at all.
    for(int i=0; i<n; i++){
        if(!vis[i]){
            bfs(i);
        }
    }
    if(cycle){
        cout << "Cycle Detected" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }

    // Cost: one BFS over the whole graph, O(V + E).

    return 0;
}