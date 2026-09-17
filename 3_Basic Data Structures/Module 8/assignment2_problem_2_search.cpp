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

int find_index(Node* head, int val){
    if(head == NULL){
        return -1;
    }
    Node* temp = head;
    int index = 0;

    while(temp != NULL){
        if(temp->val == val){
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int main(){
    
    int T;
    cin >> T;

    while(T--){
        Node* head = NULL;
        Node* tail = NULL;
        
        int V;
        while(true){
            cin >> V;
            if(V == -1){
                break;
            }
            insert_at_tail(head, tail, V);
        }
    
        int X;
        cin >> X;

        int index = find_index(head, X);
        cout << index << endl;

    }

    return 0;
}