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

// Practice copy of reverse_linked_list_printing.cpp, typed again from memory. The
// original explains the idea in full; this copy has one typo and will not compile.

// The O(1) tail insert again: `tail` points at the last node, so no walking.
// Node* & = reference to main's pointer, so main sees the changes.
void insert_at_tail(Node* & head, Node* &tail, int val){
    Node* newNode = new Node(val); // the node to add
    if(head == NULL){ // empty list
        head = newNode; // first node
        tail = newNode; // last node
        return; // done
    }

    tail->next = newNode; // attach after the last node
    tail = newNode; // the new node is now the last
}

// This is recursion_n_to_1 from printing_reverse_printing.cpp with the counter replaced
// by a node pointer. A singly linked list has no way back, yet this prints it backwards:
// the recursive call runs to the very end first, and the printing happens while the calls
// return, so the last node is printed by the deepest call and the head is printed last.
// Time O(n); memory O(n) for the call stack, since all n calls are open at the bottom.
void print_reverse(Node* tmp){
    // Base case: past the end of the list, print nothing and go back up.
    if(tmp == NULL){
        return;
    }
    print_reverse(tmp->next);   // first go all the way to the end
    // BUG (left in place on purpose): `end` should be `endl`. There is no name `end` in
    // scope, so the file does not compile and produces no output at all. With `endl` it
    // prints 40 30 20 10 for the input 10 20 30 40 -1.
    // (std::end does exist, but it is a function template that needs an argument, so
    // `cout << end` still fails to compile.)
    cout << tmp->val << end;
}

int main(){ // the program starts running here
    // Both start as NULL so the insert knows the list is empty on the first value.
    Node* head = NULL;
    Node* tail = NULL;

    // Read until the sentinel -1, exactly as in input_a_linked_list.cpp. The -1 itself is
    // never inserted, because the break comes before the insert.
    int val; // each number read
    while(true){ // loop until break
        cin >> val; // read one number
        if(val == -1){ // sentinel?
            break; // stop reading
        }
        insert_at_tail(head, tail, val); // append it
    }

    // Note what is NOT here: the list is never rebuilt or reversed in memory. Only the
    // printing order changes, so the list itself is untouched afterwards.
    print_reverse(head);

    return 0; // program finished (if it compiled)
}
