#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>


using namespace std;


class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this->val = val;
            this->next = next;
        }
};

class myQueue{
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
        tail = newNode;
    }    

    void pop(){
        size--;
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        if(head == NULL){
            tail = NULL;
        }
    }

    int front(){
        return head->val;
    }

    int back(){
        return tail->val;
    }

    int size(){
        return size;
    }

    bool empty(){
        return head == NULL;
    }
};

int main(){
    myQueue q;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        q.push(x);
    }

    return 0;
}