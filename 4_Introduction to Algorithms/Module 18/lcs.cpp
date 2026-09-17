// Longest common substring using recursion
// We will be given two strings a and b. We have to find the length of the 
// longest common substring of the two strings.
// We will use memoization to optimize the solution.


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
string a, b;
int dp[1005][1005];

int lcs(int i, int j){
    if(i < 0 || j < 0){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(a[i] == b[j]){
        dp[i][j] = lcs(i-1, j-1) + 1;
        return dp[i][j];
    } else{
        int op1 = lcs(i-1, j);
        int op2 = lcs(i, j-1);
        dp[i][j] = max(op1, op2);
        return dp[i][j];
    }
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    cout << lcs(n-1, m-1);

    return 0;
}
