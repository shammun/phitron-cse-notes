/*

Take a singly linked list as input, then print the maximum value of them.

Input:
10 20 30 40 50 -1
Output:
50

Input:
10 20 30 40 -1
Output:
40

*/

/*
 * The maximum of a list is found in one walk, the same way as in an array:
 * keep the biggest value seen so far in `max` and compare every node with it.
 * `max` starts at INT_MIN (the smallest int there is), so the very first
 * node always replaces it - even when every value is negative.
 */

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used here
#include <algorithm>  // sort/max/min - not used here
#include <string>     // std::string - not used here
#include <limits.h>   // C header that defines INT_MIN / INT_MAX
#include <climits>    // the C++ name of the same header (one of the two is enough)
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.


// One node of a singly linked list.
class Node {
    public:
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        // `this->val` is the member; plain `val` is the parameter.
        Node(int val) {
            this->val = val;  // Assign the provided value to the 'val' member.
            this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
        }
};

// Append in O(1) using `tail`; references let main see the updated pointers.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // `new` makes the node on the heap
    if(head == NULL){                // empty list: first and last
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;   // link after the last node
    tail = newNode; // or tail = tail->next
}

// Return the largest value in the list (or -1 for an empty list).
int find_max(Node* head){
    if(head == NULL){
        return -1;       // empty list: no maximum, -1 is just a marker
    }
    Node* tmp = head;    // walker
    // A local variable named `max` hides std::max inside this function - allowed, just a name.
    int max = INT_MIN;   // smaller than any value the list can hold

    // One pass per node; compare, then step. Trace 10 20 5: max 10 -> 20 -> stays 20.
    while(tmp!=NULL){
        if(tmp->val > max){
            max = tmp->val;  // a new biggest value: remember it
        }
        tmp = tmp->next;     // next node
    }
    return max;          // after the walk, max is the largest of all
}

int main(){
    Node* head = NULL;   // empty list
    Node* tail = NULL;

    // Read values until the stop sign -1 (not stored).
    int val;
    while(true){
        cin >> val;            // next integer
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    int max = find_max(head);   // the answer

    cout << max << endl;        // print it; endl = newline + flush

    return 0;
}
