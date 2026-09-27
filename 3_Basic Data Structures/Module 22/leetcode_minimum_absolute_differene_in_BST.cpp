/*

Minimum Absolute Difference in BST
https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/


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
 * Task in short: find the smallest difference between the values of any two
 * nodes of a BST. Example: the tree 4 (2 (1, 3), 6) gives 1.
 *
 * Idea: an in-order walk of a BST visits the values in sorted order, and in
 * a sorted list the closest pair is always two neighbours. So each node is
 * compared only with the node visited just before it (prev).
 * Sorted order here: 1 2 3 4 6 -> gaps 1 1 1 2 -> the smallest is 1.
 */
class Solution {
public:

    // Member variables, shared by all the recursive calls:
    TreeNode* prev = NULL;    // the node visited just before the current one
    int min_diff = INT_MAX;   // smallest gap found so far (starts "infinite")

    void inorderTraversal(TreeNode* node){
        if(!node){
            return;
        }

        // Left subtree first: the smaller values.
        inorderTraversal(node->left);

        // Compare with the previous value in sorted order. The very first
        // node has no previous one (prev is NULL), so it is skipped.
        if(prev){
            min_diff = min(min_diff, abs(node->val - prev->val));
        }

        // This node becomes "previous" for the next node visited.
        prev = node;

        // Right subtree last: the bigger values.
        inorderTraversal(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        return min_diff;
    }
};