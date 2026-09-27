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
 * The idea: a queue adds at one end and removes at the other. In a singly
 * linked list:
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
 */

// A node of the singly linked list: one value and the node behind it.
class Node {
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Queue {
    Node* head;   // front of the queue (removed first)
    Node* tail;   // back of the queue (newest value)

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if(head == NULL){
            // Empty queue: the new node is both the front and the back.
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;   // hook it behind the current back
        tail = newNode;         // it is the new back
    }

    int dequeue() {
        if(head == NULL){
            return -1;          // nothing to remove
        }
        int val = head->data;   // save the value before the node is freed
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        if(head == NULL){
            tail = NULL;        // the queue became empty: reset the back too
        }
        return val;
    }

    int front() {
        if(head == NULL){
            return -1;
        }
        return head->data;
    }
};
