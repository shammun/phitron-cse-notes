/*

Practice Day 01, problem 5: sort a doubly linked list in ascending order.

Read a doubly linked list (values ended by -1), sort it from smallest to
largest and print it.

Example
input
1 4 5 2 7 -1
output
1 2 4 5 7

*/

/*
 * The idea: this is the selection sort of Module 7
 * (selection_sort_linked_list.cpp), run on a doubly linked list.
 *
 * Selection sort on an array says: for every position i, look at every
 * position j after it, and whenever a[j] is smaller than a[i], swap them.
 * After the inner loop, the smallest remaining value sits at position i.
 *
 * On a list, "position" becomes "node". `i` walks from the head, and for each
 * `i` a second pointer `j` walks the nodes after it. We swap only the values
 * (`i->val` and `j->val`); the nodes and their `next`/`prev` arrows never
 * move, so head and tail stay valid and no link has to be rewired.
 *
 * For 1 4 5 2 7:
 *   i on 1: nothing after it is smaller           -> 1 4 5 2 7
 *   i on 4: 2 is smaller, swap                    -> 1 2 5 4 7
 *   i on 5: 4 is smaller, swap                    -> 1 2 4 5 7
 *   i on 5 and i on 7: nothing smaller            -> 1 2 4 5 7
 *
 * Because the arrows are untouched, printing backward from `tail` gives the
 * same list in descending order for free.
 */

#include <iostream>   // cin (keyboard input) and cout (screen output)
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// A doubly linked node: the value, an arrow forward and an arrow back.
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

// Append at the end in O(1), because `tail` is remembered.
// `Node* &head` = a reference to the caller's pointer, so main's head/tail really change.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head == NULL){        // empty list: the new node is head and tail
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    tail->next = newNode;    // old tail -> new node
    newNode->prev = tail;    // new node -> old tail
    tail = newNode;   // the new node is the last node now
}

// Left to right, along `next`.
void print_forward(Node* head){   // print from the first node to the last, on one line
    Node* tmp = head;   // walker from the first node
    while(tmp != NULL){   // stop after walking off the end
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->next;   // one node forward
    }
    cout << endl;   // end the line (endl = newline + flush)
}

// Selection sort by swapping values. An empty list is fine: `i` starts as
// NULL and the outer loop never runs.
void sort_ascending(Node* head){
    for(Node* i = head; i != NULL; i = i->next){   // i = the node being settled, walks the whole list
        // Every node after `i` gets one chance to be compared with it.
        for(Node* j = i->next; j != NULL; j = j->next){
            if(j->val < i->val){   // a smaller value further on?
                // A smaller value belongs earlier: bring it to `i`.
                swap(i->val, j->val);   // std::swap exchanges the two ints (the nodes stay put)
            }
        }
        // Here `i` holds the smallest value of everything from `i` onward.
    }
}

// main: read the list until -1, sort it, print it.
int main(){
    Node* head = NULL;   // first node (none yet: the list starts empty)
    Node* tail = NULL;   // last node (none yet)

    // Read values until -1. `break;` leaves the loop, not the program.
    int val;   // holds each number as it is read
    while(true){   // repeat until -1
        cin >> val;   // read the next integer (spaces/newlines are skipped)
        if(val == -1){   // -1 ends the input
            break;   // leave the loop
        }
        insert_at_tail(head, tail, val);   // append, keeping input order
    }

    sort_ascending(head);   // sort the values in place
    print_forward(head);   // print smallest to largest

    return 0;   // 0 = the program ended normally
}
