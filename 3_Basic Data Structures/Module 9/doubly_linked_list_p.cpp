// Practice copy of doubly_linked_list.cpp - the same program, re-typed.
// The node, `new Node(...)`, and the head/tail idea are explained in full there;
// the short comments below repeat the essentials so this file reads on its own.
// Nothing differs here except the brace style.

#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>   // std::vector (a resizable array) - not used in this file
#include <algorithm>   // sort, reverse, swap, max, min ... - not used in this file
#include <string>   // std::string - not used in this file
using namespace std;   // lets us write cout, list ... instead of std::cout, std::list ...

class Node{   // one node: a value plus links to the next AND the previous node
    public:   // members below are usable from outside the class
        int val;   // the value this node carries
        Node* next;   // address of the node after this one (NULL = none)
        Node* prev;   // address of the node before this one (NULL = none)

        // Both links start as NULL, so a new box is attached to nothing yet.
        Node(int val){   // constructor: runs on `new Node(x)`
            this->val = val;   // `this->val` = the member, plain `val` = the parameter
            this->next = NULL;   // not linked to anything yet
            this->prev = NULL;   // not linked to anything yet
        }
};

// main: build three nodes by hand and link them both ways.
// `new Node(10)` makes a node on the heap (it lives until `delete`) and
// returns its address, so head / a / tail are pointers, not nodes.
int main(){
    Node* head = new Node(10);   // first node (`new` makes it on the heap and returns its address)
    Node* a = new Node(20);   // middle node
    Node* tail = new Node(30);   // last node

    // Two joins, two lines each: forward first, then the matching backward link.
    head->next = a;   // 10 -> 20
    a->prev = head;   // 10 <- 20

    a->next = tail;   // 20 -> 30
    tail->prev = a;   // 20 <- 30

    // Result: NULL <- [10] <-> [20] <-> [30] -> NULL
    // `head->prev` and `tail->next` are still NULL, which is what marks the ends.

    return 0;   // 0 = the program ended normally
}
