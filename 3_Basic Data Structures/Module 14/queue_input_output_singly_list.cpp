/*

The same singly linked queue, but this one compiles

Everything here is explained in `implement_queue_using_singly_linked_list.cpp`.
The one change is the counter: it is called `sz` instead of `size`, so it no
longer collides with the `size()` method. That single rename is the whole
difference between a file that fails to build and one that runs.

The shape is unchanged: head is the front (pop deletes here), tail is the back
(push adds here), both O(1), so values leave in the order they arrived.

*/

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here (template leftover)
#include <algorithm>    // not used here (template leftover)
#include <string>       // not used here (template leftover)
using namespace std;    // write cin/cout without std::

// One person in the line: a value plus the address of the one behind.
class Node {
    public:
        int val;        // the stored value
        Node* next;     // the node behind this one (NULL for the last)

    // Constructor, runs on `new Node(val)`; this->val = member, val = parameter.
    Node(int val) {
        this->val = val;
        this->next = NULL;  // not linked to anything yet
    }
};

// Queue on a singly linked list: push at the tail, pop at the head.
class myQueue{
    public:
        Node* head = NULL;  // front -- the next value to leave
        Node* tail = NULL;  // back  -- where new values join
        int sz = 0;         // renamed from `size`, so size() below is legal

        // push: join the back, O(1).
        void push(int val){
            sz++;
            Node* newNode = new Node(val);  // `new` builds the node on the heap
            if(head == NULL){       // empty queue: first value is both ends
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;   // link it behind the current back
            tail = newNode;         // and it becomes the new back
        }

        // pop: the front leaves, O(1). Only call when not empty.
        void pop(){
            sz--;
            Node* deleteNode = head;  // the front is the oldest value (FIFO)
            head = head->next;        // the next in line takes its place
            delete deleteNode;        // free the old front's memory
            if(head==NULL){           // queue emptied: don't leave tail
                tail = NULL;          // pointing at deleted memory
            }
        }

        // front: the oldest value.
        int front(){
            return head->val;
        }

        // back: the newest value.
        int back(){
            return tail->val;
        }

        // O(1) because pushes and pops keep the counter up to date; counting
        // the nodes by walking the list would be O(n).
        int size(){
            return sz;
        }

        // Check this before front(), back() or pop() -- they all step through
        // a pointer that would be NULL on an empty queue.
        bool empty(){
            return head == NULL;
            // return size == 0;    // old idea; it would need `sz == 0` now (size is the function)
        }
};

int main(){
    myQueue q;          // an empty queue
    int n;
    cin >> n;           // how many values (cin >> skips whitespace)
    for(int i=0; i<n; i++){     // n passes, one value each
        int val;
        cin >> val;
        q.push(val);
    }

    // For input 3 / 5 6 7 this prints `5 7 3`: front, back, size.
    cout << q.front() << " " << q.back() << " " << q.size() <<  endl;

    // Then the queue is emptied from the front, so the output is 5 6 7 --
    // the same order as the input. (A stack would print 7 6 5.)
    while(!q.empty()){
        cout << q.front() << endl;  // endl = newline + flush
        q.pop();
    }
    // (main returns 0 automatically when it reaches its end.)
}
