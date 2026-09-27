/*

Problem Statement

You will be given an undirected graph as input. Then you will be given Q queries. For
each query you will be given a node X. You need to print the nodes that are connected
with X in descending order.

Note: If there is no node connected to X, then print -1.

Input Format

- The first line will contain N and E, the number of nodes and the number of edges,
respectively. The values of the nodes range from 0 to N-1.
- Next E lines will contain two node values which means there is a connection between
first node and second node.
- The next line will contain Q.
- The following Q lines will each contain X.

Constraints

1. 1 <= N <= 10^3
2. 1 <= E <= 10^6
3. 1 <= Q <= 10^6
4. 0 <= X <= N

Output Format

- Output the nodes that are connected with  in descending order.

Sample Input 0

6 8
0 4
0 5
4 2
4 3
5 3
2 0
0 1
1 3
6
0
1
2
3
4
5

Sample Output 0

5 4 2 1
3 0
4 0
5 4 1
3 2 0
3 0

Sample Input 1

5 3
0 1
1 2
0 4
2
3
0
Sample Output 1

-1
4 1

*/

// Idea: "the nodes connected with X" are X's direct neighbours, which is
// exactly X's adjacency list. So each query is: if the list is empty print -1,
// otherwise sort that list largest-first and print it.
//
// Example: in sample 0, node 0 has edges to 4, 5, 2 and 1 -> "5 4 2 1".
// In sample 1, node 3 appears in no edge, so its list is empty -> "-1".

#include <iostream>     // cin / cout
#include <vector>       // vector (growable array)
#include <algorithm>    // sort, greater

using namespace std;    // use cin, vector, sort ... without the std:: prefix

// Adjacency list: one vector per node. adj_list[x] = every node joined to x by
// an edge. Size 1005 covers node values 0..1000 (N <= 1000, and even X == N
// from the constraints stays inside the array). Global = starts empty.
vector<int> adj_list[1005];

int main(){
    int n, e;                 // n = number of nodes, e = number of edges
    cin >> n >> e;

    // Undirected: each edge goes into both endpoints' lists.
    // One pass reads one edge; the loop stops after e edges.
    for(int i=0; i<e; i++){
        int a, b;             // the two ends of this edge
        cin >> a >> b;
        adj_list[a].push_back(b);   // b is a neighbour of a
        adj_list[b].push_back(a);   // and a is a neighbour of b
    }

    int Q;                    // number of queries
    cin >> Q;

    // Runs Q times: test Q, then decrease it; stops when Q hits 0.
    while(Q--){
        int x;                // the node asked about
        cin >> x;
        if(adj_list[x].size() == 0){      // size() = how many neighbours x has
            cout << -1 << endl;           // X touches no edge at all
        }
        else{
            // Sort X's own list in descending order (greater<int>() flips the
            // comparison). Sorting it in place is harmless: if X is asked
            // again, the list is simply already sorted.
            // begin()/end() mark the whole range of the vector to sort.
            // Without greater<int>() sort would give ascending order.
            sort(adj_list[x].begin(), adj_list[x].end(), greater<int>());
            // Print every neighbour, each followed by a space
            // (the sample output also ends each line with a space).
            for(int i=0; i<adj_list[x].size(); i++){
                cout << adj_list[x][i] << " ";   // i-th neighbour of x
            }
            cout << endl;                         // finish this query's line
        }

    }

    return 0;                 // normal end of program
}
