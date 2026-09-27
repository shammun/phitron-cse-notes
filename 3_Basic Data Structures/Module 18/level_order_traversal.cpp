/*

Level-order traversal

We use queue

We start with a node and add it to the queue

Then we pop the first element from the queue and print it

Then we add its left and right child to the queue

Then we repeat the process until the queue is empty

Why a queue: it serves the oldest waiting node first (FIFO). The children
of a level are always pushed behind every node of that level, so a whole
level is printed before the next one starts.

            10
           /  \
         20    30
         /     / \
       40    50   60

  queue: [10] -> print 10, push 20 30 -> [20 30] -> print 20, push 40
         -> [30 40] -> print 30, push 50 60 -> [40 50 60] -> print 40, 50, 60
  Level-order: 10 20 30 40 50 60

*/

#include <iostream>     // cout, endl
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // STL queue

using namespace std;    // write cout, queue without std::

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

// Pre-order: Root, Left, Right. Base case: NULL prints nothing.
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// In-order: Left, Root, Right.
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Post-order: Left, Right, Root.
void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Level order (breadth-first). Note: no NULL check here, so calling it with
// an empty tree would push NULL and then crash on f->val. main never does that.
void level_order(Node* root){
    queue<Node *> q; // Create a queue to store nodes in level order traversal order
                     // (it holds pointers to nodes, not copies)
    q.push(root); // Push the root node into the queue

    // One pass prints one node; stops when no node is waiting.
    while(!q.empty()){
        Node* f = q.front();    // the oldest waiting node
        q.pop();                // take it out of the queue
        cout << f->val << " "; // Print the value of the current node
        if(f->left){            // a pointer is "true" when it is not NULL
            q.push(f->left);    // left child joins the back of the line
        }
        if(f->right){
            q.push(f->right);   // then the right child
        }
    }
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
    cout << endl;       // endl = newline + flush

    cout << "In-order traversal: ";
    inorder(root);      // 40 20 10 50 30 60
    cout << endl;

    cout << "Post-order traversal: ";
    postorder(root);    // 40 20 50 60 30 10
    cout << endl;

    cout << "Level-order traversal: ";
    level_order(root);  // 10 20 30 40 50 60
    cout << endl;

    return 0;           // program finished normally
}
