/*

You will be given an undirected graph as input. Then you will be given a query Q. For 
each query, you will be given source S and destination D. You need to print the shortest 
distance between S and D. If there is no path from S to D, print -1.

Sample Input
6 7
0 1
0 2
1 2
0 3
4 2
3 5
4 3
6
0 5
1 5
2 5
2 3
1 4
0 0

Sample Output
2
3
3
2
2
0

Sample Input
7 5
0 1
0 2
4 5
4 6
5 7
3
0 4
5 1
1 3

Sample Output
-1
-1
-1

*/

/// Idea: every edge costs one step, so "shortest distance" is exactly the BFS
// level from single_source_shortest_distance.cpp. The only new part is that
// there are many queries, each with its own source, so each query runs a fresh
// BFS from its S and then reads level[D].
//
// Trace, sample 1, query "1 5": BFS from 1 -> level 1 = {0, 2}; level 2 = {3, 4};
// level 3 = {5}. So level[5] = 3 (path 1 0 3 5).
// Sample 2 note: it says n = 7 but uses node 7 (edge 5-7). That is harmless here
// because the arrays have room for 1005 nodes.

#include <iostream>     // cin, cout
#include <vector>       // vector for the adjacency list
#include <algorithm>    // not used here
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // queue for BFS (first in, first out)
#include <cstring>      // memset

using namespace std;    // drop the std:: prefix

vector<int> adj_list[1005];   // the graph, built once and shared by every query
bool visited[1005];           // visited[x] = x already queued in the current BFS
int level[1005];              // level[x] = edges from the current source; -1 = unreached

// BFS from src that fills level[] with shortest distances (in edges) from src.
void bfs(int src){
    // A new source means a new search: wipe the marks the previous query left
    // behind. Without this, nodes visited last time would be skipped now and
    // their level would be the OLD distance, from the OLD source.
    // memset(array, value, bytes): false -> all 0; -1 -> every byte 0xFF = int -1.
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));

    queue<int> q;             // waiting line of found-but-unexplored nodes
    q.push(src);              // start from the source
    visited[src] = true;      // mark on push
    level[src] = 0;           // the source is 0 edges from itself

    // One pass = explore one node; ends when the queue is empty.
    while(!q.empty()){
        int par = q.front();  // the node at the front
        q.pop();              // remove it

        for(int child : adj_list[par]){              // every neighbour of par
            if(!visited[child]){                     // first time seen
                q.push(child);                       // explore later
                visited[child] = true;               // mark when pushed
                level[child] = level[par] + 1;       // one ring further out
            }
        }
    }
}


int main(){
    int n, e;          // number of nodes, number of edges
    cin >> n >> e;

    // Undirected graph: store each edge in both lists.
    while(e--){                     // runs e times
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);   // b is a neighbour of a
        adj_list[b].push_back(a);   // a is a neighbour of b
    }

    int q;
    cin >> q;          // number of (S, D) questions

    while(q--){                          // handle each question
        int src, dest;
        cin >> src >> dest;
        bfs(src);                        // distances from THIS query's source
        // level[dest] is the answer as it stands: the fewest edges from src,
        // or the -1 it was reset to when dest lies in another piece of the
        // graph. S == D gives 0, because level[src] was set to 0.
        cout << level[dest] << endl;     // endl = newline + flush
    }

    // Cost: one BFS per query, so O(Q * (V + E)) in total.

    return 0;   // normal end
}
