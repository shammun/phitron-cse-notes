/*
Take two stacks of size N and M as input and check if both of them are the same or not. 
Don’t use STL stack to solve this problem.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std; 

class Node {
    public:
        int val;     
        Node* next;
        Node* prev;

    Node(int val) {
        this->val = val; 
        this->next = NULL;
        this->prev = NULL;
    }
};

class myStack{
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int sz = 0;

        void push(int val){ // O(1)
            sz++;
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        void pop(){ // O(1)
            sz--;
            Node* deleteNode = tail;
            tail = tail->prev;
            delete deleteNode; 
            if(tail==NULL){
                head=NULL;
                return;
            }
            tail->next = NULL;
        }

        int top(){
            return tail->val; // O(1)
        }

        int size(){
            return sz; // O(1)
        }

        bool empty(){
            return sz==0; // O(1)
            // return head==NULL; // O(1)
        }
};


int main(){
    myStack s1;

    // get the input for stack
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s1.push(x);
    }

    myStack s2;
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        s2.push(x);
    }

    if(s1.size() != s2.size()){
        cout << "NO" << endl;
        return 0;
    }

    bool flag = true;
    while(!s1.empty()){
        if(s1.top() != s2.top()){
            flag = false;
            break;
        }
        s1.pop();
        s2.pop();
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}