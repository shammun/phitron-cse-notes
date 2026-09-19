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

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Node class represents a single element in a linked list.
class Node {
    public:
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
    Node(int val) {
        this->val = val;  // Assign the provided value to the 'val' member.
        this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
    }
};

// The Module 6 helper, unchanged: add a value at the end of the list. It is
// O(1) because `tail` is remembered, so there is no walk. `head` and `tail`
// are taken by reference (`&`), which is what lets `main` see the new ends.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    
    tail->next = newNode;
    tail = newNode; // or tail = tail->next
}

// Walk from the head and print every value. `tmp` is a copy of the pointer,
// so moving `tmp` never moves `head` itself.
void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp-> val << endl;
        tmp = tmp->next;
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
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
}

// Remove the node at 0-based index `idx`.
//
// `head` is taken by value here, and that is only safe because this function
// never removes the first node, so `head` itself never changes. For `idx = 0`
// you must call `delete_head` instead, which takes `Node* &head`.
// Cost: O(idx) - one step per node walked - so O(n) in the worst case.
void delete_at_any_position(Node* head, int idx){
    Node* tmp = head;
    // Counting starts at 1 and stops *before* `idx`, so `tmp` ends on index
    // idx-1: the node just in front of the victim. With idx = 2 the body runs
    // once and `tmp` stands on index 1, the node holding 20.
    for(int i=1; i<idx; i++){
        tmp = tmp->next;
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
    
    int val;
    // Read values until the sentinel -1 arrives. -1 is only a stop sign; it
    // is never stored in the list.
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    print_linked_list(head);   // 10 20 30 40 50, one per line

    // Remove index 2, counting from 0 - the third node, value 30.
    delete_at_any_position(head, 2);

    print_linked_list(head);   // 10 20 40 50 - the 30 is gone

    return 0;
}