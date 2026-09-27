/*

Problem Statement

You will be given a binary tree as input in level order. You need to print the outer side of the binary tree. See the sample input output for more clarifications. You need to print from the left most leaf node to right most leaf node.

For example:
The output for the above tree will be: 90 40 20 10 30 50 60

Input Format
Input will contain the binary tree in level order.  means there is no node available.

Constraints
1. 1<= Maximum number of nodes <= 10^5 
2. 1 <= Node's value <= 1000 

Output Format
Output the left most leaf node to right most leaf node.

Sample Input 0
10
20 30
40 70 -1 50
90 110 -1 -1 80 60
-1 -1 -1 -1 100 -1 -1 -1
-1 -1

Sample Output 0
90 40 20 10 30 50 60 

Explanation 0
This test case was explained in the question.

Sample Input 1
10
20 30
-1 40 70 50
60 90 -1 -1 80 -1
-1 -1 -1 -1 100 110
-1 -1 -1 -1

Sample Output 1
60 40 20 10 30 50 80 110 

*/



#include <iostream>     // cin and cout
#include <queue>        // STL queue, for level-order input
#include <utility>      // pair (not used here)
#include <vector>       // vector
using namespace std;    // write cout, vector ... without std::

// A binary tree node: a value and two child pointers (NULL = no child).
class Node {
    public:
        int val;        // the value stored here
        Node* left;     // address of the left child
        Node* right;    // address of the right child

    // Constructor, runs on `new Node(x)`: store x, no children yet.
    Node(int val) {
        this->val = val;        // this->val = member, val = parameter
        this->left = NULL;
        this->right = NULL;
    }
};

// Reads the tree in level order, the Module 18 way: first the root, then for
// every real node (in the order a queue hands them out) its left and right
// child, with -1 meaning "no child".
Node* input_tree(){
    int val;
    cin >> val;                  // the root (or -1 for an empty tree)
    Node* root;
    if(val == -1){
        root = NULL;
    } else {
        root = new Node(val);    // `new` builds the node on the heap and returns its address
    }

    // Nodes whose two children have not been read yet.
    queue<Node*> q;
    if(root){                    // a pointer is "true" when it is not NULL
        q.push(root);
    }

    // One pass reads one node's two children; stops when no node is waiting.
    while(!q.empty()){
        Node* p = q.front();     // oldest node still waiting for its children
        q.pop();

        int l, r;
        cin >> l >> r;           // its left and right child values
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

        p->left = myLeft;        // attach the children (-> = member through a pointer)
        p->right = myRight;

        // Only real children wait in the queue for their own pair of values.
        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }

    }

    return root;
}

/*
 * An attempt at problem 5 using the textbook "boundary traversal": left edge,
 * then EVERY leaf, then right edge. That is a different problem: this
 * assignment only wants the two outer edges, so inner leaves such as 110,
 * 70 and 100 must not be printed. The right edge is also printed in the
 * wrong order (50 30 instead of 30 50).
 * Sample 0 prints 60 100 70 110 90 40 20 10 50 30, but the expected answer is
 * 90 40 20 10 30 50 60. The working solution is
 * assignment_problem_5_print_order_tree_another.cpp.
 * (Checked by running it on Sample 0.)
 */

// Helper function to check if node is leaf
// (true only for a real node with no children; NULL is not a leaf).
bool isLeaf(Node* node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}

// Function to collect left boundary
// Walks down the left edge (left child if any, else right child), storing
// each node top-down and stopping BEFORE the leaf at the bottom.
// Sample 0 from 20: stores 20, 40 and stops at the leaf 90.
void leftBoundaryNodes(Node* root, vector<int>& res) {
    if (!root || isLeaf(root)) return;      // !root is true when root is NULL

    res.push_back(root->val);               // top-down order
    if (root->left) {
        leftBoundaryNodes(root->left, res);
    } else if (root->right) {
        leftBoundaryNodes(root->right, res);
    }
}

// Function to collect leaf nodes
// Collects EVERY leaf, left to right (left subtree before right subtree).
// Sample 0: 90 110 70 100 60.
void leafNodes(Node* root, vector<int>& res) {
    if (!root) return;                      // empty subtree

    if (isLeaf(root)) {
        res.push_back(root->val);           // a leaf: store it and stop
        return;
    }

    leafNodes(root->left, res);
    leafNodes(root->right, res);
}

// Function to collect right boundary
// Walks down the right edge (right child if any, else left child), stopping
// before the bottom leaf. The value is stored AFTER the recursive call, so
// the order comes out bottom-up. Sample 0 from 30: stores 50, then 30.
// BUG: the problem wants the right edge top-down (30 50); storing before
// the recursive call (or printing this vector backwards) would fix it.
void rightBoundaryNodes(Node* root, vector<int>& res) {
    if (!root || isLeaf(root)) return;

    if (root->right) {
        rightBoundaryNodes(root->right, res);
    } else if (root->left) {
        rightBoundaryNodes(root->left, res);
    }
    res.push_back(root->val);               // after the call -> bottom-up
}

// Collects the three parts and prints them.
void printBoundary(Node* root) {
    if (!root) return;                      // empty tree: print nothing

    vector<int> leftBoundary, leaves, rightBoundary;    // three empty vectors

    // For single node tree
    if (isLeaf(root)) {
        cout << root->val << endl;
        return;
    }

    // Collect left boundary nodes
    if (root->left) {
        leftBoundaryNodes(root->left, leftBoundary);
    }

    // Collect all leaf nodes
    // BUG: this collects inner leaves too (110, 70, 100 in Sample 0), which
    // the problem does not want. Only the bottom of each outer edge belongs.
    leafNodes(root, leaves);

    // Collect right boundary nodes
    if (root->right) {
        rightBoundaryNodes(root->right, rightBoundary);
    }

    // Print the leaves. The loop walks them BACKWARDS, from the last index
    // down to 0, so they come out right to left: 60 100 70 110 90.
    // BUG: the problem wants the leftmost leaf first, and only the leaves at
    // the bottom of the two outer edges.
    // leaves.size() is unsigned; comparing it with int i works here because
    // i stays >= 0 inside the loop.
    for (int i = leaves.size() - 1; i >= 0; i--) {
        if (i == leaves.size() - 1) {  // the first value printed: no space before it
            cout << leaves[i];
        } else {
            cout << " " << leaves[i];
        }
    }

    // Print left boundary in reverse (excluding root)
    // leftBoundary is top-down (20 40), so backwards gives 40 20.
    for (int i = leftBoundary.size() - 1; i >= 0; i--) {
        cout << " " << leftBoundary[i];
    }

    // Print root
    cout << " " << root->val;

    // Print right boundary nodes
    // (in the bottom-up order they were stored: 50 30)
    for (int i = 0; i < rightBoundary.size(); i++) {
        cout << " " << rightBoundary[i];
    }
    cout << endl;                          // end the line (endl = newline + flush)
}

int main() {
    Node* root = input_tree();             // build the tree
    printBoundary(root);                   // print the (not quite right) boundary
    return 0;                              // program finished normally
}
