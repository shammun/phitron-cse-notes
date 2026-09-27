// Dynamic nodes: create each node with `new` on the heap and keep only its
// address in a pointer. This is how real linked lists are built, because
// you can make as many nodes as you need while the program runs.
// Output:
//   The value of head is: 10
//   The value of a is: 20
//   The value of b is: 30

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
        // A constructor has the class's name and no return type; it runs
        // automatically every time a Node is created, e.g. new Node(10).
        Node(int val) {
            // The parameter is also called val, so it hides the member. `this` is a
            // pointer to the node being built; this->val means "the member val".
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
    // (until someone calls delete on it; this program never does, which is a
    // small memory leak. The operating system frees everything when the program exits.)
    // `new Node(10)` asks for memory on the heap, runs the constructor with 10,
    // and returns the new node's address.

    Node* head = new Node(10); // Create the first node and store its address in 'head'.
    Node* a = new Node(20);   // Create the second node and store its address in 'a'.
    Node* b = new Node(30);  // Create the third node and store its address in 'b'.

    // previously a.next = &b;
    // previously a was an object, so in the left side, we used . to access the member of the object

    (*head).next = a; // Link the first node to the second node using pointers.
    // because a is a pointer, so in the right side, we don't need to use &
    // but in the left side, we need to use * to dereference the pointer
    // (*head is the node head points at; then .next is its member.)

    a->next = b; // previously, it was a.next = &b;
    // p->x is the short way to write (*p).x.

    cout << "The value of head is: " << head->val << endl; // Output the value of the first node.
    cout << "The value of a is: " << head->next->val << endl; // Output the value of the second node.
    cout << "The value of b is: " << head->next->next->val << endl; // Output the value of the third node.

    return 0; // program finished successfully
}
