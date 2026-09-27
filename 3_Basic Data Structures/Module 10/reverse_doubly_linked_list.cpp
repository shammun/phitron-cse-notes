/*

Reverse a doubly linked list by walking in from both ends and swapping the
values as you go.

Here every node has a `prev` as well as a `next`, and that changes everything.
You can put one pointer `i` on the head and another `j` on the tail, swap the
two values, then step `i` forward and `j` backward. After half a pass the
whole list is reversed. Not a single arrow is rewired - the boxes stay exactly
where they are and only the numbers change places - which is why this is so
much shorter than the singly-list version, where each arrow had to be turned
one at a time.

When to stop is the part worth thinking about:

  * odd length (say 5 nodes): the pointers meet on the middle node, `i == j`,
    and that node has nothing to be swapped with.
  * even length (say 4 nodes): they never land on the same node. After the
    last useful swap they cross, and at that moment `j` is exactly one step to
    the left of `i` - that is `i->prev == j`.

Both tests are needed. With only `i != j` an even-length list runs past the
crossing point and swaps every pair back again, undoing the work.

This is also the answer to Practice Day problem 2 (reverse a doubly linked
list and print it). For `10 20 30 40 -1` it prints 10 20 30 40 and then
40 30 20 10.

Watch out when writing the input loop: it must be `while(true)` with `break;`
when -1 arrives. The first version here had `while(tail)` - `tail` is still
NULL before the first insert, so that loop never ran - and `return;`, which
would have left `main` before anything was printed. The `_p.cpp` copy still
has that mistake.

Input: the values of the list, ended by -1.

*/

#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>   // std::vector (a resizable array) - not used in this file
#include <algorithm>   // sort, reverse, swap, max, min ...
#include <string>   // std::string - not used in this file
using namespace std;   // lets us write cout, list ... instead of std::cout, std::list ...

class Node {   // one node: a value plus links to the next AND the previous node
    public:   // members below are usable from outside the class
        int val;   // the value this node carries
        Node* next;   // address of the node after this one (NULL = none)
        Node* prev;   // address of the node before this one (NULL = none)

    Node(int val) {   // constructor: runs on `new Node(x)`
        this->val = val;   // `this->val` = the member, plain `val` = the parameter
        this->next = NULL;   // not linked to anything yet
        this->prev = NULL;   // not linked to anything yet
    }
};

// Everything from here down to `delete_at_any_position` is the Module 9
// doubly-linked-list toolkit, copied in unchanged so this file can stand on
// its own. The new work starts at `reverse_doubly` near the bottom.
//
// Print forward along `next`; print backward along `prev`. A doubly list can
// do both, and that is the whole reason `prev` exists.
void print_forward(Node* head){   // print from the first node to the last, on one line
    Node* tmp = head;   // walker from the first node
    while(tmp != NULL){   // stop after walking off the end
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->next;   // one node forward
    }
    cout << endl;   // end the line (endl = newline + flush)
}

void print_backward(Node* tail){   // print from the last node back to the first, on one line
    Node* tmp = tail;   // walker, starting at the last node
    while(tmp != NULL){   // stop after walking off the end
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->prev;   // step one node backward
    }
    cout << endl;   // end the line (endl = newline + flush)
}

// Inserting: the head and tail cases write two arrows, the middle case four.
// An empty list is the special case in both - the new node becomes head and
// tail at once.
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    newNode->next = head;   // new node points forward to the old first node
    head->prev = newNode;   // old first node points back to the new node
    head = newNode;   // the new node is the first node now
}

// Hang a new node after the last node - O(1), because `tail` is already known.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    tail->next = newNode;   // old last node points forward to the new node
    newNode->prev = tail;   // new node points back to the old last node
    tail = newNode;   // the new node is the last node now
}

// Insert `val` so that it ends up at index `pos` (0-based). O(pos) for the walk.
// Assumes 0 <= pos <= size. (For pos 0 and for an append, `newNode` is not
// used - the helper makes its own - so it leaks; harmless in a short demo.)
void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(pos==0){   // index 0 has no node before it
        insert_at_head(head, tail, val);   // index 0 = an insert at the head
        return;   // leave the function now
    }
    Node* tmp = head;   // walker from the first node
    for(int i=1; i<pos; i++){   // stop on index pos-1 (the node before the spot)
        tmp = tmp->next;   // one node forward
    }
    if(tmp->next == NULL){   // tmp is the last node?
        insert_at_tail(head, tail, val);   // append, keeping input order
        return;   // leave the function now
    }
    newNode->next = tmp->next;   // new node points forward to the old next node
    tmp->next->prev = newNode;   // old next node points back to the new node
    tmp->next = newNode;   // node before points forward to the new node
    newNode->prev = tmp;   // new node points back to the node before
}

// Deleting: unlink, then free. In a doubly list the node before the victim is
// reachable through `prev`, so there is no walk when you already hold the
// node - which is why `delete_at_tail` here is O(1), unlike the singly list.
void delete_at_head(Node* &head, Node* & tail){
    if(head==NULL){   // empty list?
        return;   // leave the function now
    }
    if(head->next == NULL){   // only one node?
        delete head;   // free the only node
        // BUG: the line below is commented out, but it IS needed. `delete` gives
        // the memory back but does not change `head`: it still holds the old
        // address (a dangling pointer), it does NOT become NULL by itself.
        // Fix: remove the `//` so the emptied list really is head = tail = NULL.
        // head = NULL;

        tail = NULL;   // no nodes left, so no last node
        return;   // leave the function now
    }
    Node* deleteNode = head;   // save the first node before head moves
    head = head->next;   // the second node becomes the first
    head->prev = NULL;   // nothing before the new first node
    delete deleteNode;   // free the removed node (`delete` undoes `new`)
}

// Remove the last node - O(1): `tail->prev` gives the new last node with no walk.
void delete_at_tail(Node* &head, Node* &tail){
    Node* deleteNode = tail;   // save the last node before tail moves
    if(head == tail){   // only one node?
        delete deleteNode;   // free the removed node (`delete` undoes `new`)
        head = NULL;   // no nodes left; `delete` does not do this for us
        tail = NULL; // needed: `delete` frees the node but leaves `tail` holding
        // its old address, so without this line `tail` would dangle
        return;   // leave the function now
    }
    tail = tail->prev;   // the second-last node becomes the last - O(1), no walk
    tail->next = NULL;   // nothing after the new last node
    delete deleteNode;   // free the removed node (`delete` undoes `new`)
}

// Remove the node at index `pos` (0-based). O(pos) for the walk.
void delete_at_any_position(Node* &head, Node* &tail, int pos){
    if(pos == 0){   // index 0 has no node before it
        delete_at_head(head, tail);   // index 0 = delete the head
        return;   // leave the function now
    }
    Node* tmp = head;   // walker from the first node
    for(int i=1; i<pos; i++){   // stop on index pos-1 (the node before the spot)
        tmp = tmp->next;   // one node forward
    }
    // BUG: one node too close. tmp stands BEFORE the victim, so for the last
    // node tmp->next is the victim (not NULL); the code below then reads
    // NULL->prev and crashes. Fix: if(tmp->next->next == NULL)
    if(tmp->next == NULL){   // tmp is the last node?
        delete_at_tail(head, tail);   // remove the last node
        return;   // leave the function now
    }
    Node* deleteNode = tmp->next;   // the victim
    tmp->next = tmp->next->next;   // step over the victim
    tmp->next->prev = tmp;   // close the gap from the other side
    delete deleteNode;   // free the removed node (`delete` undoes `new`)
}

// Swap two ints through references, so the caller's values really change.
void swap(int &a, int &b){
    int temp = a;   // keep a's old value
    a = b;   // a gets b
    b = temp;   // b gets a's old value
}


// Reverse the list by swapping values from both ends towards the middle.
//
// `head` and `tail` are references out of habit; they are never assigned here
// because the boxes never move - only the numbers inside them do, so the
// first and last box stay the first and last box.
void reverse_doubly(Node* &head, Node* &tail){
    // The `for` header does three jobs at once: `i` starts at the head and
    // `j` at the tail; the loop runs while they have not met (`i != j`, odd
    // length) and have not crossed (`i->prev != j`, even length); and each
    // round steps `i` one to the right and `j` one to the left.
    //
    // Reading `i->prev` is safe because the two pointers always stop at each
    // other before either can walk off an end - except on an empty list,
    // where `i` starts out NULL and `i->prev` crashes. Guard with
    // `if(head == NULL) return;` if that can happen.
    for(Node *i=head, *j=tail; i!=j && i->prev != j; i=i->next,j=j->prev){
        // Exchange the two ends of the part that is still unreversed.
        swap(i->val, j->val);   // exchange the two values (the nodes stay put)
    }
}

// main: read the list until -1, print it, reverse it, print it again.
int main(){
    Node* head = NULL;   // first node (none yet: the list starts empty)
    Node* tail = NULL;   // last node (none yet)

    int val;   // holds each number as it is read
    // Read until -1. `while(true)`, not `while(tail)`: `tail` is NULL before
    // the first insert, so a `while(tail)` loop would never start.
    while(true){   // repeat until -1
        cin >> val;   // read the next integer (spaces/newlines are skipped)
        if(val==-1){   // -1 ends the input
            // `break;` leaves only the loop, so the prints below still run.
            // (`return;` here would end the whole program.)
            break;   // leave the loop
        }
        insert_at_tail(head, tail, val);   // append, keeping input order
    }

    print_forward(head);   // 10 20 30 40

    reverse_doubly(head, tail);   // reverse by swapping values

    print_forward(head);   // 40 30 20 10
    
    return 0;   // 0 = the program ended normally
}