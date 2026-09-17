/*

https://www.naukri.com/code360/problems/diameter-of-the-binary-tree_920552

*/

#include <bits/stdc++.h> 
int mx; // Global variable to store the maximum diameter

int max_height(TreeNode<int> *root) {
    if (root == NULL) {
        return 0; // Return 0 for NULL nodes
    }
    if(root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    int l = max_height(root->left);  // Height of the left subtree
    int r = max_height(root->right); // Height of the right subtree
    int d = l + r; // Diameter of the current subtree
    // Update the diameter at this node
    mx = max(mx, d);
    
    // Return the height of the current node
    return max(l, r) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root) {
    mx = 0; // Initialize mx before computation
    int h = max_height(root); // Compute the height and update the diameter
    return mx; // Return the diameter
}
