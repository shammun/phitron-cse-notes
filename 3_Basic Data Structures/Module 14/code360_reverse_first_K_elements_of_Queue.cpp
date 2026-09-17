/*

https://www.naukri.com/code360/problems/reverse-first-k-elements-of-queue_982771?leftPanelTabValue=PROBLEM

Reverse First K elements of Queue

*/

#include <bits/stdc++.h> 
queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.
    if (k == 0 || k > q.size()) {
        return q;
    }

    stack<int> st;
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}
