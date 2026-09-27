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
// (no BFS/DFS) is needed. Store the directed graph as an adjacency list
// (Module 1) and, for a query (A, B), look through A's list for B. The sample
// also treats A == B as YES (a node can always "reach" itself), so that case is
// answered first.
//
// Example: edge 1 -> 2 exists, so "1 2" is YES, but "2 1" is NO because the
// graph is directed and nobody stored 2 -> 1. "0 3" is NO even though
// 0 -> 2 -> 3 is a path: that path uses the other node 2, so it is not direct.

#include <iostream>     // cin (read input) and cout (print output)
#include <vector>       // vector: an array that can grow with push_back

using namespace std;    // lets us write cin, vector, ... instead of std::cin, std::vector

// Adjacency list: an ARRAY of 1005 vectors, one vector per node (N <= 1000,
// plus a little spare room). adj_list[a] holds every node b with an arrow
// a -> b. It is global, so it lives outside main (no stack-size worries) and
// every function can use it.
vector<int> adj_list[1005];   // adj_list[a] = nodes with an arrow a -> them

// Is there an arrow from -> to (or are they the same node)?
// Parameters: the two query nodes. Returns true (YES) or false (NO).
bool direct_edge(int from, int to){
    if(from == to){           // query like "2 2"
        return true;          // same node: the sample expects YES
    }
    // Scan the neighbours of "from", looking for "to".
    // Range-for: "child" takes each value stored in adj_list[from] in turn.
    for(int child : adj_list[from]){
        if(child == to){      // found the arrow from -> to
            return true;      // stop at once, no need to look further
        }
    }
    return false;             // walked the whole list, no arrow to "to"
}

int main(){
    int n, e;                 // n = number of nodes, e = number of edges
    cin >> n >> e;            // cin >> skips spaces/newlines between numbers

    // Directed: store only a -> b, never b -> a.
    // One pass reads one edge; i counts edges read, the loop stops after e of them.
    for(int i=0; i<e; i++){
        int a, b;             // the edge goes from a to b
        cin >> a >> b;
        adj_list[a].push_back(b);   // append b to the end of a's neighbour list
    }

    int Q;                    // number of queries
    cin >> Q;

    // while(Q--) runs exactly Q times: it tests Q (non-zero = true), then
    // lowers it by 1. When Q reaches 0 the test is false and the loop ends.
    while(Q--){
        int from, to;         // the query: can we go from -> to in one step?
        cin >> from >> to;
        if(direct_edge(from, to)){
            cout << "YES" << endl;   // endl prints a newline and flushes the output
        } else {
            cout << "NO" << endl;
        }
    }

    // Another way: an N x N adjacency matrix (N <= 1000 fits) answers each
    // query in O(1) with adj_mat[A][B]. The list costs O(degree of A) per query.
    // Note: with up to 10^6 queries, "\n" instead of endl would be faster,
    // because endl forces a flush of the output every single time.

    return 0;                 // 0 tells the system the program ended normally
}
