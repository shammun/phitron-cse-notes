// Stack, the ready-made way: the STL `stack<int>` from <stack>.
// No class to write - the STL already gives push, pop, top, size and empty,
// all O(1), with the same Last-In-First-Out rule as our hand-made stacks.

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here (template leftover)
#include <algorithm>    // not used here (template leftover)
#include <string>       // not used here (template leftover)
#include <stack>        // std::stack


using namespace std;    // write stack/cin/cout without std::


int main(){
    stack<int> s;       // an empty stack of ints

    // Five fixed values first: 10 at the bottom, 50 on top.
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    // push, pop, top, size, empty -- main 5 functions

    // get the input for stack
    // These values go ON TOP of the five above.
    int n;              // how many more values
    cin >> n;           // cin >> skips whitespace and reads one number
    for(int i=0; i<n; i++){     // n passes, one value each
        int x;
        cin >> x;
        s.push(x);
    }

    // Always check whether the stack is empty or not before doing pop and top
    // (top() or pop() on an empty stack is undefined behaviour - usually a crash).

    // print the stack
    // Newest first: input 2 / 1 2 prints 2, 1, 50, 40, 30, 20, 10.
    while(!s.empty()){          // `!` = not: loop while the stack is NOT empty
    // while(s.empty() == false){   // the same test written the long way (kept for reference)
        cout << s.top() << endl;    // read the top (does not remove it)
        s.pop();                    // now remove it (pop returns nothing)
    }

    return 0;           // normal exit
}