/*

Delete the last node of a singly linked list - shown two ways.

Removing the tail is the expensive delete, and it is worth understanding why.
We do keep a `tail` pointer, so we can reach the last node in a single step -
but we cannot remove it from there. The node *before* the tail has to be told
to stop pointing at it, and in a singly list nothing points backwards. The
only way to reach that second-last node is to walk the whole list from the
head. So deleting the tail costs O(n) while deleting the head costs O(1),
even though both remove exactly one node.

The three steps are the same as always: save the victim's address, bend the
arrow (here: cut it, and move `tail` back one node), then `delete`. Freeing
first would leave us walking through memory we had already given back.

This file does not compile. `main` calls `delete_tail(head);` with one
argument, but the function needs two: `delete_tail(head, tail);`. `tail` has
to be passed as well, because the node it points at is the one about to
disappear. The compiler says "too few arguments to function delete_tail".
Nothing else is wrong - fix the call and it runs.

Input: the values of the list, ended by -1.

Example (after the fix): input 10 20 30 40 -1
    before: 10 -> 20 -> 30 -> 40 -> NULL     tail on 40
    after : 10 -> 20 -> 30 -> NULL           tail on 30

*/

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used in this file
#include <algorithm>  // sort/max/min - not used in this file
#include <string>     // std::string - not used in this file
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Node class represents a single element in a linked list: one value plus
// the address of the next node.
class Node {
    public:          // usable from outside the class
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list (NULL = no next node).

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        // Runs automatically on `new Node(x)`.
    Node(int val) {
        // `this` points at the object being built; `this->val` is the member,
        // plain `val` is the parameter with the same name.
        this->val = val;  // Assign the provided value to the 'val' member.
        this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
    }
};

// The usual builder: append a value in O(1), because `tail` is remembered.
// `Node* &head` = a reference to main's pointer, so changes are seen in main.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // `new` makes a node on the heap, returns its address
    if(head == NULL){                // empty list: the new node is first and last
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;   // link after the current last node
    tail = newNode; // or tail = tail->next   (the new node is now the last)
}

// Walk from the head and print every value, one per line.
void print_linked_list(Node* head){
    Node* tmp = head;               // copy of the pointer; `head` itself is not moved
    while(tmp != NULL){             // until we fall off the end
        cout << tmp-> val << endl;  // `->` = member through a pointer; endl = newline + flush
        tmp = tmp->next;            // step forward
    }
}

// Case 1 - the head. No walk at all: there is no node in front of the first
// one, so `head` itself is simply moved forward. O(1).
// (Not called in this file.)
void delete_head(Node* &head){
    Node* deleteNode = head;   // save the old first node
    head = head->next;         // second node becomes first
    delete deleteNode;         // `delete` frees heap memory made by `new`
}

// Case 2 - the middle. Walk to index idx-1, bend its arrow past the victim,
// then free the victim. O(idx).
// (Only used from a commented-out line in main.)
void delete_at_any_position(Node* head, int idx){
    Node* tmp = head;
    for(int i=1; i<idx; i++){     // ends with tmp on index idx-1
        tmp = tmp->next;
    }
    Node* deleteNode = tmp->next; // the victim
    tmp->next = tmp->next->next;  // skip over it
    delete deleteNode;            // free it
}

// Case 3 - the tail. The walk is the whole story here.
// Both pointers are references: `tail` will be moved back one node.
void delete_tail(Node* &head, Node* &tail){
    // Save the box first; in a moment nothing will point at it any more.
    Node* deleteNode = tail;
    Node* tmp = head;          // walker from the start
    // Walk until the node we are standing on is the one pointing at the tail.
    // The test compares *addresses*, not values, so it stops exactly at the
    // second-last node even if two nodes happen to hold the same number.
    // This walk is the O(n) cost of deleting the tail.
    // Trace with 10 20 30 40: tmp=10 (next is 20, not tail) -> tmp=20 ->
    // tmp=30 (next is 40 == tail) -> stop on 30.
    //
    // Trap: on a one-node list `head == tail`, so `tmp->next` is NULL on the
    // very first test, `NULL != tail` is true, and the next round follows a
    // NULL pointer and crashes. A safe version handles `head == tail` first.
    while(tmp->next != tail){
        tmp = tmp->next;
    }
    tmp->next = NULL;       // the second-last node becomes the new end
    tail = tmp;             // and `tail` must follow it - hence the reference
    delete deleteNode;     // only now is it safe to give the old last box back
}

// The same delete written differently: if you already know the index of the
// last node (that is size-1), you can reuse the "delete at any index" walk
// instead of watching for `tmp->next == tail`. The cost is the same O(n)
// walk; only the stopping rule changes. `head` may be taken by value here
// because the first node never moves, but `tail` must be a reference.
// (Not called in this file.)
void delete_tail2(Node* head, Node* &tail, int idx){
    Node* tmp = head;
    // Stop one node early, on index idx-1 - the node before the victim.
    for(int i=1; i<idx; i++){
        tmp = tmp->next;
    }
    Node* deleteNode = tmp->next;   // the last node
    // For the last node this line does the same as `tmp->next = NULL;`,
    // because the node after the last one is NULL anyway. Written this way it
    // is simply the general "skip one node" line reused.
    tmp->next = tmp->next->next;
    delete deleteNode;              // free the old last node
    // Keep `tail` in step: the node we stopped on is now the last one.
    tail = tmp;
}

// Main function: Entry point of the program.
int main(){
    // An empty list to start with.
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    // Read values until the -1 sentinel; -1 itself is never stored.
    while(true){
        cin >> val;           // next integer from input
        if(val == -1){
            break;            // stop reading
        }
        insert_at_tail(head, tail, val);   // append in input order
    }

    print_linked_list(head);   // 10 20 30 40

    // Commented out: would delete index 2 (the third node) instead.
    // delete_at_any_position(head, 2);

    // This is the line that stops the compiler: `delete_tail` also needs
    // `tail`, so write `delete_tail(head, tail);`. After that the list is
    // 10 20 30 and `tail` points at the node holding 30.
    // BUG: too few arguments - `delete_tail` takes (head, tail). Fix: delete_tail(head, tail);
    delete_tail(head);

    print_linked_list(head);   // after the fix: 10 20 30

    return 0;   // normal exit
}
