/*

Problem statement
You are given a queue of 'N' elements. Your task is to reverse the order of elements present in the queue.

You can only use the standard operations of the QUEUE STL.

1. enqueue(x): Add an item x to the rear of the queue.

2. dequeue(): Removes an item from the front of the queue.

3. size(): Returns the number of elements in the queue.

4. front(): Finds front element.

5. empty(): Checks whether the queue is empty or not.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100 
1 <= N <= 3000
-10 ^ 5 <= Queue[i] <= 10 ^ 5

Time Limit: 1 sec
Sample Input 1:
2
1
9
5
10 6 8 12 3
Sample Output 1:
9 
3 12 8 6 10
Explanation 1:
For the first test case, the queue has only one element, i.e. 9. So, even after reversing, our queue remains the same.

For the second test case, the queue has elements in the order: 10, 6, 8, 12, 3. Reversing the queue changes the order of elements to - 3, 12, 8, 6, 10.
Sample Input 2:
2
2
99 89
6
1 2 3 4 5 6
Sample Output 2:
89 99
6 5 4 3 2 1

*/

/* Re-typed copy of code360_reverse_a_queue.cpp; the code is the same. */

/*
 * Idea
 *
 * A queue keeps order, a stack reverses it. So pass the values through a
 * stack: dequeue all of them into the stack (the last value ends on top),
 * then pop the stack back into the same queue. The last value comes out
 * first and becomes the new front.
 *
 *   q = 10 6 8 12 3  ->  stack top 3 12 8 6 10  ->  q = 3 12 8 6 10
 *
 * O(n) time, O(n) extra space for the stack.
 */

// <bits/stdc++.h> = GCC's "include everything" header (queue, stack, ...).
// Code360's template supplies `using namespace std;` and main().
#include <bits/stdc++.h>
// q is passed BY VALUE (no &): the function reverses its own copy and returns it.
queue<int> reverseQueue(queue<int> q)
{
    // Write your code here.
    // Move every value from the front of q onto the stack.
    stack<int> st;
    // One pass = one value: read the front, push it on the stack, remove it from q.
    while(!q.empty()){
        st.push(q.front());     // front() reads the oldest value
        q.pop();                // queue pop removes the FRONT
    }

    // Pop the stack back into q: the order is now reversed.
    // q.push() adds at the BACK; the stack hands out the newest value first.
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    return q;
}