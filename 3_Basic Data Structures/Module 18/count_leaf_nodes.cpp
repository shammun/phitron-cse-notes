/*

Count the leaf nodes of a binary tree

A leaf is a node with no children at all -- the ends of the tree. Counting
them is the same recursive shape as counting every node
(count_nodes_in_a_binary_tree.cpp), with one extra case:

    empty tree (NULL)        -> 0 leaves
    both children are NULL   -> this node IS a leaf -> 1
    anything else            -> leaves on the left + leaves on the right,
                                and this node is NOT counted

That third line is the difference from count_nodes, which adds 1 for itself
every time. Here an inner node contributes nothing of its own.

The leaf test has to come before the two recursive calls. Without it a leaf
would go on to ask both of its NULL children, get 0 + 0, and no leaf would
ever be counted.

Cost: O(n) time (every node is visited once) and O(h) memory for the
recursion, where h is the height of the tree.

BUG in main: it prints `count_nodes(root)`, not `count_leaf_nodes(root)`, so
the new function is never actually called. For the sample tree you see 6 (the
number of nodes) instead of 3 (the leaves 40, 50 and 60). The fix is one line:
`cout << count_leaf_nodes(root) << endl;`. The code is left as it is here so
the mistake stays visible.

*/


#include <iostream>     // cin and cout
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // STL queue, for level-order reading and printing

using namespace std;    // write cout, queue ... without std::

// One node of a binary tree: a value and two child pointers. NULL means
// "no child on that side".
class Node{
    public:
        int val;        // the value stored here
        Node* left;     // address of the left child (NULL = none)
        Node* right;    // address of the right child (NULL = none)

    // Constructor, runs on `new Node(x)`: store x, no children yet.
    Node(int val){
        this->val = val;        // this->val = the member; val = the parameter
        this->left = NULL;
        this->right = NULL;
    }
};

// Level order (breadth-first) printing, as built earlier in this module:
// take the front of the queue, print it, push its real children. The queue
// is what keeps the upper levels ahead of the lower ones.
void level_order(Node* root){
    if(root == NULL){
        cout << "No tree" << endl;
        return;
    }

    queue<Node*> q;     // nodes waiting to be printed (pointers, oldest first)
    q.push(root);

    // One pass prints one node; stops when nothing is waiting.
    while(!q.empty()){
        Node* f= q.front();     // oldest waiting node
        q.pop();                // remove it from the queue

        cout << f->val << " ";

        if(f->left){            // true when the pointer is not NULL
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}

// Reading a tree level by level, also from earlier in this module: the root
// first, then two numbers (left child, right child) for every node taken out
// of the queue, with -1 meaning "no child". Only real children are pushed,
// so only they get their own line of input later.
Node* input_tree(){
    int val;
    cin >> val;                 // the root's value
    Node* root;
    if(val == -1){
        root = NULL;            // empty tree
    } else{
        root = new Node(val);   // `new` makes the node on the heap and returns its address
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
        cin >> l >> r;          // p's left and right child values (-1 = none)

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

        // Queue the real children so their children are read later, in order.
        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }
    }

    return root;
}

// Every node counts itself once: left side + right side + 1.
// Base case: NULL -> 0. Each call trusts count_nodes(child) to count that subtree.
int count_nodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = count_nodes(root->left);    // nodes in the left subtree
    int r = count_nodes(root->right);   // nodes in the right subtree
    return l + r + 1;                   // + 1 for this node
}

// Number of leaves in the tree under root.
int count_leaf_nodes(Node* root){
    // Nothing here, so nothing to count. This is also what stops the
    // recursion on the side where a node has only one child.
    if(root == NULL){
        return 0;
    }
    // No children on either side: this node is a leaf. Answer 1 and stop --
    // asking the two NULL children would give 0 + 0 and lose the leaf.
    if(root-> left == NULL && root->right == NULL){
        return 1;
    }
    // An inner node: the leaves below it are the leaves of its two subtrees.
    // Note there is no `+ 1` -- an inner node is not a leaf itself.
    int l = count_leaf_nodes(root->left);
    int r = count_leaf_nodes(root->right);
    return l + r;
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
   // Build the tree, then show it level by level so the shape is visible.
   Node* root = input_tree();
   level_order(root);           // 10 20 30 40 50 60
   cout << endl;                // end that line

   // BUG: this should be count_leaf_nodes(root) -- see the note at the top of
   // the file. As written it prints 6, the node count, not the 3 leaves.
   // Fix: cout << count_leaf_nodes(root) << endl;
   cout << count_nodes(root) << endl;

    return 0;                   // program finished normally
}
