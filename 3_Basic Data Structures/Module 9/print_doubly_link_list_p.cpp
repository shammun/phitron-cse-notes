// Practice copy of print_doubly_link_list.cpp - and a good example of how a
// doubly linked list goes wrong. Two things were re-typed differently, and one
// of them makes the program never finish. See the notes on each below.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* prev;

        Node(int val){
            this->val = val;
            // BUG. These two lines should be `this->next = NULL;` and
            // `this->prev = NULL;`. As written, the parameter list has no `next`
            // or `prev`, so the names on the right mean the members themselves:
            // each one is assigned to itself and keeps whatever rubbish happened
            // to be in that memory. The links are never NULL, so nothing marks
            // the ends of the list.
            this->next = next;
            this->prev = prev;
        }
};

void print_forward(Node* head){
    Node* tmp = head;
    // The loop is correct; the data is not. After 30 it reads `tail->next`, which
    // is garbage rather than NULL, so the walk keeps going into random memory and
    // prints whatever numbers it finds - for ever, until the run is cut off.
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
    // Second difference from the original: the `cout << endl;` is missing here,
    // so this function does not close its line. Harmless on its own, but it would
    // glue this output onto whatever prints next.
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    // These four links are set correctly - the four ends that nobody assigns
    // (head->prev and tail->next) are the ones left as garbage.
    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    print_forward(head);   // 10 20 30, then an endless run of junk numbers
    print_backward(tail);  // never reached
}
