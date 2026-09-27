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
 * The idea: a stack is LIFO (last in, first out, like a pile of plates).
 * In a singly linked list the only place where adding AND removing
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
 *
 * Note: no #include, no main() and no Node class here - the judge's hidden
 * code supplies them. Node has `int data`, `Node* next` and a constructor
 * Node(int data) that sets next to NULL.
 */

class Stack
{
    // Private members (the default inside a class): only Stack's functions use them.
    Node* head;   // top of the stack; NULL when the stack is empty
    int size;     // how many nodes are in the list

public:           // everything below can be called by the judge
    // Constructor: runs when a Stack is created; a new stack is empty.
    Stack()
    {
        head = NULL;   // no top node yet
        size = 0;      // nothing counted yet
    }

    // Number of values in the stack, read straight from the counter: O(1).
    int getSize()
    {
        return size;
    }

    // True when the stack holds no values.
    bool isEmpty()
    {
        return size == 0;   // the comparison is already true/false
    }

    // Put `data` on top of the stack.
    void push(int data)
    {
        // The new node points at the current top and then becomes the top.
        Node* newNode = new Node(data);   // `new` creates the node on the heap and returns its address
        newNode->next = head;             // -> reaches a member through a pointer; the old top sits below it
        head = newNode;                   // the new node is now the top
        size++;                           // one more value in the stack
    }

    // Remove the top value (nothing is returned).
    void pop()
    {
        // Popping an empty stack is allowed and simply does nothing.
        if(head == NULL){
            return;
        }
        Node* deleteNode = head;   // remember the old top so it can be freed
        head = head->next;     // the node below becomes the top
        delete deleteNode;     // free the removed node's memory
        size--;                // one value fewer
    }

    // The value on top, or -1 if the stack is empty.
    int getTop()
    {
        if(head == NULL){
            return -1;         // the judge's "no top" answer
        }
        return head->data;     // value in the top node, e.g. 8 after push 4, push 8
    }
};
