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

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj_list[1005];

bool direct_edge(int from, int to){
    if(from == to){
        return true;
    }
    for(int child : adj_list[from]){
        if(child == to){
            return true;
        }
    }
    return false;
}

int main(){
    int n, e;
    cin >> n >> e;

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

    return 0;
}