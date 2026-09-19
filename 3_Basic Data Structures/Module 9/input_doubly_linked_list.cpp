// Read a doubly linked list from input - and a `return;` where a `break;` was meant.
//
// Up to now the list was typed into the source by hand. Here it is built from
// whatever the user types: read numbers until -1 arrives, appending each one at
// the tail, then print the result.
//
// It does not work. The loop leaves the program instead of leaving the loop, so
// nothing is ever printed. The exact line is marked in `main` below.
//
// This file also carries the full set of list functions, because every later
// program in the module needs them. Each one gets the short version here and is
// taught properly in its own file - the comments say which.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Node and the two print walks are unchanged from print_doubly_link_list.cpp.
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

// `Node* &head` - note the `&`. The printing functions took a plain `Node* head`,
// a copy of the pointer, which was enough because they only read the list. These
// functions move the ends of the list, so they need the caller's own `head` and
// `tail` variables, not copies. Without the `&`, `head = newNode` would change a
// copy inside the function and `main` would never see the new list.
//
// Put the new node in front. Full version: insert_at_head_doubly_linked_list.cpp.
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head==NULL){          // empty list: the one node is both ends
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;    // forward link
    head->prev = newNode;    // the matching backward link
    head = newNode;          // the new node is now the first one
}

// Put the new node at the end. This is the one the input loop below uses, and
// the reason a `tail` pointer is worth keeping: no walk, just three assignments,
// so it costs the same whether the list holds 3 nodes or 3000.
// Full version: insert_at_tail_doubly_linked_list.cpp.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head==NULL){          // first value ever read: it is head and tail at once
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;    // old last box -> new box
    newNode->prev = tail;    // old last box <- new box
    tail = newNode;          // the new box is the last one now
}

// Insert at an index. Full version: insert_at_any_position_doubly_linked_list.cpp.
void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    Node* newNode = new Node(val);
    if(pos==0){
        insert_at_head(head, tail, val);
        return;
    }
    Node* tmp = head;
    for(int i=1; i<pos; i++){    // walk to the node at index pos-1
        tmp = tmp->next;
    }
    if(tmp->next == NULL){       // tmp is the last node, so this is an append
        insert_at_tail(head, tail, val);
        return;
    }
    newNode->next = tmp->next;   // the four middle links, in the safe order
    tmp->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
}

// Remove the first node. Full version: delete_at_head_doubly_linked_list.cpp.
void delete_at_head(Node* &head, Node* & tail){
    if(head==NULL){
        return;
    }
    if(head->next == NULL){
        delete head;
        // head = NULL;
        // Correction to an earlier note here: this line IS needed. `delete` gives
        // the memory back but does not touch the pointer, so `head` keeps the old
        // address and is now a dangling pointer - using it is undefined behaviour.
        // The practice copy delete_at_head_doubly_linked_list_p.cpp adds the line.

        tail = NULL;
        return;
    }
    Node* deleteNode = head;   // keep hold of the node before losing sight of it
    head = head->next;
    head->prev = NULL;         // the new first node has nothing behind it
    delete deleteNode;
}

// Remove the last node. Full version: delete_at_tail_doubly_linked_list.cpp.
void delete_at_tail(Node* &head, Node* &tail){
    Node* deleteNode = tail;
    if(head == tail){          // one node only (also true when both are NULL)
        delete deleteNode;
        head = NULL;
        tail = NULL; // Also needed, for the same reason as `head = NULL` above:
        // `delete` frees the memory but leaves the pointer aimed at it.
        return;
    }
    tail = tail->prev;         // this is why `prev` earns its keep: O(1), no walk
    tail->next = NULL;
    delete deleteNode;
}

// Remove the node at an index. Full version:
// delete_at_any_position_doubly_linked_list.cpp - which also explains why the
// `tmp->next == NULL` test below is one node too close and can crash.
void delete_at_any_position(Node* &head, Node* &tail, int pos){
    if(pos == 0){
        delete_at_head(head, tail);
        return;
    }
    Node* tmp = head;
    for(int i=1; i<pos; i++){
        tmp = tmp->next;
    }
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
    // An empty list is two NULL pointers. insert_at_tail turns the first value
    // into both head and tail, so nothing here has to be a special case.
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while(true){                 // no count is given, so read until a signal value
        cin >> val;
        if(val==-1){
            // BUG. `return;` leaves `main` altogether, so `print_forward` below is
            // never reached and the program prints nothing at all. The intended
            // line is `break;`, which leaves only the loop.
            // (`return;` with no value in a function returning `int` is not valid
            // C++ either - the compiler here lets it through with a warning.)
            return;
        }
        insert_at_tail(head, tail, val);   // append, keeping the input order
    }

    print_forward(head);   // would print 10 20 30 once the `return;` becomes `break;`

    return 0;
}
