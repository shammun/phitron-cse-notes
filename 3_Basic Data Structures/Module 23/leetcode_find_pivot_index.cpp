/*

https://leetcode.com/problems/find-pivot-index/solutions/127676/find-pivot-index/

Find Pivot Index

*/



/*
 * Task in short: return the first index i where the sum of everything to the
 * left of i equals the sum of everything to the right of i (the element at i
 * itself is in neither side). Return -1 if there is none.
 * Example: [1,7,3,6,5,6] -> 3, since 1+7+3 = 11 = 5+6.
 *
 * Idea (prefix sums, as in Module 3): add up the whole array once. Then walk
 * left to right keeping leftSum. The right side never needs its own loop:
 *     rightSum = total - leftSum - nums[i]
 * so every index is checked in O(1).
 */
class Solution {
public:   // LeetCode calls pivotIndex from outside the class
    int pivotIndex(vector<int>& nums) {
        // Pass 1: total of all elements.
        int total = 0;
        for(int num : nums){        // range-for: num is each element in turn
            total += num;
        }

        // Pass 2: leftSum = sum of nums[0..i-1] (0 before the first index).
        int leftSum = 0;
        // i is the index being tested as the pivot.
        for(int i=0; i< nums.size(); i++){
            // Everything that is not on the left and not nums[i] is on the right.
            int rightSum = total - leftSum - nums[i];
            if(leftSum == rightSum){
                return i;     // first (leftmost) pivot found
            }
            // nums[i] joins the left side before moving to i+1.
            leftSum += nums[i];
        }

        // No index balanced the two sides.
        return -1;
    }
};