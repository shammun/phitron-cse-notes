// Print the list both ways.
//
// This is the payoff of the `prev` pointer. Walking forward is the same loop as
// in Module 7. Walking backward used to need recursion (Module 6) because a node
// could not see behind itself; here it is an ordinary loop in the other direction.
//
// It is also the free correctness test for the rest of the module: the backward
// line must be the exact reverse of the forward line. If it is not, some `prev`
// was left unset somewhere.
//
// The Node class is the one built in doubly_linked_list.cpp.

#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>   // std::vector (a resizable array) - not used in this file
#include <algorithm>   // sort, reverse, swap, max, min ... - not used in this file
#include <string>   // std::string - not used in this file
using namespace std;   // lets us write cout, list ... instead of std::cout, std::list ...

class Node {   // one node: a value plus links to the next AND the previous node
    public:   // members below are usable from outside the class
        int val;   // the value this node carries
        Node* next;   // address of the node after this one (NULL = none)
        Node* prev;   // address of the node before this one (NULL = none)

    Node(int val) {   // constructor: runs on `new Node(x)`
        this->val = val;   // `this->val` = the member, plain `val` = the parameter
        this->next = NULL;   // not linked to anything yet
        this->prev = NULL;   // not linked to anything yet
    }
};

// Start at the first box and follow `next` until it runs out.
void print_forward(Node* head){   // print from the first node to the last, on one line
    // Walk with a copy, never with `head` itself: moving `head` would lose the
    // start of the list. (`head` here is a copy anyway, but the habit matters -
    // in the insert functions below the parameter really is the caller's pointer.)
    Node* tmp = head;   // walker (a copy; the caller's head is not moved)
    while(tmp != NULL){        // NULL is the end marker the constructor put there
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->next;       // step one box forward
    }
    cout << endl;              // finish the line, so the next print starts fresh
}

// Same walk from the other end: start at the last box and follow `prev`.
void print_backward(Node* tail){   // print from the last node back to the first, on one line
    Node* tmp = tail;   // walker, starting at the last node
    while(tmp != NULL){        // stops when it steps off the front: head->prev is NULL
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->prev;       // step one box backward
    }
    cout << endl;   // end the line (endl = newline + flush)
}

// main: build 10 <-> 20 <-> 30 by hand, then print it both ways.
int main(){
    // The same hand-built chain as before: NULL <- 10 <-> 20 <-> 30 -> NULL
    Node* head = new Node(10);   // first node (`new` makes it on the heap and returns its address)
    Node* a = new Node(20);   // middle node
    Node* tail = new Node(30);   // last node

    head->next = a;   // 10 -> 20
    a->prev = head;   // 10 <- 20

    a->next = tail;   // 20 -> 30
    tail->prev = a;   // 20 <- 30

    print_forward(head);   // 10 20 30
    print_backward(tail);  // 30 20 10 - the exact reverse, so every prev is right

    return 0;   // 0 = the program ended normally
}
