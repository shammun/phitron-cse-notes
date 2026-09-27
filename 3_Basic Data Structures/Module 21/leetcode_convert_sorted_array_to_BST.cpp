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
 *
 * (LeetCode defines TreeNode and calls our function from its own hidden
 * main, so there are no #includes or main here. After ':' comes an
 * initializer list; nullptr is the C++11 name for a null pointer.)
 */
/*
 * Idea: the same trick as array_to_BST.cpp in the lesson.
 *
 * The array is sorted, so its middle value has as many smaller values on
 * its left as bigger values on its right. Making that middle value the root
 * splits the rest into two halves of (almost) equal size, so the tree comes
 * out balanced. Each half is itself a sorted array, so we build its subtree
 * the same way, with recursion.
 *
 * With [-10,-3,0,5,9]: the middle is 0 (the root), the left half [-10,-3]
 * becomes the left subtree and the right half [5,9] the right subtree.
 */
class Solution {
public:   // LeetCode calls sortedArrayToBST from outside the class
    // nums is passed by reference (&), so the vector is not copied on every call.
    // Builds a balanced BST from nums[start..end] and returns its root.
    TreeNode* array_to_BST(vector<int>& nums, int start, int end) {
        // Base case: an empty range (start passed end) gives an empty subtree.
        if(start > end){
            return NULL;
        }
        // The middle index of the current range; its value becomes the root.
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);   // `new` builds the node on the heap and returns its address
        // Everything left of mid is smaller: it builds the left subtree.
        TreeNode* leftroot = array_to_BST(nums, start, mid-1);
        // Everything right of mid is bigger: it builds the right subtree.
        TreeNode* rightroot = array_to_BST(nums, mid+1, end);
        // Hang both subtrees under the root and hand the root back.
        root->left = leftroot;
        root->right = rightroot;
        return root;
    }

    // LeetCode calls this one: build from the whole array, index 0 to n-1.
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // nums.size() is unsigned, but it is at least 1 here, so size() - 1 is safe.
        TreeNode* root = array_to_BST(nums, 0, nums.size() - 1);
        return root;                // the root of the balanced BST
    }
};