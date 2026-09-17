/*

https://cses.fi/problemset/task/1666/

Building Roads

Byteland has n cities, and m roads between them. The goal is to construct new roads so that there 
is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads 
should be built.

Input
The first input line has two integers n and m: the number of cities and roads. The cities are 
numbered 1,2, ...,n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is 
a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.

Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.
Constraints

1. 1 <= n <= 10^5
2. 1 <= m <= 2x10^5
3. 1 <= a,b <= n

Example
Input:
4 2
1 2
3 4

Output:
1
2 3

*/


#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
    vis[node] = true;
    for(int child : adj[node]){
        if(!vis[child]){
            dfs(child, adj, vis);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n, false);
    vector<int> components;

    for(int i=0; i<n; i++){
        if(!vis[i]){
            components.push_back(i+1);
            dfs(i, adj, vis);
        }
    }

    int k = components.size() - 1;
    cout << k << endl;

    for(int i=0; i<k; i++){
        cout << components[i] << " " << components[i+1] << endl;
    }

    return 0;
}