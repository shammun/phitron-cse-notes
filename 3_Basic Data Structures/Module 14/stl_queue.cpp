/*

The ready-made queue: `queue<int>` from the STL

A queue is First-In-First-Out (FIFO): a line at a counter. New values join at
the back, and the value that leaves is always the one at the front, so nothing
overtakes and the order is preserved. That is the whole difference from a
stack, which is Last-In-First-Out and therefore reverses the order.

Module 13 built a queue by hand out of linked-list nodes. This file uses the
one the standard library already provides. The six operations:

    push(x)   join the back
    pop()     the front leaves (returns nothing)
    front()   read the value at the front -- the next to leave
    back()    read the value at the back  -- the newest one
    size()    how many are in the line
    empty()   is the line empty?

All of them are O(1).

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>        // gives us queue<int>
using namespace std;

int main() {
    queue<int> q;
    int n;
    cin >> n;
    // Read n values. Each push() puts the value at the back of the line, so
    // the queue ends up holding them in the order they were typed.
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        q.push(val);
    }

    // front = the first value typed, back = the last one, size = how many.
    // For input 4 / 1 2 3 4 this line is `1 4 4`.
    cout << q.front() << " " << q.back() << " " << q.size() <<  endl;

    // Always check if the queue is empty or not before using pop() or
    // using front() or back()
    // (Those three read or remove a value that must exist. On an empty queue
    // the behaviour is undefined -- a junk number or a crash.)

    // Drain the queue: print the front, remove it, repeat. Because removal
    // happens at the front, the values come out in arrival order: 1 2 3 4.
    // Run the same input through a stack and you would get 4 3 2 1.
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}
