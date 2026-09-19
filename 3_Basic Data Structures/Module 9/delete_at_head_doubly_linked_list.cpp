// Delete the head.
//
// The first delete of the module. Two new things come with it: a node has to be
// handed back with `delete`, and the node that becomes the new first one must be
// told that nothing is behind it any more. Three cases: empty list, a list of
// one, and everything else.

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

// The three inserts, unchanged from the files before this one.
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

void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    Node* newNode = new Node(val);
    if(pos==0){
        insert_at_head(head, tail, val);
        return;
    }
    Node* tmp = head;
    for(int i=1; i<pos; i++){
        tmp = tmp->next;
    }
    if(tmp->next == NULL){
        insert_at_tail(head, tail, val);
        return;
    }
    newNode->next = tmp->next;   // the old next node must be dealt with first
    tmp->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
}

void delete_at_head(Node* &head, Node* & tail){
    // Nothing to delete. Without this line the code below would read `head->next`
    // through a NULL pointer and crash.
    if(head==NULL){
        return;
    }

    // Only one node: `head->next` is NULL, so there is no "new head" to move to.
    // The list becomes empty, which means BOTH ends have to become NULL.
    if(head->next == NULL){
        delete head;
        // head = NULL;
        // Correction to an earlier note here: this line IS needed, and leaving it
        // commented out is a real fault, not a style choice. `delete` hands the
        // memory back to the system; it does not change the pointer. `head` still
        // holds the old address, so it is a dangling pointer - it is not NULL,
        // and reading through it is undefined behaviour. The practice copy
        // delete_at_head_doubly_linked_list_p.cpp adds the line.

        tail = NULL;   // same reason: `tail` was aimed at that node too
        return;
    }

    // Normal case, two or more nodes. Save the victim first: after `head` moves,
    // nothing else knows where the old first node lives, and it could never be
    // given back.
    Node* deleteNode = head;
    head = head->next;      // the second node becomes the first
    head->prev = NULL;      // ...and must forget the node behind it, or it would
                            // point at freed memory and print_backward would walk
                            // straight into it
    delete deleteNode;      // now, and only now, give the memory back

    // No walking: O(1). `tail` is untouched, because the end of the list has not
    // moved - unless the list had exactly one node, which is the case above.
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

    insert_at_any_position(head, tail, 2, 200); // 10 20 200 30 100 100

    print_forward(head);

    insert_at_any_position(head, tail, 0, 300); // 300 10 20 200 30 100 100

    print_forward(head);

    insert_at_any_position(head, tail, 5, 400); // 300 10 20 200 30 400 100 100

    print_forward(head);

    // Two head deletes in a row, each dropping the value at the front: first 300,
    // then 10. Neither list is empty afterwards, so the one-node case above is
    // never exercised by this demo.
    delete_at_head(head, tail); // 10 20 200 30 400 100 100

    print_forward(head); // 10 20 200 30 400 100 100

    delete_at_head(head, tail); // 20 200 30 400 100 100

    print_forward(head); // 20 200 30 400 100 100

    return 0;
}
