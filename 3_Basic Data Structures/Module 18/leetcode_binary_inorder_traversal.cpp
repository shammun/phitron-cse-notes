/*

https://leetcode.com/problems/binary-tree-inorder-traversal/

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
 * Inorder traversal (Left, Root, Right), returned as a vector instead of printed.
 *
 * The idea: the same recursive function as Module 17, with `cout` replaced by
 * `result.push_back(...)`. The vector is passed by reference (&result) so every
 * recursive call adds to the SAME vector; passing it by value would give each
 * call its own copy and the answer would be lost.
 *
 * Example: root 1, right child 2, and 2 has a left child 3 (LeetCode's sample).
 *   preorder = [1, 2, 3], inorder = [1, 3, 2], postorder = [3, 2, 1].
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
        // Fill the vector with a helper, then hand it back.
        inorder(root, result);
        return result;
    }

public:
    void inorder(TreeNode* node, vector<int> &result){
        if(node == NULL){   // empty subtree: nothing to add
            return;
        }
        // The value is pushed between the two calls -- that is the only
        // difference between pre-, in- and post-order.
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }
};