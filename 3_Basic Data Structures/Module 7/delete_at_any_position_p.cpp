/*

Practice copy of delete_at_any_position.cpp, re-typed from memory.

The one difference from the original: here `delete_at_any_position` takes
`Node* &head` - a reference - instead of `Node* head`. Everything else, and
the output, is the same. The reference costs nothing but is not needed either,
because this function never moves the first node. It would start to matter the
day the function also handled `idx = 0`, since then `head` itself changes.

The rule being practised: stand on the node before the victim, bend the arrow
past it, then delete the box - in that order.

Example: input 10 20 30 40 50 -1  ->  prints 10 20 30 40 50, then 10 20 40 50.

*/

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used in this file
#include <algorithm>  // sort/max/min - not used in this file
#include <string>     // std::string - not used in this file
using namespace std;  // lets us write cout instead of std::cout


// One node of a singly linked list: a value plus the address of the next node.
class Node {
    public:            // accessible from outside the class
        int val;       // the data stored in this node
        Node* next;    // address of the next node; NULL means "this is the last node"

    // Constructor: runs on `new Node(x)`. `this->val` is the member, `val` the parameter.
    Node(int val) {
        this->val = val;    // store the value
        this->next = NULL;  // a brand-new node is not linked to anything yet
    }
};

// Append `val` at the end in O(1). `&` (reference) lets the function change
// main's own `head` and `tail`, not copies of them.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // `new` creates the node on the heap and returns its address
    if(head == NULL){                // empty list: new node is first and last
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;   // old last node now points at the new one
    tail = newNode; // or tail = tail->next   (move the tail bookmark)
}

// Print every value, one per line, walking with a copy `tmp` so `head` is untouched.
void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){                // stop after the last node
        cout << tmp-> val << endl;     // `->` reads a member through a pointer; endl = newline + flush
        tmp = tmp->next;               // step to the next node
    }
}

// Kept from the previous lesson for comparison: removing the first node needs
// no walk at all, only `head = head->next` - O(1) instead of O(n).
// (Not called in this file. Crashes on an empty list: no NULL check.)
void delete_head(Node* &head){
    Node* deleteNode = head;   // remember the old first node
    head = head->next;         // second node becomes first
    delete deleteNode;         // free the old first node's memory
}

// Remove the node at 0-based index `idx`, by standing on index idx-1.
// Assumes 1 <= idx < size; idx = 0 or idx >= size is not handled.
void delete_at_any_position(Node* &head, int idx){
    Node* tmp = head;          // walker on index 0
    // Stop one node early: after the loop `tmp` is on index idx-1.
    // With idx = 2: the loop runs once (i = 1), tmp moves 10 -> 20.
    for(int i=1; i<idx; i++){
        tmp = tmp->next;
    }
    // Save, then relink, then free. Never the other way round.
    Node* deleteNode = tmp->next;  // the victim (30 in the example)
    tmp->next = tmp->next->next;   // the victim's neighbours are joined together (20 -> 40)
    delete deleteNode;             // return the victim's memory to the heap
}

int main(){
    Node* head = NULL;   // empty list
    Node* tail = NULL;

    int val;
    while(true){         // read until -1
        // -1 ends the input and is not stored.
        cin >> val;      // reads the next whole number, skipping spaces/newlines
        if(val == -1){
            break;       // leave the loop
        }
        insert_at_tail(head, tail, val);   // keep input order
    }

    print_linked_list(head);   // whole list

    delete_at_any_position(head, 2);   // delete the third node (index 2, value 30)

    print_linked_list(head);   // list without the 30

    return 0;   // normal exit
}
