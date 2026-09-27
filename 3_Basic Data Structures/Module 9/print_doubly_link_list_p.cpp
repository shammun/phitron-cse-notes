// Practice copy of print_doubly_link_list.cpp - and a good example of how a
// doubly linked list goes wrong. Two things were re-typed differently, and one
// of them makes the program never finish. See the notes on each below.

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

        Node(int val){   // constructor: runs on `new Node(x)`
            this->val = val;   // `this->val` = the member, plain `val` = the parameter
            // BUG: these two lines should be `this->next = NULL;` and
            // `this->prev = NULL;`. As written, the parameter list has no `next`
            // or `prev`, so the names on the right mean the members themselves:
            // each one is assigned to itself and keeps whatever rubbish happened
            // to be in that memory. The links are never NULL, so nothing marks
            // the ends of the list.
            this->next = next;
            this->prev = prev;   // BUG: same self-assignment; should be NULL
        }
};

void print_forward(Node* head){   // print from the first node to the last, on one line
    Node* tmp = head;   // walker (a copy; the caller's head is not moved)
    // The loop is correct; the data is not. After 30 it reads `tail->next`, which
    // is garbage rather than NULL, so the walk keeps going into random memory and
    // prints whatever numbers it finds - for ever, until the run is cut off.
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
    // BUG: second difference from the original - the `cout << endl;` is missing here,
    // so this function does not close its line. Harmless on its own, but it would
    // glue this output onto whatever prints next.
}

// main: build 10 <-> 20 <-> 30 by hand, then print both ways.
// `new Node(x)` makes a node on the heap and returns its address.
int main(){
    Node* head = new Node(10);   // first node (`new` makes it on the heap and returns its address)
    Node* a = new Node(20);   // middle node
    Node* tail = new Node(30);   // last node

    // These four links are set correctly - the two ends that nobody assigns
    // (head->prev and tail->next) are the ones left as garbage.
    head->next = a;   // 10 -> 20
    a->prev = head;   // 10 <- 20

    a->next = tail;   // 20 -> 30
    tail->prev = a;   // 20 <- 30

    print_forward(head);   // 10 20 30, then an endless run of junk numbers
    print_backward(tail);  // never reached
    // No `return 0;` - main alone may leave it out; it then returns 0.
}
