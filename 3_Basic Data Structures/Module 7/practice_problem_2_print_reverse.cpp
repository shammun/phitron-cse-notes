/*

Practice Day 02, problem 2: print a singly linked list backwards.

Task, in short: read a singly linked list (values ended by -1) and print its
values from the last one to the first one.

Example
  input:  5 4 8 6 2 1 -1
  output: 1 2 6 8 4 5

(This is the working answer; practice_problem_2_reverse_linked_list.cpp was
meant to do the same but ended up sorting the list instead.)

*/

/*
 * A singly list only lets us walk forwards, so how do we reach the last value
 * first? We let recursion remember the way back.
 *
 * print_reverse(node) does two things, in this order:
 *   1. it asks itself to print everything AFTER this node,
 *   2. and only when that is completely done, it prints this node's value.
 *
 * For 1 -> 2 -> 3 the calls go down 1, 2, 3, NULL. NULL prints nothing and
 * returns; then the call for 3 prints 3, the call for 2 prints 2, the call
 * for 1 prints 1. The pending calls act like a pile of bookmarks that are
 * picked up in the opposite order they were put down.
 *
 * Nothing in the list changes: no arrow is rewired, the list is only read.
 */

#include <iostream>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

class Node {
    public:
        int val;     // the data
        Node* next;  // address of the next node, NULL for the last one

        Node(int val) {
            this->val = val;
            this->next = NULL;
        }
};

// O(1) append: `tail` remembers the last node.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void print_reverse(Node* node){
    // Base case: we walked past the last node, so there is nothing to print.
    if(node == NULL){
        return;
    }
    print_reverse(node->next);   // first print the rest of the list (backwards)
    cout << node->val << " ";    // then this node, after everything behind it
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

    print_reverse(head);
    cout << endl;

    return 0;
}
