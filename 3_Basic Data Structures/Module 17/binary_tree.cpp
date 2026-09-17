/*

Implements a binary tree

*/


#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>

using namespace std;

class Node {
    public:
        int val;     // Value stored in the node (data).
        Node* left;  // Pointer to the left node in the binary tree.
        Node* right; // Pointer to the right node in the binary tree.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
    Node(int val) {
        this->val = val;  // Assign the provided value to the 'val' member.
        this->left = NULL; // Initialize 'left' to NULL, meaning no left node by default.
        this->right = NULL; // Initialize 'right' to NULL, meaning no right node by default.
    }
};

int main(){
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    cout << "The value of root is: " << root->val << endl;
    cout << "The value of a is: " << root->left->val << endl;
    cout << "The value of b is: " << root->right->val << endl;
    cout << "The value of c is: " << root->left->left->val << endl;
    cout << "The value of d is: " << root->right->left->val << endl;
    cout << "The value of e is: " << root->right->right->val << endl;

    return 0;
}