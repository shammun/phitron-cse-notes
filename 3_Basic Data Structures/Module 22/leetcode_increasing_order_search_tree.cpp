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
class Solution {
private:
    void inorder(TreeNode* node, TreeNode* &current) {
        if (!node){
            return;
        }

        inorder(node->left, current);

        node->left = NULL;
        current->right = node;
        current = node;    

        inorder(node->right, current);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* start = new TreeNode(999);
        TreeNode* current = start;
        
        inorder(root, current);
        
        return start->right;
    }
};