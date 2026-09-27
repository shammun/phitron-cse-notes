/*

Practice copy of the doubly linked list stack

Same class as stack_implementation_using_doubly_linked_list.cpp, typed out
again from memory -- that file carries the full explanation. The only visible
difference is that the object in `main` is called `st` instead of `s`.

It also carries the same compile error: `int size = 0;` and `int size()`
cannot both live in one class. Rename the counter to `sz` and it builds. So
the practice was useful twice over: once for the logic, once for spotting
that the mistake was copied along with it.

The shape to remember: tail = top, so push and pop work at the tail, and
`prev` is what makes pop O(1).

*/

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here (template leftover)
#include <algorithm>    // not used here (template leftover)
#include <string>       // not used here (template leftover)
#include <list>         // not used here (template leftover)

using namespace std;    // write cin/cout without std::

// One node: a value plus links up and down the pile.
class Node{
    public:
        int val;      // the value stored
        Node* next;   // towards the top
        Node* prev;   // towards the bottom

        // Constructor, runs on `new Node(val)`; `this->val` is the member,
        // plain `val` the parameter. A new node is linked to nothing (NULL).
        Node(int val){
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

// Stack on a doubly linked list: tail = top.
class myStack{
    public:
        Node* head = NULL;  // bottom of the pile
        Node* tail = NULL;  // top of the pile
        // This counter clashes with the size() method below; rename it sz.
        // BUG: same name for a data member and a member function -> compile error.
        int size = 0;

        // push: new node on top, O(1).
        void push(int val){
            size++;
            Node* newNode = new Node(val);  // node on the heap
            // The very first node is head and tail at the same time.
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            // Link after the old top and move the top up.
            tail->next = newNode;   // old top -> new
            newNode->prev = tail;   // old top <- new
            tail = newNode;         // new top
        }

        // pop: remove the top node, O(1). Call only when not empty.
        void pop(){
            size--;
            Node* deleteNode = tail; // remember the old top to free it
            tail = tail->prev;   // step down one node -- this is why prev exists
            delete deleteNode;   // free its memory
            if(tail == NULL){    // that was the last node
                head = NULL;
                return;
            }
            tail->next = NULL;   // the new top points at nothing above it
        }

        // top: read the newest value.
        int top(){
            return tail->val;    // newest value first (LIFO)
        }

        // size: count of values (the clashing name).
        int size(){
            return size;
        }

        // empty: true when the stack holds nothing.
        bool empty(){
            return size == 0;
        }
};

int main(){
    myStack st;         // empty stack

    int n;              // how many values
    cin >> n;           // cin >> skips whitespace and reads one number

    // Push n values: the last one typed sits on top.
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        st.push(x);
    }

    // Empty the stack to see it. `!st.empty()` guards top() and pop(), both
    // of which would follow a NULL tail if the stack were empty.
    // Input 3 / 7 8 9 would print 9, 8, 7.
    while(!st.empty()){
        cout << st.top() << endl;   // endl = newline + flush
        st.pop();
    }

    return 0;           // normal exit
}
