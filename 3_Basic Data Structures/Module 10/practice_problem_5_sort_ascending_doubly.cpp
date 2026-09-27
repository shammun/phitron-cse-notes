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

#include <iostream>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// A doubly linked node: the value, an arrow forward and an arrow back.
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

// Append at the end in O(1), because `tail` is remembered.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){        // empty list: the new node is head and tail
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;    // old tail -> new node
    newNode->prev = tail;    // new node -> old tail
    tail = newNode;
}

// Left to right, along `next`.
void print_forward(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Selection sort by swapping values. An empty list is fine: `i` starts as
// NULL and the outer loop never runs.
void sort_ascending(Node* head){
    for(Node* i = head; i != NULL; i = i->next){
        // Every node after `i` gets one chance to be compared with it.
        for(Node* j = i->next; j != NULL; j = j->next){
            if(j->val < i->val){
                // A smaller value belongs earlier: bring it to `i`.
                swap(i->val, j->val);
            }
        }
        // Here `i` holds the smallest value of everything from `i` onward.
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // Read values until -1. `break;` leaves the loop, not the program.
    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    sort_ascending(head);
    print_forward(head);

    return 0;
}
