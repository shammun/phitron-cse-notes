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
 */
class Solution {
public:
    bool isUnivalHelper(TreeNode* root, int value){
        if(root == NULL){
            return true;
        }

        if(root->val != value){
            return false;
        }

        return isUnivalHelper(root->left, value) && isUnivalHelper(root->right, value);
    }

    bool isUnivalTree(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        return isUnivalHelper(root, root->val);
    }
};