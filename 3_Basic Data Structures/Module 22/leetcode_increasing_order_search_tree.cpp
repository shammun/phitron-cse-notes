/*

https://leetcode.com/problems/increasing-order-search-tree/

Increasing Order Search Tree

Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

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
 * Task in short: rearrange the BST into a chain where no node has a left
 * child and each right child is the next bigger value, smallest first.
 *
 * Idea: an in-order walk (left, node, right) of a BST visits the values in
 * increasing order. So we walk in-order and, as each node is visited, hang
 * it on the right of the node visited just before it.
 *
 * `start` is a dummy node in front of the chain, so the very first node
 * needs no special case. `current` is the last node of the chain so far.
 */
class Solution {
private:
    // current is passed by reference (&), so every call moves the SAME
    // "end of chain" pointer forward.
    void inorder(TreeNode* node, TreeNode* &current) {
        if (!node){
            return;
        }

        // 1. All smaller values first.
        inorder(node->left, current);

        // 2. Visit this node: cut its left link, attach it after the
        //    current end of the chain, and make it the new end.
        node->left = NULL;
        current->right = node;
        current = node;

        // 3. Then all bigger values.
        inorder(node->right, current);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        // Dummy head; its value (999) is never used.
        TreeNode* start = new TreeNode(999);
        TreeNode* current = start;

        inorder(root, current);

        // The real chain starts right after the dummy.
        return start->right;
    }
};