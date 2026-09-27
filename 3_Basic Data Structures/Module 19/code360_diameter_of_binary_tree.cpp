/*

https://www.naukri.com/code360/problems/diameter-of-the-binary-tree_920552

Diameter of a binary tree = the number of EDGES on the longest path between
any two nodes. The path may or may not pass through the root.

The idea: every path has a highest node where it "turns". A longest path
turning at node X goes down the tallest branch on X's left and the tallest
branch on X's right. If l and r are the heights (in nodes) of X's left and
right subtrees, that path has l + r edges (one edge per node on each side,
counting the edge from X down to it). So: compute every node's height with
the usual recursion, and on the way try l + r as a candidate answer.

Example:        1
               / \
              2   3
             / \
            4   5
  At node 2: l = 1, r = 1 -> 2.  At node 1: l = 2 (2 -> 4), r = 1 -> 3.
  Diameter = 3 (path 4 - 2 - 1 - 3).

Note: TreeNode<int> (with data/val, left, right) is defined by the judge's
hidden code, which also calls diameterOfBinaryTree. There is no main here.

*/

#include <bits/stdc++.h>
// <bits/stdc++.h>: GCC shortcut that includes the whole standard library (max, ...).
int mx; // Global variable to store the maximum diameter
        // (global = declared outside every function, so all functions share it)

// Returns the height of the subtree under root, counted in NODES
// (NULL -> 0, a leaf -> 1), and as a side effect updates mx with the
// longest path that turns at each node.
int max_height(TreeNode<int> *root) {
    if (root == NULL) {
        return 0; // Return 0 for NULL nodes
    }
    if(root->left == NULL && root->right == NULL) {
        return 1; // a leaf: height 1 (its l + r would be 0, so mx needs no update)
    }

    // The recursive calls trust max_height(child) to return the child's height.
    int l = max_height(root->left);  // Height of the left subtree
    int r = max_height(root->right); // Height of the right subtree
    int d = l + r; // Diameter of the current subtree
                   // (edges on the longest path that turns at this node)
    // Update the diameter at this node
    mx = max(mx, d);   // max(a, b) returns the larger value

    // Return the height of the current node
    return max(l, r) + 1;   // taller side + this node
}

// The function the judge calls. Returns the diameter in edges.
int diameterOfBinaryTree(TreeNode<int> *root) {
    mx = 0; // Initialize mx before computation
            // (important: the judge may call this for many test cases, and a
            // leftover mx from the previous tree would give a wrong answer)
    int h = max_height(root); // Compute the height and update the diameter
                              // (h itself is not needed; we only want mx)
    return mx; // Return the diameter
}
