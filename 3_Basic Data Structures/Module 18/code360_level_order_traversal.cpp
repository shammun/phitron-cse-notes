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
/*
 * Level-order traversal: list the values level by level, top to bottom and
 * left to right inside each level, returned in a vector.
 *
 * The idea is the module's queue walk. A queue serves the oldest waiting node
 * first, so the root comes out, then its two children (which were pushed next),
 * then the grandchildren, and so on: exactly the level order.
 *
 * Example: 1 with children 2 and 3, 2 has children 4 and 5.
 *   the queue hands out 1, 2, 3, 4, 5, so the answer is [1, 2, 3, 4, 5].
 */
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> result;          // the values in the order we visit them
    if (root == NULL) {          // empty tree: return an empty vector
        return result;
    }

    // Start the queue with the root, the only node on level 0.
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        // Take the oldest waiting node and record its value.
        BinaryTreeNode<int> *current = q.front();
        q.pop();

        result.push_back(current->val);

        // Queue its children, left before right, so they come out in that
        // order after everything already waiting on the level above.
        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }

    return result;
}