/*

https://www.naukri.com/code360/problems/code-find-a-node_5682?leftPanelTabValue=PROBLEM

*/


/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

/*
 * Is the value x stored anywhere in the tree?
 *
 * The idea ("ask both children"): x is in the tree if the root holds x, OR x
 * is in the left subtree, OR x is in the right subtree. The same question is
 * asked of each subtree until we reach an empty one (NULL), which holds nothing.
 *
 * Example: tree 10 / 20 30 / 40 50, x = 50 -> true;  x = 7 -> false.
 */
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    // Empty subtree: x cannot be here.
    if (root == NULL) {
        return false;
    }

    // Found it at this node, no need to look further.
    if (root->data == x) {
        return true;
    }

    // Search the left side first; if it is there, stop right away
    // (the right side is never searched).
    bool left = isNodePresent(root->left, x);
    if (left) {
        return true;
    }
    // Not on the left, so the right side decides.
    bool right = isNodePresent(root->right, x);
    if (right) {
        return true;
    }
    
    return false;
    
}