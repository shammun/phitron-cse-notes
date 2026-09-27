/*

Problem Statement

You will be given two singly linked list of integer values as input. You need to check if all the 
elements of both list are same which means both list are same. If they are same print "YES" 
otherwise print "NO".

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

First line will contain the values of the first singly linked list, and will terminate with -1.
Second line will contain the values of the second singly linked list, and will terminate with -1.

Constraints
- 1 <= N1, N2 <= 1000; Here N1 and N2 is the maximum number of nodes of the first and second linked 
list.
- 0 <= V <= 1000; Here V is the value of each node.

Output Format
Output "YES" or "NO".

Sample Input 0
10 20 30 40 -1
10 20 30 40 -1

Sample Output 0
YES

Sample Input 1
10 20 30 40 -1
10 20 30 -1

Sample Output 1
NO

Sample Input 2
10 20 30 40 -1
40 30 20 10 -1

Sample Output 2
NO

*/

/*
 * Two lists are "the same" when they have the same length AND the same value
 * at every position. So first compare the sizes: different sizes can never be
 * the same list, and it also guarantees the next step is safe. Then walk both
 * lists side by side with two pointers, one step each per round, and compare
 * the values under them. The first mismatch means NO; no mismatch means YES.
 *
 * Sample 2: sizes 4 and 4 are equal, but position 0 holds 10 vs 40 -> NO.
 * Cost: O(N1 + N2) - a few straight walks.
 */

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used here
#include <algorithm>  // sort/max/min - not used here
#include <string>     // std::string - not used here
#include <limits.h>   // INT_MIN / INT_MAX - not used here
#include <climits>    // C++ name of the same header - not used here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.


// One node of a singly linked list: a value plus the next node's address.
class Node {
    public:            // usable from outside the class
        int val;       // the data
        Node* next;    // next node's address; NULL for the last node

    // Constructor, runs on `new Node(x)`. `this->val` is the member,
    // plain `val` the parameter.
    Node(int val) {
        this->val = val;      // store the value
        this->next = NULL;    // not linked yet
    }
};

// O(1) append: `tail` remembers the last node, so there is no walk.
// `Node* &` = reference, so the caller's own head/tail are updated.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // `new` builds the node on the heap, returns its address
    if(head == NULL){                // empty list: first and last node
        head = newNode;   // the new node is the first node...
        tail = newNode;   // ...and the last node
        return;   // leave the function now
    }
    
    // Link the new node after the old last node, then move `tail` onto it.
    tail->next = newNode;   // old last node now points at the new node
    tail = newNode; // or tail = tail->next
}

// Count the nodes from head to NULL.
int get_size(Node* head){
    int size = 0;          // counter
    Node* tmp = head;      // walker
    while(tmp!=NULL){      // one pass per node
        tmp = tmp->next;   // step over a node...
        size++;            // ...and count it
    }
    return size;   // number of nodes counted
}

// Prints YES when both lists hold the same values in the same order.
// It prints the answer itself, so it returns nothing (`void`).
void is_similar(Node* head1, Node* head2){
    int size1 = get_size(head1);   // length of list 1
    int size2 = get_size(head2);   // length of list 2

    // Different lengths: they cannot be equal.
    if(size1 != size2){
        cout << "NO" << endl;   // endl = newline + flush
        return;                 // stop: nothing more to check
    }

    // Equal lengths, so both pointers reach NULL together: walk them in step.
    Node* temp1 = head1;   // walker on list 1
    Node* temp2 = head2;   // walker on list 2

    // Round i compares position i of both lists (size1 rounds in total).
    for(int i=0; i<size1; i++){
        int val1 = temp1->val;   // value at position i in list 1
        int val2 = temp2->val;   // value at position i in list 2
        if(val1 != val2){
            cout << "NO" << endl;   // first mismatch decides it
            return;   // leave the function now
        }
        // Both pointers move one node forward.
        temp1 = temp1->next;   // list 1: next position
        temp2 = temp2->next;   // list 2: next position
    }
    // Every position matched.
    cout << "YES" << endl;   // endl = newline + flush
}


int main(){
    Node* head1 = NULL;   // list 1, empty for now
    Node* tail1 = NULL;   // last node of list 1 (none yet)
    
    int val;   // holds each number as it is read
    // First list: values until -1 (a stop sign, not stored).
    while(true){
        cin >> val;          // next integer; spaces/newlines skipped
        if(val == -1){
            break;   // leave the loop; the -1 is not stored
        }
        insert_at_tail(head1, tail1, val);   // append to list 1
    }

    // Second list, read the same way into its own head/tail.
    Node* head2 = NULL;   // list 2: first node (none yet)
    Node* tail2 = NULL;   // list 2: last node (none yet)

    while(true){
        cin >> val;   // read the next integer (spaces/newlines are skipped)
        if(val == -1){
            break;   // leave the loop; the -1 is not stored
        }
        insert_at_tail(head2, tail2, val);   // append to list 2
    }

    is_similar(head1, head2);   // prints YES or NO

    return 0;   // normal exit
}
