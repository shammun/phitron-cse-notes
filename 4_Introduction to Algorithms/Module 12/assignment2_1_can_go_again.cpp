/*

https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/can-go-again

Can Go Again?

Problem Statement

You will be given N numbers of nodes, E numbers of edges in a graph. For each edge you will be given A, B and 
W which means there is a connection from A to B only and for which you need to give W cost. The value of nodes 
could be from 1 to N.

You will be given a source node S. Then you will be given a test case T, for each test case you will be given a 
destination node D. You need to tell the minimum cost from source node to destination. If there is no possible 
path from S to D then print Not Possible.

Note: If there is a negative weight cycle in the graph, then no answer would be correct. So print one line only - 
"Negative Cycle Detected".

Input Format

First line will contain  and .
Next  lines will contain ,  and .
Next line will contain source node .
Next line will contain , the number of test cases.
For each test case, you will get .

Constraints

1. 1 <= N <= 1000
2. 1 <= E <= 10^6
3. 1 <= S <= N
4. 1 <= T <= 10^3
5. 1 <= D <= N
6. -10^9 <= W <= 10^9

Output Format

Output the minimum cost for each test case.
Sample Input 0
5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
1
5
1
2
3
4
5

Sample Output 0
0
-1
-2
-5
0

Sample Input 1
5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
5
5
1
2
3
4
5

Sample Output 1
Not Possible
Not Possible
Not Possible
Not Possible
0

Sample Input 2
5 8
1 2 -2
1 3 -10
3 2 1
2 4 7
4 3 -3
4 5 5
2 5 2
4 1 1
1
5
1
2
3
4
5

Sample Output 2
Negative Cycle Detected

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Edge{
    public:
    int a, b, c;
    Edge(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;
long long dis[1005];

bool bellman_ford(int n, int source){
    dis[source] = 0;

    for(int i=1; i<n-1; i++){
        for(auto edge : edge_list){
            int a = edge.a;
            int b = edge.b;
            int c = edge.c;

            if(dis[a] != LLONG_MAX && dis[a] + c < dis[b]){
                dis[b] = dis[a] + c;
            }
        }
    }

    for(auto edge : edge_list){
        int a = edge.a;
        int b = edge.b;
        int c = edge.c;

        if(dis[a] != LLONG_MAX && dis[a] + c < dis[b]){
            return true;
        }
    }

    return false;
}

int main(){
    int n, e;
    cin >> n >> e;

    for(int i=0; i<e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    for(int i=1; i<=n;i++){
        dis[i] = LLONG_MAX;
    }

    int source;
    cin >> source;

    int t;
    cin >> t;

    bool negative_cycle = bellman_ford(n, source);

    if(negative_cycle){
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    while(t--){
        int dest;
        cin >> dest;

        if(source == dest){
            cout << 0 << endl; 
        } else if(dis[dest] == LLONG_MAX){
            cout << "Not Possible" << endl;
        } else {
            cout << dis[dest] << endl;
        }
    }

    return 0;
}


