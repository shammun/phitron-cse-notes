/*

https://cses.fi/problemset/task/1666/

Building Roads

Time limit: 1.00 s
Memory limit: 512 MB



Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route 
between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads should be built.

Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.

Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.
Constraints

1. 1 <=n<=10^5
2. 1<=m<=2.10^5
3. 1<=a,b<=n

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
#include <cstring>
using namespace std;

int par[100005];
int group_size[100005];

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

    if(group_size[leader1] >= group_size[leader1]){
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    } else{
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main(){
    int n, m;
    ccin >> n >> m;

    memset(par, -1, sizeof(par));

    for(int i=1; i<=n; i++){
        group_size[i] = 1;
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }

    vector<int> component_leaders;
    for(int i=1; i<=n; i++){
        if(par[i] == -1){
            component_leaders.push_back(i);
        }
    }

    int new_roads = component_leaders.size() - 1;
    cout << new_roads << endl;

    for(int i=0; i <component_leaders.size() - 1; i++){
        cout << component_leaders[i] << " " << component_leaders[i + 1] << endl;
    }

    /*
    // Star topology
    for(int i = 0; i < new_roads; i++){
        cout << component_leaders[0] << " " << component_leaders[i + 1] << endl;
    }
    */
    

    return 0;
}