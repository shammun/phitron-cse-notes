/*

Question: You will be given an undirected graph as input. You need to tell the number 
of components in this graph.

Input:
6 5
0 1
0 2
0 3
2 3
4 5

Output:
2

Input:
9 7
0 1
0 2
0 3
2 3
4 5
6 8
7 6

Output:
3

Input:
7 7
0 1
1 2
2 3
1 3
4 0
0 5
5 6

Output:
1

Input:
10 5
1 2
2 3
1 3
4 0
5 6

Output:
6 
(Because 7 8 and 9 nodes are not connected, but they are also components)


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj_list[1005];
bool vis[1005];

void dfs(int src){
    vis[src] = true;

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

    memset(vis, false, sizeof(vis));

    int count = 0;
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            dfs(i);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}