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

// Practice copy of input_a_linked_list.cpp, typed again from memory. It matches the
// original line for line, so this copy only notes what each part is for; the original
// carries the longer explanation.

// The O(1) tail insert from insert_at_tail_optimized.cpp: `tail` always points at the
// last node, so no walk is needed. Both pointers are taken as `Node* &` because the
// empty-list branch below assigns to both, and main must see those new values.
void insert_at_tail(Node* & head, Node* &tail, int val){
    Node* newNode = new Node(val); // new node on the heap, next = NULL

    // The first value read: the list is empty, so this one node is both first and last.
    if(head == NULL){
        head = newNode; // first node
        tail = newNode; // last node
        return; // nothing more to do
    }

    tail->next = newNode;   // attach behind the current last node
    tail = newNode;         // and that new node becomes the last one
}

// Print all values, one per line. Only reads the list, so a copy of head is enough.
void print_linked_list(Node* head){
    Node* tmp = head; // walker pointer
    while(tmp != NULL){ // until we fall off the end
        cout << tmp->val << endl; // print this value
        tmp = tmp->next; // step forward
    }
}

int main(){ // the program starts running here
    // Start with nothing. Setting both pointers to NULL is what tells insert_at_tail
    // that the list is still empty; leaving them uninitialised would send it straight
    // into the `tail->next` line with a garbage tail.
    Node* head = NULL;
    Node* tail = NULL;

    // The count is not given in advance, so the input ends with a sentinel: keep reading
    // until the value -1 shows up. `while(true)` plus a break in the middle is the normal
    // shape for this, because the test can only be made after the value has been read.
    // -1 is only a marker; it is never inserted, since the break happens first.
    int val; // each number read
    while(true){ // loop until break
        cin >> val; // read one number
        if(val == -1){ // sentinel?
            break; // stop reading
        }
        insert_at_tail(head, tail, val); // append it
    }

    // Inserting at the tail keeps the reading order: 10 20 30 40 -1 gives 10 20 30 40.
    // Using insert_at_head instead would print them reversed, 40 30 20 10.
    // Reading n values costs O(n) time (each insert is O(1)) and O(n) space for nodes.
    print_linked_list(head);

    return 0; // program finished successfully
}
