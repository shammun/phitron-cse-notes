// Practice copy of delete_at_head_doubly_linked_list.cpp - with the one-node
// case fixed. This version sets `head = NULL` after deleting the last node
// instead of leaving it commented out, so an emptied list really is two NULL
// pointers rather than one NULL and one dangling pointer. Everything else, and
// the whole demo, is the same.

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
    if(pos==0){
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

void delete_at_head(Node* &head, Node* &tail){
    if(head == NULL){       // empty list: nothing to do, and nothing safe to read
        return;
    }

    // One node only. The list becomes empty, so both ends are blanked - `delete`
    // frees the memory but would leave both pointers aimed at it. This is the
    // line the original file left commented out.
    if(head->next == NULL){
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node* deleteNode = head;   // save it before `head` moves away from it
    head = head->next;
    head->prev = NULL;         // the new first node has nothing behind it now
    delete deleteNode;
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    print_forward(head); // 10 20 30
    // print_backward(tail);

    insert_at_tail(head, tail, 100);

    print_forward(head); // 10 20 30 100

    insert_at_tail(head, tail, 100); //  10 20 30 100 100

    print_forward(head);

    insert_at_any_position(head, tail, 2, 200); // 10 20 200 30 100 100

    print_forward(head);

    insert_at_any_position(head, tail, 0, 300); // 300 10 20 200 30 100 100

    print_forward(head);

    insert_at_any_position(head, tail, 5, 400); // 300 10 20 200 30 400 100 100

    print_forward(head);

    delete_at_head(head, tail); // 10 20 200 30 400 100 100

    print_forward(head); // 10 20 200 30 400 100 100

    delete_at_head(head, tail); // 20 200 30 400 100 100

    print_forward(head); // 20 200 30 400 100 100

    return 0;
}
