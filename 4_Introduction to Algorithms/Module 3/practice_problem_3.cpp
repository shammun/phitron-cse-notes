/*

Question: You will be given an undirected graph as input. You need to tell the number 
of nodes in each component in ascending order.

Input:
6 5
0 1
0 2
0 3
2 3
4 5

Output:
2 4

Input:
9 7
0 1
0 2
0 3
2 3
4 5
6 8
7 6

Output:
2 3 4

Input:
7 7
0 1
1 2
2 3
1 3
4 0
0 5
5 6

Output:
7

Input:
10 5
1 2
2 3
1 3

Output:
1 1 1 2 2 3

*/

// Idea: the component loop of practice_problem_2.cpp, but instead of only
// counting the pieces we measure each one. A counter is set to 0 before each
// new DFS and dfs() adds 1 for every node it enters; when the DFS returns, the
// counter is that piece's size. Collect the sizes, sort them, print them.
//
// Example 1: pieces {0,1,2,3} and {4,5} -> sizes 4 and 2 -> "2 4".

#include <iostream>
#include <vector>
#include <algorithm>    // sort
#include <cstring>      // memset

using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
int component_size;     // nodes entered by the CURRENT dfs

void dfs(int src){
    vis[src] = true;
    component_size++;   // this node belongs to the piece being measured

    for(int child : adj_list[src]){
        if(!vis[child]){
            dfs(child);
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

    memset(vis, false, sizeof(vis));

    vector<int> sizes;  // one entry per component

    for(int i=0; i<n; i++){
        if(!vis[i]){
            component_size = 0;               // a new piece starts from zero
            dfs(i);
            sizes.push_back(component_size);  // its final size
        }
    }

    sort(sizes.begin(), sizes.end());         // ascending, as asked

    // Separate the numbers with a space, but put none after the last one.
    for(int i=0; i<sizes.size(); i++){
        cout << sizes[i];
        if(i < sizes.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
