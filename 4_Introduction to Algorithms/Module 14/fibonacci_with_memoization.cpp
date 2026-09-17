#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>

using namespace std;
int dp[1005];

int fib(int n){
    if(n < 2){ // or, we can also write if(n == 0 || n == 1)
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << fib(n) << endl;

    return 0;
}