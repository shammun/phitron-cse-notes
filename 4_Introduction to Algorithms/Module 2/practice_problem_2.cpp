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
vector<int> nodes;

void bfs(int src, int l){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while(!q.empty()){
        int par = q.front();
        q.pop();

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
    cin >> l;

    bfs(0, l);

    sort(nodes.begin(), nodes.end(), greater<int>());

    for(int node : nodes){
        cout << node << " ";
    }

    cout << endl;

    return 0;
}
