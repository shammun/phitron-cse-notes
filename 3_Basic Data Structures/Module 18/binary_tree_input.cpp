/*

Binary tree input using level-order

*/

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

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

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void level_order(Node* root){
    if(root == NULL){
        cout << "No tree" << endl;
        return;
    }
    queue<Node*> q; // Create a queue to store nodes in level order traversal order
    q.push(root); // Push the root node into the queue

    while(!q.empty()){ 
        Node* f = q.front(); 
        q.pop();
        cout << f->val << " "; // Print the value of the current node
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}

Node* input_tree(){
    int val;
    cin >> val;
    Node* root;
    if(val == -1){
        root = NULL;
    } else {
        root = new Node(val);
    }

    queue<Node*> q;
    if(root){
        q.push(root);
    }

    while(!q.empty()){
        Node* p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node* myLeft;
        Node* myRight;
        if(l == -1){
            myLeft = NULL;
        } else {
            myLeft = new Node(l);
        }

        if(r==-1){
            myRight = NULL;
        } else {
            myRight = new Node(r);
        }

        p->left = myLeft;
        p->right = myRight;

        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }

    }

    return root;
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
   Node* root = input_tree();
   level_order(root);

    return 0;
}

