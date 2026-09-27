/*

Practice copy of delete_at_tail.cpp, re-typed from memory.

What differs from the original:
  * the walking version was re-typed under the name `delete_at_tail`, but
    `main` still calls the old name `delete_tail` - "'delete_tail' was not
    declared in this scope", with the compiler suggesting `delete_tail2`.
  * inside that walk, `tmp = tmp->next` lost its semicolon, so the file does
    not even get as far as the call: "expected ';' before '}' token".
  * `delete_tail2` here forgets its `delete deleteNode;`. The node is unlinked
    but its memory is never given back - a memory leak. The program would
    still print the right answer, which is exactly what makes leaks easy to
    miss.

The idea being practised is unchanged: to remove the last node you must walk
from the head to the second-last node, because nothing in a singly list points
backwards. Cut its link, move `tail` back one, then free the old last box.

*/

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used here
#include <algorithm>  // sort/max/min - not used here
#include <string>     // std::string - not used here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Node class represents a single element in a linked list.
class Node {
    public:          // members reachable from outside the class
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        // `this->val` is the member; plain `val` is the parameter.
    Node(int val) {
        this->val = val;  // Assign the provided value to the 'val' member.
        this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
    }
};

// Append in O(1) using the remembered tail. References (`&`) let main see the change.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new heap node
    if(head == NULL){                // empty list: first and last at once
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;   // link after the old last node
    tail = newNode; // or tail = tail->next   (move the tail bookmark)
}

// Print all values, one per line.
void print_linked_list(Node* head){
    Node* tmp = head;                // walker (copy), head stays put
    while(tmp != NULL){              // until past the last node
        cout << tmp-> val << endl;   // print this node's value; endl = newline + flush
        tmp = tmp->next;             // next node
    }
}

// The head is the cheap case: no walk, just move `head` forward. O(1).
void delete_head(Node* &head){
    Node* deleteNode = head;   // save
    head = head->next;         // move head
    delete deleteNode;         // free
}

// The middle case: walk to index idx-1, then skip the victim. O(idx).
void delete_at_any_position(Node* head, int idx){
    Node* tmp = head;
    for(int i=1; i<idx; i++){      // stop on index idx-1
        tmp = tmp->next;
    }
    Node* deleteNode = tmp->next;  // victim
    tmp->next = tmp->next->next;   // bypass it
    delete deleteNode;             // free it
}

// The tail case. Renamed from `delete_tail` in the original - and `main` was
// not renamed with it, which is one of the two compile errors in this file.
// Save the victim, walk to the node before it, cut, move `tail`, then free.
void delete_at_tail(Node* &head, Node* &tail){
    Node* deleteNode = tail;   // remember the last node
    Node* tmp = head;          // walker

    // Walk to the node that points at the tail; addresses are compared, not
    // values. This walk is why deleting the tail costs O(n).
    // The next line is the missing semicolon: the compiler stops with
    // "expected ';' before '}' token".
    while(tmp->next != tail){
        // BUG: missing semicolon after `tmp->next`. Fix: tmp = tmp->next;
        tmp = tmp->next
    }

    tmp->next = NULL;        // the second-last node is the new end
    tail = tmp;              // keep `tail` in step with it
    delete deleteNode;      // and only now free the old last box
}

// The index-based version of the same delete. Look at what is missing at the
// end: there is no `delete deleteNode;`, so the unlinked node stays allocated
// for the rest of the run - a leak that no output ever reveals.
// `idx` is the index of the last node (size-1).
void delete_tail2(Node* & head, Node* &tail, int idx){
    Node* tmp = head;
    // Stop one node early, on index idx-1.
    for(int i=1; i<idx; i++){
        tmp = tmp->next;
    }
    Node* deleteNode = tmp->next;   // the last node
    tmp->next = tmp->next->next; // shouldn't this be tmp->next = NULL; ?
    // Answer to the question on the line above: for the *last* node the two
    // are the same, because `tmp->next->next` is NULL there anyway. Writing
    // `tmp->next = NULL;` just states the intention more plainly.
    // And here `tail` is moved back to the node we stopped on.
    tail = tmp;
    // BUG: memory leak - `deleteNode` is never freed. Fix: add `delete deleteNode;` here.
}

// Main function: Entry point of the program.
int main(){
    Node* head = NULL;   // empty list
    Node* tail = NULL;

    int val;
    while(true){         // read until -1 (not stored)
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    print_linked_list(head);   // the list as read

    // Commented out: would delete index 2 instead of the tail.
    // delete_at_any_position(head, 2);

    // The second compile error: in this file the function is called
    // `delete_at_tail` and it takes two arguments - `delete_at_tail(head,
    // tail);`.
    // BUG: no function named `delete_tail` exists here, and one argument is too few.
    // Fix: delete_at_tail(head, tail);
    delete_tail(head);

    print_linked_list(head);   // after the fix: the list without its last value

    return 0;
}
