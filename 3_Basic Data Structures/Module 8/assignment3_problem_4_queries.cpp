/*

Problem Statement

You have a singly linked list which is empty initially. Then you will be given Q queries. In each 
query you will be given two values X and V.

If X is 0 that means you will insert the value V to the head of the linked list.
If X is 1 then you will insert the value V to the tail of the linked list.
If X is 2 then you will delete the value Vth index of the linked list. Assume that index starts 
from 0. If the index is invalid, then you shouldn't perform the deletion.
After each query you need to print the linked list.
Note: You must use singly linked list, otherwise you will not get marks.

Input Format

First line will contain Q.
Next Q lines will contain X and V.
Constraints

1 <= Q <= 1000;
0 <= X <= 2;
0 <= V <= 10^9
Output Format

For each query ouput the updated linked list.

Sample Input 0
4
0 10
1 20
1 30
0 40

Sample Output 0
10 
10 20 
10 20 30 
40 10 20 30 

Sample Input 1
11
0 10
2 5
1 20
1 30
0 40
2 0
0 50
2 2
1 60
2 3
2 3

Sample Output 1
10 
10 
10 20 
10 20 30 
40 10 20 30 
10 20 30 
50 10 20 30 
50 10 30 
50 10 30 60 
50 10 30 
50 10 30 

Sample Input 2
10
1 4
2 1
0 9
0 10
2 2
1 5
2 0
2 1
2 5
2 2

Sample Output 2
4 
4 
9 4 
10 9 4 
10 9 
10 9 5 
9 5 
9 
9 
9 

*/

/*
 * A list that starts empty and changes with every query:
 *   X = 0 -> insert V at the head
 *   X = 1 -> insert V at the tail
 *   X = 2 -> delete the node at index V, but only if that index exists
 * and after every query the whole list is printed.
 *
 * The only tricky query is the delete. Valid indexes are 0..size-1, so any
 * V >= size is ignored. Index 0 is the head (move head forward). Any other
 * index: stand on the node one BEFORE it, bend its arrow past the victim,
 * then free the victim. If the victim was the last node, tail moves back.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

class Node {
    public:
        int val;     
        Node* next;

    Node(int val) {
        this->val = val; 
        this->next = NULL;
    }
};

// Count the nodes from head to NULL.
int get_size(Node* head){
    int size = 0;
    Node* tmp = head;
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
}

// X = 0: the new node points at the old head and becomes the head.
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    // Non-empty list: link in front of the old head.
    newNode->next = head;
    head = newNode;
}

// X = 1: walk to the last node and hang the new node after it.
void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    Node* tmp = head;
    // Walk to the last node (O(n); the `tail` pointer would make this O(1)).
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    tail = newNode;
}

// X = 2: remove the node at index `idx` if it exists.
void delete_at_any_position(Node* &head, Node* &tail, int idx){

    // Empty list, or an index past the last node: nothing to delete.
    if(head == NULL || idx >= get_size(head)){
        return;
    }

    // Deleting the head: the second node becomes the head.
    if(idx == 0){
        Node* deleteNode = head;
        head = head->next;
        if(head == NULL){
            // The list is now empty, so there is no last node either.
            tail = NULL;
        }
        delete deleteNode;
        return;
    }

    // Stop on the node just BEFORE the victim: idx-1 steps.
    Node* temp = head;
    for(int i=1; i<idx; i++){
        temp = temp->next;
    }

    // Hold the victim, bend the arrow past it, then free it.
    Node* deleteNode = temp->next;
    temp->next = temp->next->next;

    // We removed the last node: the node before it is the new tail.
    if(temp->next == NULL){
        tail = temp;
    }
    delete deleteNode;
}


void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp-> val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main(){
    int Q;
    cin >> Q;

    Node* head = NULL;
    Node* tail = NULL;

    // One query per round; print the list after each one.
    while(Q--){
        int X, V;
        cin >> X >> V;

        if(X==0){
            insert_at_head(head, tail, V);
        } else if(X==1){
            insert_at_tail(head, tail, V);
        } else if(X==2){
            delete_at_any_position(head, tail, V);
        }
        print_linked_list(head);
    }

    return 0;
}




