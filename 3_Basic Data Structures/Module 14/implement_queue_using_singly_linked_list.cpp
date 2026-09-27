/*

The hand-made queue, finished: singly linked list, push at tail, pop at head

Module 13 started this class; here it has a `main` that actually prints. The
rule to keep in mind is which end does what, and why:

    head = the front. pop() deletes the head, and `head->next` is instantly
           the new front, so removing is O(1).
    tail = the back.  push() links a node after the tail. Keeping a `tail`
           pointer is what makes adding O(1) instead of a walk.

It has to be this way round for a *singly* linked list. Deleting the tail
would need the node before it, and the only way to find that is to walk from
the head -- O(n). Removing at the head costs nothing, so the head is the front
and First-In-First-Out falls out naturally.

WARNING: this file does not compile. `int size = 0;` and `int size()` are the
same name inside one class. `queue_input_output_singly_list.cpp` is this exact
program with the counter renamed to `sz`, so look there to see it run.

*/

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here (template leftover)
#include <algorithm>    // not used here (template leftover)
#include <string>       // not used here (template leftover)
using namespace std;    // write cin/cout without std::

// One person in the line: a value and the address of the one behind.
class Node {
    public:
        int val;     // the stored value
        Node* next;  // the next value in the line, behind this one

    // Constructor, runs on `new Node(val)`; this->val = member, val = parameter.
    Node(int val) {
        this->val = val;
        this->next = NULL;  // a fresh node ends the chain until it is linked
    }
};

// Queue on a singly linked list.
class myQueue{
    public:
        Node* head = NULL;  // front: the oldest value, the next to leave
        Node* tail = NULL;  // back: the newest value
        // The counter that clashes with the size() method below.
        // BUG: same name for a data member and a function -> compile error.
        // Fix: `int sz = 0;` and use sz (see queue_input_output_singly_list.cpp).
        int size = 0;

        // push: join the back.
        void push(int val){ // O(1)
            size++;
            Node* newNode = new Node(val);  // node on the heap
            // An empty queue: the first value is both front and back.
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            // Otherwise join the back of the line and become the new back.
            tail->next = newNode;   // '->' = member through a pointer
            tail = newNode;
        }

        // pop: the front leaves. Only call when not empty.
        void pop(){ // O(1)
            size--;
            Node* deleteNode = head;   // the front leaves first -- FIFO
            head = head->next;         // the one behind becomes the front
            delete deleteNode;         // free the memory
            // The queue just became empty, so tail points at freed memory.
            // Clear it, or the next push() would write through it.
            if(head==NULL){
                tail = NULL;
            }
        }

        // front: oldest value.
        int front(){ // O(1)
            return head->val;
        }

        // back: newest value.
        int back(){ // O(1)
            return tail->val;
        }

        // size: count of values (the clashing name).
        int size(){ // O(1)
            return size;
        }

        // The guard for front(), back() and pop(): all three follow head or
        // tail, so they must not be called when there is nothing there.
        bool empty(){ // O(1)
            return head == NULL;
            // return size == 0;
            // Both tests agree; this one needs no counter at all.
        }
};

int main(){
    myQueue q;          // an empty queue
    int n;
    cin >> n;           // how many values follow
    for(int i=0; i<n; i++){     // n passes
        int val;
        cin >> val;
        q.push(val);
    }

    // front, back and size on one line. For 4 / 10 20 30 40 that is
    // `10 40 4`: the oldest value, the newest value, and the count.
    cout << q.front() << " " << q.back() << " " << q.size() <<  endl;

    // Drain the queue. Removal happens at the front, so the values come out
    // in the order they arrived: 10 20 30 40.
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    // (Reaching the end of main without `return 0;` returns 0 automatically.)
}
