/*

https://leetcode.com/problems/search-in-a-binary-search-tree/

Search in a Binary Search Tree

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree 
rooted with that node. If such a node does not exist, return null.

Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
- 1 <= Node.val <= 10^7
- root is a binary search tree.
- 1 <= val <= 10^7

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

    TreeNode* search(TreeNode* root, int val){
        if(root == NULL){
            return NULL;
        }
        if(root->val == val){
            return root;
        }

        if(val < root->val){
            return search(root->left, val);
        } else{
            return search(root->right, val);
        }
    }

    TreeNode* sub_tree(TreeNode* node){
        if(node == NULL){
            return NULL;
        }
        TreeNode* leftNode = sub_tree(node->left);
        TreeNode* rightNode = sub_tree(node->right);
        node->left = leftNode;
        node->right = rightNode;
        return node;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node_found = search(root, val);
        TreeNode* tree = sub_tree(node_found);
        return tree;
    }
};