// Stack, built the third way: on top of the STL `list<int>`.
// A stack is Last-In-First-Out (LIFO): the value pushed last comes out first.
// std::list is a ready-made doubly linked list, so its back end is cheap to reach:
// push_back / pop_back / back are all O(1). The back of the list is the top.

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here (template leftover)
#include <algorithm>    // not used here (template leftover)
#include <string>       // not used here (template leftover)
#include <list>         // std::list, the storage for our stack
using namespace std;    // write list/cin/cout without std::

// Our own stack class. It only lets you touch the back of the list.
class myStack{
    public:             // callable from main
        list<int> l; // list uses doubly linked list internally

        // push: put val on top (append at the back).
        void push(int val){
            l.push_back(val); // O(1)
        }

        // pop: throw the top away. Returns nothing. Only call when not empty.
        void pop(){
            l.pop_back(); // O(1)
        }

        // top: read the newest value without removing it.
        int top(){
            return l.back(); // O(1)
        }

        // size: how many values are inside.
        int size(){
            return l.size(); // O(1)
        }

        // empty: true when nothing is inside. Check this before top() or pop().
        bool empty(){
            return l.empty(); // O(1)
        }
};


int main(){
    myStack s;          // an empty stack

    // get the input for stack
    int n;              // how many values
    cin >> n;           // cin >> skips whitespace and reads one number
    for(int i=0; i<n; i++){     // n passes, one value per pass
        int x;
        cin >> x;
        s.push(x);      // the last number typed ends up on top
    }

    // print the stack
    // Print the top, remove it, repeat while something is left. The values come
    // out newest first: input 3 / 5 6 7 prints 7, 6, 5 (the input reversed).
    while(s.empty() == false){
        cout << s.top() << endl;    // endl = newline + flush
        s.pop();
    }

    return 0;           // normal exit
}