/*

https://leetcode.com/problems/univalued-binary-tree/

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
 * (LeetCode defines this struct and calls isUnivalTree from its own hidden
 * main, so there are no #includes or main here.)
 */
/*
 * Univalued binary tree: true if every node in the tree holds the same value.
 *
 * The idea: remember the root's value, then ask "does every node equal this
 * value?" recursively. A node passes if it holds the value AND its left
 * subtree passes AND its right subtree passes (combine with &&).
 *
 * Example: [1, 1, 1, 1, 1, null, 1] -> true;  [2, 2, 2, 5, 2] -> false.
 */
class Solution {
public:   // LeetCode calls isUnivalTree from outside the class
    // True if every node in the subtree under root equals `value`.
    // Base case: NULL. The recursive calls trust the helper to check whole subtrees.
    bool isUnivalHelper(TreeNode* root, int value){
        if(root == NULL){           // an empty subtree has no wrong values
            return true;
        }

        // One different value is enough to fail.
        if(root->val != value){
            return false;
        }

        // This node matches; now both sides must match too.
        // && skips the right side if the left side already failed.
        return isUnivalHelper(root->left, value) && isUnivalHelper(root->right, value);
    }

    bool isUnivalTree(TreeNode* root) {
        if(root == NULL){           // an empty tree counts as univalued
            return true;
        }

        // Every node is compared with the root's value.
        return isUnivalHelper(root, root->val);
    }
};
