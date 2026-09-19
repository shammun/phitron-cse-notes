/*

Binary search tree: looking a value up

A binary search tree (BST) is an ordinary binary tree with one extra promise:

    for every node, every value in its LEFT subtree is smaller,
                    and every value in its RIGHT subtree is bigger.

The promise holds for the whole subtree, not just the two direct children.

That one rule turns a tree into binary search. At each node you compare the
value you want with the value you are standing on. Smaller means it can only
be on the left, so the entire right subtree is thrown away without looking at
it; bigger means the opposite. Every step halves the work in a balanced tree,
so a search costs O(h) -- h being the height, about log2(n) when the tree is
balanced -- instead of the O(n) of searching a plain binary tree.

(Binary search on an array needed the array to be sorted. Here the sorting is
built into the shape of the tree, and each step is a pointer hop instead of an
index calculation.)

BUG: the Node constructor says `this->val;` instead of `this->val = val;`. The
line is legal C++ -- it just reads the member and throws the result away -- so
it compiles, but every node keeps whatever junk was in memory. The search then
compares against garbage and prints `Not Found` even for a value that is in
the tree. Fix that one line and the sample prints `Found`. The code is left
unchanged here so the mistake stays visible.

*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Node{
    public:
        int val;
        Node* left;    // smaller values live on this side
        Node* right;   // bigger values live on this side

    Node(int val){
        this->val;         // BUG: does nothing. Should be `this->val = val;`
        this->left = NULL;
        this->right = NULL;
    }
};

/* Read a tree level by level (Module 18's input_tree).
   First number: the root. Then, for every node taken out of the queue, two
   numbers -- its left child and its right child -- with -1 meaning "none".
   Only real children go back into the queue, so only they get a line of
   their own later. Nothing here checks the BST rule: the input is trusted
   to already be a search tree. */
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

bool search(Node* root, int val){
    // Walked off the end of the tree. If the value were in the tree, the
    // comparisons below would have led somewhere else, so it is not here.
    if(root == NULL){
        return false;
    }
    // Standing on it.
    if(root->val == val){
        return true;
    }

    // The BST promise decides the direction, and only one side is ever
    // searched. `val` is smaller than this node, so every value on the right
    // is bigger than `val` too -- that whole half can be skipped. Bigger
    // means the mirror image.
    if(val < root->val){
        return search(root->left, val);
    } else{
        return search(root->right, val);
    }
}

int main(){
    Node* root = input_tree();
    int val;
    cin >> val;

    // For the tree 20 / 10 30 / 5 15 25 40, searching 15 walks
    // 20 (smaller, go left) -> 10 (bigger, go right) -> 15, three steps for
    // seven nodes. Searching 27 walks 20 -> 30 -> 25 -> NULL: Not Found.
    if(search(root, val)){
        cout << "Found\n";
    } else{
        cout << "Not Found\n";
    }

    return 0;
}
