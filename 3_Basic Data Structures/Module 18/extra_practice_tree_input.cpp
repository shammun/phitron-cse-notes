/*

Extra practice: what input builds this tree?

The module's extra-practice sheet shows the same 9-node tree as Module 17's
extra practice and asks what you must type so that input_tree() builds it:

                 1
              /     \
             7       9
            / \       \
           2   6       9
              / \     /
             5   11  5

Answer (one line is fine, cin does not care about line breaks):
    1 7 9 2 6 -1 9 -1 -1 5 11 5 -1 -1 -1 -1 -1 -1 -1

This program reads that line, builds the tree, and prints it back in level
order and in the three depth-first orders, so you can check the tree is right:
    Level-order: 1 7 9 2 6 9 5 11 5
    Pre-order  : 1 7 2 6 5 11 9 9 5

*/

/*
 * How to write the input by hand:
 *   1. Write the root.
 *   2. Then walk the tree level by level (the same order the queue uses).
 *      For every REAL node, write its left child and its right child,
 *      using -1 for a missing child.
 *   3. Missing children (-1) never get children of their own, so nothing is
 *      written for them. Every leaf still needs its "-1 -1".
 *
 * For our tree, the pairs are:
 *   1 -> 7 9      7 -> 2 6      9 -> -1 9      2 -> -1 -1
 *   6 -> 5 11     9 -> 5 -1     5 -> -1 -1     11 -> -1 -1    5 -> -1 -1
 * Nine real nodes, so nine pairs after the root: 1 + 18 = 19 numbers.
 */

#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
        int val;     // Value stored in the node.
        Node* left;  // Left child (NULL = none).
        Node* right; // Right child (NULL = none).

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Reads the tree exactly the way binary_tree_input.cpp does.
Node* input_tree(){
    int val;
    cin >> val;                          // the root, or -1 for an empty tree
    Node* root;
    if(val == -1){
        root = NULL;
    } else {
        root = new Node(val);
    }

    // The queue holds the real nodes whose two children we still have to read.
    queue<Node*> q;
    if(root){
        q.push(root);
    }

    while(!q.empty()){
        Node* p = q.front();             // the oldest node still waiting
        q.pop();

        int l, r;
        cin >> l >> r;                   // its left and right child values

        // -1 means "no child here"; any other number becomes a new node.
        Node* myLeft;
        Node* myRight;
        if(l == -1){
            myLeft = NULL;
        } else {
            myLeft = new Node(l);
        }
        if(r == -1){
            myRight = NULL;
        } else {
            myRight = new Node(r);
        }

        p->left = myLeft;
        p->right = myRight;

        // Only real children wait in the queue for their own pair of numbers.
        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }
    }

    return root;
}

// Prints the tree level by level with the same queue idea.
void level_order(Node* root){
    if(root == NULL){
        cout << "No tree" << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* f = q.front();
        q.pop();
        cout << f->val << " ";
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}

// Root -> Left -> Right (from Module 17), a second check of the shape.
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root = input_tree();

    cout << "Level-order: ";
    level_order(root);
    cout << endl;

    cout << "Pre-order  : ";
    preorder(root);
    cout << endl;

    return 0;
}
