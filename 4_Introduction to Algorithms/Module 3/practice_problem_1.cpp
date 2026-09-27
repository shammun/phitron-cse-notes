/*

Question: You will be given an undirected graph as input. Then you will be given a node 
N. You need to tell the number of nodes that can be visited from node N.

Input:
6 5
0 1
0 2
0 3
2 3
4 5
2

Output:
4

Input:
6 5
0 1
0 2
0 3
2 3
4 5
4

Output:
2

Input:
7 6
0 1
1 2
2 3
1 3
4 0
5 6
1

Output:
5

*/

// Idea: "how many nodes can be visited from N" is the size of N's connected
// piece. One DFS from N enters every node of that piece exactly once, so add
// 1 each time dfs() is entered and the total is the answer (N itself included).
//
// Example 1: from node 2 the DFS reaches 2, 0, 1, 3 -> 4. Nodes 4 and 5 form a
// separate piece and are never entered.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>      // memset

using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
// Named cnt, not count: with "using namespace std" a global called count would
// clash with the library's std::count and the compiler refuses to guess.
int cnt = 0;            // nodes entered so far

void dfs(int src){
    vis[src] = true;    // mark on entry so no node is counted twice
    cnt++;              // one more node reached

    // Go as deep as possible through each unvisited neighbour.
    for(int child : adj_list[src]){
        if(!vis[child]){
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
        adj_list[b].push_back(a);   // undirected
    }

    int start_node;
    cin >> start_node;

    memset(vis, false, sizeof(vis));

    // Do NOT declare a new "int cnt = 0;" here: a local with the same name
    // would hide the global one that dfs() increases, and we would print 0.
    dfs(start_node);

    cout << cnt << endl;    // Cost: O(V + E)

    return 0;
}
