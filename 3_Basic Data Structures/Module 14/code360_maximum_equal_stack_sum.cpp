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

#include <bits/stdc++.h>

// Adds up a stack. `st` is a copy (passed by value), so popping it here
// does not empty the caller's stack.
int getSum(stack<int> st) {
    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    return sum;
}

int maxSum(stack<int> &st1, stack<int> &st2, stack<int> &st3) {
    // Write your code here
    int sum1 = getSum(st1);
    int sum2 = getSum(st2);
    int sum3 = getSum(st3);

    // Keep the three running sums up to date instead of re-adding the
    // stacks after every pop: each pop just subtracts the removed top.
    while (true) {
        if (sum1 == sum2 && sum2 == sum3) {
            break;
        }
        // Otherwise shrink the stack whose sum is the largest.
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= st1.top();
            st1.pop();
        }
        else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= st2.top();
            st2.pop();
        } else {
            sum3 -= st3.top();
            st3.pop();
        }
    }
    return sum1;   // all three sums are equal here
}