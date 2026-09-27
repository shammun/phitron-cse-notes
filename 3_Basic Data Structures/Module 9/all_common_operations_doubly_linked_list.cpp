// Every doubly linked list operation of this module in one file - and a `main`
// that never runs its own loop.
//
// The functions are the finished versions from the files before this one, so
// they are only summarised here; each is explained in full in the file named
// after it. What is worth reading closely is `main` at the bottom: it is meant
// to read a list and print it, and it does neither.
//
// In fact the file does not even compile: `main` contains a bare `return;`,
// and `main` returns an int, so g++ stops with "return-statement with no
// value, in function returning 'int'". See the BUG notes in `main`.
//
// Quick reminders so this file reads on its own:
//   * a doubly linked list node holds a value, `next` (the node after it) and
//     `prev` (the node before it); NULL in either means "nothing there".
//   * `head` points at the first node, `tail` at the last one.
//   * `Node* &head` in a parameter list is a REFERENCE to the caller's pointer,
//     so a function can move the caller's head/tail, not just a copy.
//   * `new Node(x)` makes a node on the heap and returns its address;
//     `delete p` gives that memory back (but does not set p to NULL).

#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>     // std::vector - not used in this file
#include <algorithm>  // sort/swap/max/min - not used in this file
#include <string>     // std::string - not used in this file
using namespace std;  // lets us write cout instead of std::cout

// One node: a value plus links to the next AND the previous node.
class Node {
    public:            // members below are usable from outside the class
        int val;       // the value this node carries
        Node* next;    // the node after this one (NULL = none)
        Node* prev;    // the node before this one (NULL = none)

    // Constructor: runs on `new Node(x)`. `this->val` is the member,
    // plain `val` is the parameter with the same name.
    Node(int val) {
        this->val = val;     // store the value
        this->next = NULL;   // not linked to anything yet
        this->prev = NULL;   // not linked to anything yet
    }
};

// Walk from `head` along `next`.
void print_forward(Node* head){
    Node* tmp = head;              // walker (a copy; head is not moved)
    while(tmp != NULL){            // stop after walking off the end
        cout << tmp->val << " ";   // print this value and a space
        tmp = tmp->next;           // one node forward
    }
    cout << endl;                  // end the line (endl = newline + flush)
}

// Walk from `tail` along `prev`. The reverse of the forward line, if every
// `prev` was kept correct.
void print_backward(Node* tail){
    Node* tmp = tail;              // walker, starts at the last node
    while(tmp != NULL){            // stops after stepping off the front (head->prev is NULL)
        cout << tmp->val << " ";
        tmp = tmp->prev;           // one node backward
    }
    cout << endl;
}

// --- inserts: head and tail are O(1), by index is O(n) for the walk ---

// New node in front of the first node.
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node; both links NULL
    if(head==NULL){              // empty list: one node is both ends
        head = newNode;
        tail = newNode;
        return;                  // done
    }
    newNode->next = head;        // new -> old first
    head->prev = newNode;        // new <- old first
    head = newNode;              // move `head` last, while the old one is in reach
}

// New node after the last node.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node; both links NULL
    if(head==NULL){              // empty list: one node is both ends
        head = newNode;
        tail = newNode;
        return;                  // done
    }
    tail->next = newNode;        // old last -> new
    newNode->prev = tail;        // old last <- new
    tail = newNode;              // the new node is the last node now
}

// New node so that it ends up at index `pos` (0-based).
void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    // Note: for pos 0 and for the append case this node is never used (the
    // helper makes its own), so it leaks - harmless in a short program.
    Node* newNode = new Node(val);
    if(pos==0){                  // index 0 has no node before it
        insert_at_head(head, tail, val);
        return;
    }
    Node* tmp = head;            // walker from the first node
    for(int i=1; i<pos; i++){    // stop on index pos-1
        tmp = tmp->next;
    }
    if(tmp->next == NULL){       // append, so `tail` must move too
        insert_at_tail(head, tail, val);
        return;
    }
    newNode->next = tmp->next;   // both lines about the old next node come first:
    tmp->next->prev = newNode;   // after the next line it is out of reach
    tmp->next = newNode;         // node before -> new
    newNode->prev = tmp;         // node before <- new
}

// --- deletes ---

// Remove the first node.
void delete_at_head(Node* &head, Node* & tail){
    if(head==NULL){              // empty list: nothing to delete
        return;
    }
    if(head->next == NULL){      // the last node: the list becomes empty
        delete head;             // free the only node
        // BUG: `head = NULL;` below is commented out. `delete` gives the memory
        // back but leaves `head` holding the old address, so `head` dangles
        // instead of being NULL. Fix: remove the `//` in front of it.
        // head = NULL;

        tail = NULL;             // no nodes left, so no last node
        return;
    }
    Node* deleteNode = head;     // save it before `head` moves
    head = head->next;           // the second node is the first now
    head->prev = NULL;           // nothing before the new first node
    delete deleteNode;           // free the old first node
}

// Remove the last node - O(1), because `tail->prev` gives the node before it.
void delete_at_tail(Node* &head, Node* &tail){
    Node* deleteNode = tail;     // safe to move `tail` afterwards: this holds it
    if(head == tail){            // one node only
        delete deleteNode;       // free it
        head = NULL;             // `delete` does not blank the pointer, so do it here
        tail = NULL; // Needed as well, for the same reason: `delete` does not
        // blank the pointer, so without this `tail` would dangle.
        return;
    }
    tail = tail->prev;           // O(1) - the whole reason `prev` exists. The
    tail->next = NULL;           // singly linked version had to walk from `head`.
    delete deleteNode;           // free the old last node
    // No empty-list guard: calling this when `tail` is NULL reads through NULL.
}

// Remove the node at index `pos` (0-based).
void delete_at_any_position(Node* &head, Node* &tail, int pos){
    if(pos == 0){                // the head has no node before it
        delete_at_head(head, tail);
        return;
    }
    Node* tmp = head;            // walker
    for(int i=1; i<pos; i++){    // `tmp` ends up on index pos-1; the victim is
        tmp = tmp->next;         // `tmp->next`
    }
    // BUG: the same one as in delete_at_any_position_doubly_linked_list.cpp: this
    // test looks one node too close. When the victim IS the last node, `tmp` is
    // the second-last, so `tmp->next` is not NULL and the code falls through to
    // the lines below - where `tmp->next` becomes NULL and `tmp->next->prev`
    // crashes. The test should be `if(tmp->next->next == NULL)`.
    if(tmp->next == NULL){
        delete_at_tail(head, tail);
        return;
    }
    Node* deleteNode = tmp->next;  // the victim
    tmp->next = tmp->next->next;   // step over the victim
    tmp->next->prev = tmp;         // and close the gap from the other side
    delete deleteNode;             // free the victim
}

// main: meant to read values until -1 into a list, then print it.
int main(){
    Node* head = NULL;   // empty list: no first node...
    Node* tail = NULL;   // ...and no last node

    int val;             // each value read
    // BUG: `while(tail)` means "while `tail` is not NULL", and `tail` was just set
    // to NULL above, so the condition is false the very first time and
    // the body would never run. The intended loop is `while(true)`.
    while(tail){
        cin >> val;          // read the next integer
        if(val==-1){         // -1 = end of input
            // BUG: `return;` with no value inside `int main` does not compile
            // ("return-statement with no value, in function returning 'int'").
            // And even with a value it would leave `main`, not just the loop,
            // skipping the print below. Fix: `break;`
            return;
        }
        insert_at_tail(head, tail, val);   // append in input order
    }

    // With both bugs fixed, input 10 20 30 -1 prints `10 20 30`.
    // (With only the `return;` fixed, the loop never runs and this prints
    // just an empty line.)
    print_forward(head);

    return 0;   // normal exit
}
