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

/*
 * Right side view: standing on the right of the tree, you see only the last
 * (rightmost) node of every level. Return them from top to bottom.
 *
 * The idea: level-order walk (BFS) with {node, level} pairs, pushing the RIGHT
 * child before the left one. Then the first node popped on each level is the
 * rightmost one. A bool array freq[level] remembers which levels already gave
 * their answer. (LeetCode allows at most 100 nodes, so at most 100 levels and
 * an array of 105 is big enough.)
 *
 * Example: [1, 2, 3, null, 5, null, 4]  ->  [1, 3, 4]
 * code360_left_view_of_a_binary_tree.cpp does the same walk with the left
 * child pushed first.
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;                 // one value per level
        bool freq[105] = {false};        // freq[L] = true once level L is answered
        queue<pair<TreeNode*, int>> q;   // {node, level it sits on}
        if(root){
            q.push({root, 1});           // the root is level 1
        }

        while(!q.empty()){
            pair<TreeNode*, int> parent = q.front();
            q.pop();

            TreeNode* node = parent.first;
            int level = parent.second;

            // First node out on this level = the rightmost one (see below).
            if(freq[level] == false){
                ans.push_back(node->val);
                freq[level] = true;
            }

            // Right child first, so it leaves the queue before its left sibling.
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