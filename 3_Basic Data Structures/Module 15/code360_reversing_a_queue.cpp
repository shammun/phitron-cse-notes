/*

Reversing a Queue (Code360)
https://www.naukri.com/code360/problems/reversing-a-queue_982934

The problem, in my own words
  You get a queue of numbers. Return the same queue with its order turned
  around: the value at the back must now be at the front.

Function to write (Code360 signature)
  queue<int> reverseQueue(queue<int> q)

Input used by the test driver
  first line t (test cases); each case: n, then the n values from front to
  back.

Sample
  1 value:  9              ->  9
  5 values: 10 6 8 12 3    ->  3 12 8 6 10

*/

/*
 * The idea: a queue gives values back in the SAME order they went in
 * (first in, first out). A stack gives them back in the OPPOSITE order
 * (last in, first out). So pour the queue into a stack, then pour the
 * stack back into the queue: the order comes out reversed.
 *
 *   queue 10 6 8 12 3  -> stack (top) 3 12 8 6 10 (bottom) -> queue 3 12 8 6 10
 */

queue<int> reverseQueue(queue<int> q)
{
    stack<int> st;

    // Front of the queue first -> it ends up at the bottom of the stack.
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    // The stack's top is the old BACK of the queue, so it re-enters first
    // and becomes the new front.
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    return q;
}
