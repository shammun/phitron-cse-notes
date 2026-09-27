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

// Practice Day problem 3: Building Roads again (Module 7 solved it with DFS),
// this time with DSU as the practice day asks. Every existing road is a union.
// When all roads are in, each group has exactly one leader (par == -1), and
// each group is one component. Linking the leaders in a chain connects
// everything with (number of leaders - 1) new roads.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int par[100005];          // par[x] = x's parent in its group; -1 = x is a leader
int group_size[100005];   // group_size[L] = members in leader L's group

// Leader of node's group, with path compression (find_optimized.cpp).
int find(int node){
    if(par[node] == -1){
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;   // point straight at the leader next time
    return leader;
}

// Join the groups of node1 and node2, smaller group under the bigger one
// (union by size, as in union.cpp).
void dsu_union(int node1, int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);

    if(leader1 == leader2){
        return;   // already connected: this road changes nothing
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
    int n, m;
    cin >> n >> m;

    memset(par, -1, sizeof(par));   // everyone starts alone, as a leader

    for(int i=1; i<=n; i++){
        group_size[i] = 1;
    }

    // Each existing road merges the groups of its two cities.
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }

    // One leader per component.
    vector<int> component_leaders;
    for(int i=1; i<=n; i++){
        if(par[i] == -1){
            component_leaders.push_back(i);
        }
    }

    int new_roads = component_leaders.size() - 1;
    cout << new_roads << endl;

    // Chain: leader 0 - leader 1 - leader 2 - ...
    for(int i=0; i <component_leaders.size() - 1; i++){
        cout << component_leaders[i] << " " << component_leaders[i + 1] << endl;
    }

    // Another valid answer: a star, joining every leader to the first one.
    /*
    // Star topology
    for(int i = 0; i < new_roads; i++){
        cout << component_leaders[0] << " " << component_leaders[i + 1] << endl;
    }
    */

    // About O(n + m): each find is almost constant thanks to both tricks.
    return 0;
}
