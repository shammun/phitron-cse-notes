// Print a linked list backwards with recursion, without changing the list.
// print_reverse(node) first prints everything AFTER node (the recursive call),
// then prints node itself, so the last node comes out first.
// Example: input 10 20 30 40 -1 -> prints 40, 30, 20, 10 (one per line).

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
        // Runs on every new Node(x); `this` points at the node being built.
        Node(int val) {
            this->val = val;  // Assign the provided value to the 'val' member.
            this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
        }
};

// O(1) tail insert: tail always points at the last node.
// Node* & = reference to main's pointer, so changes here are seen in main.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val); // the node to add
    if(head == NULL){ // empty list
        head = newNode; // first node
        tail = newNode; // last node
        return; // done
    }

    tail->next = newNode; // attach after the last node
    tail = newNode; // or tail = tail->next
}

// Recursive reverse print.
// Base case: temp == NULL means we are past the end: nothing to print.
// Trust: print_reverse(temp->next) prints the rest of the list backwards;
// printing temp->val afterwards puts this node after all of them.
// Time O(n); memory O(n) for the n calls waiting on the call stack.
void print_reverse(Node* temp){
    if(temp == NULL){ // past the end
        return; // go back up
    }
    print_reverse(temp->next); // first print everything after this node (backwards)
    cout << temp->val << endl; // then this node
}

int main(){ // the program starts running here
    Node* head = NULL; // empty list
    Node* tail = NULL; // no last node yet

    int val; // each number read
    // Read until the sentinel -1 (it is not stored).
    while(true){
        cin >> val; // read one number
        if(val == -1){ // end marker?
            break; // stop reading
        }
        insert_at_tail(head, tail, val); // append in reading order
    }

    print_reverse(head); // print the list from last to first

    return 0; // program finished successfully
}
