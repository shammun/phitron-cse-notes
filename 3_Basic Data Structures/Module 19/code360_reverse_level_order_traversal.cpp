/*

https://www.naukri.com/code360/problems/reverse-level-order-traversal_764339?leftPanelTabValue=SUBMISSION

*/

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

    (TreeNode<int> stores an int in `val`. The judge's hidden code defines
    it and calls reverseLevelOrder - there is no main in this file.)

************************************************************/
#include <bits/stdc++.h>
// <bits/stdc++.h>: GCC shortcut that includes the whole standard library
// (vector, queue, reverse, ...).
/*
 * Reverse level order: list the values level by level, but starting from the
 * BOTTOM level and ending with the root.
 *
 * The idea: do the normal level-order walk with a queue (Module 18), collect
 * the values in a vector, and at the end reverse the whole vector.
 *
 * Example: tree 1 / 2 3 / 4 5 (4 and 5 under 2)
 *   level order         = 1 2 3 4 5
 *   reversed            = 5 4 3 2 1
 * (Each level also reads right to left, because the whole list is reversed.)
 */
vector<int> reverseLevelOrder(TreeNode<int> *root){
    // Write your code here.
    vector<int> v;               // values in normal level order
    queue<TreeNode<int>*> q;     // nodes waiting to be visited
    if (root) {                  // a pointer is "true" when it is not NULL
        q.push(root);
    }

    // One pass visits one node; stops when no node is waiting.
    while (!q.empty()) {
        // Visit the oldest waiting node and record its value.
        TreeNode<int>* f = q.front();
        q.pop();
        v.push_back(f->val);     // push_back adds at the end of the vector

        // Its children wait behind everything already in the queue.
        if (f->left) {
            q.push(f->left);
        }
        if (f->right) {
            q.push(f->right);
        }
    }
    // Flip the list: the last level visited now comes first.
    // reverse(first, last) reverses the range; v.begin()/v.end() cover the whole vector.
    reverse(v.begin(), v.end());
    return v;
}
