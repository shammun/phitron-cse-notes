/*

https://codeforces.com/problemset/problem/25/D

Roads not only in Berland

Berland Government decided to improve relations with neighboring countries. First of all, it was decided to build new roads so that from 
each city of Berland and neighboring countries it became possible to reach all the others. There are n cities in Berland and neighboring 
countries in total and exactly n - 1 two-way roads. Because of the recent financial crisis, the Berland Government is strongly pressed for 
money, so to build a new road it has to close some of the existing ones. Every day it is possible to close one existing road and immediately 
build a new one. Your task is to determine how many days would be needed to rebuild roads so that from each city it became possible to reach 
all the others, and to draw a plan of closure of old roads and building of new ones.

Input
The first line contains integer n (2 ≤ n ≤ 1000) — amount of cities in Berland and neighboring countries. Next n - 1 lines contain the 
description of roads. Each road is described by two space-separated integers ai, bi (1 ≤ ai, bi ≤ n, ai ≠ bi) — pair of cities, which the 
road connects. It can't be more than one road between a pair of cities. No road connects the city with itself.

Output
Output the answer, number t — what is the least amount of days needed to rebuild roads so that from each city it became possible to reach all 
the others. Then output t lines — the plan of closure of old roads and building of new ones. Each line should describe one day in the format 
i j u v — it means that road between cities i and j became closed and a new road between cities u and v is built. Cities are numbered from 1. If 
the answer is not unique, output any.

*/

// Solution idea (DSU, Module 11).
// n cities and n-1 roads: if they were all useful, the map would already be
// one connected tree. Every road that closes a cycle is wasted, and each wasted
// road means one component too many. So:
//   1. Read the roads through a DSU. A road whose ends already share a leader
//      is a "remove" road (it adds nothing).
//   2. Then join every component to city 1's component: each join is an "add"
//      road. There are exactly as many adds as removes (n-1 roads in total,
//      every useful one cuts the component count by one).
//   3. Pair them: day i closes remove[i] and builds add[i].

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int par[1005];          // DSU parent; -1 = leader
int group_size[1005];   // group size, kept at the leader

int find(int node){
    if(par[node] == -1){
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;   // path compression
    return leader;
}

void dsu_union(int node1, int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);

    if(leader1 == leader2){
        return;
    }

    // Union by size.
    if(group_size[leader1] >= group_size[leader2]){
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    } else{
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        par[i] = -1;
        group_size[i] = 1;
    }

    vector<pair<int, int>> remove_roads;   // roads that only closed a cycle
    vector<pair<int, int>> add_roads;      // new roads that join two components

    // Step 1: sort the old roads into "useful" (union) and "wasted" (remove).
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        if(leaderA == leaderB){
            remove_roads.push_back({a, b});   // a and b were already connected
        } else {
            dsu_union(a, b);
        }
    }

    // Step 2: walk over every city. If it is not yet in city 1's component,
    // build a road 1 - i and merge, so its whole component joins at once.
    // Later cities of that same component now share the leader and are skipped.
    for(int i=2; i<=n; i++){
        int leader1 = find(1);
        int leader2 = find(i);
        if(leader1 != leader2){
            add_roads.push_back({1, i});
            dsu_union(1, i);
        }
    }

    // Step 3: one day per wasted road, closing it and building one new road.
    cout << remove_roads.size() << endl;

    for(int i=0; i<remove_roads.size(); i++){
        cout << remove_roads[i].first << " " << remove_roads[i].second << " " << add_roads[i].first << " " << add_roads[i].second << endl;
    }

    // Debug helper: print only the roads that get closed.
    /*
    for(auto road : remove_roads){
        cout << road.first << " " << road.second << endl;
    }
    */

    // Cost: about O(n * alpha(n)).
}
