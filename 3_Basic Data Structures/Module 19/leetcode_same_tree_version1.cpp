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

class Solution {
public:
    void inorder(TreeNode* node, vector<int> & result){
        if(node == NULL){
            result.push_back(-1001);
            return;
        }
        result.push_back(node->val);
        inorder(node->left, result);
        inorder(node->right, result);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> result1;
        vector<int> result2;

        inorder(p, result1);
        inorder(q, result2);

        return result1 == result2;
    }
};