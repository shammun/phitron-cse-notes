#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

bool vis[105];
vector<int> adj_list[105];
bool pathvisit[105];
bool cycle;

void dfs(int src){
    vis[src] = true;
    pathvisit[src] = true;
    for(int child : adj_list[src]){
        if(vis[child] && pathvisit[child]){
            cycle = true;
        }
        if(!vis[child]){
            dfs(child);
        }
    }
    pathvisit[src] = false;
}

int main(){
    int n, e;
    cin >> n >> e;
    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(pathvisit, false, sizeof(pathvisit));

    cycle = false;

    // We are running for loop as there could be disconnected 
    // components
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(cycle){
        cout << "Cycle Detected" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }

    return 0;
}