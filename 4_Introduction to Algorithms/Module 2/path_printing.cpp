// Print the shortest path itself, not just its length.
//
// Same BFS again, now with a parent array as well as level. Every node except the
// source is discovered by exactly one other node: the one that pushed it. Writing
// that discoverer down gives a chain of single steps, and following the chain back
// from the destination walks a shortest path in reverse.
//
// So the search never stores paths. It stores one number per node, and the path is
// rebuilt afterwards from those numbers.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

vector<int> adj_list[1005];
bool visited[1005];
int level[1005];
int parent[1005];   // parent[x] = the node that first reached x; -1 for the source

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    // parent[src] = -1;
    // The line above is commented out because main already set the whole parent
    // array to -1. The source keeps that -1, and that is what stops the walk back.

    while(!q.empty()){
        int par = q.front();
        q.pop();

        cout << par << " ";

        for(int child : adj_list[par]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;
                // Recorded at the same moment as the mark, so it records the
                // first discovery. Any later edge into child is ignored, which
                // is right: the first one came along a shortest route.
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
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));   // -1 means "nobody discovered this node"

    int src, dest;
    cin >> src >> dest;

    bfs(src);

    // Useful while learning: see who discovered each node.
    /*
    for(int i=0; i<n; i++){
        cout << i << " parent -> " << parent[i] << endl;
    }
    */

    // First way to print path -- prints in reverse order
    // Start at the destination and keep stepping to the parent. The source has
    // parent -1, so that value is the signal to stop. What comes out is the path
    // read backwards, from dest to src.
    int node = dest;

    while(node != -1){
        cout << node << " ";
        node = parent[node];
    }

    // Second way to print path -- prints in correct order
    // Same walk, but collect the nodes into a vector instead of printing them,
    // then turn the vector round. reverse() comes from <algorithm>.
    vector<int> path;
    int node2 = dest;
    while(node2 != -1){
        path.push_back(node2);
        node2 = parent[node2];
    }
    reverse(path.begin(), path.end());
    for(int x : path){
        cout << x << " ";
    }

    // Both walks are printed one after the other, so the output shows the path
    // backwards and then forwards. In a real solution you would keep only one.
    //
    // A trap worth knowing: if dest was never reached, parent[dest] is still -1
    // and this prints just dest, which looks like a path but is not one. Check
    // visited[dest] first before trusting the walk.

    return 0;
}