/*

https://cses.fi/problemset/task/1676/

Road Construction

There are n cities and initially no roads between them. However, every day a new road will be 
constructed, and there will be a total of m roads.
A component is a group of cities where there is a route between any two cities using the roads. After 
each day, your task is to find the number of components and the size of the largest component.

Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 
1,2, ...,n.

Then, there are m lines describing the new roads. Each line has two integers a and b: a new road is 
constructed between cities a and b.
You may assume that every road will be constructed between two different cities.

Output
Print m lines: the required information after each day.

Constraints
1. 1 <= n <= 10^5
2. 1 <= m <= 2X10^5
3. 1 <= a,b <= n

Example

Input:
5 3
1 2
1 3
4 5

Output:
4 2
3 3
2 3


*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int par[100005];
int group_size[100005];
int cmp, max_size;

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
        max_size = max(max_size, group_size[leader1]);
    } else{
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
        max_size = max(max_size, group_size[leader2]);
    }
    cmp--;
}

int main(){
    int n, e;
    cin >> n >> e;
    cmp = n;
    max_size = 1;

    for(int i=1; i<=n; i++){
        par[i] = -1;
        group_size[i] = 1;
    }

    while(e--){
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
        cout << cmp << " " << max_size << endl;
    }
}
