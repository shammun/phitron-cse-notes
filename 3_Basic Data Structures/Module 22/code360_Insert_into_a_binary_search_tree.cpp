/*

https://www.naukri.com/code360/problems/insert-into-a-binary-search-tree_1279913?leftPanelTabValue=PROBLEM

 Insert Into A Binary Search Tree

*/



/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left, *right;
        TreeNode() : val(0), left(NULL), right(NULL) {}
        TreeNode(T x) : val(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : val(x), left(left), right(right) {}
    };


    (TreeNode<int> holds an int in val. The part after ':' is an
    initializer list: val(x) sets val to x. The judge's hidden code defines
    this class and calls insertionInBST, so there is no main here.)

************************************************************/

/*
 * Task in short: insert val into a BST so that it is still a BST, and return
 * the root. Example: inserting 6 into the tree 8 (left 3, right 10) puts 6
 * as the right child of 3, because 6 < 8 and 6 > 3.
 *
 * Idea: a new value always ends up as a leaf. Walk down from the root the
 * same way a search would (smaller -> left, otherwise -> right) until an
 * empty spot (NULL) is reached, and put the new node there.
 */
// root = the (sub)tree to insert into, val = the new value.
// Returns the root of that (sub)tree after the insert.
// Base case: NULL. The recursive call trusts insertionInBST to return the
// updated root of the child's subtree.
TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
{
    // Empty spot found: the new node becomes the root of this (empty) subtree.
    if (root == NULL) {
        return new TreeNode<int>(val);   // `new` builds the node on the heap and returns its address
    }

    // Go to the side where val belongs. The call returns the (possibly new)
    // root of that subtree, and we store it back in the child pointer; that
    // is how the new leaf gets linked to its parent.
    if (val < root->val) {
        root->left = insertionInBST(root->left, val);
    } else {
        root->right = insertionInBST(root->right, val);
    }

    // The root of this subtree did not change, so return it as it is.
    return root;
}