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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Node {
    public:
        int val;
        Node* next;  // towards the back of the line
        Node* prev;  // towards the front of the line

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myQueue{
    public:
        Node* head = NULL;  // front: pop() removes here
        Node* tail = NULL;  // back: push() adds here
        // The counter that clashes with the size() method below.
        int size = 0;

        void push(int val){
            size++;
            Node* newNode = new Node(val);
            if(head == NULL){          // first value: front and back at once
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;      // link forward
            newNode->prev = tail;      // and backward -- the only extra work
            tail = newNode;            // the new arrival is now the back
        }

        void pop(){
            size--;
            Node* deleteNode = head;   // the oldest value leaves first
            head = head->next;
            delete deleteNode;
            if(head==NULL){            // the line is now empty, so the back
                tail = NULL;           // pointer must not survive either
                return;
            }
            // Someone is still in the line: the new front has nobody in
            // front of it, and the node its prev used to name is gone.
            head->prev = NULL;
        }

        int front(){
            return head->val;
        }

        int back(){
            return tail->val;
        }

        int size(){
            return size;
        }

        // front(), back() and pop() all dereference head or tail, so this
        // check has to come first.
        bool empty(){
            return head == NULL;
            // return size == 0;
        }
};

int main(){
    myQueue q;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        q.push(val);
    }

    // With the rename applied, input 4 / 10 20 30 40 prints `10 40 4` here,
    cout << q.front() << " " << q.back() << " " << q.size() <<  endl;

    // and then 10 20 30 40, one per line -- arrival order, as a queue should.
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}
