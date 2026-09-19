#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

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

// Practice copy of input_a_linked_list.cpp, typed again from memory. It matches the
// original line for line, so this copy only notes what each part is for; the original
// carries the longer explanation.

// The O(1) tail insert from insert_at_tail_optimized.cpp: `tail` always points at the
// last node, so no walk is needed. Both pointers are taken as `Node* &` because the
// empty-list branch below assigns to both, and main must see those new values.
void insert_at_tail(Node* & head, Node* &tail, int val){
    Node* newNode = new Node(val);

    // The first value read: the list is empty, so this one node is both first and last.
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;   // attach behind the current last node
    tail = newNode;         // and that new node becomes the last one
}

void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

int main(){
    // Start with nothing. Setting both pointers to NULL is what tells insert_at_tail
    // that the list is still empty; leaving them uninitialised would send it straight
    // into the `tail->next` line with a garbage tail.
    Node* head = NULL;
    Node* tail = NULL;

    // The count is not given in advance, so the input ends with a sentinel: keep reading
    // until the value -1 shows up. `while(true)` plus a break in the middle is the normal
    // shape for this, because the test can only be made after the value has been read.
    // -1 is only a marker; it is never inserted, since the break happens first.
    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    // Inserting at the tail keeps the reading order: 10 20 30 40 -1 gives 10 20 30 40.
    // Using insert_at_head instead would print them reversed, 40 30 20 10.
    // Reading n values costs O(n) time (each insert is O(1)) and O(n) space for nodes.
    print_linked_list(head);

    return 0;
}
