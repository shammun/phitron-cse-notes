/*

Coin Change II   (LeetCode 518)
https://leetcode.com/problems/coin-change-ii/

You have coins of a few different values and an unlimited supply of each.
Count in how many different ways they can add up to exactly `amount`.
Only WHICH coins are used (and how many of each) matters, not the order,
so 1+2 and 2+1 are the same way. If no pile works, the answer is 0.

Constraints
    1 <= coins.length <= 300
    1 <= coins[i] <= 5000, all coin values are different
    0 <= amount <= 5000

Input (for the small driver below)
    first line: amount and n, the number of coin values
    second line: the n coin values

Output
    change = <number of ways>

Example
input
5 3
1 2 5

output
change = 4

    The four piles are 5, 2+2+1, 2+1+1+1 and 1+1+1+1+1.

*/

// Solution idea: this is two ideas of this module glued together.
//   * From unbounded_knapsack.cpp: a coin never runs out, so after TAKING
//     coin i the recursion stays at i (it may take coin i again), and only
//     the LEAVE branch moves on to i-1.
//   * From count_of_subset_sum.cpp: we want a count, not a yes/no or a max,
//     so the base case returns 1 for "exactly paid" and 0 otherwise, and the
//     two branches are ADDED.
// Because the recursion decides coin by coin (all the 5s, then all the 2s,
// then all the 1s), each pile is built in only one order, so 1+2 and 2+1 can
// never both be counted.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> val;                // the coin values
    // dp[i][a] = number of ways to pay exactly a using coins 0..i (each
    // unlimited), or -1 while it has not been counted yet.
    // long long, because a count for a small amount part-way through can be
    // much bigger than the final answer the judge promises fits in an int.
    vector<vector<long long>> dp;

    //   i      = the highest coin still on offer (coins 0..i)
    //   amount = how much is still to be paid
    long long ways(int i, int amount) {
        // Paid exactly: this pile is one valid way.
        if (amount == 0) {
            return 1;
        }
        // Still owe something but no coins left: a dead end.
        if (i < 0) {
            return 0;
        }

        // Counted this state before? Reuse it.
        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        // op2 = LEAVE coin i for good: same amount, coins 0..i-1 remain.
        long long op2 = ways(i - 1, amount);

        // op1 = TAKE one more coin i, only if it is not bigger than what is
        // still owed. Note the i, not i-1: the same coin may be taken again.
        long long op1 = 0;
        if (val[i] <= amount) {
            op1 = ways(i, amount - val[i]);
        }

        // Every pile either uses one more coin i or stops using coin i, never
        // both, so the two counts do not overlap and are simply added.
        dp[i][amount] = op1 + op2;
        return dp[i][amount];
    }

    int change(int amount, vector<int>& coins) {
        val = coins;
        // One row per coin, one column per amount 0..amount (so amount + 1
        // columns), every cell starting as "not counted yet".
        dp.assign(coins.size(), vector<long long>(amount + 1, -1));

        // Start with every coin on offer and the full amount owed.
        return (int)ways((int)coins.size() - 1, amount);
    }
};

int main() {
    int amount, n;
    cin >> amount >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    Solution sol;
    cout << "change = " << sol.change(amount, coins) << endl;

    // n * (amount + 1) states, each done once with O(1) work:
    // O(n * amount) time and memory.
    return 0;
}
