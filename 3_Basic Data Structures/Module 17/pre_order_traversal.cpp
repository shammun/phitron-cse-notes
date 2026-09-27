/*

Pre-order traversal

Root  -> Left -> Right

Visit every node of a binary tree: the node itself FIRST, then its whole
left subtree, then its whole right subtree. The same tree as binary_tree.cpp:

            10
           /  \
         20    30
         /     / \
       40    50   60

  Pre-order: 10 20 40 30 50 60

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

// Pre-order: Root -> Left -> Right (recursive).
// Base case: root == NULL (an empty subtree) prints nothing and returns.
// The recursive calls trust that preorder(child) prints the child's whole
// subtree in pre-order. Trace: print 10, preorder(20) prints "20 40",
// preorder(30) prints "30 50 60".
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";   // the node first
    preorder(root->left);       // then everything in its left subtree
    preorder(root->right);      // then everything in its right subtree
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


    return 0;           // program finished normally
}
