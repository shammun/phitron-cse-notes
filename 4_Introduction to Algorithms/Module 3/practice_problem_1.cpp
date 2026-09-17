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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
int count = 0;

void dfs(int src){
    vis[src] = true;
    count++;

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
        adj_list[b].push_back(a);
    }

    int start_node;
    cin >> start_node;

    memset(vis, false, sizeof(vis));

    int count = 0;
    dfs(start_node);

    cout << count << endl;

    return 0;
}