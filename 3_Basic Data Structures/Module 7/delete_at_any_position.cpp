/*

Delete the node sitting at a given index of a singly linked list.

Every delete in a singly linked list follows the same three steps, and it is
worth saying them out loud once:

    1. stand on the node *before* the one you want to remove,
    2. bend that node's arrow past the victim,
    3. only then `delete` the victim's box.

The order is not a matter of taste. If you free the box first, its `next`
field goes with it, so you no longer know which node came after the victim and
the whole rest of the list is unreachable. That is why we always copy the
victim's address into a separate pointer before touching any arrow.

Why "the node before"? Because in a singly list a node knows only its `next`.
Nothing points backwards, so the only way to make the list skip a node is to
change the `next` of the node standing in front of it.

Input: the values of the list, ended by -1. The index to delete (2) is fixed
in the code.

Example: input 10 20 30 40 50 -1
    before: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    after : 10 -> 20 -> 40 -> 50 -> NULL      (index 2, the 30, is gone)

*/

#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>     // std::vector - not used in this file, left over from a template
#include <algorithm>  // sort, max, min ... - not used here either
#include <string>     // std::string - not used here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::` (we write cout, not std::cout).

// Node class represents a single element in a linked list.
// Each node is a small "box" in memory holding one value plus the address of
// the next box. The boxes can live anywhere in memory; only the `next`
// arrows chain them together in order.
class Node {
    public:              // members below can be used from outside the class (e.g. from main)
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list (NULL for the last node).

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        // It runs automatically when we write `new Node(5)`.
    Node(int val) {
        // `this` is a pointer to the object being built. The parameter is also
        // called `val`, so `this->val` means "the member", plain `val` means
        // "the parameter". `->` reads a member through a pointer.
        this->val = val;  // Assign the provided value to the 'val' member.
        this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
    }
};   // a class definition must end with a semicolon

// The Module 6 helper, unchanged: add a value at the end of the list. It is
// O(1) because `tail` is remembered, so there is no walk. `head` and `tail`
// are taken by reference (`&`), which is what lets `main` see the new ends.
// (Without `&` the function would get copies of the two pointers, and
// changing the copies would not change main's `head` and `tail`.)
void insert_at_tail(Node* &head, Node* &tail, int val){
    // `new Node(val)` asks the heap for one Node, runs the constructor, and
    // returns its address. Heap memory stays alive after the function ends.
    Node* newNode = new Node(val);
    // Empty list: the new node is both the first and the last node.
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;          // done - skip the code below
    }

    // Non-empty list: hook the new node after the current last node...
    tail->next = newNode;
    // ...and move the `tail` bookmark onto it.
    tail = newNode; // or tail = tail->next
}

// Walk from the head and print every value. `tmp` is a copy of the pointer,
// so moving `tmp` never moves `head` itself.
void print_linked_list(Node* head){
    Node* tmp = head;              // start at the first node
    // One pass = print one node, then step to the next. Stops after the last
    // node, when `tmp` becomes NULL.
    while(tmp != NULL){
        // `endl` prints a newline and flushes the output buffer.
        cout << tmp-> val << endl;   // `tmp-> val` is the same as `tmp->val` (spaces are ignored)
        tmp = tmp->next;             // follow the arrow to the next node
    }
}

// Deleting the first node is the easy case: there is no "node before", so we
// simply move `head` one step forward. Same three steps, though - save, move,
// free. Freeing first would make `head = head->next` a read of memory we have
// already given back. `head` has to be a reference: which node is first
// really does change.
// (Not called in this file; kept here so the two deletes sit side by side.)
// Trap: an empty list crashes here. A safe version starts with
// `if(head == NULL) return;`.
void delete_head(Node* &head){
    Node* deleteNode = head;   // 1. remember the old first node
    head = head->next;         // 2. the second node becomes the first
    delete deleteNode;         // 3. `delete` gives the node's memory back to the heap
}

// Remove the node at 0-based index `idx`.
//
// `head` is taken by value here, and that is only safe because this function
// never removes the first node, so `head` itself never changes. For `idx = 0`
// you must call `delete_head` instead, which takes `Node* &head`.
// Cost: O(idx) - one step per node walked - so O(n) in the worst case.
void delete_at_any_position(Node* head, int idx){
    Node* tmp = head;          // walker, starts on index 0
    // Counting starts at 1 and stops *before* `idx`, so `tmp` ends on index
    // idx-1: the node just in front of the victim. With idx = 2 the body runs
    // once and `tmp` stands on index 1, the node holding 20.
    for(int i=1; i<idx; i++){
        tmp = tmp->next;       // one step forward
    }
    // Step 1: remember the box, before any arrow moves away from it.
    Node* deleteNode = tmp->next;
    // Step 2: bend the arrow past it - 20 now points straight at 40. The
    // victim is still whole, it is just nobody's neighbour any more.
    tmp->next = tmp->next->next;
    // Step 3: nothing points at it now, so give the memory back. Had we
    // deleted first, the line above would have read `tmp->next->next` out of
    // a box that no longer belonged to us.
    //
    // Trap: if `idx` is past the end of the list, the walk leaves `tmp` on the
    // last node, `tmp->next` is NULL, and `tmp->next->next` crashes. There is
    // no size check here.
    delete deleteNode;
}

// Main function: Entry point of the program.
int main(){
    // An empty list: no first node and no last node yet.
    Node* head = NULL;
    Node* tail = NULL;

    int val;   // holds each number as it is read
    // Read values until the sentinel -1 arrives. -1 is only a stop sign; it
    // is never stored in the list. `while(true)` loops forever; only `break`
    // gets us out.
    while(true){
        cin >> val;          // `cin >>` skips spaces/newlines and reads the next integer
        if(val == -1){
            break;           // leave the loop, -1 is not added
        }
        insert_at_tail(head, tail, val);   // append, keeping the input order
    }

    print_linked_list(head);   // 10 20 30 40 50, one per line

    // Remove index 2, counting from 0 - the third node, value 30.
    delete_at_any_position(head, 2);

    print_linked_list(head);   // 10 20 40 50 - the 30 is gone

    return 0;   // 0 tells the operating system the program finished normally
}
