/*

Take a singly linked list as input and sort it in descending order. Then print the list.

Input:
10 20 30 40 50 -1
Output:
50 40 30 20 10

Input:
10 20 30 40 -1
Output:
40 30 20 10

*/

/*
 * Selection sort on the list, but swapping only the VALUES, never the nodes.
 * `i` walks the list; `j` walks every node after `i`. Whenever `j` holds a
 * bigger value than `i`, the two values swap. When the inner walk ends, `i` holds
 * the biggest value of the remaining part, so the list fills up in descending order
 * from the front. The comparison sign is the only thing that decides the order.
 *
 * Practice copy. It does not compile: the inner loop uses `j` without
 * declaring it (see the BUG note).
 */

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used here
#include <algorithm>  // brings in std::swap, which the sort below would call
#include <string>     // std::string - not used here
#include <limits.h>   // INT_MIN / INT_MAX - not used here
#include <climits>    // C++ name of the same header - not used here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.


// One node of a singly linked list: a value and the address of the next node.
class Node {
    public:
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        // Runs on `new Node(x)`; `this->val` is the member, `val` the parameter.
        Node(int val) {
            this->val = val;  // Assign the provided value to the 'val' member.
            this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
        }
};

// Append in O(1) using the remembered tail. References update main's pointers.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // heap node
    if(head == NULL){                // empty list: first and last node
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;   // link after the old last node
    tail = newNode; // or tail = tail->next
}

// Print the values on one line, separated by spaces.
void print_linked_list(Node* head){
    Node* tmp = head;                // walker
    while(tmp != NULL){              // stop after the last node
        cout << tmp-> val << " ";    // `tmp-> val` is the same as `tmp->val`
        tmp = tmp->next;             // next node
    }
}

// Selection sort into descending order, swapping values only.
void sort_descending(Node* head){
    // i stops on the last node: nothing after it is left to compare.
    for(Node* i=head; i->next!=NULL; i=i->next){
        // BUG (kept on purpose): `j` is never declared - write `Node* j=i->next`.
        // The compiler stops with "'j' was not declared in this scope".
        for(j=i->next; j!=NULL; j=j->next){
            if(i->val < j->val){        // "<" -> bigger values move to the front
                swap(i->val, j->val);   // exchange the values
            }
        }
    }
}

// Swap two ints through references, so the caller's values really change.
// (Defined after the sort, so the sort actually calls std::swap - same effect.)
void swap(int &a, int &b){
    int temp = b;   // keep b's old value
    b = a;          // b gets a
    a = temp;       // a gets b's old value
}
int main(){
    Node* head = NULL;   // empty list
    Node* tail = NULL;

    // Read values until the stop sign -1 (not stored).
    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    sort_descending(head);     // biggest first

    print_linked_list(head);   // e.g. 50 40 30 20 10

    return 0;
}
