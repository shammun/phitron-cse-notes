/*

https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/1516133080/

Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert 
it to a height-balanced binary search tree.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

Constraints:

- 1 <= nums.length <= 10^4
- -10^4 <= nums[i] <= 10^4
- nums is sorted in a strictly increasing order.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* array_to_BST(vector<int>& nums, int start, int end) {
        if(start > end){
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* leftroot = array_to_BST(nums, start, mid-1);
        TreeNode* rightroot = array_to_BST(nums, mid+1, end);
        root->left = leftroot;
        root->right = rightroot;
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = array_to_BST(nums, 0, nums.size() - 1);
        return root;
    }
};