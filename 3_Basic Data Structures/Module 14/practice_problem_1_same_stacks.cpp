/*
Take two stacks of size N and M as input and check if both of them are the same or not.
Don’t use STL stack to solve this problem.
*/

/*

Idea

"Don't use STL stack" means the `myStack` class from Module 13 has to come
along -- the doubly linked list version, with the counter renamed to `sz` so
it compiles.

Two stacks are the same when they hold the same values in the same order. A
stack only lets you see the top, so the comparison has to happen from the top
downwards: compare the two tops, pop both, compare the new tops, and so on.
If the sizes differ there is nothing to compare, so that case is answered
straight away.

Both stacks are destroyed by the comparison. That is fine here, since nothing
uses them afterwards; a function that must keep them would take copies.

*/

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here (template leftover)
#include <algorithm>    // not used here (template leftover)
#include <string>       // not used here (template leftover)
#include <list>         // not used here (template leftover)
using namespace std;    // write cin/cout without std::

// One node of a doubly linked list: a value plus links both ways.
class Node {
    public:
        int val;        // the stored value
        Node* next;     // node above (towards the top)
        Node* prev;     // node below (towards the bottom)

    // Constructor, runs on `new Node(val)`; this->val = member, val = parameter.
    Node(int val) {
        this->val = val;
        this->next = NULL;  // not linked yet
        this->prev = NULL;
    }
};

// The Module 13 stack, with `sz` instead of `size` so the counter and the
// size() method no longer share a name. tail = top of the pile.
class myStack{
    public:
        Node* head = NULL;  // bottom
        Node* tail = NULL;  // top -- push and pop both work here
        int sz = 0;         // number of values

        // push: new value on top.
        void push(int val){ // O(1)
            sz++;
            Node* newNode = new Node(val);  // `new` builds the node on the heap
            if(head == NULL){       // first node is both ends at once
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;   // old top -> new
            newNode->prev = tail;   // old top <- new
            tail = newNode;         // the newest value is the new top
        }

        // pop: remove the top. Only call when not empty.
        void pop(){ // O(1)
            sz--;
            Node* deleteNode = tail;    // remember the old top
            tail = tail->prev;      // prev is why this is O(1) and not a walk
            delete deleteNode;      // free its memory
            if(tail==NULL){         // the stack is empty now
                head=NULL;
                return;
            }
            tail->next = NULL;      // nothing above the new top
        }

        // top: read the newest value.
        int top(){
            return tail->val; // O(1) -- the last value pushed (LIFO)
        }

        // size: how many values.
        int size(){
            return sz; // O(1)
        }

        // empty: true when nothing is inside.
        bool empty(){
            return sz==0; // O(1)
            // return head==NULL; // O(1)   (equivalent test without the counter)
        }
};


int main(){
    myStack s1;         // the first stack

    // get the input for stack
    // n values into the first stack; the last one typed ends up on top.
    int n;
    cin >> n;           // cin >> skips whitespace and reads one number
    for(int i=0; i<n; i++){     // n passes
        int x;
        cin >> x;
        s1.push(x);
    }

    // The second stack, read the same way (m values).
    myStack s2;
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        s2.push(x);
    }

    // Different heights can never be the same pile, and checking it first
    // also makes the loop below safe: from here on the two stacks empty out
    // together, so s2 is never popped while it is already empty.
    if(s1.size() != s2.size()){
        cout << "NO" << endl;
        return 0;       // answer known, end the program
    }

    // Compare top against top, then pop both. `flag` remembers the verdict;
    // `break` leaves as soon as one pair disagrees, since no later pair can
    // rescue it.
    // Trace s1 = 1 2 3, s2 = 1 2 3: tops 3/3, 2/2, 1/1 all equal -> YES.
    bool flag = true;
    while(!s1.empty()){
        if(s1.top() != s2.top()){
            flag = false;
            break;
        }
        s1.pop();
        s2.pop();
    }

    // if/else written on one line each (no braces needed for a single statement).
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;           // normal exit
}
