// Insert at any index - the four-link case, and why the order of the four lines
// is not a matter of taste.
//
// Putting a node between two others means four arrows change: two forward and
// two backward. Inserting at the very front or the very back is the same idea
// with one neighbour missing, so those two cases just hand the work to the
// functions written earlier.

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
    Node* tmp = head;   // walker from the first node
    while(tmp != NULL){   // stop after walking off the end
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->next;   // one node forward
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

// Both unchanged from the two files before this one.
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

// Hang a new node after the last node - O(1), because `tail` is already known.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    tail->next = newNode;   // old last node points forward to the new node
    newNode->prev = tail;   // new node points back to the old last node
    tail = newNode;   // the new node is the last node now
}

// `pos` counts from 0 and means "after this call, the new value sits at index pos".
void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    // Small flaw, worth knowing about: the node is built before the two special
    // cases are tested. If either of them fires, `insert_at_head` or
    // `insert_at_tail` builds a node of its own and this one is never used or
    // deleted - leaked memory. Creating it after the checks would fix it.
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL

    // Index 0 means "go in front of everything", which is exactly a head insert -
    // and it is a separate case because there is no node before index 0 to hang
    // the new one off.
    if(pos==0){   // index 0 has no node before it
        insert_at_head(head, tail, val);   // index 0 = an insert at the head
        return;   // leave the function now
    }

    // Walk to the node that will sit just BEFORE the new one, at index pos-1.
    // `tmp` starts at index 0, so the loop takes pos-1 steps: that is why it
    // counts from 1 and stops at `i < pos`, not `i <= pos`.
    Node* tmp = head;   // walker from the first node
    for(int i=1; i<pos; i++){   // stop on index pos-1 (the node before the spot)
        tmp = tmp->next;   // one node forward
    }

    // Nothing after `tmp`, so `tmp` is the last node and the new value goes on
    // the end. Hand it to insert_at_tail, which also moves the `tail` pointer -
    // the code below would not, and `tail` would be left pointing at the
    // second-last node.
    if(tmp->next == NULL){   // tmp is the last node?
        insert_at_tail(head, tail, val);   // then this is really an append
        return;   // leave the function now
    }

    // The real middle case. Standing on `tmp` (say 20) with `tmp->next` (say 30)
    // in front of it, inserting 200 between them:
    newNode->next = tmp->next;   // 200 -> 30
    tmp->next->prev = newNode;   // 200 <- 30
    tmp->next = newNode;         // 20  -> 200
    newNode->prev = tmp;         // 20  <- 200

    // The order of those four lines. The only way to reach node 30 is through
    // `tmp->next`, so both lines that mention 30 must come first. Move line 3 to
    // the top and `tmp->next` is 200 from then on: line 2 would set the new
    // node's own `prev` to itself, and 30 would keep pointing back at 20 while
    // 20 points forward at 200. The forward print would still look perfect and
    // only the backward print would show it.
    //
    // No check is made that `pos` is really between 0 and the list size. Too
    // large a `pos` walks `tmp` past the end and dereferences NULL.
    // Cost: O(n) for the walk, O(1) for the links.
}

// main: build 10 <-> 20 <-> 30 by hand, then change it step by step,
// printing after each change.
int main(){
    Node* head = new Node(10);   // first node (`new` makes it on the heap and returns its address)
    Node* a = new Node(20);   // middle node
    Node* tail = new Node(30);   // last node

    head->next = a;   // 10 -> 20
    a->prev = head;   // 10 <- 20

    a->next = tail;   // 20 -> 30
    tail->prev = a;   // 20 <- 30

    print_forward(head); // 10 20 30
    // print_backward(tail);   // switched off; would print the list from tail back to head

    insert_at_tail(head, tail, 100);   // append 100

    print_forward(head); // 10 20 30 100

    insert_at_tail(head, tail, 100); //  10 20 30 100 100

    print_forward(head);   // show the list now

    // The middle case: `tmp` stops on 20 (index 1) and 200 lands at index 2.
    insert_at_any_position(head, tail, 2, 200); // 10 20 200 30 100 100

    print_forward(head);   // show the list now

    // Index 0: straight to insert_at_head, and `head` moves.
    insert_at_any_position(head, tail, 0, 300); // 300 10 20 200 30 100 100

    print_forward(head);   // show the list now

    // Index 5 on a seven-node list: `tmp` stops on 30 (index 4), which still has
    // 100 in front of it, so this is the middle case again, not an append.
    insert_at_any_position(head, tail, 5, 400); // 300 10 20 200 30 400 100 100

    print_forward(head);   // show the list now

    return 0;   // 0 = the program ended normally
}
