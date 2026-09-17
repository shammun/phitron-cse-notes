/*

https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTabValue=PROBLEM

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
            int size;
        }

        /*----------------- Public Functions of Queue -----------------*/

        bool isEmpty() {
            // Implement the isEmpty() function
            return head == NULL;
        }

        void enqueue(int data) {
            // Implement the enqueue() function
            Node* newNode = new Node(data);

            if (isEmpty()) {
                head = newNode;
            } else {
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
            return head->data;
        }
};