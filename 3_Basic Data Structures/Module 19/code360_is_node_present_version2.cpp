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
 * Same problem as version 1, with a shorter ending: instead of three if
 * statements, both answers are combined with ||.
 *
 * Difference to notice: here BOTH sides are always searched, even when the
 * left side already found x, because both calls run before the ||.
 * Writing `return isNodePresent(root->left, x) || isNodePresent(root->right, x);`
 * would stop early, like version 1.
 */
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if (root == NULL) {
        return false;
    }

    if (root->data == x) {
        return true;
    }

    /*
    bool left = isNodePresent(root->left, x);
    if (left) {
        return true;
    }
    bool right = isNodePresent(root->right, x);
    if (right) {
        return true;
    }
    
    return false;
    */
   // x is present if either side has it.
   bool left = isNodePresent(root->left, x);
   bool right = isNodePresent(root->right, x);
   return left || right;
    
}