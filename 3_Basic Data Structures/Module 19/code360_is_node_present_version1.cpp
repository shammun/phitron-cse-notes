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

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if (root == NULL) {
        return false;
    }

    if (root->data == x) {
        return true;
    }

    bool left = isNodePresent(root->left, x);
    if (left) {
        return true;
    }
    bool right = isNodePresent(root->right, x);
    if (right) {
        return true;
    }
    
    return false;
    
}