/*

https://leetcode.com/problems/range-sum-of-bst/description/

Range sum of BST

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

Example 1
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

Example 2
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.



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
 * Idea: use the BST rule to skip whole branches.
 * - Node below the range (val < low): its left subtree is even smaller, so
 *   only the right subtree can hold values in range.
 * - Node above the range (val > high): only the left subtree can.
 * - Otherwise the node is in range: count it and look at both sides.
 */
class Solution {
public:   // LeetCode calls rangeSumBST from outside the class
    // Base case: NULL. Each recursive call trusts rangeSumBST to return the
    // in-range sum of that whole subtree.
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Empty subtree adds nothing.
        if(root == NULL){
            return 0;
        }

        // Node too small: skip it and its left side, go right.
        if(low > root->val){
            return rangeSumBST(root->right, low, high);
        }

        // Node too big: skip it and its right side, go left.
        if(high < root->val){
            return rangeSumBST(root->left, low, high);
        }

        // low <= val <= high: this value counts, plus whatever is in range
        // on both sides.
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};