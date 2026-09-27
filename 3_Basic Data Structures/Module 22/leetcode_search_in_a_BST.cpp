/*

https://leetcode.com/problems/search-in-a-binary-search-tree/

Search in a Binary Search Tree (LeetCode 700)
You get the root of a binary search tree and a number `val`. Find the node
whose value is `val` and return it (the subtree hanging from it comes along).
If no node holds `val`, return NULL (an empty tree).

Input (LeetCode): the tree in level order, and val.
Output: the subtree rooted at the found node, in level order.

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
 *
 * (LeetCode defines TreeNode and calls our function from its own hidden
 * main, so there are no #includes or main here. After ':' comes an
 * initializer list: val(x) sets val to x; nullptr is the C++11 null pointer.)
 */

/*
 * Idea: the BST rule tells us which way to go at every node, so we never
 * need to look at both sides.
 *   - val is smaller than the node -> it can only be in the left subtree;
 *   - val is bigger                -> it can only be in the right subtree;
 *   - equal                        -> found it.
 *
 * Module 21 wrote this search with recursion. Because we only ever go down
 * ONE side, a plain loop works just as well: keep a pointer `cur` and move
 * it left or right until it lands on `val` or falls off the tree (NULL).
 * No recursion means no call stack, so the extra space is O(1).
 */
class Solution {
public:   // LeetCode calls searchBST from outside the class
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* cur = root;       // start at the top of the tree

        // Stop when we fall off the tree or find the value.
        // (cur != NULL is checked first: && stops early, so cur->val is never read on NULL.)
        while(cur != NULL && cur->val != val){
            if(val < cur->val){
                cur = cur->left;    // everything smaller lives on the left
            }
            else{
                cur = cur->right;   // everything bigger lives on the right
            }
        }

        // Either the node holding val, or NULL when it is not in the tree.
        return cur;
    }
};
