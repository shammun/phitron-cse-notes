/*

The same vector stack, but the values come from input

`stack_implementation_using_array.cpp` explains the class itself. The only new
thing here is `main`: read n values, push them one by one, then empty the
stack and print what comes out.

Because a stack is Last-In-First-Out, the printing loop gives you the input
back in reverse order. Reversing a sequence is the simplest job a stack does,
and many later problems are built on exactly this.

*/

#include <iostream>     // cin, cout, endl
#include <vector>       // std::vector, the storage of our stack
#include <algorithm>    // not used here (template leftover)
#include <string>       // not used here (template leftover)
#include <list>         // not used here (template leftover)

using namespace std;    // write vector/cin/cout without std::


// Same class as in the previous file: the back of the vector is the top,
// so push/pop/top are all O(1).
class myStack{
    public:             // callable from main
        vector<int> v;  // storage; v.back() is the top

        // push: add val on top (end of the vector).
        void push(int val){
            v.push_back(val);
        }

        // pop: remove the top value (returns nothing).
        void pop(){
            v.pop_back();
        }

        // top: read the top value without removing it.
        int top(){
            return v.back();    // same as v[v.size()-1]
        }

        // size: how many values are stored.
        int size(){
            return v.size();
        }

        // Guard for top() and pop(): both of them are undefined on an empty
        // stack, so nothing should call them without asking this first.
        bool empty(){
            return v.empty();
        }
};

int main(){
    myStack s;          // an empty stack

    // get the input for stack
    // First n, then n values. Each value is pushed on the top, so the last
    // number you type ends up on top of the pile.
    int n;
    cin >> n;           // cin >> skips whitespace and reads one number
    for(int i=0; i<n; i++){     // i = 0 .. n-1, one value per pass
        int x;
        cin >> x;
        s.push(x);
    }

    // print the stack
    // Print the top, remove it, repeat until nothing is left. The loop
    // condition is also the safety check: top() and pop() are only reached
    // while the stack still has something in it.
    // For input 3 / 5 6 7 this prints 7, 6, 5 -- the input reversed.
    while(s.empty() == false){
        cout << s.top() << endl;    // endl = newline + flush
        s.pop();
    }

    return 0;           // normal exit
}
