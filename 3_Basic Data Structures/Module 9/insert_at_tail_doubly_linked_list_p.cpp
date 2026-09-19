// Practice copy of insert_at_tail_doubly_linked_list.cpp.
// Same functions; the demo appends 40 and then 50 instead of 100 twice, so the
// two new values are easy to tell apart in the output.

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
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){       // empty list: one node, both ends
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;   // 30 -> 40
    newNode->prev = tail;   // 30 <- 40
    tail = newNode;         // last, while `tail` still names the old end
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;

    print_forward(head);          // 10 20 30

    insert_at_tail(head, tail, 40);
    print_forward(head);          // 10 20 30 40

    insert_at_tail(head, tail, 50);
    print_forward(head);          // 10 20 30 40 50
    // print_backward(tail) here would give 50 40 30 20 10 - every prev is set.

    return 0;
}
