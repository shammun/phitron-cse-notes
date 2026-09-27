/*

https://www.naukri.com/code360/problems/implement-stack-with-linked-list_630475?leftPanelTabValue=PROBLEM

Implement Stack With Linked List (Code360)

Write a stack class on a singly linked list with getSize(), isEmpty(),
push(x), pop() and getTop(). getTop() returns -1 on an empty stack, and
pop() on an empty stack does nothing.

Example: push 4, push 9, getTop() -> 9, pop(), getTop() -> 4, getSize() -> 1.

*/

/*
 * Idea
 *
 * The top of the stack is the HEAD of the list. Adding and removing at the
 * head needs no walk at all, so push and pop are O(1) with a singly linked
 * list and no tail pointer. `size` is kept as a counter so getSize() is O(1).
 * A stack is Last-In-First-Out: the value pushed last is the first one out.
 *
 * Note: this file has no #include and no main - Code360 pastes it into its own
 * program, which already defines the Node class shown below.
 */

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

// The stack class. Members before `public:` are private (only the class uses them).
class Stack
{
    //Write your code here
    Node* head;   // top of the stack
    int size;     // how many values are in the stack

    public:
        // Constructor: runs when a Stack is created; starts empty.
        Stack()
        {
            //Write your code here
            head = NULL;
            size = 0;
        }

        // Number of values in the stack, O(1) thanks to the counter.
        int getSize()
        {
            //Write your code here
            return size;
        }

        // True when the stack holds nothing.
        bool isEmpty()
        {
            //Write your code here
            return head == NULL;
        }

        // Put data on top.
        void push(int data)
        {
            //Write your code here
            // Insert at head: the new node points to the old top and
            // becomes the new top.
            Node* newNode = new Node(data);     // `new` builds the node on the heap
            newNode->next =head;                // new -> old top ('->' = member through pointer)
            head = newNode;                     // new node is the top
            size++;
            // Trace: push 4, push 9 -> list 9 -> 4, head on 9.
        }

        // Remove the top value (does nothing on an empty stack).
        void pop()
        {
            //Write your code here
            if (isEmpty()) {
                return;   // nothing to remove
            }
            // Delete at head: move head down one node, free the old top.
            Node* tmp = head;
            head = head->next;
            delete tmp;         // give the old top's memory back
            size--;
        }

        // Read the top value; -1 when the stack is empty.
        int getTop()
        {
            //Write your code here
            if (isEmpty()) {
                return -1;
            }

            return head->data;   // the top value lives in the head node
        }
};