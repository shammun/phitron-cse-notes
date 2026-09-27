// Insert at tail (plain version): add a new node at the END of the list.
// Without a tail pointer we must walk from head to the last node first, so
// each insert costs O(n). insert_at_tail_optimized.cpp removes that walk.
// Start 10 -> 20 -> 30; insert 100, 200, 300 -> 10 20 30 100 200 300.

#include <iostream>  // cout
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
        // Runs on every new Node(x); `this` points at the node being built.
        Node(int val) {
            this->val = val;  // Assign the provided value to the 'val' member.
            this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
        }
};

// head is taken by reference (Node* &) because the empty-list case assigns
// to it, and main must see that change.
void insert_at_tail(Node* &head, int val){
    Node* newNode = new Node(val); // the node to add
    // Empty list: the new node becomes the whole list.
    if(head == NULL){
        head = newNode; // first (and only) node
        return; // done
    }
    Node* tmp = head; // walker, starts at the front
    // Stop ON the last node (its next is NULL), not after it, so we can attach there.
    while (tmp->next != NULL){
        tmp = tmp->next; // step forward
    }
    tmp->next = newNode; // attach the new node after the last node
}

// Print every value, one per line (reads only, so a copy of head is fine).
void print_linked_list(Node* head){
    Node* tmp = head; // walker
    while(tmp != NULL){ // until past the last node
        cout << tmp-> val << endl; // print this value
        tmp = tmp->next; // step forward
    }
}

int main(){ // the program starts running here
    // Build 10 -> 20 -> 30 by hand.
    Node* head = new Node(10); // first node
    Node* a = new Node(20); // second
    Node* b = new Node(30); // third (next = NULL)

    head->next = a; // 10 -> 20
    a->next = b; // 20 -> 30

    insert_at_tail(head, 100); // 10 20 30 100
    insert_at_tail(head, 200); // 10 20 30 100 200
    insert_at_tail(head, 300); // 10 20 30 100 200 300

    print_linked_list(head); // print them

    /*

    Output:
    10
    20
    30
    100
    200
    300

    */

    return 0; // program finished successfully
}
