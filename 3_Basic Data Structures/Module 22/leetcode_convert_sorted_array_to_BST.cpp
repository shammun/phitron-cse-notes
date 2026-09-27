/*

https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Convert Sorted Array to Binary Search Tree (LeetCode 108)
You get an array `nums` sorted in increasing order (no repeats). Build a
binary search tree that holds all its values and is height-balanced: for
every node, the heights of its left and right subtrees differ by at most 1.
Return the root. More than one tree can be correct.

Input (LeetCode): the array nums.
Output: the root of the tree.

Example
nums = [-10,-3,0,5,9]  ->  [0,-3,9,-10,null,5]  or  [0,-10,5,null,-3,null,9]
nums = [1,3]           ->  [3,1]  or  [1,null,3]

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
 * initializer list: val(x) sets val to x; nullptr is the C++11 null pointer.)
 */

/*
 * Idea (Module 21's array_to_BST, used on the practice day):
 *
 * A BST needs smaller values on the left and bigger ones on the right. In a
 * sorted array, the middle element already has that shape: everything before
 * it is smaller, everything after it is bigger. So:
 *   - the middle element becomes the root;
 *   - the left half of the array builds the left subtree;
 *   - the right half builds the right subtree.
 * Both halves are sorted arrays again, so the same function builds them
 * (recursion). Because the two halves differ in size by at most one element,
 * the two subtrees end up with (almost) the same height: balanced.
 *
 * Instead of copying halves into new vectors, we only pass the range
 * [l, r] of the part we are working on.
 */
class Solution {
public:   // LeetCode calls sortedArrayToBST from outside the class
    // nums is a reference (&), so the vector is never copied.
    // Builds a balanced BST from nums[l..r] and returns its root.
    TreeNode* build(vector<int>& nums, int l, int r) {
        // No elements in this range: the subtree is empty.
        if(l > r){
            return NULL;
        }

        int mid = (l + r) / 2;                    // the middle of the range
        TreeNode* root = new TreeNode(nums[mid]); // it becomes the root (`new` makes the node on the heap)

        // Each recursive call trusts build() to return a balanced BST of its half.
        root->left = build(nums, l, mid - 1);     // smaller values
        root->right = build(nums, mid + 1, r);    // bigger values

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // The whole array: indexes 0 to n-1.
        // (nums has at least 1 value, so nums.size() - 1 cannot underflow.)
        return build(nums, 0, nums.size() - 1);
    }
};
