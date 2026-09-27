// Practice copy of insert_at_head.cpp, typed again from memory. The full explanation
// lives in that file; this one only notes the idea and the one place the copy differs.
// Output (one per line): 300 200 100 10 20 30

#include <iostream>  // cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // not needed here
#include <string>    // not needed here

using namespace std; // lets us drop the std:: prefix

// One node of the list: a value plus the address of the next node.
class Node{
    public: // usable from outside the class
        int val; // the data
        Node* next; // address of the next node

        // Typed correctly here: `this->next = NULL` marks the new node as the end of the
        // list. Every loop over a list stops on NULL, so this one line is what keeps the
        // other files in this folder from running for ever.
        // (Constructor: runs on every new Node(x); `this` points at the node being built.)
        Node(int val){
            this->val = val; // store the value in the member
            this->next = NULL; // no next node yet
        }
};

// Insert at head in O(1): no walking needed, the head is already in your hand.
// The order of the two lines is the whole trick.
void insert_at_head(Node* &head, int val){
    Node* newNode = new Node(val); // create the node on the heap
    newNode->next = head;   // first: hook the new node onto the old first node
    head = newNode;         // then: the new node becomes the first node
    // Swapping these two lines loses the list: head would already point at newNode, so
    // `newNode->next = head` would point the node at itself.
    //
    // `Node* &head` is a reference to the pointer, not a copy of it. A plain `Node* head`
    // would let this function change only its own copy, and main's head would still point
    // at the old first node.
}

// The one difference from the original: here print takes `Node* &head` too. It is
// unnecessary - this function only reads the list and never assigns to head - but it is
// harmless, and the output is the same. A plain `Node* head` copy says more clearly
// "I will not move your head pointer".
void print_linked_list(Node* &head){
    // Walk with a separate pointer tmp so that head itself is never moved; losing head
    // would lose the only way back to the start of the list.
    Node* tmp = head;
    while(tmp!=NULL){ // until past the last node
        cout << tmp->val << endl; // print this value
        tmp = tmp->next; // step forward
    }
}

int main(){ // the program starts running here
    // Build 10 -> 20 -> 30 by hand, the way Module 5 did it.
    Node* head = new Node(10); // first node
    Node* a = new Node(20); // second node
    Node* b = new Node(30); // third node

    head->next = a; // 10 -> 20
    a->next = b; // 20 -> 30

    // Each insert puts the new value in front, so the values come out in the reverse
    // order of insertion: 300 200 100, then the original 10 20 30.
    insert_at_head(head, 100); // 100 10 20 30
    insert_at_head(head, 200); // 200 100 10 20 30
    insert_at_head(head, 300); // 300 200 100 10 20 30
    print_linked_list(head); // print the list

    return 0; // program finished successfully
}
