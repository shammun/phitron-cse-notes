/*

Problem Statement

You need to take a singly linked list of integer values as input. Afterward, you will be 
given an integer value X. Your task is to determine whether X is present in the linked list 
or not. If it is present, print its first index from the left side; otherwise, print -1. 
Assume that the linked list's index starts with 0.

Note: You must use a singly linked list; otherwise, you will not receive marks.

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain the values of the singly linked list, and will 
terminate with -1.
Second line of each test case will contain X.
Constraints

1 <= T <= 100
1 <= N <= 10^5; Here N is the maximum number of nodes of the linked list.
-10^9 <= V <= 10^9; Here V is the value of each node.
-10^9 <= X <= 10^9
Output Format

Output the index of X in the linked list.
Sample Input 0

4
1 2 3 4 5 -1
3
1 2 3 -1
5
1 -1
1
10 20 -1
20
Sample Output 0

2
-1
0
1

*/

/*
 * Search in a list = walk from the head and count the steps. The counter
 * `index` starts at 0 (the head's index) and goes up by one for every node we
 * pass. The first node whose value equals X gives the answer, and we return at
 * once so a later copy of X cannot overwrite it. If the walk falls off the
 * end, X is not in the list: -1.
 *
 * There are T test cases, so every case starts a brand-new empty list.
 *
 * Practice copy of assignment2_problem_2_search.cpp - same logic.
 * Trace of case 4: list 10 20, X = 20 -> index 0: 10 no; index 1: 20 yes -> 1.
 */

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used here
#include <algorithm>  // sort/max/min - not used here
#include <string>     // std::string - not used here
#include <limits.h>   // INT_MIN / INT_MAX - not used here
#include <climits>    // C++ name of the same header - not used here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// One node of a singly linked list.
class Node {
    public:   // members below are usable from outside the class
        int val;       // the data
        Node* next;    // next node's address; NULL for the last node

        // Constructor: `this->val` is the member, `val` the parameter.
        Node(int val){
            this->val = val;     // store the value
            this->next = NULL;   // not linked yet
        }
};

// O(1) append: `tail` remembers the last node, so there is no walk.
// `Node* &head` is a reference to main's pointer, so main sees the change.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // `new` builds the node on the heap, returns its address
    if(head == NULL){                // empty list: first and last node at once
        head = newNode;   // the new node is the first node...
        tail = newNode;   // ...and the last node
        return;   // leave the function now
    }

    // Link the new node after the old last node, then move `tail` onto it.
    tail->next = newNode;   // old last node now points at the new node
    tail = newNode;   // the new node is now the last node
}

// Return the first index holding `val`, or -1 if it is not there.
int find_index(Node* head, int val){
    if(head == NULL){
        // Empty list: nothing can match.
        return -1;   // -1 = "not found / nothing there"
    }

    Node* tmp = head;   // walker, starts on index 0
    int index = 0;      // index of the node tmp stands on

    // One pass per node: check, then step and count. Ends at NULL.
    while(tmp != NULL){
        if(tmp->val == val){
            // First match: stop here, this is the leftmost position.
            return index;   // index of the first match
        }
        tmp = tmp->next;   // next node
        index++;           // its index
    }

    return -1;             // no match anywhere
}

int main(){
    int T;       // number of test cases
    cin >> T;   // number of test cases

    // One test case per round; a fresh head/tail makes a new empty list.
    // `while(T--)` runs the body T times (tests T, then subtracts 1).
    while(T--){
        Node* head = NULL;   // new empty list for this case
        Node* tail = NULL;   // last node (none yet)

        int val;             // one value of the list
        // Read this case's values until -1.
        while(true){
            cin >> val;        // next integer
            if(val == -1){
                break;         // end of this list; -1 not stored
            }
            insert_at_tail(head, tail, val);   // append at the end, keeping input order
        }

        int X;         // value to search for
        cin >> X;   // the value to search for

        int index = find_index(head, X);   // first index of X, or -1
        cout << index << endl;             // endl = newline + flush
    }

    return 0;   // 0 = the program ended normally
}