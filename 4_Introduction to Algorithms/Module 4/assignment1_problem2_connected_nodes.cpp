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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj_list[1005];

int main(){
    int n, e;
    cin >> n >> e;

    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int Q;
    cin >> Q;

    while(Q--){
        int x;
        cin >> x;
        if(adj_list[x].size() == 0){
            cout << -1 << endl;
        }
        else{
            sort(adj_list[x].begin(), adj_list[x].end(), greater<int>());
            for(int i=0; i<adj_list[x].size(); i++){
                cout << adj_list[x][i] << " ";
            }
            cout << endl;
        }
        
    }

    return 0;
}