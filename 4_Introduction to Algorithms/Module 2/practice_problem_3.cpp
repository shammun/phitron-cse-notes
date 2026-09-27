/*

You will be given an undirected graph as input. Then you will be given a node N. You 
need to print the number of nodes that are directly connected to the node N.

Sample Input
6 5
0 1
0 2
0 3
2 3
4 5
2

Sample Output
2

Sample Input
6 5
0 1
0 2
0 3
2 3
4 5
0

Sample Output
3

Sample Input
7 7
0 1
1 2
2 3
1 3
4 0
0 5
5 6
1

Sample Output
3

*/

// Idea: "directly connected to N" means one edge away, i.e. N's neighbours.
// The adjacency list already stores exactly those, one entry per edge that
// touches N, so no search is needed at all: the answer is adj_list[N].size(),
// which graph books call the DEGREE of N.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

vector<int> adj_list[1005];   // adj_list[x] = the neighbours of x

int main(){
    int n, e;
    cin >> n >> e;

    // Each undirected edge a-b is stored in both lists, so it counts once
    // towards the degree of a and once towards the degree of b.
    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int node;
    cin >> node;

    // size() of N's list = how many edges touch N = how many direct neighbours.
    // (This assumes no edge is given twice; a repeated edge would be counted twice.)
    cout << adj_list[node].size() << endl;

    return 0;
}
