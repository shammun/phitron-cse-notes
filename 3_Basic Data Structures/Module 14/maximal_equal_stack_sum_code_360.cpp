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


#include <bits/stdc++.h>

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

    while (true) {
        if (sum1 == sum2 && sum2 == sum3) {
            break;
        }
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
    return sum1;
}