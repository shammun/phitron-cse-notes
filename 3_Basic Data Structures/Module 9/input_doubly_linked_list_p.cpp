// Practice copy of input_doubly_linked_list.cpp - the same program, re-typed,
// including the same `return;` bug in `main`, so it also prints nothing.
// The functions are explained in the original; each one is taught in full in its
// own file later in this module.

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

// `Node* &head` passes the caller's own pointer, so moving an end of the list
// here is visible back in `main`.
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;   // forward link, then the matching backward one
    head->prev = newNode;
    head = newNode;
}

// O(1) append: three assignments, no walk, because `tail` is already in hand.
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
    if(pos==0){                  // index 0 is just a head insert
        insert_at_head(head, tail, val);
        return;
    }
    Node* tmp = head;
    for(int i=1; i<pos; i++){    // stop on the node at index pos-1
        tmp = tmp->next;
    }
    if(tmp->next == NULL){       // nothing after tmp, so this is an append
        insert_at_tail(head, tail, val);
        return;
    }
    newNode->next = tmp->next;   // four links: two forward, two backward
    tmp->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
}

void delete_at_head(Node* &head, Node* & tail){
    if(head==NULL){
        return;
    }
    if(head->next == NULL){
        delete head;
        // head = NULL;
        // Correction to an earlier note here: this line IS needed. `delete` frees
        // the memory but leaves `head` holding the old address - a dangling
        // pointer. delete_at_head_doubly_linked_list_p.cpp has the fixed version.

        tail = NULL;
        return;
    }
    Node* deleteNode = head;
    head = head->next;
    head->prev = NULL;      // the new first node has nothing behind it
    delete deleteNode;
}

void delete_at_tail(Node* &head, Node* &tail){
    Node* deleteNode = tail;
    if(head == tail){
        delete deleteNode;
        head = NULL;
        tail = NULL; // Needed too - `delete` does not blank the pointer.
        return;
    }
    tail = tail->prev;      // `prev` hands over the new tail with no walk at all
    tail->next = NULL;
    delete deleteNode;
}

void delete_at_any_position(Node* &head, Node* &tail, int pos){
    if(pos == 0){
        delete_at_head(head, tail);
        return;
    }
    Node* tmp = head;
    for(int i=1; i<pos; i++){
        tmp = tmp->next;
    }
    if(tmp->next == NULL){  // one node too close - see the delete_at_any files
        delete_at_tail(head, tail);
        return;
    }
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    delete deleteNode;
}

int main(){
    Node* head = NULL;      // an empty list is simply two NULL pointers
    Node* tail = NULL;

    int val;
    while(true){
        cin >> val;
        if(val == -1){
            // Same bug as the original: `return;` leaves `main`, not the loop,
            // so nothing below ever runs. It should be `break;`.
            return;
        }
        insert_at_tail(head, tail, val);
    }
    print_forward(head);    // never reached as the file stands

    return 0;
}
