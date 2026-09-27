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

// Solution idea (Dijkstra, Module 7, plus path printing from Module 2).
// Weights are positive, so Dijkstra finds the cheapest distance from 1 to n.
// To print the ROUTE, not just its cost, remember for every node which node
// we came from when its distance last improved: par[child] = parent. Then walk
// par[] back from n to 1 and reverse, exactly like BFS path printing.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>    // reverse
#include <string>
#include <climits>      // LLONG_MAX

using namespace std;

// long long everywhere: up to 10^5 edges of length up to 10^6 can add up to
// 10^11, which does not fit in an int.
#define ll long long int
vector<pair<ll, ll>> adj_list[100005];   // adj_list[x] = {neighbour, edge length}
ll dis[100005];                           // cheapest known distance from node 1
ll par[100005];                           // node we came from on that cheapest route; -1 = none

void dijkstra(ll src){
    // Min-heap of {distance, node}: the smallest distance comes out first.
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while(!pq.empty()){
        // Named cur, not par: a local called par would hide the global par[]
        // array, and the line par[child_node] = par_node below would not compile.
        pair<ll, ll> cur = pq.top();
        pq.pop();
        ll par_node = cur.second;
        ll par_dist = cur.first;

        for(auto child : adj_list[par_node]){
            ll child_node = child.first;
            ll child_dist = child.second;

            // Relax: going through par_node is a cheaper way to child_node.
            if(par_dist + child_dist < dis[child_node]){
                dis[child_node] = par_dist + child_dist;
                pq.push({dis[child_node], child_node});
                par[child_node] = par_node;   // remember the step that gave this best route
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
        adj_list[b].push_back({a, c});   // undirected
        // Loops and repeated edges are harmless: Dijkstra just keeps the cheaper.
    }

    for(ll i=1; i<=n; i++){
        dis[i] = LLONG_MAX;   // not reached yet
        par[i] = -1;          // no parent yet; node 1 keeps -1, which ends the walk-back
    }

    dijkstra(1);

    if(dis[n] == LLONG_MAX){
        cout << -1 << endl;   // n was never reached
    } else {
        // Walk back n -> par[n] -> ... -> 1 (whose par is -1).
        ll node = n;
        vector<ll> path;
        while(node != -1){
            path.push_back(node);
            node = par[node];
        }

        // The walk collected the route backwards, so flip it to start at 1.
        reverse(path.begin(), path.end());

        for(auto x : path){
            cout << x << " ";
        }
        cout << endl;
    }

    // Cost: O((n + m) log n) for Dijkstra, O(n) for the path.
    return 0;
}
