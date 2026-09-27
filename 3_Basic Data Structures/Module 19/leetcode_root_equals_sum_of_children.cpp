/*

https://leetcode.com/problems/root-equals-sum-of-children/

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
/*
 * Root equals sum of children: the tree always has exactly 3 nodes, a root
 * with a left and a right child. Return true if root = left + right.
 *
 * The idea: no loop or recursion needed. Both children are guaranteed to
 * exist, so we can read root->left->val and root->right->val directly.
 *
 * Example: [10, 4, 6] -> 4 + 6 = 10 -> true;  [5, 3, 1] -> 3 + 1 = 4 -> false.
 */
class Solution {
public:
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};