// Practice copy of doubly_linked_list.cpp - the same program, re-typed.
// The node, `new Node(...)`, and the head/tail idea are explained in full there.
// Nothing differs here except the brace style.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* prev;

        // Both links start as NULL, so a new box is attached to nothing yet.
        Node(int val){
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    // Two joins, two lines each: forward first, then the matching backward link.
    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    // Result: NULL <- [10] <-> [20] <-> [30] -> NULL
    // `head->prev` and `tail->next` are still NULL, which is what marks the ends.

    return 0;
}
