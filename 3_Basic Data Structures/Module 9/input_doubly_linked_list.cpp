// Read a doubly linked list from input - and a `return;` where a `break;` was meant.
//
// Up to now the list was typed into the source by hand. Here it is built from
// whatever the user types: read numbers until -1 arrives, appending each one at
// the tail, then print the result.
//
// It does not work. As written it does not even compile: `main` has a bare
// `return;`, which is not allowed in a function that returns `int`. And the
// idea behind that line is wrong too - `return` leaves the whole program
// instead of just the loop, so nothing would ever be printed. The exact line
// is marked in `main` below.
//
// This file also carries the full set of list functions, because every later
// program in the module needs them. Each one gets the short version here and is
// taught properly in its own file - the comments say which.

#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>   // std::vector (a resizable array) - not used in this file
#include <algorithm>   // sort, reverse, swap, max, min ... - not used in this file
#include <string>   // std::string - not used in this file
using namespace std;   // lets us write cout, list ... instead of std::cout, std::list ...

// Node and the two print walks are unchanged from print_doubly_link_list.cpp.
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

// `Node* &head` - note the `&`. The printing functions took a plain `Node* head`,
// a copy of the pointer, which was enough because they only read the list. These
// functions move the ends of the list, so they need the caller's own `head` and
// `tail` variables, not copies. Without the `&`, `head = newNode` would change a
// copy inside the function and `main` would never see the new list.
//
// Put the new node in front. Full version: insert_at_head_doubly_linked_list.cpp.
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){          // empty list: the one node is both ends
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
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
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){          // first value ever read: it is head and tail at once
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    tail->next = newNode;    // old last box -> new box
    newNode->prev = tail;    // old last box <- new box
    tail = newNode;          // the new box is the last one now
}

// Insert at an index. Full version: insert_at_any_position_doubly_linked_list.cpp.
void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    // (For pos 0 and for an append this node is not used - the helper makes
    // its own - so it simply leaks. Harmless in a short program.)
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(pos==0){   // index 0 has no node before it
        insert_at_head(head, tail, val);   // index 0 = insert at the head
        return;   // leave the function now
    }
    Node* tmp = head;   // walker from the first node
    for(int i=1; i<pos; i++){    // walk to the node at index pos-1
        tmp = tmp->next;   // one node forward
    }
    if(tmp->next == NULL){       // tmp is the last node, so this is an append
        insert_at_tail(head, tail, val);   // nothing after tmp = insert at the tail
        return;   // leave the function now
    }
    newNode->next = tmp->next;   // the four middle links, in the safe order
    tmp->next->prev = newNode;   // old next node points back to the new node
    tmp->next = newNode;   // node before points forward to the new node
    newNode->prev = tmp;   // new node points back to the node before
}

// Remove the first node. Full version: delete_at_head_doubly_linked_list.cpp.
void delete_at_head(Node* &head, Node* & tail){
    if(head==NULL){   // empty list?
        return;   // leave the function now
    }
    if(head->next == NULL){   // only one node?
        delete head;   // free the only node
        // BUG: the line below is commented out, but it is needed. `delete` gives
        // the memory back but does not touch the pointer, so `head` keeps the old
        // address and is now a dangling pointer - using it is undefined behaviour.
        // Fix: remove the `//` (delete_at_head_doubly_linked_list_p.cpp does).
        // head = NULL;

        tail = NULL;   // no nodes left, so no last node
        return;   // leave the function now
    }
    Node* deleteNode = head;   // keep hold of the node before losing sight of it
    head = head->next;   // the second node becomes the first
    head->prev = NULL;         // the new first node has nothing behind it
    delete deleteNode;   // free the removed node
}

// Remove the last node. Full version: delete_at_tail_doubly_linked_list.cpp.
void delete_at_tail(Node* &head, Node* &tail){
    Node* deleteNode = tail;   // save the last node before tail moves
    if(head == tail){          // one node only (also true when both are NULL)
        delete deleteNode;   // free the removed node
        head = NULL;   // `delete` does not blank the pointer, so do it here
        tail = NULL; // Also needed, for the same reason as `head = NULL` above:
        // `delete` frees the memory but leaves the pointer aimed at it.
        return;   // leave the function now
    }
    tail = tail->prev;         // this is why `prev` earns its keep: O(1), no walk
    tail->next = NULL;   // nothing after the new last node
    delete deleteNode;   // free the removed node
}

// Remove the node at an index. Full version:
// delete_at_any_position_doubly_linked_list.cpp - which also explains why the
// `tmp->next == NULL` test below is one node too close and can crash.
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
    if(tmp->next == NULL){
        delete_at_tail(head, tail);   // victim is the last node
        return;   // leave the function now
    }
    Node* deleteNode = tmp->next;   // the victim
    tmp->next = tmp->next->next;   // step over the victim
    tmp->next->prev = tmp;         // and close the gap from the other side
    delete deleteNode;   // free the removed node
}

// main: read values until -1 into the list, then print it.
int main(){
    // An empty list is two NULL pointers. insert_at_tail turns the first value
    // into both head and tail, so nothing here has to be a special case.
    Node* head = NULL;   // first node (none yet: the list starts empty)
    Node* tail = NULL;   // last node (none yet)

    int val;   // holds each number as it is read
    while(true){                 // no count is given, so read until a signal value
        cin >> val;   // read the next integer
        if(val==-1){   // -1 marks the end of input
            // BUG: `return;` with no value is not allowed in `int main`, so g++
            // stops with "return-statement with no value, in function returning
            // 'int'". And even `return 0;` would leave `main` altogether, so
            // `print_forward` below would never run. Fix: `break;`, which leaves
            // only the loop.
            return;   // leave the function now
        }
        insert_at_tail(head, tail, val);   // append, keeping the input order
    }

    print_forward(head);   // would print 10 20 30 once the `return;` becomes `break;`

    return 0;   // 0 = the program ended normally
}
