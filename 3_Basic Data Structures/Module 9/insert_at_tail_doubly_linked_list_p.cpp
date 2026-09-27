// Practice copy of insert_at_tail_doubly_linked_list.cpp.
// Same functions; the demo appends 40 and then 50 instead of 100 twice, so the
// two new values are easy to tell apart in the output.

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

void print_forward(Node* head){   // print from the first node to the last, on one line
    Node* tmp = head;   // walker (a copy; the caller's head is not moved)
    while(tmp != NULL){   // stop after walking off the end
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->next;   // step one node forward
    }
    cout << endl;   // end the line (endl = newline + flush)
}

void print_backward(Node* tail){   // print from the last node back to the first, on one line
    Node* tmp = tail;   // walker, starting at the last node
    while(tmp != NULL){   // stop after walking off the end
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->prev;   // step one node backward
    }
    cout << endl;   // end the line (endl = newline + flush)
}

// Put a new node in front of the first node, O(1). (Not called in this file.)
// `Node* &head` means head is a REFERENCE to the caller's pointer (not a copy),
// so when this function moves head/tail, main's own head/tail move too.
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    newNode->next = head;   // new node points forward to the old first node
    head->prev = newNode;   // old first node points back to the new node
    head = newNode;   // the new node is the first node now
}

// Hang a new node after the last node, O(1) thanks to `tail`.
// References (`&`) let main see head/tail move.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head == NULL){       // empty list: one node, both ends
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    tail->next = newNode;   // 30 -> 40
    newNode->prev = tail;   // 30 <- 40
    tail = newNode;         // last, while `tail` still names the old end
}

// main: build 10 <-> 20 <-> 30 by hand, append 40 and 50, print after each.
int main(){
    Node* head = new Node(10);   // first node (`new` makes it on the heap and returns its address)
    Node* a = new Node(20);   // middle node
    Node* tail = new Node(30);   // last node

    head->next = a;   // 10 -> 20
    a->prev = head;   // 10 <- 20
    a->next = tail;   // 20 -> 30
    tail->prev = a;   // 20 <- 30

    print_forward(head);          // 10 20 30

    insert_at_tail(head, tail, 40);   // tail moves to 40
    print_forward(head);          // 10 20 30 40

    insert_at_tail(head, tail, 50);   // tail moves to 50
    print_forward(head);          // 10 20 30 40 50
    // print_backward(tail) here would give 50 40 30 20 10 - every prev is set.

    return 0;   // 0 = the program ended normally
}
