/*

https://leetcode.com/problems/maximum-depth-of-binary-tree/

Maximum Depth of Binary Tree

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
 * (LeetCode defines this struct and calls our function from its own hidden
 * main, so there are no #includes or main here. After ':' comes an
 * initializer list: val(x) sets val to x; nullptr is the C++11 null pointer.)
 */
/*
 * Task in short: count the nodes on the longest path from the root down to
 * a leaf. Example: 3 (9, 20 (15, 7)) has depth 3 (3 -> 20 -> 15).
 *
 * Idea: the same recursion as get_max_height.cpp in Module 18. A tree is as
 * deep as its deeper subtree, plus 1 for the root itself.
 */
class Solution {
public:   // LeetCode calls maxDepth from outside the class
    int maxDepth(TreeNode* root) {
        // An empty tree has no nodes, so its depth is 0.
        if(root == NULL){
            return 0;
        }

        // Depth of each subtree...
        // The recursive calls trust maxDepth to return each subtree's depth.
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        // ...keep the deeper one and count this node on top of it.
        return max(l, r) + 1;       // max(a, b) = the larger of the two
    }
};