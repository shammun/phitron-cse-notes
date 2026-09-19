// Insert at the tail - the mirror image of the head insert.
//
// Everything is the same shape as insert_at_head, with `next` and `prev` swapped
// and `tail` moving instead of `head`. Because the list keeps a `tail` pointer,
// no walk is needed: the last node is already in hand.

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

// Unchanged from insert_at_head_doubly_linked_list.cpp; kept so both ends of the
// list can be used in the same program.
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

    // Empty list: the single node is the first and the last one.
    // `head == NULL` is tested rather than `tail == NULL` - on a well-kept list
    // the two are NULL together, so either test works.
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // Normal case, on 10 20 30 with val = 100:
    tail->next = newNode;   // 30 -> 100
    newNode->prev = tail;   // 30 <- 100
    tail = newNode;         // 100 is the last node now

    // `tail` is moved last, for the same reason `head` was: until this line,
    // `tail` is the only name for node 30.
    //
    // `tail` is a `Node* &`, the caller's own pointer. Without the `&` this last
    // line would move a copy, `main` would still think 30 was the end, and the
    // next append would hang 100 off 30 a second time.
    //
    // `newNode->next` stays NULL from the constructor, which is what marks the
    // new end of the list.
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
    // print_backward(tail);

    insert_at_tail(head, tail, 100);

    print_forward(head);   // 10 20 30 100

    // The same value again - a list is happy to hold duplicates, and this also
    // shows that `tail` really did move: 100 is appended after the first 100.
    insert_at_tail(head, tail, 100);

    print_forward(head);   // 10 20 30 100 100

    return 0;
}
