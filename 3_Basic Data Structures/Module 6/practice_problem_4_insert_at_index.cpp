/*

Take a singly linked list as input, then take q queries. In each query
you will be given an index and value. You need to insert those values in
the given index and print the linked list. If the index is invalid
print “Invalid”.

Input:
10 20 30 -1
1 40
5 50
4 50
0 100
7 40
1 110
7 40

Output:
10 40 20 30
Invalid
10 40 20 30 50
100 10 40 20 30 50
Invalid
100 110 10 40 20 30 50
100 110 10 40 20 30 50 40


*/

/*
 * Every query is "put value v at index idx". For a list of `size` nodes the
 * valid indexes are 0..size:
 *   idx == 0          -> the new node becomes the head   (insert_at_head)
 *   idx == size       -> the new node goes after the tail (insert_at_tail)
 *   0 < idx < size    -> walk to the node at idx-1 and hook the new node in
 *   anything else     -> "Invalid", the list is not touched
 * After every valid query the whole list is printed on one line.
 */

#include <iostream>  // cin and cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // not needed here
#include <string>    // not needed here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// One node: a value plus the address of the next node.
class Node{
    public: // usable from outside the class
        int val; // the data
        Node* next; // address of the next node

    // Constructor: runs on every new Node(x); `this` points at the node being built.
    Node(int val){
        this->val = val; // store the value in the member
        this->next = NULL; // not linked yet
    }
};

// The new node points at the old head, then becomes the head. O(1).
// Node* &head: a reference, so main's head really changes.
void insert_at_head(Node* &head, int val){
    Node* newNode = new Node(val); // new node on the heap
    newNode->next = head; // link it in front of the old first node
    head = newNode; // it is now the first node
}

// O(1) append using the remembered last node.
void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val); // new node on the heap
    if(head==NULL){ // empty list
        head = newNode; // first node
        tail = newNode; // and last node
        return; // done
    }
    tail->next = newNode; // attach after the last node
    tail = newNode; // it is the new last node
}

// Insert strictly inside the list (0 < idx < size).
void insert_at_any_index(Node* &head, int idx, int val){
    Node* newNode = new Node(val); // the node to insert
    Node* tmp = head; // walker at index 0

    // Stop one node BEFORE the target index: idx-1 steps from the head.
    for(int i=1; i<idx; i++){
        tmp = tmp->next; // step forward
    }
    newNode->next = tmp->next; // first grab the rest of the list...
    tmp->next = newNode;       // ...then hang the new node after tmp
}

// Count the nodes by walking from head to NULL. O(n).
int get_size(Node* head){
    int size = 0; // count so far
    Node* tmp = head; // walker
    while(tmp!=NULL){ // on a real node
        tmp = tmp->next; // step forward
        size++; // count it
    }
    return size; // number of nodes
}

// Print the list on one line, values separated by spaces.
void print_linked_list(Node* head){
    Node* tmp = head; // walker
    while(tmp != NULL){ // until past the last node
        cout << tmp->val << " "; // value and a space
        tmp = tmp->next; // step forward
    }
    cout << endl; // end the line
}

int main(){ // the program starts running here
    Node* head = NULL; // empty list
    Node* tail = NULL; // no last node yet

    // Read the starting list until the stop sign -1.
    // `cin >> val` is itself true when a number was read and false when input
    // ends, so this stops on -1 OR at end of input. && checks the left side first.
    int val; // each value read
    while(cin >> val && val != -1){
        insert_at_tail(head, tail, val); // append it
    }

    // The queries run until the input ends.
    // (cin >> idx >> val becomes false when there is nothing more to read.)
    int idx; // the index of the current query
    while(cin >> idx >> val){
        int size = get_size(head);  // the valid range depends on the current size
        if(idx < 0 || idx > size){ // || means "or": either one makes it invalid
            cout << "Invalid" << endl;
            continue;               // nothing inserted, nothing printed
            // (continue jumps straight to the next round of the while loop)
        }
        // Exactly one branch runs ("else if"): on an empty list idx 0 is
        // both "head" and "size", and it must be inserted only once.
        if(idx == 0){ // new first node
            insert_at_head(head, val);
            if(tail == NULL){
                tail = head;        // the first node is also the last one
            }
        } else if(idx == size){ // right after the last node
            insert_at_tail(head, tail, val);
        } else{ // somewhere in the middle
            insert_at_any_index(head, idx, val);
        }
        print_linked_list(head); // show the list after this query
    }

    return 0; // program finished successfully
}
