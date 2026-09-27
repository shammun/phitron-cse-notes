/*

https://leetcode.com/problems/implement-queue-using-stacks/description/

Implement Queue using Stacks (LeetCode 232)

Build a First-In-First-Out queue using only stacks. A stack hands back the
newest value; a queue must hand back the oldest one.

Example: push 1, push 2, peek() -> 1, pop() -> 1, empty() -> false.

*/

/*
 * Idea
 *
 * One stack `st` holds all the values. Its top is the newest value, so its
 * BOTTOM is the oldest -- and the oldest is what a queue must give back.
 *
 * To reach the bottom, pour `st` into a temporary stack. Pouring reverses the
 * order, so pouring back afterwards restores it.
 *  - pop():  pour out everything except the bottom value, drop the bottom
 *            value, pour the rest back.
 *  - peek(): pour out everything (remembering the last value taken, which is
 *            the bottom), then pour it all back.
 *
 * Cost: push and empty are O(1); pop and peek are O(n).
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> st;   // top = newest value, bottom = oldest value (the queue's front)
    MyQueue() {

    }

    // The newest value simply goes on top. O(1).
    void push(int x) {
        st.push(x);
    }

    // Remove and return the oldest value: the bottom of `st`.
    int pop() {
        stack<int> st2;
        int val;
        while(!st.empty()){
            // Take the top value off; `val` always holds the one just taken.
            val = st.top();
            st.pop();
            // When st runs empty, `val` was the bottom (oldest) value. Stop
            // BEFORE saving it in st2, so it is removed for good.
            if(st.empty()){
                break;
            }
            st2.push(val);
        }

        // Pour st2 back into st. This second reversal puts the remaining
        // values back in their original order.
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        return val;
    }

    // Read the oldest value without removing it.
    int peek() {
        stack<int> st3;
        int val;
        // Move everything, bottom value included, into st3. The last value
        // taken off st is the bottom one, so `val` ends up as the oldest.
        while(!st.empty()){
            val = st.top();
            st.pop();
            st3.push(val);
        }

        // Pour it all back so the queue is unchanged.
        while(!st3.empty()){
            st.push(st3.top());
            st3.pop();
        }
        return val;
    }

    // The queue is empty exactly when the stack is.
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */