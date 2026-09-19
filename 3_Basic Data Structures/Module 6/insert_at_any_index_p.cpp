#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Practice copy of insert_at_any_index.cpp, typed again from memory. The original holds
// the full explanation; this copy repeats the constructor bug, which shows up only at
// the very end of the printing.

class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this->val = val;
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
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

// Insert so that the new node ends up at position `idx`, counting the head as 0.
// To splice a node in you need the node BEFORE the position, because that is the one
// whose `next` has to be changed - a singly linked list has no way back.
void insert_at_any_index(Node* &head, int idx, int val){
    Node* newNode = new Node(val);
    Node* tmp = head;

    // Walk idx-1 steps. Starting the counter at 1 and stopping at `i < idx` is what makes
    // it idx-1 steps, so tmp lands on the node just before the target slot: for idx = 2
    // it takes one step and tmp is the node at index 1.
    for(int i=1; i<idx; i++){
        tmp = tmp->next;
    }

    // The two linking lines, written on one line in this copy but the same as the
    // original. Order matters: grab the rest of the list first, then re-point tmp.
    //   newNode->next = tmp->next;  the new node takes over whatever followed tmp
    //   tmp->next = newNode;        tmp now points at the new node
    // Doing them the other way round would overwrite tmp->next before it was read, and
    // everything after the insertion point would be lost.
    newNode->next = tmp->next;tmp->next = newNode;
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);

    head->next = a;
    a->next = b;

    // Follow the list after each call:
    //   start           10 20 30
    //   idx 2, 1000 ->  10 20 1000 30
    //   idx 2, 2000 ->  10 20 2000 1000 30
    //   idx 3, 3000 ->  10 20 2000 3000 1000 30
    // Each insert walks idx-1 nodes, so an insert costs O(idx) and O(1) extra space.
    insert_at_any_index(head, 2, 1000);
    insert_at_any_index(head, 2, 2000);
    insert_at_any_index(head, 3, 3000);

    // Those six numbers do print correctly, and then the garbage `next` of node 30 takes
    // the printing loop off the end of the list.
    print_linked_list(head);

    return 0;
}