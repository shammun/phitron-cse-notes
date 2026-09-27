/*

Binary tree input using level-order

Read a whole binary tree from the input, level by level, and print it back
in level order. -1 means "no node here".

Input format: the root's value first; then, for every real node in level
order (top to bottom, left to right), two numbers: its left child and its
right child (-1 = no child).

  input  10 20 30 40 -1 50 60 -1 -1 -1 -1 -1 -1

            10
           /  \
         20    30
         /     / \
       40    50   60

  output 10 20 30 40 50 60

*/

#include <iostream>     // cin and cout
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // STL queue, used for level order

using namespace std;    // write cout, queue ... without std::

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

// Pre-order (Root, Left, Right). Base case: NULL prints nothing.
// (Not called in main here; kept from the previous module.)
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// In-order (Left, Root, Right). Not called in main.
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Post-order (Left, Right, Root). Not called in main.
void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Level order (breadth-first): print level 0, then level 1, ... each level
// left to right. A queue serves the oldest waiting node first, and children
// are added behind everything already waiting, so levels come out in order.
void level_order(Node* root){
    if(root == NULL){
        cout << "No tree" << endl;
        return;
    }
    queue<Node*> q; // Create a queue to store nodes in level order traversal order
                    // (it stores pointers, Node*, not copies of nodes)
    q.push(root); // Push the root node into the queue

    // One pass handles one node; stops when no node is waiting.
    while(!q.empty()){
        Node* f = q.front();   // the oldest waiting node
        q.pop();               // remove it from the queue
        cout << f->val << " "; // Print the value of the current node
        if(f->left){           // a pointer used as a condition is true when it is not NULL
            q.push(f->left);   // left child waits in line
        }
        if(f->right){
            q.push(f->right);  // then the right child
        }
    }
}

// Reads a tree in the level-order format described at the top and returns
// a pointer to its root (NULL for an empty tree).
Node* input_tree(){
    int val;
    cin >> val;             // the root's value
    Node* root;
    if(val == -1){
        root = NULL;        // -1 as the root means the tree is empty
    } else {
        root = new Node(val);   // `new` creates the node on the heap and returns its address
    }

    // Nodes whose children have not been read yet, oldest first.
    queue<Node*> q;
    if(root){
        q.push(root);
    }

    // One pass: take the next node and read its two children from the input.
    // Stops when every real node has had its children read.
    while(!q.empty()){
        Node* p = q.front();    // the node whose children come next in the input
        q.pop();

        int l, r;
        cin >> l >> r;          // left child's value, right child's value (-1 = none)
        Node* myLeft;
        Node* myRight;
        if(l == -1){
            myLeft = NULL;              // no left child
        } else {
            myLeft = new Node(l);       // make the left child
        }

        if(r==-1){
            myRight = NULL;             // no right child
        } else {
            myRight = new Node(r);      // make the right child
        }

        p->left = myLeft;       // attach them to p (-> reaches a member through a pointer)
        p->right = myRight;

        // Real children must get their own children read later, so queue them.
        // Order matters: left before right keeps the input in level order.
        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }

    }

    return root;            // the whole tree hangs off this pointer
}

int main(){

    /*
    10 20 30 40 -1 50 60 -1 -1 -1 -1 -1 -1
    */

   /*

   Take input in this way: first insert a number (this is the root). Then go to the next line and insert
   two inputs for left and right child.

   10
   20 30
   40 -1
   50 60
   -1 -1
   -1 -1
   -1 -1

   */
   Node* root = input_tree();   // read the whole tree
   level_order(root);           // prints 10 20 30 40 50 60 for the sample

    return 0;               // program finished normally
}
