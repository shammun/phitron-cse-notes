/*

You will be given an undirected graph which will be connected as input. Then you will be 
given a level L. You need to print the node values at level L in descending order. The 
source will be 0 always.

Sample Input
3 2
0 1
0 2
1

Saample Output
2 1

Sample Input
6 7
0 1
0 2
1 2
0 3
4 2
3 5
4 3
1

Sample Output
3 2 1

Sample Input
6 7
0 1
0 2
1 2
0 3
4 2
3 5
4 3
2

Sample Output
5 4

*/

/// Idea: a BFS from 0 already hands every node its level (its distance from 0).
// So run one BFS, and as each node leaves the queue, keep it if its level is L.
// The problem wants those nodes largest first, so sort the collected nodes in
// descending order at the end.
//
// Trace, sample 2 with L = 1: BFS from 0 -> level 1 = {1, 2, 3}, level 2 = {4, 5}.
// Collected in BFS order: 1 2 3 ; sorted descending: 3 2 1.

#include <iostream>     // cin, cout
#include <vector>       // vector
#include <algorithm>    // sort, greater
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // queue for BFS
#include <cstring>      // memset

using namespace std;    // drop the std:: prefix

vector<int> adj_list[1005];   // adj_list[x] = neighbours of x
bool visited[1005];           // visited[x] = already queued
int level[1005];              // level[x] = edges from node 0 to x (-1 = unreached)
vector<int> nodes;          // the nodes found at level L

// BFS from src; every node whose level equals l is appended to `nodes`.
// Parameters: src = start node (always 0 here), l = the level asked for.
void bfs(int src, int l){
    queue<int> q;          // FIFO line of nodes to explore
    q.push(src);           // start at the source
    visited[src] = true;   // mark on push
    level[src] = 0;        // source is at level 0

    // One pass = explore one node; ends when nothing is waiting.
    while(!q.empty()){
        int par = q.front();   // front node
        q.pop();               // remove it

        // By the time par leaves the queue its level is final (BFS finds each
        // node by the fewest edges first), so it is safe to test it here.
        if(level[par] ==l){
            nodes.push_back(par);   // par is on the requested level: keep it
        }

        for(int child : adj_list[par]){       // every neighbour of par
            if(!visited[child]){              // first time seen
                q.push(child);                // explore later
                visited[child] = true;        // mark now
                level[child] = level[par] + 1;   // one level deeper than par
            }
        }
    }
}

int main(){
    int n, e;          // nodes, edges
    cin >> n >> e;

    // Read the e undirected edges.
    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);   // both directions
    }

    // Reset the arrays (memset fills bytes: false = 0, -1 = all bytes 0xFF).
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));

    int l;
    cin >> l;          // the level we are asked about

    bfs(0, l);         // the source is always node 0

    // Nodes join `nodes` in BFS order, which is not sorted. greater<int>()
    // flips sort's comparison, so the biggest number comes first.
    // begin()/end() say "sort the whole vector".
    sort(nodes.begin(), nodes.end(), greater<int>());

    for(int node : nodes){      // print each collected node
        cout << node << " ";
    }

    cout << endl;   // finish the line

    // Cost: O(V + E) for the BFS plus O(k log k) to sort the k nodes found.

    return 0;   // normal end
}
