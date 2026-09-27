// Insert at the tail - the mirror image of the head insert.
//
// Everything is the same shape as insert_at_head, with `next` and `prev` swapped
// and `tail` moving instead of `head`. Because the list keeps a `tail` pointer,
// no walk is needed: the last node is already in hand.

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

// Unchanged from insert_at_head_doubly_linked_list.cpp; kept so both ends of the
// list can be used in the same program.
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

// Hang a new node holding `val` after the last node. O(1) thanks to `tail`.
// `Node* &head` means head is a REFERENCE to the caller's pointer (not a copy),
// so when this function moves head/tail, main's own head/tail move too.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL

    // Empty list: the single node is the first and the last one.
    // `head == NULL` is tested rather than `tail == NULL` - on a well-kept list
    // the two are NULL together, so either test works.
    if(head==NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }

    // Normal case, on 10 20 30 with val = 100:
    tail->next = newNode;   // 30 -> 100
    newNode->prev = tail;   // 30 <- 100
    tail = newNode;         // 100 is the last node now

    // `tail` is moved last, for the same reason `head` was: until this line,
    // `tail` is the only name for node 30.
    //
    // `tail` is a `Node* &`, the caller's own pointer. Without the `&` this last
    // line would move a copy, `main` would still think 30 was the end, and the
    // next append would hang 100 off 30 a second time.
    //
    // `newNode->next` stays NULL from the constructor, which is what marks the
    // new end of the list.
}

// main: build 10 <-> 20 <-> 30 by hand, append 100 twice, print after each step.
int main(){
    Node* head = new Node(10);   // first node (`new` makes it on the heap and returns its address)
    Node* a = new Node(20);   // middle node
    Node* tail = new Node(30);   // last node

    head->next = a;   // 10 -> 20
    a->prev = head;   // 10 <- 20

    a->next = tail;   // 20 -> 30
    tail->prev = a;   // 20 <- 30

    print_forward(head);   // 10 20 30
    // print_backward(tail);   // switched off; would print 30 20 10

    insert_at_tail(head, tail, 100);   // first append: tail moves to the new 100

    print_forward(head);   // 10 20 30 100

    // The same value again - a list is happy to hold duplicates, and this also
    // shows that `tail` really did move: 100 is appended after the first 100.
    insert_at_tail(head, tail, 100);   // second append: hangs after the first 100

    print_forward(head);   // 10 20 30 100 100

    return 0;   // 0 = the program ended normally
}
