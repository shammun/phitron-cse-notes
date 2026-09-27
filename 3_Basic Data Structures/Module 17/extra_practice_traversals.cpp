/*

Extra practice: write the pre-order, in-order and post-order of a given tree.

The module's extra-practice sheet shows a picture of a 9-node binary tree and
asks for its three depth-first traversals. Here is that tree, drawn with text:

                 1
              /     \
             7       9
            / \       \
           2   6       9
              / \     /
             5   11  5

Expected answer (worked out below, and printed by the program):
    Pre-order : 1 7 2 6 5 11 9 9 5
    In-order  : 2 7 5 6 11 1 9 5 9
    Post-order: 2 5 11 6 7 5 9 9 1

*/

/*
 * The idea: build the tree by hand, exactly like binary_tree.cpp, and let the
 * three recursive functions of this module do the work. Each function is the
 * same three lines; only the position of the `cout` changes:
 *   pre-order  = print the node, then the left side, then the right side
 *   in-order   = the left side, then print the node, then the right side
 *   post-order = the left side, then the right side, then print the node
 *
 * Doing it on paper first and then comparing with the output is the best
 * practice: if your paper answer differs, trace the recursion again.
 */

#include <iostream>     // cout, endl
using namespace std;    // write cout instead of std::cout

// One node of the binary tree: a value and pointers to its two children.
class Node {
    public:
        int val;     // Value stored in the node.
        Node* left;  // Pointer to the left child (NULL = no left child).
        Node* right; // Pointer to the right child (NULL = no right child).

    // Constructor, runs on `new Node(x)`: store the value, no children yet.
    Node(int val) {
        this->val = val;      // this->val is the member, val is the parameter
        this->left = NULL;
        this->right = NULL;
    }
};

// Root -> Left -> Right
// Base case: an empty subtree (NULL). The recursive calls trust that
// preorder(child) prints that child's whole subtree in pre-order.
void preorder(Node* root){
    if(root == NULL){       // An empty subtree prints nothing.
        return;
    }
    cout << root->val << " ";   // The node itself comes first ...
    preorder(root->left);       // ... then its whole left subtree ...
    preorder(root->right);      // ... then its whole right subtree.
}

// Left -> Root -> Right
// Same base case; each call trusts inorder(child) to print that subtree in-order.
void inorder(Node* root){
    if(root == NULL){           // empty subtree: nothing to print
        return;
    }
    inorder(root->left);        // Finish everything on the left first,
    cout << root->val << " ";   // then the node,
    inorder(root->right);       // then everything on the right.
}

// Left -> Right -> Root
// Same base case; each call trusts postorder(child) to print that subtree in post-order.
void postorder(Node* root){
    if(root == NULL){           // empty subtree: nothing to print
        return;
    }
    postorder(root->left);      // Both children are finished first,
    postorder(root->right);
    cout << root->val << " ";   // and the node is printed last.
}

int main(){
    // One Node object per circle in the picture. There are two 9s and two 5s,
    // so the names say where each one sits.
    // `new` builds each node on the heap and returns its address.
    Node* root   = new Node(1);
    Node* a      = new Node(7);   // left child of 1
    Node* b      = new Node(9);   // right child of 1
    Node* c      = new Node(2);   // left child of 7 (a leaf)
    Node* d      = new Node(6);   // right child of 7
    Node* e      = new Node(9);   // right child of the upper 9
    Node* f      = new Node(5);   // left child of 6 (a leaf)
    Node* g      = new Node(11);  // right child of 6 (a leaf)
    Node* h      = new Node(5);   // left child of the lower 9 (a leaf)

    // Link the pointers level by level. Any pointer we do not set stays NULL,
    // which is how "no child" is written (for example b->left).
    // (p->left means "the left member of the node p points to".)
    root->left = a;     // 1 -> left 7
    root->right = b;    // 1 -> right 9
    a->left = c;        // 7 -> left 2
    a->right = d;       // 7 -> right 6
    b->right = e;       // upper 9 -> right lower 9
    d->left = f;        // 6 -> left 5
    d->right = g;       // 6 -> right 11
    e->left = h;        // lower 9 -> left 5

    // Each traversal gets its own line (endl after each call).
    cout << "Pre-order : ";
    preorder(root);     // prints 1 7 2 6 5 11 9 9 5
    cout << endl;       // endl = newline + flush

    cout << "In-order  : ";
    inorder(root);      // prints 2 7 5 6 11 1 9 5 9
    cout << endl;

    cout << "Post-order: ";
    postorder(root);    // prints 2 5 11 6 7 5 9 9 1
    cout << endl;

    return 0;           // program finished normally
}
