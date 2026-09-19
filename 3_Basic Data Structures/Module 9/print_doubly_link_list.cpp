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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Start at the first box and follow `next` until it runs out.
void print_forward(Node* head){
    // Walk with a copy, never with `head` itself: moving `head` would lose the
    // start of the list. (`head` here is a copy anyway, but the habit matters -
    // in the insert functions below the parameter really is the caller's pointer.)
    Node* tmp = head;
    while(tmp != NULL){        // NULL is the end marker the constructor put there
        cout << tmp->val << " ";
        tmp = tmp->next;       // step one box forward
    }
    cout << endl;              // finish the line, so the next print starts fresh
}

// Same walk from the other end: start at the last box and follow `prev`.
void print_backward(Node* tail){
    Node* tmp = tail;
    while(tmp != NULL){        // stops when it steps off the front: head->prev is NULL
        cout << tmp->val << " ";
        tmp = tmp->prev;       // step one box backward
    }
    cout << endl;
}

int main(){
    // The same hand-built chain as before: NULL <- 10 <-> 20 <-> 30 -> NULL
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    print_forward(head);   // 10 20 30
    print_backward(tail);  // 30 20 10 - the exact reverse, so every prev is right

    return 0;
}
