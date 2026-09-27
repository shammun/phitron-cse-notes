/*

https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTabValue=PROBLEM

Implement a Queue (Code360) -- improved version

Same task as code360_implement_a_queue_using_linked_list.cpp. This version
fixes its two weak spots: `size` really starts at 0, and a `tail` pointer
makes enqueue() O(1) instead of walking the whole list.

Example: enqueue 5, enqueue 7, front() -> 5, dequeue() -> 5, front() -> 7.

*/

/*
 * Idea
 *
 * head = front of the queue (values leave here), tail = back of the queue
 * (values join here). Both ends are reached directly, so every operation
 * is O(1). A queue is First-In-First-Out: the oldest value leaves first.
 */

// <bits/stdc++.h> = GCC's "include everything" header; here it supplies NULL.
// The judge provides main() and calls these methods.
#include <bits/stdc++.h>

// One node: a value plus the address of the node behind it in the queue.
class Node {
    public:
        int data;       // the stored value
        Node* next;     // next node towards the back (NULL at the back)

        // Constructor, runs on `new Node(data)`; this->data is the member,
        // plain data the parameter.
        Node(int data) {
            this->data = data;
            next = NULL;
        }
};

// The queue. Members before `public:` are private to the class.
class Queue {
    Node *head;     // front: the next value to leave
    Node *tail;     // back: the value that joined last
    int size;       // number of values inside
    public:
        // Constructor: an empty queue.
        Queue() {
            // Implement the Constructor
            head = NULL;
            tail = NULL;
            size = 0;   // the member itself (no `int` in front this time)
        }

        /*----------------- Public Functions of Queue -----------------*/

        // True when the queue holds nothing.
        bool isEmpty() {
            // Implement the isEmpty() function
            return head == NULL;   // no nodes -> empty queue
        }

        // Add a value at the back of the queue in O(1).
        void enqueue(int data) {
            // Implement the enqueue() function
            Node* newNode = new Node(data);     // node on the heap

            if (isEmpty()) {
                // The only node is both the front and the back.
                head = newNode;
                tail = newNode;
            } else {
                // Link after the current last node; the new node is the new back.
                tail->next = newNode;   // '->' = member through a pointer
                tail = newNode;
            }
            size++;
        }

        // Remove the front value and return it; -1 when empty.
        int dequeue() {
            // Implement the dequeue() function
            if (isEmpty()) {

                return -1;
            }

            // Remember the front value and move head forward.
            int data = head->data;
            Node* tmp = head;       // the node to free
            head = head->next;

            // The queue just became empty: tail still points at the node we
            // are about to delete, so reset it too. Otherwise the next
            // enqueue would link through freed memory.
            if(head == NULL){
                tail = NULL;
            }

            delete tmp;             // free the old front node
            size--;
            return data;
            // Trace: 5 7 -> dequeue() gives 5, head moves to 7.
        }

        // Read the front value without removing it; -1 when empty.
        int front() {
            // Implement the front() function
            if (isEmpty()) {
                return -1;
            }
            return head->data;   // the front of the queue is the head node
        }
};