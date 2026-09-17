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


vector<pair<int, vector<int>>> all_nodes_at_all_levels(Node* root){
    vector<pair<int, vector<int>>> levels;
    int level = 0;

    while(true){
        vector<int> current_level_nodes = level_nodes(root, level);
        if(current_level_nodes[0] == -999){
            break;
        }

        levels.push_back({level, current_level_nodes});
        level++;
    }
    return levels;
}

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

void print_outer_nodes(Node* root) {
    if(root == NULL) {
        return;
    }

    vector<pair<int, vector<int>>> levels = all_nodes_at_all_levels(root);
    if(levels.empty()) {
        return;
    }

    vector<int> result;

    // Handle leaf nodes first
    vector<int> leafLevel = levels[levels.size()-1].second;
    
    // Go bottom to top on left side
    for(size_t i = levels.size()-1; i >= 0; i--) {
        // Only add if it's a left boundary node (first in level)
        if(i == levels.size()-1) {
            // For leaf level, only add the leftmost leaf
            result.push_back(leafLevel[0]);
        } else {
            result.push_back(levels[i].second[0]);
        }
    }
    
    // Then go top to bottom on right side (excluding root)
    for(size_t i = 1; i < levels.size(); i++) {
        if(levels[i].second.size() > 1) {
            result.push_back(levels[i].second.back());
        }
    }

    // Print result
    for(size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i < result.size() - 1) cout << " ";
    }
}

int main()
{
    // Write your code here
    Node* root = input_tree();
    int X;
    cin >> X;

    print_outer_nodes(root);

    return 0;
}