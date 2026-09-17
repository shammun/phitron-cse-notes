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

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        cout << par << " ";

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

    int src, dest;
    cin >> src >> dest;

    bfs(src);

    /*
    for(int i=0; i<n; i++){
        cout << "level of " << i << " = " << level[i] << endl;
    }
    */
    
    cout << "level of " << dest << " = " << level[dest] << endl;


    return 0;
}