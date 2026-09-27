#include <bits/stdc++.h> // GCC's "include everything" header: gives std::stack

/*

Problem statement
You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert 
‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.

Note :
If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at the bottom 
of the stack and the last element represents the element at the top of the stack.
For Example :
Let ‘MY_STACK’ = [7, 1, 4, 5] and ‘X’ = 9. So, ‘MY_STACK’ after insertion becomes 
[9, 7, 1, 4, 5].

*/

/* Re-typed copy of code360_insert_an_element_at_its_bottom_in_a_given_stack.cpp;
 * the code is the same. */

/*
 * Idea
 *
 * A stack only lets you touch its top, so to reach the bottom everything
 * above it has to be moved out of the way first:
 *
 *   st = [7 1 4 5] (5 on top), x = 9
 *   1. pour st into new_st  -> st empty, new_st = [5 4 1 7] (7 on top)
 *   2. push x onto empty st -> st = [9]
 *   3. pour new_st back     -> st = [9 7 1 4 5]; the second pour restores
 *                              the original order, now sitting on top of 9.
 *
 * Every value moves twice: O(n) time, O(n) extra space.
 */

// (The #include at the very top is <bits/stdc++.h>, GCC's "include everything"
//  header; Code360's template adds `using namespace std;` and main().)
// st is taken by reference (&): we change the caller's own stack.
// Returns the updated stack (a copy of st) as the problem asks.
stack<int> pushAtBottom(stack<int>& st, int x)
{
    // Write your code here.
    stack<int> new_st;      // temporary holder for everything above the bottom
    int val;   // declared but never used
    // 1. Empty st into new_st (this reverses the order).
    // One pass = move the top of st onto new_st; stops when st is empty.
    while (!st.empty()) {
        new_st.push(st.top());  // top() only reads the value
        st.pop();               // pop() removes it
    }
    // 2. st is empty now, so x lands at the very bottom.
    st.push(x);
    // 3. Pour the values back on top of x; reversing again restores their order.
    while (!new_st.empty()) {
        st.push(new_st.top());
        new_st.pop();
    }
    // Trace [7 1 4 5], x 9: new_st = [5 4 1 7] -> st = [9] -> st = [9 7 1 4 5].
    return st;
}
