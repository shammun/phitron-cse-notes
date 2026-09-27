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

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// A binary tree node: a value and two child pointers (NULL = no child).
class Node {
    public:
        int val;     
        Node* left;  
        Node* right; 

    
    Node(int val) {
        this->val = val; 
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
        root = new Node(val);
    }

    // Nodes whose two children have not been read yet.
    queue<Node*> q;
    if(root){
        q.push(root);
    }

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

        p->left = myLeft;
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
 * Outer side of the tree: the left edge from its bottom up to the root, then
 * the right edge from the root down to its bottom.
 *
 * The idea: two small recursions that each walk ONE path, not the whole tree.
 *   - left_boundary walks down the left edge: go left if possible, otherwise
 *     right. The value is stored AFTER the recursive call, so the deepest
 *     node is stored first (bottom-up order).
 *   - right_boundary walks down the right edge: go right if possible,
 *     otherwise left. The value is stored BEFORE the recursive call, so the
 *     order is top-down.
 * Sample 0: left edge 20 -> 40 -> 90 gives 90 40 20, then the root 10, then
 * the right edge 30 -> 50 -> 60: 90 40 20 10 30 50 60.
 *
 * This is the version that gives the expected answers. The other two
 * problem-5 files are earlier attempts that do not.
 */
void left_boundary(Node* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    // Follow the outer path: left child first, the right one only if there
    // is no left child.
    if(root->left){
        left_boundary(root->left, v);
    } else if(root->right){
        left_boundary(root->right, v);
    }
    v.push_back(root->val);      // after the call -> bottom-up
}

void right_boundary(Node* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    v.push_back(root->val);      // before the call -> top-down
    // Follow the outer path: right child first, the left one only if there
    // is no right child.
    if(root->right){
        right_boundary(root->right, v);
    } else if(root->left){
        right_boundary(root->left, v);
    }
}

void print_boundary(Node* root, vector<int> &v){
    left_boundary(root->left, v);    // left edge, bottom to top
    v.push_back(root->val);          // the root in the middle
    right_boundary(root->right, v);  // right edge, top to bottom

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}


int main() {
    Node* root = input_tree();
    vector<int> v;
    print_boundary(root, v);
    return 0;
}