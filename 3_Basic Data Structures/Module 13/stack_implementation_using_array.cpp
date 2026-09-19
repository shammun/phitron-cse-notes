/*

Stack, built the first way: on top of a vector

A stack is Last-In-First-Out (LIFO). Picture a pile of plates: a new plate
goes on the top of the pile, and the plate you take off is the top one again.
So the value that went in last is the first one to come back out.

A stack is not a new kind of memory. It is a rule about which end you are
allowed to touch. That is why the same five operations can sit on top of very
different storage: a vector here, a hand-made linked list later in this
module, and finally the ready-made `stack<int>` from the STL.

The five operations, and all of them cost O(1) on a vector:

    push(x)   put x on the top
    pop()     throw the top away (it returns nothing)
    top()     read the top without removing it
    size()    how many values are inside
    empty()   is there nothing left?

This first file writes the values straight into `main` so you can follow the
pile by eye. The next file reads them from input.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;


/* Our own stack. Inside it is just a vector; the whole class is about
   allowing nothing except the back of that vector to be touched.

   Why the back and not the front? `push_back` and `pop_back` only work on the
   last box, so they are O(1). Adding or removing at the front would shift
   every other element one place, which is O(n). The back is the top. */
class myStack{
    public:
        vector<int> v;

        // push: a new value joins at the back, which is the top of the pile.
        void push(int val){
            v.push_back(val);
        }

        // pop: remove the last box. That is the newest value -- LIFO.
        // Note it returns nothing; read the value with top() first if you
        // need it.
        void pop(){
            v.pop_back();
        }

        // top: look at the newest value without removing it. `v.back()` is
        // the same as `v[v.size()-1]`, just easier to read.
        int top(){
            return v.back();
        }

        int size(){
            return v.size();
        }

        // empty: the guard for the two dangerous operations. `top()` on an
        // empty vector reads a box that does not exist and `pop()` removes
        // one that is not there -- undefined behaviour, usually a crash or a
        // junk number. So always ask this first.
        bool empty(){
            return v.empty();
        }
};

int main(){
    myStack s;

    // The pile grows upward: 10 at the bottom, 60 on the top.
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;   // 60 -- the last one pushed
    s.pop();                   // 60 is gone; 50 is now the top
    cout << s.top() << endl;   // 50

    // Reading the top does not remove it, so this prints 50 again.
    if(s.empty() == false){
        cout << s.top() << endl;
    }

    // Before doing top and pop, first check
    // whether the stack is empty or not
    // (`!s.empty()` is the shorter way of writing `s.empty() == false`.)
    if(!s.empty()){
        cout << s.top() << endl;   // 50 once more
        s.pop();                   // and now 50 really is gone
    }

    // print the stack
    // The only way to see everything in a stack is to empty it: print the
    // top, pop it, repeat while something is left. The values come out
    // newest first, so this prints 40 30 20 10 -- the reverse of the order
    // they were pushed in.
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
