#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* prev;

        Node(int val){
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

        void push(int val){
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

        void pop(){
            size--;
            Node* deleteNode = tail;
            tail = tail->prev;
            delete deleteNode;
            if(tail == NULL){
                head = NULL;
                return;
            }
            tail->next = NULL;
        }

        int top(){
            return tail->val;
        }

        int size(){
            return size;
        }

        bool empty(){
            return size == 0;
        }
};

int main(){
    myStack st;

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        st.push(x);
    }

    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}