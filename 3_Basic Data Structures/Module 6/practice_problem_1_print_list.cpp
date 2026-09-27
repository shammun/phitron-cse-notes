/*

Take a singly linked list as input and print the size of the linked list.

Input:
2 1 5 3 4 8 9 -1

Output:
7

Input:
5 1 4 5 -1

Output:
4

*/

/*
 * The size of a list is not stored anywhere: a list only knows where its
 * first node is. So we count the nodes the only way we can - start at the
 * head, follow `next` one node at a time and add 1 for every node we stand
 * on, until `next` leads to NULL.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// One box of the list: a value and the address of the next box.
class Node{
    public:
        int val;
        Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL; // a new node points nowhere until it is linked
    }
};

// Append in O(1): `tail` remembers the last node, so there is no walk.
// head and tail are references because the first insert changes both.
void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        // Empty list: the new node is the first and the last node at once.
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode; // hang the new node after the old last node
    tail = newNode;       // and remember it as the new last node
}

// Count the nodes: one step and one +1 per node, until we fall off the end.
int get_size(Node* head){
    int size = 0;
    Node* tmp = head;       // walk with a copy, so head itself never moves
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;            // an empty list returns 0: the loop never runs
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // Read values until -1. The -1 only says "stop"; it is not stored.
    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }
    cout << get_size(head);

    return 0;
}
