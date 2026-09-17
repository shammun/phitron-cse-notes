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
    Node* head = new Node(10); // Create the first node and store its address in 'head'.
    Node* a = new Node(20);   // Create the second node and store its address in 'a'.
    Node* b = new Node(30);  // Create the third node and store its address in 'b'.
    Node* c = new Node(40);  // Create the fourth node and store its address in 'c'.


    head->next = a;
    a->next = b;
    b->next = c;

    Node* tmp = head;

    // This will not print the value of the last node
    while(tmp->next != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    // Running the loop for second time
    tmp = head;

    // This will not print the value of the last node
    while(tmp->next != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    // Now, let's also print the value of the last node
    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }


    return 0;
}