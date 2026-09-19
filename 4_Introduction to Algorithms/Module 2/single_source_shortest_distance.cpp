// Shortest distance from one source, using BFS levels.
//
// Same BFS as bfs.cpp, with one array added: level[]. BFS leaves the queue in
// rings, so the ring a node belongs to IS its distance from the source, counted
// in edges. Writing that ring number down as each node is discovered turns the
// traversal into a shortest-distance machine, for free.
//
// This only works because every edge costs the same (one step). Once edges carry
// different weights the ring order breaks down, and Dijkstra takes over (Module 7).

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

vector<int> adj_list[1005];
bool visited[1005];
int level[1005];     // level[x] = fewest edges from the source to x; -1 = not reached

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;    // the source is zero edges away from itself

    while(!q.empty()){
        int par = q.front();
        q.pop();

        cout << par << " ";

        for(int child : adj_list[par]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
                // par came out of the queue with its final, smallest level, and
                // child sits one edge beyond it. Because of the ring order, the
                // first time we ever reach child is along a shortest route, so
                // this value is never improved later and never needs correcting.
                level[child] = level[par] + 1;
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
    // Fill level with -1, the "never reached" marker. -1 is chosen because a real
    // distance is always 0 or more, so it can never be mistaken for an answer.
    // (memset writes bytes; -1 works because all four bytes of -1 are 0xFF.)
    memset(level, -1, sizeof(level));

    int src, dest;
    cin >> src >> dest;

    bfs(src);

    // Handy while learning: print the distance to every node, not just dest.
    /*
    for(int i=0; i<n; i++){
        cout << "level of " << i << " = " << level[i] << endl;
    }
    */
    
    // If dest sits in another piece of the graph it was never reached, and this
    // prints -1, which is exactly the answer such problems usually want.
    cout << "level of " << dest << " = " << level[dest] << endl;


    return 0;
}