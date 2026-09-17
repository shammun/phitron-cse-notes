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
class Solution {
public:

    TreeNode* prev = NULL;
    int min_diff = INT_MAX;

    void inorderTraversal(TreeNode* node){
        if(!node){
            return;
        }

        inorderTraversal(node->left);

        if(prev){
            min_diff = min(min_diff, abs(node->val - prev->val));
        }

        prev = node;

        inorderTraversal(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        return min_diff;
    }
};