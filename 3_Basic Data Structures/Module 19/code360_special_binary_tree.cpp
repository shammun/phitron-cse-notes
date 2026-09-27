/*

https://www.naukri.com/code360/problems/special-binary-tree_920502?leftPanelTabValue=SUBMISSION

*/

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

/*
 * Special binary tree: every node has either 0 children or 2 children, never
 * exactly one. (This is also called a "full" binary tree.)
 *
 * The idea ("ask both children, combine with &&"): the tree is special if
 * this node is fine AND the left subtree is special AND the right subtree is
 * special. A node is not fine when exactly one of its children is NULL.
 *
 * Example: 1 / 2 3 / 4 5 (under 2)          -> true
 *          1 / 2 3 / 4 (only 4 under 2)     -> false, 2 has one child.
 */
bool isSpecialBinaryTree(BinaryTreeNode<int>* root)
{
    // Write your code here.
    // An empty subtree breaks no rule.
    if (root == NULL) {
        return true;
    }
    // Only a right child: exactly one child, so the tree is not special.
    if (root->left == NULL && root->right != NULL) {
        return false;
    }
    // Only a left child: also exactly one child.
    if (root->left != NULL && root->right == NULL) {
        return false;
    }
    // This node is fine (0 or 2 children); now every node below must be too.
    bool l = isSpecialBinaryTree(root->left);
    bool r = isSpecialBinaryTree(root->right);
    
    return l && r;
}