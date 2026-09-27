/*

Maximum height of a binary tree (counted in EDGES)

Read a tree in level order (-1 = no node), print it level by level, print
the number of nodes, then print the tree's height.

Height here = the number of edges (links) on the longest path from the root
down to a leaf. So a single leaf has height 0. (Some problems count NODES
instead, where a leaf has height 1 - see code360_height_of_a_binary_tree.cpp.)

The idea (recursion): the longest path from a node goes down through its
taller child, so height(node) = max(height(left), height(right)) + 1, the
+ 1 being the edge from the node to that child.

  Sample 1:  10 20 30 40 -1 50 60 -1 -1 -1 -1 -1 -1
            10
           /  \
         20    30
         /     / \
       40    50   60
  output: 10 20 30 40 50 60 / 6 / 2   (path 10 -> 30 -> 50 has 2 edges)

  Sample 2:  6 3 5 -1 2 0 -1 -1 1 -1 -1 -1 -1
  tree: 6 -> (3, 5), 3 -> right 2, 5 -> left 0, 2 -> right 1
  output: 6 3 5 2 0 1 / 6 / 3   (path 6 -> 3 -> 2 -> 1 has 3 edges)

*/



#include <iostream>     // cin and cout
#include <vector>       // not used here
#include <algorithm>    // max()
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // STL queue, for level order

using namespace std;    // write cout, queue, max without std::

// One node of a binary tree: a value and two child pointers (NULL = no child).
class Node{
    public:
        int val;        // the value stored here
        Node* left;     // address of the left child
        Node* right;    // address of the right child

    // Constructor, runs on `new Node(x)`: store x, no children yet.
    Node(int val){
        this->val = val;        // this->val = member, val = parameter
        this->left = NULL;
        this->right = NULL;
    }
};

// Print the tree level by level (breadth-first) with a queue.
void level_order(Node* root){
    if(root == NULL){
        cout << "No tree" << endl;
        return;
    }

    queue<Node*> q;     // waiting nodes, oldest first
    q.push(root);

    // One pass prints one node and queues its real children.
    while(!q.empty()){
        Node* f= q.front();
        q.pop();

        cout << f->val << " ";

        if(f->left){            // pointer is "true" when not NULL
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}

// Read a tree in level order: root first, then for each real node its left
// and right child values (-1 = no child). Returns the root's address.
Node* input_tree(){
    int val;
    cin >> val;
    Node* root;
    if(val == -1){
        root = NULL;            // empty tree
    } else{
        root = new Node(val);   // `new` builds the node on the heap, returns its address
    }

    queue<Node*> q;             // nodes whose children are still to be read
    if(root){
        q.push(root);
    }

    // One pass reads one node's two children.
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

        if(r == -1){
            myRight = NULL;
        } else{
            myRight = new Node(r);
        }

        p->left = myLeft;       // attach the children to p
        p->right = myRight;

        // Real children wait in the queue for their own children to be read.
        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }
    }

    return root;
}

// Number of nodes: left + right + 1 (this node). NULL -> 0.
int count_nodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);
    return l + r + 1;
}

// Number of leaves (nodes with no children). Not called in main here.
int count_leaf_nodes(Node* root){
    if(root == NULL){
        return 0;               // empty: no leaves
    }
    if(root-> left == NULL && root->right == NULL){
        return 1;               // this node is a leaf
    }
    int l = count_leaf_nodes(root->left);
    int r = count_leaf_nodes(root->right);
    return l + r;               // an inner node adds nothing itself
}

// Height in edges. Base cases: NULL -> 0 and a leaf -> 0.
// The recursive calls trust max_height(child) to return the child's height.
// A node with only one child: the NULL side gives 0, which is never larger
// than the real child's height (>= 0), so max() still picks the real side.
// Trace (sample 1): 40, 50, 60 are leaves -> 0; 20 -> max(0,0)+1 = 1;
// 30 -> max(0,0)+1 = 1; 10 -> max(1,1)+1 = 2.
int max_height(Node* root){
    if(root == NULL){
        return 0;
    }
    // is it a leaf node?
    if(root->left == NULL && root->right == NULL){
        return 0;               // a leaf has no edges below it
    }
    int l = max_height(root->left);     // height of the left subtree
    int r = max_height(root->right);    // height of the right subtree
    return max(l, r) + 1;               // taller side + the edge down to it
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

   6
   3 5
   -1 2
   0 -1
   -1 1
   -1 -1
   -1 -1

   */
   Node* root = input_tree();           // build the tree
   level_order(root);                   // show its shape level by level
   cout << endl;

   cout << count_nodes(root) << endl;   // number of nodes

   cout << max_height(root) << endl;    // height in edges

    return 0;                           // program finished normally
}
