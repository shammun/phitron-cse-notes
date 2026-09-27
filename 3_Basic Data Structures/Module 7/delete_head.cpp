/*

Delete the first node (the head) of a singly linked list.

The program reads numbers until -1, builds a list from them (in input order),
prints it, removes the first node, and prints it again.

Deleting the head is the cheapest delete there is - O(1), no walking - because
there is no "node before" the head that has to be re-linked. We only move the
`head` pointer one node forward and free the old first node.

The order of the three steps matters:
    1. save the old head's address in `deleteNode`,
    2. move `head` to `head->next`,
    3. `delete` the saved node.
If we freed the node first, reading `head->next` would read memory we no
longer own.

Example: input 10 20 30 -1
    prints 10 20 30 (one per line), then 20 30.

*/

#include <iostream>   // cin (read from keyboard) and cout (print to screen)
#include <vector>     // std::vector - not used in this file, left from a template
#include <algorithm>  // sort/max/min - not used in this file
#include <string>     // std::string - not used in this file
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Node class represents a single element in a linked list.
// A node is a small box on the heap: a value, and the address of the next box.
class Node {
    public:          // the members below can be used from main and other functions
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list (NULL = this is the last node).

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        // It runs automatically when we write `new Node(x)`.
    Node(int val) {
        // `this` is a pointer to the object being built. Because the parameter
        // is also called `val`, `this->val` is the member and `val` the parameter.
        this->val = val;  // Assign the provided value to the 'val' member.
        this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
    }
};   // a class definition ends with a semicolon

// Append `val` at the end of the list in O(1).
// `Node* &head` means "a reference to main's pointer": the function changes
// main's own `head`/`tail`, not copies of them.
void insert_at_tail(Node* &head, Node* &tail, int val){
    // `new Node(val)` creates a node on the heap and gives back its address.
    Node* newNode = new Node(val);
    // Empty list: this node is both the first and the last one.
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;          // nothing more to do
    }
    
    // Otherwise link it after the current last node...
    tail->next = newNode;
    // ...and move the `tail` bookmark onto it.
    tail = newNode; // or tail = tail->next
}

// Print every value, one per line, from head to the end.
void print_linked_list(Node* head){
    Node* tmp = head;               // walker; a copy, so main's head is not moved
    // Each pass prints one node and steps forward; stops when tmp is NULL
    // (we have walked past the last node).
    while(tmp != NULL){
        // `->` reads a member through a pointer. `endl` prints a newline and
        // flushes the output.
        cout << tmp-> val << endl;
        tmp = tmp->next;            // follow the arrow
    }
}

// Remove the first node in O(1). `head` is a reference because the first
// node really changes and main must see that.
// Note: there is no check for an empty list; calling this on an empty list
// would read `NULL->next` and crash. A safe version starts with
// `if(head == NULL) return;`.
void delete_head(Node* &head){
    Node* deleteNode = head;   // 1. remember the old first node
    head = head->next;         // 2. the second node becomes the first
    delete deleteNode;         // 3. `delete` returns the node's memory (made by `new`) to the heap
}

// Main function: Entry point of the program.
int main(){
    // Start with an empty list: no first node, no last node.
    Node* head = NULL;
    Node* tail = NULL;
    
    int val;   // each number read
    // Read until -1. `while(true)` repeats forever; only `break` ends it.
    // -1 is a stop sign and is never stored.
    while(true){
        cin >> val;          // `cin >>` skips spaces/newlines and reads one integer
        if(val == -1){
            break;           // leave the loop
        }
        insert_at_tail(head, tail, val);   // append, keeping input order
    }

    print_linked_list(head);   // e.g. 10 20 30

    delete_head(head);         // remove the first node

    print_linked_list(head);   // e.g. 20 30

    // Note: `tail` still points at the right node here, because deleting the
    // head does not touch the last node (unless the list had only one node).
    return 0;   // 0 = program ended normally
}
