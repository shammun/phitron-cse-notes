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
/*
 * Idea: the BST search from BST_search.cpp, but returning the node itself.
 *
 * In a BST every value on the left of a node is smaller and every value on
 * the right is bigger. So at each node we compare val with node->val and
 * walk into only one side, throwing the other half away.
 *
 * The node we find already "is" the answer: its left and right pointers
 * still lead to all of its children, so returning that pointer returns the
 * whole subtree under it.
 */
class Solution {
public:

    // Walks down the BST and returns the node holding val, or NULL.
    TreeNode* search(TreeNode* root, int val){
        // Fell off the tree: val is not in it.
        if(root == NULL){
            return NULL;
        }
        // Found it: return this node (its subtree comes with it).
        if(root->val == val){
            return root;
        }

        // Smaller values can only be on the left, bigger ones on the right,
        // so only one recursive call is made per level.
        if(val < root->val){
            return search(root->left, val);
        } else{
            return search(root->right, val);
        }
    }

    // Visits every node under `node` and re-links its children to it.
    // The links are already there, so this changes nothing: it just
    // returns the same subtree. It is kept to show that the found node's
    // subtree is complete; searchBST would work with `return node_found;`.
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
        // Step 1: find the node whose value is val (NULL if absent).
        TreeNode* node_found = search(root, val);
        // Step 2: return the subtree rooted at that node.
        TreeNode* tree = sub_tree(node_found);
        return tree;
    }
};