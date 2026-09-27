/*

Practice copy of reverse_doubly_linked_list.cpp, re-typed from memory.

What is new here: a second way to reverse, `reverse_doubly_1`, which turns the
list around for real instead of moving values about. For every node it swaps
the two pointer fields - `next` becomes `prev` and `prev` becomes `next` - and
then swaps `head` with `tail`. The value-swapping version from the original is
kept as `reverse_doubly_2`, and that is the one `main` calls, so the output is
the same as the original's.

Two things to watch:

  * `reverse_doubly_1` takes `Node* head, Node* tail` *by value*, so its
    closing `swap(head, tail)` only swaps two local copies and `main`'s head
    and tail are left pointing at the wrong ends of the list. It needs
    `Node* &head, Node* &tail`.
  * the first version's input-loop bugs are still here: `while(tail)` never
    starts (tail is NULL), and the bare `return;` inside it does not compile
    in `int main` ("return-statement with no value"). So this file does not
    compile; with `while(true)` and `break;` it would work.

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

// Everything down to `delete_at_any_position` is the Module 9 doubly-list
// toolkit, unchanged. The two reversal functions are near the bottom.
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

// Put a new node in front of the first node - O(1).
// `Node* &head` = a REFERENCE to the caller's pointer (not a copy), so
// when this function moves head/tail, main's own head/tail move too.
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

// Remove the first node - O(1).
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

// Swap two ints. Note: this one only matches `int` arguments - see below.
void swap(int &a, int &b){
    int temp = a;   // keep a's old value
    a = b;   // a gets b
    b = temp;   // b gets a's old value
}


// Reversal, approach 1: rewire the list properly. Every node's two arrows
// change places, and the two ends of the list change places with them.
void reverse_doubly_1(Node* head, Node* tail){
    Node* tmp = head;   // walker from the first node
    while(tmp != NULL){   // stop after walking off the end
        // This is the standard library's `swap` from <algorithm>, not the
        // `swap(int&, int&)` above: these arguments are `Node*`, not `int`.
        // After it, the node's `next` holds what used to be its `prev`.
        swap(tmp->next, tmp->prev);
        // Move on through `prev`, because `prev` is now carrying the old
        // `next` - the direction we still have to travel. Using `tmp->next`
        // here would send us straight back the way we came.
        tmp = tmp->prev;   // step one node backward
    }
    // The first node is now the last one, so the two ends must trade places
    // too. Except that `head` and `tail` were passed by value, so this swaps
    // two copies and `main` never sees it.
    // BUG: by-value parameters. Fix: `Node* &head, Node* &tail`.
    swap(head, tail);   // swaps the two LOCAL copies only (see BUG)
}

// Reversal, approach 2: leave every arrow alone and swap the values instead.
// `i` comes in from the head, `j` from the tail; they stop when they meet
// (`i == j`, odd length) or cross (`i->prev == j`, even length). Both tests
// are needed, or an even-length list gets swapped back to where it started.
void reverse_doubly_2(Node* &head, Node* &tail){
    for(Node* i=head, *j=tail; i!=j && i->prev != j; i=i->next, j=j->prev){   // i from the front, j from the back
        swap(i->val, j->val);   // exchange the two values (the nodes stay put)
    }
}

// main: read the list until -1, print it, reverse it, print it again.
int main(){
    Node* head = NULL;   // first node (none yet: the list starts empty)
    Node* tail = NULL;   // last node (none yet)

    int val;   // holds each number as it is read
    // BUG: `tail` is NULL here, so this loop never starts and nothing is read.
    // Fix: `while(true)` with `break;` on -1.
    while(tail){
        cin >> val;   // read the next integer (spaces/newlines are skipped)
        if(val==-1){   // -1 ends the input
            // BUG: a bare `return;` in `int main` does not compile. Fix: `break;`
            return;   // leave the function now
        }
        insert_at_tail(head, tail, val);   // append, keeping input order
    }

    print_forward(head);   // print the list on one line

    // The value-swap version; `reverse_doubly_1` above is left unused.
    reverse_doubly_2(head, tail);   // reverse by swapping values

    print_forward(head);   // print the list on one line
    
    return 0;   // 0 = the program ended normally
}