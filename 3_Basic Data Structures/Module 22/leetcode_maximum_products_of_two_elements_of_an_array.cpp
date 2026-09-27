/*

https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/

Maximum Product of Two Elements in an Array

Given the array of integers nums, you will choose two different indices i and j of 
that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the 
maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the 
maximum value of (5-1)*(5-1) = 16.


*/

/*
 * Idea: every value is at least 1, so (a-1)*(b-1) is biggest when a and b
 * are the two biggest values. One pass keeps the largest value seen so far
 * (max_first) and the second largest (max_second); no sorting needed.
 *
 * With [3,4,5,2]: after 3 -> (3,0), after 4 -> (4,3), after 5 -> (5,4),
 * and 2 changes nothing. Answer (5-1)*(4-1) = 12.
 */
// (LeetCode's hidden main includes the headers and calls maxProduct.)
class Solution {
public:   // LeetCode calls maxProduct from outside the class
    // nums is passed by reference (&), so the vector is not copied.
    int maxProduct(vector<int>& nums) {
        // Start both at 0: every value is >= 1, so real values replace them.
        int max_first = 0;
        int max_second = 0;

        // Range-for: num takes each value of nums in turn.
        for(int num : nums){
            if(num > max_first){
                // New biggest value: the old biggest drops to second place.
                max_second = max_first;
                max_first = num;
            } else if(num > max_second){
                // Not the biggest, but bigger than the second: take its place.
                // A repeat of the biggest (the second 5 in [1,5,4,5]) also
                // lands here, so both 5s get used.
                max_second = num;
            }
        }

        return (max_first - 1) * (max_second - 1);   // e.g. (5-1)*(4-1) = 12
    }
};