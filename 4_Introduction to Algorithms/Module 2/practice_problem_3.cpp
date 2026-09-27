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

/// Idea: "directly connected to N" means one edge away, i.e. N's neighbours.
// The adjacency list already stores exactly those, one entry per edge that
// touches N, so no search is needed at all: the answer is adj_list[N].size(),
// which graph books call the DEGREE of N.
//
// Trace, sample 3 with N = 1: edges touching 1 are 0-1, 1-2, 1-3,
// so adj_list[1] = {0, 2, 3} and the answer is 3.

#include <iostream>     // cin, cout
#include <vector>       // vector for the adjacency list
#include <algorithm>    // not used here
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // not used here (no BFS needed)

using namespace std;    // drop the std:: prefix

vector<int> adj_list[1005];   // adj_list[x] = the neighbours of x

int main(){
    int n, e;          // number of nodes, number of edges
    cin >> n >> e;

    // Each undirected edge a-b is stored in both lists, so it counts once
    // towards the degree of a and once towards the degree of b.
    while(e--){                     // runs e times
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);   // b becomes a neighbour of a
        adj_list[b].push_back(a);   // a becomes a neighbour of b
    }

    int node;          // the node N from the problem
    cin >> node;

    // size() of N's list = how many edges touch N = how many direct neighbours.
    // (This assumes no edge is given twice; a repeated edge would be counted twice.)
    cout << adj_list[node].size() << endl;

    return 0;   // normal end
}
