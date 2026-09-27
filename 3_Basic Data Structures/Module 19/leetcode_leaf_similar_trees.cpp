/*

https://leetcode.com/problems/leaf-similar-trees/

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
 * Leaf-similar trees: read the leaves of each tree from left to right. If the
 * two sequences are exactly the same, the trees are leaf-similar.
 *
 * The idea: a recursive DFS that visits the left subtree before the right one
 * and collects only leaves (nodes with no children) into a vector. Build the
 * vector for both trees and compare the two vectors with ==.
 *
 * Example: [1,2,3] has leaves 2 3 and [1,3,2] has leaves 3 2 -> false.
 *          Two trees of different shapes whose leaves both read 6 7 4 9 8 -> true.
 */
class Solution {
public:

    void leafSequence(TreeNode* root, vector<int>& leaves){
        if(root == NULL){       // empty subtree: no leaves here
            return;
        }

        // A leaf: record it. It has no children, so we can stop here.
        if(root->left == NULL && root->right == NULL){
            leaves.push_back(root->val);
            return;
        }

        // Left side first, so the leaves are collected from left to right.
        // `leaves` is a reference, so every call adds to the same vector.
        leafSequence(root->left, leaves);
        leafSequence(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;

        leafSequence(root1, leaves1);
        leafSequence(root2, leaves2);

        // == on vectors compares size and every element in order.
        return leaves1 == leaves2;
    }
};