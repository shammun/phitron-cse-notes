// Practice copy of insert_at_any_position_doubly_linked_list.cpp.
// The functions are identical (same four links, same order, same early
// `new Node` leak); only the demo is shorter, and its last call shows the
// append case that the original never reached.

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

// Put a new node in front of the first node - O(1).
// `Node* &head` = a REFERENCE to the caller's pointer (not a copy), so
// when this function moves head/tail, main's own head/tail move too.
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

// Insert `val` so that it ends up at index `pos` (0-based).
// head/tail are references (`&`), so if an end of the list moves, main sees it.
void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(pos == 0){                 // no node before index 0 - that is a head insert
        insert_at_head(head, tail, val);   // index 0 = an insert at the head
        return;   // leave the function now
    }

    Node* tmp = head;   // walker from the first node
    for(int i=1; i<pos; i++){     // pos-1 steps, so `tmp` lands on index pos-1
        tmp = tmp->next;   // one node forward
    }

    if(tmp->next == NULL){        // `tmp` is the last node: this is an append,
        insert_at_tail(head, tail, val);   // and `tail` has to move as well
        return;   // leave the function now
    }

    newNode->next = tmp->next;    // the two lines that mention the old next node
    tmp->next->prev = newNode;    // must come first - after the next line it is
    tmp->next = newNode;          // no longer reachable through `tmp`
    newNode->prev = tmp;   // and the new node points back at `tmp`
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

    print_forward(head);                        // 10 20 30

    insert_at_tail(head, tail, 100);   // append 100 (tail moves)
    print_forward(head);                        // 10 20 30 100

    insert_at_any_position(head, tail, 2, 200); // middle case
    print_forward(head);                        // 10 20 200 30 100

    insert_at_any_position(head, tail, 0, 500); // head case
    print_forward(head);                        // 500 10 20 200 30 100

    // Index 6 on a list of size 6 means "one past the last node", which is a
    // legal place to insert: the walk stops on the last node, `tmp->next` is
    // NULL, and insert_at_tail takes over. Valid indexes here are 0 through 6.
    insert_at_any_position(head, tail, 6, 600);
    print_forward(head);                        // 500 10 20 200 30 100 600

    return 0;   // 0 = the program ended normally
}
