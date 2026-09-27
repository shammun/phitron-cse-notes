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

// Print the values on one line, separated by spaces.
void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp-> val << " ";
        tmp = tmp->next;
    }
}

void sort_descending(Node* head){
    // i stops on the last node: nothing after it is left to compare.
    for(Node* i=head; i->next!=NULL; i=i->next){
        // j starts right after i; everything before i is already in place.
        for(Node* j=i->next; j!=NULL; j=j->next){
            // "<" puts the bigger value first: descending order.
            if(i->val < j->val){
                swap(i->val, j->val);
            }
        }
    }
}

// Swap two ints through references, so the caller's values really change.
// (Defined after the sort, so the sort actually calls std::swap - same effect.)
void swap(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
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

    sort_descending(head);

    print_linked_list(head);

    return 0;
}