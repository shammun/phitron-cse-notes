/*

https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTabValue=PROBLEM

Insert an element at its bottom in a given stack

Problem statement
You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.

Note :
If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at the bottom of the stack and the last element represents the element at the top of the stack.
For Example :
Let ‘MY_STACK’ = [7, 1, 4, 5] and ‘X’ = 9. So, ‘MY_STACK’ after insertion becomes [9, 7, 1, 4, 5].

Follow Up :
Try to do this without using any other data structure.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <=100
1 <= N <= 10^4
0 <= 'X’ and 'MY_STACK[i]’ <= 10^5

Time limit: 1 second

*/

#include <bits/stdc++.h> 
stack<int> pushAtBottom(stack<int>& st, int x) 
{
    // Write your code here.
    stack<int> new_st;
    int val;
    while (!st.empty()) {
        new_st.push(st.top());
        st.pop();
    }
    st.push(x);
    while (!new_st.empty()) {
        st.push(new_st.top());
        new_st.pop();
    }
    return st;
}
