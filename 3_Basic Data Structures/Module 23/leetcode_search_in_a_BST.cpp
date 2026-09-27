/*

https://leetcode.com/problems/search-in-a-binary-search-tree/

Search in a Binary Search Tree (LeetCode 700)
You get the root of a binary search tree and a number `val`. Return the node
that holds `val` (with everything below it), or NULL if `val` is not in the
tree.

Input (LeetCode): the tree in level order, and val.
Output: the subtree rooted at the found node, in level order ([] if none).

Example
root = [4,2,7,1,3], val = 2   ->   [2,1,3]
root = [4,2,7,1,3], val = 5   ->   []

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
 * Idea: the BST search from Module 21, written with recursion.
 *
 * Each node splits the problem in two, and the BST rule says which half can
 * hold `val`:
 *   - empty tree          -> val is not here, return NULL;
 *   - node holds val      -> this node is the answer;
 *   - val < node's value  -> only the left subtree can hold it;
 *   - val > node's value  -> only the right subtree can hold it.
 * The answer of that one subtree is the answer of the whole tree, so it is
 * returned straight up.
 *
 * With [4,2,7,1,3] and val = 2: 2 < 4, go left; the left child is 2 -> done.
 * With val = 5: 5 > 4, go right to 7; 5 < 7, go left; 7 has no left child
 * -> NULL.
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;                          // fell off the tree
        }
        if (root->val == val) {
            return root;                          // found it
        }
        if (val < root->val) {
            return searchBST(root->left, val);    // smaller values: left
        }
        return searchBST(root->right, val);       // bigger values: right
    }
};
