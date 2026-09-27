// Shortest distance from one source, using BFS levels.
//
// Same BFS as bfs.cpp, with one array added: level[]. BFS leaves the queue in
// rings, so the ring a node belongs to IS its distance from the source, counted
// in edges. Writing that ring number down as each node is discovered turns the
// traversal into a shortest-distance machine, for free.
//
// This only works because every edge costs the same (one step). Once edges carry
// different weights the ring order breaks down, and Dijkstra takes over (Module 7).
//
// Input: "n e", e undirected edges "a b", then "src dest".
// Output: BFS order, then "level of dest = <distance>" (-1 if unreachable).
//
// Tiny trace: edges 0-1, 0-2, 1-3, 3-4 ; src 0.
//   level[0]=0 ; exploring 0 gives level[1]=1, level[2]=1 ;
//   exploring 1 gives level[3]=2 ; exploring 3 gives level[4]=3.

#include <iostream>     // cin, cout
#include <vector>       // vector for the adjacency list
#include <algorithm>    // not used here
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // queue for BFS (first in, first out)

using namespace std;    // drop the std:: prefix

vector<int> adj_list[1005];   // adj_list[x] = neighbours of x
bool visited[1005];           // visited[x] = x already put in the queue
int level[1005];     // level[x] = fewest edges from the source to x; -1 = not reached

// BFS from src: prints the visit order and fills level[] with distances from src.
void bfs(int src){
    queue<int> q;      // FIFO line of found-but-unexplored nodes
    q.push(src);       // start at the source
    visited[src] = true;   // mark on push
    level[src] = 0;    // the source is zero edges away from itself

    // One pass = explore one node. Stops when the queue is empty.
    while(!q.empty()){
        int par = q.front();   // node at the front
        q.pop();               // remove it

        cout << par << " ";    // print BFS order

        for(int child : adj_list[par]){   // every neighbour of par
            if(!visited[child]){          // first time seen
                q.push(child);            // explore later
                visited[child] = true;    // mark now so it is never pushed twice
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
    int n, e;          // nodes, edges
    cin >> n >> e;

    // Read e undirected edges.
    while(e--){                     // body runs e times
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);   // a -> b
        adj_list[b].push_back(a);   // b -> a
    }

    // memset(array, value, bytes) fills every byte with value.
    // BUG: memset is declared in <cstring>, which this file never includes. Some
    // compilers pull it in through <iostream> or <string>, but others (e.g. MinGW
    // g++ 8.1) stop with "'memset' was not declared". Fix: add #include <cstring>.
    memset(visited, false, sizeof(visited));
    // Fill level with -1, the "never reached" marker. -1 is chosen because a real
    // distance is always 0 or more, so it can never be mistaken for an answer.
    // (memset writes bytes; -1 works because all four bytes of -1 are 0xFF.)
    memset(level, -1, sizeof(level));

    int src, dest;         // distance wanted from src to dest
    cin >> src >> dest;

    bfs(src);              // fill level[] from src

    // Handy while learning: print the distance to every node, not just dest.
    // (Commented out; switched on it prints one "level of i = ..." line per node.)
    /*
    for(int i=0; i<n; i++){
        cout << "level of " << i << " = " << level[i] << endl;
    }
    */

    // If dest sits in another piece of the graph it was never reached, and this
    // prints -1, which is exactly the answer such problems usually want.
    // Note: it is printed right after the BFS order, on the same line.
    cout << "level of " << dest << " = " << level[dest] << endl;


    return 0;   // normal end
}
