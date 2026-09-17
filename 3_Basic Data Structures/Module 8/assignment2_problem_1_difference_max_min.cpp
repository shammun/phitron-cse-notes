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

int find_min(Node* head){
    if(head == NULL){
        return -1;
    }
    Node* tmp = head;
    int min = INT_MAX;

    while(tmp!=NULL){
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
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    int max = find_max(head);
    int min = find_min(head);

    int diff = max - min;

    cout << diff << endl;

    return 0;
}