/*

Problem Statement

You will be given a directed graph as input. Then you will receive Q queries. For each query, you will be 
given two nodes, A and B. You need to determine whether you can go from A to B directly without using any 
other nodes.

Input Format

- The first line will contain N and E, the number of nodes and the number of edges, 
respectively. The values of the nodes range from 0 to N-1.
- Next E lines will contain two node values which means there is a connection from first 
node to second node.
- The next line will contain Q.
- The following Q lines will each contain A and B.

Constraints

1. 1 <= N <= 10^3
2. 1 <= E <= 10^6
3. 1 <= Q <= 10^6
4. 0 <= A, B < N

Output Format

For each query output YES if it is possible to go from A to B directly without using any 
other nodes, NO otherwise. Don't forget to put a new line after each query.

Sample Input 0
5 6
0 1
1 2
2 3
3 4
1 4
0 2
10
0 1
1 0
2 2
2 3
0 3
3 0
1 4
4 1
4 3
1 2

Sample Output 0
YES
NO
YES
YES
NO
NO
YES
NO
NO
YES

*/

// Idea: "directly, without using any other node" means ONE edge, so no search
// is needed. Store the directed graph as an adjacency list (Module 1) and, for
// a query (A, B), look through A's list for B. The sample also treats A == B as
// YES (a node can always "reach" itself), so that case is answered first.
//
// Example: edge 1 -> 2 exists, so "1 2" is YES, but "2 1" is NO because the
// graph is directed and nobody stored 2 -> 1.

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj_list[1005];   // adj_list[a] = nodes with an arrow a -> them

// Is there an arrow from -> to (or are they the same node)?
bool direct_edge(int from, int to){
    if(from == to){
        return true;          // same node: the sample expects YES
    }
    // Scan the neighbours of "from", looking for "to".
    for(int child : adj_list[from]){
        if(child == to){
            return true;
        }
    }
    return false;             // walked the whole list, no arrow to "to"
}

int main(){
    int n, e;
    cin >> n >> e;

    // Directed: store only a -> b, never b -> a.
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }

    int Q;
    cin >> Q;

    while(Q--){
        int from, to;
        cin >> from >> to;
        if(direct_edge(from, to)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    // Another way: an N x N adjacency matrix (N <= 1000 fits) answers each
    // query in O(1) with adj_mat[A][B]. The list costs O(degree of A) per query.

    return 0;
}
