/*

Sum without leaf

Problem Statement

You will be given a binary tree as input in level order. You need to output the sum of all node's values in that tree except the leaf nodes.

For example

The output for the above tree will be: 60

Input Format

Input will contain the binary tree in level order. -1 means there is no node
available.

Constraints

1. 1<= Maximum number of nodes<= 10^5
2. 1<= Node's value <= 1000

Output Format

Output the total sum of that tree except the leaf nodes.

Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1

Sample Output 0

60

The sample tree:
            10
           /  \
         20    30
        /  \     \
      40    50    60

*/

#include <iostream>     // cin and cout
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // not used here
#include <queue>        // STL queue, for level order

using namespace std;    // write cout, queue ... without std::

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
 * Sum without leaf: add up every node that has at least one child.
 *
 * The idea: visit every node once with a level-order walk (queue). A node is
 * NOT a leaf when it has a left child or a right child, so only then is its
 * value added. Example (sample): 10, 20 and 30 have children, 40 50 60 do not,
 * so the answer is 10 + 20 + 30 = 60.
 *
 * int is enough: at most 10^5 nodes * 1000 = 10^8, below int's limit (~2.1 * 10^9).
 */
int sum_without_leaf(Node* root){
    if(!root){                   // empty tree: the sum is 0 (!root is true when root is NULL)
        return 0;
    }

    queue<Node*> q;              // nodes waiting to be checked
    q.push(root);

    int sum = 0;                 // running total of non-leaf values
    // One pass checks one node; stops when every node has been checked.
    while(!q.empty()){
        Node* parent = q.front();
        q.pop();

        // At least one child -> not a leaf -> count it.
        if(parent->left || parent->right){
            sum += parent->val;
        }

        // Queue the children so every node gets checked.
        if(parent->left){
            q.push(parent->left);
        }
        if(parent->right){
            q.push(parent->right);
        }
    }

    return sum;
}

int main()
{
    // Write your code here
    Node* root = input_tree();                 // build the tree from the input
    cout << sum_without_leaf(root) << endl;    // print the answer (endl = newline + flush)
    return 0;                                  // program finished normally
}
