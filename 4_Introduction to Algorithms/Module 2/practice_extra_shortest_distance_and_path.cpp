// Extra practice (Module 2 sheet): on the 7-node graph below, use BFS to find
//   1. the shortest distance from 0 to 3, and
//   2. the shortest path from 0 to 2.
//
// The graph (undirected, nodes 0..6):
//   edges: 0-5  5-1  1-4  1-6  4-6  4-2  2-3  3-6
//
// Input: n e, the e edges, then q and q lines "src dest". For each query the
// program prints the distance (in edges) and one shortest path, or -1 when
// dest cannot be reached.
//
// Example: for "0 3" the answer is 4 along 0 5 1 6 3, and for "0 2" it is 4
// along 0 5 1 4 2. (0 -> 3 through 4 and 2 would also work but takes 5 edges.)
//
// Nothing new is needed: this is single_source_shortest_distance.cpp (level[])
// and path_printing.cpp (parent[]) in one BFS.

#include <iostream>
#include <vector>
#include <algorithm>    // reverse
#include <queue>
#include <cstring>      // memset

using namespace std;

vector<int> adj_list[1005];
bool visited[1005];
int level[1005];     // level[x]  = fewest edges from the source to x, -1 = unreached
int parent[1005];    // parent[x] = the node that discovered x, -1 = none

void bfs(int src){
    // Fresh marks for every query: each query may start somewhere else.
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;   // one ring further out
                parent[child] = par;             // remember who found it
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
        adj_list[b].push_back(a);   // undirected
    }

    int q;
    cin >> q;
    while(q--){
        int src, dest;
        cin >> src >> dest;

        bfs(src);

        // Question 1: the distance is simply dest's level.
        cout << "distance " << src << " -> " << dest << " = " << level[dest] << endl;

        // Question 2: the path. Only walk the parents if dest was reached;
        // otherwise parent[dest] is -1 and the "path" would be dest alone.
        if(!visited[dest]){
            cout << "no path" << endl;
            continue;
        }

        // Walk back dest -> parent -> ... -> src (whose parent is -1), which
        // collects the path backwards, then turn it round.
        vector<int> path;
        int node = dest;
        while(node != -1){
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());

        cout << "path: ";
        for(int x : path){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
