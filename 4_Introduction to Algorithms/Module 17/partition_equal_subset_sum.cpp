/*

Partition Equal Subset Sum   (LeetCode 416)

You are given an array of positive integers. Decide whether it can be split
into two groups whose sums are equal. Every number must go into exactly one
of the two groups.

The trick is that the two sums are equal only when each one is total / 2.
So the question is really the subset sum question of this module: is there a
subset that adds up to exactly total / 2? If the total is odd there is
nothing to check, the answer is no.

Constraints
    1 <= nums.length <= 200
    1 <= nums[i] <= 100

Input (for the small driver below)
    first line: n, the number of values
    second line: the n values

Output
    canPartition = true   if the array can be split into two equal halves
    canPartition = false  otherwise

Example 1

input
4
1 5 11 5

output
canPartition = true

    The total is 22, so each side must be 11. One side is {11}, the other
    is {1, 5, 5}.

Example 2

input
4
1 2 3 5

output
canPartition = false

    The total is 11, which is odd, so the two sides can never match.

*/

// The DP in three parts:
//   meaning     dp[i][s] = can items 0..i pick a subset adding up to s?
//               (1 = yes, 0 = no, -1 = not worked out yet)
//   base case   i < 0: yes only if s == 0
//   transition  dp[i][s] = dp[i-1][s] (skip i) OR dp[i-1][s - val[i]] (take i)
// Why -1 as the "unknown" marker: the real answers are only 0 or 1, so -1
// can never be mistaken for a stored answer.

// <bits/stdc++.h>: g++'s "include the whole standard library" header.
#include <bits/stdc++.h>
using namespace std;    // no std:: prefix

// LeetCode's required class; canPartition is what the judge calls.
class Solution {
public:   // usable from outside the class
    vector<int> val;           // the numbers, copied in by canPartition
    vector<vector<int>> dp;    // the memo table described above

    // Can the items 0..i pick a subset that adds up to exactly `sum`?
    bool subset_sum(int i, int sum) {
        if (i < 0) {
            // No items left: we succeeded only if nothing is still owed.
            return sum == 0;
        }

        if (dp[i][sum] != -1) {     // already worked out
            return dp[i][sum];      // int 1/0 becomes true/false
        }

        // Option 1: skip item i and still owe the same sum.
        bool ans = subset_sum(i - 1, sum);

        // Option 2: take item i, but only if it is not bigger than what is
        // left to pay, otherwise `sum - val[i]` would go negative.
        // (!ans: if skipping already works, there is no need to try taking.)
        if (!ans && val[i] <= sum) {
            ans = subset_sum(i - 1, sum - val[i]);
        }

        dp[i][sum] = ans;           // store true as 1, false as 0
        return ans;
    }

    // nums is passed by reference (&): no copy on the call.
    bool canPartition(vector<int>& nums) {
        int total = 0;              // sum of all the numbers
        for (int i = 0; i < (int)nums.size(); i++) {
            total += nums[i];
        }

        // An odd total cannot be cut into two equal integer halves.
        if (total % 2 != 0) {
            return false;
        }

        int half = total / 2;       // the sum each side must reach

        val = nums;                 // copy so subset_sum can read the numbers
        // The memo has to cover every sum the recursion can ask about,
        // that is 0..half inclusive, so the row is half + 1 long.
        // assign(rows, rowValue): nums.size() rows, each half+1 cells of -1.
        dp.assign(nums.size(), vector<int>(half + 1, -1));

        // All items on offer, target = half the total.
        return subset_sum((int)nums.size() - 1, half);
    }
};

// Small driver so the file runs on its own.
int main() {
    int n;                    // how many values
    cin >> n;

    vector<int> nums(n);      // n slots
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;             // object to call canPartition on
    bool ans = sol.canPartition(nums);

    // (cond ? a : b) is the ternary operator: a if cond is true, else b.
    cout << "canPartition = " << (ans ? "true" : "false") << endl;

    return 0;   // success
}
