// Practice copy of insert_at_head_doubly_linked_list.cpp.
// Same function, same three links; the demo inserts 5 instead of 100 and the
// commented-out backward print was left out. See the original for the reasoning.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

void print_forward(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_backward(Node* tail){
    Node* tmp = tail;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){       // empty list: the new node is both ends at once
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;   // 5 -> 10
    head->prev = newNode;   // 5 <- 10
    head = newNode;         // move `head` last, while 10 is still reachable
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    print_forward(head);   // 10 20 30

    insert_at_head(head, tail, 5);

    print_forward(head);   // 5 10 20 30

    return 0;
}
