/*

Same or not 2

Problem Statement

There is a list of  values that were inserted into a stack and a list of  values that were inserted into a queue. You need to determine whether the stack and queue are the same or not based on the order in which the elements are removed.

Note: You cannot use any  here. You need to implement the stack and queue by yourself. You can use linked list or array as you want.

(The blanks above lost their symbols when copied: the stack gets N values,
the queue gets M values, and you cannot use any STL container.)

Input Format

First line will contain  and .
Second line will contain stack  with  values.
Third line will contain queue  with  values.
Constraints

Output Format

Output YES if they were same, otherwise NO.
Sample Input 0

5 5
10 20 30 40 50
50 40 30 20 10
Sample Output 0

YES
Sample Input 1

4 4
10 20 30 40
10 20 30 40
Sample Output 1

NO
Sample Input 2

5 4
1 2 3 4 5
5 4 3 2
Sample Output 2

NO

*/

/*
 * Idea
 *
 * Same question as problem 1, but without the STL: the stack and the queue
 * are built by hand on a linked list, the way Modules 13 and 14 built them.
 *
 *  - myStack: a doubly linked list; push and pop both work at the TAIL, so
 *    the tail is the top. `prev` lets pop step back in O(1).
 *  - myQueue: push at the tail (the back), pop at the head (the front).
 *
 * The counters are called size1 and size2 (not `size`) so they do not
 * clash with the size() methods. main() then compares them exactly like
 * problem 1.
 */


#include <iostream>     // cin and cout
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // not used here
using namespace std;    // write cout instead of std::cout

// One node of a doubly linked list: a value plus links to both neighbours.
class Node {
    public:              // members are usable from outside the class
        int val;         // the stored value
        Node* next;      // address of the node after this one (NULL = none)
        Node* prev;      // address of the node before this one (NULL = none)

    // Constructor: runs on `new Node(x)`. `this->val` is the member,
    // plain `val` is the parameter with the same name.
    Node(int val) {
        this->val = val;
        this->next = NULL;   // not linked to anything yet
        this->prev = NULL;
    }
};

// Stack on a doubly linked list. tail = top.
class myStack{
    public:
        Node* head = NULL;   // bottom
        Node* tail = NULL;   // top
        int size1 = 0;       // number of values in the stack

        // Put val on top.
        void push(int val){ // O(1)
            size1++;                          // one more value
            Node* newNode = new Node(val);    // `new` creates the node on the heap, returns its address
            if(head == NULL){       // first node is both bottom and top
                head = newNode;
                tail = newNode;
                return;
            }
            // Link the new node after the old top, both ways; it is the new top.
            tail->next = newNode;   // -> reaches a member through a pointer
            newNode->prev = tail;
            tail = newNode;
        }

        // Remove the top value. (Only called when the stack is not empty.)
        void pop(){ // O(1)
            size1--;
            // The node below the top becomes the new top.
            Node* deleteNode = tail;   // remember the old top so we can free it
            tail = tail->prev;         // step back one node
            delete deleteNode;         // `delete` frees the node's memory
            if(tail==NULL){         // that was the last node: stack is empty
                head=NULL;
                return;
            }
            tail->next = NULL;      // nothing above the new top
        }

        // Value on top (stack must not be empty).
        int top(){
            return tail->val; // O(1)
        }

        // Number of values, from the counter.
        int size(){
            return size1; // O(1)
        }

        // True when the stack holds nothing.
        bool empty(){
            return size1==0; // O(1)
            // return head==NULL; // O(1)   (another correct way; unreachable after the return above)
        }
};

// Queue on a linked list. head = front (leave here), tail = back (join here).
// It reuses Node but never sets prev (a queue only walks forward).
class myQueue{
    public:
        Node* head = NULL;   // front
        Node* tail = NULL;   // back
        int size2 = 0;       // number of values in the queue

        // Add val at the back.
        void push(int val){ // O(1)
            size2++;
            Node* newNode = new Node(val);
            if(head == NULL){                 // empty queue: new node is front and back
                head = newNode;
                tail = newNode;
                return;
            }
            // Join at the back.
            tail->next = newNode;
            tail = newNode;
        }

        // Remove the front value. (Only called when the queue is not empty.)
        void pop(){ // O(1)
            size2--;
            // Leave from the front: head moves to the next node.
            Node* deleteNode = head;
            head = head->next;
            delete deleteNode;
            if(head==NULL){         // queue is empty: tail must not point at freed memory
                tail = NULL;
            }
        }

        // Value at the front.
        int front(){ // O(1)
            return head->val;
        }

        // Value at the back.
        int back(){ // O(1)
            return tail->val;
        }

        // Number of values.
        int size(){ // O(1)
            return size2;
        }

        // True when the queue holds nothing.
        bool empty(){ // O(1)
            return head == NULL;
            // return size == 0;   (would not compile here: the counter is size2, and size is a function)
        }
};

int main(){
    int n, m;               // n values for the stack, m values for the queue
    cin >> n >> m;          // cin >> skips spaces/newlines between numbers

    myStack st;             // our hand-made stack, starts empty
    myQueue q;              // our hand-made queue, starts empty

    // The stack gets n values: the last one typed ends up on top.
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        st.push(val);
    }

    // The queue gets m values: the first one typed is at the front.
    for(int i=0; i<m; i++){
        int val;
        cin >> val;
        q.push(val);
    }

    // Different sizes can never give the same removal order. Checking this
    // first also means the loop below never touches an empty queue.
    if(n != m){
        cout << "NO" << endl;   // endl = newline + flush
        return 0;
    }

    // Remove from both side by side: the stack gives top(), the queue gives
    // front(). The first pair that differs settles it.
    // Sample 0: stack gives 50 40 30 20 10, queue gives 50 40 30 20 10 -> YES.
    while(!st.empty()){
        if(st.top() != q.front()){
            cout << "NO" << endl;
            return 0;
        }
        st.pop();
        q.pop();
    }

    // Every pair matched.
    cout << "YES" << endl;

    return 0;               // program finished normally
}
