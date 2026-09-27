/*

https://leetcode.com/problems/house-robber/description/

198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain 
amount of money stashed, the only constraint stopping you from robbing each of them is that 
adjacent houses have security systems connected and it will automatically contact the police if 
two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum 
amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400

*/

// Solution idea (bottom-up DP, take-or-leave like knapsack).
// dp[i] = the most money from houses 0..i. For house i there are two choices:
//   rob it   -> nums[i] + dp[i-2]  (house i-1 must then be left alone)
//   skip it  -> dp[i-1]
// Keep the bigger one.

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n==0){
                return 0;
            }
            if(n==1){
                return nums[0];   // a single house: rob it
            }

            int dp[105];   // at most 100 houses
            memset(dp, 0, sizeof(dp));

            // The first two cells have no i-2, so fill them by hand.
            dp[0] = nums[0];                  // only house 0 exists
            dp[1] = max(nums[0], nums[1]);    // neighbours: pick the richer one

            for(int i=2; i <n; i++){
                dp[i] = max(nums[i] + dp[i-2], dp[i-1]);   // rob i, or skip i
            }

            return dp[n-1];   // best over all houses
            // Cost: O(n) time, O(n) memory.
        }
};

    // Test the solution
    // This file brings its own main, with LeetCode's two examples built in,
    // so it reads no input.
int main() {
    // Test case 1
    std::vector<int> nums1 = {1, 2, 3, 1};
    Solution sol1;
    std::cout << "Example 1 output: " << sol1.rob(nums1) << std::endl; // Expected: 4

    // Test case 2
    std::vector<int> nums2 = {2, 7, 9, 3, 1};
    Solution sol2;
    std::cout << "Example 2 output: " << sol2.rob(nums2) << std::endl; // Expected: 12

    return 0;
}
