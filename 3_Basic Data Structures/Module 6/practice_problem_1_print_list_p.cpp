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
 * Re-typed copy of practice_problem_1_print_list.cpp: build the list from
 * the input, then walk it once and count the nodes.
 * A list does not store its size, so counting means walking: O(n).
 */

#include <iostream>  // cin and cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // not needed here
#include <string>    // not needed here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// One node: a value plus the address of the next node.
class Node{
    public: // usable from outside the class
        int val; // the data
        Node* next; // address of the next node

    // Constructor: runs on every new Node(x); `this` points at the node being built.
    Node(int val){
        this->val = val; // store the value in the member
        this->next = NULL; // not linked to anything yet
    }
};

// O(1) append using the tail pointer. head and tail are references (Node* &)
// so that main's pointers change when the first node is added.
void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val); // new node on the heap
    if(head==NULL){ // empty list
        head = newNode; // first node
        tail = newNode; // and last node
        return; // done
    }
    tail->next = newNode; // link after the last node...
    tail = newNode;       // ...and make the new node the last one
}

// Walk from head to NULL and add 1 for every node passed.
int get_size(Node* head){
    int size = 0; // count so far
    Node* tmp = head; // walker; head itself is not moved
    while(tmp != NULL){ // on a real node
        tmp = tmp->next; // step forward
        size++; // count it
    }
    return size; // number of nodes (0 for an empty list)
}

int main(){ // the program starts running here
    Node* head = NULL; // empty list
    Node* tail = NULL; // no last node yet

    // Read values until the stop sign -1 (not stored).
    int val; // each value read
    while(true){ // loop until break
        cin >> val; // read one
        if(val == -1){ // stop sign?
            break; // leave the loop
        }
        insert_at_tail(head, tail, val); // append it
    }
    cout << get_size(head); // print the size

    return 0; // program finished successfully
}
