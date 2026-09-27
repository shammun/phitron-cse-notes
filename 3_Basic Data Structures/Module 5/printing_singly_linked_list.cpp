// Printing a singly linked list: start a temporary pointer at head and keep
// moving it to ->next, printing each node, until it falls off the end (NULL).
// The list here is 10 -> 20 -> 30 -> 40 -> NULL.
// This file also shows a common mistake: stopping at tmp->next != NULL skips
// the last node.
// Output (one per line): 10 20 30, 10 20 30, 40

#include <iostream>  // cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // not needed here
#include <string>    // not needed here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Node class represents a single element in a linked list.
class Node {
    public: // usable from main()
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        // Runs automatically on new Node(x). this = pointer to the node being built.
    Node(int val) {
        this->val = val;  // Assign the provided value to the 'val' member.
        this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
    }
};

// Main function: Entry point of the program.
int main() {
    // new creates each node on the heap and returns its address.
    Node* head = new Node(10); // Create the first node and store its address in 'head'.
    Node* a = new Node(20);   // Create the second node and store its address in 'a'.
    Node* b = new Node(30);  // Create the third node and store its address in 'b'.
    Node* c = new Node(40);  // Create the fourth node and store its address in 'c'.


    // Link them: head -> a -> b -> c. c->next stays NULL (set by the constructor).
    head->next = a; // p->x is short for (*p).x
    a->next = b;
    b->next = c;

    // tmp walks the list. We never move head itself, or we would lose the
    // start of the list.
    Node* tmp = head;

    // This will not print the value of the last node
    // The loop stops when tmp is ON the last node (its next is NULL), before
    // printing it. Prints 10, 20, 30.
    while(tmp->next != NULL){
        cout << tmp->val << endl; // print this node's value
        tmp = tmp->next; // step to the next node
    }

    // Running the loop for second time
    tmp = head; // go back to the start

    // This will not print the value of the last node
    // Same loop again: prints 10, 20, 30; tmp is left on the node with 40.
    while(tmp->next != NULL){
        cout << tmp->val << endl; // print this node's value
        tmp = tmp->next; // step forward
    }

    // Now, let's also print the value of the last node
    // tmp was NOT reset to head, so it starts at the last node (40): this loop
    // prints only 40. The correct full-print loop is: tmp = head; then
    // while(tmp != NULL) { print; move }, which stops only after the last node.
    while(tmp != NULL){
        cout << tmp->val << endl; // print this node's value
        tmp = tmp->next; // step forward; becomes NULL after the last node
    }


    return 0; // program finished successfully
}
