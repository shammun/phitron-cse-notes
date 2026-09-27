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

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here (template leftover)
#include <algorithm>    // not used here (template leftover)
#include <string>       // not used here (template leftover)
#include <list>         // not used here (template leftover)
using namespace std;    // write cin/cout without std::

// One link of the chain: a value plus a pointer each way.
class Node {
    public:             // members usable from outside
        int val;        // the value stored
        Node* next;  // the node above this one (towards the top)
        Node* prev;  // the node below this one (towards the bottom)

    // Constructor, runs on `new Node(val)`. `this` points to the node being built;
    // this->val is the member, plain val is the parameter.
    Node(int val) {
        this->val = val;
        // A brand-new node is not linked to anything yet. Leaving these
        // uninitialised would give two garbage addresses that the first
        // pop or print would follow.
        this->next = NULL;
        this->prev = NULL;
    }
};

// Our own stack on a doubly linked list: the tail is the top.
class myStack{
    public:
        Node* head = NULL;  // the bottom of the pile (the oldest value)
        Node* tail = NULL;  // the TOP of the pile (the newest value)
        // This counter is the name clash with size() below -- see the top.
        // BUG: member `size` and function `size()` share a name, so the class does
        // not compile. Fix: `int sz = 0;` and use sz in push/pop/size/empty.
        int size = 0;

        // push: put val on top.
        void push(int val){ // O(1)
            size++;                         // one more value
            Node* newNode = new Node(val);  // `new` builds the node on the heap
            // First value: it is both the bottom and the top at once.
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            // Otherwise hook it on after the current top, link back with
            // prev, and move tail so it still means "the top".
            tail->next = newNode;       // old top -> new
            newNode->prev = tail;       // old top <- new
            tail = newNode;             // new is the top
        }

        // pop: remove the top. Only call when not empty.
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

        // top: read the newest value.
        int top(){
            return tail->val; // O(1) -- the newest value, LIFO
        }

        // size: how many values (the clashing name, see BUG above).
        int size(){
            return size; // O(1) -- a counter is kept so this is not a walk
        }

        // empty: true when nothing is inside.
        bool empty(){
            return size==0; // O(1)
            // return head==NULL; // O(1)
            // Both tests say the same thing; the commented one needs no
            // counter at all, which is why the later files prefer it.
        }
};


int main(){
    myStack s;          // an empty stack

    // get the input for stack
    int n;              // how many values
    cin >> n;           // cin >> skips whitespace and reads one number
    for(int i=0; i<n; i++){     // n passes, one value each
        int x;
        cin >> x;
        s.push(x);      // 10 20 30 40 -> 40 ends on top
    }

    // print the stack
    // empty() first, then top() and pop(): the same guard as the vector
    // version, and for the same reason -- popping an empty stack would step
    // through a NULL pointer.
    while(s.empty() == false){
        cout << s.top() << endl;    // newest first: 40, 30, 20, 10
        s.pop();
    }

    return 0;           // normal exit
}

