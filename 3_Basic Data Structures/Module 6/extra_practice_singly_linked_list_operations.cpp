/*

Extra practice (Module 6): the six basic singly linked list operations in one program.

Task, in short: build a singly linked list from the input, then support
  - counting its size,
  - displaying it,
  - inserting a value at the head,
  - inserting a value at the tail,
  - inserting a value at a given position (0-based).

Input format used here
  First line: the starting list, values ended by -1.
  Then one command per line until the input ends:
    1 v      insert v at the head
    2 v      insert v at the tail
    3 i v    insert v at index i (0 <= i <= size), otherwise print "Invalid"
    4        print the size
    5        display the list

Example
  input                 output
  10 20 30 -1
  5                     10 20 30
  1 5                   (nothing - a command that changes the list prints nothing)
  2 40
  3 2 15
  3 9 99                Invalid
  5                     5 10 15 20 30 40
  4                     6

*/

/*
 * Nothing new is invented here: every function is one of the moves from this
 * module's lesson files, put side by side so the whole toolkit can be revised
 * in one place.
 *
 * The one idea that ties them together is `Node* &head` (and `Node* &tail`):
 * an insert at the head, or the very first insert into an empty list, has to
 * change main's own head/tail pointer, so the functions receive the pointer
 * itself by reference and not a copy of it.
 */

#include <iostream>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

class Node {
    public:
        int val;     // the data
        Node* next;  // address of the next node, NULL for the last one

        Node(int val) {
            this->val = val;
            this->next = NULL; // not linked to anything yet
        }
};

// Operation: size. Walk from head to NULL and count the nodes. O(n)
int get_size(Node* head){
    int size = 0;
    Node* tmp = head;          // a copy: moving tmp does not move head
    while(tmp != NULL){
        size++;
        tmp = tmp->next;
    }
    return size;
}

// Operation: display. Same walk, printing each value. O(n)
void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Operation: insert at head. O(1)
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    newNode->next = head;      // the new node points at the old first node
    head = newNode;            // and becomes the first node itself
    if(tail == NULL){
        tail = newNode;        // the list was empty: it is also the last node
    }
}

// Operation: insert at tail. O(1), because `tail` remembers the last node.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        // Empty list: the new node is both the first and the last node.
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;      // hang it after the old last node
    tail = newNode;            // it is the new last node
}

// Operation: insert at a position. Walk to the node just BEFORE idx. O(idx)
void insert_at_any_index(Node* &head, Node* &tail, int idx, int val){
    // Index 0 and index size are the head and tail cases above.
    if(idx == 0){
        insert_at_head(head, tail, val);
        return;
    }
    if(idx == get_size(head)){
        insert_at_tail(head, tail, val);
        return;
    }

    Node* newNode = new Node(val);
    Node* tmp = head;
    for(int i = 1; i < idx; i++){   // idx-1 steps: tmp stops at index idx-1
        tmp = tmp->next;
    }
    newNode->next = tmp->next;      // first keep hold of the rest of the list
    tmp->next = newNode;            // then link the new node in after tmp
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // Operation: create. Read values until -1 and append each one.
    int val;
    while(cin >> val && val != -1){
        insert_at_tail(head, tail, val);
    }

    // Commands until the input runs out.
    int cmd;
    while(cin >> cmd){
        if(cmd == 1){
            cin >> val;
            insert_at_head(head, tail, val);
        } else if(cmd == 2){
            cin >> val;
            insert_at_tail(head, tail, val);
        } else if(cmd == 3){
            int idx;
            cin >> idx >> val;
            // Valid places are 0..size (size itself means "after the tail").
            if(idx < 0 || idx > get_size(head)){
                cout << "Invalid" << endl;
            } else{
                insert_at_any_index(head, tail, idx, val);
            }
        } else if(cmd == 4){
            cout << get_size(head) << endl;
        } else if(cmd == 5){
            print_linked_list(head);
        }
    }

    return 0;
}
