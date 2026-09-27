/*

Problem Statement

There is a list of  values that were inserted into a stack and a list of  values that were inserted into a queue. You need to determine whether the stack and queue are the same or not based on the order in which the elements are removed.

Note: You need to solve it using  Stack and Queue only.

(The blanks above lost their symbols when copied: the stack gets N values,
the queue gets M values, and you must use the STL stack and queue.)

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
 * "Same in the order of removal": a stack gives back its values newest
 * first (LIFO), a queue oldest first (FIFO). So a stack filled with
 * 10 20 30 40 50 comes out as 50 40 30 20 10, and it matches a queue that
 * was filled with 50 40 30 20 10.
 *
 * Fill an STL stack and an STL queue, then pop both together and compare
 * st.top() with q.front() every time. O(n).
 *
 * Sample 1: stack 10 20 30 40 comes out 40 30 20 10, queue comes out
 * 10 20 30 40 -> first pair 40 vs 10 differs -> NO.
 */

#include <iostream>     // cin (read input) and cout (print output)
#include <vector>       // vector (not actually used here)
#include <algorithm>    // sort, reverse, ... (not actually used here)
#include <string>       // string (not actually used here)
#include <stack>        // stack<T>: push, pop, top, empty
#include <queue>        // queue<T>: push, pop, front, empty
using namespace std;    // lets us write cout, stack, ... instead of std::cout, std::stack

int main(){
    int n, m;               // n = how many values go into the stack, m = into the queue
    cin >> n >> m;          // cin >> skips spaces/newlines and reads one number into each variable
    stack<int> st;          // an empty STL stack of ints
    queue<int> q;           // an empty STL queue of ints

    // The stack gets n values: the last one typed ends up on top.
    // i just counts the n reads.
    for(int i=0; i<n; i++){
        int val;            // one value from the input
        cin >> val;
        st.push(val);       // put it on top of the stack
    }

    // The queue gets m values: the first one typed is at the front.
    for(int i=0; i<m; i++){
        int val;
        cin >> val;
        q.push(val);        // add it at the back of the queue
    }

    // Different sizes can never give the same removal order. Checking this
    // first also means the loop below never touches an empty queue.
    if(n != m){
        cout << "NO" << endl;   // endl prints a newline and flushes the output
        return 0;               // end the program right here
    }

    // Remove from both side by side: the stack gives top(), the queue gives
    // front(). The first pair that differs settles it. One pass compares
    // one pair; the loop stops when the stack is empty.
    while(!st.empty()){
        if(st.top() != q.front()){      // the next value removed from each differs
            cout << "NO" << endl;
            return 0;
        }
        st.pop();           // remove the top of the stack
        q.pop();            // remove the front of the queue
    }

    // Every pair matched.
    cout << "YES" << endl;

    return 0;               // 0 tells the system the program finished normally
}
