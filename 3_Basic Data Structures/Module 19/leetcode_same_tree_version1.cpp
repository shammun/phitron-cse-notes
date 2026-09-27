/*

https://leetcode.com/problems/same-tree/

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

#include <iostream>
#include <vector>

/*
 * Same tree, version 1: turn each tree into a list and compare the lists.
 *
 * The idea: walk each tree in PRE-order (node, left, right; the helper is
 * named `inorder` but it pushes the node before its children) and write every
 * value into a vector. Every missing child (NULL) is written as the marker
 * -1001, so the SHAPE is recorded too, not just the values.
 * Two trees are the same exactly when their two vectors are equal.
 *
 * Why the marker matters: [1, 2] (2 on the left) and [1, null, 2] (2 on the
 * right) both give "1 2" without markers, but with markers they give
 * 1 2 X X X  versus  1 X 2 X X  (X = -1001), which differ.
 */
class Solution {
public:
    void inorder(TreeNode* node, vector<int> & result){
        if(node == NULL){
            result.push_back(-1001);   // marker for "no node here"
            return;
        }
        // Node first, then its left side, then its right side (pre-order).
        result.push_back(node->val);
        inorder(node->left, result);
        inorder(node->right, result);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> result1;
        vector<int> result2;

        inorder(p, result1);
        inorder(q, result2);

        // Same values in the same places, including the empty places.
        return result1 == result2;
    }
};