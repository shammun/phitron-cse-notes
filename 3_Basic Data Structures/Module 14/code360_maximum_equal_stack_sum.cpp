/*

https://www.naukri.com/code360/problems/maximum-equal-stack-sum_1062571

Maximum Equal Stack Sum (Code360)

Three stacks of positive numbers. You may pop values off their tops. Find
the largest sum that all three stacks can have at the same time.

Example: stacks (top first) 8 5 3 | 6 9 4 2 2 | 3 2 1 2 have sums 16, 23, 8.
Popping 8 from the first and 6 and 9 from the second gives 8, 8, 8 -> 8.

*/

/*
 * Idea
 *
 * Only top values may be removed, and all values are positive, so removing
 * a value always makes that stack's sum smaller. The answer is the largest
 * sum all three stacks can share.
 *
 * Greedy: while the three sums differ, pop from the stack with the LARGEST
 * sum. The biggest sum is the only one that is certainly too big (the
 * common sum can never be above the smallest one), so shrinking it never
 * throws away the best answer. Stop as soon as the sums are equal; if the
 * stacks run out, all sums reach 0, which is equal too.
 *
 * Example: sums 16, 23, 8 -> pop from stack 2 until it is <= the others,
 * then from stack 1, ... until all are 8.
 */

// <bits/stdc++.h> = GCC's "include everything" header (gives std::stack).
// Code360's template supplies `using namespace std;` and main().
#include <bits/stdc++.h>

// Adds up a stack. `st` is a copy (passed by value), so popping it here
// does not empty the caller's stack.
// BUG: stackData goes up to 10^9 and N up to 10^4, so a sum can reach 10^13,
// far past the int limit (about 2.1 * 10^9) - the int overflows and the sums
// become wrong. Fix: use `long long` for sum, sum1, sum2, sum3 and the return type.
int getSum(stack<int> st) {
    int sum = 0;
    // One pass per value: add the top, then remove it from this copy.
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    return sum;
}

// The three stacks are passed by reference (&), so the pops below change the
// caller's stacks. Returns the largest equal sum.
int maxSum(stack<int> &st1, stack<int> &st2, stack<int> &st3) {
    // Write your code here
    int sum1 = getSum(st1);     // e.g. 16
    int sum2 = getSum(st2);     // e.g. 23
    int sum3 = getSum(st3);     // e.g. 8

    // Keep the three running sums up to date instead of re-adding the
    // stacks after every pop: each pop just subtracts the removed top.
    while (true) {              // ends only through `break`
        if (sum1 == sum2 && sum2 == sum3) {
            break;              // all equal: this is the answer
        }
        // Otherwise shrink the stack whose sum is the largest.
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= st1.top();  // take the top's value off the sum...
            st1.pop();          // ...and off the stack
        }
        else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= st2.top();
            st2.pop();
        } else {
            sum3 -= st3.top();
            st3.pop();
        }
    }
    // Trace 16,23,8: pop 6 -> 16,17,8; pop 9 -> 16,8,8; pop 8 from st1 -> 8,8,8 -> stop.
    return sum1;   // all three sums are equal here
}