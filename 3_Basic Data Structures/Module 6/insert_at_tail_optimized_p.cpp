#include <iostream>  // cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // not needed here
#include <string>    // not needed here
using namespace std; // lets us drop the std:: prefix

// Practice copy of insert_at_tail_optimized.cpp, typed again from memory. Read the
// original for the full story; this copy has two typos and does not compile.

// One node of the list: a value plus the address of the next node.
class Node{
    public: // usable from outside the class
        int val; // the data
        Node* next; // address of the next node

        // Constructor: runs on every new Node(x); `this` points at the node being built.
        Node(int val){
            this->val = val; // store the value in the member
            // Same BUG as insert_at_tail_p.cpp: `next` here is the member itself, which
            // holds nothing yet, so the node's next ends up as garbage instead of NULL.
            // Fix: this->next = NULL;
            this->next = next;
        }
};

// The optimization: keep a second pointer, `tail`, always aimed at the last node. Then
// inserting at the end needs no walk at all - two assignments and you are done, O(1)
// instead of the O(n) walk in insert_at_tail.cpp.
// Both head and tail come in as `Node* &` because both can change here and main must see
// it. (The original names this function insert_at_tail; the copy renamed it.)
void insert_at_tail_optimized(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val); // the node to add

    // Empty list: the single new node is both the first and the last node, so head and
    // tail must both be set. Forgetting tail here is the classic mistake - the next
    // insert would then write through a tail that points nowhere.
    if(head == NULL){
        head = newNode; // first node
        tail = newNode; // last node
        return; // done
    }

    tail->next = newNode;   // hang the new node off the current last node
    tail = newNode;         // the new node is now the last (same as tail = tail->next)
    // Order matters again: move tail first and you lose the link to the old last node.
}

// Print every value, one per line.
void print_linked_list(Node* head){
    Node* tmp = head; // walker
    while(tmp != NULL){ // until past the last node
        cout << tmp->val << endl; // print this value
        tmp = tmp->next; // step forward
    }
}

int main(){ // the program starts running here
    // 10 -> 20 -> 30 again, but the third node is called `tail` from the start, because
    // the insert function needs a pointer to the last node.
    Node* head = new Node(10); // first node
    Node* a = new Node(20); // second node
    Node* tail = new Node(30); // third (last) node

    head->next = a; // 10 -> 20
    // BUG (left in place on purpose): there is no `b` in this file - the third node was
    // named `tail`. The compiler stops right here with "'b' was not declared in this
    // scope", which is why the program produces no output at all.
    // Fix: a->next = tail;
    a->next = b;

    // Intended result: 10 20 30 100 200 300, with each insert costing O(1).
    insert_at_tail_optimized(head, tail, 100); // append 100
    insert_at_tail_optimized(head, tail, 200); // append 200
    insert_at_tail_optimized(head, tail, 300); // append 300
    print_linked_list(head); // print the list

    return 0; // program finished (if it compiled)
}
