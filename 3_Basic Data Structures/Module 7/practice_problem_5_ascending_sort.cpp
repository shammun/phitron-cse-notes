/*

Take a doubly linked list as input and sort it in ascending order. Then print the list.

Input:
1 4 5 2 7 -1
Output:
1 2 4 5 7

Input:
20 40 30 10 50 60 -1
Output:
10 20 30 40 50 60

*/

/*
 * Selection sort on the list, but swapping only the VALUES, never the nodes.
 * `i` walks the list; `j` walks every node after `i`. Whenever `j` holds a
 * smaller value than `i`, the two values swap. When the inner walk ends, `i` holds
 * the smallest value of the remaining part, so the list fills up in ascending order
 * from the front. The comparison sign is the only thing that decides the order.
 *
 * Note: the task says "doubly linked list", but this code builds a singly
 * linked list (a Node has only `next`). Because only values are swapped, the
 * same sort would work on a doubly list unchanged.
 *
 * This file has a bug in the inner loop (see BUG note): as written it never
 * finishes for a list of two or more values.
 */

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used here
#include <algorithm>  // brings in std::swap, which the sort below ends up calling
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
    Node* newNode = new Node(val);   // `new` creates the node on the heap
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

// Selection sort into ascending order, swapping values only.
void sort_ascending(Node* head){
    // i stops on the last node: nothing after it is left to compare.
    for(Node* i=head; i->next!=NULL; i=i->next){
        // BUG (kept on purpose): `j->next` reads a value and throws it away,
        // so j never moves and this loop never ends. It must be `j=j->next`.
        for(Node* j=i->next; j!=NULL; j->next){
            if(i->val > j->val){        // ">" -> smaller values move to the front
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

    sort_ascending(head);      // smallest first (hangs because of the BUG above)

    print_linked_list(head);   // after the fix: e.g. 1 2 4 5 7

    return 0;
}
