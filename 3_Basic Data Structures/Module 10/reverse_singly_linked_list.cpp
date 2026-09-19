/*

Reverse a singly linked list - really reverse it, by turning every arrow
around. This is not the same as printing the list backwards: when this
function is done, the node that used to be last is the one `head` points at,
and the old first node is the one whose `next` is NULL.

The three pointers
------------------
The plain loop version of this uses three pointers, and it is worth naming
them because the recursion below does the same work in a different order:

    prev - the node whose arrow already points the new way (starts at NULL)
    curr - the node whose arrow is being turned this round
    next - the node that comes after `curr`, saved before anything moves

    while(curr != NULL){
        next = curr->next;   // SAVE first
        curr->next = prev;   // turn one arrow: curr now points backwards
        prev = curr;         // the pair shuffles one step to the right
        curr = next;
    }
    head = prev;

Exactly one arrow is turned each round - the arrow belonging to `curr`. And
`next` has to be saved *before* `curr->next = prev` overwrites it: that field
was the only thing that knew where the rest of the list is. Lose it and the
remainder of the list is gone for good.

The recursive version used here
-------------------------------
Recursion gets the same safety for free. Each call goes forward first and only
turns an arrow on the way back, so when a call finally does its work its own
`temp->next` has not been touched yet - the recursion stack is doing the job
that `next` does in the loop.

For 10 -> 20 -> 30 -> 40 the calls run down to 40, and then, coming back out:

    at 40 (the base case):  head = 40
    at 30:  temp->next is 40, so 40->next = 30, and 30->next = NULL
    at 20:  temp->next is 30, so 30->next = 20, and 20->next = NULL
    at 10:  temp->next is 20, so 20->next = 10, and 10->next = NULL

Each of those NULLs is overwritten a moment later by the node behind it -
except the last one, on the old head, which is what correctly ends the new
list. Result: 40 -> 30 -> 20 -> 10.

Cost: O(n) time, and O(n) memory for the recursion stack - the one thing the
loop version does better.

Input: the values of the list, ended by -1.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>   // for `list`, the ready-made doubly linked list
                    // used later in this module; not needed by this file
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

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

// Append a value at the end in O(1): `tail` already points at the last node,
// so there is no walk. Both ends are taken by reference, so `main` sees them
// change.
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

// Print forward: follow `next` from the head until it runs out.
void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp-> val << endl;
        tmp = tmp->next;
    }
}

// Print the values backwards *without changing the list*: each call prints
// everything after itself first, and only then its own value. Handy to
// compare with the real reversal below - this one leaves every arrow as it
// was. (Defined here for comparison; `main` does not call it.)
void print_reverse(Node* temp){
    if(temp == NULL){
        return;
    }
    print_reverse(temp->next);
    cout << temp->val << endl;
}

// Reverse the list itself. `temp` is the node this call is standing on; it
// starts at the head and walks forward, one node per call.
//
// Trap: an empty list crashes here, because the first thing the function
// does is read `temp->next` while `temp` is NULL. Check `head == NULL`
// before calling.
void reverse_linked_list(Node* &head, Node* &tail, Node* temp){
    // Base case: nothing after `temp`, so `temp` is the old last node - and
    // the old last node is the new first one. `head` is a reference, so this
    // really moves `main`'s head. No arrow is turned here: `temp`'s own
    // `next` will be filled in by the node behind it, one level up.
    if(temp->next == NULL){
        head = temp;
        return;
    }
    // Go all the way forward first. When this returns, everything from
    // `temp->next` onwards is already reversed - and `temp->next` itself is
    // untouched, still pointing at the node in front. That is our saved
    // "next" pointer; the recursion held it for us.
    reverse_linked_list(head, tail, temp->next);
    // Turn exactly one arrow: the node in front of me is made to point back
    // at me. (`temp->next` is that node; `temp->next->next` is its arrow.)
    temp->next->next = temp;
    // Cut my own old forward arrow. Without this line the last two nodes
    // would point at each other and `print_linked_list` would never stop.
    // For every node except the old head this NULL is overwritten by the
    // node behind it on the next level out.
    temp->next = NULL;
    // The old head is the new tail. Every level writes this; the outermost
    // call - the one standing on the old head - writes last and so wins.
    tail = temp;
}

int main(){
    // Start with an empty list.
    Node* head = NULL;
    Node* tail = NULL;
    
    int val;
    // Read values until -1; the -1 is only a stop sign and is not stored.
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    cout << endl;

    cout << "Before reversing: The linked list is :" << endl;
    
    print_linked_list(head);

    // Node* temp = head;
    // The third argument is where the walk starts: the head. The first two
    // are the list ends the function has to update, which is why they are
    // references.
    reverse_linked_list(head, tail, head);

    cout << "After reversing: The linked list is :" << endl;
    print_linked_list(head);

    return 0;
}