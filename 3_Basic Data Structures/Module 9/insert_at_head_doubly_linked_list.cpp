// Insert at the head, arrow by arrow.
//
// The singly linked version of this in Module 7 needed two lines: point the new
// node at the old head, then move `head`. Here there is a third, because the old
// head must learn who is now behind it. That one extra line is the whole
// difference, and forgetting it is invisible in a forward print.
//
// Node, the print walks and the `Node* &` reference parameters were explained in
// the files before this one; short reminders are given next to each line below.

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

// Put a new node holding `val` in front of the first node. O(1).
// `Node* &head` means head is a REFERENCE to the caller's pointer (not a copy),
// so when this function moves head/tail, main's own head/tail move too.
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // both its links are NULL for now

    // Empty list. There is no old head to link to, and the new node is the last
    // node as well as the first - so `tail` must move too, or an append later
    // would write through a NULL pointer.
    if(head==NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }

    // Normal case, on 10 20 30 with val = 100:
    newNode->next = head;   // 100 -> 10
    head->prev = newNode;   // 100 <- 10   the line the singly list did not need
    head = newNode;         // 100 is the first node now

    // Done last on purpose. `head` is still the old first node in the two lines
    // above; move it first and you lose the only easy way to reach node 10.
    //
    // No walking happens anywhere here, so the cost is the same for a list of
    // three nodes or three million: O(1).
    // `newNode->prev` is left as the NULL from the constructor, which is correct -
    // nothing comes before the first node.
}

// main: build 10 <-> 20 <-> 30 by hand, insert 100 at the head, print.
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

    insert_at_head(head, tail, 100);   // head now points at the new node 100

    print_forward(head);   // 100 10 20 30

    return 0;   // 0 = the program ended normally
}
