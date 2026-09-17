/*

https://www.naukri.com/code360/problems/level-order-traversal_796002?leftPanelTabValue=SUBMISSION

*/


#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> result;
    if (root == NULL) {
        return result;
    }

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode<int> *current = q.front();
        q.pop();

        result.push_back(current->val);

        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }

    return result;
}