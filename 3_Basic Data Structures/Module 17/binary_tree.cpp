/*

Implements a binary tree

A binary tree is made of nodes. Every node holds a value and two pointers:
one to its LEFT child and one to its RIGHT child (either can be NULL,
meaning "no child there"). The top node is called the root. Here we build
this tree by hand and print every value by walking the pointers:

            10          <- root
           /  \
         20    30       <- a, b
         /     / \
       40    50   60    <- c, d, e

*/


#include <iostream>     // cin and cout
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // not used here
#include <stack>        // not used here

using namespace std;    // write cout instead of std::cout

// One node of the binary tree.
class Node {
    public:              // members usable from outside the class (main needs them)
        int val;     // Value stored in the node (data).
        Node* left;  // Pointer to the left node in the binary tree.
        Node* right; // Pointer to the right node in the binary tree.

        // Constructor for the Node class: stores 'val' and sets 'left' and 'right' to NULL.
        // It runs automatically on `new Node(x)`.
    Node(int val) {
        this->val = val;  // Assign the provided value to the 'val' member (this->val = member, val = parameter).
        this->left = NULL; // Initialize 'left' to NULL, meaning no left node by default.
        this->right = NULL; // Initialize 'right' to NULL, meaning no right node by default.
    }
};

int main(){
    // `new Node(x)` creates a node on the heap (it lives until the program
    // ends or it is deleted) and gives back its address, kept in a Node* pointer.
    Node* root = new Node(10);   // the top of the tree
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    // Connect the nodes. p->left is the `left` member of the node p points to
    // (the arrow -> is short for (*p).left).
    root->left = a;     // 20 is the left child of 10
    root->right = b;    // 30 is the right child of 10
    a->left = c;        // 40 is the left child of 20 (20 has no right child: stays NULL)
    b->left = d;        // 50 is the left child of 30
    b->right = e;       // 60 is the right child of 30

    // Reach each node from the root by following pointers.
    // e.g. root->left->left: from 10 go left (20), then left again (40).
    cout << "The value of root is: " << root->val << endl;               // 10
    cout << "The value of a is: " << root->left->val << endl;            // 20
    cout << "The value of b is: " << root->right->val << endl;           // 30
    cout << "The value of c is: " << root->left->left->val << endl;      // 40
    cout << "The value of d is: " << root->right->left->val << endl;     // 50
    cout << "The value of e is: " << root->right->right->val << endl;    // 60
    // (endl ends the line and flushes the output)

    return 0;           // program finished normally
}
