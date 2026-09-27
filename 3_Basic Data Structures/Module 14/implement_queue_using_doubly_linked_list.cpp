/*

The same queue on a doubly linked list

Every node now also keeps a `prev` pointer. For a queue that is extra memory
and nothing else: pushing at the tail and popping at the head are already O(1)
with a singly linked list, so `prev` buys no speed here. (It was worth it for
the *stack* in Module 13, where pop removes the tail and needs the node before
it.) What `prev` does add is tidiness -- when the head leaves, the new head's
`prev` must be cleared so no pointer refers to the node that was deleted.

The ends still mean the same thing: head is the front, values leave there;
tail is the back, values join there. First in, first out.

WARNING: same compile error as the singly linked version -- `int size = 0;`
and `int size()` cannot share a name. Rename the counter to `sz`, as
`queue_input_output_singly_list.cpp` does, and it runs.

*/

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here (template leftover)
#include <algorithm>    // not used here (template leftover)
#include <string>       // not used here (template leftover)
using namespace std;    // write cin/cout without std::

// One person in the line, linked both ways.
class Node {
    public:
        int val;     // the stored value
        Node* next;  // towards the back of the line
        Node* prev;  // towards the front of the line

    // Constructor, runs on `new Node(val)`. `this` points to the node being built;
    // this->val is the member, plain val is the parameter.
    Node(int val) {
        this->val = val;
        this->next = NULL;  // not linked to anything yet
        this->prev = NULL;
    }
};

// Queue on a doubly linked list: push at the tail, pop at the head.
class myQueue{
    public:
        Node* head = NULL;  // front: pop() removes here
        Node* tail = NULL;  // back: push() adds here
        // The counter that clashes with the size() method below.
        // BUG: data member and member function both named `size` -> compile error.
        // Fix: `int sz = 0;` and use sz in push/pop/size.
        int size = 0;

        // push: join the back of the line, O(1).
        void push(int val){
            size++;
            Node* newNode = new Node(val);  // `new` builds the node on the heap
            if(head == NULL){          // first value: front and back at once
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;      // link forward
            newNode->prev = tail;      // and backward -- the only extra work
            tail = newNode;            // the new arrival is now the back
        }

        // pop: the front leaves, O(1). Only call when not empty.
        void pop(){
            size--;
            Node* deleteNode = head;   // the oldest value leaves first
            head = head->next;         // the one behind becomes the front
            delete deleteNode;         // free the old front's memory
            if(head==NULL){            // the line is now empty, so the back
                tail = NULL;           // pointer must not survive either
                return;
            }
            // Someone is still in the line: the new front has nobody in
            // front of it, and the node its prev used to name is gone.
            head->prev = NULL;
        }

        // front: the oldest value (next to leave).
        int front(){
            return head->val;
        }

        // back: the newest value.
        int back(){
            return tail->val;
        }

        // size: count of values (the clashing name, see BUG above).
        int size(){
            return size;
        }

        // front(), back() and pop() all dereference head or tail, so this
        // check has to come first.
        bool empty(){
            return head == NULL;
            // return size == 0;    // equivalent test using the counter
        }
};

int main(){
    myQueue q;          // an empty queue
    int n;              // how many values
    cin >> n;           // cin >> skips whitespace and reads one number
    for(int i=0; i<n; i++){     // n passes, one value each
        int val;
        cin >> val;
        q.push(val);
    }

    // With the rename applied, input 4 / 10 20 30 40 prints `10 40 4` here,
    cout << q.front() << " " << q.back() << " " << q.size() <<  endl;

    // and then 10 20 30 40, one per line -- arrival order, as a queue should.
    while(!q.empty()){
        cout << q.front() << endl;  // endl = newline + flush
        q.pop();
    }
    // (main without `return 0;` still returns 0 automatically in C++.)
}
