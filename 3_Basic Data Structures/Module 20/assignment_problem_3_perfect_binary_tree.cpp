/*

Problem Statement

You will be given a binary tree as input in level order. You need to tell if the 
binary tree is perfect or not. A binary tree is called perfect if all leaf nodes 
are at the maximum depth of the tree, and the tree is completely filled with no gaps.


Also there is formula available to tell if a binary tree is perfect or not. The 
formula is :

Total number of nodes = 2^(max_depth) - 1

Note: Here depth is counted from 1. In the above image maximum depth is 4, so total 
number of nodes are 2^4 - 1. So there should be 15 nodes to call it a perfect binary 
tree.



Input Format

Input will contain the binary tree in level order. -1 means there is no node available.

Constraints

1. 1<= Maximum number of nodes <= 10^5 
2. 1<= Node's value <= 1000

Output Format

Output YES if the tree is perfect, NO otherwise.

Sample Input 0

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 0

YES

Sample Input 1

10 20 30 40 -1 60 -1 -1 -1 -1 -1

Sample Output 1

NO

Sample Input 2

10 20 -1 -1 -1

Sample Output 2

NO

Sample Input 3

10 20 30 40 50 60 70 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 3

YES
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>


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

int count_nodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);
    return l + r + 1;
}

int max_depth(Node* root){
    if(root == NULL){
        return 0;
    }

    int l = max_depth(root->left);
    int r = max_depth(root->right);

    return max(l, r) + 1;
}

bool is_perfect(Node* root){
    if(root == NULL){
        return true;
    }
    int total_nodes = count_nodes(root);
    int max_depth_of_tree = max_depth(root);

    int total_nodes_for_perfect_tree = pow(2, max_depth_of_tree) - 1;

    return total_nodes == total_nodes_for_perfect_tree;
}

int main()
{
    // Write your code here
    Node* root = input_tree(); 

    bool ans = is_perfect(root);

    if(ans){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    
    return 0;
}