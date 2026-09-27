/*

https://www.naukri.com/code360/problems/code-find-a-node_5682?leftPanelTabValue=PROBLEM

Is the value x stored anywhere in the tree? Return true or false.
Example: tree 10 / 20 30 / 40 50, x = 50 -> true;  x = 7 -> false.

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

    (A template class: BinaryTreeNode<int> stores an int in `data`. The
    judge's hidden code defines it and calls isNodePresent, so there is no
    #include and no main in this file.)

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
// Returns true if x is in the (sub)tree under root.
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if (root == NULL) {
        return false;       // empty subtree: x cannot be here
    }

    if (root->data == x) {
        return true;        // found at this node
    }

    // The block below is version 1's ending, kept switched off for comparison.
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
   // Each call trusts isNodePresent(child, x) to answer for that whole subtree.
   bool left = isNodePresent(root->left, x);     // is x somewhere on the left?
   bool right = isNodePresent(root->right, x);   // is x somewhere on the right?
   return left || right;                         // || is "or": true if at least one is true

}
