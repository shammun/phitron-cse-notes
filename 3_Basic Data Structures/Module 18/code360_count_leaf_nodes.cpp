/*

https://www.naukri.com/code360/problems/count-leaf-nodes_893055

*/


/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
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
    
***********************************************************/

/*
 * Count the leaves: nodes that have no left child and no right child.
 *
 * The idea: a tree's leaf count is the leaf count of its left subtree plus the
 * leaf count of its right subtree. Recursion asks that same question of each
 * child until it reaches the two simple cases:
 *   - an empty tree (NULL) has 0 leaves;
 *   - a node with no children IS a leaf, so it counts as 1.
 *
 * Example: 1 with children 2 and 3, and 2 has a left child 4.
 *   leaves are 4 and 3, so the answer is 2.
 */
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    // An empty subtree has no leaves.
    if(root == NULL){
        return 0;
    }
    // Both children missing: this node is a leaf, count it once.
    if(root-> left == NULL && root->right == NULL){
        return 1;
    }
    // Otherwise the node is not a leaf itself; its leaves are all below it.
    int l = noOfLeafNodes(root->left);   // leaves on the left side
    int r = noOfLeafNodes(root->right);  // leaves on the right side
    return l + r;
}