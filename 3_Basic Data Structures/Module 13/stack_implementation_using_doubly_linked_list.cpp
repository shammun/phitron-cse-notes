/*

Stack, built the second way: on a hand-made doubly linked list

The five operations do not care what the storage is, only that one end is
cheap to reach. Here the storage is a chain of nodes (Module 6 onwards), and
the tail is the top of the stack: push adds a node after the tail, pop removes
the tail. Both are O(1), the same as the vector version.

Why a *doubly* linked list? Because of pop. After deleting the tail, the stack
needs to know the node before it, and `tail->prev` gives that away for free.
In a singly linked list you would have to walk from the head every time --
O(n) per pop.

WARNING: this file does not compile. The class has a data member `int size`
and a member function `int size()`, and a class may not use one name for both.
The fix is to rename the counter, for example to `sz` -- which is exactly what
Module 14's practice_problem_1_same_stacks.cpp does. The logic below is
correct; only the name is wrong. With the fix, the input 4 / 10 20 30 40
prints 40 30 20 10, one per line.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

// One link of the chain: a value plus a pointer each way.
class Node {
    public:
        int val;
        Node* next;  // the node above this one (towards the top)
        Node* prev;  // the node below this one (towards the bottom)

    Node(int val) {
        this->val = val;
        // A brand-new node is not linked to anything yet. Leaving these
        // uninitialised would give two garbage addresses that the first
        // pop or print would follow.
        this->next = NULL;
        this->prev = NULL;
    }
};

class myStack{
    public:
        Node* head = NULL;  // the bottom of the pile (the oldest value)
        Node* tail = NULL;  // the TOP of the pile (the newest value)
        // This counter is the name clash with size() below -- see the top.
        int size = 0;

        void push(int val){ // O(1)
            size++;
            Node* newNode = new Node(val);
            // First value: it is both the bottom and the top at once.
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            // Otherwise hook it on after the current top, link back with
            // prev, and move tail so it still means "the top".
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        void pop(){ // O(1)
            size--;
            Node* deleteNode = tail;   // hold the old top so it can be freed
            tail = tail->prev;         // the node below becomes the new top
            delete deleteNode;         // give the memory back
            // If there was nothing below, the stack is now empty, so head
            // must be cleared too -- otherwise it would point at freed
            // memory and empty() would disagree with reality.
            if(tail==NULL){
                head=NULL;
                return;
            }
            // The new top must not point up at a node that no longer exists.
            tail->next = NULL;
        }

        int top(){
            return tail->val; // O(1) -- the newest value, LIFO
        }

        int size(){
            return size; // O(1) -- a counter is kept so this is not a walk
        }

        bool empty(){
            return size==0; // O(1)
            // return head==NULL; // O(1)
            // Both tests say the same thing; the commented one needs no
            // counter at all, which is why the later files prefer it.
        }
};


int main(){
    myStack s;

    // get the input for stack
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s.push(x);
    }

    // print the stack
    // empty() first, then top() and pop(): the same guard as the vector
    // version, and for the same reason -- popping an empty stack would step
    // through a NULL pointer.
    while(s.empty() == false){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}

