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
            int size;   // bug: a new local variable; the member `size` is not set to 0
        }

        /*----------------- Public Functions of Queue -----------------*/

        bool isEmpty() {
            // Implement the isEmpty() function
            return head == NULL;   // no nodes -> empty queue
        }

        // Add a value at the back of the queue.
        void enqueue(int data) {
            // Implement the enqueue() function
            Node* newNode = new Node(data);

            if (isEmpty()) {
                head = newNode;          // the first value is the front
            } else {
                // Walk to the last node and link the new one after it.
                // `tail` is never used, so this walk makes enqueue O(n).
                Node* tmp = head;
                while (tmp->next != NULL) {
                    tmp = tmp->next;
                }
                tmp->next = newNode;
            }
            size++;
        }

        int dequeue() {
            // Implement the dequeue() function
            if (isEmpty()) {
            
                return -1;
            }

            // Remember the front value, move head to the next node,
            // then free the old front node.
            int data = head->data;
            Node* tmp = head;
            head = head->next;
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