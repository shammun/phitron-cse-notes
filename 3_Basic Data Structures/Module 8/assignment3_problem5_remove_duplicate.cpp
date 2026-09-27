/*

Problem Statement

You will be given a singly linked list of integer values as input. You need to remove duplicate 
values from the linked list and finally print the linked list.

The process is, for each node N, traverse from that node and delete all nodes where the values are 
same with N.

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

First line will contain the values of the singly linked list, and will terminate with -1.
Constraints

- 1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
- 0 <= V <= 1000; Here V is the value of each node.

Output Format
Output the final linked list where there will be no duplicate values.

Sample Input 0
1 2 3 4 5 -1

Sample Output 0
1 2 3 4 5

Sample Input 1
1 2 4 2 3 5 1 4 5 2 6 1 -1

Sample Output 1
1 2 4 3 5 6

Sample Input 2
5 5 1 1 2 4 2 4 1 3 5 0 -1

Sample Output 2
5 1 2 4 3 0

Sample Input 3
10 10 10 20 20 20 10 20 -1

Sample Output 3
10 20

*/


/*
 * Keep the first copy of every value, delete every later copy - exactly as the
 * statement describes: for each node `outer`, walk the rest of the list and
 * delete every node whose value equals outer->val.
 *
 * The walker `inner` always stands one node BEFORE the node it is checking
 * (it looks at inner->next). That is what a deletion in a singly list needs:
 * the node before the victim, so its arrow can be bent past the victim.
 * After a deletion `inner` stays put, because its new `next` is a node that
 * has not been checked yet. Two nested walks: O(n^2), fine for n <= 1000.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 

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

// Append at the end by walking to the last node (O(n) per value).
void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    Node* tmp = head;
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    tail = newNode;
}


void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp-> val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Delete every later copy of each value, keeping the first one.
void remove_duplicate(Node* &head){
    Node* outer = head;

    while(outer != NULL){
        // `inner` starts on `outer` and inspects the node after it.
        Node* inner = outer;
        while(inner->next != NULL){
            if(outer->val != inner->next->val){
                // Not a copy of outer->val: step forward.
                inner = inner->next;
            } else{
                // A copy: bend inner's arrow past it and free it. `inner` does not move.
                Node* duplicate = inner->next;
                inner->next = inner->next->next;
                delete duplicate;
            }
        }
        // All later copies of outer->val are gone; move to the next value.
        outer = outer->next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    int val;
    // Read values until -1.
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    remove_duplicate(head);

    print_linked_list(head);

    return 0;
}