/*

Take a stack of size N as input and copy those elements to another stack to get the
values in the order they were inserted and print them. You should use STL to solve
this problem.

Input
5
10 20 30 40 50

Output
10 20 30 40 50

*/

/*
 * Idea
 *
 * Printing a stack means popping it, and popping gives the values back
 * newest-first: 50 40 30 20 10. But every time values are poured from one
 * stack into another, their order flips: the value that was on top goes in
 * first and ends up at the bottom.
 *
 * So pour st1 into st2 ONCE. Now 10 (the first value typed) is on top of st2,
 * and popping st2 prints 10 20 30 40 50 -- the order they were inserted.
 * (Pouring a second time would flip them back and print 50 first again.)
 */

#include <iostream>     // cin, cout, endl
#include <stack>        // std::stack
using namespace std;    // write stack/cin/cout without std::

int main() {
    // Read n values into st1. The last value typed sits on top.
    stack<int> st1;
    int n;
    cin >> n;           // cin >> skips whitespace and reads one number
    for(int i=0; i<n; i++){     // n passes, one value each
        int val;
        cin >> val;
        st1.push(val);
    }

    // Pour st1 into st2: take the top of st1, push it on st2, pop it from st1.
    // 50 goes in first (bottom of st2), 10 goes in last (top of st2).
    stack<int> st2;
    while(!st1.empty()){
        st2.push(st1.top());    // top() reads without removing
        st1.pop();              // pop() removes (returns nothing)
    }

    // Popping st2 now gives the values oldest-first: 10 20 30 40 50.
    while(!st2.empty()){
        cout << st2.top() << " ";
        st2.pop();
    }

    cout << endl;       // finish the line

    return 0;           // normal exit
}
