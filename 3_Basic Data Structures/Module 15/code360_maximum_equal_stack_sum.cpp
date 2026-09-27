/*

Maximum Equal Stack Sum (Code360)
https://www.naukri.com/code360/problems/maximum-equal-stack-sum_1062571

The problem, in my own words
  There are three stacks of positive numbers. You may only remove values from
  the TOP of a stack (as many as you like, from any stack). Remove values so
  that the three stacks end up with the same sum, and make that common sum as
  large as possible. Return it (it is 0 if the only way is to empty them all).

Function to write (Code360 signature)
  int maxSum(stack<int> &st1, stack<int> &st2, stack<int> &st3)

Input used by the test driver
  first line t (test cases); each case has three lines, one per stack:
  its size, then its values listed from the TOP down.

Sample
  stack 1 (top first): 3 2 1 1 1    sum 8
  stack 2 (top first): 4 3 2        sum 9
  stack 3 (top first): 1 1 4 1      sum 7
  answer 5: remove 3 from stack 1, 4 from stack 2, and 1, 1 from stack 3.

*/

/*
 * The idea: removing values only ever makes a sum smaller. So look at the
 * three sums. If they are all equal, that is the answer - it is the biggest
 * equal sum possible, because we have removed as little as we could.
 * If they are not equal, the stack with the LARGEST sum can never be part of
 * the answer at its current height (the others cannot grow to meet it), so
 * pop its top and try again.
 *
 * Every round removes one value, so after at most n1 + n2 + n3 rounds we stop.
 * If a stack runs empty its sum is 0, and then the answer is 0.
 *
 * Trace with the sample (sums 8, 9, 7):
 *   9 is largest -> pop 4 from stack 2   sums 8, 5, 7
 *   8 is largest -> pop 3 from stack 1   sums 5, 5, 7
 *   7 is largest -> pop 1 from stack 3   sums 5, 5, 6
 *   6 is largest -> pop 1 from stack 3   sums 5, 5, 5   -> all equal, answer 5
 *
 * Note: no #include or main() - the judge's hidden code includes <stack>
 * and calls maxSum.
 */

// Adds up a stack. It is taken by value (a copy), so the caller's stack is
// not emptied by the pops here.
int stackSum(stack<int> st){
    int sum = 0;               // running total
    while(!st.empty()){        // one pass adds one value; stops when the copy is empty
        sum += st.top();       // add the value on top
        st.pop();              // remove it so the next value comes to the top
    }
    return sum;                // total of all values in the stack
}

// The three stacks are passed by reference (&): we pop the judge's real
// stacks, not copies. Returns the largest equal sum.
int maxSum(stack<int> &st1, stack<int> &st2, stack<int> &st3)
{
    // Work out each sum once, then keep them up to date while popping,
    // instead of adding the whole stack again every round.
    int sum1 = stackSum(st1);
    int sum2 = stackSum(st2);
    int sum3 = stackSum(st3);

    // Keep going while the three sums are NOT all equal.
    // (a == b && b == c) means all three are equal; ! turns it around.
    while(!(sum1 == sum2 && sum2 == sum3)){
        // Shrink the tallest (largest sum) stack by one value.
        if(sum1 >= sum2 && sum1 >= sum3){          // stack 1 has the largest sum
            sum1 -= st1.top();                     // its sum loses the top value
            st1.pop();                             // and the value leaves the stack
        }
        else if(sum2 >= sum1 && sum2 >= sum3){     // stack 2 has the largest sum
            sum2 -= st2.top();
            st2.pop();
        }
        else{                                      // otherwise stack 3 is the largest
            sum3 -= st3.top();
            st3.pop();
        }
        // No empty() check is needed: the largest sum is not equal to the
        // others, so it is bigger than 0 and its stack still has values.
    }

    return sum1;   // all three are equal here
}
