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
 *
 * (LeetCode defines this struct and calls isSameTree from its own hidden
 * main.)
 */

#include <iostream>     // cin/cout (not really needed on LeetCode)
#include <vector>       // vector

/*
 * Same tree, version 1: turn each tree into a list and compare the lists.
 *
 * The idea: walk each tree in PRE-order (node, left, right; the helper is
 * named `inorder` but it pushes the node before its children) and write every
 * value into a vector. Every missing child (NULL) is written as the marker
 * -1001, so the SHAPE is recorded too, not just the values.
 * Two trees are the same exactly when their two vectors are equal.
 *
 * BUG (rare edge case): a marker must be a value no real node can hold, but
 * LeetCode allows node values from -10^4 to 10^4, and -1001 is inside that
 * range. So p = [5, -1001] (a real -1001 on the left) and q = [5, null, -1001]
 * (-1001 on the right) both become 5 -1001 -1001 -1001 -1001 and the function
 * wrongly says "same". Fix: use a marker outside the range, e.g. -10001 or
 * INT_MIN. (Version 2 compares node by node and has no such problem.)
 *
 * Why the marker matters: [1, 2] (2 on the left) and [1, null, 2] (2 on the
 * right) both give "1 2" without markers, but with markers they give
 * 1 2 X X X  versus  1 X 2 X X  (X = -1001), which differ.
 */
class Solution {
public:   // LeetCode calls isSameTree from outside the class
    // Writes the subtree under node into result in pre-order, with -1001 for
    // every empty spot. result is a reference (&): all calls fill the SAME vector.
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
        vector<int> result1;        // list for tree p
        vector<int> result2;        // list for tree q

        inorder(p, result1);
        inorder(q, result2);

        // Same values in the same places, including the empty places.
        // == on vectors compares the sizes and every element in order.
        return result1 == result2;
    }
};
