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
 *
 * (LeetCode defines this struct and calls rightSideView from its own hidden
 * main. After ':' comes an initializer list: val(x) sets val to x, and
 * nullptr is the C++11 name for a null pointer.)
 */

#include <iostream>     // cin/cout (not really needed on LeetCode)
#include <queue>        // queue
#include <utility>      // pair
#include <utility>      // (included twice by accident; harmless, the header guards itself)

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
public:   // LeetCode calls rightSideView from outside the class
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;                 // one value per level
        bool freq[105] = {false};        // freq[L] = true once level L is answered
                                         // (= {false} sets EVERY element to false)
        queue<pair<TreeNode*, int>> q;   // {node, level it sits on}; .first = node, .second = level
        if(root){                        // a pointer is "true" when it is not NULL
            q.push({root, 1});           // the root is level 1
        }

        // One pass handles one node; stops when no node is waiting.
        while(!q.empty()){
            pair<TreeNode*, int> parent = q.front();   // oldest waiting entry
            q.pop();

            TreeNode* node = parent.first;   // the node
            int level = parent.second;       // its level

            // First node out on this level = the rightmost one (see below).
            if(freq[level] == false){
                ans.push_back(node->val);    // push_back adds at the end of the vector
                freq[level] = true;          // this level is done
            }

            // Right child first, so it leaves the queue before its left sibling.
            if(node->right){
                q.push({node->right, level + 1});
            }
            if(node->left){
                q.push({node->left, level + 1});
            }
        }
        return ans;                          // the right view, top level first
    }
};
