/*

https://leetcode.com/problems/left-and-right-sum-differences/

Left and Right Sum Differences


*/


/*
 * Task in short: for each index i, leftSum[i] is the sum of the elements
 * before i and rightSum[i] the sum of the elements after i. Return the list
 * of |leftSum[i] - rightSum[i]|.
 * Example: [10,4,8,3] -> left [0,10,14,22], right [15,11,3,0]
 *          -> answer [15,1,11,22].
 */
class Solution {
public:   // LeetCode calls leftRightDifference from outside the class
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum;        // leftSum[i]  = sum of the elements before i
        vector<int> rightSum;       // rightSum[i] = sum of the elements after i

        // Left sums are a running (prefix) sum shifted by one place:
        // nothing is left of index 0, and only nums[0] is left of index 1.
        leftSum.push_back(0);
        leftSum.push_back(nums[0]);
        int sum1 = nums[0];         // running total of the elements seen so far

        // Each next left sum adds one more element. The loop stops one early
        // because the last element is never to the left of anything.
        // (nums.size() is unsigned; with one element size()-1 is 0 and the loop simply does not run.)
        for(int i=1; i<nums.size()-1; i++){
            sum1 += nums[i];
            leftSum.push_back(sum1);
        }


        // Right sum of index i-1 = nums[i] + nums[i+1] + ... + the last one.
        // It is added up from scratch each time with an inner loop, which
        // makes this part O(n^2). A running sum from the right end (or
        // total - leftSum - nums[i], as in the pivot index problem) would
        // give O(n).
        for(int i=1; i<nums.size(); i++){
            int sum2 = nums[i];                 // start the sum at nums[i]
            for(int j =i+1; j<nums.size(); j++){
                sum2 += nums[j];
            }
            rightSum.push_back(sum2);           // this is rightSum[i-1]
        }
        // Nothing is to the right of the last index.
        rightSum.push_back(0);

        // Answer: the absolute difference at every index.
        vector<int> result;

        for(int i=0; i<nums.size(); i++){
            result.push_back(abs(leftSum[i] - rightSum[i]));   // abs() drops the minus sign
        }


        return result;
    }
};