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

The sample tree:
            10
           /  \
         20    30
        /  \     \
      40    50    60

*/

#include <iostream>     // cin and cout
#include <vector>       // vector
#include <algorithm>    // sort
#include <string>       // not used here
#include <queue>        // STL queue, for level-order input


using namespace std;    // write cout, vector, sort ... without std::

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
 * Leaf nodes in descending order.
 *
 * The idea: a recursive DFS collects every leaf (no left and no right child)
 * into the vector v, which is passed by reference so all calls fill the same
 * vector. Then main sorts it from big to small with greater<int>().
 * Example (sample): leaves 40 50 60 are found, printed as 60 50 40.
 *
 * Base case: NULL adds nothing. The recursive calls trust all_leaf_nodes to
 * add every leaf of that subtree to v.
 */
vector<int> all_leaf_nodes(Node* root, vector<int> &v){
    if(root == NULL){            // empty subtree: nothing to add
        return v;
    }
    // A leaf: store its value.
    if(root->left == NULL && root->right == NULL){
        v.push_back(root->val);  // push_back adds at the end of the vector
    }
    // Look for leaves on both sides (for a leaf both calls return at once).
    // Their return values (copies) are ignored; the real work is done in v.
    all_leaf_nodes(root->left, v);
    all_leaf_nodes(root->right, v);
    return v;                    // a copy of the filled vector
}


int main()
{
    // Write your code here
    Node* root = input_tree();                  // build the tree

    vector<int> v;                              // empty; the function fills it
    vector<int> ans = all_leaf_nodes(root, v);  // ans gets a copy of the leaves
    // greater<int>() puts the biggest value first (descending order).
    // Without it, sort would put the smallest first.
    sort(ans.begin(), ans.end(), greater<int>());

    // i walks over every index of ans; print each value followed by a space.
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;                                   // program finished normally
}
