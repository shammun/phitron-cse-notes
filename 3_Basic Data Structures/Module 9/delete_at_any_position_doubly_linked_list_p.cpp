// Practice copy of delete_at_any_position_doubly_linked_list.cpp, with its
// two bugs fixed: `head = NULL;` is set after deleting the only node, and the
// last-node test is `tmp->next->next == NULL`. So this demo runs to the end.
//
// Delete the node at any index of a doubly linked list.
//
// The program builds 10 <-> 20 <-> 30 by hand, grows and shrinks it with all
// the insert and delete functions of this module, and prints the list after
// every step. The new function here is delete_at_any_position.
//
// To remove the node at index `pos` we stand on the node BEFORE it (index
// pos-1), then fix two arrows so the neighbours skip the victim:
//     before:  A <-> victim <-> C
//     after :  A <-> C            (A->next = C, and C->prev = A)
// and only then `delete` the victim. Index 0 (no node before it) and the last
// index (no node after it) are handed to delete_at_head / delete_at_tail.
//
#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>   // std::vector (a resizable array) - not used in this file
#include <algorithm>   // sort, reverse, swap, max, min ... - not used in this file
#include <string>   // std::string - not used in this file
using namespace std;   // lets us write cout, list ... instead of std::cout, std::list ...

class Node {   // one node: a value plus links to the next AND the previous node
    public:   // members below are usable from outside the class
        int val;   // the value this node carries
        Node* next;   // address of the node after this one (NULL = none)
        Node* prev;   // address of the node before this one (NULL = none)

    Node(int val) {   // constructor: runs on `new Node(x)`
        this->val = val;   // `this->val` = the member, plain `val` = the parameter
        this->next = NULL;   // not linked to anything yet
        this->prev = NULL;   // not linked to anything yet
    }
};

void print_forward(Node* head){   // print from the first node to the last, on one line
    Node* tmp = head;   // walker from the first node
    while(tmp != NULL){   // stop after walking off the end
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->next;   // one node forward
    }
    cout << endl;   // end the line (endl = newline + flush)
}

void print_backward(Node* tail){   // print from the last node back to the first, on one line
    Node* tmp = tail;   // walker, starting at the last node
    while(tmp != NULL){   // stop after walking off the end
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->prev;   // step one node backward
    }
    cout << endl;   // end the line (endl = newline + flush)
}

// Put a new node in front of the first node - O(1).
// `Node* &head` = a REFERENCE to the caller's pointer (not a copy), so
// when this function moves head/tail, main's own head/tail move too.
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    newNode->next = head;   // new node points forward to the old first node
    head->prev = newNode;   // old first node points back to the new node
    head = newNode;   // the new node is the first node now
}

// Hang a new node after the last node - O(1), because `tail` is already known.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    tail->next = newNode;   // old last node points forward to the new node
    newNode->prev = tail;   // new node points back to the old last node
    tail = newNode;   // the new node is the last node now
}

// Insert `val` so that it ends up at index `pos` (0-based). O(pos) for the walk.
// Assumes 0 <= pos <= size. (For pos 0 and for an append, `newNode` is not
// used - the helper makes its own - so it leaks; harmless in a short demo.)
void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(pos==0){   // index 0 has no node before it
        insert_at_head(head, tail, val);   // index 0 = an insert at the head
        return;   // leave the function now
    }
    Node* tmp = head;   // walker from the first node
    for(int i=1; i<pos; i++){   // stop on index pos-1 (the node before the spot)
        tmp = tmp->next;   // one node forward
    }
    if(tmp->next == NULL){   // tmp is the last node?
        insert_at_tail(head, tail, val);   // then this is really an append
        return;   // leave the function now
    }
    newNode->next = tmp->next;   // new node points forward to the old next node
    tmp->next->prev = newNode;   // old next node points back to the new node
    tmp->next = newNode;   // node before points forward to the new node
    newNode->prev = tmp;   // new node points back to the node before
}

// Remove the first node - O(1).
void delete_at_head(Node* &head, Node* & tail){
    if(head==NULL){   // empty list?
        return;   // leave the function now
    }
    if(head->next == NULL){   // only one node?
        delete head;   // free the only node
        // `delete` does not set `head` to NULL by itself - it would keep the old
        // (now freed) address - so both ends are blanked by hand.
        head = NULL;   // no nodes left; `delete` does not do this for us
        tail = NULL;   // no nodes left, so no last node
        return;   // leave the function now
    }
    Node* deleteNode = head;   // save the first node before head moves
    head = head->next;   // the second node becomes the first
    head->prev = NULL;   // nothing before the new first node
    delete deleteNode;   // free the removed node (`delete` undoes `new`)
}

// Remove the last node - O(1): `tail->prev` gives the new last node with no walk.
void delete_at_tail(Node* &head, Node* &tail){
    Node* deleteNode = tail;   // save the last node before tail moves
    if(head == tail){   // only one node?
        delete deleteNode;   // free the removed node (`delete` undoes `new`)
        head = NULL;   // no nodes left; `delete` does not do this for us
        tail = NULL; // needed: `delete` frees the node but leaves `tail` holding
        // its old address, so without this line `tail` would dangle
        return;   // leave the function now
    }
    tail = tail->prev;   // the second-last node becomes the last - O(1), no walk
    tail->next = NULL;   // nothing after the new last node
    delete deleteNode;   // free the removed node (`delete` undoes `new`)
}

// Remove the node at index `pos` (0-based). O(pos) for the walk.
void delete_at_any_position(Node* &head, Node* &tail, int pos){
    if(pos == 0){   // index 0 has no node before it
        delete_at_head(head, tail);   // index 0 = delete the head
        return;   // leave the function now
    }

    Node* tmp = head;   // walker from the first node
    for(int i=1; i<pos; i++){   // stop on index pos-1 (the node before the spot)
        tmp = tmp->next;   // one node forward
    }

    // tmp is BEFORE the victim, so "the victim is the last node" means the node
    // after the victim is NULL: tmp->next->next == NULL.
    if(tmp->next->next == NULL){
        delete_at_tail(head, tail);   // remove the last node
        return;   // leave the function now
    }

    Node* deleteNode = tmp->next;   // the victim
    tmp->next = tmp->next->next;   // step over the victim
    tmp->next->prev = tmp;   // close the gap from the other side
    delete deleteNode;   // free the removed node (`delete` undoes `new`)
}

// main: build 10 <-> 20 <-> 30 by hand, then change it step by step,
// printing after each change.
int main(){
    Node* head = new Node(10);   // first node (`new` makes it on the heap and returns its address)
    Node* a = new Node(20);   // middle node
    Node* tail = new Node(30);   // last node

    head->next = a;   // 10 -> 20
    a->prev = head;   // 10 <- 20

    a->next = tail;   // 20 -> 30
    tail->prev = a;   // 20 <- 30

    print_forward(head); // 10 20 30
    // print_backward(tail);   // switched off; would print the list from tail back to head

    insert_at_tail(head, tail, 100);   // append 100

    print_forward(head); // 10 20 30 100

    insert_at_tail(head, tail, 100); //  10 20 30 100 100

    print_forward(head);   // show the list now

    insert_at_any_position(head, tail, 2, 200); // 10 20 200 30 100 100

    print_forward(head);   // show the list now

    insert_at_any_position(head, tail, 0, 300); // 300 10 20 200 30 100 100

    print_forward(head);   // show the list now

    insert_at_any_position(head, tail, 5, 400); // 300 10 20 200 30 400 100 100

    print_forward(head);   // show the list now

    delete_at_head(head, tail); // 10 20 200 30 400 100 100

    print_forward(head); // 10 20 200 30 400 100 100

    delete_at_head(head, tail); // 20 200 30 400 100 100

    print_forward(head); // 20 200 30 400 100 100

    delete_at_tail(head, tail); // 20 200 30 400 100

    print_forward(head); // 20 200 30 400 100

    delete_at_tail(head, tail); // 20 200 30 400

    print_forward(head); // 20 200 30 400

    delete_at_tail(head, tail); // 20 200 30

    print_forward(head); // 20 200 30

    delete_at_any_position(head, tail, 2); // 20 200

    print_forward(head); // 20 200

    insert_at_any_position(head, tail, 1, 300); // 20 300 200

    print_forward(head); // 20 300 200

    insert_at_any_position(head, tail, 1, 400); // 20 400 300 200

    print_forward(head); // 20 400 300 200

    delete_at_any_position(head, tail, 2); // 20 400 200
    
    return 0;   // 0 = the program ended normally
}