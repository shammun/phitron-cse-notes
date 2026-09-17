/*

Sum without leaf

Problem Statement

You will be given a binary tree as input in level order. You need to output the sum of all node's values in that tree except the leaf nodes.

For example

The output for the above tree will be: 60

Input Format

Input will contain the binary tree in level order. -1 means there is no node 
available.

Constraints

1. 1<= Maximum number of nodes<= 10^5
2. 1<= Node's value <= 1000

Output Format

Output the total sum of that tree except the leaf nodes.

Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1

Sample Output 0

60

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

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

int sum_without_leaf(Node* root){
    if(!root){
        return 0;
    }
    
    queue<Node*> q;
    q.push(root);

    int sum = 0;
    while(!q.empty()){
        Node* parent = q.front();
        q.pop();

        if(parent->left || parent->right){
            sum += parent->val;
        }

        if(parent->left){
            q.push(parent->left);
        }
        if(parent->right){
            q.push(parent->right);
        }
    }

    return sum;
}

int main()
{
    // Write your code here
    Node* root = input_tree(); 
    cout << sum_without_leaf(root) << endl;
    return 0;
}