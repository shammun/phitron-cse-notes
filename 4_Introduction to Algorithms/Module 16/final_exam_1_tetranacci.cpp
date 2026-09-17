/*

https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/tetranacci-number-a-easy-version


Tetranacci Number 1

The Tetranacci sequence is an extension of the well-known Fibonacci sequence, incorporating four 
previous terms instead of two.

The Tetranacci sequence Tn is defined as follows:

- T0 = 0, T1 = 1, T2 = 1,T3 = 2
- For n >= 4, Tn = Tn-1 + Tn-2 + Tn-3 + Tn-4

Given an integer 𝑛, return the value of Tn

Note : You must solve this problem using Recursion. (Top Down)

Input Format

A single integer n representing the position in the Tetranacci sequence.

Constraints
- 0 <= n <= 30
- The result is guaranteed to fit within a 32-bit integer (<=2^31-1)

Output Format

Print a single integer, the value of Tn

Sample Input 0
4

Sample Output 0
4

Explanation 0

T4 = T3 + T2 + T1 + T0 = 2 + 1 + 1 + 0 = 4

Sample Input 1
5

Sample Output 1
8

Explanation 1
T5 = T4 + T3 + T2 + T1 = 4 + 2 + 1 + 1 = 8

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>  
#include <cstring>  
#include <string>

using namespace std;
int dp[35];

int tetranacci(int n){
    if(n <= 1){ // or, we can also write if(n == 0 || n == 1)
        return n;
    }
    if(n== 2){
        return 1;
    }
    if(n == 3){
        return 2;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = tetranacci(n-1) + tetranacci(n-2) + tetranacci(n-3) + tetranacci(n-4);
    return dp[n];
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << tetranacci(n) << endl;

    return 0;
}