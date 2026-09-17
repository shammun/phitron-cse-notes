#include <bits/stdc++.h> 

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
