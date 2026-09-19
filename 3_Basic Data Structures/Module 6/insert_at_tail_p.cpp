#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Practice copy of insert_at_tail.cpp, typed again from memory. The original carries the
// full explanation; here the interesting part is one character that went missing.

class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this->val = val;
            // BUG (left in place on purpose - do not fix it here, study it).
            // The original says `this->next = NULL;`. This copy says `next`, and inside
            // the constructor the bare name `next` means the member itself, which has
            // not been given a value yet. So the line reads "set next to whatever
            // rubbish next already holds" and the new node ends up with a garbage
            // address instead of NULL.
            // Consequence: nothing marks the end of the list. The walk to the tail below
            // keeps following garbage pointers, never meets NULL, and the program runs
            // until the judge kills it (timeout) or it crashes.
            // Fix: this->next = NULL;
            this->next = next;
        }
};


// Insert at tail without a tail pointer. Unlike insert at head, the place to attach is
// at the far end, and the only way to reach it is to walk there from head.
void insert_at_tail(Node* &head, int val){
    Node* newNode = new Node(val);

    // Empty list: there is no last node to attach to, so the new node is the whole list.
    // This is the case that needs `Node* &head` - it assigns to head, and the caller must
    // see that change.
    if(head == NULL){
        head = newNode;
        return;
    }

    // Walk to the LAST node. The test is `tmp->next != NULL`, not `tmp != NULL`: stopping
    // on tmp == NULL would walk one step too far, off the end of the list, and there
    // would be nothing left to attach to.
    // This walk is why the plain tail insert costs O(n) per insert - see the optimized
    // version, which remembers the tail and attaches in O(1).
    Node* tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    // With the constructor bug above, tmp->next is never NULL, so this loop never ends.
}

// Same as the original except that head comes in by reference here; print only reads the
// list, so a plain copy would do just as well.
void print_linked_list(Node* &head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

int main(){
    // 10 -> 20 -> 30, built by hand. Note that b's next is never set here; it should be
    // NULL from the constructor, and that is exactly what the bug takes away.
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);

    head->next = a;
    a->next = b;

    // Intended result: 10 20 30 100 200 300, each insert added at the far end.
    // What actually happens: the first insert walks off the end and hangs.
    insert_at_tail(head, 100);
    insert_at_tail(head, 200);
    insert_at_tail(head, 300);

    print_linked_list(head);

    return 0;
}