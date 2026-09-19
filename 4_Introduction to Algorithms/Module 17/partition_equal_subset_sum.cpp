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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> val;
    vector<vector<int>> dp;

    // Can the items 0..i pick a subset that adds up to exactly `sum`?
    bool subset_sum(int i, int sum) {
        if (i < 0) {
            // No items left: we succeeded only if nothing is still owed.
            return sum == 0;
        }

        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

        // Option 1: skip item i and still owe the same sum.
        bool ans = subset_sum(i - 1, sum);

        // Option 2: take item i, but only if it is not bigger than what is
        // left to pay, otherwise `sum - val[i]` would go negative.
        if (!ans && val[i] <= sum) {
            ans = subset_sum(i - 1, sum - val[i]);
        }

        dp[i][sum] = ans;
        return ans;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            total += nums[i];
        }

        // An odd total cannot be cut into two equal integer halves.
        if (total % 2 != 0) {
            return false;
        }

        int half = total / 2;

        val = nums;
        // The memo has to cover every sum the recursion can ask about,
        // that is 0..half inclusive, so the row is half + 1 long.
        dp.assign(nums.size(), vector<int>(half + 1, -1));

        return subset_sum((int)nums.size() - 1, half);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    bool ans = sol.canPartition(nums);

    cout << "canPartition = " << (ans ? "true" : "false") << endl;

    return 0;
}
