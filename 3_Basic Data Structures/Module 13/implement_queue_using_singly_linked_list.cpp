/*

First look at a queue: push at the tail, pop at the head

A queue is the opposite rule to a stack. A stack is Last-In-First-Out; a queue
is First-In-First-Out (FIFO). Think of a line at a counter: a new person joins
at the back, and the person served is the one at the front. Nobody overtakes,
so values leave in exactly the order they arrived.

That means a queue touches *both* ends, one for adding and one for removing.
A singly linked list is enough for this:

    head  = the front  -> pop() deletes here. Deleting the head is O(1),
                          because `head->next` is the new head.
    tail  = the back   -> push() adds here. With a `tail` pointer this is
                          O(1) too; without one you would walk the list.

Note which end does what, and why it is that way round. Removing at the *tail*
of a singly linked list would be O(n), since you would have to walk from the
head to find the node before the tail. So: add at the tail, remove at the head.

WARNING: this file does not compile yet, and even when fixed it prints
nothing, because `main` only pushes. It is the first attempt; the finished
version is in Module 14. Two mistakes to notice:

  1. `int size = 0;` and `int size()` -- one name for a member and a method.
     Rename the counter to `sz`.
  2. In the Node constructor, `this->next = next;` copies the member onto
     itself. `next` on the right is the uninitialised member, not a
     parameter, so the new node keeps a garbage pointer. It should be
     `this->next = NULL;`.

*/

#include <iostream>     // cin, cout
#include <vector>       // not used here (template leftover)
#include <algorithm>    // not used here (template leftover)
#include <string>       // not used here (template leftover)
#include <stack>        // STL stack - not used here (we build our own queue)


using namespace std;    // write cin/cout without std::


// One person in the line: a value plus the address of the person behind.
class Node{
    public:             // members usable from outside the class
        int val;        // the value this node holds
        Node* next;   // the person behind this one in the line

        // Constructor, runs on `new Node(val)`. `this` points to the node being built;
        // this->val is the member, plain `val` is the parameter.
        Node(int val){
            this->val = val;
            this->next = next;  // BUG: assigns the garbage member to itself.
                                // Should be `this->next = NULL;` so a fresh
                                // node ends the chain.
        }
};

// Our own queue on a singly linked list: push at the tail, pop at the head.
class myQueue{
    public:
        Node* head = NULL;  // the front -- the oldest value, next to leave
        Node* tail = NULL;  // the back  -- the newest value
        // This counter clashes with the size() method below (mistake 1).
        // BUG: a class cannot have a data member and a function both called size;
        // the compiler rejects the class. Fix: rename this to `int sz = 0;` and use sz.
        int size = 0;

    // push: add val at the back of the line. O(1).
    void push(int val){
        size++;                         // one more value inside
        Node* newNode = new Node(val);  // `new` builds the node on the heap and returns its address
        // First value in an empty queue: it is the front and the back at once.
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        // Otherwise join the back of the line and become the new back.
        tail->next = newNode;           // old back -> new node ('->' = member through a pointer)
        tail = newNode;                 // new node is the back now
    }

    // pop: remove the front value. O(1). Only safe when the queue is not empty.
    void pop(){
        size--;                    // one value fewer
        Node* deleteNode = head;   // the front leaves first (FIFO)
        head = head->next;         // the next in line becomes the front
        delete deleteNode;         // `delete` frees the memory `new` gave us
        // If the line is now empty, tail still points at the node we just
        // deleted. Clearing it matters: the next push() would otherwise
        // write through that dangling pointer.
        if(head == NULL){
            tail = NULL;
        }
    }

    // front: read the oldest value without removing it.
    int front(){
        return head->val;   // the value that will leave next
    }

    // back: read the newest value.
    int back(){
        return tail->val;   // the value that arrived last
    }

    // size: how many values are inside (this is the name that clashes, see BUG above).
    int size(){
        return size;
    }

    // The guard. front(), back() and pop() all step through head or tail, so
    // they are only safe while this is false.
    bool empty(){
        return head == NULL;    // true when there is no front node
    }
};

int main(){
    myQueue q;          // an empty queue object
    int n;              // how many values to read
    cin >> n;           // cin >> skips spaces/newlines and reads one number
    // Read n values and let each one join the back of the line.
    for(int i=0; i<n; i++){     // i counts 0 .. n-1, one value per pass
        int x;
        cin >> x;
        q.push(x);
    }
    // Example input 3 / 10 20 30 -> front 10, back 30.

    // Nothing is printed yet -- the draining loop (print front(), pop(),
    // repeat while !empty()) arrives in Module 14.

    return 0;           // normal exit
}
