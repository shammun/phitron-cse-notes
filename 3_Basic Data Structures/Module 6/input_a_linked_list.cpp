// Read numbers until -1 and store them in a linked list, in the order read.
// Uses the O(1) tail insert: we keep a `tail` pointer to the last node, so
// adding a new node never needs a walk through the list.
// Example: input 10 20 30 -1 -> prints 10, 20, 30 (one per line).

#include <iostream>  // cin and cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // not needed here
#include <string>    // not needed here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// One node of the list: a value plus the address of the next node.
class Node {
    public: // usable from outside the class
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        // It runs on every new Node(x). `this` points at the node being built.
        Node(int val) {
            this->val = val;  // Assign the provided value to the 'val' member.
            this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
        }
};

// Add val at the end of the list in O(1).
// Node* &head / Node* &tail: references to main's pointers (not copies), so
// when this function changes head or tail, main's variables change too.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val); // make the new node on the heap
    // Empty list: the new node is both the first and the last node.
    if(head == NULL){
        head = newNode; // first node
        tail = newNode; // and also last node
        return; // done; skip the lines below
    }

    tail->next = newNode; // hook the new node after the current last node
    tail = newNode; // or tail = tail->next
    // (the new node is now the last one)
}

// Print every value, one per line. head is a copy of main's pointer, which is
// fine because this function only reads the list.
void print_linked_list(Node* head){
    Node* tmp = head; // walker; starts at the first node
    while(tmp != NULL){ // stop after the last node (its next is NULL)
        cout << tmp-> val << endl; // print this node's value (a space after -> is allowed)
        tmp = tmp->next; // move to the next node
    }
}

int main(){ // the program starts running here
    Node* head = NULL; // empty list: no first node yet
    Node* tail = NULL; // and no last node

    int val; // holds each number read
    // while(true) loops for ever; the break inside is the only way out.
    // We must read a value before we can test it, so the test sits in the middle.
    while(true){
        cin >> val; // read the next number
        if(val == -1){ // -1 is the "end of input" marker
            break; // leave the loop; -1 is not stored
        }
        insert_at_tail(head, tail, val); // store the number at the end
    }

    print_linked_list(head); // print the whole list

    return 0; // program finished successfully
}
