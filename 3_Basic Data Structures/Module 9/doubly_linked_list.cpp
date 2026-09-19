// Build a doubly linked list by hand.
//
// In Module 7 a node knew only the box in front of it (`next`). A doubly linked
// list gives every node a second pointer, `prev`, aimed at the box behind it.
// This program only wires three nodes together; it prints nothing. Run it to
// check that it compiles, and read it to see which arrows have to be set.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// One box of the chain. Three things live inside it.
class Node {
    public:
        int val;     // The value this box carries.
        Node* next;  // Address of the box in front. NULL means "nothing in front".
        Node* prev;  // Address of the box behind.   NULL means "nothing behind".

    // Constructor: it runs once, on the box that `new Node(...)` just made.
    // `val` here is the parameter, so `this->val` says "the member of this box",
    // not the parameter.
    Node(int val) {
        this->val = val;
        // Both links start empty. A fresh box is not attached to anything yet;
        // the code that creates it decides where it belongs. Forgetting this and
        // leaving the links as garbage is the bug in print_doubly_link_list_p.cpp.
        this->next = NULL;
        this->prev = NULL;
    }
};

int main(){
    // `new Node(10)` asks for memory that stays alive until we `delete` it, runs
    // the constructor on it, and hands back the address of that box. So `head` is
    // not a box; it is a pointer holding the address of one.
    //
    // `head` is the name for the first box and `tail` for the last. They are just
    // two ordinary pointers - the chain itself has no idea it has ends. Keeping
    // `tail` around is what will make "add at the end" and "delete the end" cheap.
    Node* head = new Node(10);
    Node* a = new Node(20);   // the middle box; it needs no special name
    Node* tail = new Node(30);

    // Now the four link assignments. The rule of this whole module:
    // if A->next is B, then B->prev must be A. Every join costs two lines,
    // one forward and one backward.

    head->next = a;    // 10 -> 20
    a->prev = head;    // 10 <- 20

    a->next = tail;    // 20 -> 30
    tail->prev = a;    // 20 <- 30

    // The picture that now exists in memory:
    //
    //   NULL <- [10] <-> [20] <-> [30] -> NULL
    //            ^                 ^
    //           head              tail
    //
    // `head->prev` and `tail->next` were never touched, so they are still the
    // NULL the constructor put there - which is exactly what marks the two ends.

    return 0;
}
