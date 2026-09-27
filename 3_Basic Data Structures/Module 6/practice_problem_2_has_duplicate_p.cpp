/*

Take a singly linked list as input and check if the linked list contains any duplicate value. You can assume that the maximum value will be 100.

Input:
5 4 8 6 2 1 -1

Output:
NO

Input:
2 4 5 6 7 4 -1

Output:
YES

*/

/*
 * Values are at most 100, so we can keep one yes/no box per possible value:
 * visited[v] says "have I already seen v?". Walk the list once. If the box of
 * the current value is already ticked, this value appeared before - that is a
 * duplicate. Otherwise tick it and move on. One pass, no second loop.
 * (Practice copy of practice_problem_2_has_duplicate.cpp; same code.)
 * Trace for 2 4 5 6 7 4: tick 2, 4, 5, 6, 7; then 4 is already ticked -> YES.
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

// O(1) append using the tail pointer; references so main's pointers change.
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

// Prints YES if some value appears twice, otherwise NO.
void has_duplicate(Node* head){
    // Indexes 0..100, all false: no value has been seen yet.
    // 101 boxes, because the value 100 needs index 100.
    // ({false} sets the first box and C++ fills the rest with false too.)
    bool visited[101] = {false};

    Node* tmp = head; // walker
    while(tmp != NULL){ // visit every node once
        if(visited[tmp->val]){ // already ticked?
            // Seen before: we found a duplicate, no need to look further.
            cout << "YES";
            return; // leave the function now
        }
        visited[tmp->val] = true; // first time: remember this value
        tmp = tmp->next; // step forward
    }
    // Reached the end without a repeat.
    cout << "NO";
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
    has_duplicate(head); // print YES or NO
    // No return 0: main alone is allowed to end without one (it then returns 0).
}
