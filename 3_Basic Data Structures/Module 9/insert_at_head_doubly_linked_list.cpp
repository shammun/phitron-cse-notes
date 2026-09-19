// Insert at the head, arrow by arrow.
//
// The singly linked version of this in Module 7 needed two lines: point the new
// node at the old head, then move `head`. Here there is a third, because the old
// head must learn who is now behind it. That one extra line is the whole
// difference, and forgetting it is invisible in a forward print.
//
// Node, the print walks and the `Node* &` reference parameters were explained in
// the files before this one.

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

void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // both its links are NULL for now

    // Empty list. There is no old head to link to, and the new node is the last
    // node as well as the first - so `tail` must move too, or an append later
    // would write through a NULL pointer.
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // Normal case, on 10 20 30 with val = 100:
    newNode->next = head;   // 100 -> 10
    head->prev = newNode;   // 100 <- 10   the line the singly list did not need
    head = newNode;         // 100 is the first node now

    // Done last on purpose. `head` is still the old first node in the two lines
    // above; move it first and you lose the only easy way to reach node 10.
    //
    // No walking happens anywhere here, so the cost is the same for a list of
    // three nodes or three million: O(1).
    // `newNode->prev` is left as the NULL from the constructor, which is correct -
    // nothing comes before the first node.
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    print_forward(head);   // 10 20 30
    // print_backward(tail);

    insert_at_head(head, tail, 100);

    print_forward(head);   // 100 10 20 30

    return 0;
}
