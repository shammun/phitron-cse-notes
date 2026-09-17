/*

https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/shortest-distance-2

Shortest Distance

Problem Statement

You'll be given a graph of N nodes and E edges. For each edge, you'll be given A, B and W which means there is an 
edge from A to B only and which will cost W.

Also, you'll be given Q queries, for each query you'll be given X and Y, where X is the source and Y is the 
destination. You need to print the minimum cost from X to Y for each query. If there is no connection between X 
and Y, print -1.

Note: There can be multiple edges from one node to another. Make sure you handle this one.

Input Format
- First line will contain N and E.
- Next E lines will contain A, B and W.
- After that you'll get Q.
- Next Q queries will contain X and Y.

Constraints
1. 1 <= N <= 100
2. 1 <= E <= 10^5
3. 1 <= A, B <= N
4. 1 <= W <= 10^9
5. 1 <= Q <= 10^5
6. 1 <= X, Y <= N

Output Format
- Output the minimum cost for each query.

Sample Input 0
4 7
1 2 10
2 3 5
3 4 2
4 2 3
3 1 7
2 1 1
1 4 4
6
1 2
4 1
3 1
1 4
2 4
4 2

Sample Output 0
7
4
6
4
5
3

Sample Input 1
4 4
1 2 4
2 3 4
3 1 2
1 2 10
6
1 2
2 1
1 3
3 1
2 3
3 2

Sample Output 1
4
6
8
2
4
6

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void floyd_warshall(long long adj_mat[105][105], int n){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]){
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;

    long long adj_mat[105][105];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                adj_mat[i][j] = 0;
            } else{
                adj_mat[i][j] = LLONG_MAX;
            }
        }
    }

    while(e--){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], c);
    }

    floyd_warshall(adj_mat, n);

    int q;
    cin >> q;

    while(q--){
        int X, Y;
        cin >> X >> Y;

        if(adj_mat[X][Y] == LLONG_MAX){
            cout << -1 << endl;
        } else{
            cout << adj_mat[X][Y] << endl;
        }
    }

    return 0;
}
