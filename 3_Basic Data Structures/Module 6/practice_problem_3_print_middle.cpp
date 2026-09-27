/*

Take a singly linked list as input and print the middle element. If there are multiple 
values in the middle print both.

Input:
2 4 6 8 10 -1

Output:
6

Input:
1 2 3 4 5 6 -1

Output:
3 4
*/

/*
 * A singly list cannot jump to "the middle": we can only walk from the head.
 * So we do it in two passes. First count the nodes (size). Then walk again,
 * stopping at the middle:
 *   odd size, e.g. 5 nodes  -> the middle is index 5/2 = 2 (walk 2 steps)
 *   even size, e.g. 6 nodes -> two middles, index 2 and 3 (walk 6/2-1 = 2
 *                              steps, print that node and the one after it)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

class Node{
    public:
        int val;
        Node* next;
    
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode; // link after the last node...
    tail = newNode;       // ...and make the new node the last one
}

// First pass: count the nodes from head to NULL.
int get_size(Node* head){
    int size = 0;
    Node* tmp = head;
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
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
    
    int size = get_size(head);

    if(size%2 == 0){
        // Even: stop on the FIRST of the two middle nodes (index size/2 - 1).
        Node* tmp = head;
        for(int i=0; i<(size/2) -1; i++){
            tmp = tmp->next;
        }
        // The second middle is simply the next node.
        cout << tmp->val << " " << tmp->next->val;
    } else{
        // Odd: exactly one middle, at index size/2 (5/2 = 2 for 5 nodes).
        Node* tmp = head;
        for(int i=0; i<(size/2); i++){
            tmp = tmp->next;
        }
        cout << tmp->val;
    }
}