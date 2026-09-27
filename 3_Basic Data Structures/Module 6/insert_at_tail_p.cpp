#include <iostream>  // cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // not needed here
#include <string>    // not needed here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Practice copy of insert_at_tail.cpp, typed again from memory. The original carries the
// full explanation; here the interesting part is one character that went missing.

// One node of the list: a value plus the address of the next node.
class Node{
    public: // usable from outside the class
        int val; // the data
        Node* next; // address of the next node

        // Constructor: runs on every new Node(x); `this` points at the node being built.
        Node(int val){
            this->val = val; // store the value in the member
            // BUG (left in place on purpose - do not fix it here, study it).
            // The original says `this->next = NULL;`. This copy says `next`, and inside
            // the constructor the bare name `next` means the member itself, which has
            // not been given a value yet. So the line reads "set next to whatever
            // rubbish next already holds" and the new node ends up with a garbage
            // address instead of NULL.
            // Consequence: nothing marks the end of the list. The walk to the tail below
            // keeps following garbage pointers, never meets NULL, and the program runs
            // until the judge kills it (timeout) or it crashes.
            // (In practice the heap memory may happen to be zero, so it can look like it
            // works on one run and fail on another - that is what undefined behaviour means.)
            // Fix: this->next = NULL;
            this->next = next;
        }
};


// Insert at tail without a tail pointer. Unlike insert at head, the place to attach is
// at the far end, and the only way to reach it is to walk there from head.
void insert_at_tail(Node* &head, int val){
    Node* newNode = new Node(val); // the node to add

    // Empty list: there is no last node to attach to, so the new node is the whole list.
    // This is the case that needs `Node* &head` - it assigns to head, and the caller must
    // see that change.
    if(head == NULL){
        head = newNode; // first and only node
        return; // done
    }

    // Walk to the LAST node. The test is `tmp->next != NULL`, not `tmp != NULL`: stopping
    // on tmp == NULL would walk one step too far, off the end of the list, and there
    // would be nothing left to attach to.
    // This walk is why the plain tail insert costs O(n) per insert - see the optimized
    // version, which remembers the tail and attaches in O(1).
    Node* tmp = head; // walker, starts at the front
    while(tmp->next != NULL){ // BUG effect: with a garbage next, this may never see NULL
        tmp = tmp->next; // step forward
    }
    tmp->next = newNode; // attach after the last node
    // With the constructor bug above, tmp->next is never NULL, so this loop never ends.
}

// Same as the original except that head comes in by reference here; print only reads the
// list, so a plain copy would do just as well.
void print_linked_list(Node* &head){
    Node* tmp = head; // walker
    while(tmp != NULL){ // until past the last node
        cout << tmp->val << endl; // print this value
        tmp = tmp->next; // step forward
    }
}

int main(){ // the program starts running here
    // 10 -> 20 -> 30, built by hand. Note that b's next is never set here; it should be
    // NULL from the constructor, and that is exactly what the bug takes away.
    Node* head = new Node(10); // first node
    Node* a = new Node(20); // second node
    Node* b = new Node(30); // third node (next is garbage because of the BUG)

    head->next = a; // 10 -> 20
    a->next = b; // 20 -> 30

    // Intended result: 10 20 30 100 200 300, each insert added at the far end.
    // What actually happens: the first insert walks off the end and hangs.
    insert_at_tail(head, 100); // intended: 10 20 30 100
    insert_at_tail(head, 200); // intended: ... 200
    insert_at_tail(head, 300); // intended: ... 300

    print_linked_list(head); // print the list

    return 0; // program finished successfully
}
