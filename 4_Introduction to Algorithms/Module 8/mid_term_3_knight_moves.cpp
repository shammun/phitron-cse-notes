/*

Knoght Moves

Problem Statement

You will be given a chessboard of N X M size. You can move anywhere in the chessboard freely. You 
will be given two cells - the knight's cell  (K_i and K_j), and the queen's cell  Q(Q_i and Q_j). 
You need to tell the minimum number of steps for the knight to attack the queen if the queen 
doesn't move.

A knight move in 8 directions. The directions are given below:

Input Format

- First line will contain , the number of test cases.
- First line of each test case will contain  and .
- Second line of each test case will contain  and .
- Third line of each test case will contain Q_i and Q_j.

Constraints

1. 1 <= T <= 100
2. 1 <= N, M <= 100
3. 0 <= K_i, Q_i < N
4. 0 <= K_j, Q_j < M

Output Format

- Output the minimum number of steps for the knight to reach the queen. If you can't reach to 
queen, print -1.

Sample Input 0
4
8 8
0 0
7 7
5 6
0 1
0 1
4 4
0 0
0 1
2 2
0 0
0 1

Sample Output 0

6
0
3
-1
Explanation 0

For the first test case, one of the possible answer could be this way:

*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int>> direction = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
int dist[105][105];

bool valid(int i, int j){
    if(i <0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}

int bfs(int k_i, int k_j, int q_i, int q_j){
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;
    q.push({k_i, k_j});
    dist[k_i][k_j]=0;

    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        if(par_i == q_i && par_j == q_j){
            return dist[par_i][par_j];
        }

        for(int i=0; i<8; i++){
            int ci = par_i + direction[i].first;
            int cj = par_j + direction[i].second;

            if(valid(ci, cj) && dist[ci][cj] == -1){
                q.push({ci, cj});
                dist[ci][cj] = dist[par_i][par_j] + 1;
            }
        }
    }

    return -1;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n >> m;
        int k_i, k_j, q_i, q_j;
        cin >> k_i >> k_j;
        cin >> q_i >> q_j;

        cout << bfs(k_i, k_j, q_i, q_j) << endl;
    }

    return 0;
}
