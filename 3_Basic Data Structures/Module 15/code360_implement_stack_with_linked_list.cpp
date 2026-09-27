/*

Implement Stack With Linked List (Code360)
https://www.naukri.com/code360/problems/implement-stack-with-linked-list_630475

The problem, in my own words
  Build a stack by hand on top of a singly linked list (no STL stack).
  The judge gives you the `Node` class (int data, Node* next, and
  constructors) and asks you to fill in a `Stack` class with:
    getSize()   number of values in the stack
    isEmpty()   true if there are none
    push(data)  put data on top
    pop()       remove the top; do nothing if the stack is empty
    getTop()    the top value, or -1 if the stack is empty

Input used by the test driver
  q, then q commands: "push x", "pop", "top", "size" or "isEmpty".

Sample
  push 4, push 8, top -> 8, size -> 2, pop, top -> 4, pop,
  isEmpty -> true, top -> -1

*/

/*
 * The idea: in a singly linked list the only place where adding AND removing
 * are both O(1) is the head. So the head of the list is the top of the stack.
 *
 *   push 4, push 8:   head -> [8] -> [4] -> NULL
 *                              ^ top
 *
 *   push: make a new node, point it at the old head, make it the new head.
 *   pop:  move head one step forward and delete the old head node.
 *
 * Counting the nodes every time getSize() is called would be O(n), so a
 * `size` counter is updated on every push and pop instead.
 */

class Stack
{
    Node* head;   // top of the stack; NULL when the stack is empty
    int size;     // how many nodes are in the list

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(int data)
    {
        // The new node points at the current top and then becomes the top.
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void pop()
    {
        // Popping an empty stack is allowed and simply does nothing.
        if(head == NULL){
            return;
        }
        Node* deleteNode = head;
        head = head->next;     // the node below becomes the top
        delete deleteNode;     // free the removed node's memory
        size--;
    }

    int getTop()
    {
        if(head == NULL){
            return -1;         // the judge's "no top" answer
        }
        return head->data;
    }
};
