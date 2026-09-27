#include <iostream>  // cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // not needed here
#include <string>    // not needed here
using namespace std; // lets us drop the std:: prefix

// Practice copy of insert_at_any_index.cpp, typed again from memory. The original holds
// the full explanation; this copy repeats the constructor bug, which shows up only at
// the very end of the printing.

// One node of the list: a value plus the address of the next node.
class Node{
    public: // usable from outside the class
        int val; // the data
        Node* next; // address of the next node

        // Constructor: runs on every new Node(x); `this` points at the node being built.
        Node(int val){
            this->val = val; // store the value in the member
            // BUG (left in place on purpose): should be `this->next = NULL;`.
            // `next` on the right is the member, still uninitialised, so the node's next
            // holds a garbage address.
            this->next = next;
        }
};

void print_linked_list(Node* head){
    // The loop stops when tmp becomes NULL - that is the only thing that marks the end.
    // Because of the constructor bug the last node's next is garbage, not NULL, so this
    // loop walks past the end of the list and keeps printing whatever it finds in memory
    // until the program is killed. The first six values are still right: their `next`
    // pointers were all set by hand or by the insert function, so only the final one is
    // rubbish.
    // (If the fresh heap memory happens to be zero, the garbage may look like NULL
    // and the program may seem to work; the behaviour is undefined either way.)
    Node* tmp = head; // walker
    while(tmp != NULL){ // BUG effect: may never see NULL
        cout << tmp->val << endl; // print this value
        tmp = tmp->next; // step forward
    }
}

// Insert so that the new node ends up at position `idx`, counting the head as 0.
// To splice a node in you need the node BEFORE the position, because that is the one
// whose `next` has to be changed - a singly linked list has no way back.
void insert_at_any_index(Node* &head, int idx, int val){
    Node* newNode = new Node(val); // the node to insert
    Node* tmp = head; // walker at position 0

    // Walk idx-1 steps. Starting the counter at 1 and stopping at `i < idx` is what makes
    // it idx-1 steps, so tmp lands on the node just before the target slot: for idx = 2
    // it takes one step and tmp is the node at index 1.
    for(int i=1; i<idx; i++){
        tmp = tmp->next; // step forward
    }

    // The two linking lines, written on one line in this copy but the same as the
    // original. Order matters: grab the rest of the list first, then re-point tmp.
    //   newNode->next = tmp->next;  the new node takes over whatever followed tmp
    //   tmp->next = newNode;        tmp now points at the new node
    // Doing them the other way round would overwrite tmp->next before it was read, and
    // everything after the insertion point would be lost.
    newNode->next = tmp->next;tmp->next = newNode;
}

int main(){ // the program starts running here
    Node* head = new Node(10); // position 0
    Node* a = new Node(20); // position 1
    Node* b = new Node(30); // position 2 (its next is garbage because of the BUG)

    head->next = a; // 10 -> 20
    a->next = b; // 20 -> 30

    // Follow the list after each call:
    //   start           10 20 30
    //   idx 2, 1000 ->  10 20 1000 30
    //   idx 2, 2000 ->  10 20 2000 1000 30
    //   idx 3, 3000 ->  10 20 2000 3000 1000 30
    // Each insert walks idx-1 nodes, so an insert costs O(idx) and O(1) extra space.
    insert_at_any_index(head, 2, 1000); // insert 1000 at position 2
    insert_at_any_index(head, 2, 2000); // insert 2000 at position 2
    insert_at_any_index(head, 3, 3000); // insert 3000 at position 3

    // Those six numbers do print correctly, and then the garbage `next` of node 30 takes
    // the printing loop off the end of the list.
    print_linked_list(head);

    return 0; // program finished (if it gets here)
}
