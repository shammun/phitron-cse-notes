/*

https://www.naukri.com/code360/problems/left-view-of-a-binary-tree_920519?leftPanelTabValue=PROBLEM

Left View Of a Binary Tree (Code360)
Stand on the left side of the tree and look at it: on every level you can only
see the first (leftmost) node. Return those nodes, from the top level down.

Example: the tree [1, 2, 3, null, 5, null, 4]
            1
          /   \
         2     3
          \     \
           5     4
    left view  = [1, 2, 5]
    (right view would be [1, 3, 4])

*/


/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

    (TreeNode<int> stores an int in `data`. The judge's hidden code defines
    it and calls getLeftView - there is no main in this file.)

************************************************************/

/*
 * The idea: a level-order walk (BFS) where every node travels together with
 * its level number, as a pair {node, level}. Because children are pushed
 * LEFT FIRST, the first node that comes out of the queue on each level is the
 * leftmost one on that level, which is exactly what the left view shows.
 *
 * To know whether a level has already given its answer we compare the level
 * with ans.size(): the queue hands out levels in order 1, 2, 3, ..., so when a
 * node on level L comes out and ans has fewer than L values, this node is the
 * first one seen on level L.
 *
 * Trace for the example: out 1 (L1, ans size 0 < 1 -> take 1), out 2 (L2,
 * size 1 < 2 -> take 2), out 3 (L2, size 2, skip), out 5 (L3, size 2 < 3 ->
 * take 5), out 4 (L3, skip). ans = [1, 2, 5].
 *
 * (Earlier this file held a copy of the LeetCode right-side-view code, which
 * pushes the right child first and so answers the wrong question.)
 */

#include <bits/stdc++.h>
// <bits/stdc++.h>: GCC shortcut that includes the whole standard library
// (vector, queue, pair, ...).

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;                        // one value per level, top to bottom

    // Each queue entry is a node plus the level it sits on (root = level 1).
    // pair<A, B> glues two values together: .first is the node, .second the level.
    queue<pair<TreeNode<int>*, int>> q;
    if(root){                               // an empty tree has an empty view
        q.push({root, 1});                  // {a, b} builds the pair in place
    }

    // One pass handles one node; stops when no node is waiting.
    while(!q.empty()){
        pair<TreeNode<int>*, int> parent = q.front();   // oldest waiting entry
        q.pop();

        TreeNode<int>* node = parent.first;   // the node
        int level = parent.second;            // its level

        // First node out of the queue on this level? Then it is the leftmost.
        // (int) turns ans.size(), which is unsigned, into a normal int so the
        // comparison with `level` is between two ints.
        if((int)ans.size() < level){
            ans.push_back(node->data);        // push_back adds at the end of the vector
        }

        // Left child first, so on the next level the leftmost node leaves the
        // queue before its neighbours. Both children are one level deeper.
        if(node->left){
            q.push({node->left, level + 1});
        }
        if(node->right){
            q.push({node->right, level + 1});
        }
    }
    return ans;                             // the left view, top level first
}
