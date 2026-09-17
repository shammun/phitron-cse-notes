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
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    Node* newNode = new Node(val);
    if(pos == 0){
        insert_at_head(head, tail, val);
        return;
    }

    Node* tmp = head;
    for(int i=1; i<pos; i++){
        tmp = tmp->next;
    }

    if(tmp->next == NULL){
        insert_at_tail(head, tail, val);
        return;
    }

    newNode->next = tmp->next;
    tmp->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;

    print_forward(head);

    insert_at_tail(head, tail, 100);
    print_forward(head);

    insert_at_any_position(head, tail, 2, 200);
    print_forward(head);

    insert_at_any_position(head, tail, 0, 500);
    print_forward(head);

    insert_at_any_position(head, tail, 6, 600);
    print_forward(head);

    return 0;
}