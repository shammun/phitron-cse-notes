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

#include <bits/stdc++.h> 
queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.
    // Nothing to reverse, or k is bigger than the queue: return it unchanged.
    if (k == 0 || k > q.size()) {
        return q;
    }

    // Step 1: the first k values go onto the stack.
    stack<int> st;
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: pop them back in reverse order; they join at the back.
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: rotate the n-k untouched values from the front to the back.
    // q.size() is n again here (all k values were put back), so the loop
    // runs exactly n-k times.
    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}
