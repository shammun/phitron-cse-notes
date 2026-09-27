/*

In-order traversal

Left -> Root -> Right

Visit every node of a binary tree: first the whole left subtree, then the
node itself, then the whole right subtree. The same tree as binary_tree.cpp:

            10
           /  \
         20    30
         /     / \
       40    50   60

  Pre-order (Root, Left, Right): 10 20 40 30 50 60
  In-order  (Left, Root, Right): 40 20 10 50 30 60

*/

#include <iostream>     // cout, endl
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // not used here
#include <stack>        // not used here

using namespace std;    // write cout instead of std::cout

// One node of the binary tree.
class Node {
    public:
        int val;     // Value stored in the node (data).
        Node* left;  // Pointer to the left node in the binary tree.
        Node* right; // Pointer to the right node in the binary tree.

        // Constructor for the Node class: stores 'val' and sets 'left' and 'right' to NULL.
    Node(int val) {
        this->val = val;  // Assign the provided value to the 'val' member.
        this->left = NULL; // Initialize 'left' to NULL, meaning no left node by default.
        this->right = NULL; // Initialize 'right' to NULL, meaning no right node by default.
    }
};

// Pre-order: Root -> Left -> Right.
// Base case: NULL (empty subtree) prints nothing. The recursive calls trust
// that preorder(child) prints the child's whole subtree.
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";   // the node first
    preorder(root->left);       // then its left subtree
    preorder(root->right);      // then its right subtree
}

// In-order: Left -> Root -> Right.
// Same base case. At node 10: inorder(20) prints "40 20", then 10 is
// printed, then inorder(30) prints "50 30 60".
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);        // everything on the left first
    cout << root->val << " ";   // then the node
    inorder(root->right);       // then everything on the right
}

int main(){
    // Build the nodes on the heap (`new` returns each node's address).
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    // Link them into the tree drawn above (-> reaches a member through a pointer).
    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    // Print each node by following pointers from the root.
    cout << "The value of root is: " << root->val << endl;               // 10
    cout << "The value of a is: " << root->left->val << endl;            // 20
    cout << "The value of b is: " << root->right->val << endl;           // 30
    cout << "The value of c is: " << root->left->left->val << endl;      // 40
    cout << "The value of d is: " << root->right->left->val << endl;     // 50
    cout << "The value of e is: " << root->right->right->val << endl;    // 60

    cout << "Pre-order traversal: ";
    preorder(root);     // 10 20 40 30 50 60

    // No endl after preorder, so this text continues on the SAME line.
    cout << "In-order traversal: ";
    inorder(root);      // 40 20 10 50 30 60


    return 0;           // program finished normally
}
