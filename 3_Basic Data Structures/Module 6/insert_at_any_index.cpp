// Insert at any index: put a new node so that it ends up at position idx
// (the head is position 0).
// In a singly linked list you can only change a node's `next`, so we must stop
// at the node JUST BEFORE position idx (position idx-1) and splice there:
//   newNode->next = tmp->next;   the new node takes over the rest of the list
//   tmp->next = newNode;         tmp now points at the new node
// Cost: walking idx-1 steps -> O(idx), O(n) in the worst case.
// Note: this version assumes 1 <= idx <= size of the list. idx = 0 (the head)
// would need insert_at_head, and a too-big idx walks off the end (tmp becomes NULL).

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



// Print every value, one per line.
void print_linked_list(Node* head){
    Node* tmp = head; // walker
    while(tmp != NULL){ // until past the last node
        cout << tmp-> val << endl; // print this value
        tmp = tmp->next; // step forward
    }
}

// Plain O(n) tail insert (not used in main here; kept from the previous lesson).
void insert_at_tail(Node* &head, int val){
    Node* newNode = new Node(val); // the node to add
    if(head == NULL){ // empty list
        head = newNode; // the new node is the whole list
        return; // done
    }
    Node* tmp = head; // walker
    while (tmp->next != NULL){ // stop ON the last node
        tmp = tmp->next; // step forward
    }
    tmp->next = newNode; // attach at the end
}

// head is a reference only by habit here: this function never changes head.
void insert_at_any_index(Node* &head, int idx, int val){
    Node* newNode = new Node(val); // the node to insert
    Node* tmp = head; // walker, starts at position 0

    // Takes idx-1 steps, so tmp ends on position idx-1. Example idx = 2: one step,
    // tmp is on position 1.
    for(int i=1; i<idx; i++){ // starting from 1 makes it sure that we stop at the previous node of the index
        tmp = tmp->next; // step forward
    }
    newNode->next = tmp->next; // first: new node points at what came after tmp
    tmp->next = newNode; // then: tmp points at the new node
    // (Reverse order would overwrite tmp->next before reading it and lose the rest.)
}


int main(){ // the program starts running here
    // Build 10 -> 20 -> 30 by hand.
    Node* head = new Node(10); // position 0
    Node* a = new Node(20); // position 1
    Node* b = new Node(30); // position 2

    head->next = a; // 10 -> 20
    a->next = b; // 20 -> 30

    insert_at_any_index(head, 2, 1000); // 10 20 1000 30
    insert_at_any_index(head, 2, 2000); // 10 20 2000 1000 30
    insert_at_any_index(head, 3, 3000); // 10 20 2000 3000 1000 30

    print_linked_list(head); // print the list


    return 0; // program finished successfully
}

/*

Output:
10
20
2000
3000
1000
30

*/
