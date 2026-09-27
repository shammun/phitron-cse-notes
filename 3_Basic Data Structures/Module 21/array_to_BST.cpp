/*

Build a balanced BST from a sorted array

Inserting sorted values one by one (insert_in_BST.cpp) is the worst thing you
can do to a BST: every value is bigger than the last, so every node hangs off
the right of the one before it and the tree becomes a chain of height n. The
search that should have cost log2(n) steps costs n.

Building the tree from the array directly avoids that. Take the MIDDLE element
as the root. Everything to its left in the array is smaller, everything to its
right is bigger -- which is exactly the BST promise -- and the two halves are
the same size, so neither side of the tree gets taller than the other. Then do
the same thing to each half.

    convert(start, end)   builds a tree out of a[start..end]
      start > end         the slice is empty -> no node at all (NULL)
      otherwise           a[mid] is the root; its left child is the tree of
                          the left half, its right child the tree of the
                          right half

Cost: O(n) -- every element becomes exactly one node -- with O(log n) stack
depth for the recursion. The resulting height is about log2(n).

The array must already be sorted; nothing here sorts it. An unsorted array
still produces a tree, but one that breaks the BST rule and that search would
give wrong answers on.

`input_tree` and `insert` are carried over from the earlier files of this
module and are not used here (the call to `insert` in `main` is commented
out); `level_order` is what prints the result.

*/

#include <iostream>     // cin and cout
#include <queue>        // STL queue, for level order
#include <utility>      // pair (not used here)
#include <vector>       // vector (not used here)
using namespace std;    // write cout, queue ... without std::

// One node of the tree: a value and two child pointers (NULL = no child).
class Node{
    public:
        int val;        // the value stored here
        Node* left;     // smaller values live on this side
        Node* right;    // bigger values live on this side

    // Constructor, runs on `new Node(x)`: store x, no children yet.
    Node(int val){
        this->val = val;        // this->val = member, val = parameter
        this->left = NULL;
        this->right = NULL;
    }
};

// Level-order tree input with -1 for a missing child. Unused in this file.
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
        Node* p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

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

        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }
    }

    return root;
}

// Print the tree level by level (breadth-first). Note: no NULL check, so
// an empty tree (n = 0) would crash on f->val.
void level_order(Node* root){
    queue<Node *> q; // Create a queue to store nodes in level order traversal order
    q.push(root); // Push the root node into the queue

    // One pass prints one node; stops when nothing is waiting.
    while(!q.empty()){
        Node* f = q.front();    // oldest waiting node
        q.pop();
        cout << f->val << " "; // Print the value of the current node
        // Each node's children are pushed behind everything already waiting,
        // so a whole level is printed before the next one begins.
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}

// The insert from the previous file: walk left for smaller, right for bigger,
// hang the new node on the first free child pointer. Unused here.
// `Node* & root` is a reference to the caller's pointer, so setting root
// here changes the caller's pointer too (needed when the tree is empty).
void insert(Node* & root, int val){
    if(root == NULL){
        root = new Node(val);   // empty tree: the new node becomes the root
                                // (no return, but both ifs below are false for an equal value, so nothing else happens)
    }
    if(val < root->val){        // smaller: belongs on the left
        if(root->left == NULL){
            root->left = new Node(val);     // free spot found
        } else{
            insert(root->left, val);        // keep walking down the left
        }
    }

    if(val > root->val){        // bigger: belongs on the right
        if(root->right == NULL){
            root->right = new Node(val);
        } else {
            insert(root->right, val);
        }
    }
    // An equal value matches neither if, so duplicates are ignored.
}

/* Build a BST from the sorted slice a[start..end]. `size` is not used; the
   slice is described entirely by start and end.
   `int a[]` as a parameter is really a pointer to the first element, so the
   array is not copied. Returns the root of the new (sub)tree. */
Node* convert(int a[], int size, int start, int end){
    // start > end means the slice holds nothing, so there is no node here.
    // This is what ends the recursion under every leaf.
    if(start > end){
        return NULL;
    }
    // The middle element becomes the root of this slice. Integer division
    // rounds down, so an even-sized slice leans to the left one -- either
    // choice gives a balanced tree.
    int mid = (start + end) / 2;
    Node* root = new Node(a[mid]);
    // The array is sorted, so everything before mid is smaller and everything
    // after it is bigger: the two halves land on the correct sides by
    // construction, with no comparisons needed.
    // Each recursive call trusts convert() to return a balanced BST of its half.
    Node* leftroot = convert(a, size, start, mid-1);
    Node* rightroot = convert(a, size, mid+1, end);
    root->left = leftroot;      // hang the left half under this root
    root->right = rightroot;    // and the right half
    return root;
}


int main(){
    int n;
    cin >> n;                   // how many values
    int a[n];                   // an array whose size comes from input (a
                                // "variable-length array": a GCC extension,
                                // not standard C++; vector<int> a(n) is the portable way)

    // Read the values. They must arrive in increasing order.
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // 0 and n-1 are the first and last index -- the whole array as one slice.
    Node* root = convert(a, n, 0, n-1);

    // insert(root, val);   (switched off: there is no `val` in main, and nothing needs inserting here)
    // For 1 2 3 4 5 6 7 the level order is `4 2 6 1 3 5 7`: 4 is the middle
    // of the whole array, 2 and 6 the middles of the halves, and the rest are
    // leaves. Height 3 instead of the 7 that one-by-one inserting would give.
    level_order(root);
    // No `return 0;`: main is the one function where leaving it out is
    // allowed; it then returns 0 automatically.
}
