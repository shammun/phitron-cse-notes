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
 * is O(1).
 */

#include <bits/stdc++.h>

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            next = NULL;
        }
};

class Queue {
    Node *head;
    Node *tail;
    int size;
    public:
        Queue() {
            // Implement the Constructor
            head = NULL;
            tail = NULL;
            size = 0;   // the member itself (no `int` in front this time)
        }

        /*----------------- Public Functions of Queue -----------------*/

        bool isEmpty() {
            // Implement the isEmpty() function
            return head == NULL;   // no nodes -> empty queue
        }

        // Add a value at the back of the queue in O(1).
        void enqueue(int data) {
            // Implement the enqueue() function
            Node* newNode = new Node(data);

            if (isEmpty()) {
                // The only node is both the front and the back.
                head = newNode;
                tail = newNode;
            } else {
                // Link after the current last node; the new node is the new back.
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }

        int dequeue() {
            // Implement the dequeue() function
            if (isEmpty()) {
            
                return -1;
            }

            // Remember the front value and move head forward.
            int data = head->data;
            Node* tmp = head;
            head = head->next;

            // The queue just became empty: tail still points at the node we
            // are about to delete, so reset it too. Otherwise the next
            // enqueue would link through freed memory.
            if(head == NULL){
                tail = NULL;
            }

            delete tmp;
            size--;
            return data;
        }

        int front() {
            // Implement the front() function
            if (isEmpty()) {
                return -1;
            }
            return head->data;   // the front of the queue is the head node
        }
};