/*

https://www.naukri.com/code360/problems/tree-height_4609628?leftPanelTabValue=PROBLEM

*/


/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

/*
 * Height = the number of nodes on the longest path from the root down to a leaf.
 * (A single node has height 1; an empty tree has height 0.)
 *
 * The idea: the longest path from a node goes down into whichever child is
 * taller, so height(node) = 1 + max(height(left), height(right)).
 * The "+ 1" counts the node itself.
 *
 * Example: 1 with children 2 and 3, and 2 has a left child 4.
 *   height(4) = 1, height(2) = 1 + max(1, 0) = 2, height(3) = 1,
 *   height(1) = 1 + max(2, 1) = 3.
 */
int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    // An empty tree adds no levels.
    if(root == NULL){
        return 0;
    }
    // is it a leaf node?
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    // (This leaf check is not strictly needed: the formula below would also
    // give max(0, 0) + 1 = 1 for a leaf. It just stops one call earlier.)

    int l = heightOfBinaryTree(root->left);   // height of the left subtree
    int r = heightOfBinaryTree(root->right);  // height of the right subtree
    return max(l, r) + 1;                     // the taller side, plus this node
}
