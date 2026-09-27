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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <climits>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.


class Node {
    public:
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        Node(int val) {
            this->val = val;  // Assign the provided value to the 'val' member.
            this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
        }
};

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    
    tail->next = newNode;
    tail = newNode; // or tail = tail->next
}

int find_max(Node* head){
    if(head == NULL){
        return -1;       // empty list: no maximum, -1 is just a marker
    }
    Node* tmp = head;
    int max = INT_MIN;   // smaller than any value the list can hold

    while(tmp!=NULL){
        if(tmp->val > max){
            max = tmp->val;  // a new biggest value: remember it
        }
        tmp = tmp->next;
    }
    return max;          // after the walk, max is the largest of all
}

int main(){
    Node* head = NULL;
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

    int max = find_max(head);

    cout << max << endl;

    return 0;
}