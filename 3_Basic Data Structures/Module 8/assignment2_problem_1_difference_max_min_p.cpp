/*

Problem Statement

You need to take a singly linked list of integer value as input and print the difference between
the maximum and minimum value of the singly linked list.

Note: You must use singly linked list to solve this problem, otherwise you will not get marks.

Input Format

Input will contain the values of the singly linked list, and will terminate with -1.
Constraints

1 <= N <= 10^5; Here N is the maximum number of nodes of the linked list.
-10^9 <= V <= 10^9; Here V is the value of each node.
Output Format

Output the difference between the maximum and minimum value.
Sample Input 0

2 4 1 5 3 6 -1
Sample Output 0

5
Sample Input 1

2 -1
Sample Output 1

0

*/

/*
 * max - min needs two numbers: the largest and the smallest value of the list.
 * Each one is a single walk over the list, keeping the best value seen so far
 * (the same running-max idea as with an array). Then subtract.
 *
 * With a single node, max and min are the same node, so the answer is 0.
 *
 * Practice copy of assignment2_problem_1_difference_max_min.cpp - same logic.
 */

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used here
#include <algorithm>  // sort/max/min - not used here
#include <string>     // std::string - not used here
#include <limits.h>   // INT_MIN and INT_MAX
#include <climits>    // C++ name of the same header
using namespace std;  // write cout instead of std::cout

// One node of a singly linked list.
class Node {
    public:   // members below are usable from outside the class
        int val;       // the data
        Node* next;    // address of the next node; NULL for the last

        // Constructor: `this->val` is the member, `val` the parameter.
        Node(int val){
            this->val = val;     // store the value
            this->next = NULL;   // not linked yet
        }
};

// O(1) append: `tail` remembers the last node, so there is no walk.
// References (`&`) let the function update main's head and tail.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new heap node
    if(head == NULL){                // empty list: first and last
        head = newNode;   // the new node is the first node...
        tail = newNode;   // ...and the last node
        return;   // leave the function now
    }

    // Link the new node after the old last node, then move `tail` onto it.
    tail->next = newNode;   // old last node now points at the new node
    tail = newNode;   // the new node is now the last node
}

// Walk once, keep the biggest value seen. INT_MIN is below every value,
// so the first node always replaces it.
int find_max(Node* head){
    if(head == NULL){
        return -1;             // empty list marker
    }
    Node* tmp = head;          // walker
    int max = INT_MIN;         // biggest so far

    while(tmp!=NULL){          // one pass per node
        if(tmp->val > max){
            max = tmp->val;    // new biggest
        }
        tmp = tmp->next;       // step forward
    }

    return max;   // the largest value
}

// Mirror image: keep the smallest value, starting from INT_MAX.
int find_min(Node* head){
    if(head == NULL){
        return -1;             // empty list marker
    }
    Node* tmp = head;          // walker
    int min = INT_MAX;         // smallest so far

    while(tmp != NULL){
        if(tmp->val < min){
            min = tmp->val;    // new smallest
        }
        tmp = tmp->next;   // step to the next node
    }

    return min;   // the smallest value
}

int main(){
    Node* head = NULL;   // empty list
    Node* tail = NULL;   // last node (none yet)

    int val;   // holds each number as it is read
    // Read values until the stop sign -1 (it is not stored).
    while(true){
        cin >> val;   // read the next integer (spaces/newlines are skipped)
        if(val == -1){
            break;   // leave the loop; the -1 is not stored
        }
        insert_at_tail(head, tail, val);   // append at the end, keeping input order
    }

    // Two separate walks over the same list: O(n) each.
    int max = find_max(head);   // walk 1: largest value
    int min = find_min(head);   // walk 2: smallest value

    int diff = max - min; // at most 10^9 - (-10^9) = 2*10^9, still fits in an int

    cout << diff << endl;   // print the answer; endl = newline + flush

    return 0;   // 0 = the program ended normally
}
