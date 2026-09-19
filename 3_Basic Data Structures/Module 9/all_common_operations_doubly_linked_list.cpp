// Every doubly linked list operation of this module in one file - and a `main`
// that never runs its own loop.
//
// The functions are the finished versions from the files before this one, so
// they are only summarised here; each is explained in full in the file named
// after it. What is worth reading closely is `main` at the bottom: it is meant
// to read a list and print it, and it does neither.

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

// Walk from `head` along `next`.
void print_forward(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Walk from `tail` along `prev`. The reverse of the forward line, if every
// `prev` was kept correct.
void print_backward(Node* tail){
    Node* tmp = tail;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

// --- inserts: head and tail are O(1), by index is O(n) for the walk ---

void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head==NULL){              // empty list: one node is both ends
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;              // move `head` last, while the old one is in reach
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
    if(pos==0){                  // index 0 has no node before it
        insert_at_head(head, tail, val);
        return;
    }
    Node* tmp = head;
    for(int i=1; i<pos; i++){    // stop on index pos-1
        tmp = tmp->next;
    }
    if(tmp->next == NULL){       // append, so `tail` must move too
        insert_at_tail(head, tail, val);
        return;
    }
    newNode->next = tmp->next;   // both lines about the old next node come first:
    tmp->next->prev = newNode;   // after the next line it is out of reach
    tmp->next = newNode;
    newNode->prev = tmp;
}

// --- deletes ---

void delete_at_head(Node* &head, Node* & tail){
    if(head==NULL){
        return;
    }
    if(head->next == NULL){      // the last node: the list becomes empty
        delete head;
        // head = NULL;
        // Correction to an earlier note here: this line IS needed. `delete` gives
        // the memory back but leaves the pointer holding the old address, so
        // `head` becomes a dangling pointer rather than NULL.

        tail = NULL;
        return;
    }
    Node* deleteNode = head;     // save it before `head` moves
    head = head->next;
    head->prev = NULL;
    delete deleteNode;
}

void delete_at_tail(Node* &head, Node* &tail){
    Node* deleteNode = tail;     // safe to move `tail` afterwards: this holds it
    if(head == tail){            // one node only
        delete deleteNode;
        head = NULL;
        tail = NULL; // Needed as well, for the same reason: `delete` does not
        // blank the pointer, so without this `tail` would dangle.
        return;
    }
    tail = tail->prev;           // O(1) - the whole reason `prev` exists. The
    tail->next = NULL;           // singly linked version had to walk from `head`.
    delete deleteNode;
    // No empty-list guard: calling this when `tail` is NULL reads through NULL.
}

void delete_at_any_position(Node* &head, Node* &tail, int pos){
    if(pos == 0){
        delete_at_head(head, tail);
        return;
    }
    Node* tmp = head;
    for(int i=1; i<pos; i++){    // `tmp` ends up on index pos-1; the victim is
        tmp = tmp->next;         // `tmp->next`
    }
    // BUG, the same one as in delete_at_any_position_doubly_linked_list.cpp: this
    // test looks one node too close. When the victim IS the last node, `tmp` is
    // the second-last, so `tmp->next` is not NULL and the code falls through to
    // the lines below - where `tmp->next` becomes NULL and `tmp->next->prev`
    // crashes. The test should be `if(tmp->next->next == NULL)`.
    if(tmp->next == NULL){
        delete_at_tail(head, tail);
        return;
    }
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;   // step over the victim
    tmp->next->prev = tmp;         // and close the gap from the other side
    delete deleteNode;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    // BUG. `while(tail)` means "while `tail` is not NULL", and `tail` was just set
    // to NULL on the line above, so the condition is false the very first time and
    // the body never runs. Nothing is read; the list stays empty. The intended
    // loop is `while(true)`.
    while(tail){
        cin >> val;
        if(val==-1){
            // Second bug, the same as in input_doubly_linked_list.cpp: `return;`
            // leaves `main`, not the loop, so it would skip the print below even
            // if the loop did run. It should be `break;`.
            return;
        }
        insert_at_tail(head, tail, val);
    }

    // Reached, but with `head` still NULL: print_forward walks nothing and prints
    // only the `endl`, so the whole program outputs one blank line. With both
    // bugs fixed it would print `10 20 30`.
    print_forward(head);

    return 0;
}
