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
 *
 * (LeetCode defines this struct for us. The part after ':' is an
 * initializer list: val(x) sets val to x, left(nullptr) sets left to
 * nullptr, the C++11 name for a null pointer. LeetCode's hidden code also
 * includes the headers and calls our function, so there is no main here.)
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
public:   // LeetCode calls inorderTraversal from outside the class
    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;             // starts empty; the helper fills it
        // Fill the vector with a helper, then hand it back.
        inorder(root, result);
        return result;
    }

public:   // a second `public:` label is allowed; it changes nothing
    // Adds the values of the subtree under `node` to result, in-order.
    // Base case: NULL. Each call trusts inorder(child, result) to add that
    // child's whole subtree in the right order.
    void inorder(TreeNode* node, vector<int> &result){
        if(node == NULL){   // empty subtree: nothing to add
            return;
        }
        // The value is pushed between the two calls -- that is the only
        // difference between pre-, in- and post-order.
        inorder(node->left, result);        // everything on the left first
        result.push_back(node->val);        // then this node (push_back adds at the end)
        inorder(node->right, result);       // then everything on the right
    }
};
