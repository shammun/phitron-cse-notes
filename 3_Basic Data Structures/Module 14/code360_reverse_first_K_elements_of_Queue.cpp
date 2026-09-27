/*

https://www.naukri.com/code360/problems/reverse-first-k-elements-of-queue_982771?leftPanelTabValue=PROBLEM

Reverse First K elements of Queue

Reverse only the first k values of a queue; the rest keep their order and
stay behind them.

Example: q = 1 2 3 4 5, k = 3 -> 3 2 1 4 5.

*/

/*
 * Idea
 *
 * 1. Dequeue the first k values onto a stack (the k-th value ends on top).
 * 2. Pop the stack back into the queue. These k values are now reversed,
 *    but they sit at the BACK, behind the n-k untouched values.
 * 3. Rotate: take the n-k untouched values from the front and enqueue them
 *    again, so they move behind the reversed block.
 *
 *   1 2 3 4 5  -> step 1: queue 4 5, stack top 3 2 1
 *              -> step 2: 4 5 3 2 1
 *              -> step 3: move 4 and 5 to the back: 3 2 1 4 5
 *
 * O(n) time.
 */

// <bits/stdc++.h> = GCC's "include everything" header (queue, stack, ...).
// Code360's template supplies `using namespace std;` and main().
#include <bits/stdc++.h>
// q is a copy (passed by value); the function returns the rearranged copy.
queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.
    // Nothing to reverse, or k is bigger than the queue: return it unchanged.
    // (q.size() is unsigned; k is never negative here, so the comparison is safe.)
    if (k == 0 || k > q.size()) {
        return q;
    }

    // Step 1: the first k values go onto the stack.
    stack<int> st;
    for (int i = 0; i < k; i++) {       // exactly k passes
        st.push(q.front());             // read the front value
        q.pop();                        // remove it from the queue's front
    }

    // Step 2: pop them back in reverse order; they join at the back.
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: rotate the n-k untouched values from the front to the back.
    // q.size() is n again here (all k values were put back), so the loop
    // runs exactly n-k times.
    // (Each pass pushes one and pops one, so q.size() stays n the whole time.)
    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());      // copy the front to the back...
        q.pop();                // ...and remove it from the front
    }

    return q;
}
