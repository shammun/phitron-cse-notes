/*

https://www.naukri.com/code360/problems/node-level_920383

*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        bool isOriginal;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

/*
 * Node level: on which level is the node with this value? The root is on
 * level 1, its children on level 2, and so on. Return 0 if it is not found.
 *
 * The idea: a level-order walk (BFS) where every node travels in the queue
 * together with its level, as a pair {node, level}. A child is always one
 * level deeper than its parent, so we push {child, level + 1}. The moment the
 * wanted value comes out of the queue, its level is the answer.
 *
 * Example: tree 10 / 20 30 / 40 50 60, value 50 -> level 3.
 */
int nodeLevel(TreeNode<int>* root, int value)
{
    // Write your code here.
    // An empty tree cannot contain the value.
    if (root == NULL) {
        return 0;
    }

    // level+=1;

    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 1});     // the root sits on level 1

    while (!q.empty()) {
        pair<TreeNode <int>*,int> parent = q.front();
        q.pop();
        
        TreeNode<int>* node = parent.first;   // the node itself
        int level = parent.second;            // and the level it is on

        // Found the value: report its level straight away.
        if (node->val == value) {
            return level;
        }

        // Otherwise queue the children, one level deeper.
        if (node->left) {
            q.push({node->left, level + 1});
        }
        if (node->right) {
            q.push({node->right, level + 1});
        }
    }

    // The whole tree was searched without finding the value.
    return 0;
}