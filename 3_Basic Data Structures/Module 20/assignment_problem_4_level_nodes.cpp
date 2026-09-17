/*

Level Nodes

Problem Statement

You will be given a binary tree as input in level order. Also you will be given a 
level . You need to print all the node's values in that level from left to right. 
Assume that level starts from .

For example:
If X = 2, then the output for the above tree will be: 40 50 60

Note: If the level X is not a valid level, the print "Invalid".

Input Format

Input will contain the binary tree in level order.  means there is no node available.

Constraints

1. 1<= Maximum number of nodes <= 10^5 
2. 1<= Node's value <= 1000 
3. 0 <= X <= 10^5

Output Format

Output all the node's values in level X.

Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
0

Sample Output 0
10

Sample Input 1
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
1

Sample Output 1
20 30

Sample Input 2
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
2

Sample Output 2
40 50 60

Sample Input 3
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
3

Sample Output 3
Invalid


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

vector<int> level_nodes(Node* root, int X) {
    vector<int> ans;
    queue<pair<Node*, int>> q;
    if(root){
        q.push({root, 0});
    }

    while(!q.empty()){
        pair<Node*, int> parent = q.front();
        q.pop();

        Node* node = parent.first;
        int level = parent.second;

        if(level == X){
            ans.push_back(node->val);
        }

        if(node->left){
            q.push({node->left, level + 1});
        }

        if(node->right){
            q.push({node->right, level + 1});
        } 
    }
    if(ans.empty()){
        ans.push_back(-999);
    }
    return ans;
}

int main()
{
    // Write your code here
    Node* root = input_tree(); 

    int X;
    cin >> X;

    vector<int> ans = level_nodes(root, X);

    if(ans.size() == 1 && ans[0] == -999){
        cout << "Invalid" << endl;
    } else {
        for(int val : ans){
            cout << val << " ";
        }
    }
    
    return 0;
}