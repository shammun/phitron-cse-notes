// Insert at head: put a new node in FRONT of the list in O(1).
// No walking is needed, because head already points at the front.
// Two steps, in this order:
//   1. newNode->next = head;   the new node points at the old first node
//   2. head = newNode;         the new node becomes the first node
// Start 10 -> 20 -> 30; insert 100, 200, 300 -> 300 200 100 10 20 30.

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

// Node* &head is a REFERENCE to main's head pointer: assigning to head here
// changes main's head too. With a plain Node* head, only a local copy would
// change and main would still point at the old first node.
void insert_at_head(Node* &head, int val){
    Node* newNode = new Node(val); // make the node on the heap
    newNode->next = head; // step 1: link it in front of the current first node
    head = newNode; // step 2: it is now the first node
    // (Swapping the two steps would make newNode point at itself and lose the list.)
}


// Print every value, one per line. A copy of head is fine: we only read.
void print_linked_list(Node* head){
    Node* tmp = head; // walker pointer; head itself is never moved
    while(tmp != NULL){ // until past the last node
        cout << tmp-> val << endl; // print this value
        tmp = tmp->next; // step forward
    }
}

int main() { // the program starts running here
    // Build 10 -> 20 -> 30 by hand.
    Node* head = new Node(10); // first node
    Node* a = new Node(20); // second node
    Node* b = new Node(30); // third node (next is already NULL)

    head->next = a; // 10 -> 20
    a->next = b; // 20 -> 30

    insert_at_head(head, 100); // 100 10 20 30
    insert_at_head(head, 200); // 200 100 10 20 30
    insert_at_head(head, 300); // 300 200 100 10 20 30
    print_linked_list(head); // print them all
    /*
    Output:
    300
    200
    100
    10
    20
    30

    */

    return 0; // program finished successfully
}
