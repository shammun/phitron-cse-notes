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

// Solution idea (a choice at every cell, like knapsack's take-or-leave).
// maxPathSum(i, j) = the best sum of a path from cell (i, j) to the bottom-right
// corner. From (i, j) you step down or right, so
//     best(i, j) = A[i][j] + max(best(i+1, j), best(i, j+1)).
// The same cell is reached along many routes, so dp[i][j] stores each answer.
//
// The DP in three parts:
//   meaning     dp[i][j] = best sum of a path from (i, j) to (n-1, m-1)
//   base case   at (n-1, m-1) the path is that cell alone
//   transition  A[i][j] + max(down, right); only one option on the last
//               row / last column
// Sample: 5 -> 1 -> 9 -> 2 -> 7 = 24.

#include <iostream>     // cin, cout, endl
#include <algorithm>    // max

using namespace std;    // no std:: prefix

int n, m;             // rows, columns
int matrix[11][11];   // N, M <= 10
int dp[11][11];       // dp[i][j] = maxPathSum(i, j); -1 = not computed

// Best sum of a path from (i, j) to the bottom-right corner.
int maxPathSum(int i, int j){
    // Base case: at the goal, the path is just this one cell.
    if(i == n-1 && j == m-1){
        return matrix[i][j];
    }

    // BUG: -1 is used as "not computed", but cells can be negative
    // (down to -10^5), so a real best sum can be exactly -1. Such a cell is
    // then recomputed every time it is visited. The answer stays correct, only
    // the memo stops helping for it. Fix: a separate bool computed[11][11]
    // array, or a marker no sum can reach, such as INT_MIN.
    if(dp[i][j] != -1){
        return dp[i][j];      // already solved
    }

    // On the last row you can only go right...
    if(i == n-1){
        return matrix[i][j] + maxPathSum(i, j+1);
    }

    // ...and on the last column you can only go down. (These two edge cases
    // are cheap chains, so they are not stored in dp.)
    if(j == m-1){
        return matrix[i][j] + maxPathSum(i+1, j);
    }

    // Two real choices: go down, or go right. Keep the better one.
    int op1 = matrix[i][j] + maxPathSum(i+1, j);   // step down
    int op2 = matrix[i][j] + maxPathSum(i, j+1);   // step right

    dp[i][j] = max(op1, op2);   // store before returning
    return dp[i][j];
}

int main(){
    cin >> n >> m;                 // matrix size

    for(int i=0; i<n; i++){        // read row i
        for(int j=0; j<m; j++){    // column j
            cin >> matrix[i][j];
        }
    }

    // Every cell starts "not computed".
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j] = -1;
        }
    }

    cout << maxPathSum(0, 0) << endl;   // best path from the top-left corner

    // Cost: O(N * M), each cell solved once.
    return 0;
}
