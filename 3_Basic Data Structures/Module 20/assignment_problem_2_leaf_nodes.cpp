/*

Print Leaf Nodes in Descending Order

Problem Statement

You will be given a binary tree as input in level order. You need to print the values 
of leaf nodes in descending order.

For example:

The output for the above tree will be: 60 50 40

Input Format

Input will contain the binary tree in level order. -1 means there is no node available.

Constraints

1. 1<= Maximum number of nodes <= 10^5 
2. 1<= Node's value <= 1000

Output Format

Output the values of leaf nodes in descending order.

Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1

Sample Output 0

60 50 40

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>


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
 * Leaf nodes in descending order.
 *
 * The idea: a recursive DFS collects every leaf (no left and no right child)
 * into the vector v, which is passed by reference so all calls fill the same
 * vector. Then main sorts it from big to small with greater<int>().
 * Example (sample): leaves 40 50 60 are found, printed as 60 50 40.
 */
vector<int> all_leaf_nodes(Node* root, vector<int> &v){
    if(root == NULL){            // empty subtree: nothing to add
        return v;
    }
    // A leaf: store its value.
    if(root->left == NULL && root->right == NULL){
        v.push_back(root->val);
    }
    // Look for leaves on both sides (for a leaf both calls return at once).
    all_leaf_nodes(root->left, v);
    all_leaf_nodes(root->right, v);
    return v;                    // a copy of the filled vector
}


int main()
{
    // Write your code here
    Node* root = input_tree(); 

    vector<int> v;
    vector<int> ans = all_leaf_nodes(root, v);
    // greater<int>() puts the biggest value first (descending order).
    sort(ans.begin(), ans.end(), greater<int>());

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}