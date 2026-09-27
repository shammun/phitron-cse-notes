/*

Binary search tree: inserting a value

Insert walks exactly the same path as search (BST_search.cpp): smaller means
go left, bigger means go right. The only difference is what happens at the
end. Search stops at NULL and reports failure; insert stops one step earlier,
at the node whose child pointer is NULL, and hangs the new node there.

So a new value always arrives as a leaf, and it lands in the one place where
the BST promise still holds -- because the path it walked is precisely the
path a later search for it will walk.

Cost: O(h). Worth knowing: inserting already-sorted values makes every new
node go the same way, and the tree degenerates into a chain with h = n. That
is the problem array_to_BST.cpp solves.

This file reads a ready-made BST level by level (the `input_tree` of Module
18), inserts one value, and prints the tree level by level so you can see
where the new node landed.

*/

#include <iostream>     // cin and cout
#include <queue>        // STL queue, for level order
#include <utility>      // pair (not used here)
#include <vector>       // vector (not used here)
using namespace std;    // write cout, queue ... without std::

// One node of the BST: a value and two child pointers (NULL = no child).
class Node{
    public:
        int val;      // the value stored here
        Node* left;   // smaller than val
        Node* right;  // bigger than val

    // Constructor, runs on `new Node(x)`: store x, no children yet.
    Node(int val){
        this->val = val;   // (BST_search.cpp is missing this line -- its bug)
        this->left = NULL;     // no left child yet
        this->right = NULL;    // no right child yet
    }
};

// Level-order input, -1 for a missing child. Same helper as in Module 18.
// (Root first; then for each real node, in queue order, its left and right child.)
Node* input_tree(){
    int val;
    cin >> val;                 // the root
    Node* root;

    if(val == -1){
        root = NULL;            // empty tree
    } else{
        root = new Node(val);   // `new` builds the node on the heap, returns its address
    }

    queue<Node*> q;             // nodes whose children are still to be read
    if(root){                   // a pointer is "true" when it is not NULL
        q.push(root);
    }

    // One pass reads one node's two children.
    while(!q.empty()){
        Node* p = q.front();    // oldest waiting node
        q.pop();

        int l, r;
        cin >> l >> r;          // its left and right child values (-1 = none)

        Node* myLeft;
        Node* myRight;

        if(l == -1){
            myLeft = NULL;
        } else{
            myLeft = new Node(l);
        }

        if(r == -1){
            myRight = NULL;
        } else{
            myRight = new Node(r);
        }

        p->left = myLeft;       // attach the children (-> = member through a pointer)
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

// Print the tree level by level (breadth-first).
void level_order(Node* root){
    queue<Node *> q; // Create a queue to store nodes in level order traversal order
    q.push(root); // Push the root node into the queue
    // Careful: root is pushed without a NULL check, so an empty tree (a
    // first input number of -1) would crash on `f->val` below.

    // One pass prints one node; stops when nothing is waiting.
    while(!q.empty()){
        Node* f = q.front();    // oldest waiting node
        q.pop();
        cout << f->val << " "; // Print the value of the current node
        // Children join the back of the queue, so the whole of this level is
        // printed before any of the next one.
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}

/* `Node* & root` -- a reference to the caller's pointer, not a copy. That is
   what lets the first `if` below create the tree itself: assigning to `root`
   changes the caller's variable. Without the `&` the new node would be
   attached to a local copy and lost. */
void insert(Node* & root, int val){
    // Empty tree (or empty subtree): the value becomes the node here.
    if(root == NULL){
        root = new Node(val);
    }
    // Smaller than this node, so it belongs somewhere on the left.
    if(val < root->val){
        // The spot is free: hang the new leaf here and stop.
        if(root->left == NULL){
            root->left = new Node(val);
        } else{
            // Occupied, so keep walking down the same side.
            insert(root->left, val);
        }
    }

    // Bigger: the mirror image on the right.
    if(val > root->val){
        if(root->right == NULL){
            root->right = new Node(val);
        } else {
            insert(root->right, val);
        }
    }

    // A value equal to root->val matches neither `<` nor `>`, so nothing
    // happens: duplicates are quietly ignored. (After the first `if` created
    // the node, `val` equals `root->val`, so both tests fail there too and
    // the function simply ends.)
}

int main(){
    Node* root = input_tree();  // read the ready-made BST
    int val;
    cin >> val;                 // the value to insert

    insert(root, val);          // root is passed by reference, so an empty tree gets its root here
    // Printing level by level shows where the value went. Inserting 13 into
    // 20 / 10 30 / 5 15 25 40 gives `20 10 30 5 15 25 40 13`: 13 is last
    // because it walked 20 -> left to 10 -> right to 15 -> left, landing on
    // a new fourth level.
    level_order(root);
    // No `return 0;`: in main (only there) it may be left out; main then returns 0.
}
