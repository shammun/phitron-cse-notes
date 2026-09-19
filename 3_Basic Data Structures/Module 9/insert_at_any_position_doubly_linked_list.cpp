// Insert at any index - the four-link case, and why the order of the four lines
// is not a matter of taste.
//
// Putting a node between two others means four arrows change: two forward and
// two backward. Inserting at the very front or the very back is the same idea
// with one neighbour missing, so those two cases just hand the work to the
// functions written earlier.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_forward(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_backward(Node* tail){
    Node* tmp = tail;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

// Both unchanged from the two files before this one.
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// `pos` counts from 0 and means "after this call, the new value sits at index pos".
void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    // Small flaw, worth knowing about: the node is built before the two special
    // cases are tested. If either of them fires, `insert_at_head` or
    // `insert_at_tail` builds a node of its own and this one is never used or
    // deleted - leaked memory. Creating it after the checks would fix it.
    Node* newNode = new Node(val);

    // Index 0 means "go in front of everything", which is exactly a head insert -
    // and it is a separate case because there is no node before index 0 to hang
    // the new one off.
    if(pos==0){
        insert_at_head(head, tail, val);
        return;
    }

    // Walk to the node that will sit just BEFORE the new one, at index pos-1.
    // `tmp` starts at index 0, so the loop takes pos-1 steps: that is why it
    // counts from 1 and stops at `i < pos`, not `i <= pos`.
    Node* tmp = head;
    for(int i=1; i<pos; i++){
        tmp = tmp->next;
    }

    // Nothing after `tmp`, so `tmp` is the last node and the new value goes on
    // the end. Hand it to insert_at_tail, which also moves the `tail` pointer -
    // the code below would not, and `tail` would be left pointing at the
    // second-last node.
    if(tmp->next == NULL){
        insert_at_tail(head, tail, val);
        return;
    }

    // The real middle case. Standing on `tmp` (say 20) with `tmp->next` (say 30)
    // in front of it, inserting 200 between them:
    newNode->next = tmp->next;   // 200 -> 30
    tmp->next->prev = newNode;   // 200 <- 30
    tmp->next = newNode;         // 20  -> 200
    newNode->prev = tmp;         // 20  <- 200

    // The order of those four lines. The only way to reach node 30 is through
    // `tmp->next`, so both lines that mention 30 must come first. Move line 3 to
    // the top and `tmp->next` is 200 from then on: line 2 would set the new
    // node's own `prev` to itself, and 30 would keep pointing back at 20 while
    // 20 points forward at 200. The forward print would still look perfect and
    // only the backward print would show it.
    //
    // No check is made that `pos` is really between 0 and the list size. Too
    // large a `pos` walks `tmp` past the end and dereferences NULL.
    // Cost: O(n) for the walk, O(1) for the links.
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    print_forward(head); // 10 20 30
    // print_backward(tail);

    insert_at_tail(head, tail, 100);

    print_forward(head); // 10 20 30 100

    insert_at_tail(head, tail, 100); //  10 20 30 100 100

    print_forward(head);

    // The middle case: `tmp` stops on 20 (index 1) and 200 lands at index 2.
    insert_at_any_position(head, tail, 2, 200); // 10 20 200 30 100 100

    print_forward(head);

    // Index 0: straight to insert_at_head, and `head` moves.
    insert_at_any_position(head, tail, 0, 300); // 300 10 20 200 30 100 100

    print_forward(head);

    // Index 5 on a seven-node list: `tmp` stops on 30 (index 4), which still has
    // 100 in front of it, so this is the middle case again, not an append.
    insert_at_any_position(head, tail, 5, 400); // 300 10 20 200 30 400 100 100

    print_forward(head);

    return 0;
}
