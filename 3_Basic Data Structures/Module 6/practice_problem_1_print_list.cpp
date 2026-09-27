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
 * Time O(n) to build and O(n) to count; O(n) memory for the nodes.
 */

#include <iostream>  // cin and cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // not needed here
#include <string>    // not needed here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// One box of the list: a value and the address of the next box.
class Node{
    public: // usable from outside the class
        int val; // the data
        Node* next; // address of the next node

    // Constructor: runs on every new Node(x). `this` points at the node being
    // built; this->val is the member, plain val is the parameter.
    Node(int val){
        this->val = val; // store the value
        this->next = NULL; // a new node points nowhere until it is linked
    }
};

// Append in O(1): `tail` remembers the last node, so there is no walk.
// head and tail are references because the first insert changes both.
// (Node* & = another name for main's pointer, not a copy.)
void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val); // new node on the heap
    if(head==NULL){
        // Empty list: the new node is the first and the last node at once.
        head = newNode;
        tail = newNode;
        return; // done
    }
    tail->next = newNode; // hang the new node after the old last node
    tail = newNode;       // and remember it as the new last node
}

// Count the nodes: one step and one +1 per node, until we fall off the end.
// Returns the number of nodes.
int get_size(Node* head){
    int size = 0; // nodes counted so far
    Node* tmp = head;       // walk with a copy, so head itself never moves
    while(tmp!=NULL){ // standing on a real node?
        tmp = tmp->next; // move to the next one
        size++; // count the node we just left
    }
    return size;            // an empty list returns 0: the loop never runs
}

int main(){ // the program starts running here
    Node* head = NULL; // empty list
    Node* tail = NULL; // no last node yet

    // Read values until -1. The -1 only says "stop"; it is not stored.
    int val; // each value read
    while(true){ // loop until break
        cin >> val; // read one value
        if(val == -1){ // stop sign?
            break; // leave the loop
        }
        insert_at_tail(head, tail, val); // append it
    }
    cout << get_size(head); // print the count (e.g. 7 for the first sample)

    return 0; // program finished successfully
}
