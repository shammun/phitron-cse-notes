/*

https://codeforces.com/problemset/problem/20/C

Dijkstra?

You are given a weighted undirected graph. The vertices are enumerated from 1 to n. Your task is to find the 
shortest path between the vertex 1 and the vertex n.

Input
The first line contains two llegers n and m (2 ≤ n ≤ 105, 0 ≤ m ≤ 105), where n is the number of vertices and m 
is the number of edges. Following m lines contain one edge each in form ai, bi and wi (1 ≤ ai, bi ≤ n, 
1 ≤ wi ≤ 106), where ai, bi are edge endpolls and wi is the length of the edge.

It is possible that the graph has loops and multiple edges between pair of vertices.

Output
Write the only lleger -1 in case of no path. Write the shortest path in opposite case. If there are many solutions, prll any of them.

Examples
InputCopy
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

OutputCopy
1 4 3 5 

InputCopy
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

OutputCopy
1 4 3 5 

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

#define ll long long int
vector<pair<ll, ll>> adj_list[100005];
ll dis[100005];
ll par[100005];

void dijkstra(ll src){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while(!pq.empty()){
        pair<ll, ll> par = pq.top();
        pq.pop();
        ll par_node = par.second;
        ll par_dist = par.first;

        for(auto child : adj_list[par_node]){
            ll child_node = child.first;
            ll child_dist = child.second;

            if(par_dist + child_dist < dis[child_node]){
                dis[child_node] = par_dist + child_dist;
                pq.push({dis[child_node], child_node});
                par[child_node] = par_node;
            }
        }
    }
}

int main(){
    ll n, e;
    cin >> n >> e;

    while(e--){
        ll a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    for(ll i=1; i<=n; i++){
        dis[i] = LLONG_MAX;
        par[i] = -1;
    }

    dijkstra(1);

    if(dis[n] == LLONG_MAX){
        cout << -1 << endl;
    } else {
        ll node = n;
        vector<ll> path;
        while(node != -1){
            path.push_back(node);
            node = par[node];
        }

        reverse(path.begin(), path.end());

        for(auto x : path){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
