#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

vector<int> adj_list[1005];
bool visited[1005];
int level[1005];
int parent[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    // parent[src] = -1;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        cout << par << " ";

        for(int child : adj_list[par]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
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
    memset(parent, -1, sizeof(parent));

    int src, dest;
    cin >> src >> dest;

    bfs(src);

    /*
    for(int i=0; i<n; i++){
        cout << i << " parent -> " << parent[i] << endl;
    }
    */

    // First way to print path -- prints in reverse order
    int node = dest;

    while(node != -1){
        cout << node << " ";
        node = parent[node];
    }

    // Second way to print path -- prints in correct order
    vector<int> path;
    int node2 = dest;
    while(node2 != -1){
        path.push_back(node2);
        node2 = parent[node2];
    }
    reverse(path.begin(), path.end());
    for(int x : path){
        cout << x << " ";
    }

    return 0;
}