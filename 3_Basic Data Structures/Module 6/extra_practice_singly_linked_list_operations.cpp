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

#include <iostream> // cin and cout
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// One node: a value plus the address of the next node.
class Node {
    public: // usable from outside the class
        int val;     // the data
        Node* next;  // address of the next node, NULL for the last one

        // Constructor: runs on every new Node(x); `this` points at the node being built.
        Node(int val) {
            this->val = val; // store the value in the member
            this->next = NULL; // not linked to anything yet
        }
};

// Operation: size. Walk from head to NULL and count the nodes. O(n)
int get_size(Node* head){
    int size = 0; // count so far
    Node* tmp = head;          // a copy: moving tmp does not move head
    while(tmp != NULL){ // on a real node
        size++; // count it
        tmp = tmp->next; // step forward
    }
    return size; // number of nodes
}

// Operation: display. Same walk, printing each value. O(n)
void print_linked_list(Node* head){
    Node* tmp = head; // walker
    while(tmp != NULL){ // until past the last node
        cout << tmp->val << " "; // value and a space
        tmp = tmp->next; // step forward
    }
    cout << endl; // end the line
}

// Operation: insert at head. O(1)
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val); // new node on the heap
    newNode->next = head;      // the new node points at the old first node
    head = newNode;            // and becomes the first node itself
    if(tail == NULL){
        tail = newNode;        // the list was empty: it is also the last node
    }
}

// Operation: insert at tail. O(1), because `tail` remembers the last node.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val); // new node on the heap
    if(head == NULL){
        // Empty list: the new node is both the first and the last node.
        head = newNode;
        tail = newNode;
        return; // done
    }
    tail->next = newNode;      // hang it after the old last node
    tail = newNode;            // it is the new last node
}

// Operation: insert at a position. Walk to the node just BEFORE idx. O(idx)
// (The caller has already checked 0 <= idx <= size.)
void insert_at_any_index(Node* &head, Node* &tail, int idx, int val){
    // Index 0 and index size are the head and tail cases above.
    if(idx == 0){ // new first node
        insert_at_head(head, tail, val);
        return; // done
    }
    if(idx == get_size(head)){ // right after the last node (keeps tail correct)
        insert_at_tail(head, tail, val);
        return; // done
    }

    Node* newNode = new Node(val); // the node to insert in the middle
    Node* tmp = head; // walker at index 0
    for(int i = 1; i < idx; i++){   // idx-1 steps: tmp stops at index idx-1
        tmp = tmp->next; // step forward
    }
    newNode->next = tmp->next;      // first keep hold of the rest of the list
    tmp->next = newNode;            // then link the new node in after tmp
}

int main(){ // the program starts running here
    Node* head = NULL; // empty list
    Node* tail = NULL; // no last node yet

    // Operation: create. Read values until -1 and append each one.
    // (`cin >> val` is false when input ends, so this also stops at end of input.)
    int val; // each value read
    while(cin >> val && val != -1){
        insert_at_tail(head, tail, val); // append it
    }

    // Commands until the input runs out.
    int cmd; // the command number 1..5
    while(cin >> cmd){ // false once there is nothing left to read
        if(cmd == 1){ // insert at head
            cin >> val; // the value
            insert_at_head(head, tail, val);
        } else if(cmd == 2){ // insert at tail
            cin >> val; // the value
            insert_at_tail(head, tail, val);
        } else if(cmd == 3){ // insert at index
            int idx; // the position
            cin >> idx >> val; // position, then value
            // Valid places are 0..size (size itself means "after the tail").
            if(idx < 0 || idx > get_size(head)){ // || = "or"
                cout << "Invalid" << endl;
            } else{
                insert_at_any_index(head, tail, idx, val);
            }
        } else if(cmd == 4){ // print size
            cout << get_size(head) << endl;
        } else if(cmd == 5){ // display
            print_linked_list(head);
        }
        // Any other number is silently ignored.
    }

    return 0; // program finished successfully
}
