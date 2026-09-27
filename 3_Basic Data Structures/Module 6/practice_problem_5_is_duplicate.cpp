/*

Take a singly linked list as input and check if the linked 
list is sorted in ascending order.

Input:
1 5 6 8 9 -1

Output:
YES

Input:
2 4 6 5 8 4 -1

Output:
NO

*/

/*
 * (The file name says "duplicate", but this is the "is it sorted?" question.)
 *
 * A list is in ascending order when no node is followed by a smaller value.
 * So we only ever compare neighbours: stand on a node, look at the value in
 * the next node, and if it is smaller the order is broken - answer NO at once.
 * If we reach the last node without finding such a pair, the answer is YES.
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

void ascending_sort_check(Node* head){
    Node* tmp = head;
    // Stop on the last node: it has no neighbour after it to compare with.
    while(tmp->next != NULL){
        // The next value is smaller than this one: not ascending.
        if(tmp->next->val < tmp->val){
            cout << "NO";
            return;
        }
        tmp = tmp->next; // this pair is fine, move one node forward
    }
    cout << "YES";
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // Read values until the stop sign -1 (not stored).
    int val;
    while(cin >> val){
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    ascending_sort_check(head);

    return 0;
}    
    
