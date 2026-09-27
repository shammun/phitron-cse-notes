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

// Solution idea: this is Fibonacci with four terms instead of two, so it is
// solved exactly like fibonacci_with_memoization.cpp (Module 14): a recursive
// function that stores every answer it works out in dp[], so each T(k) is
// computed once instead of an exponential number of times.
//
// The DP in three parts:
//   meaning     dp[k] = T(k)
//   base cases  T0 = 0, T1 = 1, T2 = 1, T3 = 2
//   transition  T(n) = T(n-1) + T(n-2) + T(n-3) + T(n-4)

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <cmath>        // not used here
#include <cstdio>       // not used here
#include <vector>       // included twice - harmless, headers guard against it
#include <cstring>      // memset
#include <string>       // not used here

using namespace std;    // no std:: prefix
// dp[k] = T(k) once it is known, -1 while it is still unknown.
// n is at most 30, so 35 boxes are plenty.
int dp[35];

// Returns T(n), top-down with memoization.
int tetranacci(int n){
    // Base cases: the four starting values are given, not computed.
    // T0 = 0 and T1 = 1 are just n itself, so one test covers both.
    if(n <= 1){ // or, we can also write if(n == 0 || n == 1)
        return n;
    }
    if(n== 2){          // T2 = 1
        return 1;
    }
    if(n == 3){         // T3 = 2
        return 2;
    }
    // Memo check: if T(n) was already worked out on another branch of the
    // recursion, hand back the stored value and skip the whole subtree.
    if(dp[n] != -1){
        return dp[n];
    }
    // Otherwise follow the rule T(n) = sum of the four terms before it,
    // and write the result down before returning it.
    dp[n] = tetranacci(n-1) + tetranacci(n-2) + tetranacci(n-3) + tetranacci(n-4);
    return dp[n];
}

int main(){
    // Mark every box "unknown". -1 is safe because no Tetranacci number is negative.
    // memset fills bytes: 0xFF in all four bytes of an int is -1.
    memset(dp, -1, sizeof(dp));
    int n;              // which term
    cin >> n;
    // With n = 5: T5 = T4 + T3 + T2 + T1 = 4 + 2 + 1 + 1 = 8.
    cout << tetranacci(n) << endl;

    // Each T(k) is computed once and each call does O(1) work: O(n) time, O(n) memory.
    return 0;
}
