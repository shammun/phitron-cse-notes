// Insert at tail, optimized: keep a second pointer `tail` that always points
// at the LAST node. Then adding at the end needs no walk from head:
//   tail->next = newNode;  (attach)   tail = newNode;  (move tail)
// Each insert is O(1) instead of O(n).
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

// head and tail are references (Node* &) to main's pointers, because this
// function can change both and main must see the new values.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val); // the node to add
    // Empty list: the one new node is both first and last.
    if(head == NULL){
        head = newNode; // first node
        tail = newNode; // last node
        return; // done
    }

    tail->next = newNode; // attach after the current last node
    tail = newNode; // or tail = tail->next
    // (the new node is now the last node)
}

// Print every value, one per line (reads only, so a copy of head is fine).
void print_linked_list(Node* head){
    Node* tmp = head; // walker
    while(tmp != NULL){ // until past the last node
        cout << tmp->val << endl; // print this value
        tmp = tmp->next; // step forward
    }
}

int main(){ // the program starts running here
    Node* head = new Node(10); // first node
    Node* a = new Node(20); // second node
    // The third node is named tail from the start, because it is the last node.
    Node* tail = new Node(30);
    // Node* tail = b;
    // (Switched off: the other way, creating a node b and then pointing tail at it.)

    head->next = a; // 10 -> 20
    a->next = tail; // 20 -> 30

    insert_at_tail(head, tail, 100); // 10 20 30 100, tail now at 100
    insert_at_tail(head, tail, 200); // ... 200, tail at 200
    insert_at_tail(head, tail, 300); // ... 300, tail at 300

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
