/*

https://leetcode.com/problems/binary-tree-inorder-traversal/

Binary Tree Inorder Traversal (LeetCode 94)
Given the root of a binary tree, return the values of its nodes in
in-order: first everything in the left subtree, then the node itself, then
everything in the right subtree.

Input (LeetCode): the tree in level order (null = no child).
Output: the list of values in in-order.

Example
root = [1,null,2,3]   ->   [1,3,2]
      1
       \
        2
       /
      3
root = []             ->   []

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
 * Idea: the in-order recursion from Module 17 (left, root, right). The only
 * change is that LeetCode wants the values in a vector instead of printed.
 *
 * `inorderTraversal` must RETURN the vector, so it cannot call itself and
 * keep adding to one list. A helper `inorder(node, ans)` does the recursion
 * and writes into `ans`, which is passed by reference (&) so every call adds
 * to the same vector instead of to its own copy.
 *
 * Why this is useful again in Module 23: in a BST, in-order visits the
 * values from smallest to biggest.
 */
class Solution {
public:
    void inorder(TreeNode* node, vector<int> &ans) {
        if (node == NULL) {
            return;                    // empty subtree: nothing to add
        }
        inorder(node->left, ans);      // 1. the whole left subtree first
        ans.push_back(node->val);      // 2. then this node
        inorder(node->right, ans);     // 3. then the whole right subtree
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);            // fills ans
        return ans;
    }
};
