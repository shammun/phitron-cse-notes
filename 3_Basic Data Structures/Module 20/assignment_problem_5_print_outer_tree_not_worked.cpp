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
#include <queue>        // STL queue
#include <utility>      // pair
#include <vector>       // vector
using namespace std;    // write cout, vector, pair ... without std::

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
 * An earlier attempt at problem 5, kept to learn from. It does not work.
 *
 * The plan: collect every level with level_nodes() from problem 4, then print
 * the first node of each level from the bottom up and the last node of each
 * level from the top down.
 *
 * Why it fails:
 *   1. It crashes. In print_outer_nodes the loop
 *        for(size_t i = levels.size()-1; i >= 0; i--)
 *      never ends: size_t is unsigned, so after i = 0 the i-- wraps round to
 *      a huge number and levels[i] reads far outside the vector.
 *      (Running it on Sample 0 does crash with an access violation.)
 *   2. Even with `int i`, "first node of each level" is not the same as the
 *      outer edge (100 is the first node of its level but is not on the edge).
 *   3. main reads an extra number X that the problem never gives.
 * The working solution is assignment_problem_5_print_order_tree_another.cpp.
 */

// Same as problem 4: the values on level X, or {-999} if there is no level X.
// Level-order walk with {node, level} pairs; the root is level 0.
vector<int> level_nodes(Node* root, int X) {
    vector<int> ans;                 // values found on level X
    queue<pair<Node*, int>> q;       // {node, level}; .first = node, .second = level
    if(root){
        q.push({root, 0});           // {a, b} builds the pair
    }

    // One pass handles one node; the whole tree is walked every time.
    while(!q.empty()){
        pair<Node*, int> parent = q.front();
        q.pop();

        Node* node = parent.first;
        int level = parent.second;

        if(level == X){
            ans.push_back(node->val);        // on the wanted level: keep it
        }

        // Children are one level deeper.
        if(node->left){
            q.push({node->left, level + 1});
        }

        if(node->right){
            q.push({node->right, level + 1});
        }
    }
    if(ans.empty()){
        ans.push_back(-999);                 // signal: no such level
    }
    return ans;
}


// Calls level_nodes for level 0, 1, 2, ... until a level is empty, and stores
// each level as {level number, values}. (One BFS per level: O(n * h) time.)
// Sample 0 gives {0,[10]}, {1,[20 30]}, {2,[40 70 50]}, {3,[90 110 80 60]}, {4,[100]}.
vector<pair<int, vector<int>>> all_nodes_at_all_levels(Node* root){
    vector<pair<int, vector<int>>> levels;   // a vector whose items are pairs (int, vector<int>)
    int level = 0;                           // the level being asked for next

    // while(true) loops forever; the break below is the only way out.
    while(true){
        vector<int> current_level_nodes = level_nodes(root, level);
        if(current_level_nodes[0] == -999){  // this level does not exist: done
            break;
        }

        levels.push_back({level, current_level_nodes});
        level++;                             // ask for the next level
    }
    return levels;
}

// Switched-off attempt 2: tries to special-case a tree with no left subtree.
// It uses `int i` in the backward loops, so it would not crash, but it still
// prints "first/last node of each level", which is not the outer edge.
/*
void print_outer_nodes(Node* root) {
    if(root == NULL) {
        return;
    }

    vector<pair<int, vector<int>>> levels = all_nodes_at_all_levels(root);
    if(levels.empty()) {
        return;
    }

    vector<int> result;
    bool isRightSideTree = false;

    if(root->left == NULL && root->right != NULL) {
        isRightSideTree = true;
    }

    if(isRightSideTree) {
        // Go bottom to top for right-side heavy trees too
        for(int i = levels.size()-1; i >= 0; i--) {
            if(i == 0 || levels[i].second.size() == 1) {
                result.push_back(levels[i].second[0]);
            } else {
                result.push_back(levels[i].second.back());
            }
        }
    } else {
        // Bottom to top on left side
        for(int i = levels.size()-1; i >= 0; i--) {
            result.push_back(levels[i].second[0]);
        }

        // Top to bottom on right side (excluding root)
        for(size_t i = 1; i < levels.size(); i++) {
            if(levels[i].second.size() > 1) {
                result.push_back(levels[i].second.back());
            }
        }
    }

    // Print result
    for(size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i < result.size() - 1) cout << " ";
    }
}
*/


// Switched-off attempt 1: first node of every level bottom-up, then the last
// node of every level top-down (the no_left_tree branch pushes some values twice).
/*

void print_outer_nodes(Node* root){
    if(root == NULL){
        return;
    }

    vector<pair<int, vector<int>>> levels = all_nodes_at_all_levels(root);
    if(levels.empty()){
        return;
    }

    vector<int> result;


    bool no_left_tree = false;

    if(root->left == NULL && root->right != NULL){
        no_left_tree = true;
    }

    if(no_left_tree){
        for(int i=levels.size()-1; i>=0; i--){
            if(i==0 || levels[i].second.size() == 1){
                result.push_back(levels[i].second[0]);
            }
            result.push_back(levels[i].second[0]);
        }
    }



    for(int i=levels.size()-1; i>=0; i--){
        result.push_back(levels[i].second[0]);
    }

    for(int i=1; i<levels.size(); i++){
        if(levels[i].second.size() > 1){
            result.push_back(levels[i].second[levels[i].second.size() - 1]);
        }
    }


    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
}


*/

// The active attempt: first node of each level (bottom-up), then the last
// node of each level below the root (top-down).
void print_outer_nodes(Node* root) {
    if(root == NULL) {
        return;                              // empty tree: nothing to print
    }

    vector<pair<int, vector<int>>> levels = all_nodes_at_all_levels(root);
    if(levels.empty()) {
        return;
    }

    vector<int> result;                      // values to print, in order

    // Handle leaf nodes first
    // (a copy of the values on the deepest level)
    vector<int> leafLevel = levels[levels.size()-1].second;

    // Go bottom to top on left side
    // BUG (see the top comment): size_t can never be negative, so i >= 0 is
    // always true and this loop runs past index 0. Fix: use `int i`.
    for(size_t i = levels.size()-1; i >= 0; i--) {
        // Only add if it's a left boundary node (first in level)
        if(i == levels.size()-1) {
            // For leaf level, only add the leftmost leaf
            result.push_back(leafLevel[0]);
        } else {
            result.push_back(levels[i].second[0]);   // first value on level i
        }
    }

    // Then go top to bottom on right side (excluding root)
    // (never reached, because the loop above crashes first)
    for(size_t i = 1; i < levels.size(); i++) {
        if(levels[i].second.size() > 1) {
            result.push_back(levels[i].second.back());   // back() = last element
        }
    }

    // Print result
    // (values separated by single spaces, no space after the last one)
    for(size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i < result.size() - 1) cout << " ";
    }
}

int main()
{
    // Write your code here
    Node* root = input_tree();               // build the tree
    int X;
    cin >> X;                                // BUG: the problem gives no X; this read is not needed

    print_outer_nodes(root);                 // crashes (see the top comment)

    return 0;                                // not reached when the crash above happens
}
