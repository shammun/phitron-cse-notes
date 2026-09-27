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
 */

// Adds up a stack. It is taken by value (a copy), so the caller's stack is
// not emptied by the pops here.
int stackSum(stack<int> st){
    int sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    return sum;
}

int maxSum(stack<int> &st1, stack<int> &st2, stack<int> &st3)
{
    // Work out each sum once, then keep them up to date while popping,
    // instead of adding the whole stack again every round.
    int sum1 = stackSum(st1);
    int sum2 = stackSum(st2);
    int sum3 = stackSum(st3);

    while(!(sum1 == sum2 && sum2 == sum3)){
        // Shrink the tallest (largest sum) stack by one value.
        if(sum1 >= sum2 && sum1 >= sum3){
            sum1 -= st1.top();
            st1.pop();
        }
        else if(sum2 >= sum1 && sum2 >= sum3){
            sum2 -= st2.top();
            st2.pop();
        }
        else{
            sum3 -= st3.top();
            st3.pop();
        }
        // No empty() check is needed: the largest sum is not equal to the
        // others, so it is bigger than 0 and its stack still has values.
    }

    return sum1;   // all three are equal here
}
