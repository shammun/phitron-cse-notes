/*

https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTabValue=PROBLEM

Implement a Queue (Code360)

Write a queue class with isEmpty(), enqueue(x), dequeue() and front().
dequeue() and front() return -1 when the queue is empty.

Example: enqueue 5, enqueue 7, front() -> 5, dequeue() -> 5, front() -> 7.

This is the FIRST attempt. It is accepted, but it has two weak spots that
code360_implement_a_queue_using_linked_list_updated.cpp fixes:
  1. enqueue() walks the whole list to find the end, so it is O(n).
  2. The constructor writes `int size;`, which declares a NEW local variable
     instead of setting the member `size` to 0, so the member starts as
     garbage. (Nothing reads `size`, so the answers are still right.)

*/

/*
 * Idea
 *
 * A queue on a singly linked list: the front of the queue is `head`, and new
 * values are linked on at the end. Removing at the head is O(1).
 * A queue is First-In-First-Out (FIFO): values leave in the order they came.
 */

// <bits/stdc++.h> is GCC's "include everything" header (iostream, vector, ...);
// here it mainly supplies NULL. The judge supplies its own main().
#include <bits/stdc++.h>

// One node of the list: a value and the address of the node behind it.
class Node {
    public:             // usable from the Queue class
        int data;       // the stored value
        Node* next;     // next node towards the back (NULL for the last node)

        // Constructor, runs on `new Node(data)`. this->data = the member;
        // plain `data` = the parameter with the same name.
        Node(int data) {
            this->data = data;
            next = NULL;    // a new node is not linked to anything yet
        }
};

// The queue. Members declared before `public:` are private (only the class can use them).
class Queue {
    Node *head;     // front of the queue: the oldest value, the next to leave
    Node *tail;     // meant to be the back, but this version never uses it
    int size;       // how many values (never read by anything)
    public:
        // Constructor: runs when a Queue object is created; makes it empty.
        Queue() {
            // Implement the Constructor
            head = NULL;
            tail = NULL;
            int size;   // BUG: a new local variable; the member `size` is not set to 0
                        // (fix: write `size = 0;` without the `int`). Harmless here only
                        // because nothing ever reads the member.
        }

        /*----------------- Public Functions of Queue -----------------*/

        // True when the queue holds no values.
        bool isEmpty() {
            // Implement the isEmpty() function
            return head == NULL;   // no nodes -> empty queue
        }

        // Add a value at the back of the queue.
        void enqueue(int data) {
            // Implement the enqueue() function
            Node* newNode = new Node(data);     // `new` builds the node on the heap

            if (isEmpty()) {
                head = newNode;          // the first value is the front
            } else {
                // Walk to the last node and link the new one after it.
                // `tail` is never used, so this walk makes enqueue O(n).
                Node* tmp = head;
                // Stops ON the last node (the one whose next is NULL).
                while (tmp->next != NULL) {
                    tmp = tmp->next;    // '->' reads a member through a pointer
                }
                tmp->next = newNode;    // hook the new node after the last one
            }
            size++;                     // counts on from garbage (see BUG above)
        }

        // Remove the front value and return it; -1 if the queue is empty.
        int dequeue() {
            // Implement the dequeue() function
            if (isEmpty()) {

                return -1;              // the problem's "nothing to remove" signal
            }

            // Remember the front value, move head to the next node,
            // then free the old front node.
            int data = head->data;
            Node* tmp = head;
            head = head->next;
            delete tmp;                 // `delete` gives the node's memory back
            size--;

            return data;
            // Trace: queue 5 7 -> dequeue returns 5, queue is now 7.
        }

        // Read the front value without removing it; -1 if empty.
        int front() {
            // Implement the front() function
            if (isEmpty()) {
                return -1;
            }
            return head->data;   // the front of the queue is the head node
        }
};