/*

https://leetcode.com/problems/binary-tree-right-side-view/

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
#include <queue>
#include <utility>
#include <utility>

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        bool freq[105] = {false};
        queue<pair<TreeNode*, int>> q;
        if(root){
            q.push({root, 1});
        }

        while(!q.empty()){
            pair<TreeNode*, int> parent = q.front();
            q.pop();

            TreeNode* node = parent.first;
            int level = parent.second;

            if(freq[level] == false){
                ans.push_back(node->val);
                freq[level] = true;
            }

            if(node->right){
                q.push({node->right, level + 1});
            }
            if(node->left){
                q.push({node->left, level + 1});
            }
        }
        return ans;
    }
};