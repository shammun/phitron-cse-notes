#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 

class Node {
    public:
        int val;     
        Node* next;

    Node(int val) {
        this->val = val; 
        this->next = NULL;
    }
};

class myQueue{
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
            tail = newNode;
        }

        void pop(){ // O(1)
            size--;
            Node* deleteNode = head;
            head = head->next;
            delete deleteNode;
            if(head==NULL){
                tail = NULL;
            }
        }

        int front(){ // O(1)
            return head->val;
        }

        int back(){ // O(1)
            return tail->val;
        }

        int size(){ // O(1)
            return size;
        }

        bool empty(){ // O(1)
            return head == NULL;
            // return size == 0;
        }
};

int main(){
    myQueue q;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        q.push(val);
    }

    cout << q.front() << " " << q.back() << " " << q.size() <<  endl;

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}