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
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <climits>
using namespace std;

class Node {
    public:
        int val;
        Node* next;

        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};

// O(1) append: `tail` remembers the last node, so there is no walk.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // Link the new node after the old last node, then move `tail` onto it.
    tail->next = newNode;
    tail = newNode;
}

// Walk once, keep the biggest value seen. INT_MIN is below every value,
// so the first node always replaces it.
int find_max(Node* head){
    if(head == NULL){
        return -1;
    }
    Node* tmp = head;
    int max = INT_MIN;

    while(tmp!=NULL){
        if(tmp->val > max){
            max = tmp->val;
        }
        tmp = tmp->next;
    }

    return max;
}

// Mirror image: keep the smallest value, starting from INT_MAX.
int find_min(Node* head){
    if(head == NULL){
        return -1;
    }
    Node* tmp = head;
    int min = INT_MAX;

    while(tmp != NULL){
        if(tmp->val < min){
            min = tmp->val;
        }
        tmp = tmp->next;
    }

    return min;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    // Read values until the stop sign -1 (it is not stored).
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    // Two separate walks over the same list: O(n) each.
    int max = find_max(head);
    int min = find_min(head);

    int diff = max - min; // at most 10^9 - (-10^9) = 2*10^9, still fits in an int

    cout << diff << endl;

    return 0;
}