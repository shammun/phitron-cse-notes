/*

Post-order traversal

Left -> Right -> Root

Visit every node of a binary tree: first the whole left subtree, then the
whole right subtree, and the node itself LAST. The same tree as
binary_tree.cpp:

            10
           /  \
         20    30
         /     / \
       40    50   60

  Pre-order  (Root, Left, Right): 10 20 40 30 50 60
  In-order   (Left, Root, Right): 40 20 10 50 30 60
  Post-order (Left, Right, Root): 40 20 50 60 30 10


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

// Pre-order: Root -> Left -> Right. Base case: NULL prints nothing.
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";   // node first
    preorder(root->left);       // then left subtree
    preorder(root->right);      // then right subtree
}

// In-order: Left -> Root -> Right. Base case: NULL prints nothing.
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);        // left subtree first
    cout << root->val << " ";   // then the node
    inorder(root->right);       // then right subtree
}

// Post-order: Left -> Right -> Root. Base case: NULL prints nothing.
// Each call trusts postorder(child) to print that child's whole subtree,
// so a node is printed only after both its subtrees are done.
void postorder(Node* root){
    // if(!root){}   (another way to write the NULL test: !root is true when root is NULL; left unfinished)
    if(root == NULL){
        return;
    }
    postorder(root->left);      // left subtree first
    postorder(root->right);     // then right subtree
    cout << root->val << " ";   // the node last
}

int main(){
    // Build the nodes on the heap (`new` returns each node's address).
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    // Link them into the tree drawn above.
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

    // No endl between the three traversals, so they all print on one line.
    cout << "Pre-order traversal: ";
    preorder(root);     // 10 20 40 30 50 60

    cout << "In-order traversal: ";
    inorder(root);      // 40 20 10 50 30 60

    cout << "Post-order traversal: ";
    postorder(root);    // 40 20 50 60 30 10

    return 0;           // program finished normally
}
