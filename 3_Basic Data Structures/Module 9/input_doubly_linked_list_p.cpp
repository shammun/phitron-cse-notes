// Practice copy of input_doubly_linked_list.cpp - the same program, re-typed,
// including the same `return;` bug in `main`, so it does not compile either
// (a bare `return;` is not allowed in `int main`).
// The functions are explained in the original; each one is taught in full in its
// own file in this module. Short reminders are given line by line below:
// `Node* &head` = a reference to the caller's pointer (so moves stick), `new`
// makes a node on the heap, `delete` frees it but does not set the pointer to NULL.

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

// `Node* &head` passes the caller's own pointer, so moving an end of the list
// here is visible back in `main`.
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    newNode->next = head;   // forward link, then the matching backward one
    head->prev = newNode;   // old first node points back to the new node
    head = newNode;   // the new node is the first node now
}

// O(1) append: three assignments, no walk, because `tail` is already in hand.
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

// Insert `val` so it ends up at index `pos` (0-based).
void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(pos==0){                  // index 0 is just a head insert
        insert_at_head(head, tail, val);   // index 0 = insert at the head
        return;   // leave the function now
    }
    Node* tmp = head;   // walker from the first node
    for(int i=1; i<pos; i++){    // stop on the node at index pos-1
        tmp = tmp->next;   // one node forward
    }
    if(tmp->next == NULL){       // nothing after tmp, so this is an append
        insert_at_tail(head, tail, val);   // append at the end
        return;   // leave the function now
    }
    newNode->next = tmp->next;   // four links: two forward, two backward
    tmp->next->prev = newNode;   // old next node points back to the new node
    tmp->next = newNode;   // node before points forward to the new node
    newNode->prev = tmp;   // new node points back to the node before
}

// Remove the first node.
void delete_at_head(Node* &head, Node* & tail){
    if(head==NULL){   // empty list?
        return;   // leave the function now
    }
    if(head->next == NULL){   // only one node?
        delete head;   // free the only node
        // BUG: the line below is commented out, but it is needed. `delete` frees
        // the memory but leaves `head` holding the old address - a dangling
        // pointer. Fix: remove the `//` (delete_at_head_doubly_linked_list_p.cpp does).
        // head = NULL;

        tail = NULL;   // no nodes left, so no last node
        return;   // leave the function now
    }
    Node* deleteNode = head;   // save the first node before head moves
    head = head->next;   // the second node becomes the first
    head->prev = NULL;      // the new first node has nothing behind it
    delete deleteNode;   // free the removed node
}

// Remove the last node - O(1) thanks to `prev`.
void delete_at_tail(Node* &head, Node* &tail){
    Node* deleteNode = tail;   // save the last node before tail moves
    if(head == tail){   // only one node?
        delete deleteNode;   // free the removed node
        head = NULL;   // `delete` does not blank the pointer, so do it here
        tail = NULL; // Needed too - `delete` does not blank the pointer.
        return;   // leave the function now
    }
    tail = tail->prev;      // `prev` hands over the new tail with no walk at all
    tail->next = NULL;   // nothing after the new last node
    delete deleteNode;   // free the removed node
}

// Remove the node at index `pos` (0-based).
void delete_at_any_position(Node* &head, Node* &tail, int pos){
    if(pos == 0){   // index 0 has no node before it
        delete_at_head(head, tail);   // index 0 = delete the head
        return;   // leave the function now
    }
    Node* tmp = head;   // walker from the first node
    for(int i=1; i<pos; i++){   // stop on index pos-1
        tmp = tmp->next;   // one node forward
    }
    // BUG: this test looks one node too close. When the victim is the last
    // node, `tmp` is the second-last, `tmp->next` is not NULL, and the code
    // below sets tmp->next to NULL and then reads `tmp->next->prev` -> crash.
    // Fix: if(tmp->next->next == NULL)
    if(tmp->next == NULL){  // one node too close - see the delete_at_any files
        delete_at_tail(head, tail);   // victim is the last node
        return;   // leave the function now
    }
    Node* deleteNode = tmp->next;   // the victim
    tmp->next = tmp->next->next;   // step over the victim
    tmp->next->prev = tmp;   // close the gap from the other side
    delete deleteNode;   // free the removed node
}

// main: read values until -1 into the list, then print it.
int main(){
    Node* head = NULL;      // an empty list is simply two NULL pointers
    Node* tail = NULL;   // last node (none yet)

    int val;   // each value read
    while(true){   // read until the -1 signal
        cin >> val;   // read the next integer
        if(val == -1){   // -1 marks the end of input
            // BUG: same as the original. A bare `return;` is not allowed in
            // `int main` (compile error), and even `return 0;` would leave `main`,
            // not the loop, so nothing below would run. Fix: `break;`
            return;   // leave the function now
        }
        insert_at_tail(head, tail, val);   // append at the end
    }
    print_forward(head);    // prints e.g. 10 20 30 once `return;` becomes `break;`

    return 0;   // 0 = the program ended normally
}
