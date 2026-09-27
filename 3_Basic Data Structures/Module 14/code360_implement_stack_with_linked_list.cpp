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

class Stack
{
    //Write your code here
    Node* head;   // top of the stack
    int size;     // how many values are in the stack

    public:
        Stack()
        {
            //Write your code here
            head = NULL;
            size = 0;
        }

        int getSize()
        {
            //Write your code here
            return size;
        }

        bool isEmpty()
        {
            //Write your code here
            return head == NULL;
        }

        void push(int data)
        {
            //Write your code here
            // Insert at head: the new node points to the old top and
            // becomes the new top.
            Node* newNode = new Node(data);
            newNode->next =head;
            head = newNode;
            size++;
        }

        void pop()
        {
            //Write your code here
            if (isEmpty()) {
                return;   // nothing to remove
            }
            // Delete at head: move head down one node, free the old top.
            Node* tmp = head;
            head = head->next;
            delete tmp;
            size--;
        }

        int getTop()
        {
            //Write your code here
            if (isEmpty()) {
                return -1;
            }

            return head->data;   // the top value lives in the head node
        }
};