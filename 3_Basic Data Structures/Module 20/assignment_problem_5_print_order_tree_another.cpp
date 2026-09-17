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

Node* input_tree(){
    int val;
    cin >> val;
    Node* root;
    if(val == -1){
        root = NULL;
    } else {
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

        if(r==-1){
            myRight = NULL;
        } else {
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

void left_boundary(Node* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    if(root->left){
        left_boundary(root->left, v);
    } else if(root->right){
        left_boundary(root->right, v);
    }
    v.push_back(root->val);
}

void right_boundary(Node* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    v.push_back(root->val);
    if(root->right){
        right_boundary(root->right, v);
    } else if(root->left){
        right_boundary(root->left, v);
    }
}

void print_boundary(Node* root, vector<int> &v){
    left_boundary(root->left, v);
    v.push_back(root->val);
    right_boundary(root->right, v);

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