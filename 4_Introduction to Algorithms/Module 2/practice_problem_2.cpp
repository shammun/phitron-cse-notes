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

// Idea: a BFS from 0 already hands every node its level (its distance from 0).
// So run one BFS, and as each node leaves the queue, keep it if its level is L.
// The problem wants those nodes largest first, so sort the collected nodes in
// descending order at the end.

#include <iostream>
#include <vector>
#include <algorithm>    // sort, greater
#include <string>
#include <stack>
#include <queue>
#include <cstring>      // memset

using namespace std;

vector<int> adj_list[1005];
bool visited[1005];
int level[1005];
vector<int> nodes;          // the nodes found at level L

void bfs(int src, int l){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        // By the time par leaves the queue its level is final (BFS finds each
        // node by the fewest edges first), so it is safe to test it here.
        if(level[par] ==l){
            nodes.push_back(par);
        } 

        for(int child : adj_list[par]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
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
    memset(level, -1, sizeof(level));

    int l;
    cin >> l;          // the level we are asked about

    bfs(0, l);         // the source is always node 0

    // Nodes join `nodes` in BFS order, which is not sorted. greater<int>()
    // flips sort's comparison, so the biggest number comes first.
    sort(nodes.begin(), nodes.end(), greater<int>());

    for(int node : nodes){
        cout << node << " ";
    }

    cout << endl;

    // Cost: O(V + E) for the BFS plus O(k log k) to sort the k nodes found.

    return 0;
}
