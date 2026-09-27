/*

Problem statement
Given three filled stacks namely ‘stack1’ ‘stack2’ and ‘stack3’ of positive numbers, the 
task is to find the possible equal maximum sum of the stacks with the removal of top 
elements allowed.

For example, let the stacks be:

We can see that currently,

the sum of stack 1 is: 8+5+3 = 16

the sum of stack 2 is: 2+2+4+9+6 = 23

the sum of stack 3 is: 2+1+2+3 = 8

So they are not equal.

However, if we pop {8} from stack 1, {6,9} from stack 2 and nothing from stack 3,

We get the sum as :

Stack 1: 16-8=8

Stack 2: 23-15=8

Stack 3: 8-0=8

We can see that now the sum of all three stacks are equal which is 8 and it is the highest possible, hence we return 8.

Note:
1. Do not print anything, just return an integer which is the maximum possible sum for the three stacks.
2.It is guaranteed that the elements in the stack are positive integers.
3.It can be proved that a non-negative integer answer always exists.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 50
1<= N <=10^4
1<= stackData <=10^9

Where ‘T’ is the total number of test cases, ‘N’ denotes the number of elements in any of the stacks and ‘stackData’ represents the data in the stacks.
Time limit: 1 second
Sample Input 1:
2
2 4 1 9 -1
1 6 3 -1
5 2 1 -1
8 2 1 -1 
1 1 1 -1 
6 3 -1
Sample Output 1:
7
0 

*/

/* Re-typed copy of code360_maximum_equal_stack_sum.cpp; the code is the same. */

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

// The three stacks come by reference (&), so the pops below change the caller's
// stacks. Returns the largest sum all three can share.
int maxSum(stack<int> &st1, stack<int> &st2, stack<int> &st3) {
    // Write your code here
    int sum1 = getSum(st1);
    int sum2 = getSum(st2);
    int sum3 = getSum(st3);

    // Keep the three running sums up to date instead of re-adding the
    // stacks after every pop: each pop just subtracts the removed top.
    while (true) {              // ends only through `break`
        if (sum1 == sum2 && sum2 == sum3) {
            break;              // equal: this is the answer
        }
        // Otherwise shrink the stack whose sum is the largest.
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= st1.top();  // remove the top's value from the sum...
            st1.pop();          // ...and from the stack
        }
        else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= st2.top();
            st2.pop();
        } else {
            sum3 -= st3.top();
            st3.pop();
        }
    }
    // Trace 16, 23, 8: pop 6 -> 16,17,8; pop 9 -> 16,8,8; pop 8 -> 8,8,8.
    return sum1;   // all three sums are equal here
}