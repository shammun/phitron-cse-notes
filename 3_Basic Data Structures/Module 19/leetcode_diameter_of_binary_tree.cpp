/*

https://leetcode.com/problems/diameter-of-binary-tree/

Diameter of a binary tree = the number of EDGES on the longest path between
any two nodes. The path may or may not pass through the root.

The idea: every path has a highest node where it "turns". The longest path
turning at node X goes down the tallest branch on each side of X. If l and r
are the heights (counted in nodes) of X's left and right subtrees, that path
has l + r edges. So compute every node's height recursively, and on the way
keep the largest l + r seen in mx.

Example: [1, 2, 3, 4, 5]
                1
               / \
              2   3
             / \
            4   5
  At node 2: l = 1, r = 1 -> 2.  At node 1: l = 2, r = 1 -> 3.  Answer 3.

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 *
 * (LeetCode defines this struct and calls diameterOfBinaryTree from its own
 * hidden main, so there are no #includes or main here.)
 */
class Solution {
public:   // LeetCode calls these from outside the class

    int mx; // Member variable (not a true global): stores the maximum diameter.
            // Every function of this Solution object can read and change it.

// Returns the height of the subtree under root, counted in NODES
// (NULL -> 0, leaf -> 1), and updates mx with the longest path turning here.
int max_height(TreeNode *root) {
        if (root == NULL) {
            return 0; // Return 0 for NULL nodes
        }
        if(root->left == NULL && root->right == NULL) {
            return 1; // a leaf: height 1 (its l + r would be 0 anyway)
        }

        // The recursive calls trust max_height(child) to return that child's height.
        int l = max_height(root->left);  // Height of the left subtree
        int r = max_height(root->right); // Height of the right subtree
        int d = l + r; // Diameter of the current subtree
                       // (edges on the longest path that turns at this node)
        // Update the diameter at this node
        mx = max(mx, d);   // max(a, b) returns the larger value

        // Return the height of the current node
        return max(l, r) + 1;   // taller side + this node
    }

    int diameterOfBinaryTree(TreeNode* root) {
        mx = 0; // Initialize mx before computation (a member int starts with garbage otherwise)
        int h = max_height(root); // Compute the height and update the diameter
                                  // (h is not needed; we only want mx)
        return mx; // Return the diameter
    }
};
