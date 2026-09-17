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
        int size = 0;

        void push(int val){ // O(1)
            size++;
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
            size--;
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
            return size; // O(1)
        }

        bool empty(){
            return size==0; // O(1)
            // return head==NULL; // O(1)
        }
};


int main(){
    myStack s;

    // get the input for stack
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s.push(x);
    }

    // print the stack
    while(s.empty() == false){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;    
}

