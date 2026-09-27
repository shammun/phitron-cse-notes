// Extra practice (Module 2 sheet): on the 7-node graph below, use BFS to find
//   1. the shortest distance from 0 to 3, and
//   2. the shortest path from 0 to 2.
//
// The graph (undirected, nodes 0..6):
//   edges: 0-5  5-1  1-4  1-6  4-6  4-2  2-3  3-6
//
// Input: n e, the e edges, then q and q lines "src dest". For each query the
// program prints the distance (in edges) and one shortest path, or -1 when
// dest cannot be reached (followed by the line "no path").
//
// Example: for "0 3" the answer is 4 along 0 5 1 6 3, and for "0 2" it is 4
// along 0 5 1 4 2. (0 -> 3 through 4 and 2 would also work but takes 5 edges.)
//
// Nothing new is needed: this is single_source_shortest_distance.cpp (level[])
// and path_printing.cpp (parent[]) in one BFS.
//
// Level trace from 0: level 0 = {0}; 1 = {5}; 2 = {1}; 3 = {4, 6}; 4 = {2, 3}.
// With the edges typed in the order listed above, exploring 1 queues 4 then 6
// (edge 1-4 comes before 1-6). 4 is explored first and discovers 2; then 6
// discovers 3. Hence parent[2] = 4 and parent[3] = 6, giving the paths above.

#include <iostream>     // cin, cout
#include <vector>       // vector (adjacency list, path)
#include <algorithm>    // reverse
#include <queue>        // queue for BFS
#include <cstring>      // memset

using namespace std;    // skip the std:: prefix

vector<int> adj_list[1005];   // adj_list[x] = neighbours of x
bool visited[1005];           // visited[x] = already queued in the current BFS
int level[1005];     // level[x]  = fewest edges from the source to x, -1 = unreached
int parent[1005];    // parent[x] = the node that discovered x, -1 = none

// BFS from src; afterwards level[] and parent[] describe shortest routes from src.
void bfs(int src){
    // Fresh marks for every query: each query may start somewhere else.
    // memset(array, value, bytes) sets every byte; -1 as bytes 0xFF = int -1.
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    queue<int> q;          // FIFO line of nodes waiting to be explored
    q.push(src);           // start at the source
    visited[src] = true;   // mark on push
    level[src] = 0;        // distance 0 to itself

    // One pass = explore one node; stops when the queue is empty.
    while(!q.empty()){
        int par = q.front();   // node to explore
        q.pop();               // remove it from the queue

        for(int child : adj_list[par]){   // each neighbour of par
            if(!visited[child]){          // not seen yet
                q.push(child);            // explore later
                visited[child] = true;    // mark now, never queue twice
                level[child] = level[par] + 1;   // one ring further out
                parent[child] = par;             // remember who found it
            }
        }
    }
}

int main(){
    int n, e;          // number of nodes, number of edges
    cin >> n >> e;

    // Build the graph from e edge lines.
    while(e--){                     // runs e times
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);   // undirected
    }

    int q;             // number of queries (this int q is a count, not the BFS queue)
    cin >> q;
    while(q--){        // answer each query in turn
        int src, dest;
        cin >> src >> dest;

        bfs(src);      // new BFS from this query's source

        // Question 1: the distance is simply dest's level.
        cout << "distance " << src << " -> " << dest << " = " << level[dest] << endl;

        // Question 2: the path. Only walk the parents if dest was reached;
        // otherwise parent[dest] is -1 and the "path" would be dest alone.
        if(!visited[dest]){
            cout << "no path" << endl;
            continue;   // skip the rest of this loop pass, go to the next query
        }

        // Walk back dest -> parent -> ... -> src (whose parent is -1), which
        // collects the path backwards, then turn it round.
        vector<int> path;          // collected backwards
        int node = dest;           // walker starts at the destination
        while(node != -1){         // -1 = past the source, stop
            path.push_back(node);
            node = parent[node];   // one step toward the source
        }
        reverse(path.begin(), path.end());   // now src ... dest

        cout << "path: ";
        for(int x : path){         // print each node of the path in order
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;   // normal end
}
