// Practice copy of insert_at_head.cpp, typed again from memory. The full explanation
// lives in that file; this one only notes the idea and the one place the copy differs.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Node{
    public:
        int val;
        Node* next;

        // Typed correctly here: `this->next = NULL` marks the new node as the end of the
        // list. Every loop over a list stops on NULL, so this one line is what keeps the
        // other files in this folder from running for ever.
        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};

// Insert at head in O(1): no walking needed, the head is already in your hand.
// The order of the two lines is the whole trick.
void insert_at_head(Node* &head, int val){
    Node* newNode = new Node(val);
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
    while(tmp!=NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

int main(){
    // Build 10 -> 20 -> 30 by hand, the way Module 5 did it.
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);

    head->next = a;
    a->next = b;

    // Each insert puts the new value in front, so the values come out in the reverse
    // order of insertion: 300 200 100, then the original 10 20 30.
    insert_at_head(head, 100);
    insert_at_head(head, 200);
    insert_at_head(head, 300);
    print_linked_list(head);

    return 0;
}