/*

Question: You will be given an undirected graph as input. You need to tell the number 
of nodes in each component in ascending order.

Input:
6 5
0 1
0 2
0 3
2 3
4 5

Output:
2 4

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
2 3 4

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
7

Input:
10 5
1 2
2 3
1 3

Output:
1 1 1 2 2 3

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
int component_size;

void dfs(int src){
    vis[src] = true;
    component_size++;

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

    vector<int> sizes;

    for(int i=0; i<n; i++){
        if(!vis[i]){
            component_size = 0;
            dfs(i);
            sizes.push_back(component_size);
        }
    }

    sort(sizes.begin(), sizes.end());

    for(int i=0; i<sizes.size(); i++){
        cout << sizes[i];
        // if(i < sizes.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
