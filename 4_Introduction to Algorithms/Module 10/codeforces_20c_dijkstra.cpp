/*

C. Dijkstra?   (Codeforces 20C)

A country has n cities, numbered 1 .. n, joined by m two-way roads. Each road
has a positive length. Print the shortest route from city 1 to city n as the
list of cities you pass through, first 1 and last n. If city n cannot be
reached, print -1. If several routes are equally short, any of them is
accepted.

This is plain Dijkstra with one addition: besides the distance we remember,
for every city, which city we came from when its distance was last improved.
Walking those parents back from n gives the route.

Input
The first line has n and m.
The next m lines each have three numbers a, b and w: a road of length w
between cities a and b. There may be several roads between the same pair, and
a road may start and end in the same city. Both n and m can be around 10^5.

Output
The cities of a shortest route from 1 to n, in order, separated by spaces, or
-1 if there is no route.

Examples

input
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

output
1 4 3 5

The route 1 -> 4 -> 3 -> 5 costs 1 + 3 + 1 = 5. Going 1 -> 2 -> 5 would cost
2 + 5 = 7.

input
3 1
1 2 5

output
-1

*/

#include <bits/stdc++.h>
using namespace std;

/* The lengths are positive but there can be about 10^5 roads, so a route can
   be far longer than an int holds. Everything that stores or adds a distance
   is long long, and INF is a large value that still leaves room for one
   addition. */
const long long INF = 1e18 / 4;

int main() {
    int n, m;
    cin >> n >> m;

    /* vector<pair<int, long long>>: for each city, the list of (neighbour,
       road length) pairs. Size n+1 so the cities keep their own numbers. */
    vector<vector<pair<int, long long>>> adj_list(n + 1);

    while(m--) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        adj_list[a].push_back({b, w});
        adj_list[b].push_back({a, w});   // the roads are two-way
    }

    vector<long long> dis(n + 1, INF);
    vector<int> parent(n + 1, -1);   // -1 means "no city came before this one"

    /* The pair is (distance, city) in that order, because the priority queue
       compares the first member first, and greater<> turns the max-heap into
       a min-heap so the closest city comes out on top. */
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dis[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        pair<long long, int> par = pq.top();
        pq.pop();
        long long par_dist = par.first;
        int par_node = par.second;

        /* An old, worse copy of this city may still be sitting in the queue
           from an earlier improvement. It is cheaper to skip it here than to
           search the queue and remove it. */
        if(par_dist > dis[par_node]) continue;

        for(auto child : adj_list[par_node]) {
            int child_node = child.first;
            long long child_dist = child.second;

            if(par_dist + child_dist < dis[child_node]) {
                dis[child_node] = par_dist + child_dist;
                parent[child_node] = par_node;   // remember how we got here
                pq.push({dis[child_node], child_node});
            }
        }
    }

    if(dis[n] == INF) {
        cout << -1 << endl;
        return 0;
    }

    /* Walk back from n; parent[1] is still -1, so the walk stops at the
       start. The cities come out reversed, so the list is turned around. */
    vector<int> path;
    int node = n;
    while(node != -1) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());

    for(int i = 0; i < (int)path.size(); i++) {
        if(i > 0) cout << " ";
        cout << path[i];
    }
    cout << endl;

    return 0;
}
