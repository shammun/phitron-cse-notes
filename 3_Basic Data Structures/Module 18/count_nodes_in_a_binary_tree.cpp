/*

Count the nodes of a binary tree

Read a tree in level order (-1 = no node), print it level by level, then
print how many nodes it has.

The idea (recursion): the number of nodes in a tree is
    (nodes in the left subtree) + (nodes in the right subtree) + 1
where the + 1 is the root itself. An empty tree (NULL) has 0 nodes, which
is where the recursion stops.

  input  10 20 30 40 -1 50 60 -1 -1 -1 -1 -1 -1

            10
           /  \
         20    30
         /     / \
       40    50   60

  output 10 20 30 40 50 60
         6

  count(40) = 0 + 0 + 1 = 1, count(20) = 1 + 0 + 1 = 2,
  count(30) = 1 + 1 + 1 = 3, count(10) = 2 + 3 + 1 = 6.

Cost: O(n) time, every node is visited once.

*/


#include <iostream>     // cin and cout
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // STL queue, for level-order reading and printing

using namespace std;    // write cout, queue ... without std::

// One node of a binary tree: a value and two child pointers (NULL = no child).
class Node{
    public:
        int val;        // the value stored here
        Node* left;     // address of the left child
        Node* right;    // address of the right child

    // Constructor, runs on `new Node(x)`: store x, no children yet.
    Node(int val){
        this->val = val;        // this->val is the member, val the parameter
        this->left = NULL;
        this->right = NULL;
    }
};

// Print the tree level by level (breadth-first) using a queue: the oldest
// waiting node is printed first, and its children join the back of the line.
void level_order(Node* root){
    if(root == NULL){
        cout << "No tree" << endl;
        return;
    }

    queue<Node*> q;     // waiting nodes (pointers)
    q.push(root);

    // One pass prints one node; stops when nothing is waiting.
    while(!q.empty()){
        Node* f= q.front();     // oldest waiting node
        q.pop();

        cout << f->val << " ";

        if(f->left){            // a pointer is "true" when it is not NULL
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}

// Read a tree in level order: the root, then for each real node (in level
// order) its left and right child values, -1 meaning "no child".
Node* input_tree(){
    int val;
    cin >> val;                 // root value
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

    // One pass reads the two children of one node.
    while(!q.empty()){
        Node* p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;          // left and right child values

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

        p->left = myLeft;       // hook them under p (-> = member through a pointer)
        p->right = myRight;

        // Real children wait in the queue so their own children are read later.
        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }
    }

    return root;
}

// Number of nodes in the tree under root.
// Base case: NULL -> 0. The recursive calls trust that count_nodes(child)
// returns the size of that child's subtree.
int count_nodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = count_nodes(root->left);    // nodes on the left
    int r = count_nodes(root->right);   // nodes on the right
    return l + r + 1;                   // plus 1 for this node
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
   Node* root = input_tree();       // build the tree from the input
   level_order(root);               // show it: 10 20 30 40 50 60
   cout << endl;                    // end that line

   cout << count_nodes(root) << endl;   // 6 for the sample

    return 0;                       // program finished normally
}
