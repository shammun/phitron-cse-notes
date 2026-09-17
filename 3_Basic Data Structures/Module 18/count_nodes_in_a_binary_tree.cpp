

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

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

void level_order(Node* root){
    if(root == NULL){
        cout << "No tree" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* f= q.front();
        q.pop();

        cout << f->val << " ";

        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}

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
        } else {
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

int count_nodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);
    return l + r + 1;
}

int main(){
    
    /*
    10 20 30 40 -1 50 60 -1 -1 -1 -1 -1 -1
    */

   /*
   
   Take input in this way: first insert a number (this is the root). Then go to the next line and insert
   two inputs for left and right child.

   10
   20 30
   40 -1
   50 60
   -1 -1
   -1 -1
   -1 -1
   
   */
   Node* root = input_tree();
   level_order(root);
   cout << endl;

   cout << count_nodes(root) << endl;
   
    return 0;
}
