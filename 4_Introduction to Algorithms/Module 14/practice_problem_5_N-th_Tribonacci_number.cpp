/*

https://leetcode.com/problems/n-th-tribonacci-number/description/

1137. N-th Tribonacci Number

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537
 

Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

*/

// Solution idea (bottom-up DP): Fibonacci with THREE previous terms.
// T(0) = 0, T(1) = 1, T(2) = 1, and each later term is the sum of the three
// before it. Fill the table from the bottom so those three are always ready.
//
// The DP in three parts:
//   meaning     dp[i] = T(i)
//   base cases  dp[0] = 0, dp[1] = 1, dp[2] = 1
//   transition  dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
// Trace for n = 4: dp[3] = 1+1+0 = 2, dp[4] = 2+1+1 = 4 -> returns 4.
//
// No #include or main: LeetCode supplies them and calls tribonacci itself.

// LeetCode's required class.
class Solution {
    public:   // callable from outside
        int tribonacci(int n) {
            // The three given starting values.
            if(n == 0){
                return 0;
            }
            if(n == 1 || n == 2){
                return 1;
            }

            int dp[40] = {0};   // n <= 37; "= {0}" zeroes the whole array
            dp[0] = 0;          // base cases
            dp[1] = 1;
            dp[2] = 1;

            // Each term looks back three places.
            for(int i=3; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            }
            return dp[n];
            // Cost: O(n) time and memory. (Three variables would do in O(1) memory.)
        }
    };
