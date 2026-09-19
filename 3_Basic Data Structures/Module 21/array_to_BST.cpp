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

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Level-order tree input with -1 for a missing child. Unused in this file.
Node* input_tree(){
    int val;
    cin >> val;
    Node* root;

    if(val == -1){
        root = NULL;
    } else{
        root = new Node(val);
    }

    queue<Node*> q;
    if(root){
        q.push(root);
    }

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

        p->left = myLeft;
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

void level_order(Node* root){
    queue<Node *> q; // Create a queue to store nodes in level order traversal order
    q.push(root); // Push the root node into the queue

    while(!q.empty()){
        Node* f = q.front();
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
void insert(Node* & root, int val){
    if(root == NULL){
        root = new Node(val);
    }
    if(val < root->val){
        if(root->left == NULL){
            root->left = new Node(val);
        } else{
            insert(root->left, val);
        }
    }

    if(val > root->val){
        if(root->right == NULL){
            root->right = new Node(val);
        } else {
            insert(root->right, val);
        }
    }
}

/* Build a BST from the sorted slice a[start..end]. `size` is not used; the
   slice is described entirely by start and end. */
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
    Node* leftroot = convert(a, size, start, mid-1);
    Node* rightroot = convert(a, size, mid+1, end);
    root->left = leftroot;
    root->right = rightroot;
    return root;
}


int main(){
    int n;
    cin >> n;
    int a[n];

    // Read the values. They must arrive in increasing order.
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // 0 and n-1 are the first and last index -- the whole array as one slice.
    Node* root = convert(a, n, 0, n-1);

    // insert(root, val);
    // For 1 2 3 4 5 6 7 the level order is `4 2 6 1 3 5 7`: 4 is the middle
    // of the whole array, 2 and 6 the middles of the halves, and the rest are
    // leaves. Height 3 instead of the 7 that one-by-one inserting would give.
    level_order(root);
}
