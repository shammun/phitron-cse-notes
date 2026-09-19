// Practice copy of insert_at_any_position_doubly_linked_list.cpp.
// The functions are identical (same four links, same order, same early
// `new Node` leak); only the demo is shorter, and its last call shows the
// append case that the original never reached.

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
    if(pos == 0){                 // no node before index 0 - that is a head insert
        insert_at_head(head, tail, val);
        return;
    }

    Node* tmp = head;
    for(int i=1; i<pos; i++){     // pos-1 steps, so `tmp` lands on index pos-1
        tmp = tmp->next;
    }

    if(tmp->next == NULL){        // `tmp` is the last node: this is an append,
        insert_at_tail(head, tail, val);   // and `tail` has to move as well
        return;
    }

    newNode->next = tmp->next;    // the two lines that mention the old next node
    tmp->next->prev = newNode;    // must come first - after the next line it is
    tmp->next = newNode;          // no longer reachable through `tmp`
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

    print_forward(head);                        // 10 20 30

    insert_at_tail(head, tail, 100);
    print_forward(head);                        // 10 20 30 100

    insert_at_any_position(head, tail, 2, 200); // middle case
    print_forward(head);                        // 10 20 200 30 100

    insert_at_any_position(head, tail, 0, 500); // head case
    print_forward(head);                        // 500 10 20 200 30 100

    // Index 6 on a list of size 6 means "one past the last node", which is a
    // legal place to insert: the walk stops on the last node, `tmp->next` is
    // NULL, and insert_at_tail takes over. Valid indexes here are 0 through 6.
    insert_at_any_position(head, tail, 6, 600);
    print_forward(head);                        // 500 10 20 200 30 100 600

    return 0;
}
