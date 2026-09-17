#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Node class represents a single element in a linked list.
class Node {
    public:
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        Node(int val) {
            this->val = val;  // Assign the provided value to the 'val' member.
            this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
        }
};

// Main function: Entry point of the program.
int main() {
    // previously, Node a(10), b(20), c(30);

    // Dynamic node
    // For dynamic node, the node is created in the heap memory
    // and the pointer to the node is stored in the stack memory
    // So even after the function ends, the node will still be there in the heap memory
    
    Node* head = new Node(10); // Create the first node and store its address in 'head'.
    Node* a = new Node(20);   // Create the second node and store its address in 'a'.
    Node* b = new Node(30);  // Create the third node and store its address in 'b'.

    // previously a.next = &b; 
    // previously a was an object, so in the left side, we used . to access the member of the object

    (*head).next = a; // Link the first node to the second node using pointers.
    // because a is a pointer, so in the right side, we don't need to use &
    // but in the left side, we need to use * to dereference the pointer

    a->next = b; // previously, it was a.next = &b;

    cout << "The value of head is: " << head->val << endl; // Output the value of the first node.
    cout << "The value of a is: " << head->next->val << endl; // Output the value of the second node.
    cout << "The value of b is: " << head->next->next->val << endl; // Output the value of the third node.

    return 0;
}