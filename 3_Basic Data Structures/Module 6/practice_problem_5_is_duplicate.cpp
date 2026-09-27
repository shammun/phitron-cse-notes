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
 * Trace for 2 4 6 5 ...: 2<=4 ok, 4<=6 ok, then 5 < 6 -> NO.
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
        this->next = NULL; // not linked yet
    }
};

// O(1) append using the tail pointer; references (Node* &) so main's pointers change.
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

// Prints YES if every value is <= the next one, otherwise NO.
// (Assumes at least one node: on an empty list tmp would be NULL and
// tmp->next would crash.)
void ascending_sort_check(Node* head){
    Node* tmp = head; // walker
    // Stop on the last node: it has no neighbour after it to compare with.
    while(tmp->next != NULL){
        // The next value is smaller than this one: not ascending.
        if(tmp->next->val < tmp->val){
            cout << "NO";
            return; // done: leave the function
        }
        tmp = tmp->next; // this pair is fine, move one node forward
    }
    cout << "YES"; // no bad pair found
}

int main(){ // the program starts running here
    Node* head = NULL; // empty list
    Node* tail = NULL; // no last node yet

    // Read values until the stop sign -1 (not stored).
    // while(cin >> val) also stops if the input simply ends.
    int val; // each value read
    while(cin >> val){
        if(val == -1){ // stop sign?
            break; // leave the loop
        }
        insert_at_tail(head, tail, val); // append it
    }

    ascending_sort_check(head); // print YES or NO

    return 0; // program finished successfully
}

