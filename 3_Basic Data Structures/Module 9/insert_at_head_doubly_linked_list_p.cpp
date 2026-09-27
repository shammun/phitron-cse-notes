// Practice copy of insert_at_head_doubly_linked_list.cpp.
// Same function, same three links; the demo inserts 5 instead of 100 and the
// commented-out backward print was left out. See the original for the reasoning.

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
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head == NULL){       // empty list: the new node is both ends at once
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    newNode->next = head;   // 5 -> 10
    head->prev = newNode;   // 5 <- 10
    head = newNode;         // move `head` last, while 10 is still reachable
}

// main: build 10 <-> 20 <-> 30 by hand, insert 5 at the head, print.
int main(){
    Node* head = new Node(10);   // first node (`new` makes it on the heap and returns its address)
    Node* a = new Node(20);   // middle node
    Node* tail = new Node(30);   // last node

    head->next = a;   // 10 -> 20
    a->prev = head;   // 10 <- 20

    a->next = tail;   // 20 -> 30
    tail->prev = a;   // 20 <- 30

    print_forward(head);   // 10 20 30

    insert_at_head(head, tail, 5);   // head now points at the new node 5

    print_forward(head);   // 5 10 20 30

    return 0;   // 0 = the program ended normally
}
