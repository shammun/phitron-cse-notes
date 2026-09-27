/*

Implement a Queue - Queue Using Array or Singly Linked List (Code360)
https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908

The problem, in my own words
  Build a queue class by hand (no STL queue) with:
    isEmpty()       true if the queue holds nothing
    enqueue(data)   add data at the back
    dequeue()       remove the front value and return it; -1 if empty
    front()         return the front value without removing it; -1 if empty
  You may use an array or a singly linked list; this solution uses the list.

Input used by the test driver
  q, then q commands: "enqueue x", "dequeue", "front" or "isEmpty".

Sample
  enqueue 10, enqueue 20, front -> 10, dequeue -> 10, dequeue -> 20,
  isEmpty -> true, dequeue -> -1, enqueue 30, front -> 30

*/

/*
 * The idea: a queue adds at one end and removes at the other (FIFO = first
 * in, first out, like a line at a shop). In a singly linked list:
 *   - removing is O(1) at the head (just move head forward),
 *   - adding is O(1) at the tail, IF we remember a `tail` pointer.
 * So the head is the front of the queue and the tail is the back.
 *
 *   enqueue 10, 20:   head -> [10] -> [20] <- tail
 *                     front              back
 *
 * The one tricky case: when dequeue removes the LAST node, head becomes NULL
 * and tail must become NULL too - otherwise tail still points at a deleted
 * node and the next enqueue would write into freed memory.
 *
 * Note: there is no #include or main() here. Code360 only asks for the
 * class; the judge's own hidden code includes the headers, reads the
 * commands and calls these functions.
 */

// A node of the singly linked list: one value and a pointer to the node
// behind it (the next one in the line).
class Node {
    public:                          // members below can be used from outside the class
        int data;                    // the value stored in this node
        Node* next;                  // address of the next node; NULL means "no next node"
        // Constructor: runs automatically when a Node is created with new Node(x).
        Node(int data){
            this->data = data;       // `this` points at the node being built; this->data is the member,
                                     // plain `data` is the parameter with the same name
            this->next = NULL;       // a brand-new node is not linked to anything yet
        }
};

// The queue itself. Members before `public:` are private (class default):
// only the queue's own functions may touch head and tail.
class Queue {
    Node* head;   // front of the queue (removed first)
    Node* tail;   // back of the queue (newest value)

public:
    // Constructor: a new queue starts empty, so both ends point at nothing.
    Queue() {
        head = NULL;   // no front node yet
        tail = NULL;   // no back node yet
    }

    // True when there is no front node, i.e. the queue holds nothing.
    bool isEmpty() {
        return head == NULL;   // the comparison itself is true/false, so return it directly
    }

    // Add `data` at the back of the queue. O(1) thanks to the tail pointer.
    void enqueue(int data) {
        Node* newNode = new Node(data);   // `new` makes a node on the heap (it lives until delete)
                                          // and gives back its address
        if(head == NULL){
            // Empty queue: the new node is both the front and the back.
            head = newNode;
            tail = newNode;
            return;                       // done; skip the lines below
        }
        tail->next = newNode;   // hook it behind the current back (-> means "member of the
                                // object this pointer points to", same as (*tail).next)
        tail = newNode;         // it is the new back
    }

    // Remove the front value and return it; -1 if the queue is empty.
    int dequeue() {
        if(head == NULL){
            return -1;          // nothing to remove
        }
        int val = head->data;   // save the value before the node is freed
        Node* deleteNode = head;   // remember the old front so we can free it
        head = head->next;         // the second node (or NULL) becomes the front
        delete deleteNode;         // `delete` gives the node's memory back (avoids a memory leak)
        if(head == NULL){
            tail = NULL;        // the queue became empty: reset the back too
        }
        return val;             // e.g. queue 10 20: returns 10, queue is now 20
    }

    // Look at the front value without removing it; -1 if empty.
    int front() {
        if(head == NULL){
            return -1;          // no front value to show
        }
        return head->data;      // value stored in the front node
    }
};
