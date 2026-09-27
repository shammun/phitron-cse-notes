/*

https://leetcode.com/problems/climbing-stairs/

70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to 
the top?


Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45


*/

// Solution idea (memoized recursion, this module).
// To stand on step n, the LAST move was either a 1-step (from n-1) or a
// 2-step (from n-2). So ways(n) = ways(n-1) + ways(n-2): the Fibonacci rule,
// with a different start: ways(1) = 1, ways(2) = 2.
// Plain recursion would recompute the same steps again and again (like
// fibonacci_recursion.cpp); the dp[] table remembers each answer once found.
//
// The DP in three parts:
//   meaning     dp[i] = number of distinct ways to reach step i
//   base cases  ways(1) = 1, ways(2) = 2
//   transition  dp[i] = ways(i-1) + ways(i-2)
// Trace: ways(3) = 2 + 1 = 3, ways(4) = 3 + 2 = 5, ways(5) = 5 + 3 = 8.
//
// No #include or main here: LeetCode supplies both (and "using namespace std;")
// and calls climbStairs itself, so this file only compiles on LeetCode.

// LeetCode's required class.
class Solution {
    public:   // members usable from outside the class
        int dp[50];   // dp[i] = ways to reach step i; -1 = not worked out yet
        // Why -1: a real answer is always >= 1, so -1 can never be mistaken
        // for a stored result. 0 would not work as the marker as safely.
        int fibo(int n){
            // Base cases: 1 way to reach step 1, 2 ways to reach step 2
            // (1+1 or 2). The test n < 3 covers both, since the answer is n.
            if(n<3){
                return n;
            }
            // Already solved? Hand back the stored answer, no recursion.
            if(dp[n] != -1){
                return dp[n];
            }
            // Solve once, store it, then return it.
            dp[n] = fibo(n-1) + fibo(n-2);
            return dp[n];
        }
        int climbStairs(int n) {
            // LeetCode may reuse the same object for several tests, so clear
            // the table at the start of every call.
            // memset fills every BYTE with 0xFF, which makes each int -1.
            memset(dp, -1, sizeof(dp));
            int ans = fibo(n);   // ways to reach the top step n
            return ans;
        }
        // Cost: O(n) time, each step is solved once; O(n) memory for dp and the call stack.
    };
