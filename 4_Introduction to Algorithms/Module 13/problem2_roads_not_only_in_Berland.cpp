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


#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int par[1005];
int group_size[1005];

int find(int node){
    if(par[node] == -1){
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);

    if(leader1 == leader2){
        return;
    }

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

    vector<pair<int, int>> remove_roads;
    vector<pair<int, int>> add_roads;

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        if(leaderA == leaderB){
            remove_roads.push_back({a, b});
        } else {
            dsu_union(a, b);
        }
    }

    for(int i=2; i<=n; i++){
        int leader1 = find(1);
        int leader2 = find(i);
        if(leader1 != leader2){
            add_roads.push_back({1, i});
            dsu_union(1, i);
        }
    }

    cout << remove_roads.size() << endl;

    for(int i=0; i<remove_roads.size(); i++){
        cout << remove_roads[i].first << " " << remove_roads[i].second << " " << add_roads[i].first << " " << add_roads[i].second << endl;
    }

    /*
    for(auto road : remove_roads){
        cout << road.first << " " << road.second << endl;
    }
    */
    
}
