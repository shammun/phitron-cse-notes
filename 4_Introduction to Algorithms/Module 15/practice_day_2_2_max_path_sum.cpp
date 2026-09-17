/*

https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/X

The Maximum path-sum

time limit per test: 1 second
memory limit per test: 256 megabytes

Given a matrix A of size N*M. Print the maximum sum of numbers that can be obtained when you take 
a path from A1,1 to AN,M.

If you stay in Ai,j you can only go to :
- Ai+1,j if and only if i≤N
- Ai,j+1 if and only if j≤M


Note: Solve this problem using recursion.

Input
First line contains two numbers N and M (1≤N,M≤10) N donates number of rows and M donates number 
of columns.

Next N lines each of them will contain M numbers (−10^5≤Ai,j≤10^5).

Output
Print the maximum sum of numbers can be obtained.

Example

Input
3 3
5 2 4
1 3 5
9 2 7

Output
24

*/

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int matrix[11][11];
int dp[11][11];

int maxPathSum(int i, int j){
    if(i == n-1 && j == m-1){
        return matrix[i][j];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(i == n-1){
        return matrix[i][j] + maxPathSum(i, j+1);
    }

    if(j == m-1){
        return matrix[i][j] + maxPathSum(i+1, j);
    }

    int op1 = matrix[i][j] + maxPathSum(i+1, j);
    int op2 = matrix[i][j] + maxPathSum(i, j+1);

    dp[i][j] = max(op1, op2);
    return dp[i][j];
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j] = -1;
        }
    }

    cout << maxPathSum(0, 0) << endl;

    return 0;
}