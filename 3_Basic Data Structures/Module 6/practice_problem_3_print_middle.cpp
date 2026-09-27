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
 * Time O(n) (two walks), extra memory O(1) beyond the list itself.
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

// First pass: count the nodes from head to NULL.
int get_size(Node* head){
    int size = 0; // count so far
    Node* tmp = head; // walker
    while(tmp!=NULL){ // on a real node
        tmp = tmp->next; // step forward
        size++; // count it
    }
    return size; // number of nodes
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

    int size = get_size(head); // how many nodes there are

    // size % 2 is the remainder after dividing by 2: 0 means even.
    // (An empty list, size 0, would take this branch and then read tmp->val on
    // NULL, which crashes; the problem always gives at least one value.)
    if(size%2 == 0){
        // Even: stop on the FIRST of the two middle nodes (index size/2 - 1).
        Node* tmp = head; // walker
        for(int i=0; i<(size/2) -1; i++){ // size/2 - 1 steps; e.g. 6 nodes -> 2 steps
            tmp = tmp->next; // step forward
        }
        // The second middle is simply the next node.
        cout << tmp->val << " " << tmp->next->val; // e.g. "3 4"
    } else{
        // Odd: exactly one middle, at index size/2 (5/2 = 2 for 5 nodes).
        Node* tmp = head; // walker
        for(int i=0; i<(size/2); i++){ // size/2 steps
            tmp = tmp->next; // step forward
        }
        cout << tmp->val; // e.g. "6"
    }
    // No return 0: main alone may end without one (it then returns 0).
}
