/*

https://leetcode.com/problems/fibonacci-number/description/

Fibonacci Number

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci 
sequence, such that each number is the sum of the two preceding ones, starting from 0 
and 1. That is,

    F(0) = 0, F(1) = 1
    F(n) = F(n - 1) + F(n - 2), for n > 1.

    Given n, calculate F(n).

 

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

Constraints:

0 <= n <= 30


*/

// Solution idea (bottom-up DP, like fibonacci_bottom_up_loop.cpp).
// Fill a table from the smallest case upward: dp[0] and dp[1] are given, and
// every later cell is the sum of the two cells just before it. No recursion,
// and each value is computed exactly once.

class Solution {
    public:
        int fib(int n) {
            // Answer the two base cases directly.
            if(n == 0){
                return 0;
            }
            if(n == 1){
                return 1;
            }

            int dp[31];   // n <= 30, so 31 cells are enough
            // Not strictly needed: every cell up to n is written before it is read.
            memset(dp, -1, sizeof(dp));

            dp[0] = 0;
            dp[1] = 1;

            // Build upward: when we compute dp[i], dp[i-1] and dp[i-2] are ready.
            for(int i=2; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2];
            }

            return dp[n];
            // Cost: O(n) time, O(n) memory.
        }
    };
