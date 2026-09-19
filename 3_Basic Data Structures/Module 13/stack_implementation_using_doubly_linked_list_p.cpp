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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

class Node{
    public:
        int val;
        Node* next;   // towards the top
        Node* prev;   // towards the bottom

        Node(int val){
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

class myStack{
    public:
        Node* head = NULL;  // bottom of the pile
        Node* tail = NULL;  // top of the pile
        // This counter clashes with the size() method below; rename it sz.
        int size = 0;

        void push(int val){
            size++;
            Node* newNode = new Node(val);
            // The very first node is head and tail at the same time.
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            // Link after the old top and move the top up.
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        void pop(){
            size--;
            Node* deleteNode = tail;
            tail = tail->prev;   // step down one node -- this is why prev exists
            delete deleteNode;
            if(tail == NULL){    // that was the last node
                head = NULL;
                return;
            }
            tail->next = NULL;   // the new top points at nothing above it
        }

        int top(){
            return tail->val;    // newest value first (LIFO)
        }

        int size(){
            return size;
        }

        bool empty(){
            return size == 0;
        }
};

int main(){
    myStack st;

    int n;
    cin >> n;

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
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
