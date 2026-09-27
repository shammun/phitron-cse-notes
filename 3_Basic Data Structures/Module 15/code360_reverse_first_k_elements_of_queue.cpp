/*

Reverse First K Elements of Queue (Code360)
https://www.naukri.com/code360/problems/reverse-first-k-elements-of-queue_982771

The problem, in my own words
  You get a queue of n numbers and a number k (1 <= k <= n). Reverse the
  order of the first k values (the k nearest the front) and leave the other
  n - k values behind them in their original order. Return the queue.

Function to write (Code360 signature)
  queue<int> reverseElements(queue<int> q, int k)

Input used by the test driver
  first line t (test cases); each case: n and k, then the n values from
  front to back.

Sample
  n = 5, k = 3, queue 1 2 3 4 5        ->  3 2 1 4 5
  n = 4, k = 4, queue 10 20 30 40      ->  40 30 20 10

*/

/*
 * The idea, in three phases:
 *   1. pop the first k values into a stack - the stack turns them around;
 *   2. push them from the stack back into the queue - they join at the BACK,
 *      already reversed:                       4 5 | 3 2 1
 *   3. the n - k untouched values are now in front of them, so rotate each
 *      of them once (pop from the front, push at the back):  3 2 1 | 4 5
 *
 * Every value is moved a constant number of times, so it is O(n).
 *
 * Note: no #include or main() - the judge's hidden code includes <queue>
 * and <stack> and calls this function.
 */

// q is taken by value (a copy of the judge's queue); we change the copy and
// return it.
queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> st;      // turns the first k values around
    int n = q.size();   // remember n now; the size changes while we work

    // Phase 1: the first k values go into the stack (1 at the bottom, k-th on top).
    // i counts how many values have been moved; the loop runs exactly k times.
    for(int i = 0; i < k; i++){
        st.push(q.front());    // front() reads the value at the front of the queue
        q.pop();               // pop() on a queue removes the FRONT value
    }

    // Phase 2: pour them back. The k-th value comes out first, so the block
    // re-enters the queue in reverse order, behind the untouched values.
    // With 1 2 3 4 5, k = 3: queue becomes 4 5 3 2 1.
    while(!st.empty()){
        q.push(st.top());      // push() on a queue adds at the BACK
        st.pop();
    }

    // Phase 3: the n - k values that were never meant to move are at the
    // front now. Send each of them to the back once, keeping their order.
    // With 4 5 3 2 1: move 4 -> 5 3 2 1 4, move 5 -> 3 2 1 4 5.
    for(int i = 0; i < n - k; i++){
        q.push(q.front());     // copy the front value to the back
        q.pop();               // and remove it from the front
    }

    return q;                  // the queue with its first k values reversed
}
